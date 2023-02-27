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

#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    INT = 258,                     /* INT  */
    LONG = 259,                    /* LONG  */
    BYTE = 260,                    /* BYTE  */
    CHAR = 261,                    /* CHAR  */
    SHORT = 262,                   /* SHORT  */
    FLOAT = 263,                   /* FLOAT  */
    DOUBLE = 264,                  /* DOUBLE  */
    BOOLEAN = 265,                 /* BOOLEAN  */
    VAR = 266,                     /* VAR  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    FOR = 269,                     /* FOR  */
    WHILE = 270,                   /* WHILE  */
    BREAK = 271,                   /* BREAK  */
    CONTINUE = 272,                /* CONTINUE  */
    VOID = 273,                    /* VOID  */
    NEW = 274,                     /* NEW  */
    RETURN = 275,                  /* RETURN  */
    PUBLIC = 276,                  /* PUBLIC  */
    PRIVATE = 277,                 /* PRIVATE  */
    CLASS = 278,                   /* CLASS  */
    STATIC = 279,                  /* STATIC  */
    FINAL = 280,                   /* FINAL  */
    ASSERT = 281,                  /* ASSERT  */
    PLUS = 282,                    /* PLUS  */
    MINUS = 283,                   /* MINUS  */
    DIV = 284,                     /* DIV  */
    MODULO = 285,                  /* MODULO  */
    INCREMENT = 286,               /* INCREMENT  */
    DECREMENT = 287,               /* DECREMENT  */
    GEQ = 288,                     /* GEQ  */
    LEQ = 289,                     /* LEQ  */
    GT = 290,                      /* GT  */
    LT = 291,                      /* LT  */
    NEQ = 292,                     /* NEQ  */
    DEQ = 293,                     /* DEQ  */
    BITWISE_AND = 294,             /* BITWISE_AND  */
    BITWISE_OR = 295,              /* BITWISE_OR  */
    BITWISE_XOR = 296,             /* BITWISE_XOR  */
    BITWISE_COMPLEMENT = 297,      /* BITWISE_COMPLEMENT  */
    LEFT_SHIFT = 298,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 299,             /* RIGHT_SHIFT  */
    UNSIGNED_RIGHT_SHIFT = 300,    /* UNSIGNED_RIGHT_SHIFT  */
    AND = 301,                     /* AND  */
    OR = 302,                      /* OR  */
    NOT = 303,                     /* NOT  */
    ASSIGNMENT = 304,              /* ASSIGNMENT  */
    DOUBLE_COLON = 305,            /* DOUBLE_COLON  */
    COLON = 306,                   /* COLON  */
    QM = 307,                      /* QM  */
    LPAREN = 308,                  /* LPAREN  */
    RPAREN = 309,                  /* RPAREN  */
    LCURLY = 310,                  /* LCURLY  */
    RCURLY = 311,                  /* RCURLY  */
    LSQUARE = 312,                 /* LSQUARE  */
    RSQUARE = 313,                 /* RSQUARE  */
    SEMICOLON = 314,               /* SEMICOLON  */
    COMMA = 315,                   /* COMMA  */
    DOT = 316,                     /* DOT  */
    CHAR_LITERAL = 317,            /* CHAR_LITERAL  */
    BOOLEAN_LITERAL = 318,         /* BOOLEAN_LITERAL  */
    NULL_LITERAL = 319,            /* NULL_LITERAL  */
    INTEGER_LITERAL = 320,         /* INTEGER_LITERAL  */
    FP_LITERAL = 321,              /* FP_LITERAL  */
    STRING = 322,                  /* STRING  */
    TEXT_BLOCK = 323,              /* TEXT_BLOCK  */
    IDENTIFIER = 324,              /* IDENTIFIER  */
    THIS = 325,                    /* THIS  */
    INSTANCEOF = 326,              /* INSTANCEOF  */
    SUPER = 327,                   /* SUPER  */
    THROW = 328,                   /* THROW  */
    EOF_ = 329,                    /* EOF_  */
    IMPLEMENTS = 330,              /* IMPLEMENTS  */
    INTERFACE = 331,               /* INTERFACE  */
    EXTENDS = 332,                 /* EXTENDS  */
    PACKAGE = 333,                 /* PACKAGE  */
    IMPORT = 334,                  /* IMPORT  */
    ASTERIK = 335,                 /* ASTERIK  */
    DIAMOND = 336                  /* DIAMOND  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "parse.y"

    int num;
    double float_num;
    char* str;

#line 151 "parse.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */
