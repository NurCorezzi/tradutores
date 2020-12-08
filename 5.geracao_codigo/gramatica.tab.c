/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 5 "./src/sintax/gramatica.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gramatica.tab.h"
#include "node.h"
#include "code_gen.h"
#include "stable.h"
#include "type_expression.h"
#include "ast.h"

extern char *yytext;
int yylex_destroy ( void );
int yylex();

/*----GLOBAL-----*/

extern TypeExpression TYPE_EXPRESSION_VOID;
extern TypeExpression TYPE_EXPRESSION_BOOLEAN;
extern TypeExpression TYPE_EXPRESSION_FLOAT;
extern TypeExpression TYPE_EXPRESSION_INT;

SymbolNode *symbol_table;
Node *ast;

Scope *global_scope;
int scope_count;

Instruction *cgen;
int next_instruction;
int temp_inst_count;
int param_inst_count;
int label_count;
int declaration_count;

int has_main;
int is_declaration_param;

/*-------UTILS-------*/

void normalize_to_list(Node *dst, Node *tree);

Node* get_params_addv();
Node* get_params_adda();
Node* get_params_graph_call();

void check_graph_call(char *id, Node* graph_params_call);
void check_params(char *function_id, Node *param, Node *param_call);
void check_return(Node *tgt, Node *expr);
void check_assign_expression(Node *tgt, TypeExpression *tgt_type, Node *op2);
void check_relational_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_boolean_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_aritmetic_expression(Node *tgt, Node *op1, Node *operator, Node *op2);

void build_incompatible_types_str(char* buffer, TypeExpression *a, TypeExpression *b);
void yyerror (char const *s);
void semantic_error(char const *s);
void warning(char const *s);
int error_recovery_mode;
int invalid;


#line 131 "gramatica.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "gramatica.tab.h".  */
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
#line 1 "./src/sintax/gramatica.y" /* yacc.c:355  */

  #include "node.h"

#line 165 "gramatica.tab.c" /* yacc.c:355  */

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
    TRUE = 267,
    FALSE = 268,
    ID = 269,
    C_FLOAT = 270,
    C_INT = 271,
    READ = 272,
    WRITE = 273,
    DFS = 274,
    BFS = 275,
    ADDA = 276,
    ADDV = 277,
    RETURN = 278,
    AND = 279,
    OR = 280,
    LE = 281,
    GE = 282,
    LESS = 283,
    GREATER = 284,
    EQ = 285,
    NE = 286,
    NOT = 287,
    MUL = 288,
    DIV = 289,
    ADD = 290,
    SUB = 291,
    ASSIGN = 292,
    END = 293,
    OPEN_BRACE = 294,
    CLOSE_BRACE = 295,
    IT = 296,
    SEPARATOR = 297,
    OPEN_P = 298,
    CLOSE_P = 299,
    OPEN_BRACKET = 300,
    CLOSE_BRACKET = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 83 "./src/sintax/gramatica.y" /* yacc.c:355  */

  int id;
  Node* node;

