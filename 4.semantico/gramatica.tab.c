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

#include "node.h"
#include "ast.c"
#include "stable.c"

extern char *yytext;
int yylex_destroy ( void );
void yyerror (char const *s);
int yylex();
int error_recovery_mode;


#line 85 "gramatica.tab.c" /* yacc.c:339  */

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

#line 119 "gramatica.tab.c" /* yacc.c:355  */

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
#line 37 "gramatica.y" /* yacc.c:355  */

  int id;
  Node* node;

#line 184 "gramatica.tab.c" /* yacc.c:355  */
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

#line 215 "gramatica.tab.c" /* yacc.c:358  */

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
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

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
       0,    79,    79,    88,    89,   102,   120,   123,   124,   134,
     140,   149,   150,   160,   166,   167,   170,   182,   182,   196,
     200,   204,   207,   210,   213,   217,   222,   229,   234,   238,
     244,   251,   257,   258,   262,   266,   269,   272,   275,   285,
     290,   295,   301,   304,   310,   313,   319,   322,   328,   331,
     337,   340,   346,   349,   355,   358,   363,   366,   369,   370,
     377,   378,   379,   382,   383,   385,   386,   387,   388,   390,
     391,   392,   393,   394,   395,   402,   406,   414,   422,   422,
     435,   450,   451,   456,   460,   464,   470,   470,   477,   486,
     487,   488,   489,   490,   493,   493,   496,   505,   514,   515
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
  "$accept", "init", "program", "function", "params", "function_call",
  "params_call", "graph_call", "graph_params_call", "statements",
  "statement", "statement_no_dangle", "dangling_if", "statement_prefix",
  "block", "statement_end", "expr_assign", "expr_relational", "expr_and",
  "expr_or", "expr_add", "expr_sub", "expr_mul", "expr_div", "expr_unary",
  "factor", "unary", "and", "or", "add", "sub", "mul", "div", "compare_op",
  "graph_add", "declaration_or_assign", "declaration", "size_specifier",
  "value", "id_or_access", "id", "type", "number", "number_int",
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

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -46,     5,    91,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -44,    16,    -7,   -46,    -5,   -46,   -10,   -46,   115,
     -30,   -46,   -44,   115,    11,    -7,   -46,   -46,   -46,   -46,
     151,   -46,     8,    20,    24,   -46,   -46,   -46,    -7,    46,
      25,    26,    46,   -46,   -46,   -46,   -46,    46,   -46,   -46,
     -46,   190,   -46,   -46,    34,    17,    89,    49,    52,    44,
      56,    47,    59,   -46,    71,   -46,   -46,    58,    64,    57,
     -46,   -46,    -1,   -46,   -46,   -46,   -46,    46,   115,    46,
      66,    61,    69,    12,    -7,    -7,    88,    85,    87,   -46,
     -46,   -46,    46,   -46,   -46,   -46,   -46,   -46,   -46,    46,
     -46,    46,   -46,    46,    46,    46,   -46,    46,   -46,    46,
     -46,   -46,   -46,    46,    46,    46,    90,    93,     2,    92,
     -46,    16,   -46,    94,    95,   -46,   -46,    46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,    22,   -46,   121,
      97,    13,    46,    27,   -46,    97,   -46,    46,    96,    46,
     -46,    46,   -46,   -46,   132,   190,   141,   107,   103,   103,
     105,   108,    13,   -46,   101,   -46,   149,    46,    -7,   -46,
     -46,   -46,    46,   -46,   118,   128,   127,   -46,    46,   -46,
     133,    46,   134,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     6,    90,    89,    91,    92,    93,
       4,    81,     0,     0,    96,     0,    88,     0,    82,     7,
       0,     9,    81,     0,     0,     0,     8,    17,     5,    80,
       0,    23,     0,     0,     0,    98,    99,    97,     0,     0,
       0,     0,     0,    60,    65,    66,    31,     0,    59,    18,
      22,     0,    32,    21,     0,    40,    42,    44,    46,    48,
      50,    52,    54,    56,     0,    61,    62,     0,     0,    78,
      58,    83,    86,    84,    94,    95,    85,     0,     0,     0,
       0,    86,     0,    86,     0,     0,     0,     0,     0,    20,
      19,    36,     0,    69,    70,    71,    72,    73,    74,     0,
      63,     0,    64,     0,     0,     0,    67,     0,    68,     0,
      55,    37,    35,     0,    11,     0,     0,     0,    78,     0,
      33,     0,    34,     0,     0,    38,    57,     0,    39,    41,
      43,    45,    47,    49,    51,    53,    79,     0,    13,     0,
      94,     0,     0,     0,    28,     0,    75,     0,     0,     0,
      10,     0,    87,    26,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    12,     0,    27,    19,     0,     0,    14,
      15,    30,     0,    77,     0,     0,     0,    29,     0,    76,
       0,     0,     0,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,    18,   -46,
     148,   -46,   -41,    39,   157,   -45,   -38,    83,    82,    86,
      81,   106,    79,   109,   -46,   126,   -46,   -46,   -46,   135,
     136,   -46,   -46,   -46,   -46,   124,   -12,   188,   -46,   177,
     -13,   214,   -46,    -9,   -46,   -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    20,    48,   137,   160,   169,    30,
     153,   154,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   101,   103,    65,
      66,   107,   109,    99,    67,    68,    69,    13,    70,    71,
      83,    22,    73,    74,    75,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    82,    12,    15,    86,     3,    90,    21,    16,    87,
      89,    26,    29,    23,    31,    24,    32,    72,    33,    34,
       5,     6,     7,     8,     9,    81,    35,    36,    16,    37,
      14,    38,    39,    14,    19,    40,    41,    42,    72,   116,
     113,   119,    18,   114,   143,   115,    43,   158,   159,    44,
      45,    27,    77,    27,   128,    92,   114,    47,   121,    35,
      36,    16,    37,    14,    78,   149,   118,   150,    79,    84,
      85,   123,   124,    91,   100,   136,   138,   139,   102,    43,
      44,   106,    44,    45,    35,    36,    16,    37,    14,   148,
      47,    -2,     4,    45,   108,   113,   156,   111,     5,     6,
       7,     8,     9,   112,   157,   120,   140,   121,   122,   161,
     166,   163,   145,   164,    89,    47,    93,    94,    95,    96,
      97,    98,     5,     6,     7,     8,     9,   125,    72,   174,
     126,   127,   142,   151,   176,   141,   165,   144,   147,   146,
     180,   162,    72,   182,   152,   -25,   167,   168,   173,    72,
     171,   172,    31,   -24,    32,   175,    33,    34,     5,     6,
       7,     8,     9,   177,    35,    36,    16,    37,    14,    38,
      39,   178,   179,    40,    41,    42,   181,   170,    49,   183,
     155,    28,   129,   130,    43,   132,   134,    44,    45,   131,
     110,    27,    46,    88,   104,    47,   105,     5,     6,     7,
       8,     9,   117,    35,    36,    16,    37,    14,    38,    39,
      25,   133,    40,    41,    42,    80,    11,     0,   135,     0,
       0,     0,     0,    43,     0,     0,    44,    45,     0,     0,
      27,     0,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      13,    39,    46,    12,    42,     0,    51,    19,    15,    47,
      51,    23,    25,    43,     1,    45,     3,    30,     5,     6,
       7,     8,     9,    10,    11,    38,    13,    14,    15,    16,
      17,    18,    19,    17,    44,    22,    23,    24,    51,    77,
      38,    79,    47,    44,    42,    46,    33,    20,    21,    36,
      37,    40,    44,    40,    92,    38,    44,    44,    46,    13,
      14,    15,    16,    17,    44,    43,    78,    45,    44,    44,
      44,    84,    85,    39,    25,   113,   114,   115,    26,    33,
      36,    34,    36,    37,    13,    14,    15,    16,    17,   127,
      44,     0,     1,    37,    35,    38,   141,    39,     7,     8,
       9,    10,    11,    39,   142,    39,   115,    46,    39,   147,
     155,   149,   121,   151,   155,    44,    27,    28,    29,    30,
      31,    32,     7,     8,     9,    10,    11,    39,   141,   167,
      45,    44,    39,    12,   172,    45,     4,    45,    43,    45,
     178,    45,   155,   181,    47,     4,    39,    44,    47,   162,
      45,    43,     1,     4,     3,   168,     5,     6,     7,     8,
       9,    10,    11,    45,    13,    14,    15,    16,    17,    18,
      19,    43,    45,    22,    23,    24,    43,   159,    30,    45,
     141,    24,    99,   101,    33,   104,   107,    36,    37,   103,
      64,    40,    41,     3,    59,    44,    60,     7,     8,     9,
      10,    11,    78,    13,    14,    15,    16,    17,    18,    19,
      22,   105,    22,    23,    24,    38,     2,    -1,   109,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      40,    -1,    -1,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     1,     7,     8,     9,    10,    11,
      51,    89,    46,    85,    17,    91,    15,    88,    47,    44,
      52,    84,    89,    43,    45,    85,    84,    40,    62,    88,
      57,     1,     3,     5,     6,    13,    14,    16,    18,    19,
      22,    23,    24,    33,    36,    37,    41,    44,    53,    58,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    77,    78,    82,    83,    84,
      86,    87,    88,    90,    91,    92,    93,    44,    44,    44,
      87,    88,    64,    88,    44,    44,    64,    64,     3,    60,
      63,    39,    38,    27,    28,    29,    30,    31,    32,    81,
      25,    75,    26,    76,    77,    78,    34,    79,    35,    80,
      73,    39,    39,    38,    44,    46,    64,    83,    84,    64,
      39,    46,    39,    88,    88,    39,    45,    44,    64,    65,
      66,    67,    68,    69,    70,    71,    64,    54,    64,    64,
      91,    45,    39,    42,    45,    91,    45,    43,    64,    43,
      45,    12,    47,    58,    59,    61,    63,    64,    20,    21,
      55,    64,    45,    64,    64,     4,    63,    39,    44,    56,
      56,    45,    43,    47,    64,    88,    64,    45,    43,    45,
      64,    43,    64,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    52,    52,
      53,    54,    54,    54,    55,    55,    56,    57,    57,    58,
      58,    58,    58,    58,    59,    59,    60,    61,    61,    61,
      61,    62,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      74,    74,    74,    75,    76,    77,    78,    79,    80,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    83,    83,
      84,    85,    85,    86,    86,    86,    87,    87,    88,    89,
      89,    89,    89,    89,    90,    90,    91,    92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     7,     1,     0,     3,     1,
       4,     0,     3,     1,     2,     2,     7,     0,     2,     2,
       2,     1,     1,     1,     2,     1,     5,     6,     4,     8,
       6,     3,     1,     3,     3,     2,     2,     2,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     8,     6,     1,     3,
       3,     0,     3,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1259 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 50: /* program  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1269 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 51: /* function  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1279 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 52: /* params  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1289 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 53: /* function_call  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1299 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* params_call  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1309 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* graph_call  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1319 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 56: /* graph_params_call  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1329 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 57: /* statements  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1339 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* statement  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1349 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* statement_no_dangle  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1359 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 60: /* dangling_if  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1369 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* statement_prefix  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1379 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* block  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1389 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* statement_end  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1399 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* expr_assign  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1409 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 65: /* expr_relational  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1419 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* expr_and  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1429 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* expr_or  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1439 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* expr_add  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1449 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 69: /* expr_sub  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1459 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 70: /* expr_mul  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1469 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 71: /* expr_div  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1479 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 72: /* expr_unary  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1489 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 73: /* factor  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1499 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 74: /* unary  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1509 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 75: /* and  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1519 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 76: /* or  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1529 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 77: /* add  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1539 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 78: /* sub  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1549 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 79: /* mul  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1559 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 80: /* div  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1569 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 81: /* compare_op  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1579 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 82: /* graph_add  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1589 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 83: /* declaration_or_assign  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1599 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 84: /* declaration  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1609 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 85: /* size_specifier  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1619 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 86: /* value  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1629 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 87: /* id_or_access  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1639 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 88: /* id  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1649 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 89: /* type  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1659 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 90: /* number  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1669 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 91: /* number_int  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1679 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 92: /* number_float  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1689 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 93: /* boolean_const  */
