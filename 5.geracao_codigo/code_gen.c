#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "code_gen.h"

extern int next_instruction;

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
        char* l_value = (char*)malloc(strlen(value) + 1);
        strcpy(l_value, "_");
        strcat(l_value, value);
        label->value = l_value;
        push_alloc((void*)l_value);
    }

    return label;
}

Field *cgen_field(union Value value, OperandType type) {
    Field* field = (Field*)calloc(1, sizeof(Field));
    push_alloc((void*)field);
    field->value = value;
    field->type = type;
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

/*----------------------------------------------*/

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
        return NULL;
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
        case TAC_MOVVD:   sprintf(buffer, "movvd");                                                         break;
        case TAC_MOVVA:   sprintf(buffer, "movva");                                                         break;
        case TAC_MOVVI:   sprintf(buffer, "movvi");                                                         break;
        case TAC_MOVDV:   sprintf(buffer, "movdv");                                                         break;
        case TAC_MOVDD:   sprintf(buffer, "movdd");                                                         break;
        case TAC_MOVDA:   sprintf(buffer, "movda");                                                         break;
        case TAC_MOVDI:   sprintf(buffer, "movdi");                                                         break;
        case TAC_MOVIV:   sprintf(buffer, "moviv");                                                         break;
        case TAC_MOVID:   sprintf(buffer, "movid");                                                         break;
        case TAC_MOVIA:   sprintf(buffer, "movia");                                                         break;
        case TAC_POP:     sprintf(buffer, "pop");                                                           break;
        case TAC_BRZ:     sprintf(buffer, "brz");                                                           break;
        case TAC_BRNZ:    sprintf(buffer, "brnz");                                                          break;
        case TAC_JUMP:    sprintf(buffer, "jump");                                                          break;
        case TAC_PARAM:   sprintf(buffer, "param");                                                         break;
        case TAC_PRINT:   sprintf(buffer, "print");                                                         break;
        case TAC_PRINTLN: sprintf(buffer, "println");                                                       break;
        case TAC_SCANC:   sprintf(buffer, "scanc");                                                         break;
        case TAC_SCANI:   sprintf(buffer, "scani");                                                         break;
        case TAC_SCANF:   sprintf(buffer, "scanf");                                                         break;
        case TAC_RAND:    sprintf(buffer, "rand");                                                          break;
        case TAC_MEMA:    sprintf(buffer, "mema");                                                          break;
        case TAC_MEMF:    sprintf(buffer, "memf");                                                          break;
        case TAC_CALL:    sprintf(buffer, "call");                                                          break;
        case TAC_RETURN:  sprintf(buffer, "return");                                                        break;
        case TAC_PUSH:    sprintf(buffer, "push");                                                          break;
        case TAC_NOP:     sprintf(buffer, "nop");                                                           break;
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
    Instruction *cur = code;
    while(cur) {
        print_inst(cur);
        cur = cur->next;
    }
}
