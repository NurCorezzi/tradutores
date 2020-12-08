#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gramatica.tab.h"
#include "code_gen.h"
#include "node.h"

extern TypeExpression TYPE_EXPRESSION_INT;
extern TypeExpression TYPE_EXPRESSION_VOID;
extern TypeExpression TYPE_EXPRESSION_ARRAY_INT;

extern int next_instruction;
extern int label_count;
extern int declaration_count;

GenericList *alloc;

union Value get_value_label(Label *label) {
    union Value v;
    v.label = label;
    return v;
}

union Value get_value_ival(int ival) {
    union Value v;
    v.ival = ival;
    return v;
}

union Value get_value_fval(float fval) {
    union Value v;
    v.fval = fval;
    return v;
}

void push_alloc(void *obj) {
    GenericList* cur = (GenericList*)calloc(1, sizeof(GenericList));
    cur->cur = obj;
    if (alloc == NULL) {
        alloc = cur;
    } else {
        alloc->next = cur;
        cur->previous = alloc;
        alloc = cur;
    }
}

void replace_label_value(Label* label, char *value) {
    if (label == NULL || value == NULL) {
        return;
    }
    label->value = strdup(value);
    push_alloc((void*)label->value);
}

Label* cgen_label(char *value, int is_user_label) {
    Label* label = (Label*)calloc(1, sizeof(Label));
    push_alloc((void*)label);

    if (is_user_label) {
        label->value = strdup(value);
        push_alloc((void*)label->value);
    } else {
        char* l_value = (char*)malloc(strlen(value) + 2);
        strcpy(l_value, "_");
        strcat(l_value, value);
        label->value = l_value;
        push_alloc((void*)l_value);
    }

    return label;
}

Label* cgen_label_by_counter() {    
    char buffer[300];
    sprintf(buffer, "L%d", label_count++);
    return cgen_label(buffer, 0);
}


Field *cgen_field(union Value value, OperandType type) {
    Field* field = (Field*)calloc(1, sizeof(Field));
    push_alloc((void*)field);
    field->value = value;
    field->type = type;
    field->value_type = RVALUE;
    return field;
}

Field *cgen_field_adress(union Value value, OperandType type, Field *index) {
    Field* field = cgen_field(value, type);
    field->adress_index = index;
    field->value_type = LVALUE;
    return field;
}

Instruction* cgen_instr(Label* label, InstCode inst_code, Field* f0, Field* f1, Field *f2) {
    Instruction* inst = (Instruction*)calloc(1, sizeof(Instruction));
    push_alloc((void*)inst);

    inst->label = label;
    inst->inst_code = inst_code;
    inst->fields[0] = f0;
    inst->fields[1] = f1;
    inst->fields[2] = f2;

    next_instruction++;
    return inst;
}

void cgen_append(Instruction **codea, Instruction *codeb) {
    Instruction** base = codea;
    if ((*base) == NULL) {
        (*base) = codeb;
        return;
    }
    
    Instruction *cur = *base;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = codeb;
}

Instruction* cgen_last_inst(Instruction *inst) {
    Instruction *cur = inst;
    while(cur && cur->next != NULL) {
        cur = cur->next;
    }
    return cur;
}

/*--------------------BACK PATCH-------------------------*/

BackPatchList* cgen_last_patch(BackPatchList *patch) {
    while(patch && patch->next != NULL) {
        patch = patch->next;
    }
    return patch;
}

BackPatchList* cgen_patch(Field *field) {
    BackPatchList* patch = (BackPatchList*)calloc(1, sizeof(BackPatchList));
    patch->cur = field;

    push_alloc((void*)patch);
    return patch;
}

BackPatchList* cgen_cpy_patch(BackPatchList *patch) {
    BackPatchList* new_patch_list = NULL;
    while(patch) {
        BackPatchList* new_patch = cgen_patch(patch->cur);

        if (new_patch_list == NULL) {
            new_patch_list = new_patch;
        } else {
            // Ineficiente mas pratico
            cgen_last_patch(new_patch_list)->next = new_patch;
        }

        patch = patch->next;
    }
    return new_patch_list;
}

BackPatchList* cgen_merge_patch(BackPatchList *a, BackPatchList *b) {
    a = cgen_cpy_patch(a);
    b = cgen_cpy_patch(b);
    if (a == NULL) {
        return b;
    } else {
        BackPatchList *last_patch = cgen_last_patch(a);
        last_patch->next = b;
        return a;
    }
}

void cgen_back_patch(BackPatchList *patch_list, Label *patch) {
    while(patch_list) {
        patch_list->cur->value.label = patch;
        patch_list = patch_list->next;
    }
}


/*---------------------LANGUAGE CODE GENERATOR-------------------------*/

/**
 * Calcula quantas unidades de memoria que o tipo deve ocupar levando em consideracao o destino traduzido como TAC, 
*/
int type_mem_sz(TypeExpression *type) {
    switch(type->node_type) {
        case GTYPE_INT:     return 1;  
        case GTYPE_FLOAT:   return 1;  
        case GTYPE_GRAPH:   return 3; // sz, *valores_vertices, *arestas    
        case GTYPE_ARRAY:   return type_mem_sz(type->child) * type->size + 1; // tamanho total + 1 para o tamanho do array
        default: return 0;
    }
}

Instruction* cgen_derref_lvalue(Field *adress, int *temp_inst_count) {
    if (adress->value_type == LVALUE) {
        return cgen_instr(
                NULL, 
                TAC_MOVVI, 
                cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), 
                adress, 
                adress->adress_index
            );     
    } else {
        return NULL;
    }
}

