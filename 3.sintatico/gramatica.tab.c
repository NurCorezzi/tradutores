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

extern char *yytext;
int yylex_destroy ( void );
void yyerror (char const *s);
int yylex();
int error_recovery_mode;

SymbolNode *symbol_table;
Node *ast;

/*-------------AST-------------------*/

void (*tree_prefix[150]) (void);
int i_prefix = 0;

Node* create_node(char const *id) {
  Node* node = (Node*)calloc(1, sizeof(Node));
  
  char* cpy = (char*)malloc(strlen(id) + 1);
  strcpy(cpy, id);
  node->id = cpy;
  
  return node;
}

void push_child(Node *root, Node *child) {
  if (child == NULL) {
    return;
  }

  if (root->beginChild == NULL) {
    root->beginChild = child;
    root->endChild = child;
  } else {
    root->endChild->next = child;
    root->endChild = child;
  }
}

void free_node(Node *node) {
  if (node->id != NULL) free(node->id);
  if (node->complement != NULL) free(node->complement);
  free(node);
}

void free_tree(Node *root) {
  if (root == NULL) return;

  Node *it = root->beginChild;
  while (it != NULL) {
    Node *next = it->next;
    free_tree(it);
    it = next;
  }
  free_node(root);
}

/*-----------------CONVERSION---------------------*/

GrammarType token_to_type(int token) {
  switch(token) {
    case BOOLEAN:  return GTYPE_BOOLEAN; 
    case INT:      return GTYPE_INT; 
    case FLOAT:    return GTYPE_FLOAT; 
    case GRAPH:    return GTYPE_GRAPH; 
    case VOID:     return GTYPE_VOID; 
    default:       return -1;
  }
}

char* stype_to_string(int type) {
  switch(type) {
    case STYPE_FUNCTION:  return "function";
    case STYPE_VARIABLE:  return "variable";
    default:              return "NONE";
  }
}

char* gtype_to_string(int type) {
  switch(type) {
    case GTYPE_BOOLEAN: return "boolean";
    case GTYPE_INT:     return "int";
    case GTYPE_FLOAT:   return "float";
    case GTYPE_GRAPH:   return "graph";
    case GTYPE_VOID:    return "void";
    default:            return "NONE";
  }
}

/*------------PRINT SYMBOL TABLE---------------*/

void stable_symbol_print(SymbolNode* entry, int isChild) {
  char default_format[] = "│%-20p-%-20s│%-15s│%-15s│%-15s│\n";
  char with_child_format[] = "│%-20p┌%-20s│%-15s│%-15s│%-15s│\n";
  char nth_child_format[] = "│%-20p├%-20s│%-15s│%-15s│%-15s│\n";
  char last_child_format[] = "│%-20p└%-20s│%-15s│%-15s│%-15s│\n";
  
  char *format = isChild ? nth_child_format : default_format;

  if (!isChild && entry->matches != NULL) format = with_child_format; 
  if (isChild && entry->matches == NULL) format = last_child_format;

  printf(format, 
    entry, 
    entry->id, 
    entry->scope, 
    stype_to_string(entry->stype), 
    gtype_to_string(entry->gtype)
  );
}

void stable_print(SymbolNode* table) {
  printf("│%-20s│%-20s│%-15s│%-15s│%-15s│\n", "ID", "ENTRY", "SCOPE", "STYPE", "GTYPE");

  SymbolNode *entry = table;
  while(entry) {
    stable_symbol_print(entry, 0);
    
    SymbolNode *match = entry->matches;
    while(match) {
      stable_symbol_print(match, 1);
      match = match->matches;
    }    
    
    entry = entry->next;
  }
}

/*-------------SYMBOL TABLE--------------*/


SymbolNode* stable_create_symbol(char *id, char *scope, SymbolType stype, GrammarType gtype, Node *ast_node) {
  SymbolNode* symbol = (SymbolNode*)calloc(1, sizeof(SymbolNode));
  char *cpy;

  cpy = (char*)malloc(strlen(id) + 1);
  strcpy(cpy, id);
  symbol->id = cpy;

  cpy = (char*)malloc(strlen(scope) + 1);
  strcpy(cpy, scope);
  symbol->scope = cpy;

  symbol->stype = stype;
  symbol->gtype = gtype;
  symbol->ast_node = ast_node;

  return symbol;
}

