/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "src/parser/parser.y"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "../ast/ast.h" // Include AST class blueprints to safely hook up tree generation

using namespace std;
extern ASTNode* global_ast_root;

/* 1. FLEX & BISON CONNECTION */

/* Calls the lexical analyzer to retrieve the next token. */
extern int yylex();

/* Current line number maintained by lexer.l for accurate syntax error reporting. */
extern int current_line;

/* Stores the current token text scanned by the lexer. */
extern char *yytext;

/* Input file pointer used by the lexer. */
extern FILE *yyin;

int syntax_error_count = 0;

/* Syntax error handling function called automatically by Bison. */
void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error on Line %d: %s at token '%s'\n", current_line, s, yytext);
    syntax_error_count++;
    exit(1);
}




/* Line 189 of yacc.c  */
#line 109 "src/parser/parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HEADER_DIRECTIVE = 258,
     KEYWORD_INT = 259,
     KEYWORD_FLOAT = 260,
     KEYWORD_BOOL = 261,
     KEYWORD_VOID = 262,
     KEYWORD_IF = 263,
     KEYWORD_ELSE = 264,
     KEYWORD_WHILE = 265,
     KEYWORD_FOR = 266,
     KEYWORD_RETURN = 267,
     KEYWORD_PRINT = 268,
     KEYWORD_PRINTF = 269,
     KEYWORD_COUT = 270,
     KEYWORD_ENDL = 271,
     CONST_INT = 272,
     CONST_FLOAT = 273,
     CONST_BOOL_TRUE = 274,
     CONST_BOOL_FALSE = 275,
     STRING_LITERAL = 276,
     IDENTIFIER = 277,
     ASSIGN = 278,
     OP_EQ = 279,
     OP_NEQ = 280,
     OP_LEQ = 281,
     OP_GEQ = 282,
     OP_AND = 283,
     OP_OR = 284,
     STREAM_INSERTION = 285,
     SEMICOLON = 286,
     COMMA = 287,
     LBRACE = 288,
     RBRACE = 289,
     LPAREN = 290,
     RPAREN = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 38 "src/parser/parser.y"

    char* string_val;
    class ASTNode* node;



/* Line 214 of yacc.c  */
#line 188 "src/parser/parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 200 "src/parser/parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,    43,     2,     2,
       2,     2,    41,    39,     2,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,     2,    38,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    20,
      22,    24,    26,    28,    32,    34,    38,    42,    45,    47,
      49,    51,    53,    55,    59,    63,    67,    71,    75,    79,
      83,    87,    91,    95,    99,   103,   107,   111,   114,   116,
     121,   125,   129,   132,   136,   142,   150,   155,   162,   164,
     168,   171,   173,   175,   177,   179,   181,   183,   185,   187,
     190,   192,   195,   201,   209,   215,   217,   219,   220,   230,
     233,   235,   239,   246,   253,   259
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    48,    -1,    47,    48,    -1,
      49,    -1,    70,    -1,    50,    52,    31,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,    22,    -1,    22,    23,
      55,    -1,    51,    -1,    52,    32,    51,    -1,    50,    52,
      31,    -1,    50,    52,    -1,    17,    -1,    18,    -1,    22,
      -1,    19,    -1,    20,    -1,    35,    55,    36,    -1,    55,
      39,    55,    -1,    55,    40,    55,    -1,    55,    41,    55,
      -1,    55,    42,    55,    -1,    55,    43,    55,    -1,    55,
      24,    55,    -1,    55,    25,    55,    -1,    55,    26,    55,
      -1,    55,    27,    55,    -1,    55,    37,    55,    -1,    55,
      38,    55,    -1,    55,    28,    55,    -1,    55,    29,    55,
      -1,    44,    55,    -1,    21,    -1,    22,    23,    55,    31,
      -1,    22,    23,    55,    -1,    12,    55,    31,    -1,    12,
      31,    -1,    13,    55,    31,    -1,    13,    35,    55,    36,
      31,    -1,    14,    35,    21,    32,    55,    36,    31,    -1,
      15,    30,    55,    31,    -1,    15,    30,    55,    30,    16,
      31,    -1,    31,    -1,    33,    63,    34,    -1,    33,    34,
      -1,    53,    -1,    56,    -1,    58,    -1,    64,    -1,    65,
      -1,    67,    -1,    59,    -1,    60,    -1,     1,    31,    -1,
      62,    -1,    63,    62,    -1,     8,    35,    55,    36,    61,
      -1,     8,    35,    55,    36,    61,     9,    61,    -1,    10,
      35,    55,    36,    61,    -1,    54,    -1,    57,    -1,    -1,
      11,    35,    66,    31,    55,    31,    57,    36,    61,    -1,
      50,    22,    -1,    68,    -1,    69,    32,    68,    -1,    50,
      22,    35,    69,    36,    61,    -1,     7,    22,    35,    69,
      36,    61,    -1,    50,    22,    35,    36,    61,    -1,     7,
      22,    35,    36,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   133,   138,   147,   148,   149,   162,   171,
     172,   173,   177,   180,   192,   197,   205,   217,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   258,
     265,   272,   273,   278,   281,   284,   287,   290,   296,   300,
     301,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     319,   324,   335,   338,   345,   353,   354,   355,   359,   368,
     375,   380,   388,   397,   406,   409
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HEADER_DIRECTIVE", "KEYWORD_INT",
  "KEYWORD_FLOAT", "KEYWORD_BOOL", "KEYWORD_VOID", "KEYWORD_IF",
  "KEYWORD_ELSE", "KEYWORD_WHILE", "KEYWORD_FOR", "KEYWORD_RETURN",
  "KEYWORD_PRINT", "KEYWORD_PRINTF", "KEYWORD_COUT", "KEYWORD_ENDL",
  "CONST_INT", "CONST_FLOAT", "CONST_BOOL_TRUE", "CONST_BOOL_FALSE",
  "STRING_LITERAL", "IDENTIFIER", "ASSIGN", "OP_EQ", "OP_NEQ", "OP_LEQ",
  "OP_GEQ", "OP_AND", "OP_OR", "STREAM_INSERTION", "SEMICOLON", "COMMA",
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "$accept", "program", "declaration_list",
  "declaration", "header_directive", "type_specifier", "variable",
  "variable_list", "variable_declaration", "variable_declaration_inline",
  "expression", "assignment_statement", "assignment_expression",
  "return_statement", "output_statement", "empty_statement", "block",
  "statement", "statement_list", "if_statement", "while_statement",
  "for_initialization", "for_statement", "parameter", "parameter_list",
  "function", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    60,    62,    43,
      45,    42,    47,    37,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    50,
      50,    50,    51,    51,    52,    52,    53,    54,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      57,    58,    58,    59,    59,    59,    59,    59,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    65,    66,    66,    66,    67,    68,
      69,    69,    70,    70,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     2,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     4,
       3,     3,     2,     3,     5,     7,     4,     6,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     5,     7,     5,     1,     1,     0,     9,     2,
       1,     3,     6,     6,     5,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     9,    10,    11,     0,     0,     2,     3,     5,
       0,     6,     0,     1,     4,    12,    14,     0,     0,     0,
       0,     7,     0,     0,     0,    70,     0,    18,    19,    21,
      22,    38,    20,     0,     0,    13,     0,     0,    12,    15,
       0,    75,    69,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    50,     0,    51,    52,    53,    57,    58,    60,
       0,    54,    55,    56,    71,    73,    23,    29,    30,    31,
      32,    35,    36,    33,    34,    24,    25,    26,    27,    28,
      72,    59,     0,     0,    67,    42,     0,     0,     0,     0,
       0,     0,     0,    49,    61,     0,     0,     0,     0,    65,
      66,     0,    41,     0,    43,     0,     0,     0,    16,     0,
       0,     0,    17,     0,    23,     0,     0,    46,    39,    62,
      64,    40,     0,    44,     0,     0,     0,     0,     0,    47,
      63,     0,    45,     0,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    24,    16,    17,    74,   119,
      35,    75,   120,    76,    77,    78,    41,    79,    80,    81,
      82,   121,    83,    25,    26,    11
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
      47,   -73,   -73,   -73,   -73,     4,    24,    47,   -73,   -73,
      19,   -73,     9,   -73,   -73,   -13,   -73,   -25,     7,   139,
      13,   -73,    23,    22,    40,   -73,   -16,   -73,   -73,   -73,
     -73,   -73,   -73,   139,   139,   361,    22,    -9,    41,   -73,
      55,   -73,   -73,    74,    22,   181,   -73,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     -73,    22,    45,    46,    50,    52,   120,   149,    63,    60,
      76,   -73,   -73,    23,   -73,   -73,   -73,   -73,   -73,   -73,
     114,   -73,   -73,   -73,   -73,   -73,   -73,   395,   395,    32,
      32,   388,   368,    32,    32,    54,    54,   -73,   -73,   -73,
     -73,   -73,   139,   139,    -1,   -73,   201,   139,   221,    79,
     139,   139,    26,   -73,   -73,   241,   261,    78,    23,   -73,
     -73,    71,   -73,   281,   -73,    72,   161,   301,   -73,    22,
      22,   139,    73,   139,    77,   139,    87,   -73,   -73,    98,
     -73,   361,   321,   -73,   341,    80,    22,    91,    90,   -73,
     -73,    94,   -73,    22,   -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,   102,   -73,     2,   101,   -72,   -73,   -73,
     -19,   -73,   -15,   -73,   -73,   -73,   -36,    51,   -73,   -73,
     -73,   -73,   -73,    92,   113,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,   112,    10,     2,     3,     4,    21,    22,    85,    10,
      19,     2,     3,     4,    45,    46,    43,     2,     3,     4,
      44,   117,    20,    43,    13,   100,    12,    61,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    15,    73,    23,    18,    38,   132,   106,   108,    36,
       1,     2,     3,     4,     5,    40,    62,   128,    22,     2,
       3,     4,    42,    63,    19,    64,    65,    66,    67,    68,
      69,    55,    56,    57,    58,    59,   101,    70,     2,     3,
       4,   102,    73,   115,   116,   103,    71,   104,   123,    72,
     110,   126,   127,   139,   140,    57,    58,    59,   109,   111,
     125,   131,   133,   145,   135,    22,   118,   146,   143,    14,
     150,   149,   141,   117,   142,    62,   144,   154,     2,     3,
       4,   152,    63,    39,    64,    65,    66,    67,    68,    69,
     153,   114,   151,    37,     0,    84,    70,    27,    28,    29,
      30,    31,    32,     0,     0,    71,     0,     0,   113,     0,
       0,   105,     0,     0,     0,    33,    27,    28,    29,    30,
      31,    32,     0,     0,    34,     0,    27,    28,    29,    30,
      31,    32,     0,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,    34,   107,    47,    48,    49,    50,    51,
      52,   136,   137,    34,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,    86,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,   122,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,   124,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,   129,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,   130,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,   134,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,   138,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,   147,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,   148,    53,    54,
      55,    56,    57,    58,    59,    47,    48,    49,    50,    51,
      52,     0,    47,    48,    49,    50,    51,     0,    53,    54,
      55,    56,    57,    58,    59,    53,    54,    55,    56,    57,
      58,    59,    47,    48,    49,    50,     0,     0,     0,     0,
       0,    49,    50,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    53,    54,    55,    56,    57,    58,    59
};