Instruction* cgen_cast(Field *field, Cast cast, int *temp_inst_count) {
    InstCode code;
    
    switch (cast){
        case CINT_TO_FLOAT: code = TAC_INTTOFL; break;
        case CFLOAT_TO_INT: code = TAC_FLTOINT; break;
        default:
            return NULL;
    }

    return cgen_instr(
            NULL, 
            code, 
            cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), 
            field, 
            NULL
        );     
}

/**
 * Value serve para atualizar o tamanho 
*/
Instruction* cgen_fill_mem(Field* field, TypeExpression *type, int position, int value) {
    Instruction *inst = NULL;
    
    switch(type->node_type) {
        case GTYPE_INT: {
            inst = cgen_instr(NULL, TAC_MOVIV, 
                field,
                cgen_field(get_value_ival(position), TAC_OPTYPE_INT), 
                cgen_field(get_value_ival(value), TAC_OPTYPE_INT));
            break;
        }
        case GTYPE_FLOAT: {
            inst = cgen_instr(NULL, TAC_MOVIV, 
                field,
                cgen_field(get_value_ival(position), TAC_OPTYPE_INT), 
                cgen_field(get_value_fval(0), TAC_OPTYPE_FLOAT));
            break;
        }  
        case GTYPE_GRAPH: {
            // Possui 3 campos inicias porem apenas e necessario inicializar tamanho para zero
            inst = cgen_instr(NULL, TAC_MOVIV, 
                field,
                cgen_field(get_value_ival(position), TAC_OPTYPE_INT), 
                cgen_field(get_value_ival(0), TAC_OPTYPE_INT));
            break;
        }    
        case GTYPE_ARRAY: {
            int i;
            int sz = type_mem_sz(type->child);

            // Atualizar tamanho aramazenado no inicio do array
            inst = cgen_fill_mem(field, &TYPE_EXPRESSION_INT, 0, type->size);

            for (i = 0; i < type->size; ++i) {
                Instruction *next = cgen_fill_mem(field, type->child, position + sz*i + 1, 0);
                cgen_append(&inst, next);
            }
            break;
        }
        default: 
            printf("ERRO: type not found in mem filling");
            exit(0);
    }
    return inst;
}

Instruction* cgen_declaration(SymbolNode *sym, int *temp_inst_count) {
    int sz = type_mem_sz(sym->type);

    if (sz == 0) {
        return NULL;
    }

    Instruction *inst = NULL;

    // nop de referencia
    cgen_append(&inst, cgen_instr(NULL, TAC_NOP, NULL, NULL, NULL));

    switch(sym->type->node_type) {
        case GTYPE_GRAPH:     
        case GTYPE_ARRAY: 
        case GTYPE_FLOAT:   
        case GTYPE_INT: {
            // Todo endereco deve conter um indice de acesso
            Field *adress_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
            Field *adress = cgen_field_adress(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP, adress_index);

            char buffer[300] = {0};
            sprintf(buffer, "%s%d", sym->id, declaration_count++);

            cgen_append(&inst, cgen_instr(cgen_label(buffer, 0), TAC_MOVVV, adress_index, cgen_field(get_value_ival(0), TAC_OPTYPE_INT), NULL));                       
            cgen_append(&inst, cgen_instr(NULL, TAC_MEMA, adress, cgen_field(get_value_ival(sz), TAC_OPTYPE_INT), NULL));

            sym->tac_ref = adress;
            cgen_append(&inst, cgen_fill_mem(adress, sym->type, 0, 0));
            break;
        }
        default: 
            printf("ERRO: type not found in declaration");
            exit(0);
    }

    // nop de referencia
    cgen_append(&inst, cgen_instr(NULL, TAC_NOP, NULL, NULL, NULL));

    return inst;
}

/**
 * A principio nao e necessario gerar instrucao, parametros de funcao serao sempre tratados como endereco
*/
Instruction* cgen_declaration_param(SymbolNode *sym, int *param_inst_count) {
    Instruction *inst = NULL;

    switch(sym->type->node_type) {
        case GTYPE_FLOAT:   
        case GTYPE_INT: 
        case GTYPE_GRAPH:     
        case GTYPE_ARRAY: {
            Field *index = cgen_field(get_value_ival((*param_inst_count)++), TAC_OPTYPE_PARAM);
            Field *adress = cgen_field_adress(get_value_ival((*param_inst_count)++), TAC_OPTYPE_PARAM, index);
            sym->tac_ref = adress;
            break;
        } 
        default: 
            printf("ERRO: type not found in declaration of param");
            exit(0);
    }

    return inst;
}

/**
 * A principio retorno sera sempre rvalue
*/
Instruction* cgen_return(Node *expr, int *temp_inst_count) {
    Instruction *inst = NULL;

    if (expr) {
        cgen_append(&(expr->code), cgen_derref_lvalue(cgen_last_inst(expr->code)->fields[0], temp_inst_count));
        cgen_append(&(expr->code), cgen_cast(cgen_last_inst(expr->code)->fields[0], expr->cast, temp_inst_count));
    }

    Field *field = expr ? cgen_last_inst(expr->code)->fields[0] : NULL;

    cgen_append(
      &inst,
      cgen_instr(
        NULL,
        TAC_RETURN,
        field,
        NULL,
        NULL
      )
    );

    // Necessario ocorrer apos para que campos convertidos acima por derref estejam corretos
    if (expr) {
        cgen_append(&(expr->code), inst);
        inst = expr->code;
    }

    return inst;
}


