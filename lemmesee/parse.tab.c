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
#line 1 "parse.y"

    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include <iomanip>
    #include <vector>

    
    #define YYDEBUG 1
    using namespace std;

    extern "C" int yylex();
    extern "C" FILE *yyin;
    extern "C" int yylineno;
    

    int yyerror(const char *);

    char* concat_str(int num_str, ...) {
        va_list arglist;
        char *arg;

        // cout << "inside concat_str ";

        char *buf = (char*)malloc(sizeof(char)*128);
        va_start(arglist, num_str);

        strcpy(buf, va_arg(arglist, char*));
        strcat(buf, " ");
        for (int i = 1; i < num_str; i++) {
            arg = va_arg(arglist, char*);
            strcat(buf, arg);
            strcat(buf, " ");
            try {
                free(arg);
            }
            catch(std::exception ex) {
                // cout << "exception occured " << ex << endl;
            }
        }

        va_end(arglist);
        // cout << "buf: " << buf << endl;
        return buf;
    }

    void throw_error(char* msg, int line) {
        printf("syntax error: line: %d: %s\n", msg, line);
        exit(1);
    }

    void check_unq_mthd_id(char *id) {
        if (!strcmp(id, "yield")) {
            printf("%s not allowed here\n", id);
            throw_error("unqualified method identifier error\n", yylineno);
        }
    }




#line 135 "parse.tab.c"

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