SymbolNode* stable_find(SymbolNode* entry, char *id) {
  if (entry == NULL) return NULL;
  if (strcmp(id, entry->id) == 0) return entry;
  else return stable_find(entry->next, id);
}

SymbolNode* stable_add(SymbolNode* table, SymbolNode* entry) {
  SymbolNode* lastSymbol = table;
  while(lastSymbol && lastSymbol->next != NULL) {
    lastSymbol = lastSymbol->next;
  }

  if (lastSymbol == NULL) {
    table = entry;
  } else {
    SymbolNode *match = stable_find(table, entry->id);
    while(match && match->matches != NULL) {
      match = match->matches;
    }

    if (match != NULL) {
      entry->matches = match->matches;
      match->matches = entry;
    } else {
      entry->next = lastSymbol->next;
      lastSymbol->next = entry;  
    }
  }

  return table;
}

void free_symbol_node(SymbolNode* node) {
  if (node->id) free(node->id);
  if (node->scope) free(node->scope);
  free(node);
}

void free_stable(SymbolNode* table) {
  SymbolNode *entry = table;
  SymbolNode *memo;

  while(entry) {    
    SymbolNode *match = entry->matches;
    while(match) {
      memo = match;
      match = match->matches;
      free_symbol_node(memo);
    }    

    memo = entry;    
    entry = entry->next;
    free_symbol_node(memo);
  }
}

/*------------PRINT TREE---------------*/

void print_l_end() {printf("└");}
void print_l_middle() {printf("├");}
void print_horizontal() {printf("─");}
void print_vertical() {printf("│");}
void print_space() {printf(" ");}

void print_node_prefix() {
  int i;
  for (i = 0; i < i_prefix; ++i) {
    (*tree_prefix[i])();
  }
}

void print_node_sufix(Node *node) {
  printf("%s", node->id);
  if (node->complement) printf(": %s", node->complement);
  printf("\n");
}

void print_node(Node *node, int isLast) {
  tree_prefix[i_prefix-1] = &print_space;
  if (isLast) {
    tree_prefix[i_prefix-3] = &print_l_end;
    tree_prefix[i_prefix-2] = &print_horizontal;
    print_node_prefix();
    print_node_sufix(node);
    tree_prefix[i_prefix-3] = &print_space;
    tree_prefix[i_prefix-2] = &print_space;
  } else {
    tree_prefix[i_prefix-3] = &print_l_middle;
    tree_prefix[i_prefix-2] = &print_horizontal;
    print_node_prefix();
    print_node_sufix(node);
    tree_prefix[i_prefix-3] = &print_vertical;
    tree_prefix[i_prefix-2] = &print_space;
  }  
}

void print_tree(Node *node, int isLast) {
  if (node == NULL) return;

  i_prefix += 3;
  print_node(node, isLast);  
  Node *it;

  for (it = node->beginChild; it != NULL; it = it->next) {
    print_tree(it, it == node->endChild);
  }
  i_prefix -= 3;
}


#line 335 "gramatica.tab.c" /* yacc.c:339  */

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

#line 369 "gramatica.tab.c" /* yacc.c:355  */

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
    RETURN = 277,
    AND = 278,
    OR = 279,
    LE = 280,
    GE = 281,
    LESS = 282,
    GREATER = 283,
    EQ = 284,
    NE = 285,
    NOT = 286,
    MUL = 287,
    DIV = 288,
    ADD = 289,
    SUB = 290,
    ASSIGN = 291,
    END = 292,
    OPEN_BRACE = 293,
    CLOSE_BRACE = 294,
    IT = 295,
    SEPARATOR = 296,
    OPEN_P = 297,
    CLOSE_P = 298,
    OPEN_BRACKET = 299,
    CLOSE_BRACKET = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 287 "gramatica.y" /* yacc.c:355  */

  int id;
  Node* node;

#line 432 "gramatica.tab.c" /* yacc.c:355  */
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