/**
 * Codigo dos parametros tambem sera anexado aqui
*/
Instruction *cgen_function_call(SymbolNode *sym, Node *params_call, int *temp_inst_count) {
    Instruction *inst = NULL;
    Node *params = params_call;
    int params_count = 0;

    if (params) {
        Node *param = params->begin_child;
        Node *declaration_param = sym->ast_node->begin_child;
        while (param != NULL) {
            cgen_append(&inst, param->code);
            Field *ref = cgen_last_inst(param->code)->fields[0];

            // Parametros sempre irao armazenar uma informacao de endereco, ou seja index + endereco
            params_count += 2;            

            switch (ref->value_type){
                case LVALUE: {
                    cgen_append(&inst, cgen_instr(NULL, TAC_PARAM, ref->adress_index, NULL, NULL));               
                    cgen_append(&inst, cgen_instr(NULL, TAC_PARAM, ref, NULL, NULL));
                    break;
                }
                // Parametros passado por valor serao alocados e passados como endereco
                case RVALUE: {
                    cgen_append(&inst, cgen_cast(ref, param->cast, temp_inst_count));

                    Field *value = cgen_last_inst(inst)->fields[0];
                    Field *copy_adress = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);

                    cgen_append(&inst, cgen_instr(NULL, TAC_MEMA, copy_adress, cgen_field(get_value_ival(1), TAC_OPTYPE_INT), NULL));
                    cgen_append(&inst, cgen_instr(NULL, TAC_MOVDV, copy_adress, value, NULL));

                    cgen_append(&inst, cgen_instr(NULL, TAC_PARAM, cgen_field(get_value_ival(0), TAC_OPTYPE_INT), NULL, NULL));               
                    cgen_append(&inst, cgen_instr(NULL, TAC_PARAM, copy_adress, NULL, NULL));
                    break;
                }
            }   
            
            param = param->next; 
            declaration_param = declaration_param->next;
        }
    } 
  
    Field *function_label = cgen_field(get_value_label(cgen_label(sym->id, 0)), TAC_OPTYPE_LABEL);
    Field *field_params_count = cgen_field(get_value_ival(params_count), TAC_OPTYPE_INT);
    cgen_append(&inst, cgen_instr(NULL, TAC_CALL, function_label, field_params_count, NULL));               
  
    if (!type_eq(sym->type, &TYPE_EXPRESSION_VOID)) {
        cgen_append(&inst, cgen_instr(NULL, TAC_POP, cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), NULL, NULL));               
    }

    return inst;
}

/**
 * Assume-se que e um acesso valido na hierarquia do simbolo passado, dimensões possuem código gerado para indice de acesso
 * Sempre que requisitado um acesso valor/endereco sera carregado e informado como instrucao
*/
Instruction *cgen_var_access(SymbolNode *sym, Node *dimension, int *temp_inst_count) {
    Node *cur_access = dimension;
    TypeExpression *cur_type = sym->type;
    Instruction *inst = NULL;

    Field *adress_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
    cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, adress_index, sym->tac_ref->adress_index, NULL));
    cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, cgen_field_adress(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP, adress_index), sym->tac_ref, NULL));

    while (cur_access) {
        switch(cur_type->node_type) {
            case GTYPE_INT:     break;
            case GTYPE_FLOAT:   break;
            case GTYPE_GRAPH:
            case GTYPE_ARRAY: {
                // Graph entra aqui para reaproveitar processamento de array
                if (cur_type->node_type == GTYPE_GRAPH) {
                     // Valor de vertices do grafo estara na segunda posicao [sz][ponteiro vertice com valores][ponteiro para array de arestas]
                    Field *adress       = cgen_last_inst(inst)->fields[0];
                    Field *adress_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
                    Field *array_index  = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);

                    // Endereco informado + 1 para acessar variavel que guarda endereco de array
                    cgen_append(&inst, cgen_instr(NULL, TAC_ADD, adress_index, adress->adress_index, cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));
                    cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, array_index, cgen_field(get_value_ival(0), TAC_OPTYPE_INT), NULL));
                    // Array sera colocado aqui com index de acesso em zero
                    cgen_append(&inst, cgen_instr(NULL, TAC_MOVVI, cgen_field_adress(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP, array_index), adress, adress_index));
                }
               
                // Calcular tamanho das dimensoes restantes esquema ROW-MAJOR
                Field *adress           = cgen_last_inst(inst)->fields[0];
                Field *user_index       = cgen_last_inst(cur_access->code)->fields[0]; 
                Field *offset           = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP); 
                Field *adress_index     = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP); 
                int type_contained_sz   = type_mem_sz(cur_type->child);

                cgen_append(&inst, cur_access->code);
                // copia para nao zuar com indice anterior
                cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, adress_index, adress->adress_index, NULL));
                cgen_append(&inst, cgen_instr(NULL, TAC_MUL, offset, user_index, cgen_field(get_value_ival(type_contained_sz), TAC_OPTYPE_INT)));
                // Adicionar 1 por causa do offset de tamanho adicionado no inicio do array
                cgen_append(&inst, cgen_instr(NULL, TAC_ADD, adress_index, offset, cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));                
                cgen_append(
                    &inst, 
                    cgen_instr(
                        NULL, 
                        TAC_MOVVV, 
                        cgen_field_adress(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP, adress_index), 
                        adress, 
                        NULL
                    )
                );

                break;
            }
            default: 
                printf("ERRO: type not found for access");
                exit(0);
        }

        cur_access = cur_access->next;
        cur_type = cur_type->child;
    }

    return inst;
}

Instruction* cgen_const_code(OperandType type, int ival, float fval, int *temp_inst_count) {   
    Instruction *inst = NULL;

    Field *field;
    if (type == TAC_OPTYPE_INT) {
        field = cgen_field(get_value_ival(ival) , type);
    } else {
        field = cgen_field(get_value_fval(fval) , type);
    }

    cgen_append(
        &inst,
        cgen_instr(
            NULL,
            TAC_MOVVV,
            cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP),
            field,
            NULL
        )
    );

    return inst;
}

