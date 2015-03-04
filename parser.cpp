/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

    #include "node.h"
    #include<bits/stdc++.h>
    using namespace std;

// stuff from flex that bison needs to know about:
    extern "C" int yylex();
    extern "C" FILE *yyin;
    void yyerror(const char *s);
    #include "parser.hpp"

ASTProgram* init_start;


#line 81 "parser.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOLEAN = 258,
    FLOAT = 259,
    INT = 260,
    INT_CONST = 261,
    FLOAT_CONST = 262,
    STRING_CONST = 263,
    CHARACTER_CONST = 264,
    ID = 265,
    COMMENT = 266,
    SYN_ERR = 267,
    IF = 268,
    ELSE = 269,
    FOR = 270,
    RETURN = 271,
    BREAK = 272,
    CONTINUE = 273,
    NULL_TOKEN = 274,
    TRUE = 275,
    FALSE = 276,
    CLASS = 277,
    OPEN_BRACE = 278,
    CLOSE_BRACE = 279,
    SEMI_COLON = 280,
    BOOLEAN_CONST = 281,
    COMMA = 282,
    DOT = 283,
    OPEN_PARANTHESIS = 284,
    CLOSE_PARANTHESIS = 285,
    OPEN_SQR_BRACKET = 286,
    CLOSE_SQR_BRACKET = 287,
    VOID = 288,
    PLUS = 289,
    PLUS_PLUS = 290,
    MINUS = 291,
    MINUS_MINUS = 292,
    MULTIPLY = 293,
    DIVIDE = 294,
    MODULUS = 295,
    NOT_EQUAL = 296,
    NOT = 297,
    OR = 298,
    CALLOUT = 299,
    AND = 300,
    EQUAL_EQUAL = 301,
    EQUAL = 302,
    MIEQ = 303,
    PLEQ = 304,
    LESS_EQUAL = 305,
    LESS = 306,
    GREATER_EQUAL = 307,
    GREATER = 308,
    EOF_TOKEN = 309,
    UMINUS = 310,
    UPLUS = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "parser.y" /* yacc.c:355  */


struct {
    int ival;
    float fval;
    bool bval;
	char* pname;
//	string my;
//	string s;  string not supported
	char sval[100];
	ASTStart *astStart;
	ASTProgram *astProgram;
	vector <ASTDecl*> *astDecl;        
	vector<ASTVarDecl *> *astVarDecl;      
	ASTMethodDecl *astMethodDecl;
	ASTBlock *astBlock;
	vector<ASTStatement *> *astStatement;
	int datatype;      /////Either Char * or array of character or make an enum class   
	ASTString *astString;        
	ASTInt *astInt;
	char* name;
	ASTFloat *astFloat;
	ASTBool *astBool;
	vector< pair<Variable *, int> > *varDecl;
	ASTExpr *astExpr;
	ASTLocation *location;
	ASTCaller *astCaller;
	vector<ASTExpr *> *astexprMult;
    	ASTReturn *astReturn;
	Variable *reference;
    };

