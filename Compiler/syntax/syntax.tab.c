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
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_Program = 35,                   /* Program  */
  YYSYMBOL_CodeDec = 36,                   /* CodeDec  */
  YYSYMBOL_MainDec = 37,                   /* MainDec  */
  YYSYMBOL_FunDec = 38,                    /* FunDec  */
  YYSYMBOL_VarList = 39,                   /* VarList  */
  YYSYMBOL_ExtDecList = 40,                /* ExtDecList  */
  YYSYMBOL_FunBody = 41,                   /* FunBody  */
  YYSYMBOL_Specifier = 42,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 43,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 44,                    /* OptTag  */
  YYSYMBOL_Tag = 45,                       /* Tag  */
  YYSYMBOL_DefList = 46,                   /* DefList  */
  YYSYMBOL_Def = 47,                       /* Def  */
  YYSYMBOL_DecList = 48,                   /* DecList  */
  YYSYMBOL_Dec = 49,                       /* Dec  */
  YYSYMBOL_VarDec = 50,                    /* VarDec  */
  YYSYMBOL_StatList = 51,                  /* StatList  */
  YYSYMBOL_Statements = 52,                /* Statements  */
  YYSYMBOL_IfStat = 53,                    /* IfStat  */
  YYSYMBOL_ElseStat = 54,                  /* ElseStat  */
  YYSYMBOL_WhileStat = 55,                 /* WhileStat  */
  YYSYMBOL_ForStat = 56,                   /* ForStat  */
  YYSYMBOL_WriteStat = 57,                 /* WriteStat  */
  YYSYMBOL_ReadStat = 58,                  /* ReadStat  */
  YYSYMBOL_CompoundStat = 59,              /* CompoundStat  */
  YYSYMBOL_ExprStat = 60,                  /* ExprStat  */
  YYSYMBOL_CallStat = 61,                  /* CallStat  */
  YYSYMBOL_Expr = 62,                      /* Expr  */
  YYSYMBOL_Bool_Expr = 63,                 /* Bool_Expr  */
  YYSYMBOL_Add_Expr = 64,                  /* Add_Expr  */
  YYSYMBOL_term = 65,                      /* term  */
  YYSYMBOL_factor = 66                     /* factor  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    89,    90,    91,    92,    93,    95,    96,
      98,    99,   101,   102,   104,   105,   107,   108,   111,   112,
     114,   115,   117,   118,   120,   124,   125,   127,   129,   130,
     132,   133,   135,   136,   137,   138,   143,   144,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   156,   157,   159,
     161,   163,   165,   167,   169,   170,   172,   173,   174,   175,
     177,   178,   181,   182,   184,   185,   186,   187,   188,   190,
     191,   192,   194,   195,   196,   198,   199,   200
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
  "$accept", "Program", "CodeDec", "MainDec", "FunDec", "VarList",
  "ExtDecList", "FunBody", "Specifier", "StructSpecifier", "OptTag", "Tag",
  "DefList", "Def", "DecList", "Dec", "VarDec", "StatList", "Statements",
  "IfStat", "ElseStat", "WhileStat", "ForStat", "WriteStat", "ReadStat",
  "CompoundStat", "ExprStat", "CallStat", "Expr", "Bool_Expr", "Add_Expr",
  "term", "factor", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,     5,   -60,    11,    28,   -60,     3,   -60,   -60,    -2,
      45,   -60,   -60,   100,     5,    32,   -60,     5,    72,    56,
      20,   -60,    54,   -60,    64,   -60,     5,    70,    76,    70,
      80,    20,    12,    71,    70,    12,    86,   -60,    94,   -60,
      95,    98,    99,   115,     6,   -60,   -60,   104,    20,   -60,
      12,    66,   -60,    12,   -60,   -60,   -60,    70,   106,   -60,
      34,   -60,    20,   -60,   -60,   -60,   121,    14,    14,   -60,
     -60,   128,   132,   -60,   109,   -60,    34,   120,   135,   137,
     106,   106,   129,   150,   133,    34,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   114,   -60,   108,   -60,   136,   123,
      14,    14,    14,    14,    14,    14,    14,   -60,   -60,   -60,
     134,   106,   106,   106,   151,   -60,   -60,   140,   -60,   -60,
     -60,   -60,   -60,   -60,   136,   132,   132,   136,   136,   -60,
     -60,   -60,   141,   142,   154,   -60,   144,    67,    67,   106,
     -60,   139,   -60,   157,    67,   -60,   106,   -60,   147,    67,
     -60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    18,    23,     0,     2,     0,    19,     7,    24,
       0,    21,     1,     0,     0,     0,     3,     0,     0,    14,
      26,    34,     0,     6,     0,     4,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     5,     0,    15,
       0,     0,     0,    28,    30,    20,    25,     0,    26,    11,
       0,    12,     9,     0,    35,    33,    27,     0,     0,    17,
       0,    10,     0,     8,    29,    77,    76,     0,     0,    31,
      63,    64,    69,    72,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    42,
      41,    43,    44,    45,     0,    13,     0,    76,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    61,    55,
       0,     0,     0,     0,     0,    52,    53,     0,    16,    36,
      59,    56,    62,    75,    65,    70,    71,    66,    67,    73,
      74,    54,     0,     0,     0,    46,     0,     0,     0,     0,
      60,    48,    50,     0,     0,    47,     0,    49,     0,     0,
      51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,    13,   -60,   -60,   -22,   143,    -4,   -19,   -60,
     -60,   -60,   -27,   -60,   110,   -60,   -10,     2,    -8,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -58,    73,
     -59,    48,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,    16,    17,    33,    18,    49,     6,     7,
      10,    11,    30,    31,    42,    43,    19,    84,    85,    86,
     145,    87,    88,    89,    90,    91,    92,    93,    94,    70,
      71,    72,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    29,    36,    34,    46,    34,     1,    13,    98,    99,
       2,    14,    29,    47,     8,     9,    58,    65,    97,    44,
     -22,    60,   114,   115,    51,     2,    28,    23,    12,    29,
      25,    52,    68,     3,    48,    74,    15,    65,    66,    37,
      95,   124,    75,    34,   127,   128,    61,    44,     3,    63,
      24,    67,    68,   132,   133,   134,    76,   -37,    77,     2,
      78,    79,    27,    80,    81,    82,    83,    20,    74,     2,
      65,    66,    62,    32,    38,    75,    28,    40,   110,    41,
      26,   143,     3,    35,    67,    68,    28,   119,   148,    76,
      50,    77,     3,    78,    79,    21,    80,    81,    82,    83,
     -32,    21,   -32,    45,   -32,    53,   -32,    56,   -32,    65,
      66,    65,    97,   -32,   -32,   120,    54,   107,    22,    55,
     -32,    57,   121,    67,    68,    67,    68,    59,   108,   141,
     142,    96,   109,   116,   101,   102,   147,   100,   111,   101,
     102,   150,   123,   103,   104,   105,   106,   101,   102,   125,
     126,   129,   130,   112,   117,   113,   118,   131,   136,   135,
     137,   138,   139,   140,   144,   146,   149,    64,     0,   122,
      39
};

static const yytype_int16 yycheck[] =
{
      58,    20,    24,    22,    31,    24,     1,     4,    67,    68,
       5,     8,    31,     1,     1,     4,    10,     3,     4,    29,
      22,    48,    80,    81,    34,     5,    20,    14,     0,    48,
      17,    35,    18,    28,    22,     1,    33,     3,     4,    26,
      62,   100,     8,    62,   103,   104,    50,    57,    28,    53,
      18,    17,    18,   111,   112,   113,    22,    23,    24,     5,
      26,    27,     6,    29,    30,    31,    32,    22,     1,     5,
       3,     4,     6,    19,     4,     8,    20,     1,    76,     3,
       8,   139,    28,    19,    17,    18,    20,    85,   146,    22,
      19,    24,    28,    26,    27,     1,    29,    30,    31,    32,
       6,     1,     8,    23,    10,    19,     6,     8,     8,     3,
       4,     3,     4,    19,    20,     1,    21,     8,    18,    21,
      20,     6,     8,    17,    18,    17,    18,    23,    19,   137,
     138,    10,    23,     4,    11,    12,   144,     9,    18,    11,
      12,   149,    19,    15,    16,    13,    14,    11,    12,   101,
     102,   105,   106,    18,     4,    18,    23,    23,    18,     8,
      19,    19,     8,    19,    25,     8,    19,    57,    -1,    96,
      27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,    28,    35,    36,    42,    43,    36,     4,
      44,    45,     0,     4,     8,    33,    37,    38,    40,    50,
      22,     1,    18,    36,    18,    36,     8,     6,    20,    42,
      46,    47,    19,    39,    42,    19,    39,    36,     4,    40,
       1,     3,    48,    49,    50,    23,    46,     1,    22,    41,
      19,    50,    41,    19,    21,    21,     8,     6,    10,    23,
      46,    41,     6,    41,    48,     3,     4,    17,    18,    62,
      63,    64,    65,    66,     1,     8,    22,    24,    26,    27,
      29,    30,    31,    32,    51,    52,    53,    55,    56,    57,
      58,    59,    60,    61,    62,    39,    10,     4,    64,    64,
       9,    11,    12,    15,    16,    13,    14,     8,    19,    23,
      51,    18,    18,    18,    62,    62,     4,     4,    23,    51,
       1,     8,    63,    19,    64,    65,    65,    64,    64,    66,
      66,    23,    62,    62,    62,     8,    18,    19,    19,     8,
      19,    52,    52,    62,    25,    54,     8,    52,    62,    19,
      52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    36,    36,    36,    37,    37,
      38,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    46,    46,    47,    48,    48,
      49,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      55,    56,    57,    58,    59,    59,    60,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    64,
      64,    64,    65,    65,    65,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     4,     3,     2,     5,     4,
       5,     4,     2,     4,     1,     3,     4,     2,     1,     1,
       5,     2,     1,     0,     1,     2,     0,     3,     1,     3,
       1,     3,     1,     4,     2,     4,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     5,     2,
       5,     9,     2,     2,     3,     2,     2,     1,     2,     2,
       4,     2,     3,     1,     1,     3,     3,     3,     2,     1,
       3,     3,     1,     3,     3,     3,     1,     1
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
  case 2: /* Program: CodeDec  */
