/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         cexpparse
#define yylex           cexplex
#define yyerror         cexperror
#define yylval          cexplval
#define yychar          cexpchar
#define yydebug         cexpdebug
#define yynerrs         cexpnerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "cexp.y"

/* $Id: cexp.y,v 1.51 2013/01/15 19:30:47 strauman Exp $ */
/* Grammar definition and lexical analyzer for Cexp */

/* SLAC Software Notices, Set 4 OTT.002a, 2004 FEB 03
 *
 * Authorship
 * ----------
 * This software (CEXP - C-expression interpreter and runtime
 * object loader/linker) was created by
 *
 *    Till Straumann <strauman@slac.stanford.edu>, 2002-2008,
 * 	  Stanford Linear Accelerator Center, Stanford University.
 *
 * Acknowledgement of sponsorship
 * ------------------------------
 * This software was produced by
 *     the Stanford Linear Accelerator Center, Stanford University,
 * 	   under Contract DE-AC03-76SFO0515 with the Department of Energy.
 * 
 * Government disclaimer of liability
 * ----------------------------------
 * Neither the United States nor the United States Department of Energy,
 * nor any of their employees, makes any warranty, express or implied, or
 * assumes any legal liability or responsibility for the accuracy,
 * completeness, or usefulness of any data, apparatus, product, or process
 * disclosed, or represents that its use would not infringe privately owned
 * rights.
 * 
 * Stanford disclaimer of liability
 * --------------------------------
 * Stanford University makes no representations or warranties, express or
 * implied, nor assumes any liability for the use of this software.
 * 
 * Stanford disclaimer of copyright
 * --------------------------------
 * Stanford University, owner of the copyright, hereby disclaims its
 * copyright and all other rights in this software.  Hence, anyone may
 * freely use it for any purpose without restriction.  
 * 
 * Maintenance of notices
 * ----------------------
 * In the interest of clarity regarding the origin and status of this
 * SLAC software, this and all the preceding Stanford University notices
 * are to remain affixed to any copy or derivative of this software made
 * or distributed by the recipient and are to be affixed to any copy of
 * software made or distributed by the recipient that contains a copy or
 * derivative of this software.
 * 
 * SLAC Software Notices, Set 4 OTT.002a, 2004 FEB 03
 */ 

#include <stdio.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cexpsyms.h"
#include "cexpmod.h"
#include "vars.h"
#include <stdarg.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* not letting them live makes not much sense */
#ifndef CONFIG_STRINGS_LIVE_FOREVER
#define CONFIG_STRINGS_LIVE_FOREVER
#endif

#define YYLEX_PARAM		ctx
#define YYERROR_VERBOSE

#define EVAL_INH	 ((ctx)->evalInhibit)
#define PSHEVAL(inh) do { EVAL_INH<<=1; if (inh) EVAL_INH++; } while(0)
#define POPEVAL      do { EVAL_INH>>=1; } while(0)
#define EVAL(stuff)  if (! EVAL_INH ) do { stuff; } while (0)

#define CHECK(cexpTfuncall) do { const char *e=(cexpTfuncall);\
					 if (e) { yyerror(ctx, e); YYERROR; } } while (0)

/* acceptable characters for identifiers - must not
 * overlap with operators
 */
#define ISIDENTCHAR(ch) ('_'==(ch) || '@'==(ch))

#define LEXERR	-1
/* ugly hack; helper for word completion */
#define LEXERR_INCOMPLETE_STRING	-100

       void yyerror(CexpParserCtx ctx, const char*msg);
static void errmsg(CexpParserCtx ctx, const char *msg, ...);
static void wrnmsg(CexpParserCtx ctx, const char *msg, ...);

int  yylex();

typedef char *LString;

struct CexpParserCtxRec_;

typedef void (*RedirCb)(struct CexpParserCtxRec_ *, void *);

typedef struct CexpParserCtxRec_ {
	const char		*chpt;
	LString			lineStrTbl[10];	/* allow for 10 strings on one line of input  */
	CexpSymRec		rval_sym;       /* return value and status of last evaluation */
	CexpValU		rval;
	int             status;         
	unsigned long	evalInhibit;
	FILE			*outf;			/* where to print evaluated value			  */
	FILE			*errf;			/* where to print error messages 			  */
	char            sbuf[1000];		/* scratch space for strings                  */
	FILE            *o_stdout;      /* redirection */
	FILE            *o_stderr;      /* redirection */
	FILE            *o_stdin;       /* redirection */
	FILE            *o_outf;
	FILE            *o_errf;
	RedirCb         redir_cb;
	void            *cb_arg;
} CexpParserCtxRec;

static CexpSym
varCreate(CexpParserCtx ctx, char *name, CexpType type)
{
CexpSym rval;
	if (!(rval=cexpVarLookup(name,1)/*allow creation*/)) {
		if ( ctx->errf )
			fprintf(ctx->errf, "unable to add new user variable");
		return 0;
	}
	rval->value.type = type;
	if (CEXP_TYPE_PTRQ(type))
		rval->value.ptv->p=0;
	else switch(type) {
		case TUChar:	rval->value.ptv->c=0;	break;
		case TUShort:	rval->value.ptv->s=0;	break;
		case TUInt:		rval->value.ptv->i=0;	break;
		case TULong:	rval->value.ptv->l=0;	break;
		case TFloat:	rval->value.ptv->f=0.0;	break;
		case TDouble:	rval->value.ptv->d=0.0;	break;
		default:
			assert(!"unknown type");
	}
	return rval;
}

static int
cexpRedir(CexpParserCtx ctx, unsigned long op, void *opath, void *ipath);

static void
cexpUnredir(CexpParserCtx ctx);

/* Redefine so that we can wrap */
#undef yyparse
#define yyparse __cexpparse



/* Line 268 of yacc.c  */
#line 241 "cexp.tab.c"

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
     NUMBER = 258,
     STR_CONST = 259,
     FUNC = 260,
     VAR = 261,
     UVAR = 262,
     IDENT = 263,
     KW_CHAR = 264,
     KW_SHORT = 265,
     KW_INT = 266,
     KW_LONG = 267,
     KW_FLOAT = 268,
     KW_DOUBLE = 269,
     MODOP = 270,
     REDIR = 271,
     REDIRBOTH = 272,
     REDIRAPPEND = 273,
     REDIRAPPENDBOTH = 274,
     NONE = 275,
     OR = 276,
     AND = 277,
     NE = 278,
     EQ = 279,
     GE = 280,
     LE = 281,
     SHR = 282,
     SHL = 283,
     CAST = 284,
     VARCAST = 285,
     DEREF = 286,
     ADDR = 287,
     PREFIX = 288,
     MM = 289,
     PP = 290,
     NEG = 291,
     CALL = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 163 "cexp.y"

	CexpTypedValRec				val;
	CexpTypedAddrRec			lval;
	CexpTypedAddr				varp;
	CexpSym						sym;	/* a symbol table entry */
	CexpType					typ;
	CexpBinOp					binop;
	char						*lstr;	/* string in the line string table */
	struct			{
		CexpTypedAddrRec	lval;
		CexpBinOp			op;
	}							fixexp;
	struct			{
		CexpSym				sym;
		char				*mname;		/* string kept in the line string table */
	}							method;
	unsigned long				ul;
	char                        *chrp;