#line 229 "gramatica.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 260 "gramatica.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   139,   140,   155,   186,   155,   241,   244,
     245,   256,   263,   292,   293,   305,   311,   316,   323,   335,
     335,   358,   358,   371,   372,   384,   399,   411,   425,   437,
     441,   451,   454,   457,   460,   469,   477,   483,   500,   505,
     514,   517,   526,   529,   537,   540,   549,   552,   561,   564,
     573,   576,   585,   588,   616,   619,   622,   629,   630,   631,
     634,   635,   637,   638,   639,   640,   642,   643,   644,   645,
     646,   647,   654,   674,   690,   745,   746,   754,   760,   765,
     770,   777,   810,   811,   836,   845,   846,   847,   848,   849,
     852,   852,   855,   869,   883,   895
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "BOOLEAN",
  "INT", "FLOAT", "GRAPH", "VOID", "TRUE", "FALSE", "ID", "C_FLOAT",
  "C_INT", "READ", "WRITE", "DFS", "BFS", "ADDA", "ADDV", "RETURN", "AND",
  "OR", "LE", "GE", "LESS", "GREATER", "EQ", "NE", "NOT", "MUL", "DIV",
  "ADD", "SUB", "ASSIGN", "END", "OPEN_BRACE", "CLOSE_BRACE", "IT",
  "SEPARATOR", "OPEN_P", "CLOSE_P", "OPEN_BRACKET", "CLOSE_BRACKET",
  "$accept", "init", "program", "function", "$@1", "$@2", "params",
  "function_call", "params_call", "graph_call", "graph_params_call",
  "statements", "block", "$@3", "statement_control", "statement",
  "expr_assign", "expr_or", "expr_and", "expr_relational", "expr_add",
  "expr_sub", "expr_mul", "expr_div", "expr_unary", "factor", "unary",
  "and", "or", "add", "sub", "mul", "div", "compare_op", "graph_add",
  "declaration", "dimension", "value", "id_or_access", "access_lvl", "id",
  "type", "number", "number_int", "number_float", "boolean_const", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -123,    11,    56,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,   -42,    -8,     0,  -123,   -23,  -123,  -123,  -123,   -19,
     126,     6,  -123,   -42,   126,  -123,     0,  -123,    -5,  -123,
    -123,    72,    -2,     1,    15,  -123,  -123,  -123,     0,   150,
      19,    27,    17,  -123,  -123,  -123,  -123,  -123,   150,  -123,
    -123,  -123,  -123,    -3,   -16,    30,    96,    38,    55,    59,
      65,  -123,  -123,     4,  -123,  -123,    63,    64,  -123,  -123,
      16,  -123,  -123,  -123,  -123,   150,   150,   150,    67,    61,
      71,     0,     0,  -123,    75,  -123,    66,  -123,  -123,   150,
     150,  -123,   150,  -123,  -123,  -123,  -123,  -123,  -123,   150,
     150,   150,  -123,   150,  -123,   150,  -123,  -123,  -123,   150,
     150,  -123,    70,    79,    77,    76,  -123,  -123,    87,    86,
    -123,   138,  -123,  -123,    30,    96,    38,    55,    59,    65,
    -123,    54,  -123,    85,    99,   150,     8,    99,   150,  -123,
    -123,   150,  -123,    61,   135,   102,   114,   114,   123,  -123,
     116,  -123,  -123,     3,   150,     0,  -123,  -123,    99,   150,
    -123,   124,   127,  -123,   128,    99,   150,  -123,  -123,   129,
     150,   131,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     8,    86,    85,    87,    88,    89,
       4,    75,     0,     0,    92,     0,    84,     5,    76,     0,
       9,     0,    11,    75,     0,     6,     0,    10,     0,    74,
      19,     0,     0,     0,     0,    94,    95,    93,     0,     0,
       0,     0,     0,    57,    62,    63,    21,     7,     0,    80,
      23,    36,    20,     0,    38,    40,    42,    44,    46,    48,
      50,    52,    54,     0,    58,    59,     0,     0,    56,    77,
      82,    78,    90,    91,    79,     0,     0,     0,     0,    82,
       0,     0,     0,    35,     0,    19,     0,    32,    61,     0,
       0,    60,     0,    66,    67,    68,    69,    70,    71,     0,
       0,     0,    64,     0,    65,     0,    53,    33,    31,    13,
       0,    81,     0,     0,    77,     0,    29,    30,     0,     0,
      34,     0,    55,    37,    39,    41,    43,    45,    47,    49,
      51,     0,    15,     0,     0,     0,     0,     0,     0,    72,
      22,     0,    12,    82,    24,     0,     0,     0,     0,    26,
       0,    14,    83,     0,     0,     0,    16,    17,     0,     0,
      25,     0,     0,    28,     0,     0,     0,    73,    27,     0,
       0,     0,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
      29,    94,  -122,  -123,    31,  -123,   -38,  -123,    90,    91,
      88,    89,    93,    92,    83,   133,  -123,  -123,  -123,   -52,
     -51,  -123,  -123,  -123,  -123,     2,   167,  -123,   -36,    48,
     -13,   190,  -123,   185,  -123,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    19,    28,    21,    49,   131,   148,
     156,    31,    50,    85,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    92,    90,    64,
      65,   103,   105,    99,    66,    67,    13,    68,    69,   111,
      70,    23,    71,    72,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    80,    78,    12,    84,   100,    32,   101,    14,    88,
      86,     3,   144,    29,    16,   149,    35,    36,    16,    37,
      14,    89,    22,    18,    20,    79,    27,   146,   147,    35,
      36,    16,    37,    14,    30,    87,   163,   112,   113,   115,
     114,    75,    46,   168,    76,   118,   119,    48,    24,    43,
      25,   123,    44,    45,    91,    83,    -2,     4,    77,   109,
      48,   110,    81,     5,     6,     7,     8,     9,    79,    79,
      82,   132,   133,    44,   100,    32,   101,    33,    34,     5,
       6,     7,     8,     9,    35,    36,    16,    37,    14,    38,
      39,    45,   102,    40,    41,    42,   141,   145,   142,   104,
     150,   107,   108,   151,    43,   116,   110,    44,    45,   117,
     122,    46,    47,   120,   134,    48,   161,   135,   136,   162,
     137,   164,    93,    94,    95,    96,    97,    98,   169,   138,
     139,   143,   171,     5,     6,     7,     8,     9,    46,   153,
     154,    32,    79,    33,    34,     5,     6,     7,     8,     9,
      35,    36,    16,    37,    14,    38,    39,   155,   159,    40,
      41,    42,    35,    36,    16,    37,    14,   158,   165,   166,
      43,   170,   167,    44,    45,   172,   157,    46,   140,   121,
     124,    48,    43,   125,   160,    44,    45,   126,   130,   127,
      26,   152,    11,    48,   128,   129,   106,    15
};