#line 59 "gramatica.y" /* yacc.c:1257  */
      { 
   if (((*yyvaluep).node) != NULL && strcmp(((*yyvaluep).node)->id, "program") != 0) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1699 "gramatica.tab.c" /* yacc.c:1257  */
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
#line 79 "gramatica.y" /* yacc.c:1646  */
    {
  ast = (yyval.node) = (yyvsp[0].node);
}
#line 1989 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1995 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("program");
  if ((yyvsp[-1].node) != NULL) {
    Node *it;
    for (it = (yyvsp[-1].node)->beginChild; it != NULL; it = it->next) {
      push_child((yyval.node), it);
    }
    free_node((yyvsp[-1].node));
  }
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2011 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("function");

  Node* decl = create_node("declaration");
  push_child(decl, (yyvsp[-6].node));
  if((yyvsp[-5].node) != NULL) {
    push_child(decl, (yyvsp[-5].node));
  }
  push_child(decl, (yyvsp[-4].node));

  push_child((yyval.node), decl);
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  SymbolNode *entry = stable_create_symbol((yyvsp[-4].node)->complement, "NONE", STYPE_FUNCTION, token_to_type((yyvsp[-6].node)->t_token), (yyval.node));
  (yyval.node)->sentry = entry;
  symbol_table = stable_add(symbol_table, entry);
}
#line 2034 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "gramatica.y" /* yacc.c:1646  */
    { error_recovery_mode = 0; (yyval.node) = NULL; }