/* Line 293 of yacc.c  */
#line 336 "cexp.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 348 "cexp.tab.c"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   474

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNRULES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,    42,    29,     2,
      55,    56,    40,    39,    21,    38,    54,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,     2,
      32,    24,    33,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,    51,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    25,    26,    30,    31,
      34,    35,    36,    37,    43,    44,    45,    46,    47,    48,
      49,    50,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    13,    16,    19,    22,
      23,    26,    29,    34,    39,    42,    46,    54,    57,    61,
      69,    71,    74,    76,    80,    82,    85,    88,    91,    94,
      96,   100,   104,   108,   110,   113,   116,   120,   124,   128,
     132,   136,   140,   144,   148,   152,   156,   160,   164,   168,
     172,   176,   180,   183,   186,   189,   192,   195,   198,   200,
     202,   204,   206,   209,   212,   215,   218,   220,   222,   224,
     226,   228,   231,   233,   235,   237,   239,   241,   243,   247,
     252,   254,   263,   265,   268,   270,   272,   274,   277,   280,
     283,   287,   291,   295,   299,   301,   305,   310,   317,   321,
     326,   333,   342,   353,   366,   381,   398,   417,   438,   461,
     486,   513
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    62,    67,    -1,    33,    -1,    36,    -1,
      33,    29,    -1,    36,    29,    -1,    75,    23,    -1,     4,
      23,    -1,    -1,    60,    61,    -1,    32,    61,    -1,    32,
      61,    60,    61,    -1,    60,    61,    32,    61,    -1,    78,
      76,    -1,    78,    40,    76,    -1,    81,    55,    40,    76,
      56,    55,    56,    -1,    78,     8,    -1,    78,    40,     8,
      -1,    81,    55,    40,     8,    56,    55,    56,    -1,    64,
      -1,    63,    52,    -1,    68,    -1,    66,    21,    68,    -1,
      57,    -1,     8,    57,    -1,    65,    57,    -1,    63,    57,
      -1,    66,    57,    -1,    69,    -1,    77,    24,    68,    -1,
      77,    15,    68,    -1,     8,    24,    68,    -1,    84,    -1,
      70,    69,    -1,    71,    69,    -1,    69,    27,    69,    -1,
      69,    28,    69,    -1,    69,    29,    69,    -1,    69,    30,
      69,    -1,    69,    31,    69,    -1,    69,    33,    69,    -1,
      69,    32,    69,    -1,    69,    35,    69,    -1,    69,    34,
      69,    -1,    69,    37,    69,    -1,    69,    36,    69,    -1,
      69,    39,    69,    -1,    69,    38,    69,    -1,    69,    40,
      69,    -1,    69,    41,    69,    -1,    69,    42,    69,    -1,
      69,    25,    -1,    69,    26,    -1,    48,    77,    -1,    49,
      77,    -1,    77,    48,    -1,    77,    49,    -1,    77,    -1,
       3,    -1,     4,    -1,    86,    -1,    52,    84,    -1,    51,
      84,    -1,    38,    84,    -1,    29,    75,    -1,     6,    -1,
       7,    -1,    75,    -1,     5,    -1,    75,    -1,    40,    84,
      -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
      -1,    14,    -1,    55,    78,    56,    -1,    55,    78,    40,
      56,    -1,    78,    -1,    55,    81,    55,    40,    56,    55,
      56,    56,    -1,     5,    -1,    29,     5,    -1,    73,    -1,
      72,    -1,    74,    -1,    79,    84,    -1,    80,    84,    -1,
      82,    84,    -1,     6,    54,     8,    -1,     7,    54,     8,
      -1,     5,    54,     8,    -1,    55,    66,    56,    -1,    83,
      -1,    85,    55,    56,    -1,    85,    55,    68,    56,    -1,
      85,    55,    68,    21,    68,    56,    -1,    86,    55,    56,
      -1,    86,    55,    68,    56,    -1,    86,    55,    68,    21,
      68,    56,    -1,    86,    55,    68,    21,    68,    21,    68,
      56,    -1,    86,    55,    68,    21,    68,    21,    68,    21,
      68,    56,    -1,    86,    55,    68,    21,    68,    21,    68,
      21,    68,    21,    68,    56,    -1,    86,    55,    68,    21,
      68,    21,    68,    21,    68,    21,    68,    21,    68,    56,
      -1,    86,    55,    68,    21,    68,    21,    68,    21,    68,
      21,    68,    21,    68,    21,    68,    56,    -1,    86,    55,
      68,    21,    68,    21,    68,    21,    68,    21,    68,    21,
      68,    21,    68,    21,    68,    56,    -1,    86,    55,    68,
      21,    68,    21,    68,    21,    68,    21,    68,    21,    68,
      21,    68,    21,    68,    21,    68,    56,    -1,    86,    55,
      68,    21,    68,    21,    68,    21,    68,    21,    68,    21,
      68,    21,    68,    21,    68,    21,    68,    21,    68,    56,
      -1,    86,    55,    68,    21,    68,    21,    68,    21,    68,
      21,    68,    21,    68,    21,    68,    21,    68,    21,    68,
      21,    68,    21,    68,    56,    -1,    86,    55,    68,    21,
      68,    21,    68,    21,    68,    21,    68,    21,    68,    21,
      68,    21,    68,    21,    68,    21,    68,    21,    68,    21,
      68,    56,    -1,    86,    55,    68,    21,    68,    21,    68,
      21,    68,    21,    68,    21,    68,    21,    68,    21,    68,
      21,    68,    21,    68,    21,    68,    21,    68,    21,    68,
      56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   250,   250,   253,   255,   257,   259,   263,   271,   277,
     278,   280,   282,   284,   288,   290,   292,   296,   301,   306,
     313,   313,   316,   317,   321,   323,   329,   330,   334,   371,
     372,   374,   381,   390,   391,   395,   399,   401,   403,   405,
     407,   409,   411,   413,   415,   417,   419,   421,   423,   425,
     427,   429,   433,   437,   441,   443,   448,   450,   452,   460,
     461,   465,   466,   468,   470,   476,   480,   482,   485,   487,
     491,   493,   508,   510,   512,   514,   516,   518,   522,   527,
     531,   550,   554,   556,   558,   570,   584,   585,   587,   589,
     594,   596,   598,   604,   605,   606,   608,   610,   612,   614,
     616,   618,   620,   622,   624,   626,   628,   630,   632,   634,
     636,   638
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "STR_CONST", "FUNC", "VAR",
  "UVAR", "IDENT", "KW_CHAR", "KW_SHORT", "KW_INT", "KW_LONG", "KW_FLOAT",
  "KW_DOUBLE", "MODOP", "REDIR", "REDIRBOTH", "REDIRAPPEND",
  "REDIRAPPENDBOTH", "NONE", "','", "'?'", "':'", "'='", "OR", "AND",
  "'|'", "'^'", "'&'", "NE", "EQ", "'<'", "'>'", "GE", "LE", "SHR", "SHL",
  "'-'", "'+'", "'*'", "'/'", "'%'", "CAST", "VARCAST", "DEREF", "ADDR",
  "PREFIX", "MM", "PP", "NEG", "'~'", "'!'", "CALL", "'.'", "'('", "')'",
  "'\\n'", "$accept", "input", "oredirop", "redirarg", "redir", "redef",
  "newdef", "def", "commaexp", "line", "exp", "binexp", "or", "and",
  "prefix", "postfix", "unexp", "nonfuncvar", "anyvar", "lval", "typeid",
  "cast", "pcast", "fptype", "fpcast", "funcp", "castexp", "symmethod",
  "call", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    44,    63,    58,    61,   276,   277,   124,    94,    38,
     278,   279,    60,    62,   280,   281,   282,   283,    45,    43,
      42,    47,    37,   284,   285,   286,   287,   288,   289,   290,
     291,   126,    33,   292,    46,    40,    41,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    79,    80,
      81,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      85,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     2,     2,     2,     0,
       2,     2,     4,     4,     2,     3,     7,     2,     3,     7,
       1,     2,     1,     3,     1,     2,     2,     2,     2,     1,
       3,     3,     3,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       1,     8,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     3,     3,     3,     1,     3,     4,     6,     3,     4,
       6,     8,    10,    12,    14,    16,    18,    20,    22,    24,
      26,    28
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     3,     4,     0,     0,     0,     0,    66,    67,
      11,     0,     5,     6,     1,    10,    59,    60,    82,    66,
      67,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,    20,     0,
       0,     2,    22,    29,     0,     0,    85,    84,    86,    70,
      58,    80,     0,     0,     0,     0,    94,    33,     0,    61,
       8,     0,     7,     0,     0,     0,     0,     0,    25,    83,
      65,    58,    64,    71,    54,    55,    63,    62,     0,     0,
      80,     0,    21,    27,    26,     0,    28,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,    56,
      57,    69,    17,     0,    68,    14,    87,    88,     0,    89,
       0,     0,    12,    13,    92,    90,    91,    32,    93,     0,
      78,     0,    23,    36,    37,    38,    39,    40,    42,    41,
      44,    43,    46,    45,    48,    47,    49,    50,    51,    31,
      30,    18,    15,     0,    95,     0,    98,     0,    79,     0,
       0,     0,     0,    96,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,   100,     0,    19,    16,
       0,    81,     0,   101,     0,     0,   102,     0,     0,   103,
       0,     0,   104,     0,     0,   105,     0,     0,   106,     0,
       0,   107,     0,     0,   108,     0,     0,   109,     0,     0,
     110,     0,   111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,    10,     6,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,   115,    71,
      51,    52,    53,    54,    55,    56,    57,    58,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
      14,   116,   -21,   -11,    23,   116,   201,    25,  -113,  -113,
      63,    30,  -113,  -113,  -113,    45,  -113,  -113,   -24,    24,
      58,    40,  -113,  -113,  -113,  -113,  -113,  -113,   161,   326,
     326,    69,    69,   326,   326,   310,  -113,   -37,  -113,    56,
     -17,  -113,  -113,   357,   326,   326,  -113,  -113,  -113,  -113,
      95,     5,   326,   326,    61,   326,  -113,  -113,    70,    71,
    -113,   116,  -113,   116,   120,   123,   124,   100,  -113,  -113,
    -113,    22,  -113,  -113,  -113,  -113,  -113,  -113,   110,   -14,
     -34,    80,  -113,  -113,  -113,   100,  -113,  -113,  -113,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   374,   390,   100,   100,  -113,
    -113,  -113,  -113,   211,  -113,  -113,  -113,  -113,    97,  -113,
     217,   256,  -113,  -113,  -113,  -113,  -113,  -113,  -113,    85,
    -113,   106,  -113,   405,   419,   432,   242,   242,   195,   195,
     195,   195,   132,   132,   202,   202,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,   221,  -113,    -7,  -113,    -5,  -113,    91,
      94,    98,   100,  -113,   100,  -113,   104,   107,   108,   119,
      -4,   121,   122,   125,  -113,   100,  -113,   133,  -113,  -113,
      -2,  -113,   100,  -113,     3,   100,  -113,     6,   100,  -113,
       7,   100,  -113,    10,   100,  -113,    12,   100,  -113,    13,
     100,  -113,    16,   100,  -113,    17,   100,  -113,    18,   100,
    -113,   134,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,   143,    -3,  -113,  -113,  -113,  -113,   145,  -113,
     -64,    -9,  -113,  -113,  -113,  -113,  -113,     4,  -112,    -6,
     152,  -113,  -113,   157,  -113,  -113,   131,  -113,  -113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      50,   152,    15,   127,    85,    11,   129,    85,    12,    11,
     111,     8,     9,   112,   162,    82,   164,   175,    13,   182,
      83,   132,   130,    14,   185,    74,    75,   188,   191,    50,
      64,   194,    70,   197,   200,   105,   106,   203,   206,   209,
      86,   161,   128,   149,   150,   113,     1,     2,    60,   163,
       3,   165,   176,    62,   183,   114,   155,   157,   122,   186,
     123,    50,   189,   192,    67,    11,   195,    11,   198,   201,
     109,   110,   204,   207,   210,     8,     9,    63,    65,    50,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     2,    68,   169,     3,
     170,    50,    50,    16,    17,    18,    19,    20,    78,    30,
     107,   180,    66,    84,    50,    50,   118,   114,   184,   108,
       7,   187,     8,     9,   190,   120,   121,   193,   124,    28,
     196,   125,   126,   199,    67,   131,   202,   153,    29,   205,
      30,   158,   208,   109,   110,   211,   159,   166,    31,    32,
     167,    33,    34,    61,   168,    35,    50,   114,    50,   171,
      72,    73,   172,   173,    76,    77,    69,     8,     9,    50,
     100,   101,   102,   103,   104,   174,    50,   177,   178,    50,
      79,   179,    50,   116,   117,    50,   119,    80,    50,   181,
     212,    50,    81,     0,    50,     0,     0,    50,     0,     0,
      50,     0,     0,    50,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   111,     8,     9,   151,
      16,    17,    18,    19,    20,    78,   111,     8,     9,   160,
      28,    98,    99,   100,   101,   102,   103,   104,     0,    29,
       0,    30,   102,   103,   104,     0,    28,     0,     0,    31,
      32,     0,    33,    34,     0,    29,    35,    30,    36,    16,
      17,    18,    19,    20,    78,    31,    32,     0,    33,    34,
       0,     0,    35,   154,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    28,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    30,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,    33,    34,     0,
       0,    35,   156,    16,    17,    18,    19,    20,    78,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
      30,     0,     0,     0,     0,    28,     0,     0,    31,    32,
       0,    33,    34,     0,    29,    35,    30,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,    33,    34,     0,
       0,    35,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-113))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,   113,     5,    67,    21,     1,    40,    21,    29,     5,
       5,     6,     7,     8,    21,    52,    21,    21,    29,    21,
      57,    85,    56,     0,    21,    31,    32,    21,    21,    35,
      54,    21,    28,    21,    21,    44,    45,    21,    21,    21,
      57,   153,    56,   107,   108,    40,    32,    33,    23,    56,
      36,    56,    56,    23,    56,    51,   120,   121,    61,    56,
      63,    67,    56,    56,    24,    61,    56,    63,    56,    56,
      48,    49,    56,    56,    56,     6,     7,    32,    54,    85,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    33,    57,   162,    36,
     164,   107,   108,     3,     4,     5,     6,     7,     8,    40,
      15,   175,    54,    57,   120,   121,    55,   113,   182,    24,
       4,   185,     6,     7,   188,    55,    55,   191,     8,    29,
     194,     8,     8,   197,    24,    55,   200,    40,    38,   203,
      40,    56,   206,    48,    49,   209,    40,    56,    48,    49,
      56,    51,    52,    10,    56,    55,   162,   153,   164,    55,
      29,    30,    55,    55,    33,    34,     5,     6,     7,   175,
      38,    39,    40,    41,    42,    56,   182,    56,    56,   185,
      35,    56,   188,    52,    53,   191,    55,    35,   194,    56,
      56,   197,    35,    -1,   200,    -1,    -1,   203,    -1,    -1,
     206,    -1,    -1,   209,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,     5,     6,     7,     8,
      29,    36,    37,    38,    39,    40,    41,    42,    -1,    38,
      -1,    40,    40,    41,    42,    -1,    29,    -1,    -1,    48,
      49,    -1,    51,    52,    -1,    38,    55,    40,    57,     3,
       4,     5,     6,     7,     8,    48,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,    -1,
      -1,    55,    56,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    29,    -1,    -1,    48,    49,
      -1,    51,    52,    -1,    38,    55,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,    -1,
      -1,    55,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,    36,    59,    60,    62,     4,     6,     7,
      61,    75,    29,    29,     0,    61,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    29,    38,
      40,    48,    49,    51,    52,    55,    57,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      23,    60,    23,    32,    54,    54,    54,    24,    57,     5,
      75,    77,    84,    84,    77,    77,    84,    84,     8,    66,
      78,    81,    52,    57,    57,    21,    57,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    69,    69,    15,    24,    48,
      49,     5,     8,    40,    75,    76,    84,    84,    55,    84,
      55,    55,    61,    61,     8,     8,     8,    68,    56,    40,
      56,    55,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    68,
      68,     8,    76,    40,    56,    68,    56,    68,    56,    40,
       8,    76,    21,    56,    21,    56,    56,    56,    56,    68,
      68,    55,    55,    55,    56,    21,    56,    56,    56,    56,
      68,    56,    21,    56,    68,    21,    56,    68,    21,    56,
      68,    21,    56,    68,    21,    56,    68,    21,    56,    68,
      21,    56,    68,    21,    56,    68,    21,    56,    68,    21,
      56,    68,    56
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
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (ctx, YY_("syntax error: cannot back up")); \
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
		  Type, Value, ctx); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, CexpParserCtx ctx)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, ctx)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    CexpParserCtx ctx;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (ctx);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, CexpParserCtx ctx)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, ctx)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    CexpParserCtx ctx;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, ctx);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, CexpParserCtx ctx)