static const yytype_uint8 yycheck[] =
{
      13,    39,    38,    45,    42,    57,     3,    58,    16,    25,
      48,     0,   134,    26,    14,   137,    12,    13,    14,    15,
      16,    37,    20,    46,    43,    38,    24,    19,    20,    12,
      13,    14,    15,    16,    39,    38,   158,    75,    76,    77,
      76,    43,    39,   165,    43,    81,    82,    43,    42,    32,
      44,    89,    35,    36,    24,    38,     0,     1,    43,    43,
      43,    45,    43,     7,     8,     9,    10,    11,    81,    82,
      43,   109,   110,    35,   126,     3,   127,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    36,    33,    21,    22,    23,    42,   135,    44,    34,
     138,    38,    38,   141,    32,    38,    45,    35,    36,    38,
      44,    39,    40,    38,    44,    43,   154,    38,    41,   155,
      44,   159,    26,    27,    28,    29,    30,    31,   166,    42,
      44,    46,   170,     7,     8,     9,    10,    11,    39,     4,
      38,     3,   155,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    43,    42,    21,
      22,    23,    12,    13,    14,    15,    16,    44,    44,    42,
      32,    42,    44,    35,    36,    44,   147,    39,    40,    85,
      90,    43,    32,    92,   153,    35,    36,    99,   105,   100,
      23,   143,     2,    43,   101,   103,    63,    12
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,     1,     7,     8,     9,    10,    11,
      50,    88,    45,    83,    16,    90,    14,    87,    46,    51,
      43,    53,    82,    88,    42,    44,    83,    82,    52,    87,
      39,    58,     3,     5,     6,    12,    13,    15,    17,    18,
      21,    22,    23,    32,    35,    36,    39,    40,    43,    54,
      59,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    76,    77,    81,    82,    84,    85,
      87,    89,    90,    91,    92,    43,    43,    43,    85,    87,
      63,    43,    43,    38,    63,    60,    63,    38,    25,    37,
      75,    24,    74,    26,    27,    28,    29,    30,    31,    80,
      76,    77,    33,    78,    34,    79,    72,    38,    38,    43,
      45,    86,    63,    63,    85,    63,    38,    38,    85,    85,
      38,    58,    44,    63,    65,    66,    67,    68,    69,    70,
      71,    55,    63,    63,    44,    38,    41,    44,    42,    44,
      40,    42,    44,    46,    59,    63,    19,    20,    56,    59,
      63,    63,    86,     4,    38,    43,    57,    57,    44,    42,
      61,    63,    85,    59,    63,    44,    42,    44,    59,    63,
      42,    63,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    51,    52,    50,    50,    53,
      53,    53,    54,    55,    55,    55,    56,    56,    57,    58,
      58,    60,    59,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      74,    75,    76,    77,    78,    79,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    83,    83,    84,    84,    84,
      84,    85,    86,    86,    87,    88,    88,    88,    88,    88,
      89,    89,    90,    91,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,    11,     1,     0,
       3,     1,     4,     0,     3,     1,     2,     2,     7,     0,
       2,     0,     4,     1,     5,     7,     5,     9,     7,     3,
       3,     2,     2,     2,     3,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     8,     3,     0,     3,     1,     1,     1,
       1,     2,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 48: /* init  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1292 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 49: /* program  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1302 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 50: /* function  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1312 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 53: /* params  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1322 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* function_call  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1332 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* params_call  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1342 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 56: /* graph_call  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1352 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 57: /* graph_params_call  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1362 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* statements  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1372 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* block  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1382 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* statement_control  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1392 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* statement  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1402 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* expr_assign  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1412 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* expr_or  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1422 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 65: /* expr_and  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1432 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* expr_relational  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1442 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* expr_add  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1452 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* expr_sub  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1462 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 69: /* expr_mul  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1472 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 70: /* expr_div  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1482 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 71: /* expr_unary  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1492 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 72: /* factor  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1502 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 73: /* unary  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1512 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 74: /* and  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1522 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 75: /* or  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1532 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 76: /* add  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1542 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 77: /* sub  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1552 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 78: /* mul  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1562 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 79: /* div  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1572 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 80: /* compare_op  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1582 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 81: /* graph_add  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1592 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 82: /* declaration  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1602 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 83: /* dimension  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1612 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 84: /* value  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1622 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 85: /* id_or_access  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1632 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 86: /* access_lvl  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1642 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 87: /* id  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1652 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 88: /* type  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1662 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 89: /* number  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1672 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 90: /* number_int  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1682 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 91: /* number_float  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1692 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 92: /* boolean_const  */
#line 105 "./src/sintax/gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1702 "gramatica.tab.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 125 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  ast = (yyval.node) = (yyvsp[0].node);

  if (!has_main) {
    warning("no main function identified program will not run");
    invalid = 1;
  }
}
#line 1997 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 139 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2003 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 140 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
    (yyval.node) = create_node("program");
  if ((yyvsp[-1].node) != NULL) {
    normalize_to_list((yyval.node), (yyvsp[-1].node));
    (yyval.node)->code = (yyvsp[-1].node)->code;
    free_node((yyvsp[-1].node));
  }
  push_child((yyval.node), (yyvsp[0].node));
  
  if ((yyvsp[0].node) != NULL) {
    cgen_append(&((yyval.node)->code), (yyvsp[0].node)->code);
  } 
}
#line 2021 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 155 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  // Necessario declarar funcao na tabela de simbolos antes da declaracao de seus parametros para que escopo esteja correto
  SymbolNode *match = stable_find_with_scope(symbol_table, global_scope, (yyvsp[0].node)->complement, STYPE_FUNCTION);
  if (match != NULL && scope_eq(global_scope, match->scope)) {
    char buffer[300] = {0};
    sprintf(buffer, "function \"%s\" already declared", (yyvsp[0].node)->complement);
    semantic_error(buffer);
  }

  if (strcmp((yyvsp[0].node)->complement, "main") == 0) {
    has_main = 1;
  }

  TypeExpression* type = type_build((yyvsp[-2].node), (yyvsp[-1].node));
  SymbolNode *entry = stable_create_symbol((yyvsp[0].node)->complement, global_scope, STYPE_FUNCTION, type, NULL);
  symbol_table = stable_add(symbol_table, entry);

  if (!type_can_return(type)) {
    char buffer[300] = {0};
    char *buffer1 = type_to_string(type);
    sprintf(buffer, "type \"%s\" cannot be a return type", buffer1);
    free(buffer1);
    semantic_error(buffer);
  }

  scope_push(&global_scope, &scope_count, entry);

  is_declaration_param = 1;
  temp_inst_count = 0;
  param_inst_count = 0;

}
#line 2058 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 186 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  // Obtencao de parametros para symbol table
  SymbolNode *entry = stable_find_with_scope(symbol_table, global_scope, (yyvsp[-4].node)->complement, STYPE_FUNCTION);  
  entry->ast_node = (yyvsp[-1].node);
  is_declaration_param = 0;
}
#line 2069 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 191 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("function");

  Node* decl = create_node("declaration");
  push_child(decl, (yyvsp[-10].node));
  if((yyvsp[-9].node) != NULL) {
    push_child(decl, (yyvsp[-9].node));
  }
  push_child(decl, (yyvsp[-8].node));

  Node* block = create_node("block");
  push_child(block, (yyvsp[-1].node));

  push_child((yyval.node), decl);
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), block);

  scope_pop(&global_scope);

  if (!invalid) {
    if ((yyvsp[-5].node) != NULL)      cgen_append(&((yyval.node)->code), (yyvsp[-5].node)->code);
    if ((yyvsp[-1].node) != NULL)  cgen_append(&((yyval.node)->code), (yyvsp[-1].node)->code);

    // nop para sempre gerar funcao com label inicial caso nao tenha statements, deve ficar antes de return obviamente
    Label *ending = cgen_label_by_counter();
    cgen_append(&((yyval.node)->code), cgen_instr(ending, TAC_NOP, NULL, NULL, NULL));

    if (strcmp((yyvsp[-8].node)->complement, "main") != 0) {
      cgen_append(&((yyval.node)->code), cgen_instr(NULL, TAC_RETURN, NULL, NULL, NULL));
    }

    if ((yyvsp[-1].node) != NULL) cgen_back_patch((yyvsp[-1].node)->back_patch, ending);

    if ((yyval.node)->code) {
      char *label_description;
      // Caso seja main nao queremos adicionar "_" na label para que tac possa executar
      if (strcmp((yyvsp[-8].node)->complement, "main") == 0) {
        label_description = cgen_label((yyvsp[-8].node)->complement, 1)->value;
      } else {
        label_description = cgen_label((yyvsp[-8].node)->complement, 0)->value;
      }
     
      if ((yyval.node)->code->label == NULL) {
        (yyval.node)->code->label = cgen_label(label_description, 1);
      } else{
        replace_label_value((yyval.node)->code->label, label_description);  
      }
    }
  }
}
#line 2124 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 241 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { error_recovery_mode = 0; (yyval.node) = NULL; }
#line 2130 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 244 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2136 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 245 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  
  if ((yyvsp[-2].node) != NULL) {
    normalize_to_list((yyval.node), (yyvsp[-2].node));
    (yyval.node)->code = (yyvsp[-2].node)->code;
    free_node((yyvsp[-2].node));
  } 
  push_child((yyval.node), (yyvsp[0].node));
  cgen_append(&((yyval.node)->code), (yyvsp[0].node)->code);
}
#line 2152 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 256 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  push_child((yyval.node), (yyvsp[0].node));
  cgen_append(&((yyval.node)->code), (yyvsp[0].node)->code);
}
#line 2162 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 263 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("function_call");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));

  SymbolNode *match = stable_find_with_scope(symbol_table, global_scope, (yyvsp[-3].node)->complement, STYPE_FUNCTION);

  if (match == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "function \"%s\" not found in scope", (yyvsp[-3].node)->complement);
    semantic_error(buffer);
  } else {
    (yyval.node)->type = type_cpy(match->type);
    check_params(
      match->id,
      match->ast_node ? match->ast_node->begin_child : NULL, 
      (yyvsp[-1].node) ? (yyvsp[-1].node)->begin_child : NULL
    );
  } 

  if (!invalid) {
    cgen_append(
      &((yyval.node)->code), 
      cgen_function_call(match, (yyvsp[-1].node), &temp_inst_count)
    );
  }
}
#line 2194 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 292 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2200 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 293 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  
  if ((yyvsp[-2].node) != NULL) {
    normalize_to_list((yyval.node), (yyvsp[-2].node));
    (yyval.node)->code = (yyvsp[-2].node)->code;
    free_node((yyvsp[-2].node));
  } 
  push_child((yyval.node), (yyvsp[0].node));
  // Parametros nao podem ser juntados aqui pois e necessario last instruction de cada um para acessar o field com seu valor
  // cgen_append(&($$->code), $expr_assign->code);
}
#line 2217 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 305 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2226 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 311 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("dfs"); 
  push_child((yyval.node), (yyvsp[0].node));
  check_graph_call((yyval.node)->id, (yyvsp[0].node));
}
#line 2236 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 316 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("bfs"); 
  push_child((yyval.node), (yyvsp[0].node));
  check_graph_call((yyval.node)->id, (yyvsp[0].node));
}
#line 2246 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 323 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("graph_params");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2257 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 335 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2263 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 335 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("statements");
  BackPatchList *back_patch = NULL;

  if ((yyvsp[-1].node) != NULL) {
    normalize_to_list((yyval.node), (yyvsp[-1].node));
    (yyval.node)->code = (yyvsp[-1].node)->code;
    back_patch = (yyvsp[-1].node)->back_patch;
    free_node((yyvsp[-1].node));
  } 
  push_child((yyval.node), (yyvsp[0].node));

  if (!invalid) {
    cgen_append(&((yyval.node)->code), (yyvsp[0].node)->code);
    if (back_patch && (yyvsp[0].node)->code->label == NULL) {
      (yyvsp[0].node)->code->label = cgen_label_by_counter();
    }
    cgen_back_patch(back_patch, (yyvsp[0].node)->code->label);  
    (yyval.node)->back_patch = (yyvsp[0].node)->back_patch;
  }
}
#line 2289 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 358 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {  
  scope_push(&global_scope, &scope_count, NULL); 
}
#line 2297 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 360 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("block");
  if ((yyvsp[-1].node)) {
    (yyval.node)->code = (yyvsp[-1].node)->code;
    (yyval.node)->back_patch = (yyvsp[-1].node)->back_patch;
    push_child((yyval.node), (yyvsp[-1].node));
  }
  scope_pop(&global_scope);
}
#line 2311 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 372 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_open");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  if (!invalid) {
    cgen_append(
      &((yyval.node)->code),
      cgen_if((yyval.node), (yyvsp[-2].node)->code, (yyvsp[0].node), &temp_inst_count)
    );
  }
}
#line 2328 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 384 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_else");
  push_child((yyval.node), (yyvsp[-4].node));
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  if (!invalid) {
    cgen_append(
      &((yyval.node)->code),
      cgen_if_else((yyval.node), (yyvsp[-4].node)->code, (yyvsp[-2].node), (yyvsp[0].node), &temp_inst_count)
    );
  }
}
#line 2346 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 399 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("while");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  if (!invalid) {
    cgen_append(
      &((yyval.node)->code),
      cgen_while((yyval.node), (yyvsp[-2].node)->code, (yyvsp[0].node), &temp_inst_count)
    );
  }
}
#line 2363 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 411 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for");
  push_child((yyval.node), (yyvsp[-6].node));
  push_child((yyval.node), (yyvsp[-4].node));
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  if (!invalid) {
    cgen_append(
      &((yyval.node)->code),
      cgen_for((yyval.node), (yyvsp[-6].node)->code, (yyvsp[-4].node)->code, (yyvsp[-2].node)->code, (yyvsp[0].node), &temp_inst_count)
    );
  }
}
#line 2382 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 425 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for_iterator");
  push_child((yyval.node), (yyvsp[-4].node));
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  if (!type_eq(&TYPE_EXPRESSION_INT, (yyvsp[-4].node)->type)) {
    char buffer[300] = {0};
    sprintf(buffer, "receiving var in for mut be of type int ");
    semantic_error(buffer);
  } 
}
#line 2399 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 437 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("read");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2408 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 441 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("write");
  push_child((yyval.node), (yyvsp[-1].node));

  if (!invalid) {
    cgen_append(&((yyval.node)->code), (yyvsp[-1].node)->code);  
    cgen_append(&((yyval.node)->code), cgen_write((yyvsp[-1].node)->type, (yyvsp[-1].node)->code, &temp_inst_count));
    cgen_append(&((yyval.node)->code), cgen_instr(NULL, TAC_PRINTLN, NULL, NULL, NULL));  
  }
}
#line 2423 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 451 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2431 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 454 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2439 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 457 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2447 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 460 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("return");
  push_child((yyval.node), (yyvsp[-1].node));
  check_return((yyval.node), (yyvsp[-1].node));

  if (!invalid) {
    cgen_append(&((yyval.node)->code), cgen_return((yyvsp[-1].node), &temp_inst_count));
  }
}
#line 2461 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 469 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("return");
  check_return((yyval.node), NULL);

  if (!invalid) {
    cgen_append(&((yyval.node)->code), cgen_return(NULL, &temp_inst_count));
  }
}
#line 2474 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 483 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_assign");
  (yyval.node)->value_type = LVALUE;
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_assign_expression((yyval.node), (yyvsp[-2].node)->type, (yyvsp[0].node));

  if ((yyvsp[-2].node)->begin_child->value_type != LVALUE) {
    char buffer[300] = {0};
    sprintf(buffer, "left side on \"ASSIGN\" must be an lvalue");
    semantic_error(buffer);
  }

  if (!invalid) {
    cgen_append(&((yyval.node)->code), cgen_assign((yyvsp[-2].node), (yyvsp[0].node), &temp_inst_count));
  }
}
#line 2496 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 500 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {  
  (yyval.node) = (yyvsp[0].node);
}
#line 2504 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 505 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_or");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_boolean_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  if (!invalid) cgen_append(&((yyval.node)->code), cgen_expression_boolean((yyvsp[-2].node), (yyvsp[0].node), TAC_OR, &temp_inst_count));

  free_tree((yyvsp[-1].node));
}
#line 2518 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 517 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_and");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_boolean_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  if (!invalid) cgen_append(&((yyval.node)->code), cgen_expression_boolean((yyvsp[-2].node), (yyvsp[0].node), TAC_AND, &temp_inst_count));

  free_tree((yyvsp[-1].node));
}
#line 2532 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 529 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_relational");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_relational_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  if (!invalid) cgen_append(&((yyval.node)->code), cgen_expression_relational((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].node)->t_token, &temp_inst_count));
}
#line 2545 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 540 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_add");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  if (!invalid) cgen_append(&((yyval.node)->code), cgen_expression_aritmetic((yyvsp[-2].node), (yyvsp[0].node), TAC_ADD, &temp_inst_count));

  free_tree((yyvsp[-1].node));
}
#line 2559 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 552 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_sub");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  if (!invalid) cgen_append(&((yyval.node)->code), cgen_expression_aritmetic((yyvsp[-2].node), (yyvsp[0].node), TAC_SUB, &temp_inst_count));

  free_tree((yyvsp[-1].node));
}
#line 2573 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 564 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_mul");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  if (!invalid) cgen_append(&((yyval.node)->code), cgen_expression_aritmetic((yyvsp[-2].node), (yyvsp[0].node), TAC_MUL, &temp_inst_count));

  free_tree((yyvsp[-1].node));
}
#line 2587 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 576 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_div");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  if (!invalid) cgen_append(&((yyval.node)->code), cgen_expression_aritmetic((yyvsp[-2].node), (yyvsp[0].node), TAC_DIV, &temp_inst_count));

  free_tree((yyvsp[-1].node));
}
#line 2601 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 588 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_unary");

  if ((yyvsp[-1].node) == NULL) {
    (yyval.node)->type = type_cpy((yyvsp[0].node)->type);
  } else {
    if (type_is_aritmetic((yyvsp[0].node)->type)) {
      // Gambiarra da preguiça
      if (strcmp((yyvsp[-1].node)->id, "NOT") == 0) {
        (yyvsp[0].node)->cast = type_get_cast(&TYPE_EXPRESSION_INT, (yyvsp[0].node)->type);  
        (yyval.node)->type = type_cpy(&TYPE_EXPRESSION_INT);
      } else {
        (yyval.node)->type = type_cpy((yyvsp[0].node)->type);
      }
    } else {
      char buffer[300] = {0};
      sprintf(buffer, "type incompatible with operator \"%s\" ", (yyvsp[-1].node)->id);
      semantic_error(buffer);
    }
  }

  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));

  if (!invalid) {
    cgen_append(&((yyval.node)->code), cgen_expression_unary((yyvsp[0].node), (yyvsp[-1].node)->t_token, &temp_inst_count));
  }
}
#line 2634 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 619 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2642 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 629 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2648 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 634 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2654 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 635 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2660 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 637 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2666 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 638 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2672 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 639 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2678 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 640 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2684 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 642 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2690 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 643 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2696 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 644 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2702 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 645 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2708 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 646 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2714 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 647 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2720 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 654 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("addv"); 
  push_child((yyval.node), (yyvsp[-1].node));

  Node* params = get_params_addv();
  check_params(
    (yyval.node)->id,
    params ? params->begin_child : NULL, 
    (yyval.node) ? (yyval.node)->begin_child : NULL
  );
  free_tree(params);

  if (!invalid) {
    cgen_append(&((yyval.node)->code), (yyvsp[-1].node)->code);
    cgen_append(
      &((yyval.node)->code),
      cgen_addv((yyvsp[-1].node)->code, &temp_inst_count)
    );
  }
}
#line 2745 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 674 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("adda"); 
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));

  Node* params = get_params_adda();
  check_params(
    (yyval.node)->id,
    params ? params->begin_child : NULL, 
    (yyval.node) ? (yyval.node)->begin_child : NULL
  );
  free_tree(params);
}
#line 2764 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 690 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("declaration");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  if((yyvsp[-1].node) != NULL) {
    push_child((yyval.node), (yyvsp[-1].node));
  }

  SymbolNode *match = stable_find_with_scope(symbol_table, global_scope, (yyvsp[0].node)->complement, STYPE_VARIABLE);
  if (match != NULL && scope_eq(global_scope, match->scope)) {
    char buffer[300] = {0};
    sprintf(buffer, "variable \"%s\" already declared", (yyvsp[0].node)->complement);
    semantic_error(buffer);
  }

  if ((yyvsp[-2].node)->t_token == VOID) {
    char buffer[300] = {0};
    sprintf(buffer, "\"VOID\" cannot be a type");
    semantic_error(buffer);
  }

  TypeExpression* type = type_build((yyvsp[-2].node), (yyvsp[-1].node));
  if (type && (yyvsp[-1].node) && type->size == 0) {
    char buffer[300] = {0};
    sprintf(buffer, "variable \"%s\" should not be a zero sized array", (yyvsp[0].node)->complement);
    semantic_error(buffer);  
  }

  SymbolNode *entry = stable_create_symbol((yyvsp[0].node)->complement, global_scope, STYPE_VARIABLE, type, (yyval.node));
  (yyval.node)->sentry = entry;
  (yyval.node)->type = type_cpy(type);
  symbol_table = stable_add(symbol_table, entry);

  if (!invalid) {
    if ((yyvsp[-1].node) != NULL) {
      // A principio nao esta sendo utilizado mas e gerado caso seja necessario
      // cgen_append(&($$->code), $dimension->code);
    }

    if (is_declaration_param) { 
      cgen_append(
        &((yyval.node)->code),
        cgen_declaration_param(entry, &param_inst_count)
      );
    } else {
      cgen_append(
        &((yyval.node)->code),
        cgen_declaration(entry, &temp_inst_count)
      );
    }
  }
}
#line 2822 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 745 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2828 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 746 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  // OBS: SE EM ALGUM MOMENTO MAIS DIMENSOES FOREM ADICIONADAS COLOCAR EM BEGIN/END CHILD
  (yyval.node) = create_node("dimension");
  push_child((yyval.node), (yyvsp[-1].node));
  (yyval.node)->code = (yyvsp[-1].node)->code;
}
#line 2839 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 754 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
  (yyval.node)->code = (yyvsp[0].node)->code;
  (yyval.node)->value_type = (yyvsp[0].node)->value_type;
}
#line 2850 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 760 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
  (yyval.node)->code = (yyvsp[0].node)->code;
}
#line 2860 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 765 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
  (yyval.node)->code = (yyvsp[0].node)->code;
}
#line 2870 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 770 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
  (yyval.node)->code = (yyvsp[0].node)->code;
}
#line 2880 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 777 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("access");
  (yyval.node)->value_type = LVALUE;
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
    
  SymbolNode *match = stable_find_with_scope(symbol_table, global_scope, (yyvsp[-1].node)->complement, STYPE_VARIABLE);

  if (match == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "variable \"%s\" not found in scope", (yyvsp[-1].node)->complement);
    semantic_error(buffer);
  } else {
    (yyval.node)->type = type_from_access_lvl(match->type, (yyvsp[0].node));
  
    if ((yyval.node)->type == NULL) {
      char buffer[300] = {0};
      sprintf(buffer, "access to \"%s\" of incompatible type", (yyvsp[-1].node)->complement);
      semantic_error(buffer);    
    }

    if (!invalid) {
      Node *access = (yyvsp[0].node) == NULL ? NULL : (yyvsp[0].node)->begin_child;
      cgen_append(
        &((yyval.node)->code),
        cgen_var_access(match, access, &temp_inst_count)
      );
    }
  }
  (yyval.node)->sentry = match;
}
#line 2916 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 810 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2922 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 811 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  // OBS: SE EM ALGUM MOMENTO MAIS DIMENSOES FOREM ADICIONADAS COLOCAR EM BEGIN/END CHILD
  (yyval.node) = create_node("access_lvl");
  push_child((yyval.node), (yyvsp[-2].node));

  if ((yyvsp[0].node)) {
    normalize_to_list((yyval.node), (yyvsp[0].node));
    free_node((yyvsp[0].node));
  }

  TypeExpression *tmax = type_max(&TYPE_EXPRESSION_INT, (yyvsp[-2].node)->type);
  (yyvsp[-2].node)->cast = type_get_cast(&TYPE_EXPRESSION_INT, (yyvsp[-2].node)->type);
  if (tmax == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "access must be of type int ");
    semantic_error(buffer);
  }

  if (!invalid) {
    cgen_append(&((yyvsp[-2].node)->code), cgen_derref_lvalue(cgen_last_inst((yyvsp[-2].node)->code)->fields[0], &temp_inst_count));
    cgen_append(&((yyvsp[-2].node)->code), cgen_cast(cgen_last_inst((yyvsp[-2].node)->code)->fields[0], (yyvsp[-2].node)->cast, &temp_inst_count));
  }
}
#line 2950 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 836 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]);
  
  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
}
#line 2962 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 845 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2968 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 846 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2974 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 847 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2980 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 848 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2986 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 849 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2992 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 855 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_int");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_INT);
  
  if (!invalid) {
    cgen_append(&((yyval.node)->code), cgen_const_code(TAC_OPTYPE_INT, atoi((yyval.node)->complement), 0.0, &temp_inst_count));
  }
}
#line 3009 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 869 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_float");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_FLOAT);
  
  if (!invalid) {
    cgen_append(&((yyval.node)->code), cgen_const_code(TAC_OPTYPE_FLOAT, 0, atof((yyval.node)->complement), &temp_inst_count));
  }
}
#line 3026 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 883 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  (yyval.node)->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("1") + 1);
  strcpy(cpy, "1");
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_INT);
  
  if (!invalid) {
    cgen_append(&((yyval.node)->code), cgen_const_code(TAC_OPTYPE_INT, 1, 0, &temp_inst_count));
  }
}
#line 3043 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 895 "./src/sintax/gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  (yyval.node)->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("0") + 1);
  strcpy(cpy, "0");
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_INT);
  
  if (!invalid) {
    cgen_append(&((yyval.node)->code), cgen_const_code(TAC_OPTYPE_INT, 0, 0, &temp_inst_count));
  }
}
#line 3060 "gramatica.tab.c" /* yacc.c:1646  */
    break;


