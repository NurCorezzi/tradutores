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
#line 5 "gramatica.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gramatica.tab.h"

#include "type_expression.c"
#include "node.h"
#include "ast.c"
#include "stable.c"

extern char *yytext;
int yylex_destroy ( void );
int yylex();

void check_params(char *function_id, Node *param, Node *param_call);
void check_compare_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_boolean_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_aritmetic_expression(Node *tgt, Node *op1, Node *operator, Node *op2);

void build_incompatible_types_str(char* buffer, TypeExpression *a, TypeExpression *b);
void yyerror (char const *s);
void semantic_error(char const *s);
int error_recovery_mode;


#line 94 "gramatica.tab.c" /* yacc.c:339  */

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
#line 1 "gramatica.y" /* yacc.c:355  */

  #include "node.h"

#line 128 "gramatica.tab.c" /* yacc.c:355  */

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
#line 46 "gramatica.y" /* yacc.c:355  */

  int id;
  Node* node;

#line 193 "gramatica.tab.c" /* yacc.c:355  */
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

#line 224 "gramatica.tab.c" /* yacc.c:358  */

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
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    97,    98,   111,   133,   111,   156,   159,
     160,   170,   176,   198,   199,   209,   215,   216,   219,   231,
     231,   245,   249,   253,   256,   259,   262,   266,   271,   278,
     283,   287,   293,   300,   300,   307,   308,   312,   316,   319,
     322,   325,   335,   351,   356,   363,   366,   374,   377,   385,
     388,   396,   399,   407,   410,   418,   421,   429,   432,   456,
     459,   462,   463,   470,   471,   472,   475,   476,   478,   479,
     480,   481,   483,   484,   485,   486,   487,   488,   495,   499,
     507,   507,   520,   544,   545,   552,   556,   560,   566,   590,
     591,   598,   607,   608,   609,   610,   611,   614,   614,   617,
     627,   637,   645
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "BOOLEAN",
  "INT", "FLOAT", "GRAPH", "VOID", "TO", "TRUE", "FALSE", "ID", "C_FLOAT",
  "C_INT", "READ", "WRITE", "DFS", "BFS", "ADDA", "ADDV", "RETURN", "AND",
  "OR", "LE", "GE", "LESS", "GREATER", "EQ", "NE", "NOT", "MUL", "DIV",
  "ADD", "SUB", "ASSIGN", "END", "OPEN_BRACE", "CLOSE_BRACE", "IT",
  "SEPARATOR", "OPEN_P", "CLOSE_P", "OPEN_BRACKET", "CLOSE_BRACKET",
  "$accept", "init", "program", "function", "$@1", "$@2", "params",
  "function_call", "params_call", "graph_call", "graph_params_call",
  "statements", "statement", "statement_no_dangle", "dangling_if",
  "statement_prefix", "block", "$@3", "statement_end", "expr_assign",
  "expr_relational", "expr_and", "expr_or", "expr_add", "expr_sub",
  "expr_mul", "expr_div", "expr_unary", "factor", "unary", "and", "or",
  "add", "sub", "mul", "div", "compare_op", "graph_add",
  "declaration_or_assign", "declaration", "dimension", "value",
  "id_or_access", "access_lvl", "id", "type", "number", "number_int",
  "number_float", "boolean_const", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -130

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-130)))