#line 463 "gramatica.tab.c" /* yacc.c:358  */

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
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   329,   329,   338,   339,   352,   362,   365,   366,   376,
     382,   391,   392,   402,   408,   409,   412,   424,   424,   438,
     442,   446,   449,   452,   455,   459,   464,   471,   476,   480,
     486,   493,   499,   500,   504,   508,   511,   514,   517,   527,
     532,   537,   543,   546,   552,   555,   561,   564,   570,   573,
     579,   582,   588,   591,   597,   600,   605,   608,   611,   612,
     619,   620,   621,   624,   625,   627,   628,   629,   630,   632,
     633,   634,   635,   636,   637,   644,   652,   652,   665,   679,
     680,   685,   689,   693,   699,   699,   706,   715,   716,   717,
     718,   719,   722,   722,   725,   734,   743,   744
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "BOOLEAN",
  "INT", "FLOAT", "GRAPH", "VOID", "TO", "TRUE", "FALSE", "ID", "C_FLOAT",
  "C_INT", "READ", "WRITE", "DFS", "BFS", "RETURN", "AND", "OR", "LE",
  "GE", "LESS", "GREATER", "EQ", "NE", "NOT", "MUL", "DIV", "ADD", "SUB",
  "ASSIGN", "END", "OPEN_BRACE", "CLOSE_BRACE", "IT", "SEPARATOR",
  "OPEN_P", "CLOSE_P", "OPEN_BRACKET", "CLOSE_BRACKET", "$accept", "init",
  "program", "function", "params", "function_call", "params_call",
  "graph_call", "graph_params_call", "statements", "statement",
  "statement_no_dangle", "dangling_if", "statement_prefix", "block",
  "statement_end", "expr_assign", "expr_relational", "expr_and", "expr_or",
  "expr_add", "expr_sub", "expr_mul", "expr_div", "expr_unary", "factor",
  "unary", "and", "or", "add", "sub", "mul", "div", "compare_op",
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
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -45

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -45,     6,    35,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,    -6,   -45,   -14,    85,   -12,   -45,    -5,    85,    11,
      15,    -6,   -45,   -45,   -45,   -45,    14,   -45,    47,   -45,
     -45,    25,    28,    29,   -45,   -45,   -45,    -6,    -1,    -1,
     -45,   -45,   -45,   -45,    -1,   -45,   -45,   -45,   179,   -45,
     -45,    39,    43,    82,    57,    59,    53,    66,    73,    55,
     -45,     5,   -45,   -45,    77,    79,    81,   -45,   -45,    33,
     -45,   -45,   -45,   -45,    -1,    85,    -1,    83,    74,    87,
      56,    88,    76,    80,   -45,   -45,   -45,    -1,   -45,   -45,
     -45,   -45,   -45,   -45,    -1,   -45,    -1,   -45,    -1,    -1,
      -1,   -45,    -1,   -45,    -1,   -45,   -45,   -45,    -1,    -1,
      -1,    84,    89,   -13,    86,   -45,    15,   -45,   -45,   -45,
      -1,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
      72,   -45,   116,    91,   143,    -1,     4,   -45,    91,    90,
      -1,   -45,    -1,   -45,   -45,   127,   179,   130,   100,    96,
      96,    97,   143,   -45,    94,   -45,   138,    -1,    -6,   -45,
     -45,   -45,   -45,   102,   114,   -45,    -1,   122,    -1,   121,
     -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     6,    88,    87,    89,    90,    91,
       4,     0,    86,     0,     7,     0,     9,    79,     0,     0,
       0,     0,     8,    17,     5,    94,     0,    78,     0,    80,
      23,     0,     0,     0,    96,    97,    95,     0,     0,     0,
      60,    65,    66,    31,     0,    59,    18,    22,     0,    32,
      21,     0,    40,    42,    44,    46,    48,    50,    52,    54,
      56,     0,    61,    62,     0,     0,    76,    58,    81,    84,
      82,    92,    93,    83,     0,     0,     0,     0,    84,     0,
      84,     0,     0,     0,    20,    19,    36,     0,    69,    70,
      71,    72,    73,    74,     0,    63,     0,    64,     0,     0,
       0,    67,     0,    68,     0,    55,    37,    35,     0,    11,
       0,     0,     0,    76,     0,    33,     0,    34,    38,    57,
       0,    39,    41,    43,    45,    47,    49,    51,    53,    77,
       0,    13,     0,    92,     0,     0,     0,    28,     0,     0,
       0,    10,     0,    85,    26,     0,     0,    21,     0,     0,
       0,     0,     0,    12,     0,    27,    19,     0,     0,    14,
      15,    30,    75,     0,     0,    29,     0,     0,     0,     0,
      16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,    16,   -45,
     115,   -45,   -43,    34,   148,   -44,   -36,    75,    95,    78,
      71,    99,    69,    68,   -45,   112,   -45,   -45,   -45,   119,
     123,   -45,   -45,   -45,   -45,   104,    -7,   -45,   -45,   146,
     -11,   182,   -45,   -19,   -45,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    15,    45,   130,   151,   159,    28,
     144,   145,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    96,    98,    62,
      63,   102,   104,    94,    64,    65,    66,    21,    67,    68,
      80,    17,    70,    71,    72,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    26,    79,    81,    85,    84,     3,    16,    82,    12,
      27,    22,    34,    35,    12,    36,    25,    69,    34,    35,
      12,    36,    25,   108,   149,   150,    78,   136,    14,    18,
      40,    19,    25,    41,    42,    -2,     4,    69,   111,    20,
     114,    44,     5,     6,     7,     8,     9,    44,    30,    23,
      31,   121,    32,    33,     5,     6,     7,     8,     9,    29,
      34,    35,    12,    36,    25,    37,    38,    74,   113,    39,
      75,    76,   129,   131,   132,   109,    86,   110,    40,    87,
      95,    41,    42,    97,   139,    23,    43,    41,   103,    44,
     147,   133,     5,     6,     7,     8,     9,   138,   109,   148,
     116,    42,   156,    84,   153,   101,   154,    88,    89,    90,
      91,    92,    93,   140,   106,   141,   107,   108,   116,   119,
     115,   163,   120,    69,   117,   118,   135,   134,   142,   137,
     167,   155,   169,   152,   -25,    69,   143,   157,   158,   162,
     161,    69,   -24,    46,    30,   165,    31,   164,    32,    33,
       5,     6,     7,     8,     9,   166,    34,    35,    12,    36,
      25,    37,    38,   168,   170,    39,   160,    24,   146,   122,
     125,   127,   128,   105,    40,    99,   124,    41,    42,   112,
     100,    23,    83,    77,    11,    44,     5,     6,     7,     8,
       9,   123,    34,    35,    12,    36,    25,    37,    38,   126,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
      40,     0,     0,    41,    42,     0,     0,    23,     0,     0,
       0,    44
};