#line 211 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   139,   140,   148,   153,   160,   161,   162,
     165,   166,   170,   175,   181,   182,   187,   194,   195,   201,
     206,   211,   216,   223,   229,   230,   241,   251,   253,   259,
     265,   271,   277,   284,   290,   296,   303,   305,   309,   311,
     315,   318,   321,   325,   327,   329,   333,   334,   338,   341,
     349,   350,   354,   356,   358,   360,   362,   364,   366,   369,
     372,   375,   378,   381,   384,   387,   389,   392,   395,   398,
     401,   404,   407,   410,   414,   416,   420
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN", "FLOAT", "INT", "INT_CONST",
  "FLOAT_CONST", "STRING_CONST", "CHARACTER_CONST", "ID", "COMMENT",
  "SYN_ERR", "IF", "ELSE", "FOR", "RETURN", "BREAK", "CONTINUE",
  "NULL_TOKEN", "TRUE", "FALSE", "CLASS", "OPEN_BRACE", "CLOSE_BRACE",
  "SEMI_COLON", "BOOLEAN_CONST", "COMMA", "DOT", "OPEN_PARANTHESIS",
  "CLOSE_PARANTHESIS", "OPEN_SQR_BRACKET", "CLOSE_SQR_BRACKET", "VOID",
  "PLUS", "PLUS_PLUS", "MINUS", "MINUS_MINUS", "MULTIPLY", "DIVIDE",
  "MODULUS", "NOT_EQUAL", "NOT", "OR", "CALLOUT", "AND", "EQUAL_EQUAL",
  "EQUAL", "MIEQ", "PLEQ", "LESS_EQUAL", "LESS", "GREATER_EQUAL",
  "GREATER", "EOF_TOKEN", "UMINUS", "UPLUS", "$accept", "program",
  "declaration", "type", "variables", "variable", "method_decl", "formals",
  "formal_param", "block", "var", "var_decl", "stmt_mult", "ret_expr",
  "else_part", "assign", "method_call", "callout_arg", "next_callout_arg",
  "location", "expr", "int_ast", "expr_mult", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,     1,    16,    -1,   -54,    74,   -54,   -54,   -54,    29,
      17,    40,    22,   -54,    33,    32,    31,     9,     9,    55,
      74,    60,    63,    45,   -54,    46,    51,   -54,    57,   -54,
     -24,    66,    66,   -54,     9,    68,     9,   -54,   -54,   -54,
      65,    60,     8,     9,    81,    81,     9,    76,    67,    64,
      89,    61,    77,    90,    91,     8,    98,   104,   -14,   -54,
     120,   121,   -54,   -54,    30,    61,    61,    85,   -54,   -54,
     -54,   -54,    61,    61,    61,   109,   -54,   -54,   316,   -54,
       8,     8,   127,   -54,   -54,     8,   -54,   -54,   -54,    61,
     107,   108,   -54,   186,   110,   296,   250,    61,   274,   -54,
     -54,     8,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,   -54,   -54,   111,   -54,   166,
       9,     9,    61,   -54,   -54,    66,   206,   -54,   -54,    42,
      42,   -54,   -54,   -54,   365,   336,   356,   365,   385,   385,
     385,   385,    61,   112,     8,   113,   114,   -54,   125,    61,
     -54,   226,   -54,   -54,    66,    66,    66,     8,   137,    61,
     -54,   -54,   -54,   -54,     8,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     9,     8,     7,     0,
       0,     0,     0,     2,    12,     0,    10,    17,    17,     0,
       3,     0,     0,     0,    18,     0,     0,     4,    12,    11,
      19,     0,     0,    13,     0,     0,    24,    14,    14,    20,
      22,     0,    27,    24,     6,     5,     0,     0,    50,     0,
       0,    36,     0,     0,     0,    27,     0,     0,     0,    25,
       0,     0,    21,    26,     0,     0,     0,     0,    74,    56,
      55,    57,     0,     0,     0,     0,    53,    52,    37,    54,
      27,    27,     0,    35,    23,    27,    40,    42,    41,     0,
       0,     0,    43,    75,     0,     0,     0,     0,     0,    72,
      71,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,    46,    29,     0,
      17,    17,     0,    44,    51,     0,     0,    73,    34,    58,
      59,    60,    61,    62,    66,    64,    63,    65,    69,    67,
      70,    68,     0,     0,    27,     0,     0,    76,    38,     0,
      47,    48,    45,    28,     0,     0,     0,    27,     0,     0,
      16,    15,    39,    31,    27,    49,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   139,    10,   -12,   -54,   123,    -8,   -26,   -31,
     102,   -54,   -53,   -54,   -54,   -54,   -38,   -54,     3,   -36,
      44,   -54,    41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    22,    15,    16,    44,    23,    24,    55,
      42,    43,    56,    75,   157,    89,    76,   143,   150,    77,
      93,    79,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    38,    83,    34,    57,     1,    58,    35,    39,    29,
      25,     3,     6,     7,     8,    11,     4,    57,    48,    58,
      62,    49,     5,    50,    51,    52,    53,   115,   116,    47,
      11,    36,   118,    86,    87,    88,    68,    69,    70,    12,
      48,    13,    57,    57,    58,    58,    41,    57,   128,    58,
      14,    17,    54,    41,    61,    61,    71,    20,    21,    72,
      92,    26,    18,    57,    19,    58,    73,    68,    69,    70,
      28,    48,    74,    30,    54,    31,    32,     6,     7,     8,
     104,   105,   106,    33,     6,     7,     8,    71,    19,    36,
      72,   153,    46,    66,   148,    78,    64,    73,    65,    67,
      40,    63,    80,    74,   163,    54,    57,     9,    58,    95,
      96,   166,   145,   146,    60,    81,    98,    99,   100,    57,
      82,    58,    84,   160,   161,   162,    57,   164,    58,    85,
      90,    91,    97,   119,   101,   117,   120,   121,   142,   156,
     123,   126,   152,   154,   155,    59,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    27,
      36,    45,   165,   147,     0,     0,     0,     0,     0,     0,
       0,   102,     0,   103,     0,   104,   105,   106,   107,     0,
     108,     0,   109,   110,     0,     0,   151,   111,   112,   113,
     114,   144,     0,   158,     0,     0,     0,     0,     0,     0,
     102,     0,   103,   151,   104,   105,   106,   107,     0,   108,
       0,   109,   110,   122,     0,     0,   111,   112,   113,   114,
     102,     0,   103,     0,   104,   105,   106,   107,     0,   108,
       0,   109,   110,   149,     0,     0,   111,   112,   113,   114,
     102,     0,   103,     0,   104,   105,   106,   107,     0,   108,
       0,   109,   110,   159,     0,     0,   111,   112,   113,   114,
     102,     0,   103,     0,   104,   105,   106,   107,     0,   108,
       0,   109,   110,     0,     0,     0,   111,   112,   113,   114,
     125,     0,     0,     0,   102,     0,   103,     0,   104,   105,
     106,   107,     0,   108,     0,   109,   110,     0,     0,     0,
     111,   112,   113,   114,   127,     0,     0,     0,   102,     0,
     103,     0,   104,   105,   106,   107,     0,   108,     0,   109,
     110,     0,     0,     0,   111,   112,   113,   114,   124,     0,
     102,     0,   103,     0,   104,   105,   106,   107,     0,   108,
       0,   109,   110,     0,     0,     0,   111,   112,   113,   114,
     102,     0,   103,     0,   104,   105,   106,   107,     0,   108,
       0,   109,   110,     0,     0,     0,   111,   112,   113,   114,
     102,     0,   103,     0,   104,   105,   106,   107,     0,     0,
       0,   109,   110,     0,     0,     0,   111,   112,   113,   114,
     102,     0,   103,     0,   104,   105,   106,   107,     0,   102,
       0,   103,   110,   104,   105,   106,   111,   112,   113,   114,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   102,
       0,   103,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      31,    32,    55,    27,    42,    22,    42,    31,    34,    21,
      18,    10,     3,     4,     5,     5,     0,    55,    10,    55,
      46,    13,    23,    15,    16,    17,    18,    80,    81,    41,
      20,    23,    85,    47,    48,    49,     6,     7,     8,    10,
      10,    24,    80,    81,    80,    81,    36,    85,   101,    85,
      10,    29,    44,    43,    44,    45,    26,    25,    27,    29,
      30,     6,    29,   101,    31,   101,    36,     6,     7,     8,
      10,    10,    42,    10,    44,    30,    30,     3,     4,     5,
      38,    39,    40,    32,     3,     4,     5,    26,    31,    23,
      29,   144,    27,    29,   125,    51,    29,    36,    31,    10,
      32,    25,    25,    42,   157,    44,   144,    33,   144,    65,
      66,   164,   120,   121,    33,    25,    72,    73,    74,   157,
      29,   157,    24,   154,   155,   156,   164,   158,   164,    25,
      10,    10,    47,    89,    25,     8,    29,    29,    27,    14,
      30,    97,    30,    30,    30,    43,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    20,
      23,    38,   159,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    36,    -1,    38,    39,    40,    41,    -1,
      43,    -1,    45,    46,    -1,    -1,   142,    50,    51,    52,
      53,    25,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    36,   159,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    27,    -1,    -1,    50,    51,    52,    53,
      34,    -1,    36,    -1,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    27,    -1,    -1,    50,    51,    52,    53,
      34,    -1,    36,    -1,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    27,    -1,    -1,    50,    51,    52,    53,
      34,    -1,    36,    -1,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      30,    -1,    -1,    -1,    34,    -1,    36,    -1,    38,    39,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,    52,    53,    30,    -1,    -1,    -1,    34,    -1,
      36,    -1,    38,    39,    40,    41,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    52,    53,    32,    -1,
      34,    -1,    36,    -1,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      34,    -1,    36,    -1,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      34,    -1,    36,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      34,    -1,    36,    -1,    38,    39,    40,    41,    -1,    34,
      -1,    36,    46,    38,    39,    40,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    34,
      -1,    36,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    58,    10,     0,    23,     3,     4,     5,    33,
      59,    60,    10,    24,    10,    61,    62,    29,    29,    31,
      25,    27,    60,    64,    65,    64,     6,    59,    10,    61,
      10,    30,    30,    32,    27,    31,    23,    66,    66,    65,
      32,    60,    67,    68,    63,    63,    27,    61,    10,    13,
      15,    16,    17,    18,    44,    66,    69,    73,    76,    67,
      33,    60,    65,    25,    29,    31,    29,    10,     6,     7,
       8,    26,    29,    36,    42,    70,    73,    76,    77,    78,
      25,    25,    29,    69,    24,    25,    47,    48,    49,    72,
      10,    10,    30,    77,    79,    77,    77,    47,    77,    77,
      77,    25,    34,    36,    38,    39,    40,    41,    43,    45,
      46,    50,    51,    52,    53,    69,    69,     8,    69,    77,
      29,    29,    27,    30,    32,    30,    77,    30,    69,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    27,    74,    25,    64,    64,    79,    66,    27,
      75,    77,    30,    69,    30,    30,    14,    71,    77,    27,
      66,    66,    66,    69,    66,    75,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    65,    65,    66,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     4,     7,     7,     1,     1,     1,
       1,     3,     1,     4,     0,     7,     7,     0,     1,     2,
       4,     6,     4,     4,     0,     2,     3,     0,     5,     3,
       8,     7,     3,     3,     4,     2,     0,     1,     0,     2,
       1,     1,     1,     3,     4,     5,     0,     2,     1,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     1,     1,     3
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 136 "parser.y" /* yacc.c:1646  */
    { init_start = new ASTProgram((yyvsp[-1].astDecl));}
