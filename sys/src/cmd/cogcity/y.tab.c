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
#line 1 "grammar.y"

/*
 * Cognitive Cities Grammar - YACC Grammar Definition
 * Defines the cognitive grammar for interacting with the network as an LLM
 */
#include "cogcity.h"

extern CognitiveCity *global_cognitive_city;
int yyerror(char *s);
int yylex(void);

/* Function prototypes for grammar actions */
void* create_hypergraph_query(char *target);
void* create_namespace_query(char *target);  
void* create_tensor_query(char *target);
void* create_inference_confidence_query(void);
void* create_hypergraph_modification(char *target);
void* create_namespace_partition_modification(char *target);
void* create_tensor_multiplex_operation(char *target);
void* create_tensor_demultiplex_operation(char *target);
void* create_namespace_creation(char *target);
void* create_tensor_channel_creation(int count);
void* create_fibration_partition(char *target);
void* create_inference_reasoning(char *target);
void* create_chat_message(char *message);
void* create_directed_chat(char *target, char *message);
void* create_resource_optimization(void);
void* create_targeted_resource_optimization(char *target);
void* create_zero_security_optimization(void);
char* concatenate_identifiers(char *id1, char *id2);
void execute_cognitive_command(char *type, void *command);


#line 105 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    STRING = 259,                  /* STRING  */
    NUMBER = 260,                  /* NUMBER  */
    FLOAT = 261,                   /* FLOAT  */
    QUERY = 262,                   /* QUERY  */
    MODIFY = 263,                  /* MODIFY  */
    CREATE = 264,                  /* CREATE  */
    DESTROY = 265,                 /* DESTROY  */
    NAMESPACE = 266,               /* NAMESPACE  */
    CHANNEL = 267,                 /* CHANNEL  */
    TENSOR = 268,                  /* TENSOR  */
    INFERENCE = 269,               /* INFERENCE  */
    TRANSFORM = 270,               /* TRANSFORM  */
    PARTITION = 271,               /* PARTITION  */
    FIBRATION = 272,               /* FIBRATION  */
    HYPERGRAPH = 273,              /* HYPERGRAPH  */
    CHAT = 274,                    /* CHAT  */
    WITH = 275,                    /* WITH  */
    IN = 276,                      /* IN  */
    ON = 277,                      /* ON  */
    FOR = 278,                     /* FOR  */
    OPTIMIZE = 279,                /* OPTIMIZE  */
    RESOURCES = 280,               /* RESOURCES  */
    ACTIVATE = 281,                /* ACTIVATE  */
    DEACTIVATE = 282,              /* DEACTIVATE  */
    MULTIPLEX = 283,               /* MULTIPLEX  */
    DEMULTIPLEX = 284,             /* DEMULTIPLEX  */
    BROADCAST = 285,               /* BROADCAST  */
    REASONING = 286,               /* REASONING  */
    CONFIDENCE = 287,              /* CONFIDENCE  */
    THRESHOLD = 288,               /* THRESHOLD  */
    ZERO_SECURITY = 289,           /* ZERO_SECURITY  */
    EXECUTION = 290,               /* EXECUTION  */
    ENVIRONMENT = 291              /* ENVIRONMENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define FLOAT 261
#define QUERY 262
#define MODIFY 263
#define CREATE 264
#define DESTROY 265
#define NAMESPACE 266
#define CHANNEL 267
#define TENSOR 268
#define INFERENCE 269
#define TRANSFORM 270
#define PARTITION 271
#define FIBRATION 272
#define HYPERGRAPH 273
#define CHAT 274
#define WITH 275
#define IN 276
#define ON 277
#define FOR 278
#define OPTIMIZE 279
#define RESOURCES 280
#define ACTIVATE 281
#define DEACTIVATE 282
#define MULTIPLEX 283
#define DEMULTIPLEX 284
#define BROADCAST 285
#define REASONING 286
#define CONFIDENCE 287
#define THRESHOLD 288
#define ZERO_SECURITY 289
#define EXECUTION 290
#define ENVIRONMENT 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "grammar.y"

    char *str;
    int num;
    double dval;
    void *ptr;

#line 237 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_QUERY = 7,                      /* QUERY  */
  YYSYMBOL_MODIFY = 8,                     /* MODIFY  */
  YYSYMBOL_CREATE = 9,                     /* CREATE  */
  YYSYMBOL_DESTROY = 10,                   /* DESTROY  */
  YYSYMBOL_NAMESPACE = 11,                 /* NAMESPACE  */
  YYSYMBOL_CHANNEL = 12,                   /* CHANNEL  */
  YYSYMBOL_TENSOR = 13,                    /* TENSOR  */
  YYSYMBOL_INFERENCE = 14,                 /* INFERENCE  */
  YYSYMBOL_TRANSFORM = 15,                 /* TRANSFORM  */
  YYSYMBOL_PARTITION = 16,                 /* PARTITION  */
  YYSYMBOL_FIBRATION = 17,                 /* FIBRATION  */
  YYSYMBOL_HYPERGRAPH = 18,                /* HYPERGRAPH  */
  YYSYMBOL_CHAT = 19,                      /* CHAT  */
  YYSYMBOL_WITH = 20,                      /* WITH  */
  YYSYMBOL_IN = 21,                        /* IN  */
  YYSYMBOL_ON = 22,                        /* ON  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_OPTIMIZE = 24,                  /* OPTIMIZE  */
  YYSYMBOL_RESOURCES = 25,                 /* RESOURCES  */
  YYSYMBOL_ACTIVATE = 26,                  /* ACTIVATE  */
  YYSYMBOL_DEACTIVATE = 27,                /* DEACTIVATE  */
  YYSYMBOL_MULTIPLEX = 28,                 /* MULTIPLEX  */
  YYSYMBOL_DEMULTIPLEX = 29,               /* DEMULTIPLEX  */
  YYSYMBOL_BROADCAST = 30,                 /* BROADCAST  */
  YYSYMBOL_REASONING = 31,                 /* REASONING  */
  YYSYMBOL_CONFIDENCE = 32,                /* CONFIDENCE  */
  YYSYMBOL_THRESHOLD = 33,                 /* THRESHOLD  */
  YYSYMBOL_ZERO_SECURITY = 34,             /* ZERO_SECURITY  */
  YYSYMBOL_EXECUTION = 35,                 /* EXECUTION  */
  YYSYMBOL_ENVIRONMENT = 36,               /* ENVIRONMENT  */
  YYSYMBOL_37_ = 37,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_cognitive_program = 39,         /* cognitive_program  */
  YYSYMBOL_cognitive_sentence = 40,        /* cognitive_sentence  */
  YYSYMBOL_query_command = 41,             /* query_command  */
  YYSYMBOL_modify_command = 42,            /* modify_command  */
  YYSYMBOL_create_command = 43,            /* create_command  */
  YYSYMBOL_chat_command = 44,              /* chat_command  */
  YYSYMBOL_optimize_command = 45,          /* optimize_command  */
  YYSYMBOL_target_specification = 46       /* target_specification  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   50

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  28
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  60

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,     2,     2,     2,     2,    37,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    62,    62,    63,    67,    68,    69,    70,    71,    75,
      77,    79,    81,    86,    88,    90,    92,    97,    99,   101,
     103,   108,   110,   115,   117,   119,   124,   125,   126
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "STRING",
  "NUMBER", "FLOAT", "QUERY", "MODIFY", "CREATE", "DESTROY", "NAMESPACE",
  "CHANNEL", "TENSOR", "INFERENCE", "TRANSFORM", "PARTITION", "FIBRATION",
  "HYPERGRAPH", "CHAT", "WITH", "IN", "ON", "FOR", "OPTIMIZE", "RESOURCES",
  "ACTIVATE", "DEACTIVATE", "MULTIPLEX", "DEMULTIPLEX", "BROADCAST",
  "REASONING", "CONFIDENCE", "THRESHOLD", "ZERO_SECURITY", "EXECUTION",
  "ENVIRONMENT", "'.'", "$accept", "cognitive_program",
  "cognitive_sentence", "query_command", "modify_command",
  "create_command", "chat_command", "optimize_command",
  "target_specification", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -27,    22,   -27,    -6,     0,    23,   -14,    -3,   -21,   -27,
     -27,   -27,   -27,   -27,   -27,    17,    15,   -26,    17,    -7,
      17,    17,    20,     2,    26,    27,    31,   -27,    17,    24,
       3,     7,   -27,   -27,    17,   -27,   -27,    17,   -27,   -27,
      42,    17,    17,    17,    17,    44,    17,    13,    47,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,    23,
       0,    26,    27,    10,     0,    12,     9,     0,    13,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      14,    18,    20,    19,    15,    16,    22,    24,    25,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     9,    10,    11,    12,    13,    14,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    27,    38,    39,    29,    15,    35,    16,    17,    37,
      45,    19,    18,    30,    25,    26,    49,    28,    20,    50,
      31,    32,     2,    52,    53,    54,    55,    34,    57,     3,
       4,     5,    40,    41,    21,     6,    22,    23,    47,    43,
      24,     7,    42,    44,    48,    46,     8,    51,    56,    58,
      59
};

static const yytype_int8 yycheck[] =
{
      18,     4,    20,    21,    25,    11,    32,    13,    14,    16,
      28,    11,    18,    34,    28,    29,    34,    20,    18,    37,
       3,     4,     0,    41,    42,    43,    44,    12,    46,     7,
       8,     9,    12,    31,    11,    13,    13,    14,    35,    12,
      17,    19,    16,    12,    37,    21,    24,     5,     4,    36,
       3
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,     0,     7,     8,     9,    13,    19,    24,    40,
      41,    42,    43,    44,    45,    11,    13,    14,    18,    11,
      18,    11,    13,    14,    17,    28,    29,     4,    20,    25,
      34,     3,     4,    46,    12,    32,    46,    16,    46,    46,
      12,    31,    16,    12,    12,    46,    21,    35,    37,    46,
      46,     5,    46,    46,    46,    46,     4,    46,    36,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    40,    40,    40,    41,
      41,    41,    41,    42,    42,    42,    42,    43,    43,    43,
      43,    44,    44,    45,    45,    45,    46,    46,    46
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     3,
       3,     4,     3,     3,     4,     4,     4,     3,     4,     4,
       4,     2,     4,     2,     4,     4,     1,     1,     3
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* cognitive_sentence: query_command  */
#line 67 "grammar.y"
                        { execute_cognitive_command("query", (yyvsp[0].ptr)); }