#else
static void
yy_reduce_print (yyvsp, yyrule, ctx)
    YYSTYPE *yyvsp;
    int yyrule;
    CexpParserCtx ctx;
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
		       		       , ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, ctx); \
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, CexpParserCtx ctx)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, ctx)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    CexpParserCtx ctx;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (ctx);

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
int yyparse (CexpParserCtx ctx);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/*----------.
| yyparse.  |
`----------*/

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
yyparse (CexpParserCtx ctx)
#else
int
yyparse (ctx)
    CexpParserCtx ctx;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

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
  if (yypact_value_is_default (yyn))
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

/* Line 1806 of yacc.c  */
#line 250 "cexp.y"
    { if ( TVoid != (yyvsp[(2) - (2)].val).type ) { ctx->rval=(yyvsp[(2) - (2)].val).tv; ctx->rval_sym.value.type = (yyvsp[(2) - (2)].val).type; } ctx->status = 0; YYACCEPT; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 254 "cexp.y"
    { (yyval.ul)=REDIR; }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 256 "cexp.y"
    { (yyval.ul)=REDIRAPPEND; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 258 "cexp.y"
    { (yyval.ul)=REDIRBOTH; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 260 "cexp.y"
    { (yyval.ul)=REDIRAPPENDBOTH; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 264 "cexp.y"
    {
			if ( TUCharP != (yyvsp[(1) - (2)].varp)->type ) {
				errmsg(ctx, "(bad type): redirector requires string argument\n");
				YYERROR;
			}
			(yyval.chrp) = (yyvsp[(1) - (2)].varp)->ptv->p;
		}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 272 "cexp.y"
    {
			(yyval.chrp) = (yyvsp[(1) - (2)].val).tv.p;
		}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 279 "cexp.y"
    { if ( cexpRedir( ctx, (yyvsp[(1) - (2)].ul), (yyvsp[(2) - (2)].chrp),  0 ) ) YYERROR; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 281 "cexp.y"
    { if ( cexpRedir( ctx,  0,  0, (yyvsp[(2) - (2)].chrp) ) ) YYERROR; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 283 "cexp.y"
    { if ( cexpRedir( ctx, (yyvsp[(3) - (4)].ul), (yyvsp[(4) - (4)].chrp), (yyvsp[(2) - (4)].chrp) ) ) YYERROR; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 285 "cexp.y"
    { if ( cexpRedir( ctx, (yyvsp[(1) - (4)].ul), (yyvsp[(2) - (4)].chrp), (yyvsp[(4) - (4)].chrp) ) ) YYERROR; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 289 "cexp.y"
    { EVAL((yyvsp[(2) - (2)].varp)->type = (yyvsp[(1) - (2)].typ);); CHECK(cexpTA2TV(&(yyval.val),(yyvsp[(2) - (2)].varp))); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 291 "cexp.y"
    { EVAL((yyvsp[(3) - (3)].varp)->type = CEXP_TYPE_BASE2PTR((yyvsp[(1) - (3)].typ));); CHECK(cexpTA2TV(&(yyval.val),(yyvsp[(3) - (3)].varp))); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 293 "cexp.y"
    { EVAL((yyvsp[(4) - (7)].varp)->type = (yyvsp[(1) - (7)].typ)); CHECK(cexpTA2TV(&(yyval.val),(yyvsp[(4) - (7)].varp))); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 297 "cexp.y"
    { CexpSym found;
					  EVAL(if (!(found = varCreate(ctx, (yyvsp[(2) - (2)].lstr), (yyvsp[(1) - (2)].typ)))) YYERROR; \
					  		CHECK(cexpTA2TV(&(yyval.val),&found->value)) );
					}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 302 "cexp.y"
    { CexpSym found;
					  EVAL(if (!(found = varCreate(ctx, (yyvsp[(3) - (3)].lstr), CEXP_TYPE_BASE2PTR((yyvsp[(1) - (3)].typ))))) YYERROR; \
					  		CHECK(cexpTA2TV(&(yyval.val),&found->value)));
					}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 307 "cexp.y"
    { CexpSym found;
					  EVAL(if (!(found = varCreate(ctx, (yyvsp[(4) - (7)].lstr), (yyvsp[(1) - (7)].typ)))) YYERROR; \
					  		CHECK(cexpTA2TV(&(yyval.val),&found->value)));
					}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 318 "cexp.y"
    { (yyval.val)=(yyvsp[(3) - (3)].val); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 322 "cexp.y"
    {	(yyval.val).type=TVoid; }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 324 "cexp.y"
    {
						(yyval.val).type=TVoid;
						yyerror(ctx, "unknown symbol/variable; '=' expected");
						YYERROR;
					}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 330 "cexp.y"
    {
						errmsg(ctx, ": symbol already defined; append '!' to enforce recast\n");
						YYERROR;
					}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 335 "cexp.y"
    {FILE *f=ctx->outf;
						(yyval.val)=(yyvsp[(1) - (2)].val);
						if (CEXP_TYPE_FPQ((yyvsp[(1) - (2)].val).type)) {
							CHECK(cexpTypeCast(&(yyvsp[(1) - (2)].val),TDouble,0));
							if (f)
								fprintf(f,"%f\n",(yyvsp[(1) - (2)].val).tv.d);
						}else {
							if (TUChar==(yyvsp[(1) - (2)].val).type) {
								unsigned char c=(yyvsp[(1) - (2)].val).tv.c,e=0;
								if (f) {
									fprintf(f,"0x%02x (%d)",c,c);
									switch (c) {
										case 0:	    e=1; c='0'; break;
										case '\t':	e=1; c='t'; break;
										case '\r':	e=1; c='r'; break;
										case '\n':	e=1; c='n'; break;
										case '\f':	e=1; c='f'; break;
										default: 	break;
									}
									if (isprint(c)) {
										fputc('\'',f);
										if (e) fputc('\\',f);
										fputc(c,f);
										fputc('\'',f);
									}
									fputc('\n',f);
								}
							} else {
								CHECK(cexpTypeCast(&(yyvsp[(1) - (2)].val),TULong,0));
								if (f)
									fprintf(f,"0x%0*lx (%ld)\n",(int)(2*sizeof((yyvsp[(1) - (2)].val).tv.l)), (yyvsp[(1) - (2)].val).tv.l, (yyvsp[(1) - (2)].val).tv.l);
							}
						}
					}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 373 "cexp.y"
    { (yyval.val)=(yyvsp[(3) - (3)].val); EVAL(CHECK(cexpTVAssign(&(yyvsp[(1) - (3)].lval), &(yyvsp[(3) - (3)].val)))); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 375 "cexp.y"
    { EVAL( \
						CHECK(cexpTA2TV(&(yyval.val),&(yyvsp[(1) - (3)].lval))); \
						CHECK(cexpTVBinOp(&(yyval.val), &(yyval.val), &(yyvsp[(3) - (3)].val), (yyvsp[(2) - (3)].binop))); \
						CHECK(cexpTVAssign(&(yyvsp[(1) - (3)].lval),&(yyval.val))); \
					  );
					}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 382 "cexp.y"
    { CexpSym found;
					  (yyval.val)=(yyvsp[(3) - (3)].val); EVAL(if (!(found=varCreate(ctx, (yyvsp[(1) - (3)].lstr), (yyvsp[(3) - (3)].val).type))) {	\
									YYERROR; 								\
								}\
								CHECK(cexpTVAssign(&found->value, &(yyvsp[(3) - (3)].val))); );
					}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 392 "cexp.y"
    { (yyval.val).tv.l = (yyvsp[(1) - (2)].ul) || cexpTVTrueQ(&(yyvsp[(2) - (2)].val));
					  (yyval.val).type = TULong;
					  POPEVAL; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 396 "cexp.y"
    { (yyval.val).tv.l = (yyvsp[(1) - (2)].ul) && cexpTVTrueQ(&(yyvsp[(2) - (2)].val));
					  (yyval.val).type = TULong;
					  POPEVAL; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 400 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OOr)); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 402 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OXor)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 404 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OAnd)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 406 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),ONe)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 408 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OEq)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 410 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OGt)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 412 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OLt)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 414 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OLe)); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 416 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OGe)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 418 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OShL)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 420 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OShR)); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 422 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OAdd)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 424 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OSub)); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 426 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OMul)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 428 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),ODiv)); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 430 "cexp.y"
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[(1) - (3)].val),&(yyvsp[(3) - (3)].val),OMod)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 434 "cexp.y"
    { (yyval.ul)=cexpTVTrueQ(&(yyvsp[(1) - (2)].val)); PSHEVAL((yyval.ul)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 438 "cexp.y"
    { (yyval.ul)=cexpTVTrueQ(&(yyvsp[(1) - (2)].val)); PSHEVAL( ! (yyval.ul)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 442 "cexp.y"
    { (yyval.fixexp).lval=(yyvsp[(2) - (2)].lval); (yyval.fixexp).op=OSub; }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 444 "cexp.y"
    { (yyval.fixexp).lval=(yyvsp[(2) - (2)].lval); (yyval.fixexp).op=OAdd; }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 449 "cexp.y"
    { (yyval.fixexp).lval=(yyvsp[(1) - (2)].lval); (yyval.fixexp).op=OSub; }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 451 "cexp.y"
    { (yyval.fixexp).lval=(yyvsp[(1) - (2)].lval); (yyval.fixexp).op=OAdd; }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 453 "cexp.y"
    { (yyval.fixexp).lval=(yyvsp[(1) - (1)].lval); (yyval.fixexp).op=ONoop; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 467 "cexp.y"
    { (yyval.val).type=TULong; (yyval.val).tv.l = ! cexpTVTrueQ(&(yyvsp[(2) - (2)].val)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 469 "cexp.y"
    { CHECK(cexpTVUnOp(&(yyval.val),&(yyvsp[(2) - (2)].val),OCpl)); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 471 "cexp.y"
    { CHECK(cexpTVUnOp(&(yyval.val),&(yyvsp[(2) - (2)].val),ONeg)); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 477 "cexp.y"
    { CHECK(cexpTVPtr(&(yyval.val), (yyvsp[(2) - (2)].varp))); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 481 "cexp.y"
    { (yyval.varp)=&(yyvsp[(1) - (1)].sym)->value; }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 483 "cexp.y"
    { (yyval.varp)=&(yyvsp[(1) - (1)].sym)->value; }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 486 "cexp.y"
    { (yyval.varp)=(yyvsp[(1) - (1)].varp); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 488 "cexp.y"
    { (yyval.varp)=&(yyvsp[(1) - (1)].sym)->value; }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 492 "cexp.y"
    { (yyval.lval) = *(yyvsp[(1) - (1)].varp); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 494 "cexp.y"
    { if (!CEXP_TYPE_PTRQ((yyvsp[(2) - (2)].val).type) || CEXP_TYPE_FUNQ((yyvsp[(2) - (2)].val).type)) {
						yyerror(ctx, "not a valid lval address");
						YYERROR;
					  }
					  (yyval.lval).type=CEXP_TYPE_PTR2BASE((yyvsp[(2) - (2)].val).type);
					  (yyval.lval).ptv=(CexpVal)(yyvsp[(2) - (2)].val).tv.p;
					}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 509 "cexp.y"
    { (yyval.typ)=TUChar; }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 511 "cexp.y"
    { (yyval.typ)=TUShort; }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 513 "cexp.y"
    { (yyval.typ)=TUInt; }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 515 "cexp.y"
    { (yyval.typ)=TULong; }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 517 "cexp.y"
    { (yyval.typ)=TFloat; }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 519 "cexp.y"
    { (yyval.typ)=TDouble; }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 523 "cexp.y"
    { (yyval.typ)=(yyvsp[(2) - (3)].typ); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 528 "cexp.y"
    { (yyval.typ)=CEXP_TYPE_BASE2PTR((yyvsp[(2) - (4)].typ)); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 532 "cexp.y"
    { switch ((yyvsp[(1) - (1)].typ)) {
						default:
							yyerror(ctx, "invalid type for function pointer cast");
						YYERROR;

						case TDouble:
							(yyval.typ)=TDFuncP;
						break;

						/* INTFIX */
						case TULong:
							(yyval.typ)=TFuncP;
						break;
					  }
					}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 551 "cexp.y"
    { (yyval.typ)=(yyvsp[(2) - (8)].typ); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 555 "cexp.y"
    { (yyval.val).type=(yyvsp[(1) - (1)].sym)->value.type; (yyval.val).tv.p=(void*)(yyvsp[(1) - (1)].sym)->value.ptv; }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 557 "cexp.y"
    { (yyval.val).type=(yyvsp[(2) - (2)].sym)->value.type; (yyval.val).tv.p=(void*)(yyvsp[(2) - (2)].sym)->value.ptv; }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 559 "cexp.y"
    { CexpTypedValRec tmp;
					  EVAL( \
						CHECK(cexpTA2TV(&(yyval.val),&(yyvsp[(1) - (1)].fixexp).lval)); \
						tmp.type=TUChar; \
						tmp.tv.c=1; \
						if (ONoop != (yyvsp[(1) - (1)].fixexp).op) { \
							CHECK(cexpTVBinOp(&tmp,&(yyval.val),&tmp,(yyvsp[(1) - (1)].fixexp).op)); \
							CHECK(cexpTVAssign(&(yyvsp[(1) - (1)].fixexp).lval,&tmp)); \
						} \
					  );
					}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 571 "cexp.y"
    { CexpTypedValRec tmp;
					  EVAL( \
						CHECK(cexpTA2TV(&(yyval.val),&(yyvsp[(1) - (1)].fixexp).lval)); \
						tmp.type=TUChar; \
						tmp.tv.c=1; \
						if (ONoop != (yyvsp[(1) - (1)].fixexp).op) { \
							CHECK(cexpTVBinOp(&(yyval.val),&(yyval.val),&tmp,(yyvsp[(1) - (1)].fixexp).op)); \
							CHECK(cexpTVAssign(&(yyvsp[(1) - (1)].fixexp).lval,&(yyval.val))); \
						} \
					  );
					}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 586 "cexp.y"
    { (yyval.val)=(yyvsp[(2) - (2)].val); CHECK(cexpTypeCast(&(yyval.val),(yyvsp[(1) - (2)].typ),CNV_FORCE)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 588 "cexp.y"
    { (yyval.val)=(yyvsp[(2) - (2)].val); CHECK(cexpTypeCast(&(yyval.val),(yyvsp[(1) - (2)].typ),CNV_FORCE)); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 590 "cexp.y"
    { (yyval.val)=(yyvsp[(2) - (2)].val); CHECK(cexpTypeCast(&(yyval.val),(yyvsp[(1) - (2)].typ),CNV_FORCE)); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 594 "cexp.y"
    { (yyval.method).sym = (yyvsp[(1) - (3)].sym); (yyval.method).mname=(yyvsp[(3) - (3)].lstr); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 596 "cexp.y"
    { (yyval.method).sym = (yyvsp[(1) - (3)].sym); (yyval.method).mname=(yyvsp[(3) - (3)].lstr); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 598 "cexp.y"
    { (yyval.method).sym = (yyvsp[(1) - (3)].sym); (yyval.method).mname=(yyvsp[(3) - (3)].lstr); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 604 "cexp.y"
    { (yyval.val)=(yyvsp[(2) - (3)].val); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 607 "cexp.y"
    {	EVAL(CHECK(cexpSymMember(&(yyval.val), (yyvsp[(1) - (3)].method).sym, (yyvsp[(1) - (3)].method).mname, 0))); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 609 "cexp.y"
    {	EVAL(CHECK(cexpSymMember(&(yyval.val), (yyvsp[(1) - (4)].method).sym, (yyvsp[(1) - (4)].method).mname, &(yyvsp[(3) - (4)].val), 0))); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 611 "cexp.y"
    {	EVAL(CHECK(cexpSymMember(&(yyval.val), (yyvsp[(1) - (6)].method).sym, (yyvsp[(1) - (6)].method).mname, &(yyvsp[(3) - (6)].val), &(yyvsp[(5) - (6)].val), 0))); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 613 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (3)].val),0))); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 615 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (4)].val),&(yyvsp[(3) - (4)].val),0))); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 617 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (6)].val),&(yyvsp[(3) - (6)].val),&(yyvsp[(5) - (6)].val),0))); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 619 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (8)].val),&(yyvsp[(3) - (8)].val),&(yyvsp[(5) - (8)].val),&(yyvsp[(7) - (8)].val),0))); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 621 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (10)].val),&(yyvsp[(3) - (10)].val),&(yyvsp[(5) - (10)].val),&(yyvsp[(7) - (10)].val),&(yyvsp[(9) - (10)].val),0))); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 623 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (12)].val),&(yyvsp[(3) - (12)].val),&(yyvsp[(5) - (12)].val),&(yyvsp[(7) - (12)].val),&(yyvsp[(9) - (12)].val),&(yyvsp[(11) - (12)].val),0))); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 625 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (14)].val),&(yyvsp[(3) - (14)].val),&(yyvsp[(5) - (14)].val),&(yyvsp[(7) - (14)].val),&(yyvsp[(9) - (14)].val),&(yyvsp[(11) - (14)].val),&(yyvsp[(13) - (14)].val),0))); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 627 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (16)].val),&(yyvsp[(3) - (16)].val),&(yyvsp[(5) - (16)].val),&(yyvsp[(7) - (16)].val),&(yyvsp[(9) - (16)].val),&(yyvsp[(11) - (16)].val),&(yyvsp[(13) - (16)].val),&(yyvsp[(15) - (16)].val),0))); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 629 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (18)].val),&(yyvsp[(3) - (18)].val),&(yyvsp[(5) - (18)].val),&(yyvsp[(7) - (18)].val),&(yyvsp[(9) - (18)].val),&(yyvsp[(11) - (18)].val),&(yyvsp[(13) - (18)].val),&(yyvsp[(15) - (18)].val),&(yyvsp[(17) - (18)].val),0))); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 631 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (20)].val),&(yyvsp[(3) - (20)].val),&(yyvsp[(5) - (20)].val),&(yyvsp[(7) - (20)].val),&(yyvsp[(9) - (20)].val),&(yyvsp[(11) - (20)].val),&(yyvsp[(13) - (20)].val),&(yyvsp[(15) - (20)].val),&(yyvsp[(17) - (20)].val),&(yyvsp[(19) - (20)].val),0))); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 633 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (22)].val),&(yyvsp[(3) - (22)].val),&(yyvsp[(5) - (22)].val),&(yyvsp[(7) - (22)].val),&(yyvsp[(9) - (22)].val),&(yyvsp[(11) - (22)].val),&(yyvsp[(13) - (22)].val),&(yyvsp[(15) - (22)].val),&(yyvsp[(17) - (22)].val),&(yyvsp[(19) - (22)].val),&(yyvsp[(21) - (22)].val),0))); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 635 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (24)].val),&(yyvsp[(3) - (24)].val),&(yyvsp[(5) - (24)].val),&(yyvsp[(7) - (24)].val),&(yyvsp[(9) - (24)].val),&(yyvsp[(11) - (24)].val),&(yyvsp[(13) - (24)].val),&(yyvsp[(15) - (24)].val),&(yyvsp[(17) - (24)].val),&(yyvsp[(19) - (24)].val),&(yyvsp[(21) - (24)].val),&(yyvsp[(23) - (24)].val),0))); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 637 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (26)].val),&(yyvsp[(3) - (26)].val),&(yyvsp[(5) - (26)].val),&(yyvsp[(7) - (26)].val),&(yyvsp[(9) - (26)].val),&(yyvsp[(11) - (26)].val),&(yyvsp[(13) - (26)].val),&(yyvsp[(15) - (26)].val),&(yyvsp[(17) - (26)].val),&(yyvsp[(19) - (26)].val),&(yyvsp[(21) - (26)].val),&(yyvsp[(23) - (26)].val),&(yyvsp[(25) - (26)].val),0))); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 639 "cexp.y"
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[(1) - (28)].val),&(yyvsp[(3) - (28)].val),&(yyvsp[(5) - (28)].val),&(yyvsp[(7) - (28)].val),&(yyvsp[(9) - (28)].val),&(yyvsp[(11) - (28)].val),&(yyvsp[(13) - (28)].val),&(yyvsp[(15) - (28)].val),&(yyvsp[(17) - (28)].val),&(yyvsp[(19) - (28)].val),&(yyvsp[(21) - (28)].val),&(yyvsp[(23) - (28)].val),&(yyvsp[(25) - (28)].val),&(yyvsp[(27) - (28)].val),0))); }
    break;



