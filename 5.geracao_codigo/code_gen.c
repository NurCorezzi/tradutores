#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "code_gen.h"
#include "node.h"

extern int next_instruction;
extern int label_count;

// GAMIARRA: evitar dependencia circular que tambem ocorreria em code_gen.h
Instruction *cgen_write(TypeExpression *type, Instruction *code, int *temp_inst_count);
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

/*---------------------HELPER-------------------------*/

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
            TypeExpression TYPE_EXPRESSION_INT = {0, NULL, GTYPE_INT};
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
        case GTYPE_FLOAT:   
        case GTYPE_GRAPH:     
        case GTYPE_ARRAY: 
        case GTYPE_INT: {
            Field *var_adress = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
            cgen_append(
                &inst,
                cgen_instr(
                    cgen_label(sym->id, 0), 
                    TAC_MEMA, 
                    var_adress, 
                    cgen_field(get_value_ival(sz), TAC_OPTYPE_INT), 
                    NULL
                )
            );

            sym->tac_ref = var_adress;
            cgen_append(&inst, cgen_fill_mem(var_adress, sym->type, 0, 0));
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

Instruction* cgen_declaration_param(SymbolNode *sym, int *param_inst_count) {
    Instruction *inst = NULL;

    switch(sym->type->node_type) {
        case GTYPE_FLOAT:   
        case GTYPE_INT: {
            Field *value = cgen_field(get_value_ival((*param_inst_count)++), TAC_OPTYPE_PARAM);
            sym->tac_ref = value;
            break;
        }
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
 * Assume-se que e um acesso valido na hierarquia do simbolo passado, dimensões possuem código gerado para indice de acesso
*/
Instruction *cgen_var_access(SymbolNode *sym, Node *dimension, int *temp_inst_count) {
    Node *cur_access = dimension;
    TypeExpression *cur_type = sym->type;
    Instruction *inst = NULL;

    // Estrategia assume que resultado sempre sera extraido de um endereco inicial
    Field *adress_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
    cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, adress_index, cgen_field(get_value_ival(0), TAC_OPTYPE_INT), NULL));
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
                    Field *adress = cgen_last_inst(inst)->fields[0];
                    Field *adress_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);
                    Field *array_index = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP);

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
        
        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, base_adress, cgen_last_inst(code)->fields[0], NULL));
        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVI, sz, base_adress, cgen_field(get_value_ival(0), TAC_OPTYPE_INT)));
        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, index, cgen_last_inst(code)->fields[0]->adress_index, NULL));
        // Adicionar 1 para pular o sz
        cgen_append(&inst, cgen_instr(NULL, TAC_ADD, index, index, cgen_field(get_value_ival(1), TAC_OPTYPE_INT)));

        Field *offset           = cgen_field(get_value_ival((*temp_inst_count)++), TAC_OPTYPE_TEMP); 
        int type_contained_sz   = type_mem_sz(type->child);

        cgen_append(&inst, cgen_instr(NULL, TAC_MOVVV, offset, cgen_field(get_value_ival(type_contained_sz), TAC_OPTYPE_INT), NULL));      

        Label* loop_init_label = cgen_label_by_counter();
        Label* loop_end_label = cgen_label_by_counter();
        
        {
            cgen_append(&inst, cgen_instr(loop_init_label, TAC_BRZ, cgen_field(get_value_label(loop_end_label), TAC_OPTYPE_LABEL), sz, NULL));
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
            break;
        }
        case GTYPE_ARRAY: {
            cgen_append(
                &inst,
                cgen_write_array(type, code, temp_inst_count)
            );
            
            break;  
        } 
        default: break;
    }   

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
        case TAC_MINUS:   sprintf(buffer, "minus");                                                         break;
        case TAC_NOT:     sprintf(buffer, "not");                                                           break;
        case TAC_SEQ:     sprintf(buffer, "seq");                                                           break;
        case TAC_SLT:     sprintf(buffer, "slt");                                                           break;
        case TAC_SLEQ:    sprintf(buffer, "sleq");                                                          break;
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
        case TAC_INTTOFL: sprintf(buffer, "inttofl");                                                       break;
        case TAC_FLTOCH:  sprintf(buffer, "fltoch");                                                        break;
        case TAC_FLTOINT: sprintf(buffer, "fltoint");                                                       break;
        case TAC_MOVVV:   sprintf(buffer, "%smov %s, %s", label, field[0], field[1]);                       break;
        case TAC_MOVVD:   sprintf(buffer, "%smov %s, *%s", label, field[0], field[1]);                      break;
        case TAC_MOVVA:   sprintf(buffer, "movva");                                                         break;
        case TAC_MOVVI:   sprintf(buffer, "%smov %s, %s[%s]", label, field[0], field[1], field[2]);         break;
        case TAC_MOVDV:   sprintf(buffer, "%smov *%s, %s", label, field[0], field[1]);                      break;
        case TAC_MOVDD:   sprintf(buffer, "movdd");                                                         break;
        case TAC_MOVDA:   sprintf(buffer, "movda");                                                         break;
        case TAC_MOVDI:   sprintf(buffer, "movdi");                                                         break;
        case TAC_MOVIV:   sprintf(buffer, "%smov %s[%s], %s", label, field[0], field[1], field[2]);         break;
        case TAC_MOVID:   sprintf(buffer, "movid");                                                         break;
        case TAC_MOVIA:   sprintf(buffer, "movia");                                                         break;
        case TAC_POP:     sprintf(buffer, "pop");                                                           break;
        case TAC_BRZ:     sprintf(buffer, "%sbrz %s, %s", label, field[0], field[1]);                       break;
        case TAC_BRNZ:    sprintf(buffer, "%sbrnz %s, %s", label, field[0], field[1]);                      break;
        case TAC_JUMP:    sprintf(buffer, "%sjump %s", label, field[0]);                                    break;
        case TAC_PARAM:   sprintf(buffer, "param");                                                         break;
        case TAC_PRINT:   sprintf(buffer, "%sprint %s", label, field[0]);                                   break;
        case TAC_PRINTLN: sprintf(buffer, "%sprintln %s", label, field[0]);                                 break;
        case TAC_SCANC:   sprintf(buffer, "scanc");                                                         break;
        case TAC_SCANI:   sprintf(buffer, "scani");                                                         break;
        case TAC_SCANF:   sprintf(buffer, "scanf");                                                         break;
        case TAC_RAND:    sprintf(buffer, "rand");                                                          break;
        case TAC_MEMA:    sprintf(buffer, "%smema %s, %s", label, field[0], field[1]);                      break;
        case TAC_MEMF:    sprintf(buffer, "memf");                                                          break;
        case TAC_CALL:    sprintf(buffer, "call");                                                          break;
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