#line 1291 "y.tab.c"
    break;

  case 5: /* cognitive_sentence: modify_command  */
#line 68 "grammar.y"
                        { execute_cognitive_command("modify", (yyvsp[0].ptr)); }
#line 1297 "y.tab.c"
    break;

  case 6: /* cognitive_sentence: create_command  */
#line 69 "grammar.y"
                        { execute_cognitive_command("create", (yyvsp[0].ptr)); }
#line 1303 "y.tab.c"
    break;

  case 7: /* cognitive_sentence: chat_command  */
#line 70 "grammar.y"
                        { execute_cognitive_command("chat", (yyvsp[0].ptr)); }
#line 1309 "y.tab.c"
    break;

  case 8: /* cognitive_sentence: optimize_command  */
#line 71 "grammar.y"
                        { execute_cognitive_command("optimize", (yyvsp[0].ptr)); }
#line 1315 "y.tab.c"
    break;

  case 9: /* query_command: QUERY HYPERGRAPH target_specification  */
#line 76 "grammar.y"
        { (yyval.ptr) = create_hypergraph_query((yyvsp[0].str)); }
#line 1321 "y.tab.c"
    break;

  case 10: /* query_command: QUERY NAMESPACE target_specification  */
#line 78 "grammar.y"
        { (yyval.ptr) = create_namespace_query((yyvsp[0].str)); }