#include "parse.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_LONG = 4,                       /* LONG  */
  YYSYMBOL_BYTE = 5,                       /* BYTE  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_SHORT = 7,                      /* SHORT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 10,                   /* BOOLEAN  */
  YYSYMBOL_VAR = 11,                       /* VAR  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_VOID = 18,                      /* VOID  */
  YYSYMBOL_NEW = 19,                       /* NEW  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_PUBLIC = 21,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 22,                   /* PRIVATE  */
  YYSYMBOL_CLASS = 23,                     /* CLASS  */
  YYSYMBOL_STATIC = 24,                    /* STATIC  */
  YYSYMBOL_FINAL = 25,                     /* FINAL  */
  YYSYMBOL_ASSERT = 26,                    /* ASSERT  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MINUS = 28,                     /* MINUS  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_MODULO = 30,                    /* MODULO  */
  YYSYMBOL_INCREMENT = 31,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 32,                 /* DECREMENT  */
  YYSYMBOL_GEQ = 33,                       /* GEQ  */
  YYSYMBOL_LEQ = 34,                       /* LEQ  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_LT = 36,                        /* LT  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_DEQ = 38,                       /* DEQ  */
  YYSYMBOL_BITWISE_AND = 39,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 40,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 41,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_COMPLEMENT = 42,        /* BITWISE_COMPLEMENT  */
  YYSYMBOL_LEFT_SHIFT = 43,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 44,               /* RIGHT_SHIFT  */
  YYSYMBOL_UNSIGNED_RIGHT_SHIFT = 45,      /* UNSIGNED_RIGHT_SHIFT  */
  YYSYMBOL_AND = 46,                       /* AND  */
  YYSYMBOL_OR = 47,                        /* OR  */
  YYSYMBOL_NOT = 48,                       /* NOT  */
  YYSYMBOL_ASSIGNMENT = 49,                /* ASSIGNMENT  */
  YYSYMBOL_DOUBLE_COLON = 50,              /* DOUBLE_COLON  */
  YYSYMBOL_COLON = 51,                     /* COLON  */
  YYSYMBOL_QM = 52,                        /* QM  */
  YYSYMBOL_LPAREN = 53,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 54,                    /* RPAREN  */
  YYSYMBOL_LCURLY = 55,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 56,                    /* RCURLY  */
  YYSYMBOL_LSQUARE = 57,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 58,                   /* RSQUARE  */
  YYSYMBOL_SEMICOLON = 59,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 60,                     /* COMMA  */
  YYSYMBOL_DOT = 61,                       /* DOT  */
  YYSYMBOL_CHAR_LITERAL = 62,              /* CHAR_LITERAL  */
  YYSYMBOL_BOOLEAN_LITERAL = 63,           /* BOOLEAN_LITERAL  */
  YYSYMBOL_NULL_LITERAL = 64,              /* NULL_LITERAL  */
  YYSYMBOL_INTEGER_LITERAL = 65,           /* INTEGER_LITERAL  */
  YYSYMBOL_FP_LITERAL = 66,                /* FP_LITERAL  */
  YYSYMBOL_STRING = 67,                    /* STRING  */
  YYSYMBOL_TEXT_BLOCK = 68,                /* TEXT_BLOCK  */
  YYSYMBOL_IDENTIFIER = 69,                /* IDENTIFIER  */
  YYSYMBOL_THIS = 70,                      /* THIS  */
  YYSYMBOL_INSTANCEOF = 71,                /* INSTANCEOF  */
  YYSYMBOL_SUPER = 72,                     /* SUPER  */
  YYSYMBOL_THROW = 73,                     /* THROW  */
  YYSYMBOL_EOF_ = 74,                      /* EOF_  */
  YYSYMBOL_IMPLEMENTS = 75,                /* IMPLEMENTS  */
  YYSYMBOL_INTERFACE = 76,                 /* INTERFACE  */
  YYSYMBOL_EXTENDS = 77,                   /* EXTENDS  */
  YYSYMBOL_PACKAGE = 78,                   /* PACKAGE  */
  YYSYMBOL_IMPORT = 79,                    /* IMPORT  */
  YYSYMBOL_ASTERIK = 80,                   /* ASTERIK  */
  YYSYMBOL_DIAMOND = 81,                   /* DIAMOND  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_Program = 83,                   /* Program  */
  YYSYMBOL_CompilationUnit = 84,           /* CompilationUnit  */
  YYSYMBOL_ClassOrInterfaceDeclarations = 85, /* ClassOrInterfaceDeclarations  */
  YYSYMBOL_ClassOrInterfaceDeclaration = 86, /* ClassOrInterfaceDeclaration  */
  YYSYMBOL_PackageDeclaration = 87,        /* PackageDeclaration  */
  YYSYMBOL_ImportDeclaration = 88,         /* ImportDeclaration  */
  YYSYMBOL_Literal = 89,                   /* Literal  */
  YYSYMBOL_UnannType = 90,                 /* UnannType  */
  YYSYMBOL_PrimitiveType = 91,             /* PrimitiveType  */
  YYSYMBOL_NumericType = 92,               /* NumericType  */
  YYSYMBOL_IntegralType = 93,              /* IntegralType  */
  YYSYMBOL_FloatingPointType = 94,         /* FloatingPointType  */
  YYSYMBOL_ReferenceType = 95,             /* ReferenceType  */
  YYSYMBOL_ClassOrInterfaceType = 96,      /* ClassOrInterfaceType  */
  YYSYMBOL_ClassType = 97,                 /* ClassType  */
  YYSYMBOL_InterfaceType = 98,             /* InterfaceType  */
  YYSYMBOL_ArrayType = 99,                 /* ArrayType  */
  YYSYMBOL_Dims = 100,                     /* Dims  */
  YYSYMBOL_TypeName = 101,                 /* TypeName  */
  YYSYMBOL_Modifiers = 102,                /* Modifiers  */
  YYSYMBOL_Modifier = 103,                 /* Modifier  */
  YYSYMBOL_ClassDeclaration = 104,         /* ClassDeclaration  */
  YYSYMBOL_Super = 105,                    /* Super  */
  YYSYMBOL_Interfaces = 106,               /* Interfaces  */
  YYSYMBOL_InterfaceTypeList = 107,        /* InterfaceTypeList  */
  YYSYMBOL_ClassBody = 108,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 109,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 110,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 111,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 112,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclaratorList = 113,   /* VariableDeclaratorList  */
  YYSYMBOL_VariableDeclarator = 114,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 115,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 116,      /* VariableInitializer  */
  YYSYMBOL_MethodDeclaration = 117,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 118,             /* MethodHeader  */
  YYSYMBOL_MethodDeclarator = 119,         /* MethodDeclarator  */
  YYSYMBOL_FormalParameterList = 120,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 121,          /* FormalParameter  */
  YYSYMBOL_MethodBody = 122,               /* MethodBody  */
  YYSYMBOL_StaticInitializer = 123,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 124,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorDeclarator = 125,    /* ConstructorDeclarator  */
  YYSYMBOL_ConstructorBody = 126,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation = 127, /* ExplicitConstructorInvocation  */
  YYSYMBOL_ArrayInitializer = 128,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializerList = 129,  /* VariableInitializerList  */
  YYSYMBOL_InterfaceDeclaration = 130,     /* InterfaceDeclaration  */
  YYSYMBOL_InterfaceExtends = 131,         /* InterfaceExtends  */
  YYSYMBOL_InterfaceBody = 132,            /* InterfaceBody  */
  YYSYMBOL_InterfaceMembers = 133,         /* InterfaceMembers  */
  YYSYMBOL_InterfaceMemberDeclaration = 134, /* InterfaceMemberDeclaration  */
  YYSYMBOL_ConstantDeclaration = 135,      /* ConstantDeclaration  */
  YYSYMBOL_InterfaceMethodDeclaration = 136, /* InterfaceMethodDeclaration  */
  YYSYMBOL_Primary = 137,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 138,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassInstanceCreationExpression = 139, /* ClassInstanceCreationExpression  */
  YYSYMBOL_FieldAccess = 140,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 141,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 142,         /* MethodInvocation  */
  YYSYMBOL_ArgumentListopt = 143,          /* ArgumentListopt  */
  YYSYMBOL_ArgumentList = 144,             /* ArgumentList  */
  YYSYMBOL_ArrayCreationExpression = 145,  /* ArrayCreationExpression  */
  YYSYMBOL_Dimsopt = 146,                  /* Dimsopt  */
  YYSYMBOL_DimExprs = 147,                 /* DimExprs  */
  YYSYMBOL_DimExpr = 148,                  /* DimExpr  */
  YYSYMBOL_ExpressionOpts = 149,           /* ExpressionOpts  */
  YYSYMBOL_Expression = 150,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 151,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 152,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 153,             /* LeftHandSide  */
  YYSYMBOL_AssignmentOperator = 154,       /* AssignmentOperator  */
  YYSYMBOL_ConditionalExpression = 155,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 156,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 157, /* ConditionalAndExpression  */
  YYSYMBOL_InclusiveOrExpression = 158,    /* InclusiveOrExpression  */
  YYSYMBOL_ExclusiveOrExpression = 159,    /* ExclusiveOrExpression  */
  YYSYMBOL_AndExpression = 160,            /* AndExpression  */
  YYSYMBOL_EqualityExpression = 161,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 162,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 163,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 164,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 165, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 166,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 167,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 168,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 169, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_PostfixExpression = 170,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 171,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 172,  /* PostDecrementExpression  */
  YYSYMBOL_CastExpression = 173,           /* CastExpression  */
  YYSYMBOL_Block = 174,                    /* Block  */
  YYSYMBOL_BlockStatements = 175,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 176,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclarationStatement = 177, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 178, /* LocalVariableDeclaration  */
  YYSYMBOL_Statement = 179,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 180,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 181, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_EmptyStatement = 182,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 183,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 184, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 185,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 186,      /* StatementExpression  */
  YYSYMBOL_IfThenStatement = 187,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 188,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 189, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_AssertStatement = 190,          /* AssertStatement  */
  YYSYMBOL_WhileStatement = 191,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 192,  /* WhileStatementNoShortIf  */
  YYSYMBOL_ForStatement = 193,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 194,    /* ForStatementNoShortIf  */
  YYSYMBOL_BasicForStatement = 195,        /* BasicForStatement  */
  YYSYMBOL_BasicForStatementNoShortIf = 196, /* BasicForStatementNoShortIf  */
  YYSYMBOL_ForInitOpt = 197,               /* ForInitOpt  */
  YYSYMBOL_ForInit = 198,                  /* ForInit  */
  YYSYMBOL_ForUpdateOpts = 199,            /* ForUpdateOpts  */
  YYSYMBOL_ForUpdate = 200,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 201,  /* StatementExpressionList  */
  YYSYMBOL_CommaStatementExpressions = 202, /* CommaStatementExpressions  */
  YYSYMBOL_EnhancedForStatement = 203,     /* EnhancedForStatement  */
  YYSYMBOL_EnhancedForStatementNoShortIf = 204, /* EnhancedForStatementNoShortIf  */
  YYSYMBOL_BreakStatement = 205,           /* BreakStatement  */
  YYSYMBOL_ContinueStatement = 206,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 207,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 208,           /* ThrowStatement  */
  YYSYMBOL_IdentifierOpts = 209            /* IdentifierOpts  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1795

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  128
/* YYNRULES -- Number of rules.  */
#define YYNRULES  283
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  491

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   336


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   118,   119,   120,   124,   125,   129,   130,
     135,   139,   140,   150,   151,   152,   153,   154,   155,   156,
     166,   167,   171,   172,   176,   177,   180,   180,   180,   180,
     180,   182,   182,   189,   190,   194,   198,   202,   226,   227,
     231,   232,   247,   248,   256,   257,   262,   262,   262,   272,
     273,   274,   275,   276,   277,   278,   279,   283,   287,   291,
     292,   296,   297,   301,   302,   306,   307,   308,   313,   314,
     318,   319,   323,   324,   328,   329,   333,   334,   338,   339,
     343,   347,   348,   349,   350,   355,   356,   360,   361,   365,
     370,   374,   378,   379,   383,   384,   389,   390,   391,   392,
     396,   397,   401,   402,   403,   404,   408,   409,   415,   416,
     417,   418,   422,   425,   426,   430,   431,   435,   436,   440,
     444,   452,   453,   456,   457,   458,   459,   460,   461,   462,
     467,   472,   473,   477,   478,   481,   482,   483,   495,   496,
     501,   502,   505,   506,   507,   508,   511,   512,   515,   516,
     519,   521,   522,   525,   528,   529,   533,   537,   538,   539,
     542,   545,   546,   549,   550,   553,   554,   557,   558,   561,
     562,   565,   566,   569,   570,   571,   574,   575,   576,   577,
     578,   579,   585,   586,   587,   588,   591,   592,   593,   596,
     597,   598,   599,   602,   603,   604,   605,   606,   609,   612,
     615,   616,   617,   618,   621,   622,   623,   624,   626,   629,
     632,   633,   634,   635,   646,   647,   650,   651,   655,   656,
     663,   666,   670,   671,   672,   673,   674,   675,   678,   679,
     680,   681,   682,   685,   686,   687,   688,   689,   690,   691,
     692,   695,   698,   701,   704,   706,   707,   708,   709,   710,
     711,   712,   714,   717,   720,   723,   724,   727,   730,   733,
     734,   737,   738,   741,   744,   747,   748,   751,   752,   755,
     756,   759,   762,   763,   766,   767,   770,   773,   776,   779,
     783,   786,   789,   790
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "LONG", "BYTE",
  "CHAR", "SHORT", "FLOAT", "DOUBLE", "BOOLEAN", "VAR", "IF", "ELSE",
  "FOR", "WHILE", "BREAK", "CONTINUE", "VOID", "NEW", "RETURN", "PUBLIC",
  "PRIVATE", "CLASS", "STATIC", "FINAL", "ASSERT", "PLUS", "MINUS", "DIV",
  "MODULO", "INCREMENT", "DECREMENT", "GEQ", "LEQ", "GT", "LT", "NEQ",
  "DEQ", "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_COMPLEMENT",
  "LEFT_SHIFT", "RIGHT_SHIFT", "UNSIGNED_RIGHT_SHIFT", "AND", "OR", "NOT",
  "ASSIGNMENT", "DOUBLE_COLON", "COLON", "QM", "LPAREN", "RPAREN",
  "LCURLY", "RCURLY", "LSQUARE", "RSQUARE", "SEMICOLON", "COMMA", "DOT",
  "CHAR_LITERAL", "BOOLEAN_LITERAL", "NULL_LITERAL", "INTEGER_LITERAL",
  "FP_LITERAL", "STRING", "TEXT_BLOCK", "IDENTIFIER", "THIS", "INSTANCEOF",
  "SUPER", "THROW", "EOF_", "IMPLEMENTS", "INTERFACE", "EXTENDS",
  "PACKAGE", "IMPORT", "ASTERIK", "DIAMOND", "$accept", "Program",
  "CompilationUnit", "ClassOrInterfaceDeclarations",
  "ClassOrInterfaceDeclaration", "PackageDeclaration", "ImportDeclaration",
  "Literal", "UnannType", "PrimitiveType", "NumericType", "IntegralType",
  "FloatingPointType", "ReferenceType", "ClassOrInterfaceType",
  "ClassType", "InterfaceType", "ArrayType", "Dims", "TypeName",
  "Modifiers", "Modifier", "ClassDeclaration", "Super", "Interfaces",
  "InterfaceTypeList", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "VariableDeclaratorList", "VariableDeclarator", "VariableDeclaratorId",
  "VariableInitializer", "MethodDeclaration", "MethodHeader",
  "MethodDeclarator", "FormalParameterList", "FormalParameter",
  "MethodBody", "StaticInitializer", "ConstructorDeclaration",
  "ConstructorDeclarator", "ConstructorBody",
  "ExplicitConstructorInvocation", "ArrayInitializer",
  "VariableInitializerList", "InterfaceDeclaration", "InterfaceExtends",
  "InterfaceBody", "InterfaceMembers", "InterfaceMemberDeclaration",
  "ConstantDeclaration", "InterfaceMethodDeclaration", "Primary",
  "PrimaryNoNewArray", "ClassInstanceCreationExpression", "FieldAccess",
  "ArrayAccess", "MethodInvocation", "ArgumentListopt", "ArgumentList",
  "ArrayCreationExpression", "Dimsopt", "DimExprs", "DimExpr",
  "ExpressionOpts", "Expression", "AssignmentExpression", "Assignment",
  "LeftHandSide", "AssignmentOperator", "ConditionalExpression",
  "ConditionalOrExpression", "ConditionalAndExpression",
  "InclusiveOrExpression", "ExclusiveOrExpression", "AndExpression",
  "EqualityExpression", "RelationalExpression", "ShiftExpression",
  "AdditiveExpression", "MultiplicativeExpression", "UnaryExpression",
  "PreIncrementExpression", "PreDecrementExpression",
  "UnaryExpressionNotPlusMinus", "PostfixExpression",
  "PostIncrementExpression", "PostDecrementExpression", "CastExpression",
  "Block", "BlockStatements", "BlockStatement",
  "LocalVariableDeclarationStatement", "LocalVariableDeclaration",
  "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "IfThenStatement", "IfThenElseStatement",
  "IfThenElseStatementNoShortIf", "AssertStatement", "WhileStatement",
  "WhileStatementNoShortIf", "ForStatement", "ForStatementNoShortIf",
  "BasicForStatement", "BasicForStatementNoShortIf", "ForInitOpt",
  "ForInit", "ForUpdateOpts", "ForUpdate", "StatementExpressionList",
  "CommaStatementExpressions", "EnhancedForStatement",
  "EnhancedForStatementNoShortIf", "BreakStatement", "ContinueStatement",
  "ReturnStatement", "ThrowStatement", "IdentifierOpts", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-407)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-252)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,     5,     5,    81,    20,    13,    19,  -407,   110,   192,
    -407,  -407,  -407,  -407,    40,  -407,    89,    19,  -407,    19,
     120,  -407,  -407,  -407,    19,  -407,   103,  -407,    65,    11,
     -10,  -407,    19,   118,   123,  -407,  -407,   140,   745,     5,
       5,   190,    28,  -407,   981,     5,   199,  -407,    11,   -10,
    -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,   147,
     201,  -407,   208,   206,  -407,  -407,  -407,  -407,   276,   910,
    -407,  -407,  -407,  -407,   201,  -407,  -407,   209,  -407,  -407,
     232,   210,  -407,  -407,  -407,   190,  -407,  -407,   623,  -407,
     237,  1052,  -407,  -407,  -407,   210,  -407,   190,    28,  -407,
     199,  -407,   257,  -407,   874,  -407,   174,   257,   175,  -407,
     154,  -407,   147,   206,   209,  -407,  -407,  -407,  -407,   945,
    -407,     5,  -407,  -407,  -407,  -407,  -407,   190,  -407,  -407,
     422,   260,   262,   297,   285,   285,    55,  1692,  1692,  1692,
    1692,  1692,  -407,  -407,  -407,  -407,  -407,  -407,  -407,  -407,
    -407,   311,  -407,   303,  1692,  -407,   301,   137,   318,   320,
      93,   345,   351,   158,  -407,  -407,   361,  -407,  -407,   316,
     328,   359,  -407,  1016,  -407,  -407,  -407,  -407,  -407,  -407,
    -407,  -407,   349,  -407,  -407,  -407,  -407,  -407,  -407,  -407,
    -407,  -407,  -407,  -407,  -407,   301,    30,  -407,  -407,   301,
    1588,   354,  -407,   218,  -407,  -407,  -407,   363,   161,  1087,
    1158,  -407,  -407,  -407,   114,  1692,  1370,  1692,  -407,   362,
     364,   357,  -407,   148,  1692,  1692,  1692,  1692,  1300,  -407,
    -407,   375,  -407,  -407,  -407,  -407,    63,   376,   395,   398,
     402,   355,   197,   246,   371,    26,  -407,  -407,  -407,  -407,
     316,  -407,  -407,  -407,   185,   132,  -407,  -407,  -407,  -407,
     388,  1393,   377,   386,  -407,   387,  1692,  1692,   384,  1692,
    -407,  1692,  -407,  -407,  -407,  -407,  -407,   401,  -407,   334,
    -407,  1484,  -407,  -407,  -407,  -407,  -407,  1692,  1692,  -407,
    1229,  -407,  -407,   405,   410,   403,   406,  -407,  -407,   408,
    -407,  -407,  1640,   409,   357,  -407,  1692,   409,   357,  -407,
    -407,  -407,  -407,   -36,   323,   412,  -407,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,    55,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  -407,
    -407,  -407,   414,  -407,   415,   411,  -407,   417,   419,   421,
    -407,  -407,  -407,   427,  -407,   181,   430,   433,  -407,  1455,
    1692,  1328,  -407,  1692,  1393,   431,   432,  -407,  -407,  -407,
    -407,   435,  -407,  -407,  1692,   436,   437,  1640,   439,  1723,
     376,   444,   395,   398,   402,   355,   197,   197,   246,   246,
     246,   246,   431,  -407,  -407,  -407,   191,   371,   371,   371,
      26,    26,  -407,  -407,  -407,   438,  1692,  -407,  1692,  -407,
    1692,  -407,  -407,  -407,  1536,  -407,  -407,   443,   445,   446,
     449,  -407,   455,   488,  -407,  -407,  -407,  -407,  -407,  -407,
     448,   403,   453,  -407,  -407,  -407,  -407,  -407,  1692,  1723,
    -407,  1692,  -407,  -407,  -407,   454,  -407,   462,  -407,  -407,
    1692,  1370,  1692,  1455,  1393,  1393,  -407,  1328,  -407,  -407,
    -407,  -407,  -407,   463,   467,   460,   466,  -407,  -407,  -407,
     468,  -407,  -407,  1455,  1692,  1692,  1455,  1393,   510,   470,
     469,  -407,  -407,  1455,  1455,  1328,  -407,  -407,   471,  1455,
    -407
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       1,     2,    46,    47,     0,    48,     0,     5,     6,     0,
       0,    44,     8,     9,     4,    10,     0,    11,     0,     0,
       0,     7,     3,     0,     0,    45,    43,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,   110,     0,     0,
      12,    28,    29,    26,    30,    27,    31,    32,    23,     0,
      48,    62,     0,     0,    20,    21,    24,    25,     0,     0,
      64,    65,    68,    69,     0,    67,    66,     0,    37,    59,
      35,    58,    36,    57,    54,     0,    52,   114,     0,   119,
       0,     0,   115,   117,   118,   112,   109,     0,     0,    49,
       0,   111,     0,    84,     0,    91,     0,    77,     0,    73,
      75,    82,     0,     0,     0,    61,    63,    80,    90,     0,
      93,     0,    56,   120,   113,   116,    53,     0,    51,   108,
       0,     0,     0,     0,   283,   283,     0,   152,     0,     0,
       0,     0,   214,   241,    15,    18,    19,    13,    14,    16,
      17,    42,   124,     0,     0,   123,     0,   205,   204,   121,
     126,   127,   128,   129,   122,   245,     0,   246,   247,     0,
     248,   249,   233,     0,   217,   218,   220,   219,   222,   234,
     223,   235,     0,   224,   225,   236,   226,   227,   259,   260,
     237,   238,   239,   240,    95,     0,     0,    88,    71,     0,
       0,     0,    83,     0,    81,    92,    99,   124,     0,     0,
       0,    60,    55,    85,     0,     0,   266,     0,   282,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,   126,
     129,     0,   151,   153,   155,   154,   161,   163,   165,   167,
     169,   171,   173,   176,   182,   186,   189,   193,   194,   197,
     200,   206,   207,   203,     0,   205,   127,   128,   198,   199,
       0,     0,     0,     0,    77,   221,   138,     0,     0,     0,
     160,     0,   208,   209,   215,   216,   244,    89,    94,     0,
      72,     0,    74,    79,    78,    76,    70,   138,   138,    98,
       0,    96,    86,     0,   268,   272,     0,   265,   267,     0,
     278,   279,     0,     0,   146,   148,   138,     0,   146,   195,
     196,   201,   202,     0,   205,     0,   280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     125,   242,   132,   281,     0,   139,   140,     0,   131,     0,
     156,    87,   103,     0,   107,     0,     0,     0,    97,     0,
       0,     0,   273,   152,     0,    41,     0,   144,   147,   142,
     149,     0,   145,   143,     0,     0,     0,     0,     0,   125,
     164,     0,   166,   168,   170,   172,   175,   174,   180,   179,
     178,   177,     0,   181,    33,    34,    35,   183,   184,   185,
     187,   188,   191,   192,   190,     0,   138,   135,     0,   133,
     138,   134,   105,   102,     0,   100,   101,     0,     0,     0,
      42,   252,     0,   222,   229,   230,   231,   232,   261,   262,
       0,   275,     0,   257,    40,   150,   130,   210,     0,     0,
     212,     0,    38,    39,   256,     0,   141,     0,   104,   106,
       0,   266,     0,     0,     0,     0,   274,   270,   211,   213,
     162,   137,   136,     0,   268,     0,     0,   243,   253,   276,
       0,   269,   271,     0,     0,   152,     0,     0,     0,     0,
       0,   258,   263,     0,     0,   270,   254,   277,     0,     0,
     264
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -407,  -407,  -407,    72,   131,  -407,   521,  -407,   -19,  -132,
    -125,  -407,  -407,  -407,   -34,   391,   413,  -407,  -201,    -1,
      85,   -11,  -407,     6,   482,   486,    34,  -407,   473,  -407,
     -21,   -83,   336,   341,  -274,  -407,     2,    54,   407,   259,
    -407,  -407,  -407,   475,   434,  -407,   -15,  -407,  -407,   495,
     -20,  -407,   461,  -407,  -407,  -407,  -407,  -102,   279,   485,
     -88,  -273,  -407,  -407,   247,   335,   -41,  -339,   423,  -407,
      -3,  -407,  -407,   116,  -407,   245,   244,   248,   249,   243,
      79,   -24,   -23,    73,  -127,    56,    96,  -371,   195,   305,
     373,  -407,    91,   -91,  -163,  -407,  -213,  -234,   -40,  -327,
    -407,  -407,  -407,  -407,  -211,  -407,  -407,  -407,  -407,  -407,
    -407,  -407,  -407,  -407,  -407,   124,  -407,    82,  -407,  -406,
     143,  -407,  -407,  -407,  -407,  -407,  -407,   441
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    17,    18,     5,     6,   155,   156,    64,
      65,    66,    67,   393,    78,    83,    79,   395,   368,   157,
      20,    21,    22,    41,    42,    81,    43,    69,    70,    71,
      72,   108,   109,   110,   282,    73,    74,   103,   196,   197,
     117,    75,    76,    77,   120,   209,   283,   355,    23,    46,
      47,    91,    92,    93,    94,   158,   159,   229,   161,   162,
     230,   344,   345,   164,   369,   304,   305,   231,   346,   233,
     234,   166,   271,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   172,   173,   174,   175,   176,   177,   422,   178,
     179,   180,   424,   181,   182,   183,   184,   425,   185,   186,
     426,   187,   427,   188,   428,   296,   297,   470,   471,   298,
     362,   189,   429,   190,   191,   192,   193,   219
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       8,     9,   160,   294,   221,   295,    82,   354,   440,    35,
     275,   222,   258,   259,   356,   357,   163,   160,   374,    63,
     303,   375,   307,    89,   432,    63,    96,   341,   210,   101,
     203,   163,   423,   371,    12,    13,    14,    15,    80,    80,
      12,    13,    14,    15,    80,    44,    90,   275,    85,   113,
      63,   472,     1,     2,    97,   335,   336,    35,    51,    52,
      53,    54,    55,    56,    57,    58,    38,    45,   459,   113,
      89,   160,    63,   265,     7,    84,    86,    35,    24,   472,
     129,    10,    99,    38,   278,   163,    39,   195,    40,    16,
     279,    32,     2,    90,    11,    16,   313,   309,   310,   311,
     312,   165,    82,   222,   127,    40,   337,   160,   160,    29,
     317,   195,   376,   378,   160,   318,   165,   111,   290,   122,
      80,   163,   163,    68,     7,   421,   423,   275,   163,    88,
     433,   126,   128,   445,    36,    80,   480,   447,   255,   255,
     449,    12,    13,    33,    15,    37,   423,  -251,    31,   423,
     431,   105,  -251,  -251,    68,    31,   423,   423,    30,   160,
     167,   212,   423,    31,   434,   118,   202,   204,   292,    25,
     165,    26,    36,   163,   279,   167,    88,    51,    52,    53,
      54,    55,    56,    57,    58,   266,  -157,    48,   160,   267,
     266,   442,    49,    26,   267,   443,    34,   392,    26,    50,
     168,   306,   163,   200,   222,   302,   165,   165,   402,   403,
     404,   201,  -250,   165,   288,   168,   102,  -250,  -250,   341,
     468,   469,   262,   255,   255,   255,   255,   314,   194,   167,
     325,   326,   327,   328,   198,   199,   338,   413,   464,   421,
     295,   414,   433,   482,   339,    38,   295,   437,   375,   468,
     469,    27,    26,    28,    44,   482,   104,   160,   165,   160,
     195,   106,   160,   370,   119,   167,   167,   370,   329,   168,
     121,   163,   167,   163,   295,   107,   163,   286,   199,    51,
      52,    53,    54,    55,    56,    57,    58,   165,   367,   330,
     331,   332,   372,    26,   112,   394,   123,    12,    13,   169,
      15,   388,   389,   390,   391,   168,   168,   397,   398,   399,
     130,   458,   168,   215,   169,   216,   255,   167,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   396,   255,
     255,   255,   255,   255,   255,   255,   255,    51,    52,    53,
      54,    55,    56,    57,    58,    62,   167,   272,   273,   160,
     217,   160,   160,   160,   218,   160,   165,   168,   165,  -206,
    -206,   165,   261,   163,   262,   163,   163,   163,   169,   163,
     264,   160,  -157,   255,   160,   160,   266,   269,   255,   268,
     377,   160,   160,   160,    26,   163,   168,   160,   163,   163,
    -207,  -207,   323,   324,  -158,   163,   163,   163,   333,   334,
    -159,   163,   386,   387,   169,   169,   400,   401,   276,   170,
     270,   169,   285,   467,   302,   167,   287,   167,   256,   256,
     167,   300,   319,   301,   170,    51,    52,    53,    54,    55,
      56,    57,    58,   478,   316,   320,   481,   255,   255,   321,
     255,   322,   340,   486,   487,   343,   342,   199,   165,   490,
     165,   165,   165,   348,   165,   168,   169,   168,   201,   359,
     168,   360,   364,   361,   281,   363,   379,   406,   454,   407,
     165,   408,   410,   165,   165,   409,   213,   171,   170,   411,
     165,   165,   165,   412,   415,   169,   165,   416,   375,   436,
     435,   438,   171,   439,   365,   441,   450,   444,   451,   452,
     453,  -228,   455,   256,   256,   256,   256,   167,   461,   167,
     167,   167,   457,   167,   170,   170,   462,   473,   474,   475,
     476,   170,   477,   483,   484,   489,    19,   223,   485,   167,
      98,    95,   167,   167,   211,   280,   277,   214,   351,   167,
     167,   167,   116,   114,   100,   167,   171,   168,   205,   168,
     168,   168,   125,   168,   169,   373,   169,   460,   308,   169,
     232,   254,   380,   382,   260,   385,   170,   488,   383,   168,
     384,     0,   168,   168,   456,   465,   220,   263,     0,   168,
     168,   168,   171,   171,     0,   168,     0,     0,     0,   171,
       0,     0,     0,     0,     0,   170,   256,     0,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,     0,   256,
     256,   256,   256,   256,   256,   256,   256,     0,     0,     0,
       0,     0,     0,   284,   257,   257,    51,    52,    53,    54,
      55,    56,    57,    58,   171,     0,     0,     0,   293,     0,
     299,   112,     0,     0,    12,    13,   169,    15,   169,   169,
     169,   315,   169,   256,     0,     0,     0,     0,   256,     0,
       0,     0,     0,   171,   170,     0,   170,     0,   169,   170,
       0,   169,   169,     0,     0,     0,     0,     0,   169,   169,
     169,     0,     0,     0,   169,     0,     0,     0,     0,     0,
     347,     0,   349,     0,   350,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,     0,   257,
     257,   257,   257,     0,     0,     0,     0,   256,   256,     0,
     256,     0,     0,     0,     0,   366,     0,     0,     0,     0,
       0,     0,   171,     0,   171,     0,     0,   171,     0,     0,
       0,   381,     0,     0,     0,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,    58,   170,     0,   170,   170,
     170,   405,   170,    59,     0,     0,    12,    13,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,   170,     0,
       0,   170,   170,   430,     0,     0,   232,     0,   170,   170,
     170,     0,     0,     0,   170,     0,     0,     0,     0,     0,
     347,    61,   257,     0,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,    62,   257,   257,   257,   257,   257,
     257,   257,   257,     0,   171,     0,   171,   171,   171,     0,
     171,   446,     0,     0,     0,     0,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,   171,     0,     0,   171,
     171,     0,     0,     0,     0,     0,   171,   171,   171,   257,
       0,     0,   171,     0,   257,     0,     0,     0,     0,     0,
       0,     0,     0,   463,     0,   466,     0,    51,    52,    53,
      54,    55,    56,    57,    58,     0,   131,     0,   132,   133,
     134,   135,     0,   136,   137,     0,     0,   479,   232,     0,
     138,     0,     0,     0,     0,   139,   140,     0,     0,     0,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,   257,   257,     0,   257,   141,    59,   104,
     142,    12,    13,   143,    60,     0,   144,   145,   146,   147,
     148,   149,   150,   151,   152,     0,   153,   154,    51,    52,
      53,    54,    55,    56,    57,    58,     0,   131,     0,   132,
     133,   134,   135,     0,   136,   137,   115,     0,     0,     0,
       0,   138,     0,     0,     0,     0,   139,   140,     0,    62,
       0,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,     0,     0,     0,     0,   141,    59,
     104,   206,    12,    13,   143,    15,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   207,     0,   208,   154,    51,
      52,    53,    54,    55,    56,    57,    58,     0,   131,     0,
     132,   133,   134,   135,     0,   136,   137,    87,     0,     0,
       0,     0,   138,     0,     0,     0,     0,   139,   140,     0,
       0,     0,     0,     0,     0,    51,    52,    53,    54,    55,
      56,    57,    58,     0,     0,     0,     0,     0,     0,   141,
      59,   104,   274,    12,    13,   143,    15,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,   153,   154,
      51,    52,    53,    54,    55,    56,    57,    58,     0,   131,
       0,   132,   133,   134,   135,     0,   136,   137,   124,     0,
       0,     0,     0,   138,     0,     0,     0,     0,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,   104,   289,     0,     0,   143,     0,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,   153,
     154,    51,    52,    53,    54,    55,    56,    57,    58,     0,
     131,     0,   132,   133,   134,   135,     0,   136,   137,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,   104,   291,     0,     0,   143,     0,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
     153,   154,    51,    52,    53,    54,    55,    56,    57,    58,
       0,   131,     0,   132,   133,   134,   135,     0,   136,   137,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,   104,   358,     0,     0,   143,     0,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,   153,   154,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,     0,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,     0,     0,   224,   225,     0,
       0,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,   136,   227,     0,
       0,     0,     0,   228,     0,     0,     0,     0,     0,   139,
     140,     0,   144,   145,   146,   147,   148,   149,   150,     7,
     152,     0,   153,    51,    52,    53,    54,    55,    56,    57,
      58,   141,     0,     0,     0,     0,     0,     0,     0,   136,
     144,   145,   146,   147,   148,   149,   150,     7,   152,     0,
     153,   139,   140,     0,     0,   131,     0,   132,   133,   134,
     135,     0,   136,   137,     0,     0,     0,     0,     0,   138,
       0,     0,     0,   141,   139,   140,     0,     0,     0,     0,
       0,     0,   144,   145,   146,   147,   148,   149,   150,     7,
     152,     0,   153,     0,     0,     0,   141,     0,   104,     0,
       0,     0,   143,     0,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   417,     0,   418,
     419,   134,   135,     0,   136,   137,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,     0,     0,     0,     0,   141,     0,
     104,   224,   225,     0,   143,   139,   140,   144,   145,   146,
     147,   148,   149,   150,   420,   152,   226,   153,   154,     0,
       0,     0,   227,     0,     0,     0,     0,   228,     0,   281,
     352,     0,     0,     0,   353,     0,   144,   145,   146,   147,
     148,   149,   150,     7,   152,   136,   153,     0,     0,     0,
       0,     0,     0,   224,   225,     0,     0,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,   227,     0,     0,     0,     0,   228,
       0,   281,   448,     0,     0,     0,     0,     0,   144,   145,
     146,   147,   148,   149,   150,     7,   152,   136,   153,     0,
       0,     0,     0,     0,     0,   224,   225,     0,     0,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,   228,     0,   281,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,   148,   149,   150,     7,   152,   136,
     153,     0,     0,     0,     0,     0,     0,   224,   225,     0,
       0,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,   227,     0,
       0,     0,     0,   228,     0,     0,     0,     0,   365,     0,
       0,     0,   144,   145,   146,   147,   148,   149,   150,     7,
     152,   136,   153,     0,     0,     0,     0,     0,     0,   224,
     225,     0,     0,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
     227,     0,   136,     0,     0,   228,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   145,   146,   147,   148,   149,
     150,     7,   152,     0,   153,   226,     0,     0,     0,     0,
       0,   227,     0,     0,     0,     0,   228,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,   146,   147,   148,
     149,   150,     7,   152,     0,   153
};