#line 1473 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.astDecl) = new vector<ASTDecl*>;}
#line 1479 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 141 "parser.y" /* yacc.c:1646  */
    {
	                (yyval.astDecl)=(yyvsp[0].astDecl);
               	 	for(int i=0;i<int((yyvsp[-2].varDecl)->size()); i++)
  	                {
	                    (yyval.astDecl)->push_back(new ASTVarDecl((yyvsp[-3].datatype), (*(yyvsp[-2].varDecl))[i].first, (*(yyvsp[-2].varDecl))[i].second));
	     		}
                }
#line 1491 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 149 "parser.y" /* yacc.c:1646  */
    {
			(yyval.astDecl)=(yyvsp[0].astDecl);
			(yyval.astDecl)->push_back(new ASTMethodDecl((ASTBlock *)(yyvsp[-1].astBlock),(yyvsp[-3].astVarDecl),new Variable((yyvsp[-5].name)),(yyvsp[-6].datatype)));
		}
#line 1500 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 154 "parser.y" /* yacc.c:1646  */
    {	
			(yyval.astDecl)=(yyvsp[0].astDecl);
			(yyval.astDecl)->push_back(new ASTMethodDecl((ASTBlock *)(yyvsp[-1].astBlock),(yyvsp[-3].astVarDecl),new Variable((yyvsp[-5].name)),4));
		}