#line 3064 "gramatica.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 909 "./src/sintax/gramatica.y" /* yacc.c:1906  */


/*-------------------UTILS--------------------------------*/

void normalize_to_list(Node *dst, Node *tree) {
  if (dst == NULL || tree == NULL) {
    return;
  }

  Node *it = tree->begin_child;
  while (it != NULL) {
    Node *tmp = it->next;
    push_child(dst, it);
    it = tmp;
  }
}

Node* get_params_addv() {
  Node* params = create_node("standalone_params");

  Node* graph  = create_node("standalone_type"); graph->t_token  = GRAPH; 
  graph->type  = type_build(graph, NULL);

  push_child(params, graph);

  return params;
}

Node* get_params_adda() {
  Node* params = create_node("standalone_params");

  Node* graph  = create_node("standalone_type"); graph->t_token  = GRAPH; 
  Node* v_src  = create_node("standalone_type"); v_src->t_token  = INT; 
  Node* v_dst  = create_node("standalone_type"); v_dst->t_token  = INT; 

  graph->type  = type_build(graph, NULL);
  v_src->type  = type_build(v_src, NULL);
  v_dst->type  = type_build(v_dst, NULL);

  push_child(params, graph);
  push_child(params, v_src);
  push_child(params, v_dst);

  return params;
}