#line 1327 "y.tab.c"
    break;

  case 11: /* query_command: QUERY TENSOR CHANNEL target_specification  */
#line 80 "grammar.y"
        { (yyval.ptr) = create_tensor_query((yyvsp[0].str)); }
#line 1333 "y.tab.c"
    break;

  case 12: /* query_command: QUERY INFERENCE CONFIDENCE  */
#line 82 "grammar.y"
        { (yyval.ptr) = create_inference_confidence_query(); }
#line 1339 "y.tab.c"
    break;

  case 13: /* modify_command: MODIFY HYPERGRAPH target_specification  */
#line 87 "grammar.y"
        { (yyval.ptr) = create_hypergraph_modification((yyvsp[0].str)); }
#line 1345 "y.tab.c"
    break;

  case 14: /* modify_command: MODIFY NAMESPACE PARTITION target_specification  */
#line 89 "grammar.y"
        { (yyval.ptr) = create_namespace_partition_modification((yyvsp[0].str)); }
#line 1351 "y.tab.c"
    break;

  case 15: /* modify_command: TENSOR MULTIPLEX CHANNEL target_specification  */
#line 91 "grammar.y"
        { (yyval.ptr) = create_tensor_multiplex_operation((yyvsp[0].str)); }
#line 1357 "y.tab.c"
    break;

  case 16: /* modify_command: TENSOR DEMULTIPLEX CHANNEL target_specification  */