/**
 * Assign assume que lado esquerdo sera sempre um campo de endereço
*/
Instruction* cgen_assign(Node *dst, Node *src, int *temp_inst_count) {
    Instruction *inst = NULL;
    
    cgen_append(&(src->code), cgen_derref_lvalue(cgen_last_inst(src->code)->fields[0], temp_inst_count));
    cgen_append(&(src->code), cgen_cast(cgen_last_inst(src->code)->fields[0], src->cast, temp_inst_count));

    cgen_append(
        &inst,
        cgen_instr(
            NULL,
            TAC_MOVIV,
            cgen_last_inst(dst->code)->fields[0],
            cgen_last_inst(dst->code)->fields[0]->adress_index,
            cgen_last_inst(src->code)->fields[0]
        )
    );

    // Necessario ocorrer apos para que campos convertidos acima por derref estejam corretos
    cgen_append(&(dst->code), src->code);
    cgen_append(&(dst->code), inst);
    inst = dst->code;

    return inst;
}

Instruction* cgen_expression_aritmetic(Node *a, Node *b, InstCode code, int *temp_inst_count) {
    Instruction *inst = NULL;

    cgen_append(&(a->code), cgen_derref_lvalue(cgen_last_inst(a->code)->fields[0], temp_inst_count));
    cgen_append(&(a->code), cgen_cast(cgen_last_inst(a->code)->fields[0], a->cast, temp_inst_count));

    cgen_append(&(b->code), cgen_derref_lvalue(cgen_last_inst(b->code)->fields[0], temp_inst_count));
    cgen_append(&(b->code), cgen_cast(cgen_last_inst(b->code)->fields[0], b->cast, temp_inst_count));

    cgen_append(
        &inst,
        cgen_instr(
        NULL,
        code,
        cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP),
        cgen_last_inst(a->code)->fields[0],
        cgen_last_inst(b->code)->fields[0]
        )
    );  

    // Necessario ocorrer apos para que campos convertidos acima por derref estejam corretos
    cgen_append(&(a->code), b->code);
    cgen_append(&(a->code), inst);
    inst = a->code;

    return inst;
}

Instruction* cgen_expression_boolean(Node *a, Node *b, InstCode code, int *temp_inst_count) {
    return cgen_expression_aritmetic(a, b, code, temp_inst_count);
}

Instruction* cgen_expression_relational(Node *a, Node *b, int op, int *temp_inst_count) {
    Instruction *inst = NULL;

    cgen_append(&(a->code), cgen_derref_lvalue(cgen_last_inst(a->code)->fields[0], temp_inst_count));
    cgen_append(&(a->code), cgen_cast(cgen_last_inst(a->code)->fields[0], a->cast, temp_inst_count));

    cgen_append(&(b->code), cgen_derref_lvalue(cgen_last_inst(b->code)->fields[0], temp_inst_count));
    cgen_append(&(b->code), cgen_cast(cgen_last_inst(b->code)->fields[0], b->cast, temp_inst_count));

    Instruction *eq     = cgen_instr(NULL, TAC_SEQ,   cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), cgen_last_inst(a->code)->fields[0], cgen_last_inst(b->code)->fields[0]);
    Instruction *less   = cgen_instr(NULL, TAC_SLT,   cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), cgen_last_inst(a->code)->fields[0], cgen_last_inst(b->code)->fields[0]);
    Instruction *le     = cgen_instr(NULL, TAC_SLEQ,  cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), cgen_last_inst(a->code)->fields[0], cgen_last_inst(b->code)->fields[0]);

    switch(op) {
        case LE: {
            cgen_append(&inst, le);
            break;
        }  
        case GREATER: {
            cgen_append(&inst, le);
            cgen_append(&inst, cgen_instr(NULL, TAC_NOT, cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), le->fields[0], NULL));
            break;
        }       
        case LESS: {
            cgen_append(&inst, less);
            break;
        }          
        case GE: {
            cgen_append(&inst, less);
            cgen_append(&inst, cgen_instr(NULL, TAC_NOT, cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), less->fields[0], NULL));
            break;
        }            
        case EQ: {
            cgen_append(&inst, eq);
            break;
        }            
        case NE: {
            cgen_append(&inst, eq);
            cgen_append(&inst, cgen_instr(NULL, TAC_NOT, cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), eq->fields[0], NULL));
            break;
        }
        default: 
            printf("ERRO: relational expression not found");
            exit(0);
    }

    cgen_append(&(a->code), b->code);
    cgen_append(&(a->code), inst);
    inst = a->code;
    return inst;
}

Instruction* cgen_expression_unary(Node *a, int op, int *temp_inst_count) {
    Instruction *inst = NULL;

    cgen_append(&(a->code), cgen_derref_lvalue(cgen_last_inst(a->code)->fields[0], temp_inst_count));
    cgen_append(&(a->code), cgen_cast(cgen_last_inst(a->code)->fields[0], a->cast, temp_inst_count));
   
    Field *field = cgen_last_inst(a->code)->fields[0];

    switch(op) {
        case NOT: {
            cgen_append(&inst, cgen_instr(NULL, TAC_NOT, cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), field, NULL));
            break;
        }       
        case SUB: {
            cgen_append(&inst, cgen_instr(NULL, TAC_MINUS, cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), field, NULL));
            break;
        }            
        case ADD: {
            break;
        }
        default: 
            printf("ERRO: relational expression not found");
            exit(0);
    }

    cgen_append(&(a->code), inst);
    inst = a->code;
    return inst;
}

Instruction *cgen_write_string(char *string) {
    if (string == NULL) {
        return NULL;
    }
    Instruction *inst = NULL;

    int i;
    for (i = 0; i < (int)strlen(string); ++i) {
        char buffer[200] = {0};
        sprintf(buffer, "'%c'", string[i]);
        if (string[i] == '\n') {
            cgen_append(&inst, cgen_instr(NULL, TAC_PRINTLN, NULL, NULL, NULL));       
        } else {
            cgen_append(&inst, cgen_instr(NULL, TAC_PRINT, cgen_field(get_value_label(cgen_label(buffer, 1)), TAC_OPTYPE_LABEL), NULL, NULL));       
        }
    }
    return inst;
}


/**
 * @param code contem codigo com field inicial sendo o destino a ser printado, pode ser lval ou rval
*/
Instruction *cgen_write_array(TypeExpression *type, Instruction *code, int *temp_inst_count) {
    if (type->node_type == GTYPE_ARRAY) {
        Instruction *inst = NULL;
        cgen_append(
            &inst,
            cgen_instr(NULL, TAC_PRINT, cgen_field(get_value_label(cgen_label("'['", 1)), TAC_OPTYPE_LABEL), NULL, NULL)
        );

        Field *sz           = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
        Field *index        = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP); 
        Field *base_adress  = cgen_field_adress(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP, index);
        
        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, index, cgen_last_inst(code)->fields[0]->adress_index, NULL));
        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, base_adress, cgen_last_inst(code)->fields[0], NULL));
        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVI, sz, base_adress, base_adress->adress_index));
        // Adicionar 1 para pular o sz
        cgen_append(&inst, cgen_instr(NULL, TAC_ADD, index, index, cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));

        Field *offset           = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP); 
        int type_contained_sz   = type_mem_sz(type->child);

        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, offset, cgen_field(get_value_ival(type_contained_sz), TAC_OPTYPE_INT), NULL));      

        Label* loop_init_label = cgen_label_by_counter();
        Label* loop_end_label = cgen_label_by_counter();
        
        {
            cgen_append(&inst, cgen_instr(loop_init_label, TAC_BRZ, cgen_field(get_value_label(loop_end_label), TAC_OPTYPE_LABEL), sz, NULL));
            // Faz com que adress seja disponibilizado como ultima instrucao antes do write abaixo que espera endereco
            cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, base_adress, base_adress, NULL));

            cgen_append(&inst, cgen_write(type->child, inst, temp_inst_count));

            cgen_append(&inst, cgen_instr(NULL, TAC_PRINT, cgen_field(get_value_label(cgen_label("','", 1)), TAC_OPTYPE_LABEL), NULL, NULL));
            cgen_append(&inst, cgen_instr(NULL, TAC_PRINT, cgen_field(get_value_label(cgen_label("' '", 1)), TAC_OPTYPE_LABEL), NULL, NULL));
            cgen_append(&inst, cgen_instr(NULL, TAC_ADD, index, index, offset));        
            cgen_append(&inst, cgen_instr(NULL, TAC_SUB, sz, sz, cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));
            cgen_append(&inst, cgen_instr(NULL, TAC_JUMP, cgen_field(get_value_label(loop_init_label), TAC_OPTYPE_LABEL), NULL, NULL));
        }

        cgen_append(&inst, cgen_instr(loop_end_label, TAC_PRINT, cgen_field(get_value_label(cgen_label("'#'", 1)), TAC_OPTYPE_LABEL), NULL, NULL));
        cgen_append(&inst, cgen_instr(NULL, TAC_PRINT, cgen_field(get_value_label(cgen_label("']'", 1)), TAC_OPTYPE_LABEL), NULL, NULL));

        return inst;
    } else {
        printf("ERRO: type must be array");
        exit(0);
        return NULL;
    }
}

/**
 * @param code contem codigo com field inicial sendo o destino a ser printado, pode ser lval ou rval
*/
Instruction *cgen_write(TypeExpression *type, Instruction *code, int *temp_inst_count) {
    Instruction *inst = NULL;
    switch(type->node_type) {
        case GTYPE_INT:     
        case GTYPE_FLOAT: {
            cgen_append(
                &inst,
                cgen_derref_lvalue(cgen_last_inst(code)->fields[0], temp_inst_count)
            );

            // caso seja lvalue sera derreferenciado para novo temporario do tac
            Field *value = inst == NULL ?
                cgen_last_inst(code)->fields[0] :
                cgen_last_inst(inst)->fields[0] ;

            cgen_append(
                &inst,
                cgen_instr(NULL, TAC_PRINT, value, NULL, NULL)
            );

            break;
        }
        case GTYPE_GRAPH: {
            cgen_append(&inst, cgen_write_string("GRAPH:\n"));
            {
                cgen_append(&inst, cgen_write_string("VALUES:"));

                Field *values_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
                cgen_append(&inst, cgen_instr(NULL, TAC_ADD, values_index, cgen_last_inst(code)->fields[0]->adress_index, cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));

                Field *vadress_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
                Field *vadress = cgen_field_adress(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP, vadress_index);

                cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, vadress_index, cgen_field(get_value_ival(0), TAC_OPTYPE_INT), NULL));
                cgen_append(&inst, cgen_instr(NULL, TAC_MOVVI, vadress, cgen_last_inst(code)->fields[0], values_index));

                cgen_append(&inst, cgen_write_array(&TYPE_EXPRESSION_ARRAY_INT, inst, temp_inst_count));
                cgen_append(&inst, cgen_write_string("\n"));          
            }

            {
                cgen_append(&inst, cgen_write_string("EDGES:\n"));

            }

            cgen_append(&inst, cgen_write_string("========\n"));
            break;
        }
        case GTYPE_ARRAY: {
            cgen_append(&inst, cgen_write_string("ARRAY: "));
            cgen_append(&inst, cgen_write_array(type, code, temp_inst_count));
            break;  
        } 
        default: break;
    }   

    return inst;
}

