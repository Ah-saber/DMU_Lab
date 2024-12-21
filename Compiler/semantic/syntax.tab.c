/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "lex.yy.c"
    #include "node.h"
    extern bool synError;
    extern char **errors;

    int error_count = 0;
    int synbuff = 100;
    char **errors;
    pNode root = NULL;
    char *errors_msg = NULL;
    #define YYERROR_VERBOSE 1
    
    int yyerror(const char* msg){
        synError = TRUE;
        if(errors_msg != NULL)
        {
            fprintf(stderr, "Error type B at line %d: %s", yylineno, errors_msg);
            errors_msg = NULL;
        }
        else fprintf(stderr, "Error type B at line %d: %s.\n", yylineno, msg);
    }
    
    //#define YYDEBUG 1


#line 101 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_TYPE = 5,                       /* TYPE  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_DOT = 7,                        /* DOT  */
  YYSYMBOL_SEMI = 8,                       /* SEMI  */
  YYSYMBOL_RELOP = 9,                      /* RELOP  */
  YYSYMBOL_ASSIGNOP = 10,                  /* ASSIGNOP  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_STAR = 13,                      /* STAR  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_LP = 18,                        /* LP  */
  YYSYMBOL_RP = 19,                        /* RP  */
  YYSYMBOL_LB = 20,                        /* LB  */
  YYSYMBOL_RB = 21,                        /* RB  */
  YYSYMBOL_LC = 22,                        /* LC  */
  YYSYMBOL_RC = 23,                        /* RC  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_FOR = 27,                       /* FOR  */
  YYSYMBOL_STRUCT = 28,                    /* STRUCT  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_WRITE = 30,                     /* WRITE  */
  YYSYMBOL_READ = 31,                      /* READ  */
  YYSYMBOL_CALL = 32,                      /* CALL  */
  YYSYMBOL_MAIN = 33,                      /* MAIN  */
  YYSYMBOL_LOWER_THAN_ELSE = 34,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_Program = 36,                   /* Program  */
  YYSYMBOL_ExtDefList = 37,                /* ExtDefList  */
  YYSYMBOL_CodeDec = 38,                   /* CodeDec  */
  YYSYMBOL_MainDec = 39,                   /* MainDec  */
  YYSYMBOL_FunDec = 40,                    /* FunDec  */
  YYSYMBOL_VarList = 41,                   /* VarList  */
  YYSYMBOL_ParamDec = 42,                  /* ParamDec  */
  YYSYMBOL_ExtDecList = 43,                /* ExtDecList  */
  YYSYMBOL_FunBody = 44,                   /* FunBody  */
  YYSYMBOL_Specifier = 45,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 46,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 47,                    /* OptTag  */
  YYSYMBOL_Tag = 48,                       /* Tag  */
  YYSYMBOL_DefList = 49,                   /* DefList  */
  YYSYMBOL_Def = 50,                       /* Def  */
  YYSYMBOL_DecList = 51,                   /* DecList  */
  YYSYMBOL_Dec = 52,                       /* Dec  */
  YYSYMBOL_VarDec = 53,                    /* VarDec  */
  YYSYMBOL_StatList = 54,                  /* StatList  */
  YYSYMBOL_Statements = 55,                /* Statements  */
  YYSYMBOL_Expr = 56,                      /* Expr  */
  YYSYMBOL_Args = 57                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    91,    91,    93,    94,    97,    98,    99,   100,   102,
     103,   105,   106,   107,   109,   110,   112,   114,   115,   117,
     118,   121,   122,   124,   125,   127,   128,   130,   134,   135,
     137,   139,   140,   142,   143,   145,   146,   147,   152,   153,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   184,   185
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "INT", "ID", "TYPE", "COMMA",
  "DOT", "SEMI", "RELOP", "ASSIGNOP", "PLUS", "MINUS", "STAR", "DIV",
  "AND", "OR", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "IF", "ELSE",
  "WHILE", "FOR", "STRUCT", "RETURN", "WRITE", "READ", "CALL", "MAIN",
  "LOWER_THAN_ELSE", "$accept", "Program", "ExtDefList", "CodeDec",
  "MainDec", "FunDec", "VarList", "ParamDec", "ExtDecList", "FunBody",
  "Specifier", "StructSpecifier", "OptTag", "Tag", "DefList", "Def",
  "DecList", "Dec", "VarDec", "StatList", "Statements", "Expr", "Args", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,     7,   -62,    14,    51,   -62,    18,   -62,    12,   -62,
     -62,    33,    37,   -62,   -62,   -62,    49,    64,   -62,    67,
      30,    68,     2,     6,   -62,    25,    45,    73,     6,   -62,
     -62,    86,    94,    86,    75,     6,   -62,    80,    95,    86,
      30,    84,   -62,    57,   -62,   -62,    83,    92,   103,   110,
       4,   -62,   -62,   -62,     6,   102,   -62,    30,    39,   -62,
     105,   117,   117,   117,   106,   107,   108,   117,   117,   123,
     -62,   109,    57,   157,   -62,   -62,   -62,    86,   117,   -62,
     -62,   -62,    90,    58,    47,   169,   117,   117,   117,   183,
     197,   120,   -62,   -62,   126,   -62,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   -62,   277,   -62,   130,   112,
     -62,   209,   223,   237,   -62,   -62,   -62,   -62,   307,   277,
      58,    58,    47,    47,   297,   287,   142,   117,   -62,    88,
      88,   117,   -62,   -62,   113,   -62,   251,    88,   117,   -62,
     263,    88,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    21,    26,     0,     2,     0,     4,     0,    22,
       8,    27,     0,    24,     1,     3,     0,    35,     7,     0,
       0,     0,    17,    29,    13,     0,     0,     0,    29,     5,
       6,     0,     0,     0,     0,    29,    12,     0,    14,     0,
       0,     0,    20,     0,    35,    18,     0,     0,     0,    31,
      33,    23,    28,    11,     0,    16,    10,     0,     0,    66,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,    37,    36,    30,     0,     0,    15,
       9,    49,     0,    55,    54,     0,     0,     0,     0,     0,
       0,     0,    19,    38,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    34,    51,    68,     0,
      56,     0,     0,     0,    48,    45,    44,    52,    58,    57,
      61,    62,    63,    64,    59,    60,     0,     0,    50,     0,
       0,     0,    53,    67,    40,    42,     0,     0,     0,    41,
       0,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   127,   -62,   -62,   -62,   -21,   -62,   116,    -8,
       3,   -62,   -62,   -62,    28,   -62,    71,   -62,   -29,    87,
     193,   -61,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    20,    37,    38,    21,    70,
      33,     9,    12,    13,    34,    35,    48,    49,    22,    71,
      72,    73,   109
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    84,    85,     8,    50,    41,    89,    90,    31,     8,
      55,     2,    29,    16,    78,    10,    17,   106,    11,     1,
      18,   108,    32,     2,    32,   111,   112,   113,    39,    39,
       2,    27,    56,    79,     3,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    36,    19,     3,    81,    50,    80,
       2,    14,    28,     3,    94,   -25,    43,    39,    58,    23,
      59,    60,    42,    52,    40,    94,   108,   104,    24,    61,
     136,   100,   101,     3,    62,    63,    30,   140,   104,    28,
     -39,    64,    25,    65,    66,    26,    67,    68,    69,    58,
      44,    59,    60,    59,    60,    46,    42,    47,    51,    53,
      61,    54,    61,    57,    74,    62,    63,    62,    63,   107,
      28,    76,    64,    75,    65,    66,    77,    67,    68,    69,
      59,    60,    32,    82,    86,    87,    88,    91,   116,    61,
     117,   128,    92,    15,    62,    63,   127,    94,   137,    96,
      97,    98,    99,   100,   101,   102,   103,    45,   105,    94,
     104,    96,    97,    98,    99,   100,   101,   102,   103,    93,
       0,   133,   104,   132,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,    94,   104,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,   110,   104,
      94,   114,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,    94,   115,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,    94,   104,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,   129,   104,
      94,     0,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,   130,   104,    94,   131,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,    94,   138,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
      94,   104,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,   141,   104,    94,     0,    96,    97,    98,    99,
     100,   101,   102,   103,    94,     0,    96,   104,    98,    99,
     100,   101,   102,     0,    94,     0,    96,   104,    98,    99,
     100,   101,     0,     0,    94,     0,     0,   104,    98,    99,
     100,   101,   134,   135,     0,     0,     0,   104,     0,     0,
     139,     0,     0,     0,   142
};