#line 1509 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 160 "parser.y" /* yacc.c:1646  */
    {(yyval.datatype) = 0;}
#line 1515 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.datatype) = 1;}
#line 1521 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.datatype) = 2;}
#line 1527 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.varDecl) = (yyvsp[0].varDecl);}
#line 1533 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.varDecl) = (yyvsp[0].varDecl); (yyval.varDecl)->push_back((*(yyvsp[-2].varDecl))[0]);}
#line 1539 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 171 "parser.y" /* yacc.c:1646  */
    {
	            (yyval.varDecl) = new vector< pair<Variable*, int> >;
                    (yyval.varDecl)->push_back(make_pair(new Variable((yyvsp[0].name)),0));
              }
#line 1548 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 176 "parser.y" /* yacc.c:1646  */
    {
                (yyval.varDecl) = new vector< pair<Variable*, int> >;
                (yyval.varDecl)->push_back( make_pair(new Variable((yyvsp[-3].name)), (yyvsp[-1].ival) ));
              }
#line 1557 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.astDecl) = new vector<ASTDecl*>;}
#line 1563 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 183 "parser.y" /* yacc.c:1646  */
    {
			 (yyval.astDecl) = (yyvsp[-6].astDecl);
			 (yyval.astDecl)->push_back(new ASTMethodDecl((ASTBlock *)(yyvsp[0].astBlock),(yyvsp[-2].astVarDecl),new Variable((yyvsp[-4].name)),(yyvsp[-5].datatype)));
		     }
