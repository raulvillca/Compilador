
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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
#line 1 "sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include "y.tab.h"
#include "polaca.h"
#include "tabla_simbolos.h"

extern YYSTYPE yylval;

int yystopparser=0;
FILE *yyin;
FILE *yyout;
char *yyltext;
char *yytext;
extern linea;
extern errMsg;

char tipoDato[31];
char valorDato[31];
char nombreDato[31];
char tipoDatoCons[31];
char opComparador[31];
char opCondicional[31];

typedef struct Dec {
	char nombreDato[31];
} Dec;
Dec pilaDec[200];

int ult, i, encontrado, contadorBetween = 0;

typedef struct Between {
	char result[31];
	char id[31];
	char min[31];
	char max[31];
} Between;

Between bt;

char p_result[31] = "aux", p_id[31] = "aux_id", p_inf[31] = "", p_sup[31] = "", aux[31] = "";



/* Line 189 of yacc.c  */
#line 125 "y.tab.c"

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
     ID = 258,
     OP_SUM = 259,
     OP_RES = 260,
     OP_MULT = 261,
     OP_DIV = 262,
     AND = 263,
     OR = 264,
     COR_A = 265,
     COR_C = 266,
     PAR_A = 267,
     PAR_C = 268,
     LLA_A = 269,
     LLA_C = 270,
     PUNTO_COMA = 271,
     COMA = 272,
     DOS_P = 273,
     OP_ASIG = 274,
     OP_ACUMULADOR = 275,
     OP_LOG_AND = 276,
     OP_LOG_OR = 277,
     I_WHILE = 278,
     I_END = 279,
     I_IF = 280,
     I_ELSE = 281,
     C_FLOTANTE = 282,
     C_CADENA = 283,
     C_ENTERO = 284,
     P_WRITE = 285,
     P_READ = 286,
     P_DECVAR = 287,
     P_ENDDEC = 288,
     P_DEFVAR = 289,
     P_ENDDEF = 290,
     P_INLIST = 291,
     P_BETWEEN = 292,
     OP_CMP_mI = 293,
     OP_CMP_MI = 294,
     OP_CMP_m = 295,
     OP_CMP_M = 296,
     OP_CMP_IGUAL = 297,
     T_ENTERO = 298,
     T_FLOTANTE = 299,
     T_STRING = 300
   };
#endif
/* Tokens.  */
#define ID 258
#define OP_SUM 259
#define OP_RES 260
#define OP_MULT 261
#define OP_DIV 262
#define AND 263
#define OR 264
#define COR_A 265
#define COR_C 266
#define PAR_A 267
#define PAR_C 268
#define LLA_A 269
#define LLA_C 270
#define PUNTO_COMA 271
#define COMA 272
#define DOS_P 273
#define OP_ASIG 274
#define OP_ACUMULADOR 275
#define OP_LOG_AND 276
#define OP_LOG_OR 277
#define I_WHILE 278
#define I_END 279
#define I_IF 280
#define I_ELSE 281
#define C_FLOTANTE 282
#define C_CADENA 283
#define C_ENTERO 284
#define P_WRITE 285
#define P_READ 286
#define P_DECVAR 287
#define P_ENDDEC 288
#define P_DEFVAR 289
#define P_ENDDEF 290
#define P_INLIST 291
#define P_BETWEEN 292
#define OP_CMP_mI 293
#define OP_CMP_MI 294
#define OP_CMP_m 295
#define OP_CMP_M 296
#define OP_CMP_IGUAL 297
#define T_ENTERO 298
#define T_FLOTANTE 299
#define T_STRING 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 51 "sintactico.y"

	int intVal;
	float floatVal;
	char *txtPtr;