static const yytype_int16 yycheck[] =
{
      61,    62,    63,     0,    33,    26,    67,    68,     6,     6,
      39,     5,    20,     1,    10,     8,     4,    78,     4,     1,
       8,    82,    20,     5,    20,    86,    87,    88,    25,    26,
       5,     1,    40,    54,    28,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    19,    33,    28,     8,    77,    57,
       5,     0,    22,    28,     7,    22,    28,    54,     1,    22,
       3,     4,    23,    35,    19,     7,   127,    20,    19,    12,
     131,    13,    14,    28,    17,    18,     8,   138,    20,    22,
      23,    24,    18,    26,    27,    18,    29,    30,    31,     1,
       4,     3,     4,     3,     4,     1,    23,     3,    23,    19,
      12,     6,    12,    19,    21,    17,    18,    17,    18,    19,
      22,     8,    24,    21,    26,    27,     6,    29,    30,    31,
       3,     4,    20,    18,    18,    18,    18,     4,     8,    12,
       4,    19,    23,     6,    17,    18,     6,     7,    25,     9,
      10,    11,    12,    13,    14,    15,    16,    31,    77,     7,
      20,     9,    10,    11,    12,    13,    14,    15,    16,    72,
      -1,   127,    20,    21,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,     7,    20,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    20,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,     7,    20,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    20,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
       7,    20,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,     7,    -1,     9,    20,    11,    12,
      13,    14,    15,    -1,     7,    -1,     9,    20,    11,    12,
      13,    14,    -1,    -1,     7,    -1,    -1,    20,    11,    12,
      13,    14,   129,   130,    -1,    -1,    -1,    20,    -1,    -1,
     137,    -1,    -1,    -1,   141
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,    28,    36,    37,    38,    39,    45,    46,
       8,     4,    47,    48,     0,    37,     1,     4,     8,    33,
      40,    43,    53,    22,    19,    18,    18,     1,    22,    44,
       8,     6,    20,    45,    49,    50,    19,    41,    42,    45,
      19,    41,    23,    49,     4,    43,     1,     3,    51,    52,
      53,    23,    49,    19,     6,    53,    44,    19,     1,     3,
       4,    12,    17,    18,    24,    26,    27,    29,    30,    31,
      44,    54,    55,    56,    21,    21,     8,     6,    10,    41,
      44,     8,    18,    56,    56,    56,    18,    18,    18,    56,
      56,     4,    23,    54,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    20,    51,    56,    19,    56,    57,
      19,    56,    56,    56,     8,     8,     8,     4,    56,    56,
      56,    56,    56,    56,    56,    56,    56,     6,    19,    19,
      19,     8,    21,    57,    55,    55,    56,    25,     8,    55,
      56,    19,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    39,
      39,    40,    40,    40,    41,    41,    42,    43,    43,    44,
      44,    45,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     3,     2,     2,     6,
       5,     4,     3,     2,     1,     3,     2,     1,     3,     4,
       2,     1,     1,     5,     2,     1,     0,     1,     2,     0,
       3,     1,     3,     1,     3,     1,     4,     4,     2,     0,
       5,     7,     5,     9,     3,     3,     1,     2,     3,     2,
       4,     3,     3,     4,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 91 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Program", 1, (yyvsp[0].node)); root = (yyval.node); }
#line 1605 "syntax.tab.c"
    break;

  case 3: /* ExtDefList: CodeDec ExtDefList  */
#line 93 "syntax.y"
                                                                                { (yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ExtDefList", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1611 "syntax.tab.c"
    break;

  case 4: /* ExtDefList: MainDec  */
#line 94 "syntax.y"
                                                                                { (yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ExtDefList", 1, (yyvsp[0].node));}
#line 1617 "syntax.tab.c"
    break;

  case 5: /* CodeDec: Specifier FunDec FunBody  */
#line 97 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "CodeDec", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1623 "syntax.tab.c"
    break;

  case 6: /* CodeDec: Specifier ExtDecList SEMI  */
#line 98 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "CodeDec", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1629 "syntax.tab.c"
    break;

  case 7: /* CodeDec: Specifier SEMI  */
#line 99 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "CodeDec", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1635 "syntax.tab.c"
    break;

  case 8: /* CodeDec: error SEMI  */
#line 100 "syntax.y"
                                                                                { synError = TRUE; }
#line 1641 "syntax.tab.c"
    break;

  case 9: /* MainDec: Specifier MAIN LP VarList RP FunBody  */
#line 102 "syntax.y"
                                                                                                 {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "MainDec", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1647 "syntax.tab.c"
    break;

  case 10: /* MainDec: Specifier MAIN LP RP FunBody  */
#line 103 "syntax.y"
                                                                                                 {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "MainDec", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1653 "syntax.tab.c"
    break;

  case 11: /* FunDec: ID LP VarList RP  */
#line 105 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "FunDec", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1659 "syntax.tab.c"
    break;

  case 12: /* FunDec: ID LP RP  */
#line 106 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "FunDec", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1665 "syntax.tab.c"
    break;

  case 13: /* FunDec: error RP  */
#line 107 "syntax.y"
                                                                                {synError = TRUE; }
#line 1671 "syntax.tab.c"
    break;

  case 14: /* VarList: ParamDec  */
#line 109 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "VarList", 1, (yyvsp[0].node)); }
#line 1677 "syntax.tab.c"
    break;

  case 15: /* VarList: ParamDec COMMA VarList  */
#line 110 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "VarList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1683 "syntax.tab.c"
    break;

  case 16: /* ParamDec: Specifier VarDec  */
#line 112 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ParamDec", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1689 "syntax.tab.c"
    break;

  case 17: /* ExtDecList: VarDec  */
#line 114 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ExtDecList", 1, (yyvsp[0].node)); }
#line 1695 "syntax.tab.c"
    break;

  case 18: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 115 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ExtDecList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1701 "syntax.tab.c"
    break;

  case 19: /* FunBody: LC DefList StatList RC  */
#line 117 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "FunBody", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1707 "syntax.tab.c"
    break;

  case 20: /* FunBody: error RC  */
#line 118 "syntax.y"
                                                                                {synError = TRUE;  }
#line 1713 "syntax.tab.c"
    break;

  case 21: /* Specifier: TYPE  */
#line 121 "syntax.y"
                                                                                 {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Specifier", 1, (yyvsp[0].node));  }
#line 1719 "syntax.tab.c"
    break;

  case 22: /* Specifier: StructSpecifier  */
#line 122 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Specifier", 1, (yyvsp[0].node));  }
#line 1725 "syntax.tab.c"
    break;

  case 23: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 124 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "StructSpecifier", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1731 "syntax.tab.c"
    break;

  case 24: /* StructSpecifier: STRUCT Tag  */
#line 125 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "StructSpecifier", 2, (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1737 "syntax.tab.c"
    break;

  case 25: /* OptTag: ID  */
#line 127 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "OptTag", 1, (yyvsp[0].node));  }
#line 1743 "syntax.tab.c"
    break;

  case 26: /* OptTag: %empty  */
#line 128 "syntax.y"
                                                                                {(yyval.node) = NULL ;}
#line 1749 "syntax.tab.c"
    break;

  case 27: /* Tag: ID  */
#line 130 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Tag", 1, (yyvsp[0].node));  }
#line 1755 "syntax.tab.c"
    break;

  case 28: /* DefList: Def DefList  */
#line 134 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "DefList", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1761 "syntax.tab.c"
    break;

  case 29: /* DefList: %empty  */
#line 135 "syntax.y"
                                                                                {(yyval.node) = NULL; }
#line 1767 "syntax.tab.c"
    break;

  case 30: /* Def: Specifier DecList SEMI  */
#line 137 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Def", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1773 "syntax.tab.c"
    break;

  case 31: /* DecList: Dec  */
#line 139 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "DecList", 1, (yyvsp[0].node));  }
#line 1779 "syntax.tab.c"
    break;

  case 32: /* DecList: Dec COMMA DecList  */
#line 140 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "DecList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1785 "syntax.tab.c"
    break;

  case 33: /* Dec: VarDec  */
#line 142 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Dec", 1, (yyvsp[0].node));  }
#line 1791 "syntax.tab.c"
    break;

  case 34: /* Dec: VarDec ASSIGNOP Expr  */
#line 143 "syntax.y"
                                                                                    {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Dec", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1797 "syntax.tab.c"
    break;

  case 35: /* VarDec: ID  */
#line 145 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "VarDec", 1, (yyvsp[0].node)); }
#line 1803 "syntax.tab.c"
    break;

  case 36: /* VarDec: VarDec LB INT RB  */
#line 146 "syntax.y"
                                                                                  {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "VarDec", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1809 "syntax.tab.c"
    break;

  case 37: /* VarDec: VarDec LB error RB  */
#line 147 "syntax.y"
                                                                                {synError = TRUE;  fprintf(stderr, "Integer declarations are required in square brackets\n");}
#line 1815 "syntax.tab.c"
    break;

  case 38: /* StatList: Statements StatList  */
#line 152 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "StatList", 2, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1821 "syntax.tab.c"
    break;

  case 39: /* StatList: %empty  */
#line 153 "syntax.y"
                                                                                {(yyval.node) = NULL;}
#line 1827 "syntax.tab.c"
    break;

  case 40: /* Statements: IF LP Expr RP Statements  */
#line 155 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1833 "syntax.tab.c"
    break;

  case 41: /* Statements: IF LP Expr RP Statements ELSE Statements  */
#line 156 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1839 "syntax.tab.c"
    break;

  case 42: /* Statements: WHILE LP Expr RP Statements  */
#line 157 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1845 "syntax.tab.c"
    break;

  case 43: /* Statements: FOR LP Expr SEMI Expr SEMI Expr RP Statements  */
#line 158 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 9, (yyvsp[-8].node), (yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1851 "syntax.tab.c"
    break;

  case 44: /* Statements: READ ID SEMI  */
#line 159 "syntax.y"
                                                                                    {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 2, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1857 "syntax.tab.c"
    break;

  case 45: /* Statements: WRITE Expr SEMI  */
#line 160 "syntax.y"
                                                                                   {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1863 "syntax.tab.c"
    break;

  case 46: /* Statements: FunBody  */
#line 161 "syntax.y"
                                                                           {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[0].node));   }
#line 1869 "syntax.tab.c"
    break;

  case 47: /* Statements: Expr SEMI  */
#line 162 "syntax.y"
                                                                                 {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[-1].node));   }
#line 1875 "syntax.tab.c"
    break;

  case 48: /* Statements: RETURN Expr SEMI  */
#line 163 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1881 "syntax.tab.c"
    break;

  case 49: /* Statements: error SEMI  */
#line 164 "syntax.y"
                                                                                 {synError = TRUE;}
#line 1887 "syntax.tab.c"
    break;

  case 50: /* Expr: ID LP Args RP  */
#line 166 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1893 "syntax.tab.c"
    break;

  case 51: /* Expr: ID LP RP  */
#line 167 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1899 "syntax.tab.c"
    break;

  case 52: /* Expr: Expr DOT ID  */
#line 168 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1905 "syntax.tab.c"
    break;

  case 53: /* Expr: Expr LB Expr RB  */
#line 169 "syntax.y"
                                                                                 {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1911 "syntax.tab.c"
    break;

  case 54: /* Expr: NOT Expr  */
#line 170 "syntax.y"
                                                                            {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 2, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1917 "syntax.tab.c"
    break;

  case 55: /* Expr: MINUS Expr  */
#line 171 "syntax.y"
                                                                              {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 2, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1923 "syntax.tab.c"
    break;

  case 56: /* Expr: LP Expr RP  */
#line 172 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1929 "syntax.tab.c"
    break;

  case 57: /* Expr: Expr ASSIGNOP Expr  */
#line 173 "syntax.y"
                                                                             {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1935 "syntax.tab.c"
    break;

  case 58: /* Expr: Expr RELOP Expr  */
#line 174 "syntax.y"
                                                                        {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1941 "syntax.tab.c"
    break;

  case 59: /* Expr: Expr AND Expr  */
#line 175 "syntax.y"
                                                                        {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1947 "syntax.tab.c"
    break;

  case 60: /* Expr: Expr OR Expr  */
#line 176 "syntax.y"
                                                                        {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1953 "syntax.tab.c"
    break;

  case 61: /* Expr: Expr PLUS Expr  */
#line 177 "syntax.y"
                                                                            {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1959 "syntax.tab.c"
    break;

  case 62: /* Expr: Expr MINUS Expr  */
#line 178 "syntax.y"
                                                                            {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1965 "syntax.tab.c"
    break;

  case 63: /* Expr: Expr STAR Expr  */
#line 179 "syntax.y"
                                                                              {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1971 "syntax.tab.c"
    break;

  case 64: /* Expr: Expr DIV Expr  */
#line 180 "syntax.y"
                                                                              {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1977 "syntax.tab.c"
    break;

  case 65: /* Expr: ID  */
#line 181 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 1, (yyvsp[0].node));   }
#line 1983 "syntax.tab.c"
    break;

  case 66: /* Expr: INT  */
#line 182 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 1, (yyvsp[0].node));   }
#line 1989 "syntax.tab.c"
    break;

  case 67: /* Args: Expr COMMA Args  */
#line 184 "syntax.y"
                                                                                { (yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Args", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1995 "syntax.tab.c"
    break;

  case 68: /* Args: Expr  */
#line 185 "syntax.y"
                                                                                { (yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Args", 1, (yyvsp[0].node)); }
#line 2001 "syntax.tab.c"
    break;


#line 2005 "syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 187 "syntax.y"



// void yyreport_syntax_errors(void) {
//         if (yychar == YYEMPTY) {
//             // 如果没有 token 被输入，输出错误信息
//             fprintf(stderr, "Syntax error: unexpected end of input.\n");
//         } else {
//             // 打印当前 token 的错误信息
//             printf("%d\n", yychar);
//             fprintf(stderr, "Syntax error: unexpected token '%s'.\n", yytname[yychar - 255]); //255是FIRST_TOKEN, yychar是lookahead token

//             // 输出期望的符号
//             if (YYNTOKENS > 0) {
//                 fprintf(stderr, "Expecting: ");
//                 for (int i = 0; i < YYNTOKENS; i++) {
//                     if (yycheck[i + yystate] == yystate) {
//                         fprintf(stderr, "%s ", yytname[i]);
//                     }
//                 }
//                 fprintf(stderr, "\n");
//             }
//         }
// }