#line 2040 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 123 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2046 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  
  Node *it;
  for (it = (yyvsp[-2].node)->beginChild; it != NULL; it = it->next) {
    push_child((yyval.node), it);
  }
  free_node((yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2061 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 134 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2070 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 140 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("function_call");
  push_child((yyval.node), (yyvsp[-3].node));
  if ((yyvsp[-1].node) != NULL) {
    push_child((yyval.node), (yyvsp[-1].node));
  }
}
#line 2082 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 149 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2088 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 150 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  
  Node *it;
  for (it = (yyvsp[-2].node)->beginChild; it != NULL; it = it->next) {
    push_child((yyval.node), it);
  }
  free_node((yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2103 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 160 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2112 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("dfs"); push_child((yyval.node), (yyvsp[0].node));}
#line 2118 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 167 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("bfs"); push_child((yyval.node), (yyvsp[0].node));}
#line 2124 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 170 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("graph_params");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2135 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 182 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2141 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 182 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("statements");

  if ((yyvsp[-1].node) != NULL) {
    Node *it;
    for (it = (yyvsp[-1].node)->beginChild; it != NULL; it = it->next) {
      push_child((yyval.node), it);
    }
    free_node((yyvsp[-1].node));
  }  
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2158 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 196 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2167 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 200 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2176 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 204 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2184 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 207 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2192 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 210 "gramatica.y" /* yacc.c:1646  */
    { error_recovery_mode = 0; (yyval.node) = NULL; }
#line 2198 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 213 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2207 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 217 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2215 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 222 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_open");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2225 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 229 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_else");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2235 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 234 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("while");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2244 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 238 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2255 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 244 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for_iterator");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2265 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 251 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("block");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2274 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 258 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("read");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2283 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 262 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("write");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2292 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 266 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2300 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 269 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2308 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 272 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2316 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 275 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("return");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2325 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 285 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_assign");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2335 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 290 "gramatica.y" /* yacc.c:1646  */
    {  
  (yyval.node) = (yyvsp[0].node);
}
#line 2343 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 295 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_relational");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2354 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 304 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_and");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2365 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 313 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_or");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2376 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 322 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_add");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2387 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 331 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_sub");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2398 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 340 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_mul");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2409 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 349 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_div");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2420 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 358 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_unary");
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2430 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 366 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2438 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 377 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2444 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 382 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2450 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 383 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2456 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 385 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2462 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 386 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2468 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 387 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2474 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 388 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2480 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 390 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2486 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 391 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2492 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 392 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2498 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 393 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2504 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 394 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2510 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 395 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2516 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 402 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("adda"); 
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2525 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 406 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node("addv"); 
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2536 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 414 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("graph_add");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2547 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 422 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("statements");

  // Divisao em declaracao e atribuicao
  Node* assign = create_node("assignment");
  push_child(assign, create_node((yyvsp[-2].node)->endChild->id));
  push_child(assign, (yyvsp[0].node));

  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), assign);
}
#line 2563 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 435 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("declaration");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  if((yyvsp[-1].node) != NULL) {
    push_child((yyval.node), (yyvsp[-1].node));
  }

  SymbolNode *entry = stable_create_symbol((yyvsp[0].node)->complement, "NONE", STYPE_VARIABLE, token_to_type((yyvsp[-2].node)->t_token), (yyval.node));
  (yyval.node)->sentry = entry;
  symbol_table = stable_add(symbol_table, entry);
}
#line 2581 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 450 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2587 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 451 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2595 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 456 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("value");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2604 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 460 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("value");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2613 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 464 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("value");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2622 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 470 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("access");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2632 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 477 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]);
  
  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
}
#line 2644 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 486 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2650 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 487 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2656 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 488 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2662 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 489 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2668 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 490 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2674 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 496 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_int");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
}
#line 2686 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 505 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_float");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
}
#line 2698 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 514 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2704 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 515 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2710 "gramatica.tab.c" /* yacc.c:1646  */
    break;


#line 2714 "gramatica.tab.c" /* yacc.c:1646  */
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
#line 518 "gramatica.y" /* yacc.c:1906  */


void yyerror (char const *s) {
  error_recovery_mode = 1;
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

int main() {
  yyparse();

  printf("%d\n", scope_count);

  printf("\n>>>>>>>>>>AST<<<<<<<<<<<\n\n");
  print_tree(ast, 1);

  printf("\n>>>>>>>>>>SYMBOL TABLE<<<<<<<<<<<\n\n");
  stable_print(symbol_table);
  
  free_tree(ast);
  free_stable(symbol_table);
  yylex_destroy();
}