#line 87 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Program", 1, (yyvsp[0].node)); root = (yyval.node); }
#line 1592 "syntax.tab.c"
    break;

  case 3: /* CodeDec: Specifier MainDec  */
#line 89 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "CodeDec", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1598 "syntax.tab.c"
    break;

  case 4: /* CodeDec: Specifier FunDec CodeDec  */
#line 90 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "CodeDec", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1604 "syntax.tab.c"
    break;

  case 5: /* CodeDec: Specifier ExtDecList SEMI CodeDec  */
#line 91 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "CodeDec", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1610 "syntax.tab.c"
    break;

  case 6: /* CodeDec: Specifier SEMI CodeDec  */
#line 92 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "CodeDec", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1616 "syntax.tab.c"
    break;

  case 7: /* CodeDec: error CodeDec  */
#line 93 "syntax.y"
                                                                                {synError = TRUE;  fprintf(stderr, "Functions need to declare types\n");}
#line 1622 "syntax.tab.c"
    break;

  case 8: /* MainDec: MAIN LP VarList RP FunBody  */
#line 95 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "MainDec", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1628 "syntax.tab.c"
    break;

  case 9: /* MainDec: MAIN LP RP FunBody  */
#line 96 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "FunDec", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1634 "syntax.tab.c"
    break;

  case 10: /* FunDec: ID LP VarList RP FunBody  */