static const yytype_int16 yycheck[] =
{
       1,     2,   104,   216,   136,   216,    40,   281,   379,    20,
     173,   136,   139,   140,   287,   288,   104,   119,    54,    38,
     221,    57,   223,    44,   363,    44,    46,   261,   119,    49,
     113,   119,   359,   306,    21,    22,    23,    24,    39,    40,
      21,    22,    23,    24,    45,    55,    44,   210,    42,    68,
      69,   457,    78,    79,    48,    29,    30,    68,     3,     4,
       5,     6,     7,     8,     9,    10,    55,    77,   439,    88,
      91,   173,    91,   156,    69,    41,    42,    88,     6,   485,
     100,     0,    48,    55,    54,   173,    75,   106,    77,    76,
      60,    19,    79,    91,    74,    76,   228,   224,   225,   226,
     227,   104,   136,   228,    98,    77,    80,   209,   210,    69,
      47,   130,   313,   314,   216,    52,   119,    63,   209,    85,
     121,   209,   210,    38,    69,   359,   453,   290,   216,    44,
     364,    97,    98,   406,    69,   136,   475,   410,   139,   140,
     414,    21,    22,    23,    24,    80,   473,    54,    17,   476,
     361,    60,    59,    60,    69,    24,   483,   484,    69,   261,
     104,   127,   489,    32,   365,    74,   112,   113,    54,    59,
     173,    61,    69,   261,    60,   119,    91,     3,     4,     5,
       6,     7,     8,     9,    10,    53,    49,    69,   290,    57,
      53,   392,    69,    61,    57,   396,    76,   329,    61,    59,
     104,    53,   290,    49,   329,    57,   209,   210,   335,   336,
     337,    57,    54,   216,    53,   119,    69,    59,    60,   453,
     454,   455,    61,   224,   225,   226,   227,   228,    54,   173,
      33,    34,    35,    36,    59,    60,    51,    56,   451,   473,
     451,    60,   476,   477,    59,    55,   457,   374,    57,   483,
     484,    59,    61,    61,    55,   489,    55,   359,   261,   361,
     279,    53,   364,   304,    55,   209,   210,   308,    71,   173,
      60,   359,   216,   361,   485,    69,   364,    59,    60,     3,
       4,     5,     6,     7,     8,     9,    10,   290,   303,    43,
      44,    45,   307,    61,    18,   329,    59,    21,    22,   104,
      24,   325,   326,   327,   328,   209,   210,   330,   331,   332,
      53,   438,   216,    53,   119,    53,   317,   261,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,     3,     4,     5,
       6,     7,     8,     9,    10,    69,   290,    31,    32,   451,
      53,   453,   454,   455,    69,   457,   359,   261,   361,    31,
      32,   364,    51,   451,    61,   453,   454,   455,   173,   457,
      69,   473,    49,   374,   476,   477,    53,    57,   379,    61,
      57,   483,   484,   485,    61,   473,   290,   489,   476,   477,
      31,    32,    37,    38,    49,   483,   484,   485,    27,    28,
      49,   489,   323,   324,   209,   210,   333,   334,    59,   104,
      49,   216,    58,   453,    57,   359,    53,   361,   139,   140,
     364,    59,    46,    59,   119,     3,     4,     5,     6,     7,
       8,     9,    10,   473,    59,    40,   476,   438,   439,    41,
     441,    39,    54,   483,   484,    59,    69,    60,   451,   489,
     453,   454,   455,    69,   457,   359,   261,   361,    57,    54,
     364,    51,    54,    60,    55,    59,    54,    53,    13,    54,
     473,    60,    53,   476,   477,    58,    54,   104,   173,    58,
     483,   484,   485,    56,    54,   290,   489,    54,    57,    54,
      58,    54,   119,    54,    58,    51,    53,    59,    53,    53,
      51,    13,    54,   224,   225,   226,   227,   451,    54,   453,
     454,   455,    59,   457,   209,   210,    54,    54,    51,    59,
      54,   216,    54,    13,    54,    54,     5,   136,    59,   473,
      48,    45,   476,   477,   121,   199,   195,   130,   279,   483,
     484,   485,    69,    68,    49,   489,   173,   451,   114,   453,
     454,   455,    91,   457,   359,   308,   361,   441,   223,   364,
     137,   138,   317,   319,   141,   322,   261,   485,   320,   473,
     321,    -1,   476,   477,   431,   451,   135,   154,    -1,   483,
     484,   485,   209,   210,    -1,   489,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,    -1,   290,   317,    -1,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,    -1,   330,
     331,   332,   333,   334,   335,   336,   337,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   139,   140,     3,     4,     5,     6,
       7,     8,     9,    10,   261,    -1,    -1,    -1,   215,    -1,
     217,    18,    -1,    -1,    21,    22,   451,    24,   453,   454,
     455,   228,   457,   374,    -1,    -1,    -1,    -1,   379,    -1,
      -1,    -1,    -1,   290,   359,    -1,   361,    -1,   473,   364,
      -1,   476,   477,    -1,    -1,    -1,    -1,    -1,   483,   484,
     485,    -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,
     267,    -1,   269,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   281,    -1,    -1,    -1,    -1,   224,
     225,   226,   227,    -1,    -1,    -1,    -1,   438,   439,    -1,
     441,    -1,    -1,    -1,    -1,   302,    -1,    -1,    -1,    -1,
      -1,    -1,   359,    -1,   361,    -1,    -1,   364,    -1,    -1,
      -1,   318,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,   451,    -1,   453,   454,
     455,   338,   457,    18,    -1,    -1,    21,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   473,    -1,
      -1,   476,   477,   360,    -1,    -1,   363,    -1,   483,   484,
     485,    -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,
     377,    56,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,    69,   330,   331,   332,   333,   334,
     335,   336,   337,    -1,   451,    -1,   453,   454,   455,    -1,
     457,   408,    -1,    -1,    -1,    -1,    -1,   414,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   473,    -1,    -1,   476,
     477,    -1,    -1,    -1,    -1,    -1,   483,   484,   485,   374,
      -1,    -1,   489,    -1,   379,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   450,    -1,   452,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    -1,    14,    15,
      16,    17,    -1,    19,    20,    -1,    -1,   474,   475,    -1,
      26,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,   438,   439,    -1,   441,    53,    18,    55,
      56,    21,    22,    59,    24,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    -1,    14,
      15,    16,    17,    -1,    19,    20,    56,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,    69,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    53,    18,
      55,    56,    21,    22,    59,    24,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    -1,    72,    73,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    -1,
      14,    15,    16,    17,    -1,    19,    20,    56,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      18,    55,    56,    21,    22,    59,    24,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    72,    73,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      -1,    14,    15,    16,    17,    -1,    19,    20,    56,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    55,    56,    -1,    -1,    59,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    -1,    72,
      73,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    -1,    14,    15,    16,    17,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    56,    -1,    -1,    59,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    -1,
      72,    73,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    -1,    14,    15,    16,    17,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    19,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    72,     3,     4,     5,     6,     7,     8,     9,
      10,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    -1,
      72,    31,    32,    -1,    -1,    12,    -1,    14,    15,    16,
      17,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    53,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    72,    -1,    -1,    -1,    53,    -1,    55,    -1,
      -1,    -1,    59,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    -1,    72,    73,    12,    -1,    14,
      15,    16,    17,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    53,    -1,
      55,    27,    28,    -1,    59,    31,    32,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    42,    72,    73,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    53,    -1,    55,
      56,    -1,    -1,    -1,    60,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    19,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    53,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    19,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    19,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    19,    72,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    19,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    42,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    -1,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    78,    79,    83,    84,    87,    88,    69,   101,   101,
       0,    74,    21,    22,    23,    24,    76,    85,    86,    88,
     102,   103,   104,   130,    85,    59,    61,    59,    61,    69,
      69,    86,    85,    23,    76,   103,    69,    80,    55,    75,
      77,   105,   106,   108,    55,    77,   131,   132,    69,    69,
      59,     3,     4,     5,     6,     7,     8,     9,    10,    18,
      24,    56,    69,    90,    91,    92,    93,    94,   102,   109,
     110,   111,   112,   117,   118,   123,   124,   125,    96,    98,
     101,   107,    96,    97,   108,   105,   108,    56,   102,   112,
     118,   133,   134,   135,   136,   107,   132,   105,   106,   108,
     131,   132,    69,   119,    55,   174,    53,    69,   113,   114,
     115,   119,    18,    90,   125,    56,   110,   122,   174,    55,
     126,    60,   108,    59,    56,   134,   108,   105,   108,   132,
      53,    12,    14,    15,    16,    17,    19,    20,    26,    31,
      32,    53,    56,    59,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    72,    73,    89,    90,   101,   137,   138,
     139,   140,   141,   142,   145,   152,   153,   167,   168,   170,
     171,   172,   174,   175,   176,   177,   178,   179,   181,   182,
     183,   185,   186,   187,   188,   190,   191,   193,   195,   203,
     205,   206,   207,   208,    54,    90,   120,   121,    59,    60,
      49,    57,   119,   113,   119,   126,    56,    70,    72,   127,
     175,    98,   108,    54,   120,    53,    53,    53,    69,   209,
     209,    91,    92,    97,    27,    28,    42,    48,    53,   139,
     142,   149,   150,   151,   152,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   150,   101,   140,   141,   166,   166,
     150,    51,    61,   150,    69,   113,    53,    57,    61,    57,
      49,   154,    31,    32,    56,   176,    59,   115,    54,    60,
     114,    55,   116,   128,   150,    58,    59,    53,    53,    56,
     175,    56,    54,   150,   178,   186,   197,   198,   201,   150,
      59,    59,    57,   100,   147,   148,    53,   100,   147,   166,
     166,   166,   166,    91,   101,   150,    59,    47,    52,    46,
      40,    41,    39,    37,    38,    33,    34,    35,    36,    71,
      43,    44,    45,    27,    28,    29,    30,    80,    51,    59,
      54,   179,    69,    59,   143,   144,   150,   150,    69,   150,
     150,   121,    56,    60,   116,   129,   143,   143,    56,    54,
      51,    60,   202,    59,    54,    58,   150,   128,   100,   146,
     148,   143,   128,   146,    54,    57,   100,    57,   100,    54,
     157,   150,   158,   159,   160,   161,   162,   162,   163,   163,
     163,   163,    91,    95,    96,    99,   101,   164,   164,   164,
     165,   165,   166,   166,   166,   150,    53,    54,    60,    58,
      53,    58,    56,    56,    60,    54,    54,    12,    14,    15,
      69,   179,   180,   181,   184,   189,   192,   194,   196,   204,
     150,   186,   149,   179,   100,    58,    54,   166,    54,    54,
     169,    51,   100,   100,    59,   143,   150,   143,    56,   116,
      53,    53,    53,    51,    13,    54,   202,    59,   166,   169,
     155,    54,    54,   150,   178,   197,   150,   180,   179,   179,
     199,   200,   201,    54,    51,    59,    54,    54,   180,   150,
     149,   180,   179,    13,    54,    59,   180,   180,   199,    54,
     180
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    84,    85,    85,    86,    86,
      87,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    91,    91,    92,    92,    93,    93,    93,    93,
      93,    94,    94,    95,    95,    96,    97,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   106,   107,
     107,   108,   108,   109,   109,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   118,   118,   118,   118,   119,   119,   120,   120,   121,
     122,   123,   124,   124,   125,   125,   126,   126,   126,   126,
     127,   127,   128,   128,   128,   128,   129,   129,   130,   130,
     130,   130,   131,   132,   132,   133,   133,   134,   134,   135,
     136,   137,   137,   138,   138,   138,   138,   138,   138,   138,
     139,   140,   140,   141,   141,   142,   142,   142,   143,   143,
     144,   144,   145,   145,   145,   145,   146,   146,   147,   147,
     148,   149,   149,   150,   151,   151,   152,   153,   153,   153,
     154,   155,   155,   156,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   161,   162,   162,   162,   162,
     162,   162,   163,   163,   163,   163,   164,   164,   164,   165,
     165,   165,   165,   166,   166,   166,   166,   166,   167,   168,
     169,   169,   169,   169,   170,   170,   170,   170,   171,   172,
     173,   173,   173,   173,   174,   174,   175,   175,   176,   176,
     177,   178,   179,   179,   179,   179,   179,   179,   180,   180,
     180,   180,   180,   181,   181,   181,   181,   181,   181,   181,
     181,   182,   183,   184,   185,   186,   186,   186,   186,   186,
     186,   186,   187,   188,   189,   190,   190,   191,   192,   193,
     193,   194,   194,   195,   196,   197,   197,   198,   198,   199,
     199,   200,   201,   201,   202,   202,   203,   204,   205,   206,
     207,   208,   209,   209
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     1,     2,     1,     1,
       3,     3,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     2,     1,     3,     1,     2,     1,     1,     1,     4,
       3,     5,     4,     5,     4,     6,     5,     2,     2,     1,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     1,     3,     1,     3,     1,     1,     1,
       2,     3,     2,     3,     2,     3,     4,     3,     1,     2,
       1,     2,     3,     2,     4,     3,     3,     4,     3,     2,
       4,     4,     3,     2,     4,     3,     3,     1,     5,     4,
       3,     4,     2,     3,     2,     1,     2,     1,     1,     1,
       2,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       5,     3,     3,     4,     4,     4,     6,     6,     0,     1,
       1,     3,     4,     4,     4,     4,     0,     1,     1,     2,
       3,     1,     0,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     2,     2,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     2,     2,
       4,     5,     4,     5,     2,     3,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     5,     7,     7,     3,     5,     5,     5,     1,
       1,     1,     1,     9,     9,     1,     0,     1,     1,     1,
       0,     1,     1,     2,     3,     2,     7,     7,     3,     3,
       3,     3,     1,     0
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
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

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
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
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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

#line 2259 "parse.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 795 "parse.y"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "format: ./build/run <file name>" << endl;
        exit (1);
    }
    yyin = fopen(argv[1], "r");

    yydebug = 1;

    do {
        yyparse();
    } while(!feof(yyin));

    /* Print Stats*/
    /* print_stats(); */

    return 0;
}

int yyerror(const char *s) {
    printf("syntax error: line %d: %s\n", yylineno, s);
    exit(1);
}