Node* get_params_graph_call() {
  Node* params = create_node("standalone_params");

  Node* graph  = create_node("standalone_type"); graph->t_token  = GRAPH; 
  Node* vertex = create_node("standalone_type"); vertex->t_token = INT; 
  Node* value  = create_node("standalone_type"); value->t_token  = INT; 

  graph->type  = type_build(graph, NULL);
  vertex->type = type_build(vertex, NULL);
  value->type  = type_build(value, NULL);

  push_child(params, graph);
  push_child(params, vertex);
  push_child(params, value);

  return params;
}

/*-------------------TYPE CHECK---------------------------*/

void check_graph_call(char *id, Node* graph_params_call) {
  Node* params = get_params_graph_call();
  check_params(
    id,
    params ? params->begin_child : NULL, 
    graph_params_call ? graph_params_call->begin_child : NULL
  );
  free_tree(params);
}

/**
 * Checa lista de parametros percorrendo sempre next dos nodes passados.
 */
void check_params(char *function_id, Node *param, Node *param_call) {
  if (param == NULL && param_call == NULL) {
    return;
  }
  TypeExpression *param_type = param ? param->type : NULL;
  TypeExpression *param_call_type = param_call ? param_call->type : NULL;

  TypeExpression *tmax = type_max(param_type, param_call_type);
  if (tmax != NULL) {
      param_call->cast = type_get_cast(param_type, param_call_type);  
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, param_type, param_call_type);
    sprintf(buffer, "%s in call \"%s\"", buffer1, function_id);
    semantic_error(buffer);
  }
  check_params(
    function_id,
    param ? param->next : NULL, 
    param_call ? param_call->next : NULL
  );
}

