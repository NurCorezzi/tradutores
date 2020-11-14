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

Node* get_params_addv();
Node* get_params_adda();
Node* get_params_graph_call();

void check_graph_call(char *id, Node* graph_params_call);
void check_params(char *function_id, Node *param, Node *param_call);
void check_assign_expression(Node *tgt, TypeExpression *tgt_type, Node *op2);
void check_compare_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_boolean_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_aritmetic_expression(Node *tgt, Node *op1, Node *operator, Node *op2);

void build_incompatible_types_str(char* buffer, TypeExpression *a, TypeExpression *b);
void yyerror (char const *s);
void semantic_error(char const *s);
void warning(char const *s);
int error_recovery_mode;


#line 101 "gramatica.tab.c" /* yacc.c:339  */

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

#line 135 "gramatica.tab.c" /* yacc.c:355  */

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
#line 53 "gramatica.y" /* yacc.c:355  */

  int id;
  Node* node;

#line 200 "gramatica.tab.c" /* yacc.c:355  */
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

#line 231 "gramatica.tab.c" /* yacc.c:358  */

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
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

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
       0,    95,    95,   108,   109,   122,   148,   122,   171,   174,
     175,   185,   191,   213,   214,   224,   230,   235,   242,   254,
     254,   268,   272,   276,   279,   282,   285,   289,   294,   301,
     306,   310,   316,   329,   329,   336,   337,   341,   345,   348,
     351,   354,   373,   385,   390,   397,   400,   408,   411,   419,
     422,   430,   433,   441,   444,   452,   455,   463,   466,   490,
     493,   496,   497,   504,   505,   506,   509,   510,   512,   513,
     514,   515,   517,   518,   519,   520,   521,   522,   529,   541,
     557,   588,   589,   596,   600,   604,   610,   635,   636,   651,
     660,   661,   662,   663,   664,   667,   667,   670,   680,   690,
     698
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
  "add", "sub", "mul", "div", "compare_op", "graph_add", "declaration",
  "dimension", "value", "id_or_access", "access_lvl", "id", "type",
  "number", "number_int", "number_float", "boolean_const", YY_NULLPTR
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

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -28

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -136,    11,    51,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   -22,    19,    31,  -136,     2,  -136,  -136,  -136,    12,
      56,   -36,  -136,   -22,    56,  -136,    31,  -136,    17,  -136,
    -136,   141,  -136,    24,    25,    26,  -136,  -136,  -136,    31,
       1,    29,    30,     1,  -136,  -136,  -136,  -136,  -136,     1,
    -136,  -136,  -136,   263,  -136,  -136,    38,    40,     0,    54,
      55,    44,    45,    49,    50,  -136,     6,  -136,  -136,    47,
      48,  -136,  -136,   -11,  -136,  -136,  -136,  -136,     1,     1,
       1,    52,    42,    53,    31,    31,    57,  -136,    39,    60,
    -136,  -136,  -136,     1,  -136,  -136,  -136,  -136,  -136,  -136,
       1,  -136,     1,  -136,     1,     1,     1,  -136,     1,  -136,
       1,  -136,  -136,  -136,     1,     1,  -136,    62,    58,    59,
      63,  -136,  -136,    67,    66,  -136,   183,  -136,     1,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,    10,  -136,    46,
     225,     1,    23,  -136,     1,  -136,  -136,    68,     1,  -136,
      42,  -136,    90,   263,    91,    61,    70,    70,    71,    69,
     225,  -136,  -136,  -136,    94,     1,    31,  -136,  -136,  -136,
       1,    72,    75,    74,  -136,     1,  -136,    77,     1,    76,
    -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     8,    91,    90,    92,    93,    94,
       4,    81,     0,     0,    97,     0,    89,     5,    82,     0,
       9,     0,    11,    81,     0,     6,     0,    10,     0,    80,
      19,     0,    25,     0,     0,     0,    99,   100,    98,     0,
       0,     0,     0,     0,    63,    68,    69,    33,     7,     0,
      62,    20,    24,     0,    35,    23,     0,    43,    45,    47,
      49,    51,    53,    55,    57,    59,     0,    64,    65,     0,
       0,    61,    83,    87,    84,    95,    96,    85,     0,     0,
       0,     0,    87,     0,     0,     0,     0,    19,     0,     0,
      22,    21,    39,     0,    72,    73,    74,    75,    76,    77,
       0,    66,     0,    67,     0,     0,     0,    70,     0,    71,
       0,    58,    40,    38,    13,     0,    86,     0,     0,    83,
       0,    36,    37,     0,     0,    41,     0,    60,     0,    42,
      44,    46,    48,    50,    52,    54,    56,     0,    15,     0,
       0,     0,     0,    30,     0,    78,    34,     0,     0,    12,
      87,    28,     0,     0,    23,     0,     0,     0,     0,     0,
       0,    14,    88,    29,    21,     0,     0,    16,    17,    32,
       0,     0,     0,     0,    31,     0,    79,     0,     0,     0,
      18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
     -58,    28,  -135,  -136,   -47,   -18,  -136,  -136,   -50,   -39,
      27,    21,    20,    32,    22,    33,    15,  -136,    64,  -136,
    -136,  -136,    73,    78,  -136,  -136,  -136,  -136,   -12,   109,
    -136,   -37,   -17,   -13,   133,  -136,   126,  -136,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    19,    28,    21,    50,   137,   158,
     167,    31,    51,   152,    52,    53,    54,    87,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
     102,   104,    67,    68,   108,   110,   100,    69,    70,    13,
      71,    72,   116,    73,    23,    74,    75,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    83,    81,    91,    86,   151,    90,    24,    22,    25,
      88,     3,    27,    29,    36,    37,    16,    38,    14,    36,
      37,    16,    38,    14,    12,   151,    82,    94,    95,    96,
      97,    98,    99,   114,    44,   115,    14,    45,    46,   117,
     118,   120,   119,   156,   157,    49,    16,   123,   124,    18,
      49,    -2,     4,   148,   129,   149,    20,    30,     5,     6,
       7,     8,     9,     5,     6,     7,     8,     9,    78,    79,
      80,    82,    82,    84,    85,   138,   139,    92,    93,   101,
      45,   103,    46,   107,   127,   109,   112,   113,   115,   147,
     154,   121,   122,   150,   163,   -27,   125,   141,   -26,   168,
     165,   142,   155,   164,   128,   159,    90,   140,   143,   161,
     144,   145,   170,   160,   166,   126,   169,   174,   175,   176,
     178,   180,   153,   131,   132,   136,   171,   130,   134,   172,
     111,   173,    26,   162,   105,    11,   177,   133,    15,   179,
     106,   135,    32,     0,    33,     0,    34,    35,     5,     6,
       7,     8,     9,    82,    36,    37,    16,    38,    14,    39,
      40,     0,     0,    41,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,     0,    45,    46,     0,
       0,    47,    48,     0,    32,    49,    33,     0,    34,    35,
       5,     6,     7,     8,     9,     0,    36,    37,    16,    38,
      14,    39,    40,     0,     0,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,    44,     0,     0,    45,
      46,     0,     0,    47,   146,     0,    32,    49,    33,     0,
      34,    35,     5,     6,     7,     8,     9,     0,    36,    37,
      16,    38,    14,    39,    40,     0,     0,    41,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
       0,    45,    46,     0,     0,    47,    89,     0,     0,    49,
       5,     6,     7,     8,     9,     0,    36,    37,    16,    38,
      14,    39,    40,     0,     0,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,    44,     0,     0,    45,
      46,     0,     0,    47,     0,     0,     0,    49
};