/* Line 1806 of yacc.c  */
#line 2637 "cexp.tab.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (ctx, YY_("syntax error"));
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
        yyerror (ctx, yymsgp);
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
		      yytoken, &yylval, ctx);
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
		  yystos[yystate], yyvsp, ctx);
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
  yyerror (ctx, YY_("memory exhausted"));
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
                  yytoken, &yylval, ctx);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, ctx);
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



/* Line 2067 of yacc.c  */
#line 643 "cexp.y"



/* add a string to the line string table returning its index
 * RETURNS a negative number on error
 */
LString
lstAddString(CexpParserCtx env, char *string)
{
LString			rval=0;
LString			*chppt;
int				i;
	for (i=0,chppt=env->lineStrTbl;
		 i<sizeof(env->lineStrTbl)/sizeof(env->lineStrTbl[0]);
		 i++,chppt++) {
		if (*chppt) {
			if  (strcmp(string,*chppt))			continue;
			else /* string exists already */	return *chppt;
		}
		/* string exists already */
		if ((rval=malloc(strlen(string)+1))) {
			*chppt=rval;
			strcpy(rval,string);
			return (LString) rval;
		}
	}
	if ( env->errf )
		fprintf(env->errf,"Cexp: Line String Table exhausted\n");
	return 0;
}