#line 98 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "FunDec", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1640 "syntax.tab.c"
    break;

  case 11: /* FunDec: ID LP RP FunBody  */
#line 99 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "FunDec", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1646 "syntax.tab.c"
    break;

  case 12: /* VarList: Specifier VarDec  */
#line 101 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "FunDec", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1652 "syntax.tab.c"
    break;

  case 13: /* VarList: Specifier VarDec COMMA VarList  */
#line 102 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "FunDec", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1658 "syntax.tab.c"
    break;

  case 14: /* ExtDecList: VarDec  */
#line 104 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ExtDecList", 1, (yyvsp[0].node)); }
#line 1664 "syntax.tab.c"
    break;

  case 15: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 105 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ExtDecList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1670 "syntax.tab.c"
    break;

  case 16: /* FunBody: LC DefList StatList RC  */
#line 107 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "FunBody", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1676 "syntax.tab.c"
    break;

  case 17: /* FunBody: error RC  */
#line 108 "syntax.y"
                                                                                {synError = TRUE;  }
#line 1682 "syntax.tab.c"
    break;

  case 18: /* Specifier: TYPE  */
#line 111 "syntax.y"
                                                                                 {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Specifier", 1, (yyvsp[0].node));  }
#line 1688 "syntax.tab.c"
    break;

  case 19: /* Specifier: StructSpecifier  */
#line 112 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Specifier", 1, (yyvsp[0].node));  }
#line 1694 "syntax.tab.c"
    break;

  case 20: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 114 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "StructSpecifier", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1700 "syntax.tab.c"
    break;

  case 21: /* StructSpecifier: STRUCT Tag  */
#line 115 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "StructSpecifier", 2, (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1706 "syntax.tab.c"
    break;

  case 22: /* OptTag: ID  */
#line 117 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "OptTag", 1, (yyvsp[0].node));  }
#line 1712 "syntax.tab.c"
    break;

  case 23: /* OptTag: %empty  */
#line 118 "syntax.y"
                                                                                {(yyval.node) = NULL ;}
#line 1718 "syntax.tab.c"
    break;

  case 24: /* Tag: ID  */
#line 120 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Tag", 1, (yyvsp[0].node));  }
#line 1724 "syntax.tab.c"
    break;

  case 25: /* DefList: Def DefList  */
#line 124 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "DefList", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1730 "syntax.tab.c"
    break;

  case 26: /* DefList: %empty  */
#line 125 "syntax.y"
                                                                                {(yyval.node) = NULL; }
#line 1736 "syntax.tab.c"
    break;

  case 27: /* Def: Specifier DecList SEMI  */
#line 127 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Def", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1742 "syntax.tab.c"
    break;

  case 28: /* DecList: Dec  */
#line 129 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "DecList", 1, (yyvsp[0].node));  }
#line 1748 "syntax.tab.c"
    break;

  case 29: /* DecList: Dec COMMA DecList  */
#line 130 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "DecList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1754 "syntax.tab.c"
    break;

  case 30: /* Dec: VarDec  */
#line 132 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Dec", 1, (yyvsp[0].node));  }
#line 1760 "syntax.tab.c"
    break;

  case 31: /* Dec: VarDec ASSIGNOP Expr  */
#line 133 "syntax.y"
                                                                                    {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Dec", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1766 "syntax.tab.c"
    break;

  case 32: /* VarDec: ID  */
#line 135 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "VarDec", 1, (yyvsp[0].node)); }
#line 1772 "syntax.tab.c"
    break;

  case 33: /* VarDec: VarDec LB INT RB  */
#line 136 "syntax.y"
                                                                                  {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "VarDec", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));  }