#line 93 "grammar.y"
        { (yyval.ptr) = create_tensor_demultiplex_operation((yyvsp[0].str)); }
#line 1363 "y.tab.c"
    break;

  case 17: /* create_command: CREATE NAMESPACE target_specification  */
#line 98 "grammar.y"
        { (yyval.ptr) = create_namespace_creation((yyvsp[0].str)); }
#line 1369 "y.tab.c"
    break;

  case 18: /* create_command: CREATE TENSOR CHANNEL NUMBER  */
#line 100 "grammar.y"
        { (yyval.ptr) = create_tensor_channel_creation((yyvsp[0].num)); }
#line 1375 "y.tab.c"
    break;

  case 19: /* create_command: CREATE FIBRATION PARTITION target_specification  */
#line 102 "grammar.y"
        { (yyval.ptr) = create_fibration_partition((yyvsp[0].str)); }
#line 1381 "y.tab.c"
    break;

  case 20: /* create_command: CREATE INFERENCE REASONING target_specification  */
#line 104 "grammar.y"
        { (yyval.ptr) = create_inference_reasoning((yyvsp[0].str)); }
#line 1387 "y.tab.c"
    break;

  case 21: /* chat_command: CHAT STRING  */
#line 109 "grammar.y"
        { (yyval.ptr) = create_chat_message((yyvsp[0].str)); }
#line 1393 "y.tab.c"
    break;

  case 22: /* chat_command: CHAT WITH target_specification STRING  */
#line 111 "grammar.y"
        { (yyval.ptr) = create_directed_chat((yyvsp[-1].str), (yyvsp[0].str)); }
#line 1399 "y.tab.c"
    break;

  case 23: /* optimize_command: OPTIMIZE RESOURCES  */
#line 116 "grammar.y"
        { (yyval.ptr) = create_resource_optimization(); }
#line 1405 "y.tab.c"
    break;

  case 24: /* optimize_command: OPTIMIZE RESOURCES IN target_specification  */
#line 118 "grammar.y"
        { (yyval.ptr) = create_targeted_resource_optimization((yyvsp[0].str)); }
#line 1411 "y.tab.c"
    break;

  case 25: /* optimize_command: OPTIMIZE ZERO_SECURITY EXECUTION ENVIRONMENT  */
#line 120 "grammar.y"
        { (yyval.ptr) = create_zero_security_optimization(); }
#line 1417 "y.tab.c"
    break;

  case 26: /* target_specification: IDENTIFIER  */
#line 124 "grammar.y"
                        { (yyval.str) = (yyvsp[0].str); }
#line 1423 "y.tab.c"
    break;

  case 27: /* target_specification: STRING  */
#line 125 "grammar.y"
                        { (yyval.str) = (yyvsp[0].str); }
#line 1429 "y.tab.c"
    break;

  case 28: /* target_specification: IDENTIFIER '.' IDENTIFIER  */
#line 127 "grammar.y"
        { (yyval.str) = concatenate_identifiers((yyvsp[-2].str), (yyvsp[0].str)); }
#line 1435 "y.tab.c"
    break;


#line 1439 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 130 "grammar.y"