static const yytype_int16 yycheck[] =
{
      13,    40,    39,    53,    43,   140,    53,    43,    20,    45,
      49,     0,    24,    26,    13,    14,    15,    16,    17,    13,
      14,    15,    16,    17,    46,   160,    39,    27,    28,    29,
      30,    31,    32,    44,    33,    46,    17,    36,    37,    78,
      79,    80,    79,    20,    21,    44,    15,    84,    85,    47,
      44,     0,     1,    43,    93,    45,    44,    40,     7,     8,
       9,    10,    11,     7,     8,     9,    10,    11,    44,    44,
      44,    84,    85,    44,    44,   114,   115,    39,    38,    25,
      36,    26,    37,    34,    45,    35,    39,    39,    46,   128,
     140,    39,    39,    47,     4,     4,    39,    39,     4,   157,
      39,    42,   141,   153,    44,   144,   153,    45,    45,   148,
      43,    45,    43,    45,    44,    87,    45,    45,    43,    45,
      43,    45,   140,   102,   104,   110,   165,   100,   106,   166,
      66,   170,    23,   150,    61,     2,   175,   105,    12,   178,
      62,   108,     1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,   166,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    36,    37,    -1,
      -1,    40,    41,    -1,     1,    44,     3,    -1,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    36,
      37,    -1,    -1,    40,    41,    -1,     1,    44,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    40,     3,    -1,    -1,    44,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    36,
      37,    -1,    -1,    40,    -1,    -1,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     1,     7,     8,     9,    10,    11,
      51,    92,    46,    87,    17,    94,    15,    91,    47,    52,
      44,    54,    86,    92,    43,    45,    87,    86,    53,    91,
      40,    59,     1,     3,     5,     6,    13,    14,    16,    18,
      19,    22,    23,    24,    33,    36,    37,    40,    41,    44,
      55,    60,    62,    63,    64,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    80,    81,    85,
      86,    88,    89,    91,    93,    94,    95,    96,    44,    44,
      44,    89,    91,    67,    44,    44,    67,    65,    67,     3,
      62,    66,    39,    38,    27,    28,    29,    30,    31,    32,
      84,    25,    78,    26,    79,    80,    81,    34,    82,    35,
      83,    76,    39,    39,    44,    46,    90,    67,    67,    89,
      67,    39,    39,    89,    89,    39,    59,    45,    44,    67,
      68,    69,    70,    71,    72,    73,    74,    56,    67,    67,
      45,    39,    42,    45,    43,    45,    41,    67,    43,    45,
      47,    60,    61,    63,    66,    67,    20,    21,    57,    67,
      45,    67,    90,     4,    66,    39,    44,    58,    58,    45,
      43,    67,    89,    67,    45,    43,    45,    67,    43,    67,
      45
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
      86,    87,    87,    88,    88,    88,    89,    90,    90,    91,
      92,    92,    92,    92,    92,    93,    93,    94,    95,    96,
      96
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
       3,     0,     3,     1,     1,     1,     2,     0,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1292 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 50: /* program  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1302 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 51: /* function  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1312 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* params  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1322 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* function_call  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1332 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 56: /* params_call  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1342 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 57: /* graph_call  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1352 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* graph_params_call  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1362 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* statements  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1372 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 60: /* statement  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1382 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* statement_no_dangle  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1392 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* dangling_if  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1402 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* statement_prefix  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1412 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* block  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1422 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* statement_end  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1432 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* expr_assign  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1442 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* expr_relational  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1452 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 69: /* expr_and  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1462 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 70: /* expr_or  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1472 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 71: /* expr_add  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1482 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 72: /* expr_sub  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1492 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 73: /* expr_mul  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1502 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 74: /* expr_div  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1512 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 75: /* expr_unary  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1522 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 76: /* factor  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1532 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 77: /* unary  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1542 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 78: /* and  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1552 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 79: /* or  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1562 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 80: /* add  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1572 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 81: /* sub  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1582 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 82: /* mul  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1592 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 83: /* div  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1602 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 84: /* compare_op  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1612 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 85: /* graph_add  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1622 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 86: /* declaration  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1632 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 87: /* dimension  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1642 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 88: /* value  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1652 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 89: /* id_or_access  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1662 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 90: /* access_lvl  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1672 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 91: /* id  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1682 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 92: /* type  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1692 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 93: /* number  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1702 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 94: /* number_int  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1712 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 95: /* number_float  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1722 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 96: /* boolean_const  */
#line 75 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1732 "gramatica.tab.c" /* yacc.c:1257  */
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
#line 95 "gramatica.y" /* yacc.c:1646  */
    {
  ast = (yyval.node) = (yyvsp[0].node);

  if (!has_main) {
    warning("no main function identified program will not run");
  }
}
#line 2026 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2032 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "gramatica.y" /* yacc.c:1646  */
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
#line 2048 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 122 "gramatica.y" /* yacc.c:1646  */
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

  scope_push(entry);
}
#line 2080 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 148 "gramatica.y" /* yacc.c:1646  */
    {
  // Obtencao de parametros para symbol table
  SymbolNode *entry = stable_find_with_scope(symbol_table, global_scope, (yyvsp[-4].node)->complement, STYPE_FUNCTION);  
  entry->ast_node = (yyvsp[-1].node);
}
#line 2090 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 152 "gramatica.y" /* yacc.c:1646  */
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
#line 2114 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 171 "gramatica.y" /* yacc.c:1646  */
    { error_recovery_mode = 0; (yyval.node) = NULL; }