#define YYTABLE_NINF -28

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -130,     6,   110,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,   -35,    18,    24,  -130,    -2,  -130,  -130,  -130,    12,
      89,   -36,  -130,   -35,    89,  -130,    24,  -130,    17,  -130,
    -130,   143,  -130,    25,    26,    27,  -130,  -130,  -130,    24,
      46,    30,    31,    46,  -130,  -130,  -130,  -130,  -130,    46,
    -130,  -130,  -130,   224,  -130,  -130,    41,    43,    57,    67,
      68,    65,    66,    70,    72,  -130,    51,  -130,  -130,    63,
      74,    76,  -130,  -130,   -28,  -130,  -130,  -130,  -130,    46,
      46,    46,    77,    69,    83,    24,    24,    84,  -130,    79,
      81,  -130,  -130,  -130,    46,  -130,  -130,  -130,  -130,  -130,
    -130,    46,  -130,    46,  -130,    46,    46,    46,  -130,    46,
    -130,    46,  -130,  -130,  -130,    46,    46,    46,  -130,    82,
      87,    88,    90,  -130,  -130,    91,    86,  -130,   185,  -130,
      46,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
       1,  -130,    85,    14,    46,    32,  -130,  -130,    46,  -130,
      92,    46,  -130,  -130,  -130,   130,   224,   135,   101,    98,
      98,   100,   104,    14,  -130,  -130,   139,    46,    24,  -130,
    -130,  -130,    46,   118,   121,   123,  -130,    46,  -130,   126,
      46,   125,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     8,    93,    92,    94,    95,    96,
       4,    83,     0,     0,    99,     0,    91,     5,    84,     0,
       9,     0,    11,    83,     0,     6,     0,    10,     0,    82,
      19,     0,    25,     0,     0,     0,   101,   102,   100,     0,
       0,     0,     0,     0,    63,    68,    69,    33,     7,     0,
      62,    20,    24,     0,    35,    23,     0,    43,    45,    47,
      49,    51,    53,    55,    57,    59,     0,    64,    65,     0,
       0,    80,    61,    85,    89,    86,    97,    98,    87,     0,
       0,     0,     0,    89,     0,     0,     0,     0,    19,     0,
       0,    22,    21,    39,     0,    72,    73,    74,    75,    76,
      77,     0,    66,     0,    67,     0,     0,     0,    70,     0,
      71,     0,    58,    40,    38,     0,    13,     0,    88,     0,
       0,    85,     0,    36,    37,     0,     0,    41,     0,    60,
       0,    42,    44,    46,    48,    50,    52,    54,    56,    81,
       0,    15,     0,     0,     0,     0,    30,    78,     0,    34,
       0,     0,    12,    90,    28,     0,     0,    23,     0,     0,
       0,     0,     0,     0,    14,    29,    21,     0,     0,    16,
      17,    32,     0,     0,     0,     0,    31,     0,    79,     0,
       0,     0,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
      11,    93,  -129,  -130,   -48,    29,  -130,  -130,   -50,   -39,
      73,    75,    80,    71,    99,    64,    78,  -130,   109,  -130,
    -130,  -130,   136,   120,  -130,  -130,  -130,  -130,  -130,   -12,
     182,  -130,   -37,  -130,   -13,   208,  -130,   199,  -130,  -130
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    19,    28,    21,    50,   140,   161,
     169,    31,    51,   155,    52,    53,    54,    88,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
     103,   105,    67,    68,   109,   111,   101,    69,    70,    71,
      13,    72,    73,   118,    74,    23,    75,    76,    77,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    84,    82,    92,    87,    91,     3,    24,    22,    25,
      89,    12,    27,    29,   154,    32,   116,    33,   117,    34,
      35,     5,     6,     7,     8,     9,    83,    36,    37,    16,
      38,    14,    39,    40,   154,    14,    41,    42,    43,    16,
     119,   120,   122,   121,   151,    18,   152,    44,   125,   126,
      45,    46,   159,   160,    47,   131,    20,    30,    49,    36,
      37,    16,    38,    14,    36,    37,    16,    38,    14,    79,
      80,    81,    83,    83,    85,    86,   139,   141,   142,    44,
      93,    94,    45,    46,    95,    96,    97,    98,    99,   100,
      49,   150,   102,   157,   104,    49,     5,     6,     7,     8,
       9,    45,   113,    46,   108,   158,   166,   110,    91,   162,
      -2,     4,   164,   114,   115,   117,   123,     5,     6,     7,
       8,     9,   124,   127,   129,   130,   144,   143,   173,   148,
     145,   174,   153,   175,   165,   146,   147,   163,   179,   -27,
     167,   181,   168,   -26,    32,   171,    33,   172,    34,    35,
       5,     6,     7,     8,     9,    83,    36,    37,    16,    38,
      14,    39,    40,   176,   177,    41,    42,    43,   178,   180,
     182,   170,   156,   137,   132,   112,    44,   135,   133,    45,
      46,   128,   107,    47,    48,   134,    32,    49,    33,   138,
      34,    35,     5,     6,     7,     8,     9,   106,    36,    37,
      16,    38,    14,    39,    40,    26,   136,    41,    42,    43,
      11,    15,     0,     0,     0,     0,     0,     0,    44,     0,
       0,    45,    46,     0,     0,    47,   149,    90,     0,    49,
       0,     5,     6,     7,     8,     9,     0,    36,    37,    16,
      38,    14,    39,    40,     0,     0,    41,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
      45,    46,     0,     0,    47,     0,     0,     0,    49
};

static const yytype_int16 yycheck[] =
{
      13,    40,    39,    53,    43,    53,     0,    43,    20,    45,
      49,    46,    24,    26,   143,     1,    44,     3,    46,     5,
       6,     7,     8,     9,    10,    11,    39,    13,    14,    15,
      16,    17,    18,    19,   163,    17,    22,    23,    24,    15,
      79,    80,    81,    80,    43,    47,    45,    33,    85,    86,
      36,    37,    20,    21,    40,    94,    44,    40,    44,    13,
      14,    15,    16,    17,    13,    14,    15,    16,    17,    44,
      44,    44,    85,    86,    44,    44,   115,   116,   117,    33,
      39,    38,    36,    37,    27,    28,    29,    30,    31,    32,
      44,   130,    25,   143,    26,    44,     7,     8,     9,    10,
      11,    36,    39,    37,    34,   144,   156,    35,   156,   148,
       0,     1,   151,    39,    38,    46,    39,     7,     8,     9,
      10,    11,    39,    39,    45,    44,    39,    45,   167,    43,
      42,   168,    47,   172,     4,    45,    45,    45,   177,     4,
      39,   180,    44,     4,     1,    45,     3,    43,     5,     6,
       7,     8,     9,    10,    11,   168,    13,    14,    15,    16,
      17,    18,    19,    45,    43,    22,    23,    24,    45,    43,
      45,   160,   143,   109,   101,    66,    33,   106,   103,    36,
      37,    88,    62,    40,    41,   105,     1,    44,     3,   111,
       5,     6,     7,     8,     9,    10,    11,    61,    13,    14,
      15,    16,    17,    18,    19,    23,   107,    22,    23,    24,
       2,    12,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    40,    41,     3,    -1,    44,
      -1,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    40,    -1,    -1,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     1,     7,     8,     9,    10,    11,
      51,    93,    46,    88,    17,    95,    15,    92,    47,    52,
      44,    54,    87,    93,    43,    45,    88,    87,    53,    92,
      40,    59,     1,     3,     5,     6,    13,    14,    16,    18,
      19,    22,    23,    24,    33,    36,    37,    40,    41,    44,
      55,    60,    62,    63,    64,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    80,    81,    85,
      86,    87,    89,    90,    92,    94,    95,    96,    97,    44,
      44,    44,    90,    92,    67,    44,    44,    67,    65,    67,
       3,    62,    66,    39,    38,    27,    28,    29,    30,    31,
      32,    84,    25,    78,    26,    79,    80,    81,    34,    82,
      35,    83,    76,    39,    39,    38,    44,    46,    91,    67,
      67,    90,    67,    39,    39,    90,    90,    39,    59,    45,
      44,    67,    68,    69,    70,    71,    72,    73,    74,    67,
      56,    67,    67,    45,    39,    42,    45,    45,    43,    41,
      67,    43,    45,    47,    60,    61,    63,    66,    67,    20,
      21,    57,    67,    45,    67,     4,    66,    39,    44,    58,
      58,    45,    43,    67,    90,    67,    45,    43,    45,    67,
      43,    67,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    52,    53,    51,    51,    54,
      54,    54,    55,    56,    56,    56,    57,    57,    58,    59,
      59,    60,    60,    60,    60,    60,    61,    61,    62,    63,
      63,    63,    63,    65,    64,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    77,    77,    77,    78,    79,    80,    81,
      82,    83,    84,    84,    84,    84,    84,    84,    85,    85,
      86,    86,    87,    88,    88,    89,    89,    89,    90,    91,
      91,    92,    93,    93,    93,    93,    93,    94,    94,    95,
      96,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,    11,     1,     0,
       3,     1,     4,     0,     3,     1,     2,     2,     7,     0,
       2,     2,     2,     1,     1,     1,     2,     1,     5,     6,
       4,     8,     6,     0,     4,     1,     3,     3,     2,     2,
       2,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     8,
       1,     3,     3,     0,     3,     1,     1,     1,     2,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
          case 49: /* init  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1278 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 50: /* program  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1288 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 51: /* function  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1298 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* params  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1308 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* function_call  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1318 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 56: /* params_call  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1328 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 57: /* graph_call  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1338 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* graph_params_call  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1348 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* statements  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1358 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 60: /* statement  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1368 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* statement_no_dangle  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1378 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* dangling_if  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1388 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* statement_prefix  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1398 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* block  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1408 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* statement_end  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1418 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* expr_assign  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1428 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* expr_relational  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1438 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 69: /* expr_and  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1448 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 70: /* expr_or  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1458 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 71: /* expr_add  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1468 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 72: /* expr_sub  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1478 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 73: /* expr_mul  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1488 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 74: /* expr_div  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1498 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 75: /* expr_unary  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1508 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 76: /* factor  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1518 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 77: /* unary  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1528 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 78: /* and  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1538 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 79: /* or  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1548 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 80: /* add  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1558 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 81: /* sub  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1568 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 82: /* mul  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1578 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 83: /* div  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1588 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 84: /* compare_op  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1598 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 85: /* graph_add  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1608 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 86: /* declaration_or_assign  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1618 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 87: /* declaration  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1628 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 88: /* dimension  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1638 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 89: /* value  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1648 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 90: /* id_or_access  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1658 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 91: /* access_lvl  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1668 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 92: /* id  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1678 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 93: /* type  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1688 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 94: /* number  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1698 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 95: /* number_int  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1708 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 96: /* number_float  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1718 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 97: /* boolean_const  */
#line 68 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1728 "gramatica.tab.c" /* yacc.c:1257  */
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
#line 88 "gramatica.y" /* yacc.c:1646  */
    {
  ast = (yyval.node) = (yyvsp[0].node);
}
#line 2018 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2024 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 98 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("program");
  if ((yyvsp[-1].node) != NULL) {
    Node *it;
    for (it = (yyvsp[-1].node)->begin_child; it != NULL; it = it->next) {
      push_child((yyval.node), it);
    }
    free_node((yyvsp[-1].node));
  }
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2040 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 111 "gramatica.y" /* yacc.c:1646  */
    {
  // Necessario declarar funcao na tabela de simbolos antes da declaracao de seus parametros para que escopo esteja correto
  SymbolNode *match = stable_find_with_scope(symbol_table, global_scope, (yyvsp[0].node)->complement, STYPE_FUNCTION);
  if (match != NULL && scope_eq(global_scope, match->scope)) {
    char buffer[300] = {0};
    sprintf(buffer, "function \"%s\" already declared", (yyvsp[0].node)->complement);
    semantic_error(buffer);
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

  scope_push();
}
#line 2068 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 133 "gramatica.y" /* yacc.c:1646  */
    {
  // Obtencao de parametros para symbol table
  SymbolNode *entry = stable_find_with_scope(symbol_table, global_scope, (yyvsp[-4].node)->complement, STYPE_FUNCTION);  
  entry->ast_node = (yyvsp[-1].node);
}
#line 2078 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 137 "gramatica.y" /* yacc.c:1646  */
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

  scope_pop();
}
#line 2102 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 156 "gramatica.y" /* yacc.c:1646  */
    { error_recovery_mode = 0; (yyval.node) = NULL; }
#line 2108 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2114 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 160 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  
  Node *it;
  for (it = (yyvsp[-2].node)->begin_child; it != NULL; it = it->next) {
    push_child((yyval.node), it);
  }
  free_node((yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2129 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 170 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2138 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "gramatica.y" /* yacc.c:1646  */
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
}
#line 2163 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 198 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2169 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 199 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  
  Node *it;
  for (it = (yyvsp[-2].node)->begin_child; it != NULL; it = it->next) {
    push_child((yyval.node), it);
  }
  free_node((yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2184 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 209 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2193 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 215 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("dfs"); push_child((yyval.node), (yyvsp[0].node));}
#line 2199 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 216 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("bfs"); push_child((yyval.node), (yyvsp[0].node));}
#line 2205 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 219 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("graph_params");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2216 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 231 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2222 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 231 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("statements");

  if ((yyvsp[-1].node) != NULL) {
    Node *it;
    for (it = (yyvsp[-1].node)->begin_child; it != NULL; it = it->next) {
      push_child((yyval.node), it);
    }
    free_node((yyvsp[-1].node));
  }  
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2239 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 245 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2248 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 249 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2257 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 253 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2265 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 256 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2273 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 259 "gramatica.y" /* yacc.c:1646  */
    { error_recovery_mode = 0; (yyval.node) = NULL; }
#line 2279 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 262 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2288 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 266 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2296 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 271 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_open");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2306 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 278 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_else");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2316 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 283 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("while");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2325 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 287 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2336 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 293 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for_iterator");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2346 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 300 "gramatica.y" /* yacc.c:1646  */
    { scope_push(); }
#line 2352 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 300 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("block");
  push_child((yyval.node), (yyvsp[-1].node));
  scope_pop();
}
#line 2362 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 308 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("read");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2371 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 312 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("write");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2380 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 316 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2388 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 319 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2396 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 322 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2404 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 325 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("return");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2413 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 335 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_assign");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  TypeExpression *tmax = type_max((yyvsp[-2].node)->type, (yyvsp[0].node)->type);
  if (type_can_assign((yyvsp[-2].node)->type) && tmax) {
      (yyvsp[0].node)->cast = type_get_cast((yyvsp[-2].node)->type, (yyvsp[0].node)->type);  
      (yyval.node)->type = type_cpy((yyvsp[-2].node)->type);
  } else {
    char buffer[300] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, (yyvsp[-2].node)->type, (yyvsp[0].node)->type);
    sprintf(buffer, "%s with operator \"ASSIGN\"", buffer1);
    semantic_error(buffer);
  }
}
#line 2434 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 351 "gramatica.y" /* yacc.c:1646  */
    {  
  (yyval.node) = (yyvsp[0].node);
}
#line 2442 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 356 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_relational");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_compare_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2454 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 366 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_and");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_boolean_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2467 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 377 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_or");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_boolean_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2480 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 388 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_add");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2493 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 399 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_sub");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  
  free_tree((yyvsp[-1].node));
}
#line 2506 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 410 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_mul");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2519 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 421 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_div");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2532 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 432 "gramatica.y" /* yacc.c:1646  */
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
}
#line 2561 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 459 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2569 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 470 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2575 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 475 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2581 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 476 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2587 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 478 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2593 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 479 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2599 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 480 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2605 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 481 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2611 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 483 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2617 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 484 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2623 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 485 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2629 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 486 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2635 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 487 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2641 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 488 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2647 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 495 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("adda"); 
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2656 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 499 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("addv"); 
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2667 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 507 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("statements");

  // Divisao em declaracao e atribuicao
  Node* assign = create_node("assignment");
  push_child(assign, create_node((yyvsp[-2].node)->end_child->id));
  push_child(assign, (yyvsp[0].node));

  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), assign);
}
#line 2683 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 520 "gramatica.y" /* yacc.c:1646  */
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

  TypeExpression* type = type_build((yyvsp[-2].node), (yyvsp[-1].node));
  SymbolNode *entry = stable_create_symbol((yyvsp[0].node)->complement, global_scope, STYPE_VARIABLE, type, (yyval.node));
  (yyval.node)->sentry = entry;
  (yyval.node)->type = type_cpy(type);
  symbol_table = stable_add(symbol_table, entry);
}
#line 2710 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 544 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2716 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 545 "gramatica.y" /* yacc.c:1646  */
    {
  // OBS: SE EM ALGUM MOMENTO MAIS DIMENSOES FOREM ADICIONADAS COLOCAR EM BEGIN/END CHILD
  (yyval.node) = create_node("dimension");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2726 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 552 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2735 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 556 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2744 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 560 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2753 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 566 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("access");
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
  }
  (yyval.node)->sentry = match;
}
#line 2780 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 590 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2786 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 591 "gramatica.y" /* yacc.c:1646  */
    {
  // OBS: SE EM ALGUM MOMENTO MAIS DIMENSOES FOREM ADICIONADAS COLOCAR EM BEGIN/END CHILD
  (yyval.node) = create_node("access_lvl");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2796 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 598 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]);
  
  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
}
#line 2808 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 607 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2814 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 608 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2820 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 609 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2826 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 610 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2832 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 611 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2838 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 617 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_int");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_INT);
}
#line 2851 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 627 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_float");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_FLOAT);
}
#line 2864 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 637 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  (yyval.node)->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("1") + 1);
  strcpy(cpy, "1");
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_INT);
}
#line 2877 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 645 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  (yyval.node)->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("0") + 1);
  strcpy(cpy, "0");
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_INT);
}
#line 2890 "gramatica.tab.c" /* yacc.c:1646  */
    break;