int yyerror(char *s) {
    fprint(2, "Cognitive Grammar Error: %s\n", s);
    return 0;
}

/* Cognitive command execution functions */
void* create_hypergraph_query(char *target) {
    if (!global_cognitive_city || !global_cognitive_city->network) {
        return nil;
    }
    
    print("🧠 Querying hypergraph structure for: %s\n", target);
    global_cognitive_city->network->query_structure(global_cognitive_city->network, target);
    return target;
}

void* create_namespace_query(char *target) {
    print("🔍 Analyzing namespace topology: %s\n", target);
    // Implementation for namespace queries
    return target;
}

void* create_tensor_query(char *target) {
    print("🎯 Examining tensor bundle channels: %s\n", target);
    // Implementation for tensor channel queries
    return target;
}

void* create_inference_confidence_query(void) {
    if (!global_cognitive_city || !global_cognitive_city->inference) {
        return nil;
    }
    
    print("🤔 Current inference confidence: %.2f\n", 
          global_cognitive_city->inference->confidence_threshold);
    return nil;
}

void* create_hypergraph_modification(char *target) {
    if (!global_cognitive_city || !global_cognitive_city->network) {
        return nil;
    }
    
    print("⚡ Modifying hypergraph topology: %s\n", target);
    global_cognitive_city->network->modify_topology(global_cognitive_city->network, target);
    return target;
}

void* create_namespace_partition_modification(char *target) {
    print("🏗️  Restructuring namespace partitions: %s\n", target);
    if (global_cognitive_city && global_cognitive_city->topology_resolver) {
        global_cognitive_city->topology_resolver->resolve_partition(
            global_cognitive_city->topology_resolver, target);
    }
    return target;
}

void* create_tensor_multiplex_operation(char *target) {
    print("📡 Multiplexing tensor bundle channels: %s\n", target);
    // Find the appropriate tensor bundle and perform multiplexing
    return target;
}

void* create_tensor_demultiplex_operation(char *target) {
    print("📡 Demultiplexing tensor bundle channels: %s\n", target);
    // Find the appropriate tensor bundle and perform demultiplexing
    return target;
}

void* create_namespace_creation(char *target) {
    print("🌟 Creating new namespace: %s\n", target);
    // Implementation for namespace creation
    return target;
}

void* create_tensor_channel_creation(int count) {
    print("🔗 Creating %d tensor channels\n", count);
    // Implementation for tensor channel creation
    return nil;
}

void* create_fibration_partition(char *target) {
    print("🌐 Creating Hopf fibration partition: %s\n", target);
    // Implementation for fibration partition creation
    return target;
}

void* create_inference_reasoning(char *target) {
    print("🧮 Initializing inference reasoning: %s\n", target);
    // Implementation for inference reasoning creation
    return target;
}

void* create_chat_message(char *message) {
    print("💬 Broadcasting: %s\n", message);
    if (global_cognitive_city) {
        global_cognitive_city->process_citizen_request(global_cognitive_city, message);
    }
    return message;
}

void* create_directed_chat(char *target, char *message) {
    print("💬 Message to %s: %s\n", target, message);
    // Implementation for directed chat
    return message;
}

void* create_resource_optimization(void) {
    print("⚡ Optimizing cognitive city resources\n");
    if (global_cognitive_city) {
        global_cognitive_city->optimize_resources(global_cognitive_city);
    }
    return nil;
}

void* create_targeted_resource_optimization(char *target) {
    print("⚡ Optimizing resources in: %s\n", target);
    // Implementation for targeted resource optimization
    return target;
}

void* create_zero_security_optimization(void) {
    print("🔓 Optimizing zero-security execution environment\n");
    // Implementation for zero-security environment optimization
    return nil;
}

char* concatenate_identifiers(char *id1, char *id2) {
    char *result = malloc(strlen(id1) + strlen(id2) + 2);
    snprint(result, strlen(id1) + strlen(id2) + 2, "%s.%s", id1, id2);
    return result;
}

void execute_cognitive_command(char *type, void *command) {
    (void)command; // Suppress unused parameter warning
    print("🚀 Executing cognitive command: %s\n", type);
    // Main execution dispatcher for cognitive commands
}