#line 2120 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 174 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2126 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 175 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  
  Node *it;
  for (it = (yyvsp[-2].node)->begin_child; it != NULL; it = it->next) {
    push_child((yyval.node), it);
  }
  free_node((yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2141 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 185 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2150 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 191 "gramatica.y" /* yacc.c:1646  */
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
#line 2175 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 213 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2181 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 214 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  
  Node *it;
  for (it = (yyvsp[-2].node)->begin_child; it != NULL; it = it->next) {
    push_child((yyval.node), it);
  }
  free_node((yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2196 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 224 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2205 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 230 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("dfs"); 
  push_child((yyval.node), (yyvsp[0].node));
  check_graph_call((yyval.node)->id, (yyvsp[0].node));
}
#line 2215 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 235 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("bfs"); 
  push_child((yyval.node), (yyvsp[0].node));
  check_graph_call((yyval.node)->id, (yyvsp[0].node));
}
#line 2225 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 242 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("graph_params");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2236 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 254 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2242 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 254 "gramatica.y" /* yacc.c:1646  */
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
#line 2259 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 268 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2268 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 272 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2277 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 276 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2285 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 279 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2293 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 282 "gramatica.y" /* yacc.c:1646  */
    { error_recovery_mode = 0; (yyval.node) = NULL; }
#line 2299 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 285 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2308 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 289 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2316 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 294 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_open");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2326 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 301 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_else");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2336 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 306 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("while");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2345 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 310 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2356 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 316 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for_iterator");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));

  if (!type_eq(&TYPE_EXPRESSION_INT, (yyvsp[-3].node)->type)) {
    char buffer[300] = {0};
    sprintf(buffer, "receiving var in for mut be of type int ");
    semantic_error(buffer);
  } 
}
#line 2372 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 329 "gramatica.y" /* yacc.c:1646  */
    { scope_push(NULL); }
#line 2378 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 329 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("block");
  push_child((yyval.node), (yyvsp[-1].node));
  scope_pop();
}
#line 2388 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 337 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("read");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2397 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 341 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("write");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2406 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 345 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2414 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 348 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2422 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 351 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2430 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 354 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("return");
  push_child((yyval.node), (yyvsp[-1].node));

  Scope* cur = scope_top();
  if (cur == NULL || cur->function == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "there is no function for this return statement");
    semantic_error(buffer);
  } else {
    check_assign_expression((yyval.node), cur->function->type, (yyvsp[-1].node));
  }
}
#line 2448 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 373 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_assign");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_assign_expression((yyval.node), (yyvsp[-2].node)->type, (yyvsp[0].node));

  if ((yyvsp[-2].node)->begin_child->value_type != LVALUE) {
    char buffer[300] = {0};
    sprintf(buffer, "left side on \"ASSIGN\" must be an lvalue");
    semantic_error(buffer);
  }
}
#line 2465 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 385 "gramatica.y" /* yacc.c:1646  */
    {  
  (yyval.node) = (yyvsp[0].node);
}
#line 2473 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 390 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_relational");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_compare_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2485 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 400 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_and");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_boolean_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2498 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 411 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_or");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_boolean_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2511 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 422 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_add");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2524 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 433 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_sub");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  
  free_tree((yyvsp[-1].node));
}
#line 2537 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 444 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_mul");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2550 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 455 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_div");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
  check_aritmetic_expression((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  free_tree((yyvsp[-1].node));
}
#line 2563 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 466 "gramatica.y" /* yacc.c:1646  */
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
#line 2592 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 493 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2600 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 504 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2606 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 509 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2612 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 510 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2618 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 512 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2624 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 513 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2630 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 514 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2636 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 515 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2642 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 517 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2648 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 518 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2654 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 519 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2660 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 520 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2666 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 521 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2672 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 522 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2678 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 529 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("adda"); 
  push_child((yyval.node), (yyvsp[-1].node));

  Node* params = get_params_addv();
  check_params(
    (yyval.node)->id,
    params ? params->begin_child : NULL, 
    (yyval.node) ? (yyval.node)->begin_child : NULL
  );
  free_tree(params);
}
#line 2695 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 541 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("addv"); 
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
#line 2714 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 557 "gramatica.y" /* yacc.c:1646  */
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
  SymbolNode *entry = stable_create_symbol((yyvsp[0].node)->complement, global_scope, STYPE_VARIABLE, type, (yyval.node));
  (yyval.node)->sentry = entry;
  (yyval.node)->type = type_cpy(type);
  symbol_table = stable_add(symbol_table, entry);
}
#line 2748 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 588 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2754 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 589 "gramatica.y" /* yacc.c:1646  */
    {
  // OBS: SE EM ALGUM MOMENTO MAIS DIMENSOES FOREM ADICIONADAS COLOCAR EM BEGIN/END CHILD
  (yyval.node) = create_node("dimension");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2764 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 596 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2773 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 600 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2782 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 604 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node_with_type("value", (yyvsp[0].node)->type);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2791 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 610 "gramatica.y" /* yacc.c:1646  */
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
  }
  (yyval.node)->sentry = match;
}
#line 2819 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 635 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2825 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 636 "gramatica.y" /* yacc.c:1646  */
    {
  // OBS: SE EM ALGUM MOMENTO MAIS DIMENSOES FOREM ADICIONADAS COLOCAR EM BEGIN/END CHILD
  (yyval.node) = create_node("access_lvl");
  push_child((yyval.node), (yyvsp[-2].node));

  if ((yyvsp[0].node)) {
    Node *it;
    for (it = (yyvsp[0].node)->begin_child; it != NULL; it = it->next) {
      push_child((yyval.node), it);
    }
    free_node((yyvsp[0].node));
  }
}
#line 2843 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 651 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]);
  
  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
}
#line 2855 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 660 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2861 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 661 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2867 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 662 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2873 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 663 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2879 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 664 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2885 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 670 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_int");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_INT);
}
#line 2898 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 680 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_float");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_FLOAT);
}
#line 2911 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 690 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  (yyval.node)->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("1") + 1);
  strcpy(cpy, "1");
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_INT);
}
#line 2924 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 698 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  (yyval.node)->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("0") + 1);
  strcpy(cpy, "0");
  (yyval.node)->complement = cpy;
  (yyval.node)->type = type_base(GTYPE_INT);
}
#line 2937 "gramatica.tab.c" /* yacc.c:1646  */
    break;


#line 2941 "gramatica.tab.c" /* yacc.c:1646  */
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
#line 708 "gramatica.y" /* yacc.c:1906  */


/*-------------------UTILS--------------------------------*/

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
    char buffer[300] = {0}, buffer1[300] = {0};
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

/**
 * Também usado para checar tipo em return statement.
 */
void check_assign_expression(Node *tgt, TypeExpression *tgt_type, Node *op2) {
  TypeExpression *tmax = type_max(tgt_type, op2->type);
  if (type_can_assign(tgt_type) && tmax) {
      op2->cast = type_get_cast(tgt_type, op2->type);  
      tgt->type = type_cpy(tgt_type);
  } else {
    char buffer[300] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, tgt_type, op2->type);
    sprintf(buffer, "%s with operator \"ASSIGN/RETURN\"", buffer1);
    semantic_error(buffer);
  }
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

void warning(char const *s) {
  printf("\033[01;33mwarning\033[0;0m: %s\n", s);
}

int main() {
  scope_push(NULL);
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