#line 1572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 188 "parser.y" /* yacc.c:1646  */
    {
			 (yyval.astDecl) = (yyvsp[-6].astDecl);
			 (yyval.astDecl)->push_back(new ASTMethodDecl((ASTBlock *)(yyvsp[0].astBlock),(yyvsp[-2].astVarDecl),new Variable((yyvsp[-4].name)),4));
		     }
#line 1581 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.astVarDecl) = NULL;}
#line 1587 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 196 "parser.y" /* yacc.c:1646  */
    {
		     (yyval.astVarDecl) = (yyvsp[0].astVarDecl);
	       }
#line 1595 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 202 "parser.y" /* yacc.c:1646  */
    {
			  (yyval.astVarDecl) = new vector<ASTVarDecl *> ;
			  (yyval.astVarDecl)->push_back(new ASTVarDecl((yyvsp[-1].datatype),new Variable((yyvsp[0].name)),0));
	       }
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "parser.y" /* yacc.c:1646  */
    {
		      (yyval.astVarDecl) = (yyvsp[0].astVarDecl);
			  (yyval.astVarDecl)->push_back(new ASTVarDecl((yyvsp[-3].datatype),new Variable((yyvsp[-2].name)),0));
	       }
#line 1613 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 212 "parser.y" /* yacc.c:1646  */
    {
              (yyval.astVarDecl) = (yyvsp[0].astVarDecl);
              (yyval.astVarDecl)->push_back(new ASTVarDecl((yyvsp[-5].datatype),new Variable((yyvsp[-4].name)),-1));
           }
#line 1622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 217 "parser.y" /* yacc.c:1646  */
    {
			  (yyval.astVarDecl) = new vector<ASTVarDecl *> ;
              (yyval.astVarDecl)->push_back(new ASTVarDecl((yyvsp[-3].datatype),new Variable((yyvsp[-2].name)),-1));
           }
#line 1631 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 224 "parser.y" /* yacc.c:1646  */
    {
		  (yyval.astBlock) = new ASTBlock((yyvsp[-2].astVarDecl),(yyvsp[-1].astStatement));
	   }
#line 1639 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 229 "parser.y" /* yacc.c:1646  */
    {(yyval.astVarDecl) = new vector<ASTVarDecl*>;}