static const yytype_int16 yycheck[] =
{
      11,    20,    38,    39,    48,    48,     0,    14,    44,    15,
      21,    18,    13,    14,    15,    16,    17,    28,    13,    14,
      15,    16,    17,    36,    20,    21,    37,    40,    42,    41,
      31,    43,    17,    34,    35,     0,     1,    48,    74,    44,
      76,    42,     7,     8,     9,    10,    11,    42,     1,    38,
       3,    87,     5,     6,     7,     8,     9,    10,    11,    45,
      13,    14,    15,    16,    17,    18,    19,    42,    75,    22,
      42,    42,   108,   109,   110,    42,    37,    44,    31,    36,
      23,    34,    35,    24,   120,    38,    39,    34,    33,    42,
     134,   110,     7,     8,     9,    10,    11,   116,    42,   135,
      44,    35,   146,   146,   140,    32,   142,    25,    26,    27,
      28,    29,    30,    41,    37,    43,    37,    36,    44,    43,
      37,   157,    42,   134,    37,    37,    37,    43,    12,    43,
     166,     4,   168,    43,     4,   146,    45,    37,    42,    45,
      43,   152,     4,    28,     1,    43,     3,   158,     5,     6,
       7,     8,     9,    10,    11,    41,    13,    14,    15,    16,
      17,    18,    19,    41,    43,    22,   150,    19,   134,    94,
      99,   102,   104,    61,    31,    56,    98,    34,    35,    75,
      57,    38,     3,    37,     2,    42,     7,     8,     9,    10,
      11,    96,    13,    14,    15,    16,    17,    18,    19,   100,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,    -1,    38,    -1,    -1,
      -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,     0,     1,     7,     8,     9,    10,    11,
      49,    87,    15,    86,    42,    50,    82,    87,    41,    43,
      44,    83,    82,    38,    60,    17,    89,    86,    55,    45,
       1,     3,     5,     6,    13,    14,    16,    18,    19,    22,
      31,    34,    35,    39,    42,    51,    56,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    75,    76,    80,    81,    82,    84,    85,    86,
      88,    89,    90,    91,    42,    42,    42,    85,    86,    62,
      86,    62,    62,     3,    58,    61,    37,    36,    25,    26,
      27,    28,    29,    30,    79,    23,    73,    24,    74,    75,
      76,    32,    77,    33,    78,    71,    37,    37,    36,    42,
      44,    62,    81,    82,    62,    37,    44,    37,    37,    43,
      42,    62,    63,    64,    65,    66,    67,    68,    69,    62,
      52,    62,    62,    89,    43,    37,    40,    43,    89,    62,
      41,    43,    12,    45,    56,    57,    59,    61,    62,    20,
      21,    53,    43,    62,    62,     4,    61,    37,    42,    54,
      54,    43,    45,    62,    86,    43,    41,    62,    41,    62,
      43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      51,    52,    52,    52,    53,    53,    54,    55,    55,    56,
      56,    56,    56,    56,    57,    57,    58,    59,    59,    59,
      59,    60,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    71,
      72,    72,    72,    73,    74,    75,    76,    77,    78,    79,
      79,    79,    79,    79,    79,    80,    81,    81,    82,    83,
      83,    84,    84,    84,    85,    85,    86,    87,    87,    87,
      87,    87,    88,    88,    89,    90,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     6,     1,     0,     3,     1,
       4,     0,     3,     1,     2,     2,     7,     0,     2,     2,
       2,     1,     1,     1,     2,     1,     5,     6,     4,     8,
       6,     3,     1,     3,     3,     2,     2,     2,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     3,     3,     0,
       3,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
          case 47: /* init  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1502 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 48: /* program  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1512 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 49: /* function  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1522 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 50: /* params  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1532 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 51: /* function_call  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1542 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 52: /* params_call  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1552 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 53: /* graph_call  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1562 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* graph_params_call  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1572 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* statements  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1582 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 56: /* statement  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1592 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 57: /* statement_no_dangle  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1602 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* dangling_if  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1612 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* statement_prefix  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1622 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 60: /* block  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1632 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* statement_end  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1642 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* expr_assign  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1652 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* expr_relational  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1662 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* expr_and  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1672 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 65: /* expr_or  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1682 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* expr_add  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1692 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* expr_sub  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1702 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* expr_mul  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1712 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 69: /* expr_div  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1722 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 70: /* expr_unary  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1732 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 71: /* factor  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1742 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 72: /* unary  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1752 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 73: /* and  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1762 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 74: /* or  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1772 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 75: /* add  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1782 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 76: /* sub  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1792 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 77: /* mul  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1802 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 78: /* div  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1812 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 79: /* compare_op  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1822 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 80: /* graph_add  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1832 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 81: /* declaration_or_assign  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1842 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 82: /* declaration  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1852 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 83: /* size_specifier  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1862 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 84: /* value  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1872 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 85: /* id_or_access  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1882 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 86: /* id  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1892 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 87: /* type  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1902 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 88: /* number  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1912 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 89: /* number_int  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1922 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 90: /* number_float  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1932 "gramatica.tab.c" /* yacc.c:1257  */
        break;

    case 91: /* boolean_const  */
#line 309 "gramatica.y" /* yacc.c:1257  */
      { 
  if (error_recovery_mode) {
    free_tree(((*yyvaluep).node));
  }
}
#line 1942 "gramatica.tab.c" /* yacc.c:1257  */
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
#line 329 "gramatica.y" /* yacc.c:1646  */
    {
  ast = (yyval.node) = (yyvsp[0].node);
}
#line 2232 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 338 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2238 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 339 "gramatica.y" /* yacc.c:1646  */
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
#line 2254 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 352 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("function");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-4].node));
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  SymbolNode *entry = stable_create_symbol((yyvsp[-4].node)->complement, "NONE", STYPE_FUNCTION, token_to_type((yyvsp[-5].node)->t_token), (yyval.node));
  symbol_table = stable_add(symbol_table, entry);
}
#line 2269 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 362 "gramatica.y" /* yacc.c:1646  */
    { error_recovery_mode = 0; (yyval.node) = NULL; }