#define ch ((int)(*pa->chpt))
#define getch() do { (pa->chpt)++;} while(0)

/* helper to save typing */
static int
prerr(CexpParserCtx ctx)
{
	errmsg(ctx, "(yylex): buffer overflow\n");
	return LEXERR;
}

static int
scanfrac(char *buf, char *chpt, int size, YYSTYPE *rval, CexpParserCtx pa, int rejectLonely)
{
int hasE=0;
	/* first, we put ch to the buffer */
	*(chpt++)=(char)ch; size--; /* assume it's still safe */
	getch();
	if ( isdigit(ch) || 'E' == toupper(ch) ) {
		do {
			while(isdigit(ch) && size) {
				*(chpt++)=(char)ch; if (!--size) return prerr(pa);
				getch();
			}
			if (toupper(ch)=='E' && !hasE) {
				*(chpt++)=(char)'E'; if (!--size) return prerr(pa);
				getch();
				if ('-'==ch || '+'==ch) {
					*(chpt++)=(char)ch; if (!--size) return prerr(pa);
					getch();
				}
				hasE=1;
			} else {
		break; /* the loop */
			}
		} while (1);
	} else {
		if ( rejectLonely )
			return '.';
	}
	*chpt=0;
	rval->val.type=TDouble;
	rval->val.tv.d=strtod(buf,&chpt);
	return *chpt ? LEXERR : NUMBER;
}

