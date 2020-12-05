%{
    #include <string.h>

    #include "gramatica.tab.h"

    #define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line; \
    yylloc.first_column = yylloc.last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
        if(yytext[i] == '\n') { \
            yylloc.last_line++; \
            yylloc.last_column = 0; \
        } \
        else { \
            yylloc.last_column++; \
        } \
    }

    void buildToken(int id) {
        yylval.id = id;
        // char* cpy = malloc(strlen(yytext) + 1);
        // strcpy(cpy, yytext);
        // countInput();
    }

    void lexError() {
        printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m lexical error, unknown character in this context: %s\n", 
            yylloc.first_line, yylloc.first_column,
            yylloc.last_line, yylloc.last_column,
            yytext);
    }
%}

%option noyywrap
%option nounput
%option noinput
%option yylineno


%s IN_COMMENT

/* regular definitions */
ws              [ \t\n]
letter          [A-Za-z]
digit           [0-9]
id              {letter}({letter}|{digit}|_)*
number_int      {digit}+
number_float    {digit}+(\.{digit}+)+
%%

"/*"              { BEGIN(IN_COMMENT); }

<IN_COMMENT>{
    "*/"      { BEGIN(INITIAL); }
    [^*\n]+   {}
    "*"       {}
    \n        { yylineno++; }
}

{ws}            { }

if				{ buildToken(IF); return IF; }
else			{ buildToken(ELSE); return ELSE; }
for				{ buildToken(FOR); return FOR; }
while			{ buildToken(WHILE); return WHILE; }

boolean			{ buildToken(BOOLEAN); return BOOLEAN; }
int				{ buildToken(INT); return INT; }
float			{ buildToken(FLOAT); return FLOAT; }
void			{ buildToken(VOID); return VOID; }
graph			{ buildToken(GRAPH); return GRAPH; }

true            { buildToken(TRUE); return TRUE; }
false           { buildToken(FALSE); return FALSE; }

dfs			    { buildToken(DFS); return DFS; }
bfs             { buildToken(BFS); return BFS; }
adda			{ buildToken(ADDA); return ADDA; }
addv            { buildToken(ADDV); return ADDV; }
return          { buildToken(RETURN); return RETURN; }

{id}            { buildToken(ID); return ID; }
{number_float}  { buildToken(C_FLOAT); return C_FLOAT; }
{number_int}    { buildToken(C_INT); return C_INT; }

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
"+"				{ buildToken(ADD); return ADD; }
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