#line 2275 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 365 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2281 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 366 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  
  Node *it;
  for (it = (yyvsp[-2].node)->beginChild; it != NULL; it = it->next) {
    push_child((yyval.node), it);
  }
  free_node((yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2296 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 376 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2305 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 382 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("function_call");
  push_child((yyval.node), (yyvsp[-3].node));
  if ((yyvsp[-1].node) != NULL) {
    push_child((yyval.node), (yyvsp[-1].node));
  }
}
#line 2317 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 391 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2323 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 392 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  
  Node *it;
  for (it = (yyvsp[-2].node)->beginChild; it != NULL; it = it->next) {
    push_child((yyval.node), it);
  }
  free_node((yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2338 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 402 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("params_call");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2347 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 408 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("dfs"); push_child((yyval.node), (yyvsp[0].node));}
#line 2353 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 409 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node("bfs"); push_child((yyval.node), (yyvsp[0].node));}
#line 2359 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 412 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("graph_params");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2370 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 424 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2376 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 424 "gramatica.y" /* yacc.c:1646  */
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
#line 2393 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 438 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2402 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 442 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2411 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 446 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2419 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 449 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2427 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 452 "gramatica.y" /* yacc.c:1646  */
    { error_recovery_mode = 0; (yyval.node) = NULL; }
#line 2433 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 455 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2442 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 459 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[0].node);
}
#line 2450 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 464 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_open");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2460 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 471 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("if_else");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2470 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 476 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("while");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2479 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 480 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2490 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 486 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("for_iterator");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2500 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 493 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("block");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2509 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 500 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("read");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2518 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 504 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("write");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2527 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 508 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2535 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 511 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2543 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 514 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2551 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 517 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("return");
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2560 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 527 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_assign");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2570 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 532 "gramatica.y" /* yacc.c:1646  */
    {  
  (yyval.node) = (yyvsp[0].node);
}
#line 2578 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 537 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_relational");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2589 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 546 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_and");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2600 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 555 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_or");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2611 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 564 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_add");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2622 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 573 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_sub");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2633 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 582 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_mul");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2644 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 591 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_div");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2655 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 600 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("expr_unary");
  push_child((yyval.node), (yyvsp[-1].node));
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2665 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 608 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2673 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 619 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2679 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 624 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2685 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 625 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2691 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 627 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2697 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 628 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2703 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 629 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2709 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 630 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2715 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 632 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2721 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 633 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2727 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 634 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2733 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 635 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2739 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 636 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2745 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 637 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); }
#line 2751 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 644 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("graph_add");
  push_child((yyval.node), (yyvsp[-5].node));
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2762 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 652 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("statements");

  // Divisao em declaracao e atribuicao
  Node* assign = create_node("assignment");
  push_child(assign, create_node((yyvsp[-2].node)->endChild->id));
  push_child(assign, (yyvsp[0].node));

  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), assign);
}
#line 2778 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 665 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("declaration");
  push_child((yyval.node), (yyvsp[-2].node));
  push_child((yyval.node), (yyvsp[0].node));

  if((yyvsp[-1].node) != NULL) {
    push_child((yyval.node), (yyvsp[-1].node));
  }

  SymbolNode *entry = stable_create_symbol((yyvsp[0].node)->complement, "NONE", STYPE_VARIABLE, token_to_type((yyvsp[-2].node)->t_token), (yyval.node));
  symbol_table = stable_add(symbol_table, entry);
}
#line 2795 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 679 "gramatica.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2801 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 680 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2809 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 685 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("value");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2818 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 689 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("value");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2827 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 693 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("value");
  push_child((yyval.node), (yyvsp[0].node));
}
#line 2836 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 699 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("access");
  push_child((yyval.node), (yyvsp[-3].node));
  push_child((yyval.node), (yyvsp[-1].node));
}
#line 2846 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 706 "gramatica.y" /* yacc.c:1646  */
    { 
  (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]);
  
  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
}
#line 2858 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 715 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2864 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 716 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2870 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 717 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2876 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 718 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2882 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 719 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2888 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 725 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_int");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
}
#line 2900 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 734 "gramatica.y" /* yacc.c:1646  */
    {
  (yyval.node) = create_node("c_float");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  (yyval.node)->complement = cpy;
}
#line 2912 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 743 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2918 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 744 "gramatica.y" /* yacc.c:1646  */
    { (yyval.node) = create_node(yytname[YYTRANSLATE(yylval.id)]); (yyval.node)->t_token = yylval.id; }
#line 2924 "gramatica.tab.c" /* yacc.c:1646  */
    break;


#line 2928 "gramatica.tab.c" /* yacc.c:1646  */
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
#line 747 "gramatica.y" /* yacc.c:1906  */


void yyerror (char const *s) {
  error_recovery_mode = 1;
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

int main() {
  yyparse();

  printf("\n>>>>>>>>>>AST<<<<<<<<<<<\n\n");
  print_tree(ast, 1);

  printf("\n>>>>>>>>>>SYMBOL TABLE<<<<<<<<<<<\n\n");
  stable_print(symbol_table);
  
  free_tree(ast);
  free_stable(symbol_table);
  yylex_destroy();
}
