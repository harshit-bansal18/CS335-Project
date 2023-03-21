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

#ifndef YY_YY_LALR1_FAST_TAB_H_INCLUDED
# define YY_YY_LALR1_FAST_TAB_H_INCLUDED
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
    CATCH = 281,                   /* CATCH  */
    FINALLY = 282,                 /* FINALLY  */
    SYNCHRONIZED = 283,            /* SYNCHRONIZED  */
    ASSERT = 284,                  /* ASSERT  */
    PLUS = 285,                    /* PLUS  */
    MINUS = 286,                   /* MINUS  */
    DIV = 287,                     /* DIV  */
    MODULO = 288,                  /* MODULO  */
    INCREMENT = 289,               /* INCREMENT  */
    DECREMENT = 290,               /* DECREMENT  */
    GEQ = 291,                     /* GEQ  */
    LEQ = 292,                     /* LEQ  */
    GT = 293,                      /* GT  */
    LT = 294,                      /* LT  */
    NEQ = 295,                     /* NEQ  */
    DEQ = 296,                     /* DEQ  */
    BITWISE_AND = 297,             /* BITWISE_AND  */
    BITWISE_OR = 298,              /* BITWISE_OR  */
    BITWISE_XOR = 299,             /* BITWISE_XOR  */
    BITWISE_COMPLEMENT = 300,      /* BITWISE_COMPLEMENT  */
    LEFT_SHIFT = 301,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 302,             /* RIGHT_SHIFT  */
    UNSIGNED_RIGHT_SHIFT = 303,    /* UNSIGNED_RIGHT_SHIFT  */
    AND = 304,                     /* AND  */
    OR = 305,                      /* OR  */
    NOT = 306,                     /* NOT  */
    ASSIGNMENT = 307,              /* ASSIGNMENT  */
    COLON = 308,                   /* COLON  */
    QM = 309,                      /* QM  */
    LPAREN = 310,                  /* LPAREN  */
    RPAREN = 311,                  /* RPAREN  */
    LCURLY = 312,                  /* LCURLY  */
    RCURLY = 313,                  /* RCURLY  */
    LSQUARE = 314,                 /* LSQUARE  */
    RSQUARE = 315,                 /* RSQUARE  */
    SEMICOLON = 316,               /* SEMICOLON  */
    COMMA = 317,                   /* COMMA  */
    DOT = 318,                     /* DOT  */
    CHAR_LITERAL = 319,            /* CHAR_LITERAL  */
    BOOLEAN_LITERAL = 320,         /* BOOLEAN_LITERAL  */
    NULL_LITERAL = 321,            /* NULL_LITERAL  */
    INTEGER_LITERAL = 322,         /* INTEGER_LITERAL  */
    FP_LITERAL = 323,              /* FP_LITERAL  */
    STRING = 324,                  /* STRING  */
    TEXT_BLOCK = 325,              /* TEXT_BLOCK  */
    IDENTIFIER = 326,              /* IDENTIFIER  */
    THIS = 327,                    /* THIS  */
    INSTANCEOF = 328,              /* INSTANCEOF  */
    SUPER = 329,                   /* SUPER  */
    THROW = 330,                   /* THROW  */
    THROWS = 331,                  /* THROWS  */
    EOF_ = 332,                    /* EOF_  */
    PACKAGE = 333,                 /* PACKAGE  */
    IMPORT = 334,                  /* IMPORT  */
    ASTERIK = 335,                 /* ASTERIK  */
    DO = 336,                      /* DO  */
    TRY = 337,                     /* TRY  */
    ASSIGN = 338                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 56 "parser/lalr1_fast.y"

    int num;
    int8_t b_no;
    double float_num;
    char* str;
    struct stackentry* stack_entry;
    struct Type *type;
    struct Identifier *id;
    // Type *type_;

#line 158 "lalr1_fast.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LALR1_FAST_TAB_H_INCLUDED  */