Instruction* cgen_if(Node* dst, Instruction* condition, Node* body, int *temp_inst_count) {
    Instruction *inst = condition;
    cgen_append(&inst, cgen_derref_lvalue(cgen_last_inst(inst)->fields[0], temp_inst_count));

    Field* field_condition = cgen_last_inst(inst)->fields[0];
    Field *field_label_else = cgen_field(get_value_label(cgen_label("_", 0)), TAC_OPTYPE_LABEL);
    
    cgen_append(&inst, cgen_instr(NULL, TAC_BRZ, field_label_else, field_condition, NULL));
    cgen_append(&inst, body->code);

    dst->back_patch = cgen_patch(field_label_else);
    dst->back_patch = cgen_merge_patch(dst->back_patch, body->back_patch);

    return inst;
}

Instruction* cgen_if_else(Node* dst, Instruction* condition, Node* body_if, Node* else_statement, int *temp_inst_count) {
    Instruction *inst = condition;
    cgen_append(&inst, cgen_derref_lvalue(cgen_last_inst(inst)->fields[0], temp_inst_count));

    // Caso else statement seja um bloco vazio sabe se la porque usuario faria isso
    if (else_statement->code == NULL) {
        else_statement->code = cgen_instr(NULL, TAC_NOP, NULL, NULL, NULL);
    }

    if (else_statement->code->label == NULL) {
        else_statement->code->label = cgen_label_by_counter();
    }

    Field* field_condition      = cgen_last_inst(inst)->fields[0];
    Field *field_label_else     = cgen_field(get_value_label(else_statement->code->label), TAC_OPTYPE_LABEL);      
    Field *field_next_statement = cgen_field(get_value_label(cgen_label("_", 0)), TAC_OPTYPE_LABEL);

    cgen_append(&inst, cgen_instr(NULL, TAC_BRZ, field_label_else, field_condition, NULL));
    cgen_append(&inst, body_if->code);
    cgen_append(&inst, cgen_instr(NULL, TAC_JUMP, field_next_statement, NULL, NULL));
    cgen_append(&inst, else_statement->code);

    dst->back_patch = cgen_patch(field_next_statement);
    dst->back_patch = cgen_merge_patch(dst->back_patch, body_if->back_patch);
    dst->back_patch = cgen_merge_patch(dst->back_patch, else_statement->back_patch);

    return inst;
}

Instruction* cgen_while(Node* dst, Instruction* condition, Node* body, int *temp_inst_count) {
    Instruction *inst = NULL;

    Label *init_while           = cgen_label_by_counter();
    Label *end_while            = cgen_label_by_counter();

    cgen_append(&inst, cgen_instr(init_while, TAC_NOP, NULL, NULL, NULL));
    cgen_append(&inst, condition);
    cgen_append(&inst, cgen_derref_lvalue(cgen_last_inst(inst)->fields[0], temp_inst_count));

    Field* field_condition      = cgen_last_inst(inst)->fields[0];
    Field *field_next_statement = cgen_field(get_value_label(cgen_label("_", 0)), TAC_OPTYPE_LABEL);
    
    cgen_append(&inst, cgen_instr(NULL, TAC_BRZ, field_next_statement, field_condition, NULL));
    cgen_append(&inst, body->code);
    cgen_append(&inst, cgen_instr(end_while, TAC_JUMP, cgen_field(get_value_label(init_while), TAC_OPTYPE_LABEL), NULL, NULL));

    cgen_back_patch(body->back_patch, end_while);
    dst->back_patch = cgen_patch(field_next_statement);

    return inst;
}

Instruction* cgen_for(Node* dst, Instruction *init, Instruction* condition, Instruction *increment, Node* body, int *temp_inst_count) {
    Instruction *inst = init;

    Label *init_for = cgen_label_by_counter();
    Label *end_for  = cgen_label_by_counter();

    cgen_append(&inst, cgen_instr(init_for, TAC_NOP, NULL, NULL, NULL));
    cgen_append(&inst, condition);
    cgen_append(&inst, cgen_derref_lvalue(cgen_last_inst(inst)->fields[0], temp_inst_count));

    Field* field_condition      = cgen_last_inst(inst)->fields[0];
    Field *field_next_statement = cgen_field(get_value_label(cgen_label("_", 0)), TAC_OPTYPE_LABEL);
    
    cgen_append(&inst, cgen_instr(NULL, TAC_BRZ, field_next_statement, field_condition, NULL));
    cgen_append(&inst, body->code);
    cgen_append(&inst, cgen_instr(end_for, TAC_NOP, NULL, NULL, NULL));
    cgen_append(&inst, increment);
    cgen_append(&inst, cgen_instr(NULL, TAC_JUMP, cgen_field(get_value_label(init_for), TAC_OPTYPE_LABEL), NULL, NULL));

    cgen_back_patch(body->back_patch, end_for);
    dst->back_patch = cgen_patch(field_next_statement);

    return inst;
}

/**
 * E assumido que destino e maior ou igual a tamanho da fonte
*/
Instruction* cgen_cpy_array(Field *dst_adress, Field *src_adress, int *temp_inst_count) {
    Instruction *inst = NULL;

    // Tamanho sempre estara no inicio do array
    Field *sz = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
    cgen_append(&inst, cgen_instr(NULL, TAC_MOVVI, sz, src_adress, src_adress->adress_index));

    Field *index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
    cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, index, cgen_field(get_value_ival(1), TAC_OPTYPE_INT), NULL));

    Field *init_loop = cgen_field(get_value_label(cgen_label_by_counter()), TAC_OPTYPE_LABEL);
    Field *end_loop  = cgen_field(get_value_label(cgen_label_by_counter()), TAC_OPTYPE_LABEL);
    Field *condition = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
    cgen_append(&inst, cgen_instr(init_loop->value.label, TAC_SLEQ, condition, index, sz));
    cgen_append(&inst, cgen_instr(NULL, TAC_BRZ, end_loop, condition, NULL));
    
    {
        // src_adress + adress + index
        Field *src_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
        Field *dst_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);

        cgen_append(&inst, cgen_instr(NULL, TAC_ADD, src_index, src_adress->adress_index, index));
        cgen_append(&inst, cgen_instr(NULL, TAC_ADD, dst_index, dst_adress->adress_index, index));

        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVI, cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), src_adress, src_index));
        cgen_append(&inst, cgen_instr(NULL, TAC_MOVIV, dst_adress, dst_index, cgen_last_inst(inst)->fields[0]));

        cgen_append(&inst, cgen_instr(NULL, TAC_ADD, index, index, cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));
        cgen_append(&inst, cgen_instr(NULL, TAC_JUMP, init_loop, NULL, NULL));
    }

    cgen_append(&inst, cgen_instr(end_loop->value.label, TAC_NOP, NULL, NULL, NULL));

    return inst;
}