static const yytype_int16 yycheck[] =
{
      36,    73,     0,     4,     5,     6,    31,    32,    44,     7,
      23,     4,     5,     6,    33,    34,    32,     4,     5,     6,
      36,    22,    35,    32,     0,    61,    22,    36,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    22,    40,    36,    35,    22,   118,    66,    67,    36,
       3,     4,     5,     6,     7,    33,     1,    31,    32,     4,
       5,     6,    22,     8,    23,    10,    11,    12,    13,    14,
      15,    39,    40,    41,    42,    43,    31,    22,     4,     5,
       6,    35,    80,   102,   103,    35,    31,    35,   107,    34,
      30,   110,   111,   129,   130,    41,    42,    43,    35,    23,
      21,    23,    31,    16,    32,    32,   104,     9,    31,     7,
     146,    31,   131,    22,   133,     1,   135,   153,     4,     5,
       6,    31,     8,    22,    10,    11,    12,    13,    14,    15,
      36,    80,   147,    20,    -1,    43,    22,    17,    18,    19,
      20,    21,    22,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    31,    -1,    -1,    -1,    35,    17,    18,    19,    20,
      21,    22,    -1,    -1,    44,    -1,    17,    18,    19,    20,
      21,    22,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    35,    24,    25,    26,    27,    28,
      29,    30,    31,    44,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    24,    25,    26,    27,    28,
      29,    -1,    24,    25,    26,    27,    28,    -1,    37,    38,
      39,    40,    41,    42,    43,    37,    38,    39,    40,    41,
      42,    43,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    37,    38,    39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    46,    47,    48,    49,
      50,    70,    22,     0,    48,    22,    51,    52,    35,    23,
      35,    31,    32,    36,    50,    68,    69,    17,    18,    19,
      20,    21,    22,    35,    44,    55,    36,    69,    22,    51,
      33,    61,    22,    32,    36,    55,    55,    24,    25,    26,
      27,    28,    29,    37,    38,    39,    40,    41,    42,    43,
      61,    36,     1,     8,    10,    11,    12,    13,    14,    15,
      22,    31,    34,    50,    53,    56,    58,    59,    60,    62,
      63,    64,    65,    67,    68,    61,    36,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      61,    31,    35,    35,    35,    31,    55,    35,    55,    35,
      30,    23,    52,    34,    62,    55,    55,    22,    50,    54,
      57,    66,    31,    55,    31,    21,    55,    55,    31,    36,
      36,    23,    52,    31,    36,    32,    30,    31,    31,    61,
      61,    55,    55,    31,    55,    16,     9,    31,    36,    31,
      61,    57,    31,    36,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 124 "src/parser/parser.y"
    { 
        (yyval.node) = (yyvsp[(1) - (1)].node); 
        global_ast_root = (yyval.node); // Catch the finished program compilation tree at the root element
    ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 133 "src/parser/parser.y"
    { 
        ProgramNode* prog = new ProgramNode(); 
        if ((yyvsp[(1) - (1)].node)) prog->declarations.push_back((yyvsp[(1) - (1)].node)); 
        (yyval.node) = prog; // Instantiate root tree vector storage for the first layout element
    ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 138 "src/parser/parser.y"
    { 
        ProgramNode* prog = (ProgramNode*)(yyvsp[(1) - (2)].node); 
        if ((yyvsp[(2) - (2)].node)) prog->declarations.push_back((yyvsp[(2) - (2)].node)); 
        (yyval.node) = prog; // Append sub-nodes sequentially into the root program vector list
    ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 147 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 148 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 149 "src/parser/parser.y"
    { 
        VariableDeclNode* decl = new VariableDeclNode((yyvsp[(1) - (3)].string_val));
        vector<ASTNode*>* list = (vector<ASTNode*>*)(yyvsp[(2) - (3)].node);
        if (list) {
            decl->variables = *list;
            delete list;
        }
        (yyval.node) = decl;
    ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 162 "src/parser/parser.y"
    { 
        (yyval.node) = new HeaderNode((yyvsp[(1) - (1)].string_val)); // Allocate a new HeaderNode object with its raw text content
    ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 171 "src/parser/parser.y"
    { (yyval.string_val) = (yyvsp[(1) - (1)].string_val); ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 172 "src/parser/parser.y"
    { (yyval.string_val) = (yyvsp[(1) - (1)].string_val); ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 173 "src/parser/parser.y"
    { (yyval.string_val) = (yyvsp[(1) - (1)].string_val); ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 177 "src/parser/parser.y"
    { 
        (yyval.node) = new VariableNode((yyvsp[(1) - (1)].string_val)); // Single unit structural variable instance allocation
    ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 180 "src/parser/parser.y"
    { 
        (yyval.node) = new AssignNode((yyvsp[(1) - (3)].string_val), (yyvsp[(3) - (3)].node)); // Directly translate inline tracking initialization expressions
    ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 192 "src/parser/parser.y"
    { 
        vector<ASTNode*>* list = new vector<ASTNode*>();
        if ((yyvsp[(1) - (1)].node)) list->push_back((yyvsp[(1) - (1)].node));
        (yyval.node) = (ASTNode*)list; // Bundle standard vector configuration as a stack pass payload
    ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 197 "src/parser/parser.y"
    { 
        vector<ASTNode*>* list = (vector<ASTNode*>*)(yyvsp[(1) - (3)].node);
        if ((yyvsp[(3) - (3)].node)) list->push_back((yyvsp[(3) - (3)].node));
        (yyval.node) = (ASTNode*)list; // Append additional inline variables to the existing allocation list
    ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 205 "src/parser/parser.y"
    { 
        VariableDeclNode* decl = new VariableDeclNode((yyvsp[(1) - (3)].string_val));
        vector<ASTNode*>* list = (vector<ASTNode*>*)(yyvsp[(2) - (3)].node);
        if (list) {
            decl->variables = *list;
            delete list;
        }
        (yyval.node) = decl; 
    ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 217 "src/parser/parser.y"
    { 
        VariableDeclNode* decl = new VariableDeclNode((yyvsp[(1) - (2)].string_val));
        vector<ASTNode*>* list = (vector<ASTNode*>*)(yyvsp[(2) - (2)].node);
        if (list) {
            decl->variables = *list;
            delete list;
        }
        (yyval.node) = decl; // Process inline declarations identically without trailing semicolons
    ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 233 "src/parser/parser.y"
    { (yyval.node) = new ConstantNode((yyvsp[(1) - (1)].string_val), "INT"); ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 234 "src/parser/parser.y"
    { (yyval.node) = new ConstantNode((yyvsp[(1) - (1)].string_val), "FLOAT"); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 235 "src/parser/parser.y"
    { (yyval.node) = new VariableNode((yyvsp[(1) - (1)].string_val)); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 236 "src/parser/parser.y"
    { (yyval.node) = new ConstantNode((yyvsp[(1) - (1)].string_val), "BOOL"); ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 237 "src/parser/parser.y"
    { (yyval.node) = new ConstantNode((yyvsp[(1) - (1)].string_val), "BOOL"); ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 238 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 239 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("+", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 240 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("-", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 241 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("*", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 242 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("/", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 243 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("%", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 244 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("==", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 245 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("!=", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 246 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("<=", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 247 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode(">=", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 248 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("<", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 249 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode(">", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 250 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("&&", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 251 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("||", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 252 "src/parser/parser.y"
    { (yyval.node) = new BinaryOpNode("!", (yyvsp[(2) - (2)].node), nullptr); ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 253 "src/parser/parser.y"
    { (yyval.node) = new ConstantNode((yyvsp[(1) - (1)].string_val), "STRING"); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 258 "src/parser/parser.y"
    { 
        (yyval.node) = new AssignNode((yyvsp[(1) - (4)].string_val), (yyvsp[(3) - (4)].node)); // Allocate dynamic AssignNode values safely
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 265 "src/parser/parser.y"
    { 
        (yyval.node) = new AssignNode((yyvsp[(1) - (3)].string_val), (yyvsp[(3) - (3)].node)); // Instantiate explicit standard control flow updates without semicolon checks
    ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 272 "src/parser/parser.y"
    { (yyval.node) = new ReturnNode((yyvsp[(2) - (3)].node)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 273 "src/parser/parser.y"
    { (yyval.node) = new ReturnNode(nullptr); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 278 "src/parser/parser.y"
    { 
        (yyval.node) = new PrintNode("PRINT", (yyvsp[(2) - (3)].node));
    ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 281 "src/parser/parser.y"
    { 
        (yyval.node) = new PrintNode("PRINT", (yyvsp[(3) - (5)].node)); 
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 284 "src/parser/parser.y"
    { 
        (yyval.node) = new PrintNode("PRINTF", (yyvsp[(5) - (7)].node), (yyvsp[(3) - (7)].string_val)); 
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 287 "src/parser/parser.y"
    { 
        (yyval.node) = new PrintNode("COUT", (yyvsp[(3) - (4)].node)); 
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 290 "src/parser/parser.y"
    { 
        (yyval.node) = new PrintNode("COUT", (yyvsp[(3) - (6)].node)); // <--- Add this line to match "cout << sum << endl;"
    ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 296 "src/parser/parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 300 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 301 "src/parser/parser.y"
    { (yyval.node) = new BlockNode(); ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 307 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 308 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 309 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 310 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 311 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 312 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 313 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 314 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 315 "src/parser/parser.y"
    { yyerrok; (yyval.node) = nullptr; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 319 "src/parser/parser.y"
    { 
        BlockNode* blk = new BlockNode();
        if ((yyvsp[(1) - (1)].node)) blk->statements.push_back((yyvsp[(1) - (1)].node));
        (yyval.node) = blk; // Initialize a scoped block node array layout to hold runtime rules
    ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 324 "src/parser/parser.y"
    { 
        BlockNode* blk = (BlockNode*)(yyvsp[(1) - (2)].node);
        if ((yyvsp[(2) - (2)].node)) blk->statements.push_back((yyvsp[(2) - (2)].node));
        (yyval.node) = blk; // Accumulate execution sequences into the active block sequence list
    ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 335 "src/parser/parser.y"
    { 
        (yyval.node) = new IfNode((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), nullptr); // Singular condition verification without alternative path execution
    ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 338 "src/parser/parser.y"
    { 
        (yyval.node) = new IfNode((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); // Complete binary branch target construction
    ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 345 "src/parser/parser.y"
    { 
        (yyval.node) = new WhileNode((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); 
    ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 353 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 354 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 355 "src/parser/parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 359 "src/parser/parser.y"
    { 
        (yyval.node) = new ForNode((yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node)); // Assemble all four components into a standard structured loop node
    ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 368 "src/parser/parser.y"
    { 
        (yyval.node) = new ParameterNode((yyvsp[(1) - (2)].string_val), (yyvsp[(2) - (2)].string_val)); 
    ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 375 "src/parser/parser.y"
    { 
        vector<ASTNode*>* list = new vector<ASTNode*>();
        if ((yyvsp[(1) - (1)].node)) list->push_back((yyvsp[(1) - (1)].node));
        (yyval.node) = (ASTNode*)list; // Handle list compilation payloads seamlessly
    ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 380 "src/parser/parser.y"
    { 
        vector<ASTNode*>* list = (vector<ASTNode*>*)(yyvsp[(1) - (3)].node);
        if ((yyvsp[(3) - (3)].node)) list->push_back((yyvsp[(3) - (3)].node));
        (yyval.node) = (ASTNode*)list; // Append consecutive function variables safely
    ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 388 "src/parser/parser.y"
    { 
        FunctionNode* func = new FunctionNode((yyvsp[(1) - (6)].string_val), (yyvsp[(2) - (6)].string_val), (yyvsp[(6) - (6)].node));
        vector<ASTNode*>* list = (vector<ASTNode*>*)(yyvsp[(4) - (6)].node);
        if (list) {
            func->parameters = *list;
            delete list;
        }
        (yyval.node) = func; 
    ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 397 "src/parser/parser.y"
    { 
        FunctionNode* func = new FunctionNode((char*)"void", (yyvsp[(2) - (6)].string_val), (yyvsp[(6) - (6)].node));
        vector<ASTNode*>* list = (vector<ASTNode*>*)(yyvsp[(4) - (6)].node);
        if (list) {
            func->parameters = *list;
            delete list;
        }
        (yyval.node) = func; 
    ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 406 "src/parser/parser.y"
    { 
        (yyval.node) = new FunctionNode((yyvsp[(1) - (5)].string_val), (yyvsp[(2) - (5)].string_val), (yyvsp[(5) - (5)].node)); 
    ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 409 "src/parser/parser.y"
    { 
        (yyval.node) = new FunctionNode((char*)"void", (yyvsp[(2) - (5)].string_val), (yyvsp[(5) - (5)].node)); 
    ;}
    break;



/* Line 1464 of yacc.c  */
#line 2224 "src/parser/parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