#line 1778 "syntax.tab.c"
    break;

  case 34: /* VarDec: ID error  */
#line 137 "syntax.y"
                                                                                {synError = TRUE;}
#line 1784 "syntax.tab.c"
    break;

  case 35: /* VarDec: VarDec LB error RB  */
#line 138 "syntax.y"
                                                                                {synError = TRUE;  fprintf(stderr, "Integer declarations are required in square brackets\n");}
#line 1790 "syntax.tab.c"
    break;

  case 36: /* StatList: Statements StatList  */
#line 143 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "StatList", 2, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1796 "syntax.tab.c"
    break;

  case 37: /* StatList: %empty  */
#line 144 "syntax.y"
                                                                                {(yyval.node) = NULL;}
#line 1802 "syntax.tab.c"
    break;

  case 38: /* Statements: IfStat  */
#line 146 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[0].node));   }
#line 1808 "syntax.tab.c"
    break;

  case 39: /* Statements: WhileStat  */
#line 147 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[0].node));   }
#line 1814 "syntax.tab.c"
    break;

  case 40: /* Statements: ForStat  */
#line 148 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[0].node));   }
#line 1820 "syntax.tab.c"
    break;

  case 41: /* Statements: ReadStat  */
#line 149 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[0].node));   }
#line 1826 "syntax.tab.c"
    break;

  case 42: /* Statements: WriteStat  */
#line 150 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[0].node));   }
#line 1832 "syntax.tab.c"
    break;

  case 43: /* Statements: CompoundStat  */
#line 151 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[0].node));   }
#line 1838 "syntax.tab.c"
    break;

  case 44: /* Statements: ExprStat  */
#line 152 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[0].node));   }
#line 1844 "syntax.tab.c"
    break;

  case 45: /* Statements: CallStat  */
#line 153 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 1, (yyvsp[0].node));   }
#line 1850 "syntax.tab.c"
    break;

  case 46: /* Statements: RETURN Expr SEMI  */
#line 154 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Statements", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1856 "syntax.tab.c"
    break;

  case 47: /* IfStat: IF LP Expr RP Statements ElseStat  */
#line 156 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "IfStat", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1862 "syntax.tab.c"
    break;

  case 48: /* IfStat: IF LP Expr RP Statements  */
#line 157 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "IfStat", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1868 "syntax.tab.c"
    break;

  case 49: /* ElseStat: ELSE Statements  */
#line 159 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ElseStat", 2, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1874 "syntax.tab.c"
    break;

  case 50: /* WhileStat: WHILE LP Expr RP Statements  */
#line 161 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "WhileStat", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1880 "syntax.tab.c"
    break;

  case 51: /* ForStat: FOR LP Expr SEMI Expr SEMI Expr RP Statements  */