Instruction* cgen_addv(Instruction *graph, int *temp_inst_count) {
    Instruction *inst = NULL;

    // Atualizar sz para + 1
    Field *graph_adress = cgen_last_inst(graph)->fields[0];
    Field *sz = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
    cgen_append(&inst, cgen_instr(NULL, TAC_MOVVI, cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP), graph_adress, graph_adress->adress_index));
    cgen_append(&inst, cgen_instr(NULL, TAC_ADD, sz, cgen_last_inst(inst)->fields[0], cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));
    cgen_append(&inst, cgen_instr(NULL, TAC_MOVIV, graph_adress, graph_adress->adress_index, sz));

    // Tratar vetor de vertices
    {
        // indice para o ponteiro de vertices, utilizado no caso de array de grafos
        Field *values_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
        cgen_append(&inst, cgen_instr(NULL, TAC_ADD, values_index, graph_adress->adress_index, cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));

        // gerar novo vetor para valor de vertices com tamanho + 1
        Field *new_vadress_index    = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
        Field *new_vadress          = cgen_field_adress(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP, new_vadress_index);
        Field *alloc_size           = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);;

        cgen_append(&inst, cgen_instr(NULL, TAC_ADD, alloc_size, sz, cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));

        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, new_vadress_index, cgen_field(get_value_ival(0), TAC_OPTYPE_INT), NULL));
        cgen_append(&inst, cgen_instr(NULL, TAC_MEMA, new_vadress, alloc_size, NULL));
        //TODO: fill esta levando em consideracao tamanho do array passado na type expression
        cgen_append(&inst, cgen_fill_mem(new_vadress, &TYPE_EXPRESSION_ARRAY_INT, 0, 0));
        // Preencher sz depois de fill
        cgen_append(&inst, cgen_instr(NULL, TAC_MOVIV, new_vadress, new_vadress_index, sz));

        // Copiar valores anteriores
        Field *old_vadress_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
        Field *old_vadress = cgen_field_adress(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP, new_vadress_index);

        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, old_vadress_index, cgen_field(get_value_ival(0), TAC_OPTYPE_INT), NULL));
        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVI, old_vadress, graph_adress, values_index));

        // Caso tamanhho atual seja 1 array passado tinha tamanho zero nao sera necessario alocar nem liberar
        Field *jump_cpy = cgen_field(get_value_label(cgen_label_by_counter()), TAC_OPTYPE_LABEL);
        Field *condition = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
        cgen_append(&inst, cgen_instr(NULL, TAC_SEQ, condition, cgen_field(get_value_ival(1), TAC_OPTYPE_INT), sz));
        cgen_append(&inst, cgen_instr(NULL, TAC_BRNZ, jump_cpy, condition, NULL));

        cgen_append(&inst, cgen_cpy_array(new_vadress, old_vadress, temp_inst_count));
        cgen_append(&inst, cgen_instr(NULL, TAC_MEMF, old_vadress, NULL, NULL));    

        // atualizar ponteiro para novo vetor
        cgen_append(&inst, cgen_instr(jump_cpy->value.label, TAC_MOVIV, graph_adress, values_index, new_vadress));
    }


    // gerar novo vetor de arestas com tamanho + 1
    // Copiar valores anteriores
    // lliberar vetor antigo
    // atualizar ponteiro para novo vetor

    return inst;
}


/*---------------------FREE-------------------------*/

void free_cgen() {
    GenericList *cur = alloc;
    while(cur) {
        GenericList* next = cur->previous;
        free(cur->cur);
        free(cur);
        cur = next;
    }
}

/*--------------------PRINT CODE------------------------*/

char* field_toa(Field *field) {
    if (field == NULL) {
        return strdup("");
    }

    char buffer[300] = {0};
    switch (field->type) {
        case TAC_OPTYPE_TEMP:   sprintf(buffer, "$%d", field->value.ival);        break;
        case TAC_OPTYPE_PARAM:  sprintf(buffer, "#%d", field->value.ival);        break;
        case TAC_OPTYPE_INT:    sprintf(buffer, "%d", field->value.ival);         break;
        case TAC_OPTYPE_FLOAT:  sprintf(buffer, "%f", field->value.fval);         break;
        case TAC_OPTYPE_LABEL:  sprintf(buffer, "%s", field->value.label->value); break;
        default:
            printf("ERROR: tac operand not identified\n");
            exit(0);
    }

    return strdup(buffer);
}