#line 1645 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 231 "parser.y" /* yacc.c:1646  */
    {
	 	 (yyval.astVarDecl) = (yyvsp[0].astVarDecl);
		 for(int i=0;i<int((yyvsp[-1].astVarDecl)->size());i++)
		 {
			 (yyval.astVarDecl)->push_back((*(yyvsp[-1].astVarDecl))[i]);
		 }
         
	 }
#line 1658 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 242 "parser.y" /* yacc.c:1646  */
    {
		    (yyval.astVarDecl) = new vector<ASTVarDecl*>;
		    for(int i=0;i<int((yyvsp[-1].varDecl)->size());i++)
		    {
			(yyval.astVarDecl)->push_back(new ASTVarDecl((yyvsp[-2].datatype),(*(yyvsp[-1].varDecl))[i].first,(*(yyvsp[-1].varDecl))[i].second));
		    }
	    }
#line 1670 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 251 "parser.y" /* yacc.c:1646  */
    {(yyval.astStatement) = new vector<ASTStatement *>;}
#line 1676 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 254 "parser.y" /* yacc.c:1646  */
    {
			        (yyval.astStatement) = (yyvsp[0].astStatement);
	                (yyval.astStatement)->push_back( new ASTAssignment((yyvsp[-4].location), (yyvsp[-2].astExpr) ,(yyvsp[-3].datatype)));
          	    }
#line 1685 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 260 "parser.y" /* yacc.c:1646  */
    {
			        (yyval.astStatement) = (yyvsp[0].astStatement);
			        (yyval.astStatement)->push_back((ASTStatement *) (yyvsp[-2].astCaller));
		        }
#line 1694 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 266 "parser.y" /* yacc.c:1646  */
    {
			        (yyval.astStatement) = (yyvsp[0].astStatement);
			        (yyval.astStatement)->push_back(new ASTFor(new Variable((yyvsp[-6].name)),(yyvsp[-4].astExpr),(yyvsp[-2].astExpr),(yyvsp[-1].astBlock)));
		        }
#line 1703 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 272 "parser.y" /* yacc.c:1646  */
    {
			        (yyval.astStatement)=(yyvsp[0].astStatement);
			        (yyval.astStatement)->push_back(new ASTIf((yyvsp[-4].astExpr),(yyvsp[-2].astBlock),(yyvsp[-1].astBlock)));
		        }
#line 1712 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 278 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.astStatement) = (yyvsp[0].astStatement);
                    (yyval.astStatement)->push_back(new ASTKeyword("break"));
                    
                }
#line 1722 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 285 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.astStatement) = (yyvsp[0].astStatement);
                    (yyval.astStatement)->push_back(new ASTKeyword("continue"));
                }
#line 1731 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 291 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.astStatement) = (yyvsp[0].astStatement);
                    (yyval.astStatement)->push_back(new ASTReturn((ASTExpr*)(yyvsp[-2].astExpr)));
                }
#line 1740 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 297 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.astStatement) = (yyvsp[0].astStatement);
                    (yyval.astStatement)->push_back((ASTStatement*)(yyvsp[-1].astBlock));
                }
#line 1749 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = NULL;}
#line 1755 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 306 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = (yyvsp[0].astExpr);}
#line 1761 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.astBlock) = NULL;}
#line 1767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 312 "parser.y" /* yacc.c:1646  */
    {(yyval.astBlock) = (yyvsp[0].astBlock);}
#line 1773 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 316 "parser.y" /* yacc.c:1646  */
    {(yyval.datatype) = 0;}
#line 1779 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 319 "parser.y" /* yacc.c:1646  */
    {(yyval.datatype) = 1;}
#line 1785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 322 "parser.y" /* yacc.c:1646  */
    {(yyval.datatype) = 2;}
#line 1791 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval.astCaller) = new ASTMethodCall(new Variable((yyvsp[-2].name)),NULL);}
#line 1797 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 328 "parser.y" /* yacc.c:1646  */
    {(yyval.astCaller) = new ASTMethodCall(new Variable((yyvsp[-3].name)),(yyvsp[-1].astexprMult));}
