#ifndef CODE_GEN_H
#define CODE_GEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

/*---------------DEFINITIONS------------------*/

typedef enum {
    TAC_ADD     = 0x00, TAC_BAND    = 0x10, TAC_CHTOINT = 0x20, TAC_MOVVV   = 0x30, TAC_MEMA    = 0x40, TAC_BRZ     = 0x50, 
    TAC_SUB     = 0x01, TAC_BOR     = 0x11, TAC_CHTOFL  = 0x22, TAC_MOVVD   = 0x31, TAC_POP     = 0x41, TAC_BRNZ    = 0x51, 
    TAC_MUL     = 0x02, TAC_BXOR    = 0x12, TAC_INTTOCH = 0x24, TAC_MOVVA   = 0x32, TAC_SCANC   = 0x42, TAC_JUMP    = 0x52, 
    TAC_DIV     = 0x03, TAC_SHL     = 0x13, TAC_INTTOFL = 0x26, TAC_MOVVI   = 0x33, TAC_SCANI   = 0x43, TAC_PARAM   = 0x53, 
    TAC_AND     = 0x04, TAC_SHR     = 0x14, TAC_FLTOCH  = 0x28, TAC_MOVDV   = 0x34, TAC_SCANF   = 0x44, TAC_PRINT   = 0x54, 
    TAC_OR      = 0x05, TAC_BNOT    = 0x15, TAC_FLTOINT = 0x29, TAC_MOVDD   = 0x35, TAC_RAND    = 0x45, TAC_PRINTLN = 0x55,
    TAC_MINUS   = 0x06, TAC_MOD     = 0x16,                     TAC_MOVDA   = 0x36,                     TAC_MEMF    = 0x56,                 
    TAC_NOT     = 0x07,                                         TAC_MOVDI   = 0x37,                     TAC_CALL    = 0x57,                                 
    TAC_SEQ     = 0x08,                                         TAC_MOVIV   = 0x3C,                     TAC_RETURN  = 0x58,                                 
    TAC_SLT     = 0x09,                                         TAC_MOVID   = 0x3D,                     TAC_PUSH    = 0x59,                                 
    TAC_SLEQ    = 0x0A,                                         TAC_MOVIA   = 0x3E,                     TAC_NOP     = 0x5A,                                 
} InstCode;

typedef enum {
    TAC_OPTYPE_TEMP,
    TAC_OPTYPE_PARAM,
    TAC_OPTYPE_INT,
    TAC_OPTYPE_FLOAT,
    TAC_OPTYPE_LABEL
} OperandType;

typedef struct t_label {
    char* value;
} Label;

union Value {
    Label* label;   // Descricao de labels
    int ival;       // Representa imediatos e identificador de temp e param
    float fval;
};

typedef struct t_field {
    union Value value;      
    OperandType type;               // Representa como campo deve ser printado em uma instrucao
    
    struct t_field *adress_index;   // Caso seja adress possui referencia para field com indice 
    ValueType value_type;           // Como esta sendo trabalhado este valor no tac endereco ou valor
} Field;

typedef struct t_instruction {
    struct t_instruction *next;
    
    Label *label;
    InstCode inst_code;
    Field *fields[3];
} Instruction;

typedef struct t_generic_list {
    struct t_generic_list *previous;
    void *cur;
    struct t_generic_list *next;
} GenericList;

typedef struct t_back_patch {
    Field *cur;
    struct t_back_patch *next;
} BackPatchList;

/*-------------------FUNCTIONS----------------------------*/


union Value get_value_label(Label *label);
union Value get_value_ival(int ival); 
union Value get_value_fval(float fval); 

void push_alloc(void *obj); 

void replace_label_value(Label* label, char *value); 
Label* cgen_label(char *value, int is_user_label);
Label* cgen_label_by_counter(); 
Field *cgen_field(union Value value, OperandType type); 
Field *cgen_field_adress(union Value value, OperandType type, Field *index); 

Instruction* cgen_instr(Label* label, InstCode inst_code, Field* f0, Field* f1, Field *f2);
void cgen_append(Instruction **codea, Instruction *codeb); 
Instruction* cgen_last_inst(Instruction *inst); 

/*--------------------BACK PATCH-------------------------*/

BackPatchList* cgen_last_patch(BackPatchList *patch);
BackPatchList* cgen_patch(Field *field); 
BackPatchList* cgen_cpy_patch(BackPatchList *patch);
BackPatchList* cgen_merge_patch(BackPatchList *a, BackPatchList *b); 

void cgen_back_patch(BackPatchList *patch_list, Label *patch); 


/*---------------------LANGUAGE CODE GENERATOR-------------------------*/

int type_mem_sz(TypeExpression *type); 
Instruction* cgen_derref_lvalue(Field *adress, int *temp_inst_count); 
Instruction* cgen_cast(Field *field, Cast cast, int *temp_inst_count); 

Instruction* cgen_fill_mem(Field* adress, Field *index, TypeExpression *type, int value, int *temp_inst_count);
Instruction* cgen_declaration(SymbolNode *sym, int *temp_inst_count); 
Instruction* cgen_declaration_param(SymbolNode *sym, int *param_inst_count); 

Instruction* cgen_return(Node *expr, int *temp_inst_count);
Instruction *cgen_function_call(SymbolNode *sym, Node *params_call, int *temp_inst_count); 

Instruction *cgen_var_access(SymbolNode *sym, Node *dimension, int *temp_inst_count); 
Instruction* cgen_const_code(OperandType type, int ival, float fval, int *temp_inst_count); 

Instruction* cgen_assign(Node *dst, Node *src, int *temp_inst_count); 

Instruction* cgen_expression_aritmetic(Node *a, Node *b, InstCode code, int *temp_inst_count); 
Instruction* cgen_expression_boolean(Node *a, Node *b, InstCode code, int *temp_inst_count);
Instruction* cgen_expression_relational(Node *a, Node *b, int op, int *temp_inst_count); 
Instruction* cgen_expression_unary(Node *a, int op, int *temp_inst_count); 

Instruction *cgen_write_string(char *string);
Instruction *cgen_write_array(TypeExpression *type, Instruction *code, int *temp_inst_count);
Instruction *cgen_write(TypeExpression *type, Instruction *code, int *temp_inst_count); 

Instruction* cgen_if(Node* dst, Instruction* condition, Node* body, int *temp_inst_count); 
Instruction* cgen_if_else(Node* dst, Instruction* condition, Node* body_if, Node* else_statement, int *temp_inst_count);
Instruction* cgen_while(Node* dst, Instruction* condition, Node* body, int *temp_inst_count); 
Instruction* cgen_for(Node* dst, Instruction *init, Instruction* condition, Instruction *increment, Node* body, int *temp_inst_count); 

Instruction* cgen_cpy_array(Field *dst_adress, Field *src_adress, int *temp_inst_count);
Instruction* cgen_addv(Instruction *graph, int *temp_inst_count);



/*---------------------FREE-------------------------*/

void free_cgen(); 

/*--------------------PRINT CODE------------------------*/

char* field_toa(Field *field); 
void print_inst(Instruction *inst); 
void print_code(Instruction *code); 


#endif