/* Line 214 of yacc.c  */
#line 259 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 271 "y.tab.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  112

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    16,    18,    20,    22,
      24,    26,    28,    30,    34,    38,    43,    45,    49,    51,
      53,    55,    59,    61,    67,    73,    83,    85,    96,   105,
     108,   111,   114,   116,   118,   120,   122,   124,   128,   132,
     134,   138,   140,   142,   144,   146,   148,   150,   152,   154,
     158,   160,   162,   164,   168,   170,   172,   174,   176,   178,
     180
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    47,    48,    -1,    32,    49,
      33,    -1,    34,    50,    35,    -1,    53,    -1,    55,    -1,
      56,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,
      51,    18,    52,    -1,    51,    18,    52,    -1,    50,    51,
      18,    52,    -1,     3,    -1,    51,    17,     3,    -1,    43,
      -1,    45,    -1,    44,    -1,    54,    19,    71,    -1,     3,
      -1,    23,    68,    14,    47,    15,    -1,    25,    68,    14,
      47,    15,    -1,    25,    68,    14,    47,    15,    57,    14,
      47,    15,    -1,    26,    -1,    37,    12,    65,    17,    10,
      62,    17,    63,    11,    13,    -1,    36,    12,    64,    17,
      10,    66,    11,    13,    -1,    30,    28,    -1,    30,     3,
      -1,    31,     3,    -1,    71,    -1,    71,    -1,     3,    -1,
       3,    -1,    71,    -1,    66,    16,    71,    -1,    71,    70,
      71,    -1,    67,    -1,    67,    69,    67,    -1,    21,    -1,
      22,    -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,
      42,    -1,    73,    -1,    71,    72,    73,    -1,     4,    -1,
       5,    -1,    75,    -1,    73,    74,    75,    -1,     6,    -1,
       7,    -1,     3,    -1,    29,    -1,    27,    -1,    28,    -1,
      12,    71,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    78,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    92,    98,   102,   108,   114,   120,   124,
     128,   134,   140,   142,   149,   157,   164,   177,   186,   189,
     194,   201,   210,   219,   231,   243,   254,   270,   289,   298,
     303,   314,   320,   329,   330,   331,   332,   333,   339,   342,
     347,   348,   350,   351,   356,   357,   360,   364,   368,   372,
     376
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "OP_SUM", "OP_RES", "OP_MULT",
  "OP_DIV", "AND", "OR", "COR_A", "COR_C", "PAR_A", "PAR_C", "LLA_A",
  "LLA_C", "PUNTO_COMA", "COMA", "DOS_P", "OP_ASIG", "OP_ACUMULADOR",
  "OP_LOG_AND", "OP_LOG_OR", "I_WHILE", "I_END", "I_IF", "I_ELSE",
  "C_FLOTANTE", "C_CADENA", "C_ENTERO", "P_WRITE", "P_READ", "P_DECVAR",
  "P_ENDDEC", "P_DEFVAR", "P_ENDDEF", "P_INLIST", "P_BETWEEN", "OP_CMP_mI",
  "OP_CMP_MI", "OP_CMP_m", "OP_CMP_M", "OP_CMP_IGUAL", "T_ENTERO",
  "T_FLOTANTE", "T_STRING", "$accept", "programa", "sentencia",
  "dec_declaracion", "def_declaracion", "declaracion", "tipo_dato",
  "asignacion", "id", "iterador", "condicional", "else", "b_between",
  "b_inList", "b_write", "b_read", "inferior", "superior", "param_inList",
  "param_between", "lista", "comparador", "condicion", "op_log", "cmp",
  "expresion", "op_sum_res", "termino", "op_mult_div", "factor", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    50,    50,    51,    51,    52,    52,
      52,    53,    54,    55,    56,    56,    57,    58,    59,    60,
      60,    61,    62,    63,    64,    65,    66,    66,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     1,     3,     1,     1,
       1,     3,     1,     5,     5,     9,     1,    10,     8,     2,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     6,     0,     7,     8,     9,    10,    11,    12,
      56,     0,    58,    59,    57,    39,     0,     0,    48,    52,
       0,    30,    29,    31,    16,     0,     0,     0,     0,     0,
       0,     1,     3,     0,     0,    41,    42,     0,     0,    50,
      51,    43,    44,    45,    46,    47,     0,     0,    54,    55,
       0,     0,     4,     0,     0,     5,     0,     0,    34,     0,
      35,     0,    21,    60,    40,     0,    38,    49,    53,     0,
      17,    18,    20,    19,    13,     0,    14,     0,     0,    23,
      24,    15,     0,     0,    26,     0,     0,    36,     0,    32,
       0,     0,     0,     0,     0,    28,    37,     0,    33,    25,
       0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    35,    37,    36,    84,    12,    13,    14,
      15,    95,    16,    17,    18,    19,    98,   107,    69,    71,
      96,    25,    26,    47,    56,    27,    57,    28,    60,    29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const yytype_int8 yypact[] =
{
     111,   -62,     4,     4,     6,     7,     9,     9,     2,    18,
      19,   -62,   -62,    33,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,     4,   -62,   -62,   -62,    24,    11,    -1,    14,   -62,
      43,   -62,   -62,   -62,   -62,    34,    30,     8,    42,    63,
      65,   -62,   -62,     4,    13,   -62,   -62,     4,   111,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,     4,     4,   -62,   -62,
       4,   111,   -62,    68,   -16,   -62,    44,   -16,   -62,    57,
     -62,    58,    59,   -62,   -62,    55,    59,    14,   -62,    73,
     -62,   -62,   -62,   -62,   -62,   -16,   -62,    67,    69,   -62,
      64,   -62,     4,     4,   -62,    70,    -3,    59,    76,    59,
     111,    82,     4,     4,    96,   -62,    59,    86,    59,   -62,
      87,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -46,   -10,   -62,   -62,    -2,   -61,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,    54,    78,   -62,   -62,   -20,   -62,    45,   -62,    46
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      42,    44,    75,    49,    50,    38,    86,    20,   101,    31,
      33,    34,    34,   102,    39,    79,    21,    49,    50,    41,
      58,    59,     1,    72,    91,    48,    73,    81,    82,    83,
      40,    22,    23,    24,    32,    66,    76,    51,    52,    53,
      54,    55,     2,    65,     3,    45,    46,    63,    64,     4,
       5,     6,    43,     7,   104,     8,     9,    61,     1,    63,
      67,    63,    85,    49,    50,    42,    68,    62,    70,    42,
      89,    80,    97,    99,    87,    88,     1,    92,     2,    93,
       3,    30,   106,   108,   100,     4,     5,     6,    90,     7,
      94,     8,     9,   103,    42,   105,     2,   110,     3,     1,
     111,    74,    77,     4,     5,     6,    78,     7,     0,     8,
       9,   109,     0,     0,     1,     0,     0,     0,     0,     2,
       0,     3,     0,     0,     0,     0,     4,     5,     6,     0,
       7,     0,     8,     9,     2,     0,     3,     0,     0,     0,
       0,     4,     5,     6,     0,     7,     0,     8,     9
};