void check_return(Node *tgt, Node *expr) {
  Scope* cur = scope_top(global_scope);
  if (cur == NULL || cur->function == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "there is no function for this return statement");
    semantic_error(buffer);
  } else {
    check_assign_expression(tgt, cur->function->type, expr);
  }
}

/**
 * Também usado para checar tipo em return statement.
 */
void check_assign_expression(Node *tgt, TypeExpression *tgt_type, Node *src) {
  TypeExpression *src_type = src ? src->type : &TYPE_EXPRESSION_VOID;
  TypeExpression *tmax = type_max(tgt_type, src_type);
  if (type_can_assign(tgt_type) && tmax) {
    if (src) {
      src->cast = type_get_cast(tgt_type, src_type);  
    }
    tgt->type = type_cpy(tgt_type);
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, tgt_type, src_type);
    sprintf(buffer, "%s with operator \"ASSIGN/RETURN\"", buffer1);
    semantic_error(buffer);
  }
}

void check_relational_expression(Node *tgt, Node *op1, Node *operator, Node *op2) {
  TypeExpression *tmax = type_max(op1->type, op2->type);
  if (type_is_aritmetic(tmax)) {
      op1->cast = type_get_cast(tmax, op1->type);  
      op2->cast = type_get_cast(tmax, op2->type);  
      tgt->type = type_cpy(&TYPE_EXPRESSION_BOOLEAN);
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, op1->type, op2->type);
    sprintf(buffer, "%s with operator \"%s\" ", buffer1, operator->id);
    semantic_error(buffer);
  }
}

