/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GRAMATICA_TAB_H_INCLUDED
# define YY_YY_GRAMATICA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "gramatica.y" /* yacc.c:1909  */

  #include "node.h"

#line 48 "gramatica.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    BOOLEAN = 262,
    INT = 263,
    FLOAT = 264,
    GRAPH = 265,
    VOID = 266,
    TO = 267,
    TRUE = 268,
    FALSE = 269,
    ID = 270,
    C_FLOAT = 271,
    C_INT = 272,
    READ = 273,
    WRITE = 274,
    DFS = 275,
    BFS = 276,
    ADDA = 277,
    ADDV = 278,
    RETURN = 279,
    AND = 280,
    OR = 281,
    LE = 282,
    GE = 283,
    LESS = 284,
    GREATER = 285,
    EQ = 286,
    NE = 287,
    NOT = 288,
    MUL = 289,
    DIV = 290,
    ADD = 291,
    SUB = 292,
    ASSIGN = 293,
    END = 294,
    OPEN_BRACE = 295,
    CLOSE_BRACE = 296,
    IT = 297,
    SEPARATOR = 298,
    OPEN_P = 299,
    CLOSE_P = 300,
    OPEN_BRACKET = 301,
    CLOSE_BRACKET = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 53 "gramatica.y" /* yacc.c:1909  */

  int id;
  Node* node;

#line 113 "gramatica.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_GRAMATICA_TAB_H_INCLUDED  */