#line 2894 "gramatica.tab.c" /* yacc.c:1646  */
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
#line 655 "gramatica.y" /* yacc.c:1906  */


/**
 * Checa lista de parametros percorrendo sempre next dos nodes passados.
 */
void check_params(char *function_id, Node *param, Node *param_call) {
  if (param == NULL && param_call == NULL) {
    return;
  }
  TypeExpression *tmax = type_max(param->type, param_call->type);
  if (tmax != NULL) {
      param_call->cast = type_get_cast(param->type, param_call->type);  
  } else {
    char buffer[300] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, param->type, param_call->type);
    sprintf(buffer, "%s in call \"%s\"", buffer1, function_id);
    semantic_error(buffer);
  }
  check_params(
    function_id,
    param ? param->next : NULL, 
    param_call ? param_call->next : NULL
  );
}

void check_compare_expression(Node *tgt, Node *op1, Node *operator, Node *op2) {
  TypeExpression *tmax = type_max(op1->type, op2->type);
  if (type_is_aritmetic(tmax)) {
      op1->cast = type_get_cast(tmax, op1->type);  
      op2->cast = type_get_cast(tmax, op2->type);  
      tgt->type = type_cpy(&TYPE_EXPRESSION_BOOLEAN);
  } else {
    char buffer[300] = {0}, buffer1[300] = {0};
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
    char buffer[300] = {0}, buffer1[300] = {0};
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
    char buffer[300] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, op1->type, op2->type);
    sprintf(buffer, "%s with operator \"%s\" ", buffer1, operator->id);
    semantic_error(buffer);
  }
}

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
  error_recovery_mode = 1;
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

void semantic_error(char const *s) {
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m semantic: %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

int main() {
  scope_push();
  yyparse();

  printf("\n>>>>>>>>>>AST<<<<<<<<<<<\n\n");
  print_tree(ast, 1);

  printf("\n>>>>>>>>>>SYMBOL TABLE<<<<<<<<<<<\n\n");
  stable_print(symbol_table);
  
  free_scope(global_scope);
  free_tree(ast);
  free_stable(symbol_table);
  yylex_destroy();
}