int
yylex(YYSTYPE *rval, CexpParserCtx pa)
{
unsigned long num;
int           limit=sizeof(pa->sbuf)-1;
char          *chpt;

	while (' '==ch || '\t'==ch)
		getch();

	if (isdigit(ch) || '\''==ch) {
		/* a number */
		num=0;

		if ('\''==ch) {
			/* char constant */
			getch();
			num=ch;
			if ('\\'==ch) {
				getch();
				/* escape sequence */
				switch (ch) {
					case 't': num='\t'; break;
					case 'n': num='\n'; break;
					case 'r': num='\r'; break;
					case '0': num=0;	break;
					case 'f': num='\f';	break;
					case '\\': num='\\';break;
					case '\'': num='\'';break;
					default:
						wrnmsg(pa, ": unknown escape sequence, using unescaped char\n");
						num=ch;
					break;
				}
			}
			getch();
			if ('\''!=ch)
				wrnmsg(pa, ": missing closing '\n");
			else
				getch();
			rval->val.tv.c=(unsigned char)num;
			rval->val.type=TUChar;
			return NUMBER;
		}
		chpt=pa->sbuf;
		if ('0'==ch) {
			
			/* hex, octal or fractional */
			*(chpt++)=(char)ch; limit--;
			getch();
			if ('x'==ch) {
				/* a hex number */
				getch();
				while (isxdigit(ch)) {
					num<<=4;
					if (ch>='a')		num+=ch-'a'+10;
					else if (ch>='A')	num+=ch-'A'+10;
					else				num+=ch-'0';
					getch();
				}
			} else if ('.'==ch) {
				/* a decimal number */
				return scanfrac(pa->sbuf,chpt,limit,rval,pa,0);
			} else {
				/* OK, it's octal */
				while ('0'<=ch && ch<'8') {
					num<<=3;
					num+=ch-'0';
					getch();
				}
			}
		} else {
			/* so it must be base 10 */
			do {
				*(chpt++)=(char)ch; limit--;
				num=10*num+(ch-'0');
				getch();
			} while (isdigit(ch) && limit);
			if (!limit) {
				return prerr(pa);
			}
			if ('.'==ch) {
				/* it's a fractional number */
				return scanfrac(pa->sbuf,chpt,limit,rval,pa,0);
			}
		}
		rval->val.tv.l=num;
		rval->val.type=TULong;
		return NUMBER;
	} else if ('.'==ch) {
		/* perhaps also a fractional number */
		return
			scanfrac(pa->sbuf,pa->sbuf,limit,rval,pa,1);
	} else if (isalpha(ch) || ISIDENTCHAR(ch)) {
		/* slurp in an identifier */
		chpt=pa->sbuf;
		do {
			*(chpt++)=ch;
			getch();
		} while ((isalnum(ch)||ISIDENTCHAR(ch)) && (--limit > 0));
		*chpt=0;
		if (!limit)
			return prerr(pa);
		/* is it one of the type cast keywords? */
		if (!strcmp(pa->sbuf,"char"))
			return KW_CHAR;
		else if (!strcmp(pa->sbuf,"short"))
			return KW_SHORT;
		else if (!strcmp(pa->sbuf,"int"))
			return KW_INT;
		else if (!strcmp(pa->sbuf,"long"))
			return KW_LONG;
		else if (!strcmp(pa->sbuf,"float"))
			return KW_FLOAT;
		else if (!strcmp(pa->sbuf,"double"))
			return KW_DOUBLE;
		else if ((rval->sym=cexpSymLookup(pa->sbuf, 0)))
			return CEXP_TYPE_FUNQ(rval->sym->value.type) ? FUNC : VAR;
		else if ((rval->sym=cexpVarLookup(pa->sbuf,0))) {
			return UVAR;
		}

		/* it's a currently undefined symbol */
		return (rval->lstr=lstAddString(pa,pa->sbuf)) ? IDENT : LEXERR;
	} else if ('"'==ch) {
		/* generate a string constant */
		char *dst;
		const char *strStart;
		dst=pa->sbuf-1;
		strStart = pa->chpt+1;
		do {
		skipit:	
			dst++; limit--;
			getch();
			*dst=ch;
			if ('\\'==ch) {
				getch();
				switch (ch) {
					case 'n':	*dst='\n'; goto skipit;
					case 'r':	*dst='\r'; goto skipit;
					case 't':	*dst='\t'; goto skipit;
					case '"':	*dst='"';  goto skipit;
					case '\\':	           goto skipit;
					case '0':	*dst=0;    goto skipit;
					default:
						dst++; limit--; *dst=ch;
						break;
				}
			}
			if ('"'==ch) {
				*dst=0;
				getch();
				rval->val.type=TUCharP;
#ifdef CONFIG_STRINGS_LIVE_FOREVER
				rval->val.tv.p=cexpStrLookup(pa->sbuf,1);
#else
				rval->val.tv.p=lstAddString(pa,pa->sbuf);
#endif
				return rval->val.tv.p ? STR_CONST : LEXERR;
			}
		} while (ch && limit>2);
		return LEXERR_INCOMPLETE_STRING - (pa->chpt - strStart);
	} else {
		long rv=ch;
		if (rv) getch();

		/* comments? skip the rest of the line */
		if ('#'==rv || ('/'==ch && '/'==rv)) {
			while (ch && '\n'!=rv) {
				rv=ch;
				getch();
			}
			return '\n';
		}

		/* it's any kind of 'special' character such as
		 * an operator etc.
		 */

		/* check for 'double' character operators '&&' '||' '<<' '>>' '==' '!=' '<=' '>=' */
		switch (ch) { /* the second character */
			default: break;

			case '+': if ('+'==rv) rv=PP;  break;
			case '-': if ('-'==rv) rv=MM;  break;

			case '&': if ('&'==rv) rv=AND; break;
			case '|': if ('|'==rv) rv=OR;  break;

			case '<': if ('<'==rv) rv=SHL; break;
			case '>': if ('>'==rv) rv=SHR; break;


			case '=':
				switch (rv) {
					default: break;
					case '=': rv=EQ;	break;
					case '!': rv=NE;	break;
					case '<': rv=LE;	break;
					case '>': rv=GE;	break;
					case '+': rv=MODOP; rval->binop=OAdd;	break;
					case '-': rv=MODOP; rval->binop=OSub;	break;
					case '*': rv=MODOP; rval->binop=OMul;	break;
					case '/': rv=MODOP; rval->binop=ODiv;	break;
					case '%': rv=MODOP; rval->binop=OMod;	break;
					case '&': rv=MODOP; rval->binop=OAnd;	break;
					case '^': rv=MODOP; rval->binop=OXor;	break;
					case '|': rv=MODOP; rval->binop=OOr;	break;
				}
			break;
		}
		if (rv>255) getch(); /* skip second char */
		/* yyparse cannot deal with '\0' chars, so we translate it back to '\n'...*/
		if ((SHL==rv || SHR==rv) && '=' == ch) {
			getch();
			rval->binop = (SHL==rv ? OShL : OShR);
			rv=MODOP;
		}
		return rv ? rv : '\n';
	}
	return 0; /* seems to mean ERROR/EOF */
}