void check_boolean_expression(Node *tgt, Node *op1, Node *operator, Node *op2) {
  TypeExpression *tmax = type_max(op1->type, op2->type);
  // Verifica se realmente pode ocorrer conversao
  tmax = type_max(&TYPE_EXPRESSION_BOOLEAN, tmax);
  if (tmax != NULL) {
      op1->cast = type_get_cast(&TYPE_EXPRESSION_BOOLEAN, op1->type);  
      op2->cast = type_get_cast(&TYPE_EXPRESSION_BOOLEAN, op2->type);  
      tgt->type = type_cpy(&TYPE_EXPRESSION_BOOLEAN);
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, op1->type, op2->type);
    sprintf(buffer, "%s with operator \"%s\" ", buffer1, operator->id);
    semantic_error(buffer);
  }
}

void check_aritmetic_expression(Node *tgt, Node *op1, Node *operator, Node *op2) {
  TypeExpression *tmax = type_max(op1->type, op2->type);
  if (type_is_aritmetic(tmax)) {
      op1->cast = type_get_cast(tmax, op1->type);  
      op2->cast = type_get_cast(tmax, op2->type);  
      tgt->type = type_cpy(tmax);
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, op1->type, op2->type);
    sprintf(buffer, "%s with operator \"%s\" ", buffer1, operator->id);
    semantic_error(buffer);
  }
}