void print_inst(Instruction *inst) {
    if (inst == NULL) {
        return;
    }

    char buffer[300] = {0};
    char label[50] = {0};
    char *field[3] = {
        field_toa(inst->fields[0]),
        field_toa(inst->fields[1]),
        field_toa(inst->fields[2])
    };

    if (inst->label != NULL) 
        sprintf(label, "%s:\n", inst->label->value);

    switch (inst->inst_code) {
        case TAC_ADD:     sprintf(buffer, "%sadd %s, %s, %s", label, field[0], field[1], field[2]);         break;
        case TAC_SUB:     sprintf(buffer, "%ssub %s, %s, %s", label, field[0], field[1], field[2]);         break;
        case TAC_MUL:     sprintf(buffer, "%smul %s, %s, %s", label, field[0], field[1], field[2]);         break;
        case TAC_DIV:     sprintf(buffer, "%sdiv %s, %s, %s", label, field[0], field[1], field[2]);         break;
        case TAC_AND:     sprintf(buffer, "%sand %s, %s, %s", label, field[0], field[1], field[2]);         break;
        case TAC_OR:      sprintf(buffer, "%sor %s, %s, %s",  label, field[0], field[1], field[2]);         break;
        case TAC_MINUS:   sprintf(buffer, "%sminus %s, %s", label, field[0], field[1]);                     break;
        case TAC_NOT:     sprintf(buffer, "%snot %s, %s", label, field[0], field[1]);                       break;
        case TAC_SEQ:     sprintf(buffer, "%sseq %s, %s, %s", label, field[0], field[1], field[2]);         break;
        case TAC_SLT:     sprintf(buffer, "%sslt %s, %s, %s", label, field[0], field[1], field[2]);         break;
        case TAC_SLEQ:    sprintf(buffer, "%ssleq %s, %s, %s", label, field[0], field[1], field[2]);        break;
        case TAC_BAND:    sprintf(buffer, "band");                                                          break;
        case TAC_BOR:     sprintf(buffer, "bor");                                                           break;
        case TAC_BXOR:    sprintf(buffer, "bxor");                                                          break;
        case TAC_SHL:     sprintf(buffer, "shl");                                                           break;
        case TAC_SHR:     sprintf(buffer, "shr");                                                           break;
        case TAC_BNOT:    sprintf(buffer, "bnot");                                                          break;
        case TAC_MOD:     sprintf(buffer, "mod");                                                           break;
        case TAC_CHTOINT: sprintf(buffer, "chtoint");                                                       break;
        case TAC_CHTOFL:  sprintf(buffer, "chtofl");                                                        break;
        case TAC_INTTOCH: sprintf(buffer, "inttoch");                                                       break;
        case TAC_INTTOFL: sprintf(buffer, "%sinttofl %s, %s", label, field[0], field[1]);                   break;
        case TAC_FLTOCH:  sprintf(buffer, "fltoch");                                                        break;
        case TAC_FLTOINT: sprintf(buffer, "%sfltoint %s, %s", label, field[0], field[1]);                   break;
        case TAC_MOVVV:   sprintf(buffer, "%smov %s, %s", label, field[0], field[1]);                       break;
        case TAC_MOVVD:   sprintf(buffer, "%smov %s, *%s", label, field[0], field[1]);                      break;
        case TAC_MOVVA:   sprintf(buffer, "%smov %s, &%s", label, field[0], field[1]);                      break;
        case TAC_MOVVI:   sprintf(buffer, "%smov %s, %s[%s]", label, field[0], field[1], field[2]);         break;
        case TAC_MOVDV:   sprintf(buffer, "%smov *%s, %s", label, field[0], field[1]);                      break;
        case TAC_MOVDD:   sprintf(buffer, "movdd");                                                         break;
        case TAC_MOVDA:   sprintf(buffer, "movda");                                                         break;
        case TAC_MOVDI:   sprintf(buffer, "movdi");                                                         break;
        case TAC_MOVIV:   sprintf(buffer, "%smov %s[%s], %s", label, field[0], field[1], field[2]);         break;
        case TAC_MOVID:   sprintf(buffer, "movid");                                                         break;
        case TAC_MOVIA:   sprintf(buffer, "movia");                                                         break;
        case TAC_POP:     sprintf(buffer, "%spop %s", label, field[0]);                                     break;
        case TAC_BRZ:     sprintf(buffer, "%sbrz %s, %s", label, field[0], field[1]);                       break;
        case TAC_BRNZ:    sprintf(buffer, "%sbrnz %s, %s", label, field[0], field[1]);                      break;
        case TAC_JUMP:    sprintf(buffer, "%sjump %s", label, field[0]);                                    break;
        case TAC_PARAM:   sprintf(buffer, "%sparam %s", label, field[0]);                                   break;
        case TAC_PRINT:   sprintf(buffer, "%sprint %s", label, field[0]);                                   break;
        case TAC_PRINTLN: sprintf(buffer, "%sprintln %s", label, field[0]);                                 break;
        case TAC_SCANC:   sprintf(buffer, "scanc");                                                         break;
        case TAC_SCANI:   sprintf(buffer, "scani");                                                         break;
        case TAC_SCANF:   sprintf(buffer, "scanf");                                                         break;
        case TAC_RAND:    sprintf(buffer, "rand");                                                          break;
        case TAC_MEMA:    sprintf(buffer, "%smema %s, %s", label, field[0], field[1]);                      break;
        case TAC_MEMF:    sprintf(buffer, "%smemf %s", label, field[0]);                                    break;
        case TAC_CALL:    sprintf(buffer, "%scall %s, %s", label, field[0], field[1]);                      break;
        case TAC_RETURN:  sprintf(buffer, "%sreturn %s", label, field[0]);                                  break;
        case TAC_PUSH:    sprintf(buffer, "push");                                                          break;
        case TAC_NOP:     sprintf(buffer, "%snop", label);                                                  break;
        default:
            printf("ERROR: tac instruction not identified\n");
            exit(0);
    }

    for (int i = 0; i < 3; ++i) {
        if (field[i]) free(field[i]);
    }

    printf("%s\n", buffer);
}

void print_code(Instruction *code) {
    printf(".code\n");

    if (code == NULL) {
        return;
    }

    Instruction *cur = code;
    while(cur) {
        print_inst(cur);
        cur = cur->next;
    }
}