/* re-initialize a parser context to parse 'buf';
 * If called with a NULL argument, a new
 * context is created and initialized.
 *
 * RETURNS: initialized context
 */

static void
releaseStrings(CexpParserCtx ctx)
{
int			i;
char		**chppt;

	/* release the line string table */
	for (i=0,chppt=ctx->lineStrTbl;
		 i<sizeof(ctx->lineStrTbl)/sizeof(ctx->lineStrTbl[0]);
		 i++,chppt++) {
		if (*chppt) {
			free(*chppt);
			*chppt=0;
		}
	}
}

CexpParserCtx
cexpCreateParserCtx(FILE *outf, FILE *errf, RedirCb redir_cb, void *uarg)
{
CexpParserCtx	ctx=0;

	assert(ctx=(CexpParserCtx)malloc(sizeof(*ctx)));
	memset(ctx,0,sizeof(*ctx));
	ctx->rval_sym.value.type = TULong;
	ctx->rval.l              = 0;
	ctx->rval_sym.value.ptv  = &ctx->rval;
	ctx->rval_sym.name       = CEXP_LAST_RESULT_VAR_NAME;
	ctx->rval_sym.size       = sizeof(ctx->rval);
	ctx->rval_sym.flags      = 0;
	ctx->rval_sym.help       = "value of last evaluated expression";
	ctx->outf                = outf;
	ctx->errf                = errf;
	ctx->status              = -1;
	ctx->o_stdout            = 0;
	ctx->o_stderr            = 0;
	ctx->o_stdin             = 0;
	ctx->o_outf              = 0;
	ctx->o_errf              = 0;
	ctx->redir_cb            = redir_cb;
	ctx->cb_arg              = uarg;

	return ctx;
}