/*-------------------ERROR/LOG-----------------------------*/

void build_incompatible_types_str(char* buffer, TypeExpression *a, TypeExpression *b) {
  char *undefined = "undefined";
  char *a_str = type_to_string(a);
  char *b_str = type_to_string(b);

  if (a_str == NULL) a_str = undefined;
  if (b_str == NULL) b_str = undefined;

  sprintf(buffer, "incompatible types \"%s\" and \"%s\"", a_str, b_str);

  if (a_str != undefined) free(a_str);
  if (b_str != undefined) free(b_str);
}

void yyerror (char const *s) {
  invalid = 1;
  error_recovery_mode = 1;
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

void semantic_error(char const *s) {
  invalid = 1;
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m semantic: %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

void warning(char const *s) {
  printf("\033[01;33mwarning\033[0;0m: %s\n", s);
}

int main() {
  scope_push(&global_scope, &scope_count, NULL);
  yyparse();

  printf("\n>>>>>>>>>>AST<<<<<<<<<<<\n\n");
  print_tree(ast, 1);

  printf("\n>>>>>>>>>>SYMBOL TABLE<<<<<<<<<<<\n\n");
  stable_print(symbol_table);

  if (!invalid && ast) {
    printf("\n>>>>>>>>>>TAC<<<<<<<<<<< (EM ARQUIVO \"out.tac\")\n\n");
    print_code(ast->code);

    fflush(stdout);
    FILE* tac_f = freopen("out.tac", "w", stdout);
    print_code(ast->code);
    fclose(tac_f);
  }
  
  free_scope(global_scope);
  free_tree(ast);
  free_stable(symbol_table);
  free_cgen();

  yylex_destroy();

  return 0;
}