static const yytype_int8 yycheck[] =
{
      10,    21,    48,     4,     5,     7,    67,     3,    11,     3,
       3,     3,     3,    16,    12,    61,    12,     4,     5,     0,
       6,     7,     3,    43,    85,    14,    13,    43,    44,    45,
      12,    27,    28,    29,    28,    37,    56,    38,    39,    40,
      41,    42,    23,    35,    25,    21,    22,    17,    18,    30,
      31,    32,    19,    34,   100,    36,    37,    14,     3,    17,
      18,    17,    18,     4,     5,    75,     3,    33,     3,    79,
      15,     3,    92,    93,    17,    17,     3,    10,    23,    10,
      25,     3,   102,   103,    14,    30,    31,    32,    15,    34,
      26,    36,    37,    17,   104,    13,    23,    11,    25,     3,
      13,    47,    57,    30,    31,    32,    60,    34,    -1,    36,
      37,    15,    -1,    -1,     3,    -1,    -1,    -1,    -1,    23,
      -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
      34,    -1,    36,    37,    23,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,    34,    -1,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    23,    25,    30,    31,    32,    34,    36,    37,
      47,    48,    53,    54,    55,    56,    58,    59,    60,    61,
       3,    12,    27,    28,    29,    67,    68,    71,    73,    75,
      68,     3,    28,     3,     3,    49,    51,    50,    51,    12,
      12,     0,    48,    19,    71,    21,    22,    69,    14,     4,
       5,    38,    39,    40,    41,    42,    70,    72,     6,     7,
      74,    14,    33,    17,    18,    35,    51,    18,     3,    64,
       3,    65,    71,    13,    67,    47,    71,    73,    75,    47,
       3,    43,    44,    45,    52,    18,    52,    17,    17,    15,
      15,    52,    10,    10,    26,    57,    66,    71,    62,    71,
      14,    11,    16,    17,    47,    13,    71,    63,    71,    15,
      11,    13
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

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
# if YYLTYPE_IS_TRIVIAL
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

/* Line 1455 of yacc.c  */
#line 77 "sintactico.y"
    { printf("Regla 1 - Compilacion OK\n"); }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 78 "sintactico.y"
    { printf("Regla 2 - programa\n"); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 81 "sintactico.y"
    { printf("Regla 3 - Sentencia\n"); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 82 "sintactico.y"
    { printf("Regla 4 - Sentencia\n"); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 83 "sintactico.y"
    { printf("Regla 5 - Sentencia\n"); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 84 "sintactico.y"
    { printf("Regla 6 - Sentencia\n"); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 85 "sintactico.y"
    { printf("Regla 7 - Sentencia\n"); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 86 "sintactico.y"
    { printf("Regla 8 - Sentencia\n"); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 87 "sintactico.y"
    { printf("Regla 9 - Sentencia\n"); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 88 "sintactico.y"
    { printf("Regla 10 - Sentencia\n"); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 89 "sintactico.y"
    { printf("Regla 11 - Sentencia\n"); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 92 "sintactico.y"
    { 
																insertarListaVariables(pilaDec, tipoDato, ult);
																printf("Regla 12 - Declaracion DEC\n"); 
															}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 98 "sintactico.y"
    { 
																insertarListaVariables(pilaDec, tipoDato, ult);
																printf("Regla 13 - Declaracion DEF %s\n"); 
															}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 102 "sintactico.y"
    { 
																insertarListaVariables(pilaDec, tipoDato, ult);
																printf("Regla 14 - Declaracion DEF %s\n"); 
															}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 108 "sintactico.y"
    { 
																//verificar si la variable ya existen en tabla
																ult = 0;
																strncpy(pilaDec[ult++].nombreDato, yylval.txtPtr, 31);
																printf("Regla 15 - Declaracion %s\n", yylval.txtPtr); 
															}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 114 "sintactico.y"
    { 
																strncpy(pilaDec[ult++].nombreDato, yylval.txtPtr, 31);
																printf("Regla 16 - Declaracion multiple %s\n", yylval.txtPtr); 
															}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 120 "sintactico.y"
    {
																printf("Regla 17 - Tipo dato entero\n"); 
																strncpy(tipoDato, "INT", 31);
															}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 124 "sintactico.y"
    {
																printf("Regla 18 - Tipo dato cadena\n"); 
																strncpy(tipoDato, "STRING", 31);
															}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 128 "sintactico.y"
    {
																printf("Regla 19 - Tipo dato flotante\n"); 
																strncpy(tipoDato, "FLOAT", 31);
															}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 134 "sintactico.y"
    { 
																//verificar tipado e insertar valor
																printf("Regla 20 - Asignacion\n"); 
																insertarEnPolaca((yyvsp[(2) - (3)].txtPtr));
															}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 140 "sintactico.y"
    { insertarEnPolaca((yyvsp[(1) - (1)].txtPtr));}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 142 "sintactico.y"
    { 
																desapilarSalto(3);
																resetearSalto(3, -1);
																printf("Regla 21 - Iterador While\n");
															}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 149 "sintactico.y"
    { 
																desapilarSalto(3);
																desapilarSalto(4);
																
																resetearSalto(3, -1);
																resetearSalto(4, -1);
																printf("Regla 22 - Condicional IF\n"); 
															}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 157 "sintactico.y"
    {
																desapilarSalto(5);
																
																resetearSalto(5, -1);
																printf("Regla 23 - Condicional IF ELSE\n"); 
															}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 164 "sintactico.y"
    {
																insertarEnPolaca("BI");
																guardarPosicion(5);
																insertarEnPolaca("_");
																
																desapilarSalto(3);
																desapilarSalto(4);
																
																resetearSalto(4, -1);
																resetearSalto(3, -1);
															}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 177 "sintactico.y"
    { 
																				printf("Regla 24 - Between\n"); 
																				strncpy(p_inf, "", 31);
																				strncpy(p_sup, "", 31);
																				desapilarSalto(0);
																				desapilarSalto(1);
																			}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 186 "sintactico.y"
    { printf("Regla 25 - InList\n"); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 189 "sintactico.y"
    { 
																insertarEnPolaca("WRITE");
																insertarEnPolaca((yyvsp[(2) - (2)].txtPtr));
																printf("Regla 26 - Write con constante\n");
															}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 194 "sintactico.y"
    { 
																insertarEnPolaca("WRITE");
																insertarEnPolaca((yyvsp[(2) - (2)].txtPtr));
																printf("Regla 27 - Write\n");
															}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 201 "sintactico.y"
    {
																insertarEnPolaca("READ");
																insertarEnPolaca((yyvsp[(2) - (2)].txtPtr));
																printf("Regla 28 - Read\n");
															}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 210 "sintactico.y"
    {
																insertarEnPolaca(p_id);
																insertarEnPolaca(p_inf);
																insertarEnPolaca("CMP");
																insertarEnPolaca("BGT");
																guardarPosicion(0);
																insertarEnPolaca("_");
															}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 219 "sintactico.y"
    {
																insertarEnPolaca(p_id);
																insertarEnPolaca(p_sup);
																insertarEnPolaca("CMP");
																insertarEnPolaca("BLT");
																guardarPosicion(1);
																insertarEnPolaca("_");
																insertarEnPolaca(p_result);
																insertarEnPolaca("true");
																insertarEnPolaca("=");
															}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 231 "sintactico.y"
    {
																encontrado=0;
																strncpy(p_id, yylval.txtPtr, 31);
																insertarEnPolaca("aux_pos");
																insertarEnPolaca("false");
																insertarEnPolaca("=");
																insertarEnPolaca("aux");
																insertarEnPolaca((yyvsp[(1) - (1)].txtPtr));
																insertarEnPolaca("=");
															}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 243 "sintactico.y"
    { 
																printf("Regla 29 - Parametro ID");
																contadorBetween = 0;
																insertarEnPolaca(p_result);
																insertarEnPolaca("false");
																insertarEnPolaca("=");
																insertarEnPolaca(p_id);
																insertarEnPolaca((yyvsp[(1) - (1)].txtPtr));
																insertarEnPolaca("=");
															}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 254 "sintactico.y"
    { 
																insertarEnPolaca("e");
																insertarEnPolaca("=");
																insertarEnPolaca("aux");
																insertarEnPolaca("e");
																insertarEnPolaca("CMP");
																insertarEnPolaca("BNE");
																guardarPosicion(2);
																insertarEnPolaca("_l");
																insertarEnPolaca("aux_pos");
																insertarEnPolaca("true");
																insertarEnPolaca("=");
																desapilarSalto(2);
																
																printf("Regla 29 - Lista\n"); 
															}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 270 "sintactico.y"
    { 
																printf("Regla 30 - Lista larga\n"); 
																insertarEnPolaca("e");
																insertarEnPolaca("=");
																insertarEnPolaca("aux");
																insertarEnPolaca("e");
																insertarEnPolaca("CMP");
																insertarEnPolaca("BNE");
																guardarPosicion(2);
																insertarEnPolaca("_l");
																insertarEnPolaca("aux_pos");
																insertarEnPolaca("true");
																insertarEnPolaca("=");
																desapilarSalto(2);
																
																printf("Regla 29 - Lista\n"); 
															}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 289 "sintactico.y"
    { 
																printf("Regla 31 - Comparador\n");
																
																insertarEnPolaca("CMP");
																insertarEnPolaca(opComparador);
																
															}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 298 "sintactico.y"
    { 
																guardarPosicion(3);
																insertarEnPolaca("_");
																printf("Regla 32 - Condicion\n");
															}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 303 "sintactico.y"
    { 
																guardarPosicion(4);
																insertarEnPolaca("_");
																if(strcmp(opCondicional, "OR") == 0) {
																	desapilarSalto(3);
																	resetearSalto(3, -1);
																}
																printf("Regla 33 - Condicion doble\n");
															}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 314 "sintactico.y"
    { 
																strncpy(opCondicional, "AND", 31);
																guardarPosicion(3);
																insertarEnPolaca("_");
																printf("Regla 34 - Operador Condicional\n");
															}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 320 "sintactico.y"
    { 
																strncpy(opCondicional, "OR", 31);
																guardarPosicion(3);
																insertarEnPolaca("_");
																printf("Regla 35 - Operador Condicional\n");
															}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 329 "sintactico.y"
    { strncpy(opComparador, "BGT", 31);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 330 "sintactico.y"
    { strncpy(opComparador, "BLT", 31);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 331 "sintactico.y"
    { strncpy(opComparador, "BGE", 31);}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 332 "sintactico.y"
    { strncpy(opComparador, "BLE", 31);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 333 "sintactico.y"
    { 
																strncpy(opComparador, "BNE", 31);
																printf("Regla 35 - Operador comparacion\n");
															}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 339 "sintactico.y"
    { 
																printf("Regla 36 - Expresion\n");
															}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 342 "sintactico.y"
    { 
																printf("Regla 38 - expresion %s \n", (yyvsp[(2) - (3)].txtPtr));
																insertarEnPolaca((yyvsp[(2) - (3)].txtPtr));
															}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 350 "sintactico.y"
    { printf("Regla 39 - Factor\n");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 351 "sintactico.y"
    { 
																printf("Regla 40 - Multiplicacion\n");
																insertarEnPolaca((yyvsp[(2) - (3)].txtPtr));
															}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 360 "sintactico.y"
    {
																printf("Regla 42 - ID: %s\n", (yyvsp[(1) - (1)].txtPtr));
																insertarEnPolaca((yyvsp[(1) - (1)].txtPtr));
															}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 364 "sintactico.y"
    {
																printf("Regla 43 - ENTERO es: %s\n", yylval.txtPtr);
																insertarEnPolaca((yyvsp[(1) - (1)].txtPtr));
															}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 368 "sintactico.y"
    {
																printf("Regla 44 - FLOTANTE es %s\n", yylval.txtPtr); 
																insertarEnPolaca((yyvsp[(1) - (1)].txtPtr));
															}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 372 "sintactico.y"
    {
																printf("Regla 45 - CADENA es %s\n", yylval.txtPtr);
																insertarEnPolaca((yyvsp[(1) - (1)].txtPtr));
															}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 376 "sintactico.y"
    { printf("Regla 46 - ( Expresion )\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2151 "y.tab.c"
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



/* Line 1675 of yacc.c  */
#line 378 "sintactico.y"


/***********************************	FUNCIONES	**********************************/
int insertarListaVariables(Dec *pilaDec, char *tipo, int cantidad) {
	int i = 0;
	
	strncpy(tipoDato, tipo, 31);
	
	for(i = 0; i < cantidad; i++) {
		printf("%s ", pilaDec[i].nombreDato);
		insertarEnTS(pilaDec[i].nombreDato, tipoDato, "", "");
	}
	printf("de tipo %s\n", tipoDato);
	return i;
}

int errorLexico(char * msgErr) {
	printf("Lexical Error en linea %d: %s\n", linea, msgErr);
	system("Pause");
	exit(1);
}

int validarEntero(char *txt) {
	long int numero = strtol(txt, NULL, 10);
	//COTA MAXIMA: 32767 || COTA MINIMA: -32767  NOTA: Tmb habia que averiguarlo?
	if( numero >= SHRT_MAX -1 || numero <= SHRT_MIN +1 ) {
		return 1;
	}
	return 0;
}

int validarFlotante(char *txt) {
	float numero = strtof(txt, NULL);
	//COTA MINIMA: 1.175494E-038; COTA MAXIMA: 3.402823E+038
	if( numero < FLT_MIN || numero > FLT_MAX) {
		return 1;
	}
	return 0;
}

/***********************************	FIN FUNCIONES	**********************************/

int main(int argc,char *argv[])
{
	
	/*yyout = fopen("tokens_reconocidos.txt", "wt");

	if(yyout == NULL) {
		perror("Error al abrir el archivo de salida\n");
		return 1;
	}*/
	
	if ((yyin = fopen(argv[1], "rt")) == NULL) {
		printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
		return 2;
	} else {
		yyparse();
	}
	
	grabarPolaca();
	grabarTS();
	
	fclose(yyin);
	//fclose(yyout);
	return 0;
}

int yyerror(voID)
{
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}



