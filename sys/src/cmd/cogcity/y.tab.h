/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 146 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