#line 1803 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 330 "parser.y" /* yacc.c:1646  */
    {(yyval.astCaller)= new ASTCallout((yyvsp[-2].name),(yyvsp[-1].astexprMult));}
#line 1809 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 333 "parser.y" /* yacc.c:1646  */
    {(yyval.astexprMult) = new vector<ASTExpr *>;}
#line 1815 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 335 "parser.y" /* yacc.c:1646  */
    {(yyval.astexprMult) = (yyvsp[0].astexprMult);}
#line 1821 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 338 "parser.y" /* yacc.c:1646  */
    {(yyval.astexprMult) = new vector<ASTExpr *>;
		    	(yyval.astexprMult)->push_back((ASTExpr *)(yyvsp[0].astExpr));
		    }
#line 1829 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 342 "parser.y" /* yacc.c:1646  */
    {
			    (yyval.astexprMult) = (yyvsp[0].astexprMult);
			    (yyval.astexprMult)->push_back((ASTExpr *)(yyvsp[-2].astExpr));
		    }
#line 1838 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 349 "parser.y" /* yacc.c:1646  */
    {(yyval.location) = new ASTLocation(new Variable((yyvsp[0].name)), NULL);}
#line 1844 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 351 "parser.y" /* yacc.c:1646  */
    {(yyval.location) = new ASTLocation(new Variable((yyvsp[-3].name)),(yyvsp[-1].astExpr));}
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = (yyvsp[0].location);}
#line 1856 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 356 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) =(ASTExpr *) (yyvsp[0].astCaller);}
#line 1862 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 358 "parser.y" /* yacc.c:1646  */
    { (yyval.astExpr) =  (yyvsp[0].astInt); }
#line 1868 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 360 "parser.y" /* yacc.c:1646  */
    { (yyval.astExpr) = new ASTString((yyvsp[0].name));}
#line 1874 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 362 "parser.y" /* yacc.c:1646  */
    { (yyval.astExpr) = new ASTFloat((yyvsp[0].fval));}
#line 1880 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 364 "parser.y" /* yacc.c:1646  */
    { (yyval.astExpr) =  new ASTBool((yyvsp[0].bval));}
#line 1886 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 367 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("+",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1892 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 370 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("-",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1898 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 373 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("*",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1904 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 376 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("/",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1910 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("%",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1916 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 382 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("&",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1922 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 385 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("|",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1928 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 388 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("==",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1934 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 390 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("!=",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1940 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 393 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("<",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1946 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 396 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp(">",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1952 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 399 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("<=",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1958 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 402 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp(">=",(ASTExpr*)(yyvsp[-2].astExpr) ,(ASTExpr*) (yyvsp[0].astExpr) );}
#line 1964 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 405 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("!",NULL,(ASTExpr*) (yyvsp[0].astExpr));}
#line 1970 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 408 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = new ASTOp("--",NULL,(ASTExpr*) (yyvsp[0].astExpr));}
#line 1976 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 411 "parser.y" /* yacc.c:1646  */
    {(yyval.astExpr) = (yyvsp[-1].astExpr);}
#line 1982 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 414 "parser.y" /* yacc.c:1646  */
    { (yyval.astInt) = new ASTInt((yyvsp[0].ival));}
#line 1988 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 416 "parser.y" /* yacc.c:1646  */
    {
		      (yyval.astexprMult)= new vector<ASTExpr *>;
	              (yyval.astexprMult)->push_back((ASTExpr *)(yyvsp[0].astExpr));
	      	   }
#line 1997 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 421 "parser.y" /* yacc.c:1646  */
    {
		      (yyval.astexprMult) = (yyvsp[0].astexprMult);
		      (yyval.astexprMult)->push_back((ASTExpr *)(yyvsp[-2].astExpr));
	      }
#line 2006 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2010 "parser.cpp" /* yacc.c:1646  */
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 428 "parser.y" /* yacc.c:1906  */


void yyerror(const char *s) 
{
        cout<<"ERROR: "<<s<<endl;
            exit(-1);
}

