%{
    #include <string.h>
    #include "gramatica.tab.h"

    struct token {
        int id;
        int line, column;
        void* value;
    };

    struct token current_token;
    int line = 1, column = 1;

    void countInput() {
        if (yytext[0] == '\n') {
            line++;
            column = 1;
        } else {
            column += strlen(yytext);
        }
    }

    void buildToken(int id) {
        char* cpy = malloc(strlen(yytext) + 1);
        strcpy(cpy, yytext);

        yylval.id = id;

        current_token.id = id;
        current_token.line = line;
        current_token.column = column;
        current_token.value = cpy;

        countInput();
    }

    void lexError() {
        printf("\033[01;33m%d:%d:\033[0;0m \033[1;31merror:\033[0;0m caracter desconhecido neste contexto: %s\n", line, column, yytext);
        countInput();
    }
%}

%option noyywrap
%option nounput
%option noinput

/* regular definitions */
ws          [ \t\n]
letter      [A-Za-z]
digit       [0-9]
id          {letter}({letter}|{digit}|_)*
number      {digit}+(\.{digit}+)?
%%

{ws}            { countInput(); }

if				{ buildToken(IF); return IF; }
else			{ buildToken(ELSE); return ELSE; }
for				{ buildToken(FOR); return FOR; }
while			{ buildToken(WHILE); return WHILE; }

boolean			{ buildToken(BOOLEAN); return BOOLEAN; }
int				{ buildToken(INT); return INT; }
float			{ buildToken(FLOAT); return FLOAT; }
void			{ buildToken(VOID); return VOID; }
graph			{ buildToken(GRAPH); return GRAPH; }
to              { buildToken(TO); return TO; }

true            { buildToken(TRUE); return TRUE; }
false           { buildToken(FALSE); return FALSE; }

dfs			    { buildToken(GRAPH); return GRAPH; }
bfs             { buildToken(TO); return TO; }
return          { buildToken(RETURN); return RETURN; }

{id}            { buildToken(ID); return ID; }
{number}        { buildToken(NUMBER); return NUMBER; }

">>"			{ buildToken(READ); return READ; }
"<<"			{ buildToken(WRITE); return WRITE; }
"&&"			{ buildToken(AND); return AND; }
"||"			{ buildToken(OR); return OR; }
"<="			{ buildToken(LE); return LE; }
">="			{ buildToken(GE); return GE; }
"<"				{ buildToken(LESS); return LESS; }
">"				{ buildToken(GREATER); return GREATER; }
"=="			{ buildToken(EQ); return EQ; }
"!="			{ buildToken(NE); return NE; }
"!"				{ buildToken(NOT); return NOT; }
"*"				{ buildToken(MUL); return MUL; }
"/"				{ buildToken(DIV); return DIV; }
"+"				{ buildToken(SUM); return SUM; }
"-"				{ buildToken(SUB); return SUB; }
"="				{ buildToken(ASSIGN); return ASSIGN; }
";"				{ buildToken(END); return END; }
"{"				{ buildToken(OPEN_BRACE); return OPEN_BRACE; }
"}"				{ buildToken(CLOSE_BRACE); return CLOSE_BRACE; }
":"				{ buildToken(IT); return IT; }
","				{ buildToken(SEPARATOR); return SEPARATOR; }
"("				{ buildToken(OPEN_P); return OPEN_P; }
")"				{ buildToken(CLOSE_P); return CLOSE_P; }
"["			    { buildToken(OPEN_BRACKET); return OPEN_BRACKET; }
"]"			    { buildToken(CLOSE_BRACKET); return CLOSE_BRACKET; }
.			    { lexError(); }

%%

// int main() {
//     printf("\n****** LEGENDA: <<IDENTIFICADOR DO TOKEN>, <LEXEMA>> *******\n\n");

//     while(yylex()) {
//         printf("<%d - %s, \"%s\">\n", current_token.id, token_str[current_token.id], (char*)current_token.value);
//         free(current_token.value);
//     }

//     yylex_destroy();
//     return 0;
// }