#line 163 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ForStat", 9, (yyvsp[-8].node), (yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1886 "syntax.tab.c"
    break;

  case 52: /* WriteStat: WRITE Expr  */
#line 165 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "WriteStat", 2, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1892 "syntax.tab.c"
    break;

  case 53: /* ReadStat: READ ID  */
#line 167 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ReadStat", 2, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1898 "syntax.tab.c"
    break;

  case 54: /* CompoundStat: LC StatList RC  */
#line 169 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "CompoundStat", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1904 "syntax.tab.c"
    break;

  case 55: /* CompoundStat: error RC  */
#line 170 "syntax.y"
                                                                                {synError = TRUE;}
#line 1910 "syntax.tab.c"
    break;

  case 56: /* ExprStat: Expr SEMI  */
#line 172 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ExprStat", 2, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1916 "syntax.tab.c"
    break;

  case 57: /* ExprStat: SEMI  */
#line 173 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "ExprStat", 1, (yyvsp[0].node));   }
#line 1922 "syntax.tab.c"
    break;

  case 58: /* ExprStat: error SEMI  */
#line 174 "syntax.y"
                                                                                {synError = TRUE;}
#line 1928 "syntax.tab.c"
    break;

  case 59: /* ExprStat: Expr error  */
#line 175 "syntax.y"
                                                                                {synError = TRUE; fprintf(stderr, "Statements need to end with a semicolon\n");}
#line 1934 "syntax.tab.c"
    break;

  case 60: /* CallStat: CALL ID LP RP  */
#line 177 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "CallStat", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1940 "syntax.tab.c"
    break;

  case 61: /* CallStat: error RP  */
#line 178 "syntax.y"
                                                                                {synError = TRUE; }
#line 1946 "syntax.tab.c"
    break;

  case 62: /* Expr: ID ASSIGNOP Bool_Expr  */
#line 181 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1952 "syntax.tab.c"
    break;

  case 63: /* Expr: Bool_Expr  */
#line 182 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Expr", 1, (yyvsp[0].node));   }
#line 1958 "syntax.tab.c"
    break;

  case 64: /* Bool_Expr: Add_Expr  */
#line 184 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Bool_Expr", 1, (yyvsp[0].node));   }
#line 1964 "syntax.tab.c"
    break;

  case 65: /* Bool_Expr: Add_Expr RELOP Add_Expr  */
#line 185 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Bool_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1970 "syntax.tab.c"
    break;

  case 66: /* Bool_Expr: Add_Expr AND Add_Expr  */
#line 186 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Bool_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1976 "syntax.tab.c"
    break;

  case 67: /* Bool_Expr: Add_Expr OR Add_Expr  */
#line 187 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Bool_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1982 "syntax.tab.c"
    break;

  case 68: /* Bool_Expr: NOT Add_Expr  */
#line 188 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Bool_Expr", 2, (yyvsp[-1].node), (yyvsp[0].node));   }
#line 1988 "syntax.tab.c"
    break;

  case 69: /* Add_Expr: term  */
#line 190 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Add_Expr", 1, (yyvsp[0].node));   }
#line 1994 "syntax.tab.c"
    break;

  case 70: /* Add_Expr: Add_Expr PLUS term  */
#line 191 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Add_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 2000 "syntax.tab.c"
    break;

  case 71: /* Add_Expr: Add_Expr MINUS term  */
#line 192 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "Add_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 2006 "syntax.tab.c"
    break;

  case 72: /* term: factor  */
#line 194 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "term", 1, (yyvsp[0].node));   }
#line 2012 "syntax.tab.c"
    break;

  case 73: /* term: term STAR factor  */
#line 195 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "term", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 2018 "syntax.tab.c"
    break;

  case 74: /* term: term DIV factor  */
#line 196 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "term", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 2024 "syntax.tab.c"
    break;

  case 75: /* factor: LP Add_Expr RP  */
#line 198 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "factor", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));   }
#line 2030 "syntax.tab.c"
    break;

  case 76: /* factor: ID  */
#line 199 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "factor", 1, (yyvsp[0].node));   }
#line 2036 "syntax.tab.c"
    break;

  case 77: /* factor: INT  */
#line 200 "syntax.y"
                                                                                {(yyval.node) = createNode((yyloc).first_line, NOT_A_TOKEN, "factor", 1, (yyvsp[0].node));   }
#line 2042 "syntax.tab.c"
    break;


#line 2046 "syntax.tab.c"

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

#line 202 "syntax.y"



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