void
cexpResetParserCtx(CexpParserCtx ctx, const char *buf)
{
	ctx->chpt=buf;
	ctx->evalInhibit=0;
	ctx->status = -1;
	cexpUnredir(ctx);
	releaseStrings(ctx);
}

void
cexpFreeParserCtx(CexpParserCtx ctx)
{
	cexpUnredir(ctx);
	releaseStrings(ctx);
	free(ctx);
}

CexpSym
cexpParserCtxGetResult(CexpParserCtx ctx)
{
	return &ctx->rval_sym;
}

int
cexpParserCtxGetStatus(CexpParserCtx ctx)
{
	return ctx->status;
}

void
yyerror(CexpParserCtx ctx, const char*msg)
{
	if ( ctx->errf ) {
		fprintf(ctx->errf,"Cexp syntax error: %s\n", msg);
	}
}

/* Other errors that are not syntax errors */
static void
errmsg(CexpParserCtx ctx, const char *fmt, ...)
{
va_list ap;
	if ( ctx->errf ) {
		fprintf(ctx->errf,"Cexp error ");
		va_start(ap, fmt);
		vfprintf(ctx->errf, fmt, ap); 
		va_end(ap);
	}
}

static void
wrnmsg(CexpParserCtx ctx, const char *fmt, ...)
{
va_list ap;
	if ( ctx->errf ) {
		fprintf(ctx->errf,"Cexp warning ");
		va_start(ap, fmt);
		vfprintf(ctx->errf, fmt, ap); 
		va_end(ap);
	}
}


static int
cexpRedir(CexpParserCtx ctx, unsigned long op, void *oarg, void *iarg)
{
const char *opath = oarg;
const char *ipath = iarg;
FILE       *nof = 0, *nif = 0;
const char *mode;

	if ( !oarg && !iarg ) {
		errmsg(ctx, "(cexpRedir): NO PATH ARGUMENT ??\n");
		return -1;
	}

	if ( opath && (ctx->o_stdout || ctx->o_stderr) ) {
		errmsg(ctx, "(cexpRedir): OUTPUT ALREADY REDIRECTED ??\n");
		return -1;
	}

	if ( ipath && ctx->o_stdin ) {
		errmsg(ctx, "(cexpRedir): INPUT ALREADY REDIRECTED ??\n");
		return -1;
	}

	if ( ipath ) {
		if ( ! (nif = fopen(ipath, "r")) ) {
			if ( ctx->errf )
				fprintf(ctx->errf, "cexpRedir (IN) ERROR - unable to open file: %s\n", strerror(errno));
			return -1;
		}
		ctx->o_stdin = stdin;
		stdin        = nif;
	}

	if ( opath ) {
		if ( REDIRAPPEND == op || REDIRAPPENDBOTH == op )
			mode = "a";
		else
			mode = "w";

		if ( ! (nof = fopen(opath, mode)) ) {
			if ( ctx->errf )
				fprintf(ctx->errf, "cexpRedir (OUT) ERROR - unable to open file: %s\n", strerror(errno));
			if ( nif ) {
				stdin = ctx->o_stdin;
				fclose(nif);
			}
			return -1;
		}
		fflush(stdout);
		ctx->o_stdout = stdout;
		stdout = nof;

		if ( ctx->outf ) {
			fflush(ctx->outf);
			ctx->o_outf = ctx->outf;
			ctx->outf   = nof;
		}

		if ( REDIRBOTH == op || REDIRAPPENDBOTH == op ) {
			fflush(stderr);
			ctx->o_stderr = stderr;
			stderr = nof;

			if ( ctx->errf ) {
				fflush(ctx->errf);
				ctx->o_errf = ctx->errf;
				ctx->errf   = nof;
			}
		}
	}

	if ( ctx->redir_cb )
		ctx->redir_cb(ctx, ctx->cb_arg);

	return 0;
}

static void
cexpUnredir(CexpParserCtx ctx)
{
	if ( ctx->o_stdout ) {
		fclose(stdout);
		stdout = ctx->o_stdout;
		ctx->o_stdout = 0;
	}
	if ( ctx->o_outf ) {
		ctx->outf   = ctx->o_outf;
		ctx->o_outf = 0;
	}

	if ( ctx->o_stderr ) {
		stderr = ctx->o_stderr;
		ctx->o_stderr = 0;
	}
	if ( ctx->o_errf ) {
		ctx->errf   = ctx->o_errf;
		ctx->o_errf = 0;
	}

	if ( ctx->o_stdin ) {
		fclose(stdin);
		stdin = ctx->o_stdin;
		ctx->o_stdin = 0;
	}

	if ( ctx->redir_cb )
		ctx->redir_cb(ctx, ctx->cb_arg);
}

/* Trivial wrapper so that we can make sure
 * redirections are undone always and before
 * cexpparse() returns to the caller.
 */
int
cexpparse(CexpParserCtx ctx)
{
int rval;

	rval = __cexpparse(ctx);	
	cexpUnredir( ctx );

	return rval;
}

