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
#line 1 "parser/lalr1_fast.y"

    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include <iomanip>
    #include <vector>
    #include <fstream>
    #include <sstream>
    // #include <argparse/argparse.hpp>
    #ifndef SYMBOL_TABLE_FAST_H
        #include "symbol_table_fast.hpp"
    #endif

    #ifndef ACTIONS_FAST_H
        #include "actions_fast.hpp"
    #endif

    #define YYDEBUG 1
    using namespace std;

    extern "C" int yylex();
    extern "C" int yywrap();
    extern "C" FILE *yyin;
    extern "C" int yylineno;
    extern void yyrestart ( FILE *input_file  );
    extern int yylex_destroy ( void );

    extern ClassDefinition *current_class;
    extern LocalSymbolTable *current_table;
    extern GlobalSymbolTable *global_table;

    extern scope current_scope;

    extern unordered_map<string, Type *> defined_types;

    int offset;

    int8_t global_modifier;
    string global_type;
    int pass_no = 1;
    stringstream text;

    static int node_num=-1;

    ofstream dotfile;

    int yyerror(const char *);
    


#line 124 "lalr1_fast.tab.c"

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

#include "lalr1_fast.tab.h"
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
  YYSYMBOL_CATCH = 26,                     /* CATCH  */
  YYSYMBOL_FINALLY = 27,                   /* FINALLY  */
  YYSYMBOL_SYNCHRONIZED = 28,              /* SYNCHRONIZED  */
  YYSYMBOL_ASSERT = 29,                    /* ASSERT  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MINUS = 31,                     /* MINUS  */
  YYSYMBOL_DIV = 32,                       /* DIV  */
  YYSYMBOL_MODULO = 33,                    /* MODULO  */
  YYSYMBOL_INCREMENT = 34,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 35,                 /* DECREMENT  */
  YYSYMBOL_GEQ = 36,                       /* GEQ  */
  YYSYMBOL_LEQ = 37,                       /* LEQ  */
  YYSYMBOL_GT = 38,                        /* GT  */
  YYSYMBOL_LT = 39,                        /* LT  */
  YYSYMBOL_NEQ = 40,                       /* NEQ  */
  YYSYMBOL_DEQ = 41,                       /* DEQ  */
  YYSYMBOL_BITWISE_AND = 42,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 43,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 44,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_COMPLEMENT = 45,        /* BITWISE_COMPLEMENT  */
  YYSYMBOL_LEFT_SHIFT = 46,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 47,               /* RIGHT_SHIFT  */
  YYSYMBOL_UNSIGNED_RIGHT_SHIFT = 48,      /* UNSIGNED_RIGHT_SHIFT  */
  YYSYMBOL_AND = 49,                       /* AND  */
  YYSYMBOL_OR = 50,                        /* OR  */
  YYSYMBOL_NOT = 51,                       /* NOT  */
  YYSYMBOL_ASSIGNMENT = 52,                /* ASSIGNMENT  */
  YYSYMBOL_COLON = 53,                     /* COLON  */
  YYSYMBOL_QM = 54,                        /* QM  */
  YYSYMBOL_LPAREN = 55,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 56,                    /* RPAREN  */
  YYSYMBOL_LCURLY = 57,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 58,                    /* RCURLY  */
  YYSYMBOL_LSQUARE = 59,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 60,                   /* RSQUARE  */
  YYSYMBOL_SEMICOLON = 61,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 62,                     /* COMMA  */
  YYSYMBOL_DOT = 63,                       /* DOT  */
  YYSYMBOL_CHAR_LITERAL = 64,              /* CHAR_LITERAL  */
  YYSYMBOL_BOOLEAN_LITERAL = 65,           /* BOOLEAN_LITERAL  */
  YYSYMBOL_NULL_LITERAL = 66,              /* NULL_LITERAL  */
  YYSYMBOL_INTEGER_LITERAL = 67,           /* INTEGER_LITERAL  */
  YYSYMBOL_FP_LITERAL = 68,                /* FP_LITERAL  */
  YYSYMBOL_STRING = 69,                    /* STRING  */
  YYSYMBOL_TEXT_BLOCK = 70,                /* TEXT_BLOCK  */
  YYSYMBOL_IDENTIFIER = 71,                /* IDENTIFIER  */
  YYSYMBOL_THIS = 72,                      /* THIS  */
  YYSYMBOL_INSTANCEOF = 73,                /* INSTANCEOF  */
  YYSYMBOL_SUPER = 74,                     /* SUPER  */
  YYSYMBOL_THROW = 75,                     /* THROW  */
  YYSYMBOL_THROWS = 76,                    /* THROWS  */
  YYSYMBOL_EOF_ = 77,                      /* EOF_  */
  YYSYMBOL_PACKAGE = 78,                   /* PACKAGE  */
  YYSYMBOL_IMPORT = 79,                    /* IMPORT  */
  YYSYMBOL_ASTERIK = 80,                   /* ASTERIK  */
  YYSYMBOL_DO = 81,                        /* DO  */
  YYSYMBOL_TRY = 82,                       /* TRY  */
  YYSYMBOL_ASSIGN = 83,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_Program = 85,                   /* Program  */
  YYSYMBOL_CompilationUnit = 86,           /* CompilationUnit  */
  YYSYMBOL_ClassOrInterfaceDeclarations = 87, /* ClassOrInterfaceDeclarations  */
  YYSYMBOL_ClassOrInterfaceDeclaration = 88, /* ClassOrInterfaceDeclaration  */
  YYSYMBOL_PackageDeclaration = 89,        /* PackageDeclaration  */
  YYSYMBOL_ImportDeclarations = 90,        /* ImportDeclarations  */
  YYSYMBOL_ImportDeclaration = 91,         /* ImportDeclaration  */
  YYSYMBOL_ScopeIncrement = 92,            /* ScopeIncrement  */
  YYSYMBOL_Literal = 93,                   /* Literal  */
  YYSYMBOL_UnannTypeSubRoutine = 94,       /* UnannTypeSubRoutine  */
  YYSYMBOL_UnannType = 95,                 /* UnannType  */
  YYSYMBOL_PrimitiveType = 96,             /* PrimitiveType  */
  YYSYMBOL_NumericType = 97,               /* NumericType  */
  YYSYMBOL_IntegralType = 98,              /* IntegralType  */
  YYSYMBOL_FloatingPointType = 99,         /* FloatingPointType  */
  YYSYMBOL_ReferenceType = 100,            /* ReferenceType  */
  YYSYMBOL_ClassOrInterfaceType = 101,     /* ClassOrInterfaceType  */
  YYSYMBOL_ArrayType = 102,                /* ArrayType  */
  YYSYMBOL_Dims = 103,                     /* Dims  */
  YYSYMBOL_TypeName = 104,                 /* TypeName  */
  YYSYMBOL_ModifiersUnannTypeSubRoutine = 105, /* ModifiersUnannTypeSubRoutine  */
  YYSYMBOL_Modifiers = 106,                /* Modifiers  */
  YYSYMBOL_Modifier = 107,                 /* Modifier  */
  YYSYMBOL_ClassDeclaration = 108,         /* ClassDeclaration  */
  YYSYMBOL_109_1 = 109,                    /* $@1  */
  YYSYMBOL_110_2 = 110,                    /* $@2  */
  YYSYMBOL_ClassBody = 111,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 112,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 113,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 114,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 115,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclaratorList = 116,   /* VariableDeclaratorList  */
  YYSYMBOL_VariableDeclarator = 117,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 118,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 119,      /* VariableInitializer  */
  YYSYMBOL_MethodDeclaration = 120,        /* MethodDeclaration  */
  YYSYMBOL_121_3 = 121,                    /* $@3  */
  YYSYMBOL_MethodHeader = 122,             /* MethodHeader  */
  YYSYMBOL_Throws = 123,                   /* Throws  */
  YYSYMBOL_ExceptionTypeList = 124,        /* ExceptionTypeList  */
  YYSYMBOL_CommaExceptionTypes = 125,      /* CommaExceptionTypes  */
  YYSYMBOL_ExceptionType = 126,            /* ExceptionType  */
  YYSYMBOL_Declarator = 127,               /* Declarator  */
  YYSYMBOL_FormalParameterList = 128,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 129,          /* FormalParameter  */
  YYSYMBOL_MethodBody = 130,               /* MethodBody  */
  YYSYMBOL_StaticInitializer = 131,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 132,   /* ConstructorDeclaration  */
  YYSYMBOL_133_4 = 133,                    /* $@4  */
  YYSYMBOL_134_5 = 134,                    /* $@5  */
  YYSYMBOL_ConstructorBody = 135,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation = 136, /* ExplicitConstructorInvocation  */
  YYSYMBOL_ArrayInitializer = 137,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializerList = 138,  /* VariableInitializerList  */
  YYSYMBOL_Primary = 139,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 140,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassInstanceCreationExpression = 141, /* ClassInstanceCreationExpression  */
  YYSYMBOL_FieldAccess = 142,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 143,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 144,         /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 145,             /* ArgumentList  */
  YYSYMBOL_ArrayCreationExpression = 146,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 147,                 /* DimExprs  */
  YYSYMBOL_DimExpr = 148,                  /* DimExpr  */
  YYSYMBOL_Expression = 149,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 150,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 151,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 152,             /* LeftHandSide  */
  YYSYMBOL_ConditionalExpression = 153,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 154,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 155, /* ConditionalAndExpression  */
  YYSYMBOL_InclusiveOrExpression = 156,    /* InclusiveOrExpression  */
  YYSYMBOL_ExclusiveOrExpression = 157,    /* ExclusiveOrExpression  */
  YYSYMBOL_AndExpression = 158,            /* AndExpression  */
  YYSYMBOL_EqualityExpression = 159,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 160,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 161,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 162,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 163, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 164,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 165,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 166,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 167, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_PostfixExpression = 168,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 169,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 170,  /* PostDecrementExpression  */
  YYSYMBOL_CastExpression = 171,           /* CastExpression  */
  YYSYMBOL_Block = 172,                    /* Block  */
  YYSYMBOL_BlockStatements = 173,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 174,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclarationStatement = 175, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 176, /* LocalVariableDeclaration  */
  YYSYMBOL_177_6 = 177,                    /* $@6  */
  YYSYMBOL_178_7 = 178,                    /* $@7  */
  YYSYMBOL_179_8 = 179,                    /* $@8  */
  YYSYMBOL_180_9 = 180,                    /* $@9  */
  YYSYMBOL_Statement = 181,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 182,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 183, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_SynchronizedStatement = 184,    /* SynchronizedStatement  */
  YYSYMBOL_EmptyStatement = 185,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 186,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 187, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 188,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 189,      /* StatementExpression  */
  YYSYMBOL_IfThenStatementSubRoutine = 190, /* IfThenStatementSubRoutine  */
  YYSYMBOL_IfThenStatement = 191,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 192,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 193, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_AssertStatement = 194,          /* AssertStatement  */
  YYSYMBOL_WhileStatementSubRoutine = 195, /* WhileStatementSubRoutine  */
  YYSYMBOL_WhileStatement = 196,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 197,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DoStatement = 198,              /* DoStatement  */
  YYSYMBOL_199_10 = 199,                   /* $@10  */
  YYSYMBOL_ForStatement = 200,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 201,    /* ForStatementNoShortIf  */
  YYSYMBOL_For1SubRoutine = 202,           /* For1SubRoutine  */
  YYSYMBOL_For2SubRoutine = 203,           /* For2SubRoutine  */
  YYSYMBOL_BasicForStatement = 204,        /* BasicForStatement  */
  YYSYMBOL_BasicForStatementNoShortIf = 205, /* BasicForStatementNoShortIf  */
  YYSYMBOL_ForInit = 206,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 207,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 208,  /* StatementExpressionList  */
  YYSYMBOL_CommaStatementExpressions = 209, /* CommaStatementExpressions  */
  YYSYMBOL_EnhancedForStatementSubRoutine = 210, /* EnhancedForStatementSubRoutine  */
  YYSYMBOL_EnhancedForStatement = 211,     /* EnhancedForStatement  */
  YYSYMBOL_EnhancedForStatementNoShortIf = 212, /* EnhancedForStatementNoShortIf  */
  YYSYMBOL_BreakStatement = 213,           /* BreakStatement  */
  YYSYMBOL_ContinueStatement = 214,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 215,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 216,           /* ThrowStatement  */
  YYSYMBOL_TryStatement = 217,             /* TryStatement  */
  YYSYMBOL_Catches = 218,                  /* Catches  */
  YYSYMBOL_CatchClause = 219,              /* CatchClause  */
  YYSYMBOL_CatchFormalParameter = 220,     /* CatchFormalParameter  */
  YYSYMBOL_CatchType = 221,                /* CatchType  */
  YYSYMBOL_Finally = 222,                  /* Finally  */
  YYSYMBOL_Int = 223,                      /* Int  */
  YYSYMBOL_Long = 224,                     /* Long  */
  YYSYMBOL_Byte = 225,                     /* Byte  */
  YYSYMBOL_Short = 226,                    /* Short  */
  YYSYMBOL_Char = 227,                     /* Char  */
  YYSYMBOL_Float = 228,                    /* Float  */
  YYSYMBOL_Double = 229,                   /* Double  */
  YYSYMBOL_Boolean = 230,                  /* Boolean  */
  YYSYMBOL_Var = 231,                      /* Var  */
  YYSYMBOL_If = 232,                       /* If  */
  YYSYMBOL_Else = 233,                     /* Else  */
  YYSYMBOL_While = 234,                    /* While  */
  YYSYMBOL_For = 235,                      /* For  */
  YYSYMBOL_Break = 236,                    /* Break  */
  YYSYMBOL_Continue = 237,                 /* Continue  */
  YYSYMBOL_Void = 238,                     /* Void  */
  YYSYMBOL_New = 239,                      /* New  */
  YYSYMBOL_Return = 240,                   /* Return  */
  YYSYMBOL_Public = 241,                   /* Public  */
  YYSYMBOL_Private = 242,                  /* Private  */
  YYSYMBOL_Class = 243,                    /* Class  */
  YYSYMBOL_Static = 244,                   /* Static  */
  YYSYMBOL_Final = 245,                    /* Final  */
  YYSYMBOL_Assert = 246,                   /* Assert  */
  YYSYMBOL_This = 247,                     /* This  */
  YYSYMBOL_Instanceof = 248,               /* Instanceof  */
  YYSYMBOL_super_ = 249,                   /* super_  */
  YYSYMBOL_Throw = 250,                    /* Throw  */
  YYSYMBOL_Package = 251,                  /* Package  */
  YYSYMBOL_Import = 252,                   /* Import  */
  YYSYMBOL_do_ = 253,                      /* do_  */
  YYSYMBOL_try_ = 254,                     /* try_  */
  YYSYMBOL_throws_ = 255,                  /* throws_  */
  YYSYMBOL_catch_ = 256,                   /* catch_  */
  YYSYMBOL_finally_ = 257,                 /* finally_  */
  YYSYMBOL_synchronized_ = 258,            /* synchronized_  */
  YYSYMBOL_Plus = 259,                     /* Plus  */
  YYSYMBOL_Minus = 260,                    /* Minus  */
  YYSYMBOL_Div = 261,                      /* Div  */
  YYSYMBOL_Asterik = 262,                  /* Asterik  */
  YYSYMBOL_Modulo = 263,                   /* Modulo  */
  YYSYMBOL_Increment = 264,                /* Increment  */
  YYSYMBOL_Decrement = 265,                /* Decrement  */
  YYSYMBOL_Geq = 266,                      /* Geq  */
  YYSYMBOL_Leq = 267,                      /* Leq  */
  YYSYMBOL_Gt = 268,                       /* Gt  */
  YYSYMBOL_Lt = 269,                       /* Lt  */
  YYSYMBOL_Neq = 270,                      /* Neq  */
  YYSYMBOL_Deq = 271,                      /* Deq  */
  YYSYMBOL_Bitwise_and = 272,              /* Bitwise_and  */
  YYSYMBOL_Bitwise_or = 273,               /* Bitwise_or  */
  YYSYMBOL_Bitwise_xor = 274,              /* Bitwise_xor  */
  YYSYMBOL_Bitwise_complement = 275,       /* Bitwise_complement  */
  YYSYMBOL_Left_shift = 276,               /* Left_shift  */
  YYSYMBOL_Right_shift = 277,              /* Right_shift  */
  YYSYMBOL_Unsigned_right_shift = 278,     /* Unsigned_right_shift  */
  YYSYMBOL_And = 279,                      /* And  */
  YYSYMBOL_Or = 280,                       /* Or  */
  YYSYMBOL_Not = 281,                      /* Not  */
  YYSYMBOL_AssignmentOperator = 282,       /* AssignmentOperator  */
  YYSYMBOL_Assign = 283,                   /* Assign  */
  YYSYMBOL_Colon = 284,                    /* Colon  */
  YYSYMBOL_Qm = 285,                       /* Qm  */
  YYSYMBOL_Lparen = 286,                   /* Lparen  */
  YYSYMBOL_Rparen = 287,                   /* Rparen  */
  YYSYMBOL_Lcurly = 288,                   /* Lcurly  */
  YYSYMBOL_Rcurly = 289,                   /* Rcurly  */
  YYSYMBOL_Lsquare = 290,                  /* Lsquare  */
  YYSYMBOL_Rsquare = 291,                  /* Rsquare  */
  YYSYMBOL_Semicolon = 292,                /* Semicolon  */
  YYSYMBOL_Comma = 293,                    /* Comma  */
  YYSYMBOL_Dot = 294,                      /* Dot  */
  YYSYMBOL_Char_literal = 295,             /* Char_literal  */
  YYSYMBOL_Boolean_literal = 296,          /* Boolean_literal  */
  YYSYMBOL_Null_literal = 297,             /* Null_literal  */
  YYSYMBOL_Integer_literal = 298,          /* Integer_literal  */
  YYSYMBOL_Fp_literal = 299,               /* Fp_literal  */
  YYSYMBOL_String = 300,                   /* String  */
  YYSYMBOL_Text_block = 301,               /* Text_block  */
  YYSYMBOL_Identifier = 302,               /* Identifier  */
  YYSYMBOL_endoffile = 303                 /* endoffile  */
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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2987

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  220
/* YYNRULES -- Number of rules.  */
#define YYNRULES  402
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  647

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   354,   354,   358,   359,   360,   361,   365,   366,   370,
     376,   379,   380,   384,   385,   389,   403,   404,   405,   406,
     407,   408,   409,   419,   422,   423,   427,   428,   432,   433,
     436,   437,   438,   439,   440,   443,   444,   452,   453,   457,
     464,   467,   476,   477,   494,   498,   508,   512,   515,   522,
     525,   528,   531,   543,   543,   544,   544,   561,   562,   566,
     567,   571,   572,   573,   574,   579,   580,   581,   586,   587,
     591,   592,   597,   600,   606,   611,   620,   621,   628,   628,
     634,   641,   647,   653,   658,   666,   673,   680,   689,   692,
     693,   696,   697,   700,   707,   708,   712,   717,   721,   730,
     734,   738,   738,   739,   739,   753,   754,   755,   756,   760,
     763,   772,   773,   778,   788,   794,   805,   814,   823,   862,
     863,   867,   868,   869,   870,   871,   872,   873,   877,   886,
     898,   908,   927,   949,   960,   971,   972,   973,   974,   981,
     988,   998,   999,  1000,  1001,  1002,  1003,  1009,  1010,  1014,
    1034,  1037,  1038,  1042,  1052,  1065,  1073,  1074,  1077,  1078,
    1100,  1101,  1108,  1109,  1116,  1117,  1124,  1125,  1132,  1133,
    1140,  1141,  1146,  1153,  1154,  1159,  1164,  1169,  1174,  1177,
    1178,  1183,  1188,  1195,  1196,  1201,  1208,  1209,  1214,  1219,
    1226,  1227,  1228,  1234,  1240,  1243,  1249,  1257,  1263,  1271,
    1272,  1278,  1284,  1287,  1288,  1289,  1290,  1293,  1302,  1313,
    1323,  1334,  1340,  1349,  1350,  1353,  1354,  1358,  1359,  1360,
    1363,  1366,  1367,  1367,  1368,  1368,  1369,  1369,  1369,  1373,
    1374,  1375,  1376,  1377,  1378,  1381,  1382,  1383,  1384,  1385,
    1388,  1389,  1390,  1391,  1392,  1393,  1394,  1395,  1397,  1398,
    1400,  1404,  1407,  1410,  1413,  1416,  1419,  1420,  1421,  1422,
    1423,  1424,  1425,  1429,  1432,  1435,  1438,  1441,  1442,  1504,
    1507,  1510,  1514,  1514,  1519,  1520,  1523,  1524,  1528,  1532,
    1535,  1536,  1537,  1538,  1539,  1540,  1541,  1542,  1545,  1546,
    1547,  1548,  1549,  1550,  1551,  1552,  1555,  1556,  1559,  1562,
    1563,  1566,  1567,  1571,  1574,  1577,  1580,  1588,  1593,  1594,
    1597,  1601,  1602,  1603,  1607,  1608,  1612,  1615,  1616,  1619,
    1620,  1624,  1629,  1632,  1635,  1638,  1641,  1644,  1647,  1650,
    1653,  1656,  1659,  1662,  1665,  1668,  1671,  1674,  1677,  1680,
    1683,  1686,  1689,  1692,  1695,  1698,  1701,  1704,  1707,  1710,
    1722,  1725,  1728,  1734,  1736,  1738,  1740,  1742,  1748,  1751,
    1754,  1757,  1760,  1763,  1766,  1769,  1772,  1775,  1778,  1781,
    1784,  1787,  1790,  1793,  1796,  1799,  1802,  1805,  1808,  1811,
    1814,  1817,  1820,  1822,  1825,  1828,  1831,  1834,  1837,  1840,
    1843,  1846,  1849,  1852,  1857,  1860,  1863,  1866,  1869,  1872,
    1875,  1878,  1881
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
  "PRIVATE", "CLASS", "STATIC", "FINAL", "CATCH", "FINALLY",
  "SYNCHRONIZED", "ASSERT", "PLUS", "MINUS", "DIV", "MODULO", "INCREMENT",
  "DECREMENT", "GEQ", "LEQ", "GT", "LT", "NEQ", "DEQ", "BITWISE_AND",
  "BITWISE_OR", "BITWISE_XOR", "BITWISE_COMPLEMENT", "LEFT_SHIFT",
  "RIGHT_SHIFT", "UNSIGNED_RIGHT_SHIFT", "AND", "OR", "NOT", "ASSIGNMENT",
  "COLON", "QM", "LPAREN", "RPAREN", "LCURLY", "RCURLY", "LSQUARE",
  "RSQUARE", "SEMICOLON", "COMMA", "DOT", "CHAR_LITERAL",
  "BOOLEAN_LITERAL", "NULL_LITERAL", "INTEGER_LITERAL", "FP_LITERAL",
  "STRING", "TEXT_BLOCK", "IDENTIFIER", "THIS", "INSTANCEOF", "SUPER",
  "THROW", "THROWS", "EOF_", "PACKAGE", "IMPORT", "ASTERIK", "DO", "TRY",
  "ASSIGN", "$accept", "Program", "CompilationUnit",
  "ClassOrInterfaceDeclarations", "ClassOrInterfaceDeclaration",
  "PackageDeclaration", "ImportDeclarations", "ImportDeclaration",
  "ScopeIncrement", "Literal", "UnannTypeSubRoutine", "UnannType",
  "PrimitiveType", "NumericType", "IntegralType", "FloatingPointType",
  "ReferenceType", "ClassOrInterfaceType", "ArrayType", "Dims", "TypeName",
  "ModifiersUnannTypeSubRoutine", "Modifiers", "Modifier",
  "ClassDeclaration", "$@1", "$@2", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "VariableDeclaratorList", "VariableDeclarator", "VariableDeclaratorId",
  "VariableInitializer", "MethodDeclaration", "$@3", "MethodHeader",
  "Throws", "ExceptionTypeList", "CommaExceptionTypes", "ExceptionType",
  "Declarator", "FormalParameterList", "FormalParameter", "MethodBody",
  "StaticInitializer", "ConstructorDeclaration", "$@4", "$@5",
  "ConstructorBody", "ExplicitConstructorInvocation", "ArrayInitializer",
  "VariableInitializerList", "Primary", "PrimaryNoNewArray",
  "ClassInstanceCreationExpression", "FieldAccess", "ArrayAccess",
  "MethodInvocation", "ArgumentList", "ArrayCreationExpression",
  "DimExprs", "DimExpr", "Expression", "AssignmentExpression",
  "Assignment", "LeftHandSide", "ConditionalExpression",
  "ConditionalOrExpression", "ConditionalAndExpression",
  "InclusiveOrExpression", "ExclusiveOrExpression", "AndExpression",
  "EqualityExpression", "RelationalExpression", "ShiftExpression",
  "AdditiveExpression", "MultiplicativeExpression", "UnaryExpression",
  "PreIncrementExpression", "PreDecrementExpression",
  "UnaryExpressionNotPlusMinus", "PostfixExpression",
  "PostIncrementExpression", "PostDecrementExpression", "CastExpression",
  "Block", "BlockStatements", "BlockStatement",
  "LocalVariableDeclarationStatement", "LocalVariableDeclaration", "$@6",
  "$@7", "$@8", "$@9", "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "SynchronizedStatement",
  "EmptyStatement", "LabeledStatement", "LabeledStatementNoShortIf",
  "ExpressionStatement", "StatementExpression",
  "IfThenStatementSubRoutine", "IfThenStatement", "IfThenElseStatement",
  "IfThenElseStatementNoShortIf", "AssertStatement",
  "WhileStatementSubRoutine", "WhileStatement", "WhileStatementNoShortIf",
  "DoStatement", "$@10", "ForStatement", "ForStatementNoShortIf",
  "For1SubRoutine", "For2SubRoutine", "BasicForStatement",
  "BasicForStatementNoShortIf", "ForInit", "ForUpdate",
  "StatementExpressionList", "CommaStatementExpressions",
  "EnhancedForStatementSubRoutine", "EnhancedForStatement",
  "EnhancedForStatementNoShortIf", "BreakStatement", "ContinueStatement",
  "ReturnStatement", "ThrowStatement", "TryStatement", "Catches",
  "CatchClause", "CatchFormalParameter", "CatchType", "Finally", "Int",
  "Long", "Byte", "Short", "Char", "Float", "Double", "Boolean", "Var",
  "If", "Else", "While", "For", "Break", "Continue", "Void", "New",
  "Return", "Public", "Private", "Class", "Static", "Final", "Assert",
  "This", "Instanceof", "super_", "Throw", "Package", "Import", "do_",
  "try_", "throws_", "catch_", "finally_", "synchronized_", "Plus",
  "Minus", "Div", "Asterik", "Modulo", "Increment", "Decrement", "Geq",
  "Leq", "Gt", "Lt", "Neq", "Deq", "Bitwise_and", "Bitwise_or",
  "Bitwise_xor", "Bitwise_complement", "Left_shift", "Right_shift",
  "Unsigned_right_shift", "And", "Or", "Not", "AssignmentOperator",
  "Assign", "Colon", "Qm", "Lparen", "Rparen", "Lcurly", "Rcurly",
  "Lsquare", "Rsquare", "Semicolon", "Comma", "Dot", "Char_literal",
  "Boolean_literal", "Null_literal", "Integer_literal", "Fp_literal",
  "String", "Text_block", "Identifier", "endoffile", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-446)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-263)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      52,  -446,  -446,  -446,  -446,  -446,  -446,  -446,    27,    31,
     316,  -446,   111,   111,  -446,   316,  -446,  -446,  -446,  -446,
      57,  -446,  -446,    57,    57,  -446,  -446,  -446,  -446,   316,
     111,   316,  -446,  -446,    57,  -446,  -446,   195,  -446,   195,
     316,  -446,   115,  -446,  -446,  -446,    57,  -446,   -12,   115,
    -446,  -446,  1471,  -446,  -446,   171,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,    57,  -446,   208,
    -446,  -446,  -446,  -446,  -446,  -446,     8,    57,  1631,  -446,
    1471,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,    57,   115,
    -446,  -446,   196,  -446,   126,  -446,    62,   194,   196,  -446,
    -446,   222,  -446,   126,   194,  -446,  -446,    57,  -446,  -446,
     115,   115,   194,   196,  -446,  2777,  -446,   480,  -446,  -446,
      57,  -446,  1540,   222,  -446,  -446,    57,  -446,   208,  -446,
    -446,   115,   194,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,    57,   140,   105,   208,   144,    10,
      30,   148,  -446,  -446,    36,  -446,  -446,  -446,  -446,  -446,
    2777,  -446,  -446,   171,  -446,  -446,  -446,  -446,  -446,  -446,
     171,   239,  -446,  -446,  -446,   239,  -446,  -446,  -446,   171,
     171,  -446,   239,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
     196,   196,   196,   171,   171,   152,  1865,   504,  2913,  -446,
     235,  2913,  2068,   115,   196,   730,   730,  2913,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,   248,  -446,    57,
      56,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,   332,
    -446,  -446,   105,  -446,  -446,  -446,  -446,  -446,  -446,    96,
     257,   265,   271,   275,   202,   224,   240,   234,     7,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  2913,  2913,  2913,
    2913,  2234,  1377,  -446,  -446,   235,  -446,   259,  -446,  -446,
    -446,  2777,   259,  -446,  -446,  2831,  2885,  -446,  -446,    57,
    2913,  -446,  2913,  2913,  -446,  -446,  -446,  -446,  -446,  2068,
    1743,  1743,  2068,    57,  2913,  2913,  2426,  -446,  -446,   208,
      -7,   171,  -446,   152,   308,   118,    57,   171,   292,   313,
     250,  2913,   186,   235,  -446,  -446,   186,   235,   239,  -446,
    2068,   208,  -446,   152,  2913,  -446,  -446,  2913,  2913,  -446,
    2913,  -446,  2913,  -446,  2913,  -446,  2913,  -446,  -446,  2913,
    2913,  -446,  -446,  -446,  -446,  -446,   152,  2913,  2913,  2913,
    2913,  -446,  -446,  -446,  2913,  2913,  2913,  2913,  2913,  -446,
    -446,  2913,  2913,  2913,   292,  -446,  -446,  -446,  -446,   110,
     239,   394,  -446,   192,  -446,   273,   259,    57,  2777,  2777,
     196,   131,  -446,    56,  -446,  -446,   222,   196,   222,  -446,
    -446,  2068,  -446,   259,   239,  -446,  2068,   239,  2068,  -446,
     259,  -446,  -446,   248,   171,  -446,   312,  1865,   115,   208,
    -446,  2885,   115,   208,  2831,  -446,    57,  -446,  2913,  -446,
     196,  -446,   196,  -446,  -446,   250,  -446,  -446,   196,   115,
     239,  -446,  -446,  -446,   257,   248,   265,   271,   275,   202,
     224,   224,   208,  -446,   240,   240,   240,   240,   234,   234,
     234,     7,     7,  -446,  -446,  -446,  2913,   586,  -446,  1702,
    -446,    57,  -446,  2777,  -446,  -446,  2831,  2831,  -446,  2913,
    -446,  2831,  -446,  -446,   319,   321,  -446,   239,  -446,   239,
    -446,  -446,   171,   171,  -446,   239,  -446,   196,   248,  -446,
    1906,  2068,  -446,  2068,  -446,  2913,  1865,  -446,  1743,  -446,
    -446,  -446,   222,  -446,  -446,    56,  -446,   259,    57,   171,
    2831,  2913,  -446,  -446,    25,  -446,   115,  2913,  -446,  -446,
    -446,  -446,  -446,  -446,    56,  -446,    56,  -446,  -446,    56,
    -446,  -446,  2068,  -446,  2068,  1743,  1743,  2068,  2426,  2068,
     259,  -446,  -446,  -446,  -446,  1743,   239,  2068,  -446,  -446,
     259,  -446,    56,  -446,  -446,   265,   239,    57,    57,  -446,
    -446,  -446,  -446,  -446,  -446,  2068,  -446,   239,  2068,   239,
    2068,  -446,   171,  1865,  -446,  -446,   239,  2068,  2068,  -446,
    -446,   239,    57,   115,   208,    57,   319,  2068,  -446,  2068,
    -446,  1865,  1743,  2068,  -446,  -446,   171,  -446,  -446,   208,
    2068,  -446,  -446,  1743,   239,  2068,  -446,  -446,  -446,   239,
    2068,  2068,  -446,  2068,  -446,  -446,  -446
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   340,   341,   342,   343,   344,   350,   351,     0,     0,
       6,     7,     0,     0,    12,     0,    47,     9,    49,    50,
       0,    51,    52,     0,     0,     1,   402,     2,     8,     5,
       0,     4,    11,    48,     0,   401,    55,     0,    44,     0,
       3,    53,     0,   391,   393,    10,     0,    13,     0,     0,
     387,    56,     0,    45,   361,     0,    54,   322,   323,   324,
     326,   325,   327,   328,   329,   337,   388,     0,    23,    24,
      26,    28,    29,    25,    37,    38,    39,     0,     0,    67,
       0,    60,    61,    65,    66,    78,   103,    63,    62,    64,
      32,    33,    30,    31,    34,    35,    36,    27,     0,    51,
      15,    58,    44,    14,     0,    71,    73,    81,    75,   389,
      40,     0,    41,     0,    80,    46,   101,     0,    59,    57,
       0,     0,    83,     0,   100,     0,   385,     0,   392,    69,
       0,   382,     0,     0,   354,    85,     0,   390,    43,    68,
      84,     0,    82,    79,    99,   104,    15,    87,   330,   331,
     334,   333,   335,   336,   338,   339,   357,   345,   363,   364,
     394,   395,   396,   397,   398,   399,   400,   346,   348,   349,
     352,   353,   217,   121,     0,   155,     0,   119,   124,   125,
     126,   127,   120,   256,     0,   257,   258,   259,   260,   240,
       0,   216,   218,     0,   219,   229,   249,   241,   230,   242,
       0,     0,   231,   232,   243,     0,   233,   248,   234,     0,
       0,   274,     0,   275,   244,   245,   246,   247,   250,   222,
       0,     0,     0,     0,     0,     0,     0,   224,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   252,
      18,    21,    22,    16,    17,    19,    20,    44,   386,     0,
       0,    97,    94,    70,    75,   358,   359,   374,   380,   204,
      72,    77,   203,   124,   127,    76,   150,   152,   151,   158,
     160,   162,   164,   166,   168,   170,   173,   179,   183,   186,
     190,   191,   194,   199,   205,   206,   202,     0,     0,     0,
       0,     0,     0,    74,    93,    39,    88,    89,    42,   102,
      86,     0,   221,   208,   210,     0,     0,   207,   209,     0,
       0,   381,     0,     0,   215,   214,   220,   255,    15,     0,
       0,     0,     0,     0,     0,     0,     0,   306,   307,     0,
       0,     0,   309,     0,     0,     0,     0,     0,   155,     0,
       0,     0,   196,   195,   125,   126,   198,   197,     0,   383,
       0,    98,    95,     0,     0,   379,   384,     0,     0,   378,
       0,   372,     0,   373,     0,   371,     0,   369,   370,     0,
       0,   365,   366,   367,   368,   347,     0,     0,     0,     0,
       0,   375,   376,   377,     0,     0,     0,     0,     0,   360,
     362,     0,     0,     0,   204,   192,   193,   200,   201,     0,
       0,   204,   118,     0,   114,     0,    90,     0,     0,     0,
     122,     0,   108,     0,   139,   133,     0,   130,     0,   153,
     154,     0,   270,   299,     0,   298,     0,     0,     0,   304,
     223,   263,   269,   297,     0,   296,   224,     0,     0,   143,
     147,     0,     0,   144,     0,   308,     0,   227,     0,   267,
       0,   310,     0,   355,   356,   311,   315,   313,     0,     0,
       0,   123,   253,    96,   161,     0,   163,   165,   167,   169,
     172,   171,     0,   178,   177,   176,   175,   174,   180,   181,
     182,   184,   185,   188,   187,   189,     0,     0,   113,     0,
     116,     0,    92,     0,   107,   105,     0,     0,   134,     0,
     131,     0,   132,   264,     0,   229,   236,     0,   237,     0,
     238,   239,     0,     0,   276,     0,   277,     0,    44,   300,
       0,     0,   282,     0,   284,     0,     0,   278,     0,   145,
     141,   148,     0,   146,   142,     0,   128,   225,     0,     0,
       0,     0,   314,   312,     0,   321,     0,     0,   211,   212,
     117,   115,    91,   106,     0,   109,     0,   111,   140,     0,
     135,   332,     0,    15,     0,     0,     0,     0,     0,     0,
     302,   285,   287,   303,   279,     0,     0,     0,   149,   129,
     228,   268,     0,   137,   272,   319,     0,     0,     0,   251,
     159,   110,   112,   136,   265,     0,   271,     0,     0,     0,
       0,   305,     0,     0,   254,   301,     0,     0,     0,   280,
     138,     0,     0,     0,   317,     0,     0,     0,   290,     0,
     292,     0,     0,     0,   281,   283,     0,   320,   316,   318,
       0,   293,   295,     0,     0,     0,   286,   273,   266,     0,
       0,     0,   288,     0,   289,   291,   294
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -446,  -446,  -446,    33,   873,  -446,   334,   107,  -138,  -446,
     -11,   270,  -200,  -446,  -446,  -446,  -262,  -133,  -446,   -58,
     381,  -446,    -8,    16,     4,  -446,  -446,   301,  -446,   272,
    -446,  -446,   -70,   223,  -243,  -249,  -446,  -446,  -446,   -15,
    -446,  -446,  -365,    75,  -446,     1,  -446,  -446,  -446,  -446,
    -446,   219,  -446,  -163,  -446,   780,  -446,   943,  2327,  2386,
    1105,  -411,  -446,    26,  -250,  -128,  -446,  2035,  -446,  -183,
    -446,    11,     5,    12,     6,    17,   -65,     0,   -93,   -77,
    -268,  1268,  1430,  -114,  -446,  1593,  1755,  -446,   -50,  -286,
    -181,  -446,  -321,  -446,  -446,  -446,  -446,  1988,    80,   215,
    -446,  -446,  -446,  -446,  -446,  -101,   331,  -446,  -446,  -446,
    -446,   422,  -446,  -446,  -446,  -446,  -446,  -446,   509,   524,
    -446,  -446,  -193,  -297,  -309,  -184,   602,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,   -62,  -446,  -445,   -61,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,    65,  -446,  -226,
      61,   687,  -446,  -446,   318,  -446,  -446,  -446,  -446,    23,
       9,  -124,  -446,   101,  -446,   102,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -264,  -241,  -446,   359,  -446,
    -121,  -111,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -171,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,   233,
    -284,  -446,   617,  2044,   -26,   -46,   -94,  -122,    -2,   142,
     -29,  -446,  -446,  -446,  -446,  -446,  -446,  -446,   -20,  -446
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     8,     9,    10,   172,    12,    13,    14,   125,   173,
     174,    68,    69,    70,    71,    72,    73,    74,    75,   110,
     338,    77,    15,    16,    17,    49,    42,    51,    80,    81,
      82,    83,   104,   105,   106,   260,    84,   120,    85,   135,
     296,   406,   297,    86,   250,   251,   143,    87,    88,   141,
     121,   145,   408,   261,   403,   262,   177,   263,   179,   180,
     264,   413,   182,   439,   440,   414,   266,   183,   184,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   189,   190,
     191,   192,   193,   323,   333,   334,   538,   194,   504,   195,
     196,   197,   198,   506,   199,   200,   201,   202,   203,   508,
     204,   205,   206,   510,   207,   611,   208,   511,   209,   210,
     211,   514,   434,   424,   425,   519,   212,   213,   516,   214,
     215,   216,   217,   218,   455,   456,   586,   587,   457,    90,
      91,    92,    93,    94,    95,    96,    97,   219,   220,   562,
     221,   222,   223,   224,    98,   225,   226,    18,    19,    20,
      21,    22,   228,   229,   376,   230,   231,    23,    24,   232,
     233,   136,   458,   459,   234,   287,   288,   391,   392,   393,
     235,   236,   377,   378,   379,   380,   369,   370,   366,   362,
     364,   289,   384,   385,   386,   360,   357,   290,   312,   132,
     350,   358,   291,   252,   100,   101,   111,   138,   239,   130,
      46,   240,   241,   242,   243,   244,   245,   246,    38,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,   227,    89,   294,   265,   433,   351,   113,   301,   314,
      48,   293,   133,   387,    41,   409,    52,   435,   112,   395,
     396,   397,   398,    52,   427,   329,    53,    25,    53,   400,
      89,    33,   102,   535,   119,    45,   388,    47,    34,   389,
     390,    67,   492,   402,    78,    29,    31,   108,   126,   124,
       5,   448,   109,   103,   303,   307,    79,   108,   102,    35,
     102,    99,  -156,    40,   304,   308,   227,   109,    54,    67,
     144,    44,    78,     1,     2,     3,     4,     5,   123,   238,
     298,   306,  -157,   310,    79,   554,   556,    54,   311,    99,
     559,   399,   330,  -156,    33,   146,    35,   123,   331,   140,
     335,    34,   129,   337,   302,   247,   292,   147,    26,   348,
     254,   139,   248,  -157,   473,   146,   249,   112,   128,   131,
      32,   109,   493,   483,   484,   485,   552,   300,    35,   582,
       6,     7,     1,     2,     3,     4,     5,    32,   303,   158,
     159,   307,   107,   615,   315,   131,   355,   309,   304,   525,
     356,   308,   114,   116,   254,    57,    58,    59,    60,    61,
      62,    63,    64,   348,   265,   354,   248,   627,    44,   109,
     247,   349,    50,   122,   158,   159,   472,   227,   416,    43,
     421,   547,   418,   340,   419,   420,   126,    43,   128,   531,
       7,   316,   142,   531,    44,   126,   431,   432,   317,   109,
    -262,   336,   436,    44,  -261,  -262,  -262,   320,   321,  -261,
    -261,   -39,   247,   460,   387,   387,   387,   303,   548,   423,
     423,   327,   328,    35,   332,   423,   416,   304,   314,   254,
     465,   576,    43,   309,   569,   441,   441,   388,   388,   388,
     550,   126,   367,   368,   354,   109,   404,   433,   354,    44,
      66,   126,   354,   430,   128,   412,    43,   133,    44,   435,
     371,   372,   373,   374,   255,   256,   292,   109,   597,   599,
     134,   438,   442,   303,   294,   529,   453,   454,   606,   533,
     303,   247,   137,   304,   227,   227,   381,   382,   383,   417,
     304,   478,   479,   480,   500,   248,   502,   375,    44,   247,
     354,   349,   247,   254,   470,   471,   359,   306,   361,   527,
     481,   482,   314,   532,   309,   363,   450,   365,   309,   148,
     539,   128,   446,  -226,   437,   634,   158,   159,   151,   445,
     247,    66,   561,   449,  -235,   451,   639,     1,     2,     3,
       4,     5,   249,   112,   614,   441,    30,   126,   115,   441,
      56,   109,   118,   253,   463,    44,   443,   488,   294,   490,
     299,   265,   494,   495,   590,   466,   158,   159,   464,   227,
     468,   558,   629,   549,   467,   602,   537,   474,   475,   476,
     477,   530,   336,   469,  -155,   534,   605,   126,   247,   247,
     630,   109,   353,   542,   543,    44,   117,   573,   574,   447,
     452,   518,   410,   411,    37,    39,   247,    55,   247,   545,
     578,   585,   292,   584,   612,  -155,   292,   313,     0,   570,
     588,     0,     0,     0,     0,   595,   254,   423,   158,   159,
       0,     0,   526,    76,   405,   528,     0,     0,     0,   407,
       0,     0,     0,   551,   436,     0,  -155,   553,     0,   126,
     -39,     0,     0,   109,     0,   585,     0,    44,     0,    76,
       0,    76,     0,   292,   423,   423,     0,   423,   580,     0,
       0,     0,     0,   247,   423,   527,     0,  -155,     0,   585,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,   574,     0,     0,   589,     0,     0,     0,
       0,   247,     0,   247,     0,     0,   175,     0,    76,     0,
     565,   566,     0,   259,     0,  -226,     0,   295,   254,     0,
     133,   423,     0,     0,   575,   -52,   -52,   -52,   -52,   -52,
       0,     0,   423,     0,     0,   133,   248,   581,     0,     0,
       0,     0,   247,     0,   518,   489,     0,   518,   491,   518,
       0,    35,     0,     0,     0,   499,     0,   247,     0,     0,
       0,     0,     0,   628,     0,   520,   603,   254,     0,     0,
       0,   175,     0,     0,     0,   518,     0,     0,   518,     0,
     518,     0,     0,     0,     0,     0,     0,   247,   247,     0,
       0,     0,     0,     0,     0,   254,     0,   518,     0,   518,
     621,   622,     0,   247,     0,   154,   295,   259,     0,   259,
     518,     0,   259,     0,     0,   518,   342,   346,   259,   633,
     518,   518,     0,   518,   637,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,   505,   258,     0,     0,
       0,   126,     0,     0,   596,     0,     0,   601,     0,   604,
     160,   161,   162,   163,   164,   165,   166,    35,   167,     0,
     168,     0,     0,     0,     0,     0,     0,     0,   394,   394,
     394,   394,   401,   259,     0,   616,     0,   499,   618,     0,
     620,     0,   175,     0,     0,     0,   259,   259,     0,     0,
       0,   259,     0,   259,   259,     0,   499,   631,   499,   632,
       0,   499,     0,     0,     0,   259,   259,   175,     0,     0,
     638,     0,   520,     0,    76,   642,     0,     0,     0,   127,
     644,   645,   259,   646,   499,   127,     0,     0,     0,     0,
       0,     0,     0,     0,    76,   259,     0,     0,   394,   259,
     127,   394,   237,   394,     0,   394,     0,   394,     0,   154,
     394,   394,   507,     0,     0,     0,     0,    76,   394,   394,
     394,   394,     0,     0,     0,   394,   394,   394,   394,   394,
       0,     0,   394,   394,   394,     0,     0,     0,     0,   505,
       0,     0,   505,     0,   505,   126,     0,     0,   295,   175,
     175,     0,   305,     0,   160,   161,   162,   163,   164,   165,
     166,    35,   167,     0,   168,     0,     0,   237,     0,     0,
     505,     0,     0,   505,     0,   505,     0,     0,   259,     0,
       0,     0,   259,     0,     0,   259,     0,     0,     0,   259,
       0,     0,   505,     0,   505,     0,     0,   324,   325,   326,
       0,     0,     0,   509,     0,   505,     0,     0,     0,   237,
     505,   341,   237,   237,     0,   505,   505,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,   394,   394,     0,
     259,     0,   295,    11,   175,     0,   305,   259,   259,     0,
     259,     0,   259,    28,     0,    11,    11,     0,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,   507,     0,
     507,     0,    28,    11,    28,   176,   259,   259,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,   237,     0,
       0,   259,   259,     0,     0,   295,   507,     0,   394,   507,
     512,   507,     0,     0,     0,     0,   237,   237,   237,   237,
       0,     0,     0,   237,     0,   513,     0,   444,   507,   175,
     507,     0,     0,     0,     0,   305,     0,     0,     0,   305,
       0,   507,     0,   305,     0,     0,   507,   237,     0,   295,
     176,   507,   507,     0,   507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,     0,   509,     0,     0,   509,
       0,   509,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,   305,   176,     0,     0,   343,   347,   509,   305,     0,
     509,     0,   509,   515,     0,   237,   237,   496,   497,     0,
       0,     0,     0,     0,   501,     0,     0,     0,   237,   509,
       0,   509,     0,   237,     0,   237,     0,     0,     0,     0,
       0,     0,   509,     0,     0,     0,     0,   509,     0,     0,
       0,     0,   509,   509,     0,   509,     0,   540,   178,   541,
       0,     0,     0,   512,     0,   544,   512,     0,   512,     0,
       0,   176,     0,     0,     0,     0,     0,     0,   513,     0,
       0,   513,     0,   513,     0,     0,     0,     0,     0,   176,
     176,   176,   176,     0,   512,     0,   176,   512,   517,   512,
     237,     0,     0,     0,     0,     0,     0,     0,     0,   513,
       0,     0,   513,     0,   513,     0,   512,     0,   512,     0,
     176,     0,     0,   178,   568,     0,     0,   237,   237,   512,
     237,   513,     0,   513,   512,   237,     0,     0,     0,   512,
     512,     0,   512,     0,   513,     0,     0,     0,     0,   513,
       0,     0,     0,     0,   513,   513,   515,   513,     0,   515,
       0,   515,     0,     0,     0,   178,     0,     0,     0,   237,
       0,   237,   237,   237,   237,   237,   237,     0,   176,   176,
       0,     0,   237,     0,   237,     0,     0,   515,     0,     0,
     515,   176,   515,     0,     0,     0,   176,     0,   176,     0,
       0,     0,   237,     0,     0,   237,     0,   237,     0,   515,
       0,   515,     0,     0,   237,   237,     0,     0,     0,     0,
     181,     0,   515,     0,   237,     0,   237,   515,     0,   237,
     237,     0,   515,   515,   178,   515,     0,   237,     0,     0,
     237,   517,   237,     0,   517,     0,   517,   237,   237,     0,
     237,     0,   178,   178,   178,   178,     0,     0,     0,   178,
       0,     0,     0,   176,     0,     0,     0,     0,     0,     0,
       0,     0,   517,     0,     0,   517,     0,   517,     0,     0,
       0,     0,     0,   178,     0,   181,     0,     0,     0,     0,
     176,   176,     0,   176,   517,     0,   517,     0,   176,     0,
       0,     0,     0,     0,     0,     0,     0,   517,     0,     0,
       0,     0,   517,     0,     0,     0,     0,   517,   517,     0,
     517,     0,     0,     0,     0,     0,     0,   181,     0,     0,
       0,     0,   176,     0,   176,   176,   176,   176,   176,   176,
       0,   178,   178,     0,     0,   176,     0,   176,     0,     0,
       0,     0,     0,     0,   178,     0,     0,     0,     0,   178,
       0,   178,     0,     0,     0,   176,     0,     0,   176,     0,
     176,     0,     0,     0,     0,     0,     0,   176,   176,     0,
       0,     0,     0,   185,     0,     0,   154,   176,     0,   176,
       0,     0,   176,   176,     0,     0,   181,   255,   256,     0,
     176,   158,   159,   176,     0,   176,     0,     0,     0,     0,
     176,   176,   257,   176,   181,   181,   181,   181,   258,     0,
       0,   181,   126,     0,    50,    66,   178,     0,     0,   128,
       0,   160,   161,   162,   163,   164,   165,   166,    35,   167,
       0,   168,     0,     0,     0,   181,     0,     0,   185,     0,
       0,     0,     0,   178,   178,     0,   178,     0,     0,     0,
       0,   178,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     1,     2,     3,     4,     5,     0,     0,     0,
     185,     0,     0,     0,     0,   178,     0,   178,   178,   178,
     178,   178,   178,   181,   181,     0,     0,     0,   178,     0,
     178,     0,     0,     0,     0,     0,   181,     0,    50,    66,
       0,   181,     0,   181,     0,     0,     0,     0,   178,     0,
       0,   178,    35,   178,     0,     0,     0,     0,     0,     0,
     178,   178,     0,     0,     0,   186,     0,     0,     0,   154,
     178,     0,   178,     0,     0,   178,   178,     0,     0,   185,
     255,   256,     0,   178,   158,   159,   178,     0,   178,     0,
       0,     0,     0,   178,   178,   257,   178,   185,   185,   185,
     185,   258,     0,     0,   185,   126,     0,    50,   181,     0,
       0,     0,     0,     0,   160,   161,   162,   163,   164,   165,
     166,    35,   167,     0,   168,     0,     0,     0,   185,     0,
     186,     0,     0,     0,     0,   181,   181,     0,   181,     0,
       0,     0,     0,   181,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     1,     2,     3,     4,     5,     0,     0,     0,
       0,     0,   186,     0,     0,     0,     0,   181,     0,   181,
     181,   181,   181,   181,   181,     0,   185,   185,     0,     0,
     181,     0,   181,     0,     0,     0,     0,     0,     0,   185,
       0,     0,     0,     0,   185,     0,   185,     0,     0,     0,
     181,     0,    35,   181,     0,   181,     0,     0,     0,     0,
       0,     0,   181,   181,     0,     0,     0,     0,   187,     0,
       0,   154,   181,     0,   181,     0,     0,   181,   181,     0,
       0,   186,   255,   256,     0,   181,   158,   159,   181,     0,
     181,     0,     0,     0,     0,   181,   181,   257,   181,   186,
     186,   186,   186,   258,     0,     0,   186,   126,     0,    50,
      66,   185,   154,     0,     0,     0,   160,   161,   162,   163,
     164,   165,   166,    35,   167,     0,   168,   158,   159,     0,
     186,     0,     0,   187,     0,     0,     0,     0,   185,   185,
       0,   185,     0,     0,     0,     0,   185,     0,   126,   248,
       0,     0,     0,     0,     0,     0,     0,   160,   161,   162,
     163,   164,   165,   166,    35,   167,     0,   168,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,     0,
     185,     0,   185,   185,   185,   185,   185,   185,   186,   186,
       0,     0,     0,   185,     0,   185,     0,     0,     0,     0,
       0,   186,     0,     0,     0,     0,   186,     0,   186,     0,
       0,     0,     0,   185,     0,     0,   185,     0,   185,     0,
       0,     0,     0,     0,     0,   185,   185,     0,     0,     0,
     188,     0,     0,     0,   154,   185,     0,   185,     0,     0,
     185,   185,     0,     0,   187,   255,   256,     0,   185,   158,
     159,   185,     0,   185,     0,     0,     0,     0,   185,   185,
     257,   185,   187,   187,   187,   187,   258,     0,     0,   187,
     126,     0,     0,   186,     0,   154,    43,     0,     0,   160,
     161,   162,   163,   164,   165,   166,    35,   167,     0,   168,
     158,   159,     0,   187,     0,   188,     0,     0,     0,     0,
     186,   186,     0,   186,     0,     0,     0,     0,   186,     0,
       0,   126,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,   162,   163,   164,   165,   166,    35,   167,     0,
     168,     0,     0,     0,     0,     0,     0,   188,     0,     0,
       0,     0,   186,     0,   186,   186,   186,   186,   186,   186,
       0,   187,   187,     0,     0,   186,     0,   186,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,   187,
       0,   187,     0,     0,     0,   186,     0,     0,   186,     0,
     186,     0,     0,     0,     0,     0,     0,   186,   186,     0,
       0,     0,     0,     0,     0,     0,     0,   186,     0,   186,
       0,     0,   186,   186,     0,     0,   188,     0,     0,     0,
     186,     0,     0,   186,     0,   186,     0,     0,     0,     0,
     186,   186,     0,   186,   188,   188,   188,   188,     0,     0,
     149,   188,   150,   151,   152,   153,   187,   154,   155,     0,
       0,     0,     0,     0,     0,     0,   156,   157,     0,     0,
       0,     0,   158,   159,     0,   188,     0,     0,     0,     0,
       0,     0,     0,   187,   187,     0,   187,     0,     0,     0,
       0,   187,     0,   126,     0,    50,     0,     0,     0,    43,
       0,     0,   160,   161,   162,   163,   164,   165,   166,    35,
     167,     0,   168,   169,     0,     0,     0,     0,     0,   170,
     171,     0,     0,     0,     0,   187,     0,   187,   187,   187,
     187,   187,   187,   188,   188,     0,     0,   267,   187,     0,
     187,     0,     0,     0,     0,     0,   188,     0,     0,     0,
       0,   188,     0,   188,     0,     0,     0,     0,   187,     0,
       0,   187,     0,   187,     0,     0,     0,     0,     0,     0,
     187,   187,     0,     0,     0,     0,     0,     0,     0,     0,
     187,     0,   187,     0,     0,   187,   187,     0,     0,     0,
     339,     0,     0,   187,     0,     0,   187,     0,   187,     0,
       0,     0,     0,   187,   187,     0,   187,    57,    58,    59,
      60,    61,    62,    63,    64,   318,     0,     0,   188,   319,
       0,     0,     0,   154,     0,     0,   322,     0,     0,     0,
       0,   267,     0,   267,   255,   256,   267,     0,   158,   159,
       0,     0,   267,     0,     0,   188,   188,     0,   188,   257,
       0,     0,     0,   188,     0,   258,     0,     0,     0,   126,
       0,     0,     0,     0,   352,     0,     0,     0,   160,   161,
     162,   163,   164,   165,   166,    35,   167,   422,   168,     0,
     429,     0,     0,     0,     0,     0,     0,   188,     0,   188,
     188,   188,   188,   188,   188,     0,   267,   267,     0,     0,
     188,     0,   188,     0,     0,     0,     0,     0,   462,     0,
     267,   267,     0,     0,     0,   267,     0,   267,   267,   415,
     188,     0,     0,   188,     0,   188,     0,     0,     0,   267,
     267,     0,   188,   188,   426,   428,     0,     0,     0,     0,
       0,     0,   188,     0,   188,     0,   267,   188,   188,     0,
       0,     0,     0,     0,     0,   188,     0,     0,   188,   267,
     188,     0,   461,   267,     0,   188,   188,     0,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   503,
       0,     0,     0,     0,   522,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,   148,     0,     0,
       0,     0,     0,   486,   487,   154,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,   498,     0,     0,
     158,   159,     0,     0,     0,     0,     0,     0,   521,     0,
       0,   523,   267,     0,     0,     0,   267,     0,     0,   267,
       0,   126,     0,   267,     0,     0,     0,    43,   536,     0,
     160,   161,   162,   163,   164,   165,   166,    35,   167,     0,
     168,     0,     0,     0,   546,     0,     0,     0,     0,   571,
       0,   572,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,     0,     0,     0,     0,
       0,   267,   267,     0,   267,     0,   267,     0,     0,     0,
     555,   557,     0,     0,     0,   560,     0,     0,     0,     0,
     594,   563,   422,   564,     0,   429,     0,   462,     0,   567,
     267,   267,   344,   344,     0,   609,     0,     0,     0,     0,
       0,     0,   577,     0,     0,   267,   267,     0,     0,   579,
       0,     0,     0,   503,   583,     0,   522,     0,   524,     0,
       0,     0,     0,     0,     0,   624,   625,     0,   591,     0,
     592,     0,     0,   593,     0,   571,     0,   572,     0,   598,
     600,   636,     0,     0,   344,   344,   344,   344,   594,   607,
     608,   345,   345,   609,     0,     0,   610,     0,   624,   625,
     613,   636,     0,     0,     0,     0,     0,     0,   267,     0,
       0,   617,     0,   619,     0,     0,     0,     0,     0,     0,
     623,     0,     0,     0,     0,   626,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   635,     0,     0,     0,
       0,     0,     0,   345,   345,   345,   345,   640,   641,     0,
       0,     0,     0,   643,   344,     0,     0,   344,     0,   344,
       0,   344,     0,   344,     0,     0,   344,   344,     0,     0,
       0,     0,     0,     0,   344,   344,   344,   344,     0,     0,
       0,   344,   344,   344,   344,   344,     0,     0,   344,   344,
     344,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   345,     0,     0,   345,     0,   345,     0,
     345,     0,   345,     0,     0,   345,   345,     0,     0,     0,
       0,     0,     0,   345,   345,   345,   345,     0,     0,     0,
     345,   345,   345,   345,   345,     0,     0,   345,   345,   345,
      57,    58,    59,    60,    61,    62,    63,    64,   148,   149,
       0,   150,   151,   152,   153,     0,   154,   155,     1,     2,
       3,     4,     5,     0,     0,   156,   157,     0,     0,     0,
       0,   158,   159,   344,   344,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,    50,    66,     0,     0,    43,     0,
       0,   160,   161,   162,   163,   164,   165,   166,    35,   167,
     154,   168,   169,     0,     0,     0,     0,     0,   170,   171,
       0,   255,   256,     0,     0,   158,   159,     0,     0,     0,
       0,     0,   345,   345,   344,     0,   257,     0,     0,     0,
       0,     0,   258,     0,     0,     0,   126,   248,     0,     0,
       0,     0,     0,     0,     0,   160,   161,   162,   163,   164,
     165,   166,    35,   167,   154,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,     0,     0,   158,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,   154,   345,     0,     0,   258,     0,     0,     0,
     126,     0,     0,   255,   256,   137,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    35,   167,   257,   168,
       0,     0,     0,     0,   258,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   161,   162,
     163,   164,   165,   166,    35,   167,     0,   168
};

static const yytype_int16 yycheck[] =
{
      20,   125,    52,   136,   132,   326,   249,    77,   146,   190,
      39,   133,   106,   277,    34,   301,    42,   326,    76,   287,
     288,   289,   290,    49,   321,   225,    46,     0,    48,   291,
      80,    15,    52,   444,    80,    37,   277,    39,    15,    32,
      33,    52,   407,   292,    52,    12,    13,    67,    55,    99,
      25,   335,    59,    55,   175,   176,    52,    77,    78,    71,
      80,    52,    52,    30,   175,   176,   190,    59,    80,    80,
     120,    63,    80,    21,    22,    23,    24,    25,    98,   125,
     138,   175,    52,   177,    80,   496,   497,    80,    52,    80,
     501,   291,   225,    83,    78,   121,    71,   117,   226,   114,
     228,    78,   104,   231,   174,   125,   132,   122,    77,   237,
     130,   113,    56,    83,   376,   141,   127,   175,    62,    83,
      13,    59,   408,   391,   392,   393,   491,   142,    71,   540,
      78,    79,    21,    22,    23,    24,    25,    30,   259,    34,
      35,   262,    67,   588,   190,    83,    50,   176,   259,   433,
      54,   262,    77,    78,   174,     3,     4,     5,     6,     7,
       8,     9,    10,   291,   292,   259,    56,   612,    63,    59,
     190,    53,    57,    98,    34,    35,   376,   301,   306,    61,
     318,   465,   310,   233,   312,   313,    55,    61,    62,   439,
      79,   193,   117,   443,    63,    55,   324,   325,   200,    59,
      56,   230,   326,    63,    56,    61,    62,   209,   210,    61,
      62,    71,   232,   341,   478,   479,   480,   338,   486,   320,
     321,   223,   224,    71,   226,   326,   354,   338,   409,   249,
     358,   528,    61,   262,   518,   329,   330,   478,   479,   480,
     489,    55,    40,    41,   338,    59,   292,   568,   342,    63,
      58,    55,   346,   323,    62,   301,    61,   351,    63,   568,
      36,    37,    38,    39,    30,    31,   292,    59,   565,   566,
      76,   329,   330,   394,   407,   438,    26,    27,   575,   442,
     401,   301,    60,   394,   408,   409,    46,    47,    48,   309,
     401,   384,   385,   386,   416,    56,   418,    73,    63,   319,
     394,    53,   322,   323,   369,   370,    49,   401,    43,   437,
     387,   388,   493,   441,   343,    44,   336,    42,   347,    11,
     448,    62,   333,    11,   326,   622,    34,    35,    15,   331,
     350,    58,    13,   335,    13,   337,   633,    21,    22,    23,
      24,    25,   353,   401,   587,   439,    12,    55,    78,   443,
      49,    59,    80,   130,   353,    63,   330,   403,   491,   405,
     141,   489,   408,   409,   547,   360,    34,    35,   357,   493,
     364,   499,   615,   487,   362,   568,   446,   377,   378,   379,
     380,   439,   411,   366,    52,   443,   570,    55,   408,   409,
     616,    59,   250,   455,   455,    63,    78,   525,   526,   334,
     339,   421,   301,   301,    23,    24,   426,    48,   428,   459,
     532,   544,   438,   541,   585,    83,   442,   184,    -1,   520,
     544,    -1,    -1,    -1,    -1,   563,   446,   528,    34,    35,
      -1,    -1,   434,    52,   292,   437,    -1,    -1,    -1,   297,
      -1,    -1,    -1,   489,   568,    -1,    52,   493,    -1,    55,
      56,    -1,    -1,    59,    -1,   588,    -1,    63,    -1,    78,
      -1,    80,    -1,   489,   565,   566,    -1,   568,   538,    -1,
      -1,    -1,    -1,   493,   575,   603,    -1,    83,    -1,   612,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,   621,    -1,    -1,   546,    -1,    -1,    -1,
      -1,   521,    -1,   523,    -1,    -1,   125,    -1,   127,    -1,
     512,   513,    -1,   132,    -1,    11,    -1,   136,   538,    -1,
     614,   622,    -1,    -1,   526,    21,    22,    23,    24,    25,
      -1,    -1,   633,    -1,    -1,   629,    56,   539,    -1,    -1,
      -1,    -1,   562,    -1,   564,   403,    -1,   567,   406,   569,
      -1,    71,    -1,    -1,    -1,   413,    -1,   577,    -1,    -1,
      -1,    -1,    -1,   613,    -1,   423,   568,   587,    -1,    -1,
      -1,   190,    -1,    -1,    -1,   595,    -1,    -1,   598,    -1,
     600,    -1,    -1,    -1,    -1,    -1,    -1,   607,   608,    -1,
      -1,    -1,    -1,    -1,    -1,   615,    -1,   617,    -1,   619,
     602,   603,    -1,   623,    -1,    19,   225,   226,    -1,   228,
     630,    -1,   231,    -1,    -1,   635,   235,   236,   237,   621,
     640,   641,    -1,   643,   626,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,   421,    51,    -1,    -1,
      -1,    55,    -1,    -1,   564,    -1,    -1,   567,    -1,   569,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   288,
     289,   290,   291,   292,    -1,   595,    -1,   535,   598,    -1,
     600,    -1,   301,    -1,    -1,    -1,   305,   306,    -1,    -1,
      -1,   310,    -1,   312,   313,    -1,   554,   617,   556,   619,
      -1,   559,    -1,    -1,    -1,   324,   325,   326,    -1,    -1,
     630,    -1,   570,    -1,   333,   635,    -1,    -1,    -1,   102,
     640,   641,   341,   643,   582,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   353,   354,    -1,    -1,   357,   358,
     123,   360,   125,   362,    -1,   364,    -1,   366,    -1,    19,
     369,   370,   421,    -1,    -1,    -1,    -1,   376,   377,   378,
     379,   380,    -1,    -1,    -1,   384,   385,   386,   387,   388,
      -1,    -1,   391,   392,   393,    -1,    -1,    -1,    -1,   564,
      -1,    -1,   567,    -1,   569,    55,    -1,    -1,   407,   408,
     409,    -1,   175,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    -1,    74,    -1,    -1,   190,    -1,    -1,
     595,    -1,    -1,   598,    -1,   600,    -1,    -1,   437,    -1,
      -1,    -1,   441,    -1,    -1,   444,    -1,    -1,    -1,   448,
      -1,    -1,   617,    -1,   619,    -1,    -1,   220,   221,   222,
      -1,    -1,    -1,   421,    -1,   630,    -1,    -1,    -1,   232,
     635,   234,   235,   236,    -1,   640,   641,    -1,   643,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,    -1,
     489,    -1,   491,     0,   493,    -1,   259,   496,   497,    -1,
     499,    -1,   501,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   564,    -1,    -1,   567,    -1,
     569,    -1,    29,    30,    31,   125,   525,   526,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,   301,    -1,
      -1,   540,   541,    -1,    -1,   544,   595,    -1,   547,   598,
     421,   600,    -1,    -1,    -1,    -1,   319,   320,   321,   322,
      -1,    -1,    -1,   326,    -1,   421,    -1,   330,   617,   568,
     619,    -1,    -1,    -1,    -1,   338,    -1,    -1,    -1,   342,
      -1,   630,    -1,   346,    -1,    -1,   635,   350,    -1,   588,
     190,   640,   641,    -1,   643,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   603,    -1,   564,    -1,    -1,   567,
      -1,   569,    -1,   612,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   394,   232,    -1,    -1,   235,   236,   595,   401,    -1,
     598,    -1,   600,   421,    -1,   408,   409,   410,   411,    -1,
      -1,    -1,    -1,    -1,   417,    -1,    -1,    -1,   421,   617,
      -1,   619,    -1,   426,    -1,   428,    -1,    -1,    -1,    -1,
      -1,    -1,   630,    -1,    -1,    -1,    -1,   635,    -1,    -1,
      -1,    -1,   640,   641,    -1,   643,    -1,   450,   125,   452,
      -1,    -1,    -1,   564,    -1,   458,   567,    -1,   569,    -1,
      -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,   564,    -1,
      -1,   567,    -1,   569,    -1,    -1,    -1,    -1,    -1,   319,
     320,   321,   322,    -1,   595,    -1,   326,   598,   421,   600,
     493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   595,
      -1,    -1,   598,    -1,   600,    -1,   617,    -1,   619,    -1,
     350,    -1,    -1,   190,   517,    -1,    -1,   520,   521,   630,
     523,   617,    -1,   619,   635,   528,    -1,    -1,    -1,   640,
     641,    -1,   643,    -1,   630,    -1,    -1,    -1,    -1,   635,
      -1,    -1,    -1,    -1,   640,   641,   564,   643,    -1,   567,
      -1,   569,    -1,    -1,    -1,   232,    -1,    -1,    -1,   562,
      -1,   564,   565,   566,   567,   568,   569,    -1,   408,   409,
      -1,    -1,   575,    -1,   577,    -1,    -1,   595,    -1,    -1,
     598,   421,   600,    -1,    -1,    -1,   426,    -1,   428,    -1,
      -1,    -1,   595,    -1,    -1,   598,    -1,   600,    -1,   617,
      -1,   619,    -1,    -1,   607,   608,    -1,    -1,    -1,    -1,
     125,    -1,   630,    -1,   617,    -1,   619,   635,    -1,   622,
     623,    -1,   640,   641,   301,   643,    -1,   630,    -1,    -1,
     633,   564,   635,    -1,   567,    -1,   569,   640,   641,    -1,
     643,    -1,   319,   320,   321,   322,    -1,    -1,    -1,   326,
      -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   595,    -1,    -1,   598,    -1,   600,    -1,    -1,
      -1,    -1,    -1,   350,    -1,   190,    -1,    -1,    -1,    -1,
     520,   521,    -1,   523,   617,    -1,   619,    -1,   528,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   630,    -1,    -1,
      -1,    -1,   635,    -1,    -1,    -1,    -1,   640,   641,    -1,
     643,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,   562,    -1,   564,   565,   566,   567,   568,   569,
      -1,   408,   409,    -1,    -1,   575,    -1,   577,    -1,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,   426,
      -1,   428,    -1,    -1,    -1,   595,    -1,    -1,   598,    -1,
     600,    -1,    -1,    -1,    -1,    -1,    -1,   607,   608,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    19,   617,    -1,   619,
      -1,    -1,   622,   623,    -1,    -1,   301,    30,    31,    -1,
     630,    34,    35,   633,    -1,   635,    -1,    -1,    -1,    -1,
     640,   641,    45,   643,   319,   320,   321,   322,    51,    -1,
      -1,   326,    55,    -1,    57,    58,   493,    -1,    -1,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      -1,    74,    -1,    -1,    -1,   350,    -1,    -1,   190,    -1,
      -1,    -1,    -1,   520,   521,    -1,   523,    -1,    -1,    -1,
      -1,   528,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,   562,    -1,   564,   565,   566,
     567,   568,   569,   408,   409,    -1,    -1,    -1,   575,    -1,
     577,    -1,    -1,    -1,    -1,    -1,   421,    -1,    57,    58,
      -1,   426,    -1,   428,    -1,    -1,    -1,    -1,   595,    -1,
      -1,   598,    71,   600,    -1,    -1,    -1,    -1,    -1,    -1,
     607,   608,    -1,    -1,    -1,   125,    -1,    -1,    -1,    19,
     617,    -1,   619,    -1,    -1,   622,   623,    -1,    -1,   301,
      30,    31,    -1,   630,    34,    35,   633,    -1,   635,    -1,
      -1,    -1,    -1,   640,   641,    45,   643,   319,   320,   321,
     322,    51,    -1,    -1,   326,    55,    -1,    57,   493,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    -1,    74,    -1,    -1,    -1,   350,    -1,
     190,    -1,    -1,    -1,    -1,   520,   521,    -1,   523,    -1,
      -1,    -1,    -1,   528,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,   562,    -1,   564,
     565,   566,   567,   568,   569,    -1,   408,   409,    -1,    -1,
     575,    -1,   577,    -1,    -1,    -1,    -1,    -1,    -1,   421,
      -1,    -1,    -1,    -1,   426,    -1,   428,    -1,    -1,    -1,
     595,    -1,    71,   598,    -1,   600,    -1,    -1,    -1,    -1,
      -1,    -1,   607,   608,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    19,   617,    -1,   619,    -1,    -1,   622,   623,    -1,
      -1,   301,    30,    31,    -1,   630,    34,    35,   633,    -1,
     635,    -1,    -1,    -1,    -1,   640,   641,    45,   643,   319,
     320,   321,   322,    51,    -1,    -1,   326,    55,    -1,    57,
      58,   493,    19,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    -1,    74,    34,    35,    -1,
     350,    -1,    -1,   190,    -1,    -1,    -1,    -1,   520,   521,
      -1,   523,    -1,    -1,    -1,    -1,   528,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,
     562,    -1,   564,   565,   566,   567,   568,   569,   408,   409,
      -1,    -1,    -1,   575,    -1,   577,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,   426,    -1,   428,    -1,
      -1,    -1,    -1,   595,    -1,    -1,   598,    -1,   600,    -1,
      -1,    -1,    -1,    -1,    -1,   607,   608,    -1,    -1,    -1,
     125,    -1,    -1,    -1,    19,   617,    -1,   619,    -1,    -1,
     622,   623,    -1,    -1,   301,    30,    31,    -1,   630,    34,
      35,   633,    -1,   635,    -1,    -1,    -1,    -1,   640,   641,
      45,   643,   319,   320,   321,   322,    51,    -1,    -1,   326,
      55,    -1,    -1,   493,    -1,    19,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    -1,    74,
      34,    35,    -1,   350,    -1,   190,    -1,    -1,    -1,    -1,
     520,   521,    -1,   523,    -1,    -1,    -1,    -1,   528,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,   562,    -1,   564,   565,   566,   567,   568,   569,
      -1,   408,   409,    -1,    -1,   575,    -1,   577,    -1,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,   426,
      -1,   428,    -1,    -1,    -1,   595,    -1,    -1,   598,    -1,
     600,    -1,    -1,    -1,    -1,    -1,    -1,   607,   608,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   617,    -1,   619,
      -1,    -1,   622,   623,    -1,    -1,   301,    -1,    -1,    -1,
     630,    -1,    -1,   633,    -1,   635,    -1,    -1,    -1,    -1,
     640,   641,    -1,   643,   319,   320,   321,   322,    -1,    -1,
      12,   326,    14,    15,    16,    17,   493,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    34,    35,    -1,   350,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   520,   521,    -1,   523,    -1,    -1,    -1,
      -1,   528,    -1,    55,    -1,    57,    -1,    -1,    -1,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,   562,    -1,   564,   565,   566,
     567,   568,   569,   408,   409,    -1,    -1,   132,   575,    -1,
     577,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,   426,    -1,   428,    -1,    -1,    -1,    -1,   595,    -1,
      -1,   598,    -1,   600,    -1,    -1,    -1,    -1,    -1,    -1,
     607,   608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     617,    -1,   619,    -1,    -1,   622,   623,    -1,    -1,    -1,
     232,    -1,    -1,   630,    -1,    -1,   633,    -1,   635,    -1,
      -1,    -1,    -1,   640,   641,    -1,   643,     3,     4,     5,
       6,     7,     8,     9,    10,   201,    -1,    -1,   493,   205,
      -1,    -1,    -1,    19,    -1,    -1,   212,    -1,    -1,    -1,
      -1,   226,    -1,   228,    30,    31,   231,    -1,    34,    35,
      -1,    -1,   237,    -1,    -1,   520,   521,    -1,   523,    45,
      -1,    -1,    -1,   528,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   319,    74,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,   564,
     565,   566,   567,   568,   569,    -1,   291,   292,    -1,    -1,
     575,    -1,   577,    -1,    -1,    -1,    -1,    -1,   350,    -1,
     305,   306,    -1,    -1,    -1,   310,    -1,   312,   313,   305,
     595,    -1,    -1,   598,    -1,   600,    -1,    -1,    -1,   324,
     325,    -1,   607,   608,   320,   321,    -1,    -1,    -1,    -1,
      -1,    -1,   617,    -1,   619,    -1,   341,   622,   623,    -1,
      -1,    -1,    -1,    -1,    -1,   630,    -1,    -1,   633,   354,
     635,    -1,   348,   358,    -1,   640,   641,    -1,   643,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,
      -1,    -1,    -1,    -1,   426,    -1,   428,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,   399,   400,    19,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,   413,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,   427,   437,    -1,    -1,    -1,   441,    -1,    -1,   444,
      -1,    55,    -1,   448,    -1,    -1,    -1,    61,   444,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    -1,
      74,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,   521,
      -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,
      -1,   496,   497,    -1,   499,    -1,   501,    -1,    -1,    -1,
     496,   497,    -1,    -1,    -1,   501,    -1,    -1,    -1,    -1,
     562,   507,   564,   509,    -1,   567,    -1,   569,    -1,   515,
     525,   526,   235,   236,    -1,   577,    -1,    -1,    -1,    -1,
      -1,    -1,   528,    -1,    -1,   540,   541,    -1,    -1,   535,
      -1,    -1,    -1,   595,   540,    -1,   598,    -1,   600,    -1,
      -1,    -1,    -1,    -1,    -1,   607,   608,    -1,   554,    -1,
     556,    -1,    -1,   559,    -1,   617,    -1,   619,    -1,   565,
     566,   623,    -1,    -1,   287,   288,   289,   290,   630,   575,
     576,   235,   236,   635,    -1,    -1,   582,    -1,   640,   641,
     586,   643,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,
      -1,   597,    -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,
     606,    -1,    -1,    -1,    -1,   611,   621,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   288,   289,   290,   633,   634,    -1,
      -1,    -1,    -1,   639,   357,    -1,    -1,   360,    -1,   362,
      -1,   364,    -1,   366,    -1,    -1,   369,   370,    -1,    -1,
      -1,    -1,    -1,    -1,   377,   378,   379,   380,    -1,    -1,
      -1,   384,   385,   386,   387,   388,    -1,    -1,   391,   392,
     393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   357,    -1,    -1,   360,    -1,   362,    -1,
     364,    -1,   366,    -1,    -1,   369,   370,    -1,    -1,    -1,
      -1,    -1,    -1,   377,   378,   379,   380,    -1,    -1,    -1,
     384,   385,   386,   387,   388,    -1,    -1,   391,   392,   393,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,   486,   487,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    57,    58,    -1,    -1,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      19,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,   486,   487,   547,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    19,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    19,   547,    -1,    -1,    51,    -1,    -1,    -1,
      55,    -1,    -1,    30,    31,    60,    -1,    34,    35,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    45,    74,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    21,    22,    23,    24,    25,    78,    79,    85,    86,
      87,    88,    89,    90,    91,   106,   107,   108,   241,   242,
     243,   244,   245,   251,   252,     0,    77,   303,    88,    87,
      90,    87,    91,   107,   243,    71,   302,   104,   302,   104,
      87,   302,   110,    61,    63,   292,   294,   292,   294,   109,
      57,   111,   288,   302,    80,   262,   111,     3,     4,     5,
       6,     7,     8,     9,    10,    18,    58,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   104,   105,   106,   108,
     112,   113,   114,   115,   120,   122,   127,   131,   132,   172,
     223,   224,   225,   226,   227,   228,   229,   230,   238,   244,
     288,   289,   302,   292,   116,   117,   118,   127,   302,    59,
     103,   290,   103,   116,   127,    95,   127,   238,   113,   289,
     121,   134,   127,   302,   172,    92,    55,   286,    62,   292,
     293,    83,   283,   290,    76,   123,   255,    60,   291,   292,
     123,   133,   127,   130,   172,   135,   288,   123,    11,    12,
      14,    15,    16,    17,    19,    20,    28,    29,    34,    35,
      64,    65,    66,    67,    68,    69,    70,    72,    74,    75,
      81,    82,    88,    93,    94,   104,   139,   140,   141,   142,
     143,   144,   146,   151,   152,   165,   166,   169,   170,   172,
     173,   174,   175,   176,   181,   183,   184,   185,   186,   188,
     189,   190,   191,   192,   194,   195,   196,   198,   200,   202,
     203,   204,   210,   211,   213,   214,   215,   216,   217,   231,
     232,   234,   235,   236,   237,   239,   240,   245,   246,   247,
     249,   250,   253,   254,   258,   264,   265,   286,   289,   292,
     295,   296,   297,   298,   299,   300,   301,   302,    56,    94,
     128,   129,   287,   117,   302,    30,    31,    45,    51,   104,
     119,   137,   139,   141,   144,   149,   150,   151,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   259,   260,   275,
     281,   286,   288,   291,   101,   104,   124,   126,   103,   135,
     123,    92,   116,   264,   265,   286,   290,   264,   265,   294,
     290,    52,   282,   283,   174,   289,   292,   292,   287,   287,
     292,   292,   287,   177,   286,   286,   286,   292,   292,    96,
     101,   149,   292,   178,   179,   149,   294,   149,   104,   181,
     172,   286,   104,   139,   142,   143,   104,   139,   149,    53,
     284,   118,   287,   293,   290,    50,    54,   280,   285,    49,
     279,    43,   273,    44,   274,    42,   272,    40,    41,   270,
     271,    36,    37,    38,    39,    73,   248,   266,   267,   268,
     269,    46,    47,    48,   276,   277,   278,   259,   260,    32,
      33,   261,   262,   263,   104,   164,   164,   164,   164,    96,
     100,   104,   119,   138,   289,   293,   125,   293,   136,   173,
     247,   249,   289,   145,   149,   287,   149,   302,   149,   149,
     149,    92,   181,   189,   207,   208,   287,   207,   287,   181,
     116,   149,   149,   176,   206,   208,   245,   292,   103,   147,
     148,   290,   103,   147,   286,   292,    94,   231,   284,   292,
     302,   292,   234,    26,    27,   218,   219,   222,   256,   257,
     149,   287,   181,   129,   155,   149,   156,   157,   158,   159,
     160,   160,    96,   100,   161,   161,   161,   161,   162,   162,
     162,   163,   163,   164,   164,   164,   287,   287,   289,   293,
     289,   293,   126,   173,   289,   289,   286,   286,   287,   293,
     291,   286,   291,   181,   182,   183,   187,   190,   193,   195,
     197,   201,   202,   203,   205,   210,   212,   235,   302,   209,
     293,   287,   181,   287,   181,   284,   292,   149,   292,   137,
     103,   148,   149,   137,   103,   145,   287,   116,   180,   149,
     286,   286,   219,   222,   286,   172,   287,   284,   164,   167,
     119,   289,   126,   289,   145,   287,   145,   287,   149,   145,
     287,    13,   233,   287,   287,   292,   292,   287,   286,   284,
     189,   181,   181,   149,   149,   292,   207,   287,   291,   287,
     116,   292,   145,   287,   149,   101,   220,   221,   245,   172,
     153,   287,   287,   287,   181,    92,   182,   207,   287,   207,
     287,   182,   206,   292,   182,   209,   207,   287,   287,   181,
     287,   199,   273,   287,   118,   221,   182,   287,   182,   287,
     182,   292,   292,   287,   181,   181,   287,   221,   172,   118,
     233,   182,   182,   292,   207,   287,   181,   292,   182,   207,
     287,   287,   182,   287,   182,   182,   182
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    84,    85,    86,    86,    86,    86,    87,    87,    88,
      89,    90,    90,    91,    91,    92,    93,    93,    93,    93,
      93,    93,    93,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    98,    98,    99,    99,   100,   100,   101,
     102,   102,   103,   103,   104,   104,   105,   106,   106,   107,
     107,   107,   107,   109,   108,   110,   108,   111,   111,   112,
     112,   113,   113,   113,   113,   114,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   121,   120,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   124,
     124,   125,   125,   126,   127,   127,   128,   128,   129,   130,
     131,   133,   132,   134,   132,   135,   135,   135,   135,   136,
     136,   136,   136,   137,   137,   137,   137,   138,   138,   139,
     139,   140,   140,   140,   140,   140,   140,   140,   141,   141,
     142,   143,   143,   144,   144,   144,   144,   144,   144,   145,
     145,   146,   146,   146,   146,   146,   146,   147,   147,   148,
     149,   150,   150,   151,   151,   152,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   156,   157,   157,   158,   158,
     159,   159,   159,   160,   160,   160,   160,   160,   160,   161,
     161,   161,   161,   162,   162,   162,   163,   163,   163,   163,
     164,   164,   164,   164,   164,   165,   165,   166,   166,   167,
     167,   167,   167,   168,   168,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   172,   173,   173,   174,   174,   174,
     175,   176,   177,   176,   178,   176,   179,   180,   176,   181,
     181,   181,   181,   181,   181,   182,   182,   182,   182,   182,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   184,   185,   186,   187,   188,   189,   189,   189,   189,
     189,   189,   189,   190,   191,   192,   193,   194,   194,   195,
     196,   197,   199,   198,   200,   200,   201,   201,   202,   203,
     204,   204,   204,   204,   204,   204,   204,   204,   205,   205,
     205,   205,   205,   205,   205,   205,   206,   206,   207,   208,
     208,   209,   209,   210,   211,   212,   213,   214,   215,   215,
     216,   217,   217,   217,   218,   218,   219,   220,   220,   221,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     1,     1,     2,     1,
       3,     2,     1,     3,     5,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     2,     1,     3,     2,     1,     2,     1,
       1,     1,     1,     0,     5,     0,     4,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     1,     3,     1,     1,     1,     0,     3,
       2,     2,     3,     2,     3,     3,     4,     3,     2,     1,
       2,     3,     2,     1,     3,     4,     3,     1,     2,     1,
       2,     0,     4,     0,     3,     4,     5,     4,     3,     3,
       4,     3,     4,     3,     2,     4,     3,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     4,     5,
       3,     4,     4,     3,     4,     5,     6,     5,     6,     1,
       3,     4,     4,     3,     3,     4,     4,     1,     2,     3,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     2,     2,     1,     2,     2,     2,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     4,     4,     3,     4,     2,     1,     1,     1,     1,
       2,     2,     0,     3,     0,     4,     0,     0,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     6,     6,     3,     5,     3,
       3,     3,     0,     8,     1,     1,     1,     1,     4,     5,
       6,     7,     4,     7,     4,     5,     8,     5,     6,     7,
       4,     7,     4,     5,     8,     5,     1,     1,     1,     1,
       2,     3,     2,     5,     3,     3,     2,     2,     3,     2,
       3,     3,     4,     3,     2,     1,     5,     2,     3,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
  case 2: /* Program: CompilationUnit endoffile  */
#line 354 "parser/lalr1_fast.y"
                              { }
#line 2696 "lalr1_fast.tab.c"
    break;

  case 3: /* CompilationUnit: PackageDeclaration ImportDeclarations ClassOrInterfaceDeclarations  */
#line 358 "parser/lalr1_fast.y"
                                                                       { }
#line 2702 "lalr1_fast.tab.c"
    break;

  case 4: /* CompilationUnit: ImportDeclarations ClassOrInterfaceDeclarations  */
#line 359 "parser/lalr1_fast.y"
                                                    { }
#line 2708 "lalr1_fast.tab.c"
    break;

  case 5: /* CompilationUnit: PackageDeclaration ClassOrInterfaceDeclarations  */
#line 360 "parser/lalr1_fast.y"
                                                    { }
#line 2714 "lalr1_fast.tab.c"
    break;

  case 6: /* CompilationUnit: ClassOrInterfaceDeclarations  */
#line 361 "parser/lalr1_fast.y"
                                 { }
#line 2720 "lalr1_fast.tab.c"
    break;

  case 7: /* ClassOrInterfaceDeclarations: ClassOrInterfaceDeclaration  */
#line 365 "parser/lalr1_fast.y"
                                { }
#line 2726 "lalr1_fast.tab.c"
    break;

  case 8: /* ClassOrInterfaceDeclarations: ClassOrInterfaceDeclarations ClassOrInterfaceDeclaration  */
#line 366 "parser/lalr1_fast.y"
                                                             { }
#line 2732 "lalr1_fast.tab.c"
    break;

  case 9: /* ClassOrInterfaceDeclaration: ClassDeclaration  */
#line 370 "parser/lalr1_fast.y"
                     { }
#line 2738 "lalr1_fast.tab.c"
    break;

  case 10: /* PackageDeclaration: Package TypeName Semicolon  */
#line 376 "parser/lalr1_fast.y"
                               { }
#line 2744 "lalr1_fast.tab.c"
    break;

  case 11: /* ImportDeclarations: ImportDeclarations ImportDeclaration  */
#line 379 "parser/lalr1_fast.y"
                                         { }
#line 2750 "lalr1_fast.tab.c"
    break;

  case 12: /* ImportDeclarations: ImportDeclaration  */
#line 380 "parser/lalr1_fast.y"
                            { }
#line 2756 "lalr1_fast.tab.c"
    break;

  case 13: /* ImportDeclaration: Import TypeName Semicolon  */
#line 384 "parser/lalr1_fast.y"
                              { }
#line 2762 "lalr1_fast.tab.c"
    break;

  case 14: /* ImportDeclaration: Import TypeName Dot Asterik Semicolon  */
#line 385 "parser/lalr1_fast.y"
                                          { }
#line 2768 "lalr1_fast.tab.c"
    break;

  case 15: /* ScopeIncrement: %empty  */
#line 389 "parser/lalr1_fast.y"
           { increase_current_level(); }
#line 2774 "lalr1_fast.tab.c"
    break;

  case 16: /* Literal: Integer_literal  */
#line 403 "parser/lalr1_fast.y"
                            { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2780 "lalr1_fast.tab.c"
    break;

  case 17: /* Literal: Fp_literal  */
#line 404 "parser/lalr1_fast.y"
                        { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2786 "lalr1_fast.tab.c"
    break;

  case 18: /* Literal: Char_literal  */
#line 405 "parser/lalr1_fast.y"
                          { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2792 "lalr1_fast.tab.c"
    break;

  case 19: /* Literal: String  */
#line 406 "parser/lalr1_fast.y"
                    { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2798 "lalr1_fast.tab.c"
    break;

  case 20: /* Literal: Text_block  */
#line 407 "parser/lalr1_fast.y"
                        { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2804 "lalr1_fast.tab.c"
    break;

  case 21: /* Literal: Boolean_literal  */
#line 408 "parser/lalr1_fast.y"
                             { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2810 "lalr1_fast.tab.c"
    break;

  case 22: /* Literal: Null_literal  */
#line 409 "parser/lalr1_fast.y"
                          { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2816 "lalr1_fast.tab.c"
    break;

  case 23: /* UnannTypeSubRoutine: UnannType  */
#line 419 "parser/lalr1_fast.y"
               { global_type = (yyvsp[0].type)->name; }
#line 2822 "lalr1_fast.tab.c"
    break;

  case 24: /* UnannType: PrimitiveType  */
#line 422 "parser/lalr1_fast.y"
                    { (yyval.type) = (yyvsp[0].type); }
#line 2828 "lalr1_fast.tab.c"
    break;

  case 25: /* UnannType: ReferenceType  */
#line 423 "parser/lalr1_fast.y"
                    { (yyval.type) = (yyvsp[0].type); }
#line 2834 "lalr1_fast.tab.c"
    break;

  case 26: /* PrimitiveType: NumericType  */
#line 427 "parser/lalr1_fast.y"
                { (yyval.type) = (yyvsp[0].type); }
#line 2840 "lalr1_fast.tab.c"
    break;

  case 27: /* PrimitiveType: Boolean  */
#line 428 "parser/lalr1_fast.y"
             { (yyval.type) = (yyvsp[0].type); }
#line 2846 "lalr1_fast.tab.c"
    break;

  case 28: /* NumericType: IntegralType  */
#line 432 "parser/lalr1_fast.y"
                 { (yyval.type) = (yyvsp[0].type); }
#line 2852 "lalr1_fast.tab.c"
    break;

  case 29: /* NumericType: FloatingPointType  */
#line 433 "parser/lalr1_fast.y"
                       { (yyval.type) = (yyvsp[0].type); }
#line 2858 "lalr1_fast.tab.c"
    break;

  case 30: /* IntegralType: Byte  */
#line 436 "parser/lalr1_fast.y"
                          { (yyval.type) = (yyvsp[0].type); }
#line 2864 "lalr1_fast.tab.c"
    break;

  case 31: /* IntegralType: Short  */
#line 437 "parser/lalr1_fast.y"
                           { (yyval.type) = (yyvsp[0].type); }
#line 2870 "lalr1_fast.tab.c"
    break;

  case 32: /* IntegralType: Int  */
#line 438 "parser/lalr1_fast.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 2876 "lalr1_fast.tab.c"
    break;

  case 33: /* IntegralType: Long  */
#line 439 "parser/lalr1_fast.y"
                          { (yyval.type) = (yyvsp[0].type); }
#line 2882 "lalr1_fast.tab.c"
    break;

  case 34: /* IntegralType: Char  */
#line 440 "parser/lalr1_fast.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 2888 "lalr1_fast.tab.c"
    break;

  case 35: /* FloatingPointType: Float  */
#line 443 "parser/lalr1_fast.y"
                            { (yyval.type) = (yyvsp[0].type); }
#line 2894 "lalr1_fast.tab.c"
    break;

  case 36: /* FloatingPointType: Double  */
#line 444 "parser/lalr1_fast.y"
                             { (yyval.type) = (yyvsp[0].type); }
#line 2900 "lalr1_fast.tab.c"
    break;

  case 37: /* ReferenceType: ClassOrInterfaceType  */
#line 452 "parser/lalr1_fast.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 2906 "lalr1_fast.tab.c"
    break;

  case 38: /* ReferenceType: ArrayType  */
#line 453 "parser/lalr1_fast.y"
              { (yyval.type) = (yyvsp[0].type); }
#line 2912 "lalr1_fast.tab.c"
    break;

  case 39: /* ClassOrInterfaceType: TypeName  */
#line 457 "parser/lalr1_fast.y"
                 {  (yyval.type) = ClassOrInterfaceType((yyvsp[0].stack_entry)); /* TypeName will not have any problem as it will not find enteries in the symbol table for name like A.B*/ }
#line 2918 "lalr1_fast.tab.c"
    break;

  case 40: /* ArrayType: PrimitiveType Dims  */
#line 464 "parser/lalr1_fast.y"
                       {    
                            (yyval.type) = get_array_type((yyvsp[-1].type), (yyvsp[0].stack_entry));
                       }
#line 2926 "lalr1_fast.tab.c"
    break;

  case 41: /* ArrayType: TypeName Dims  */
#line 467 "parser/lalr1_fast.y"
                    { 
                        (yyval.type) = get_array_type(get_type(((yyvsp[-1].stack_entry))->token), (yyvsp[0].stack_entry));
                    }
#line 2934 "lalr1_fast.tab.c"
    break;

  case 42: /* Dims: Lsquare Rsquare Dims  */
#line 476 "parser/lalr1_fast.y"
                            {  (yyval.stack_entry) = increase_dims((yyvsp[0].stack_entry));}
#line 2940 "lalr1_fast.tab.c"
    break;

  case 43: /* Dims: Lsquare Rsquare  */
#line 477 "parser/lalr1_fast.y"
                    { 
                        (yyval.stack_entry) = make_stackentry("", yylineno);
                        (yyval.stack_entry)->type = get_array_type(); 
                    }
#line 2949 "lalr1_fast.tab.c"
    break;

  case 44: /* TypeName: Identifier  */
#line 494 "parser/lalr1_fast.y"
                { 
                    (yyval.stack_entry) = make_stackentry((((yyvsp[0].id))->name).c_str(), yylineno);
                    free((yyvsp[0].id));
                }
#line 2958 "lalr1_fast.tab.c"
    break;

  case 45: /* TypeName: TypeName Dot Identifier  */
#line 498 "parser/lalr1_fast.y"
                            {
                                (yyvsp[-2].stack_entry)->token = (yyvsp[-2].stack_entry)->token + "." + (yyvsp[0].id)->name;
                                free((yyvsp[0].id));
                                (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                            }
#line 2968 "lalr1_fast.tab.c"
    break;

  case 46: /* ModifiersUnannTypeSubRoutine: Modifiers UnannType  */
#line 508 "parser/lalr1_fast.y"
                            { global_modifier = (yyvsp[-1].b_no); global_type = ((yyvsp[0].type))->name; }
#line 2974 "lalr1_fast.tab.c"
    break;

  case 47: /* Modifiers: Modifier  */
#line 512 "parser/lalr1_fast.y"
             {  
                (yyval.b_no) = set_modifier(0, (yyvsp[0].b_no));
            }
#line 2982 "lalr1_fast.tab.c"
    break;

  case 48: /* Modifiers: Modifiers Modifier  */
#line 515 "parser/lalr1_fast.y"
                        { 
                            (yyval.b_no) = set_modifier((yyvsp[-1].b_no), (yyvsp[0].b_no));
                        }
#line 2990 "lalr1_fast.tab.c"
    break;

  case 49: /* Modifier: Public  */
#line 522 "parser/lalr1_fast.y"
                { 
                    (yyval.b_no) = __PUBLIC;
                }
#line 2998 "lalr1_fast.tab.c"
    break;

  case 50: /* Modifier: Private  */
#line 525 "parser/lalr1_fast.y"
                { 
                    (yyval.b_no) = __PRIVATE;    
                }
#line 3006 "lalr1_fast.tab.c"
    break;

  case 51: /* Modifier: Static  */
#line 528 "parser/lalr1_fast.y"
                { 
                    (yyval.b_no) = __STATIC;    
                }
#line 3014 "lalr1_fast.tab.c"
    break;

  case 52: /* Modifier: Final  */
#line 531 "parser/lalr1_fast.y"
                { 
                    (yyval.b_no) = __FINAL;    
                }
#line 3022 "lalr1_fast.tab.c"
    break;

  case 53: /* $@1: %empty  */
#line 543 "parser/lalr1_fast.y"
                               { add_class((yyvsp[-2].b_no), ((yyvsp[0].id))->name);}
#line 3028 "lalr1_fast.tab.c"
    break;

  case 54: /* ClassDeclaration: Modifiers Class Identifier $@1 ClassBody  */
#line 543 "parser/lalr1_fast.y"
                                                                       { current_class = NULL; current_scope = scope_global; }
#line 3034 "lalr1_fast.tab.c"
    break;

  case 55: /* $@2: %empty  */
#line 544 "parser/lalr1_fast.y"
                     { add_class(0b0, ((yyvsp[0].id))->name);}
#line 3040 "lalr1_fast.tab.c"
    break;

  case 56: /* ClassDeclaration: Class Identifier $@2 ClassBody  */
#line 544 "parser/lalr1_fast.y"
                                                              { current_class = NULL; current_scope = scope_global;}
#line 3046 "lalr1_fast.tab.c"
    break;

  case 59: /* ClassBodyDeclarations: ClassBodyDeclarations ClassBodyDeclaration  */
#line 566 "parser/lalr1_fast.y"
                                               { }
#line 3052 "lalr1_fast.tab.c"
    break;

  case 60: /* ClassBodyDeclarations: ClassBodyDeclaration  */
#line 567 "parser/lalr1_fast.y"
                         { }
#line 3058 "lalr1_fast.tab.c"
    break;

  case 61: /* ClassBodyDeclaration: ClassMemberDeclaration  */
#line 571 "parser/lalr1_fast.y"
                           { }
#line 3064 "lalr1_fast.tab.c"
    break;

  case 62: /* ClassBodyDeclaration: ConstructorDeclaration  */
#line 572 "parser/lalr1_fast.y"
                           { }
#line 3070 "lalr1_fast.tab.c"
    break;

  case 63: /* ClassBodyDeclaration: StaticInitializer  */
#line 573 "parser/lalr1_fast.y"
                      { }
#line 3076 "lalr1_fast.tab.c"
    break;

  case 64: /* ClassBodyDeclaration: Block  */
#line 574 "parser/lalr1_fast.y"
                        { }
#line 3082 "lalr1_fast.tab.c"
    break;

  case 65: /* ClassMemberDeclaration: FieldDeclaration  */
#line 579 "parser/lalr1_fast.y"
                     { }
#line 3088 "lalr1_fast.tab.c"
    break;

  case 66: /* ClassMemberDeclaration: MethodDeclaration  */
#line 580 "parser/lalr1_fast.y"
                      { }
#line 3094 "lalr1_fast.tab.c"
    break;

  case 67: /* ClassMemberDeclaration: ClassDeclaration  */
#line 581 "parser/lalr1_fast.y"
                      { }
#line 3100 "lalr1_fast.tab.c"
    break;

  case 68: /* FieldDeclaration: ModifiersUnannTypeSubRoutine VariableDeclaratorList Semicolon  */
#line 586 "parser/lalr1_fast.y"
                                                                  { global_modifier = 0b0; global_type =""; }
#line 3106 "lalr1_fast.tab.c"
    break;

  case 69: /* FieldDeclaration: UnannTypeSubRoutine VariableDeclaratorList Semicolon  */
#line 587 "parser/lalr1_fast.y"
                                                         { global_type =""; }
#line 3112 "lalr1_fast.tab.c"
    break;

  case 70: /* VariableDeclaratorList: VariableDeclaratorList Comma VariableDeclarator  */
#line 591 "parser/lalr1_fast.y"
                                                    {}
#line 3118 "lalr1_fast.tab.c"
    break;

  case 71: /* VariableDeclaratorList: VariableDeclarator  */
#line 592 "parser/lalr1_fast.y"
                       { }
#line 3124 "lalr1_fast.tab.c"
    break;

  case 72: /* VariableDeclarator: VariableDeclaratorId Assign VariableInitializer  */
#line 597 "parser/lalr1_fast.y"
                                                    {    
                                                        if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) VariableDeclarator((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry), 1);
                                                    }
#line 3132 "lalr1_fast.tab.c"
    break;

  case 73: /* VariableDeclarator: VariableDeclaratorId  */
#line 600 "parser/lalr1_fast.y"
                         { 
                            if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) VariableDeclarator((yyvsp[0].stack_entry), NULL, 2);
                         }
#line 3140 "lalr1_fast.tab.c"
    break;

  case 74: /* VariableDeclaratorId: VariableDeclaratorId Lsquare Rsquare  */
#line 606 "parser/lalr1_fast.y"
                                          {     
                                                if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                                                    (yyval.stack_entry) = increase_dims((yyvsp[-2].stack_entry));
                                                }                                               
                                          }
#line 3150 "lalr1_fast.tab.c"
    break;

  case 75: /* VariableDeclaratorId: Identifier  */
#line 611 "parser/lalr1_fast.y"
                {    
                    if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                        (yyval.stack_entry) = make_stackentry((((yyvsp[0].id))->name).c_str(), global_type, yylineno);
                        free((yyvsp[0].id));
                    }
                }
#line 3161 "lalr1_fast.tab.c"
    break;

  case 76: /* VariableInitializer: Expression  */
#line 620 "parser/lalr1_fast.y"
               { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3167 "lalr1_fast.tab.c"
    break;

  case 77: /* VariableInitializer: ArrayInitializer  */
#line 621 "parser/lalr1_fast.y"
                     { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3173 "lalr1_fast.tab.c"
    break;

  case 78: /* $@3: %empty  */
#line 628 "parser/lalr1_fast.y"
                {
                    add_function(((yyvsp[0].stack_entry))->token, ((yyvsp[0].stack_entry))->argument_type, ((yyvsp[0].stack_entry))->type, ((yyvsp[0].stack_entry))->modifier);   
                }
#line 3181 "lalr1_fast.tab.c"
    break;

  case 80: /* MethodHeader: ModifiersUnannTypeSubRoutine Declarator  */
#line 634 "parser/lalr1_fast.y"
                                            {
                                            struct stackentry* entry = make_stackentry( (((yyvsp[0].stack_entry))->token).c_str(), global_type, yylineno);
                                            entry->modifier = global_modifier; 
                                            entry->argument_type = ((yyvsp[0].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry; 
                                            global_modifier = 0b0; global_type ="";
                                        }
#line 3193 "lalr1_fast.tab.c"
    break;

  case 81: /* MethodHeader: UnannTypeSubRoutine Declarator  */
#line 641 "parser/lalr1_fast.y"
                                        { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[0].stack_entry))->token).c_str(), global_type, yylineno); 
                                            entry->argument_type = ((yyvsp[0].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry;
                                            global_type = "";
                                        }
#line 3204 "lalr1_fast.tab.c"
    break;

  case 82: /* MethodHeader: Modifiers Void Declarator  */
#line 647 "parser/lalr1_fast.y"
                                        { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[0].stack_entry))->token).c_str(), __VOID, yylineno);
                                            entry->modifier = (yyvsp[-2].b_no); 
                                            entry->argument_type = ((yyvsp[0].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry;
                                        }
#line 3215 "lalr1_fast.tab.c"
    break;

  case 83: /* MethodHeader: Void Declarator  */
#line 653 "parser/lalr1_fast.y"
                                        { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[0].stack_entry))->token).c_str(), __VOID, yylineno);
                                            entry->argument_type = ((yyvsp[0].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry;
                                        }
#line 3225 "lalr1_fast.tab.c"
    break;

  case 84: /* MethodHeader: ModifiersUnannTypeSubRoutine Declarator Throws  */
#line 658 "parser/lalr1_fast.y"
                                                   { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[-1].stack_entry))->token).c_str(), global_type, yylineno);
                                            entry->modifier = global_modifier; 
                                            entry->argument_type = ((yyvsp[-1].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry;
                                            global_modifier = 0b0; global_type ="";
                                            // Throws ???????????????????????????????????????
                                          }
#line 3238 "lalr1_fast.tab.c"
    break;

  case 85: /* MethodHeader: UnannTypeSubRoutine Declarator Throws  */
#line 666 "parser/lalr1_fast.y"
                                                    { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[-1].stack_entry))->token).c_str(), global_type, yylineno);  
                                            entry->argument_type = ((yyvsp[-1].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry;
                                            global_type = "";
                                            // Throws ???????????????????????????????????????
                                          }
#line 3250 "lalr1_fast.tab.c"
    break;

  case 86: /* MethodHeader: Modifiers Void Declarator Throws  */
#line 673 "parser/lalr1_fast.y"
                                          { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[-1].stack_entry))->token).c_str(), __VOID, yylineno);
                                            entry->modifier = (yyvsp[-3].b_no); 
                                            entry->argument_type = ((yyvsp[-1].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry;
                                            // Throws ???????????????????????????????????????
                                          }
#line 3262 "lalr1_fast.tab.c"
    break;

  case 87: /* MethodHeader: Void Declarator Throws  */
#line 680 "parser/lalr1_fast.y"
                                          { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[-1].stack_entry))->token).c_str(), __VOID, yylineno);
                                            entry->argument_type = ((yyvsp[-1].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry;
                                            // Throws ???????????????????????????????????????
                                          }
#line 3273 "lalr1_fast.tab.c"
    break;

  case 88: /* Throws: throws_ ExceptionTypeList  */
#line 689 "parser/lalr1_fast.y"
                                          { }
#line 3279 "lalr1_fast.tab.c"
    break;

  case 89: /* ExceptionTypeList: ExceptionType  */
#line 692 "parser/lalr1_fast.y"
                                          { }
#line 3285 "lalr1_fast.tab.c"
    break;

  case 90: /* ExceptionTypeList: ExceptionType CommaExceptionTypes  */
#line 693 "parser/lalr1_fast.y"
                                          { }
#line 3291 "lalr1_fast.tab.c"
    break;

  case 91: /* CommaExceptionTypes: CommaExceptionTypes Comma ExceptionType  */
#line 696 "parser/lalr1_fast.y"
                                             { }
#line 3297 "lalr1_fast.tab.c"
    break;

  case 92: /* CommaExceptionTypes: Comma ExceptionType  */
#line 697 "parser/lalr1_fast.y"
                                             { }
#line 3303 "lalr1_fast.tab.c"
    break;

  case 93: /* ExceptionType: ClassOrInterfaceType  */
#line 700 "parser/lalr1_fast.y"
                                            { }
#line 3309 "lalr1_fast.tab.c"
    break;

  case 94: /* Declarator: Identifier Lparen Rparen  */
#line 707 "parser/lalr1_fast.y"
                                                { (yyval.stack_entry) = make_stackentry(((yyvsp[-2].id)->name).c_str(), yylineno); free((yyvsp[-2].id)); }
#line 3315 "lalr1_fast.tab.c"
    break;

  case 95: /* Declarator: Identifier Lparen FormalParameterList Rparen  */
#line 708 "parser/lalr1_fast.y"
                                                 { (yyvsp[-1].stack_entry)->token =((yyvsp[-3].id))->name; (yyval.stack_entry) = (yyvsp[-1].stack_entry); }
#line 3321 "lalr1_fast.tab.c"
    break;

  case 96: /* FormalParameterList: FormalParameterList Comma FormalParameter  */
#line 712 "parser/lalr1_fast.y"
                                              {
                                                (yyvsp[-2].stack_entry)->argument_type = ((yyvsp[-2].stack_entry))->argument_type + "," + ((yyvsp[0].stack_entry))->argument_type;
                                                (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                free((yyvsp[0].stack_entry));
                                             }
#line 3331 "lalr1_fast.tab.c"
    break;

  case 97: /* FormalParameterList: FormalParameter  */
#line 717 "parser/lalr1_fast.y"
                    {  (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3337 "lalr1_fast.tab.c"
    break;

  case 98: /* FormalParameter: UnannTypeSubRoutine VariableDeclaratorId  */
#line 721 "parser/lalr1_fast.y"
                                             {
                                                (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                global_type = "";
                                                if (pass_no == 2 && current_scope == scope_class)
                                                    add_variable((yyvsp[0].stack_entry)->token, 0b0, (yyvsp[0].stack_entry)->type, true);
                                            }
#line 3348 "lalr1_fast.tab.c"
    break;

  case 99: /* MethodBody: Block  */
#line 730 "parser/lalr1_fast.y"
          { }
#line 3354 "lalr1_fast.tab.c"
    break;

  case 100: /* StaticInitializer: Static Block  */
#line 734 "parser/lalr1_fast.y"
                 { }
#line 3360 "lalr1_fast.tab.c"
    break;

  case 101: /* $@4: %empty  */
#line 738 "parser/lalr1_fast.y"
                         { add_constructor(((yyvsp[0].stack_entry))->token, ((yyvsp[0].stack_entry))->argument_type, (yyvsp[-1].b_no)); }
#line 3366 "lalr1_fast.tab.c"
    break;

  case 102: /* ConstructorDeclaration: Modifiers Declarator $@4 ConstructorBody  */
#line 738 "parser/lalr1_fast.y"
                                                                                                    {}
#line 3372 "lalr1_fast.tab.c"
    break;

  case 103: /* $@5: %empty  */
#line 739 "parser/lalr1_fast.y"
               { add_constructor(((yyvsp[0].stack_entry))->token, ((yyvsp[0].stack_entry))->argument_type, (int8_t) 0); }
#line 3378 "lalr1_fast.tab.c"
    break;

  case 104: /* ConstructorDeclaration: Declarator $@5 ConstructorBody  */
#line 739 "parser/lalr1_fast.y"
                                                                                                  {}
#line 3384 "lalr1_fast.tab.c"
    break;

  case 105: /* ConstructorBody: Lcurly ScopeIncrement BlockStatements Rcurly  */
#line 753 "parser/lalr1_fast.y"
                                                 { if(pass_no == 2) { clear_current_scope(); } }
#line 3390 "lalr1_fast.tab.c"
    break;

  case 106: /* ConstructorBody: Lcurly ScopeIncrement ExplicitConstructorInvocation BlockStatements Rcurly  */
#line 754 "parser/lalr1_fast.y"
                                                                               { if(pass_no == 2) { clear_current_scope();} }
#line 3396 "lalr1_fast.tab.c"
    break;

  case 107: /* ConstructorBody: Lcurly ScopeIncrement ExplicitConstructorInvocation Rcurly  */
#line 755 "parser/lalr1_fast.y"
                                                               { if(pass_no == 2) { clear_current_scope(); } }
#line 3402 "lalr1_fast.tab.c"
    break;

  case 108: /* ConstructorBody: Lcurly ScopeIncrement Rcurly  */
#line 756 "parser/lalr1_fast.y"
                                 { if(pass_no == 2) { clear_current_scope(); } }
#line 3408 "lalr1_fast.tab.c"
    break;

  case 109: /* ExplicitConstructorInvocation: This Lparen Rparen  */
#line 760 "parser/lalr1_fast.y"
                        {
                            // This is the default constructor of a class, hence always exists, no need to check anything
                        }
#line 3416 "lalr1_fast.tab.c"
    break;

  case 110: /* ExplicitConstructorInvocation: This Lparen ArgumentList Rparen  */
#line 763 "parser/lalr1_fast.y"
                                    {
                                        // Check if any constructor exists with the same argument type
                                        if(pass_no == 2){
                                            if(is_null(check_function_in_class( current_class->name, ((yyvsp[-1].stack_entry))->argument_type, CONSTRUCTOR))){
                                                cerr << "Line No: " <<  yylineno  << "No such constructor present in class\n";
                                                exit(-1);
                                            }
                                        }
                                    }
#line 3430 "lalr1_fast.tab.c"
    break;

  case 111: /* ExplicitConstructorInvocation: super_ Lparen Rparen  */
#line 772 "parser/lalr1_fast.y"
                         { }
#line 3436 "lalr1_fast.tab.c"
    break;

  case 112: /* ExplicitConstructorInvocation: super_ Lparen ArgumentList Rparen  */
#line 773 "parser/lalr1_fast.y"
                                      { }
#line 3442 "lalr1_fast.tab.c"
    break;

  case 113: /* ArrayInitializer: Lcurly VariableInitializerList Rcurly  */
#line 778 "parser/lalr1_fast.y"
                                          { 
                                            if(pass_no == 2) {
                                                if ((yyvsp[-1].stack_entry)->type->is_pointer()) {
                                                    (yyval.stack_entry) = increase_dims((yyvsp[-1].stack_entry));
                                                } else {
                                                    (yyval.stack_entry)->type = get_array_type();
                                                    (yyval.stack_entry) = assign_arr_dim((yyvsp[-1].stack_entry)->type, (yyval.stack_entry));
                                                }
                                            }
                                          }
#line 3457 "lalr1_fast.tab.c"
    break;

  case 114: /* ArrayInitializer: Lcurly Rcurly  */
#line 788 "parser/lalr1_fast.y"
                  { /*empty array*/
                    if(pass_no == 2){ 
                        (yyval.stack_entry) = make_stackentry("", yylineno); 
                        (yyval.stack_entry)->type = get_array_type();
                    }
                 }
#line 3468 "lalr1_fast.tab.c"
    break;

  case 115: /* ArrayInitializer: Lcurly VariableInitializerList Comma Rcurly  */
#line 794 "parser/lalr1_fast.y"
                                                { 
                                                    if(pass_no == 2) {
                                                        (yyval.stack_entry) = (yyvsp[-2].stack_entry); 
                                                        if ((yyvsp[-2].stack_entry)->type->is_pointer()) {
                                                            (yyval.stack_entry) = increase_dims((yyvsp[-2].stack_entry));
                                                        } else {
                                                            (yyval.stack_entry)->type = get_array_type();
                                                            (yyval.stack_entry) = assign_arr_dim((yyvsp[-2].stack_entry)->type, (yyval.stack_entry));
                                                        }
                                                    }
                                                }
#line 3484 "lalr1_fast.tab.c"
    break;

  case 116: /* ArrayInitializer: Lcurly Comma Rcurly  */
#line 805 "parser/lalr1_fast.y"
                        {   
                            if(pass_no == 2){
                                (yyval.stack_entry) = make_stackentry("", yylineno);
                                (yyval.stack_entry)->type = get_array_type();
                            }
                        }
#line 3495 "lalr1_fast.tab.c"
    break;

  case 117: /* VariableInitializerList: VariableInitializerList Comma VariableInitializer  */
#line 814 "parser/lalr1_fast.y"
                                                      {     
                                                            if(pass_no == 2){
                                                                if(check_return_type(((yyvsp[-2].stack_entry))->type,((yyvsp[0].stack_entry))->type)){
                                                                    (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                                } else if(check_return_type(((yyvsp[0].stack_entry))->type,((yyvsp[-2].stack_entry))->type)) {
                                                                    (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                                }
                                                            }
                                                      }
#line 3509 "lalr1_fast.tab.c"
    break;

  case 118: /* VariableInitializerList: VariableInitializer  */
#line 823 "parser/lalr1_fast.y"
                        { if(pass_no ==2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3515 "lalr1_fast.tab.c"
    break;

  case 119: /* Primary: PrimaryNoNewArray  */
#line 862 "parser/lalr1_fast.y"
                              { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3521 "lalr1_fast.tab.c"
    break;

  case 120: /* Primary: ArrayCreationExpression  */
#line 863 "parser/lalr1_fast.y"
                                    { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3527 "lalr1_fast.tab.c"
    break;

  case 121: /* PrimaryNoNewArray: Literal  */
#line 867 "parser/lalr1_fast.y"
                            { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3533 "lalr1_fast.tab.c"
    break;

  case 122: /* PrimaryNoNewArray: This  */
#line 868 "parser/lalr1_fast.y"
                         { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3539 "lalr1_fast.tab.c"
    break;

  case 123: /* PrimaryNoNewArray: Lparen Expression Rparen  */
#line 869 "parser/lalr1_fast.y"
                                             { (yyval.stack_entry) = (yyvsp[-1].stack_entry); }
#line 3545 "lalr1_fast.tab.c"
    break;

  case 124: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 870 "parser/lalr1_fast.y"
                                                    { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3551 "lalr1_fast.tab.c"
    break;

  case 125: /* PrimaryNoNewArray: FieldAccess  */
#line 871 "parser/lalr1_fast.y"
                                { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3557 "lalr1_fast.tab.c"
    break;

  case 126: /* PrimaryNoNewArray: ArrayAccess  */
#line 872 "parser/lalr1_fast.y"
                                { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3563 "lalr1_fast.tab.c"
    break;

  case 127: /* PrimaryNoNewArray: MethodInvocation  */
#line 873 "parser/lalr1_fast.y"
                                     { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3569 "lalr1_fast.tab.c"
    break;

  case 128: /* ClassInstanceCreationExpression: New ClassOrInterfaceType Lparen Rparen  */
#line 877 "parser/lalr1_fast.y"
                                            {
                                                if(pass_no == 2){
                                                    if(is_null(check_function_in_class(((yyvsp[-2].type))->name, "", CONSTRUCTOR))) {
                                                        cerr << "Line No: " <<  yylineno << "Unknown constructor used"<<endl;
                                                        exit(1);
                                                    }
                                                    (yyval.stack_entry) = make_stackentry("", ((yyvsp[-2].type))->name, yylineno);
                                                } 
                                            }
#line 3583 "lalr1_fast.tab.c"
    break;

  case 129: /* ClassInstanceCreationExpression: New ClassOrInterfaceType Lparen ArgumentList Rparen  */
#line 886 "parser/lalr1_fast.y"
                                                        {   
                                                            if(pass_no == 2){
                                                                if(is_null(check_function_in_class(((yyvsp[-3].type))->name, ((yyvsp[-1].stack_entry))->argument_type, CONSTRUCTOR))){
                                                                    cerr << "Line No: " <<  yylineno <<"Unknown constructor used"<<endl;
                                                                    exit(1);
                                                                }

                                                                (yyval.stack_entry) = make_stackentry("", ((yyvsp[-3].type))->name, yylineno);
                                                            }
                                                        }
#line 3598 "lalr1_fast.tab.c"
    break;

  case 130: /* FieldAccess: Primary Dot Identifier  */
#line 898 "parser/lalr1_fast.y"
                                        {   
                                            if(pass_no == 2 ){
                                                (yyval.stack_entry) = find_variable_in_class((yyvsp[0].id)->name, true);
                                                free((yyvsp[0].id));
                                            }
                                        }
#line 3609 "lalr1_fast.tab.c"
    break;

  case 131: /* ArrayAccess: TypeName Lsquare Expression Rsquare  */
#line 908 "parser/lalr1_fast.y"
                                                    {   
                                                        if(pass_no == 2 ){
                                                            if( !(((yyvsp[-1].stack_entry))->type->is_integral)){
                                                                cerr << "Line No: " <<  yylineno <<"Array index must be integer"<<endl;
                                                                exit(-1);
                                                            }
                                                            (yyvsp[-3].stack_entry) = find_variable_in_class(((yyvsp[-3].stack_entry))->token, false);                

                                                            // string id = ($1)->type;
                                                            Type *t = (yyvsp[-3].stack_entry)->type;
                                                            if(!t->is_pointer()){
                                                                cerr << "Line No: " <<  yylineno <<"Type of variable must be array type"<<endl;
                                                                exit(1);
                                                            }
                                                            t->arr_dim--;
                                                            free((yyvsp[-1].stack_entry));
                                                            (yyval.stack_entry) = (yyvsp[-3].stack_entry); 
                                                        }
                                                    }
#line 3633 "lalr1_fast.tab.c"
    break;

  case 132: /* ArrayAccess: PrimaryNoNewArray Lsquare Expression Rsquare  */
#line 927 "parser/lalr1_fast.y"
                                                                {   
                                                        if(pass_no == 2 ){
                                                            if( !(((yyvsp[-1].stack_entry))->type->is_integral)){
                                                                cerr << "Line No: " <<  yylineno <<"Array index must be integer"<<endl;
                                                                exit(-1);
                                                            }
                                                            (yyvsp[-3].stack_entry) = find_variable_in_class(((yyvsp[-3].stack_entry))->token, false);                

                                                            // string id = ($1)->type;
                                                            Type *t = (yyvsp[-3].stack_entry)->type;
                                                            if(!t->is_pointer()){
                                                                cerr << "Line No: " <<  yylineno <<"Type of variable must be array type"<<endl;
                                                                exit(1);
                                                            }
                                                            t->arr_dim--;
                                                            free((yyvsp[-1].stack_entry));
                                                            (yyval.stack_entry) = (yyvsp[-3].stack_entry); 
                                                        }
                                                    }
#line 3657 "lalr1_fast.tab.c"
    break;

  case 133: /* MethodInvocation: TypeName Lparen Rparen  */
#line 949 "parser/lalr1_fast.y"
                                           {    
                                                if(pass_no == 2 ){
                                                    Type* return_type = check_function_in_class(((yyvsp[-2].stack_entry))->token, "", FUNCTION);
                                                    if(return_type == NULL){
                                                        cerr << "Line No: " <<  yylineno  << "Undeclared function called\n";
                                                        exit(-1);
                                                    }
                                                    (yyval.stack_entry) = make_stackentry("", yylineno); 
                                                    (yyval.stack_entry)->type = return_type;
                                                }
                                            }
#line 3673 "lalr1_fast.tab.c"
    break;

  case 134: /* MethodInvocation: TypeName Lparen ArgumentList Rparen  */
#line 960 "parser/lalr1_fast.y"
                                                        {   
                                                            if(pass_no == 2 ){
                                                                Type* return_type = check_function_in_class(((yyvsp[-3].stack_entry))->token, ((yyvsp[-1].stack_entry))->argument_type, FUNCTION);
                                                                if(return_type == NULL){
                                                                    cerr << "Line No: " <<  yylineno  << "Undeclared function called\n";
                                                                    exit(-1);
                                                                }
                                                                (yyval.stack_entry) = make_stackentry("", yylineno); 
                                                                (yyval.stack_entry)->type = return_type;
                                                            }
                                                        }
#line 3689 "lalr1_fast.tab.c"
    break;

  case 135: /* MethodInvocation: Primary Dot Identifier Lparen Rparen  */
#line 971 "parser/lalr1_fast.y"
                                                         { }
#line 3695 "lalr1_fast.tab.c"
    break;

  case 136: /* MethodInvocation: Primary Dot Identifier Lparen ArgumentList Rparen  */
#line 972 "parser/lalr1_fast.y"
                                                                      { }
#line 3701 "lalr1_fast.tab.c"
    break;

  case 137: /* MethodInvocation: super_ Dot Identifier Lparen Rparen  */
#line 973 "parser/lalr1_fast.y"
                                                        { }
#line 3707 "lalr1_fast.tab.c"
    break;

  case 138: /* MethodInvocation: super_ Dot Identifier Lparen ArgumentList Rparen  */
#line 974 "parser/lalr1_fast.y"
                                                                     { }
#line 3713 "lalr1_fast.tab.c"
    break;

  case 139: /* ArgumentList: Expression  */
#line 981 "parser/lalr1_fast.y"
                                { 
                                    if(pass_no == 2 ){
                                        struct stackentry* entry = make_stackentry("", yylineno); 
                                        entry->argument_type = ((yyvsp[0].stack_entry))->type->name; 
                                        (yyval.stack_entry) = entry; 
                                    }
                                }
#line 3725 "lalr1_fast.tab.c"
    break;

  case 140: /* ArgumentList: ArgumentList Comma Expression  */
#line 988 "parser/lalr1_fast.y"
                                                  { 
                                                    if(pass_no == 2 ){      
                                                        struct stackentry* entry = make_stackentry("", yylineno); 
                                                        entry->argument_type = ((yyvsp[-2].stack_entry))->argument_type + "," + ((yyvsp[-1].stack_entry))->type->name; 
                                                        (yyval.stack_entry) = entry; 
                                                    }
                                                  }
#line 3737 "lalr1_fast.tab.c"
    break;

  case 141: /* ArrayCreationExpression: New PrimitiveType DimExprs Dims  */
#line 998 "parser/lalr1_fast.y"
                                                                    {  if(pass_no == 2 ){  (yyval.stack_entry) = assign_arr_dim((yyvsp[-2].type), (yyvsp[-1].stack_entry), (yyvsp[0].stack_entry)); } }
#line 3743 "lalr1_fast.tab.c"
    break;

  case 142: /* ArrayCreationExpression: New ClassOrInterfaceType DimExprs Dims  */
#line 999 "parser/lalr1_fast.y"
                                                                    {  if(pass_no == 2 ){  (yyval.stack_entry) = assign_arr_dim((yyvsp[-2].type), (yyvsp[-1].stack_entry), (yyvsp[0].stack_entry)); } }
#line 3749 "lalr1_fast.tab.c"
    break;

  case 143: /* ArrayCreationExpression: New PrimitiveType DimExprs  */
#line 1000 "parser/lalr1_fast.y"
                                                                    {  if(pass_no == 2 ){  (yyval.stack_entry) = assign_arr_dim((yyvsp[-1].type), (yyvsp[0].stack_entry)); } }
#line 3755 "lalr1_fast.tab.c"
    break;

  case 144: /* ArrayCreationExpression: New ClassOrInterfaceType DimExprs  */
#line 1001 "parser/lalr1_fast.y"
                                                                    {  if(pass_no == 2 ){  (yyval.stack_entry) = assign_arr_dim((yyvsp[-1].type), (yyvsp[0].stack_entry)); } }
#line 3761 "lalr1_fast.tab.c"
    break;

  case 145: /* ArrayCreationExpression: New PrimitiveType Dims ArrayInitializer  */
#line 1002 "parser/lalr1_fast.y"
                                                                    {  if(pass_no == 2 ){  (yyval.stack_entry) = assign_arr_dim((yyvsp[-2].type), (yyvsp[-1].stack_entry)); } }
#line 3767 "lalr1_fast.tab.c"
    break;

  case 146: /* ArrayCreationExpression: New ClassOrInterfaceType Dims ArrayInitializer  */
#line 1003 "parser/lalr1_fast.y"
                                                                           {  if(pass_no == 2 ){  (yyval.stack_entry) = assign_arr_dim((yyvsp[-2].type), (yyvsp[-1].stack_entry)); } }
#line 3773 "lalr1_fast.tab.c"
    break;

  case 147: /* DimExprs: DimExpr  */
#line 1009 "parser/lalr1_fast.y"
                     { if(pass_no == 2) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3779 "lalr1_fast.tab.c"
    break;

  case 148: /* DimExprs: DimExprs DimExpr  */
#line 1010 "parser/lalr1_fast.y"
                             {  if(pass_no == 2 ){  (yyval.stack_entry) = assign_arr_dim((yyvsp[-1].stack_entry), (yyvsp[0].stack_entry));} }
#line 3785 "lalr1_fast.tab.c"
    break;

  case 149: /* DimExpr: Lsquare Expression Rsquare  */
#line 1014 "parser/lalr1_fast.y"
                                       {    
                                            if(pass_no == 2 ){  
                                                if(!check_if_numeric_type(((yyvsp[-1].stack_entry))->type)) {
                                                    cerr << "Line No: " << yylineno << "Array dimension must be integer\n";
                                                    exit(-1);
                                                }

                                                if(!(((yyvsp[-1].stack_entry))->type->is_integral)) {
                                                    cerr << "Line No: " << yylineno << "Array dimension must be integer\n";
                                                    exit(-1);
                                                }

                                                (yyval.stack_entry) = make_stackentry("", yylineno);
                                                (yyval.stack_entry)->type = get_array_type();
                                            }
                                        }
#line 3806 "lalr1_fast.tab.c"
    break;

  case 150: /* Expression: AssignmentExpression  */
#line 1034 "parser/lalr1_fast.y"
                                  { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3812 "lalr1_fast.tab.c"
    break;

  case 151: /* AssignmentExpression: ConditionalExpression  */
#line 1037 "parser/lalr1_fast.y"
                          { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3818 "lalr1_fast.tab.c"
    break;

  case 152: /* AssignmentExpression: Assignment  */
#line 1038 "parser/lalr1_fast.y"
               { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3824 "lalr1_fast.tab.c"
    break;

  case 153: /* Assignment: LeftHandSide AssignmentOperator Expression  */
#line 1042 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        if(!check_return_type(((yyvsp[-2].stack_entry))->type, ((yyvsp[0].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "incompatible types: "<< ((yyvsp[-2].stack_entry))->type << "cannot be converted to " << ((yyvsp[0].stack_entry))->type <<"\n";
                                                            exit(-1);
                                                        }

                                                        (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                    }
                                                }
#line 3839 "lalr1_fast.tab.c"
    break;

  case 154: /* Assignment: LeftHandSide Assign Expression  */
#line 1052 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        if(!check_return_type(((yyvsp[-2].stack_entry))->type, ((yyvsp[0].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "incompatible types: "<< ((yyvsp[-2].stack_entry))->type << "cannot be converted to " << ((yyvsp[0].stack_entry))->type <<"\n";
                                                            exit(-1);
                                                        }

                                                        (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                    }
                                                }
#line 3854 "lalr1_fast.tab.c"
    break;

  case 155: /* LeftHandSide: TypeName  */
#line 1065 "parser/lalr1_fast.y"
             {  
                if(pass_no == 2 ){  
                    // struct stackentry* entry = find_variable_in_class(symmbol_table_pass2[current_class], ($1)->token);
                    // entry->variable_init_status = __INITIALIZED;
                    // $$ = entry;
                    
                }
            }
#line 3867 "lalr1_fast.tab.c"
    break;

  case 156: /* LeftHandSide: FieldAccess  */
#line 1073 "parser/lalr1_fast.y"
                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3873 "lalr1_fast.tab.c"
    break;

  case 157: /* LeftHandSide: ArrayAccess  */
#line 1074 "parser/lalr1_fast.y"
                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3879 "lalr1_fast.tab.c"
    break;

  case 158: /* ConditionalExpression: ConditionalOrExpression  */
#line 1077 "parser/lalr1_fast.y"
                                                { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3885 "lalr1_fast.tab.c"
    break;

  case 159: /* ConditionalExpression: ConditionalOrExpression Qm Expression Colon ConditionalExpression  */
#line 1078 "parser/lalr1_fast.y"
                                                                                      {     
                                                                                            if(pass_no == 2 ){
                                                                                                if(((yyvsp[-4].stack_entry))->type != defined_types[__BOOLEAN]){
                                                                                                    cerr << "Line No: " <<  yylineno  << "incompatible types: "<< ((yyvsp[-4].stack_entry))->type << "cannot be converted to boolean\n";
                                                                                                    exit(-1);
                                                                                                }

                                                                                                if((((yyvsp[-2].stack_entry))->type == defined_types[__BOOLEAN]) && (((yyvsp[0].stack_entry))->type == defined_types[__BOOLEAN])) {
                                                                                                    (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                                                                } else if (((((yyvsp[-2].stack_entry))->type == defined_types[__BOOLEAN]) && (((yyvsp[0].stack_entry))->type != defined_types[__BOOLEAN])) || ((((yyvsp[-2].stack_entry))->type != defined_types[__BOOLEAN]) && (((yyvsp[0].stack_entry))->type == defined_types[__BOOLEAN]))) {
                                                                                                    cerr << "Line No: " <<  yylineno  << "Non intersectionable type: " << ((yyvsp[-2].stack_entry))->type << " and " << ((yyvsp[0].stack_entry))->type << "\n";
                                                                                                    exit(-1);
                                                                                                } else {
                                                                                                    if(check_return_type(((yyvsp[-2].stack_entry))->type, ((yyvsp[0].stack_entry))->type)) 
                                                                                                        (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                                                                    else
                                                                                                        (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                                                                }
                                                                                            }
                                                                                      }
#line 3910 "lalr1_fast.tab.c"
    break;

  case 160: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 1100 "parser/lalr1_fast.y"
                                                     { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3916 "lalr1_fast.tab.c"
    break;

  case 161: /* ConditionalOrExpression: ConditionalOrExpression Or ConditionalAndExpression  */
#line 1101 "parser/lalr1_fast.y"
                                                                        {   
                                                                            if(pass_no == 2 ) {  
                                                                                (yyval.stack_entry) = ConditionalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                        }
#line 3926 "lalr1_fast.tab.c"
    break;

  case 162: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 1108 "parser/lalr1_fast.y"
                                                  { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3932 "lalr1_fast.tab.c"
    break;

  case 163: /* ConditionalAndExpression: ConditionalAndExpression And InclusiveOrExpression  */
#line 1109 "parser/lalr1_fast.y"
                                                                        {   
                                                                            if(pass_no == 2 ) {
                                                                                (yyval.stack_entry) = ConditionalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                        }
#line 3942 "lalr1_fast.tab.c"
    break;

  case 164: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 1116 "parser/lalr1_fast.y"
                                              { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3948 "lalr1_fast.tab.c"
    break;

  case 165: /* InclusiveOrExpression: InclusiveOrExpression Bitwise_or ExclusiveOrExpression  */
#line 1117 "parser/lalr1_fast.y"
                                                                            {   
                                                                                if(pass_no == 2 ){  
                                                                                    (yyval.stack_entry) = BitwiseExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                }
                                                                            }
#line 3958 "lalr1_fast.tab.c"
    break;

  case 166: /* ExclusiveOrExpression: AndExpression  */
#line 1124 "parser/lalr1_fast.y"
                                        { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3964 "lalr1_fast.tab.c"
    break;

  case 167: /* ExclusiveOrExpression: ExclusiveOrExpression Bitwise_xor AndExpression  */
#line 1125 "parser/lalr1_fast.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = BitwiseExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                        }
#line 3974 "lalr1_fast.tab.c"
    break;

  case 168: /* AndExpression: EqualityExpression  */
#line 1132 "parser/lalr1_fast.y"
                                    { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3980 "lalr1_fast.tab.c"
    break;

  case 169: /* AndExpression: AndExpression Bitwise_and EqualityExpression  */
#line 1133 "parser/lalr1_fast.y"
                                                                    {       
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = BitwiseExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                        }
#line 3990 "lalr1_fast.tab.c"
    break;

  case 170: /* EqualityExpression: RelationalExpression  */
#line 1140 "parser/lalr1_fast.y"
                                         { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3996 "lalr1_fast.tab.c"
    break;

  case 171: /* EqualityExpression: EqualityExpression Deq RelationalExpression  */
#line 1141 "parser/lalr1_fast.y"
                                                                    {   
                                                                        if(pass_no == 2 ){  
                                                                            EqualityExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                        }
                                                                    }
#line 4006 "lalr1_fast.tab.c"
    break;

  case 172: /* EqualityExpression: EqualityExpression Neq RelationalExpression  */
#line 1146 "parser/lalr1_fast.y"
                                                                    {   
                                                                        if(pass_no == 2 ){  
                                                                            EqualityExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                        }
                                                                    }
#line 4016 "lalr1_fast.tab.c"
    break;

  case 173: /* RelationalExpression: ShiftExpression  */
#line 1153 "parser/lalr1_fast.y"
                                        { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4022 "lalr1_fast.tab.c"
    break;

  case 174: /* RelationalExpression: RelationalExpression Lt ShiftExpression  */
#line 1154 "parser/lalr1_fast.y"
                                                                    {       
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = RelationalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                    }
#line 4032 "lalr1_fast.tab.c"
    break;

  case 175: /* RelationalExpression: RelationalExpression Gt ShiftExpression  */
#line 1159 "parser/lalr1_fast.y"
                                                                    {       
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = RelationalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                    }
#line 4042 "lalr1_fast.tab.c"
    break;

  case 176: /* RelationalExpression: RelationalExpression Leq ShiftExpression  */
#line 1164 "parser/lalr1_fast.y"
                                                                    {        
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = RelationalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                    }
#line 4052 "lalr1_fast.tab.c"
    break;

  case 177: /* RelationalExpression: RelationalExpression Geq ShiftExpression  */
#line 1169 "parser/lalr1_fast.y"
                                                                    {       
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = RelationalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                    }
#line 4062 "lalr1_fast.tab.c"
    break;

  case 178: /* RelationalExpression: RelationalExpression Instanceof ReferenceType  */
#line 1174 "parser/lalr1_fast.y"
                                                                    { }
#line 4068 "lalr1_fast.tab.c"
    break;

  case 179: /* ShiftExpression: AdditiveExpression  */
#line 1177 "parser/lalr1_fast.y"
                                       { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4074 "lalr1_fast.tab.c"
    break;

  case 180: /* ShiftExpression: ShiftExpression Left_shift AdditiveExpression  */
#line 1178 "parser/lalr1_fast.y"
                                                                    {   
                                                                        if(pass_no == 2 ){  
                                                                            (yyval.stack_entry) = ShiftExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                        }
                                                                    }
#line 4084 "lalr1_fast.tab.c"
    break;

  case 181: /* ShiftExpression: ShiftExpression Right_shift AdditiveExpression  */
#line 1183 "parser/lalr1_fast.y"
                                                                    {   
                                                                        if(pass_no == 2 ){  
                                                                            (yyval.stack_entry) = ShiftExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                        }
                                                                    }
#line 4094 "lalr1_fast.tab.c"
    break;

  case 182: /* ShiftExpression: ShiftExpression Unsigned_right_shift AdditiveExpression  */
#line 1188 "parser/lalr1_fast.y"
                                                                                {   
                                                                                    if(pass_no == 2 ){  
                                                                                       (yyval.stack_entry) = ShiftExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                    }
                                                                                }
#line 4104 "lalr1_fast.tab.c"
    break;

  case 183: /* AdditiveExpression: MultiplicativeExpression  */
#line 1195 "parser/lalr1_fast.y"
                                             { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4110 "lalr1_fast.tab.c"
    break;

  case 184: /* AdditiveExpression: AdditiveExpression Plus MultiplicativeExpression  */
#line 1196 "parser/lalr1_fast.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_additive_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                        }
#line 4120 "lalr1_fast.tab.c"
    break;

  case 185: /* AdditiveExpression: AdditiveExpression Minus MultiplicativeExpression  */
#line 1201 "parser/lalr1_fast.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_additive_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                        }
#line 4130 "lalr1_fast.tab.c"
    break;

  case 186: /* MultiplicativeExpression: UnaryExpression  */
#line 1208 "parser/lalr1_fast.y"
                                                                        { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4136 "lalr1_fast.tab.c"
    break;

  case 187: /* MultiplicativeExpression: MultiplicativeExpression Asterik UnaryExpression  */
#line 1209 "parser/lalr1_fast.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_multiplicative_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                        }
#line 4146 "lalr1_fast.tab.c"
    break;

  case 188: /* MultiplicativeExpression: MultiplicativeExpression Div UnaryExpression  */
#line 1214 "parser/lalr1_fast.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_multiplicative_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                        }
#line 4156 "lalr1_fast.tab.c"
    break;

  case 189: /* MultiplicativeExpression: MultiplicativeExpression Modulo UnaryExpression  */
#line 1219 "parser/lalr1_fast.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_multiplicative_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            }
                                                                        }
#line 4166 "lalr1_fast.tab.c"
    break;

  case 190: /* UnaryExpression: PreIncrementExpression  */
#line 1226 "parser/lalr1_fast.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4172 "lalr1_fast.tab.c"
    break;

  case 191: /* UnaryExpression: PreDecrementExpression  */
#line 1227 "parser/lalr1_fast.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4178 "lalr1_fast.tab.c"
    break;

  case 192: /* UnaryExpression: Plus UnaryExpression  */
#line 1228 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        check_if_numeric_type(((yyvsp[0].stack_entry))->type);
                                                        (yyval.stack_entry) = (yyvsp[-1].stack_entry);
                                                    }
                                                }
#line 4189 "lalr1_fast.tab.c"
    break;

  case 193: /* UnaryExpression: Minus UnaryExpression  */
#line 1234 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){   
                                                        check_if_numeric_type(((yyvsp[0].stack_entry))->type);
                                                        (yyval.stack_entry) = (yyvsp[-1].stack_entry);
                                                    }
                                                }
#line 4200 "lalr1_fast.tab.c"
    break;

  case 194: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 1240 "parser/lalr1_fast.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4206 "lalr1_fast.tab.c"
    break;

  case 195: /* PreIncrementExpression: Increment Primary  */
#line 1243 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        check_if_numeric_type(((yyvsp[0].stack_entry))->type);
                                                        (yyval.stack_entry) = (yyvsp[-1].stack_entry);
                                                    }
                                                }
#line 4217 "lalr1_fast.tab.c"
    break;

  case 196: /* PreIncrementExpression: Increment TypeName  */
#line 1249 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        (yyval.stack_entry) = find_variable_in_class(((yyvsp[0].stack_entry))->token, false);
                                                        check_if_numeric_type(((yyval.stack_entry))->type);
                                                    }
                                                }
#line 4228 "lalr1_fast.tab.c"
    break;

  case 197: /* PreDecrementExpression: Decrement Primary  */
#line 1257 "parser/lalr1_fast.y"
                                            {       
                                                    if(pass_no == 2 ){   
                                                        check_if_numeric_type(((yyvsp[0].stack_entry))->type);
                                                        (yyval.stack_entry) = (yyvsp[-1].stack_entry);
                                                    }
                                            }
#line 4239 "lalr1_fast.tab.c"
    break;

  case 198: /* PreDecrementExpression: Decrement TypeName  */
#line 1263 "parser/lalr1_fast.y"
                                            {       
                                                    if(pass_no == 2 ){  
                                                        (yyval.stack_entry) = find_variable_in_class(((yyvsp[0].stack_entry))->token, false);
                                                        check_if_numeric_type(((yyval.stack_entry))->type);
                                                    }
                                            }
#line 4250 "lalr1_fast.tab.c"
    break;

  case 199: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 1271 "parser/lalr1_fast.y"
                                                                    { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4256 "lalr1_fast.tab.c"
    break;

  case 200: /* UnaryExpressionNotPlusMinus: Bitwise_complement UnaryExpression  */
#line 1272 "parser/lalr1_fast.y"
                                                                    {   
                                                                        if(pass_no == 2 ){  
                                                                            check_boolean((yyvsp[0].stack_entry)->type);
                                                                            (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                                        }
                                                                    }
#line 4267 "lalr1_fast.tab.c"
    break;

  case 201: /* UnaryExpressionNotPlusMinus: Not UnaryExpression  */
#line 1278 "parser/lalr1_fast.y"
                                                                    {   
                                                                        if(pass_no == 2 ){  
                                                                            check_boolean((yyvsp[0].stack_entry)->type);
                                                                            (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                                        }
                                                                    }
#line 4278 "lalr1_fast.tab.c"
    break;

  case 202: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 1284 "parser/lalr1_fast.y"
                                                                    { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4284 "lalr1_fast.tab.c"
    break;

  case 203: /* PostfixExpression: Primary  */
#line 1287 "parser/lalr1_fast.y"
                                            { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4290 "lalr1_fast.tab.c"
    break;

  case 204: /* PostfixExpression: TypeName  */
#line 1288 "parser/lalr1_fast.y"
                                            { if(pass_no == 2 ) (yyval.stack_entry) = find_variable_in_class(((yyvsp[0].stack_entry))->token, false); }
#line 4296 "lalr1_fast.tab.c"
    break;

  case 205: /* PostfixExpression: PostIncrementExpression  */
#line 1289 "parser/lalr1_fast.y"
                                            { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4302 "lalr1_fast.tab.c"
    break;

  case 206: /* PostfixExpression: PostDecrementExpression  */
#line 1290 "parser/lalr1_fast.y"
                                            { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4308 "lalr1_fast.tab.c"
    break;

  case 207: /* PostIncrementExpression: Primary Increment  */
#line 1293 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        if(!check_if_numeric_type(((yyvsp[-1].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '++' \n first type: "<< ((yyvsp[-1].stack_entry))->type << "\n";
                                                            exit(-1);
                                                        }
                                                        (yyval.stack_entry) = (yyvsp[-1].stack_entry);
                                                    }
                                                }
#line 4322 "lalr1_fast.tab.c"
    break;

  case 208: /* PostIncrementExpression: TypeName Increment  */
#line 1302 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        (yyval.stack_entry) = find_variable_in_class(((yyvsp[-1].stack_entry))->token, false);
                                                        if(!check_if_numeric_type(((yyval.stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '++' \n first type: "<< ((yyvsp[-1].stack_entry))->type << "\n";
                                                            exit(-1);
                                                        }
                                                    }
                                                }
#line 4336 "lalr1_fast.tab.c"
    break;

  case 209: /* PostDecrementExpression: Primary Decrement  */
#line 1313 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){
                                                        if(!check_if_numeric_type(((yyvsp[-1].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '--' \n first type: "<< ((yyvsp[-1].stack_entry))->type << "\n";
                                                            exit(-1);
                                                        }
                                                        
                                                        (yyval.stack_entry) = (yyvsp[-1].stack_entry);
                                                    }
                                                }
#line 4351 "lalr1_fast.tab.c"
    break;

  case 210: /* PostDecrementExpression: TypeName Decrement  */
#line 1323 "parser/lalr1_fast.y"
                                                {   
                                                    if(pass_no == 2 ){
                                                        (yyval.stack_entry) = find_variable_in_class(((yyvsp[-1].stack_entry))->token, false);
                                                        if(!check_if_numeric_type(((yyval.stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '--' \n first type: "<< ((yyvsp[-1].stack_entry))->type << "\n";
                                                            exit(-1);
                                                        }
                                                    }
                                                }
#line 4365 "lalr1_fast.tab.c"
    break;

  case 211: /* CastExpression: Lparen PrimitiveType Rparen UnaryExpression  */
#line 1334 "parser/lalr1_fast.y"
                                                                                {   
                                                                                    if(pass_no == 2 ){
                                                                                        check_cast_types((yyvsp[-2].type), (yyvsp[0].stack_entry)->type);
                                                                                        (yyval.stack_entry) = make_stackentry("", (yyvsp[-2].type)->name, yylineno);
                                                                                    }
                                                                                }
#line 4376 "lalr1_fast.tab.c"
    break;

  case 212: /* CastExpression: Lparen ReferenceType Rparen UnaryExpressionNotPlusMinus  */
#line 1340 "parser/lalr1_fast.y"
                                                                                {   
                                                                                    if(pass_no == 2 ){
                                                                                        check_cast_types((yyvsp[-2].type), (yyvsp[0].stack_entry)->type);
                                                                                        (yyval.stack_entry) = make_stackentry("", (yyvsp[-2].type)->name, yylineno);
                                                                                    }
                                                                                }
#line 4387 "lalr1_fast.tab.c"
    break;

  case 213: /* Block: Lcurly ScopeIncrement Rcurly  */
#line 1349 "parser/lalr1_fast.y"
                                       { if(pass_no == 2 ){ clear_current_scope(); } }
#line 4393 "lalr1_fast.tab.c"
    break;

  case 214: /* Block: Lcurly ScopeIncrement BlockStatements Rcurly  */
#line 1350 "parser/lalr1_fast.y"
                                                       { if(pass_no == 2 ){ clear_current_scope(); } }
#line 4399 "lalr1_fast.tab.c"
    break;

  case 215: /* BlockStatements: BlockStatements BlockStatement  */
#line 1353 "parser/lalr1_fast.y"
                                                    { }
#line 4405 "lalr1_fast.tab.c"
    break;

  case 216: /* BlockStatements: BlockStatement  */
#line 1354 "parser/lalr1_fast.y"
                                                    { }
#line 4411 "lalr1_fast.tab.c"
    break;

  case 217: /* BlockStatement: ClassOrInterfaceDeclaration  */
#line 1358 "parser/lalr1_fast.y"
                                                { }
#line 4417 "lalr1_fast.tab.c"
    break;

  case 218: /* BlockStatement: LocalVariableDeclarationStatement  */
#line 1359 "parser/lalr1_fast.y"
                                                        { }
#line 4423 "lalr1_fast.tab.c"
    break;

  case 219: /* BlockStatement: Statement  */
#line 1360 "parser/lalr1_fast.y"
                                { }
#line 4429 "lalr1_fast.tab.c"
    break;

  case 220: /* LocalVariableDeclarationStatement: LocalVariableDeclaration Semicolon  */
#line 1363 "parser/lalr1_fast.y"
                                                                          { if(pass_no == 2 ){ global_type = ""; global_modifier= 0b0;} }
#line 4435 "lalr1_fast.tab.c"
    break;

  case 221: /* LocalVariableDeclaration: UnannTypeSubRoutine VariableDeclaratorList  */
#line 1366 "parser/lalr1_fast.y"
                                                                          { global_type = ""; }
#line 4441 "lalr1_fast.tab.c"
    break;

  case 222: /* $@6: %empty  */
#line 1367 "parser/lalr1_fast.y"
                                      { if(pass_no == 2 ) global_type = __VAR; }
#line 4447 "lalr1_fast.tab.c"
    break;

  case 223: /* LocalVariableDeclaration: Var $@6 VariableDeclaratorList  */
#line 1367 "parser/lalr1_fast.y"
                                                                                                           { }
#line 4453 "lalr1_fast.tab.c"
    break;

  case 224: /* $@7: %empty  */
#line 1368 "parser/lalr1_fast.y"
                                   { if(pass_no == 2 ) global_modifier = __FINAL; }
#line 4459 "lalr1_fast.tab.c"
    break;

  case 225: /* LocalVariableDeclaration: Final $@7 UnannTypeSubRoutine VariableDeclaratorList  */
#line 1368 "parser/lalr1_fast.y"
                                                                                                                               { global_type = ""; }
#line 4465 "lalr1_fast.tab.c"
    break;

  case 226: /* $@8: %empty  */
#line 1369 "parser/lalr1_fast.y"
                                   { if(pass_no == 2 ) global_modifier = __FINAL; }
#line 4471 "lalr1_fast.tab.c"
    break;

  case 227: /* $@9: %empty  */
#line 1369 "parser/lalr1_fast.y"
                                                                                           { if(pass_no == 2 ) global_type = __VAR; }
#line 4477 "lalr1_fast.tab.c"
    break;

  case 228: /* LocalVariableDeclaration: Final $@8 Var $@9 VariableDeclaratorList  */
#line 1369 "parser/lalr1_fast.y"
                                                                                                                                                               { }
#line 4483 "lalr1_fast.tab.c"
    break;

  case 251: /* SynchronizedStatement: synchronized_ Lparen Expression Rparen Block  */
#line 1404 "parser/lalr1_fast.y"
                                                                     { }
#line 4489 "lalr1_fast.tab.c"
    break;

  case 252: /* EmptyStatement: Semicolon  */
#line 1407 "parser/lalr1_fast.y"
                                { }
#line 4495 "lalr1_fast.tab.c"
    break;

  case 253: /* LabeledStatement: Identifier Colon Statement  */
#line 1410 "parser/lalr1_fast.y"
                                                  { }
#line 4501 "lalr1_fast.tab.c"
    break;

  case 254: /* LabeledStatementNoShortIf: Identifier Colon StatementNoShortIf  */
#line 1413 "parser/lalr1_fast.y"
                                                                    { }
#line 4507 "lalr1_fast.tab.c"
    break;

  case 255: /* ExpressionStatement: StatementExpression Semicolon  */
#line 1416 "parser/lalr1_fast.y"
                                                        { (yyval.stack_entry) = (yyvsp[-1].stack_entry); }
#line 4513 "lalr1_fast.tab.c"
    break;

  case 256: /* StatementExpression: Assignment  */
#line 1419 "parser/lalr1_fast.y"
                                    { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4519 "lalr1_fast.tab.c"
    break;

  case 257: /* StatementExpression: PreIncrementExpression  */
#line 1420 "parser/lalr1_fast.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4525 "lalr1_fast.tab.c"
    break;

  case 258: /* StatementExpression: PreDecrementExpression  */
#line 1421 "parser/lalr1_fast.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4531 "lalr1_fast.tab.c"
    break;

  case 259: /* StatementExpression: PostIncrementExpression  */
#line 1422 "parser/lalr1_fast.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4537 "lalr1_fast.tab.c"
    break;

  case 260: /* StatementExpression: PostDecrementExpression  */
#line 1423 "parser/lalr1_fast.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4543 "lalr1_fast.tab.c"
    break;

  case 261: /* StatementExpression: MethodInvocation  */
#line 1424 "parser/lalr1_fast.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4549 "lalr1_fast.tab.c"
    break;

  case 262: /* StatementExpression: ClassInstanceCreationExpression  */
#line 1425 "parser/lalr1_fast.y"
                                                         { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4555 "lalr1_fast.tab.c"
    break;

  case 263: /* IfThenStatementSubRoutine: If Lparen Expression  */
#line 1429 "parser/lalr1_fast.y"
                          { IfCondition((yyvsp[0].stack_entry)); }
#line 4561 "lalr1_fast.tab.c"
    break;

  case 264: /* IfThenStatement: IfThenStatementSubRoutine Rparen ScopeIncrement Statement  */
#line 1432 "parser/lalr1_fast.y"
                                                                                { clear_current_scope(); }
#line 4567 "lalr1_fast.tab.c"
    break;

  case 265: /* IfThenElseStatement: IfThenStatementSubRoutine Rparen ScopeIncrement StatementNoShortIf Else Statement  */
#line 1435 "parser/lalr1_fast.y"
                                                                                                            { clear_current_scope(); }
#line 4573 "lalr1_fast.tab.c"
    break;

  case 266: /* IfThenElseStatementNoShortIf: IfThenStatementSubRoutine Rparen ScopeIncrement StatementNoShortIf Else StatementNoShortIf  */
#line 1438 "parser/lalr1_fast.y"
                                                                                                                             { clear_current_scope(); }
#line 4579 "lalr1_fast.tab.c"
    break;

  case 267: /* AssertStatement: Assert Expression Semicolon  */
#line 1441 "parser/lalr1_fast.y"
                                                { AssertCondition((yyvsp[-1].stack_entry)); }
#line 4585 "lalr1_fast.tab.c"
    break;

  case 268: /* AssertStatement: Assert Expression Colon Expression Semicolon  */
#line 1442 "parser/lalr1_fast.y"
                                                                    { AssertCondition((yyvsp[-3].stack_entry)); }
#line 4591 "lalr1_fast.tab.c"
    break;

  case 269: /* WhileStatementSubRoutine: While Lparen Expression  */
#line 1504 "parser/lalr1_fast.y"
                            { WhileCondition((yyvsp[0].stack_entry)); }
#line 4597 "lalr1_fast.tab.c"
    break;

  case 270: /* WhileStatement: WhileStatementSubRoutine Rparen Statement  */
#line 1507 "parser/lalr1_fast.y"
                                                             { clear_current_scope(); }
#line 4603 "lalr1_fast.tab.c"
    break;

  case 271: /* WhileStatementNoShortIf: WhileStatementSubRoutine Rparen StatementNoShortIf  */
#line 1510 "parser/lalr1_fast.y"
                                                                               { clear_current_scope(); }
#line 4609 "lalr1_fast.tab.c"
    break;

  case 272: /* $@10: %empty  */
#line 1514 "parser/lalr1_fast.y"
                                          {     
                                                if(pass_no == 2){ check_boolean((yyvsp[-2].stack_entry)->type); }
                                            }
#line 4617 "lalr1_fast.tab.c"
    break;

  case 273: /* DoStatement: do_ Statement While Lparen Expression $@10 Rparen Semicolon  */
#line 1516 "parser/lalr1_fast.y"
                                                                { clear_current_scope(); }
#line 4623 "lalr1_fast.tab.c"
    break;

  case 278: /* For1SubRoutine: For Lparen Semicolon Expression  */
#line 1528 "parser/lalr1_fast.y"
                                             { ForCondition((yyvsp[0].stack_entry)); }
#line 4629 "lalr1_fast.tab.c"
    break;

  case 279: /* For2SubRoutine: For Lparen ForInit Semicolon Expression  */
#line 1532 "parser/lalr1_fast.y"
                                               { ForCondition((yyvsp[0].stack_entry));}
#line 4635 "lalr1_fast.tab.c"
    break;

  case 280: /* BasicForStatement: For Lparen Semicolon Semicolon Rparen Statement  */
#line 1535 "parser/lalr1_fast.y"
                                                                                        { clear_current_scope(); }
#line 4641 "lalr1_fast.tab.c"
    break;

  case 281: /* BasicForStatement: For Lparen ForInit Semicolon Semicolon Rparen Statement  */
#line 1536 "parser/lalr1_fast.y"
                                                                                        { clear_current_scope(); }
#line 4647 "lalr1_fast.tab.c"
    break;

  case 282: /* BasicForStatement: For1SubRoutine Semicolon Rparen Statement  */
#line 1537 "parser/lalr1_fast.y"
                                                                                    { clear_current_scope(); }
#line 4653 "lalr1_fast.tab.c"
    break;

  case 283: /* BasicForStatement: For Lparen Semicolon Semicolon ForUpdate Rparen Statement  */
#line 1538 "parser/lalr1_fast.y"
                                                                                    { clear_current_scope(); }
#line 4659 "lalr1_fast.tab.c"
    break;

  case 284: /* BasicForStatement: For2SubRoutine Semicolon Rparen Statement  */
#line 1539 "parser/lalr1_fast.y"
                                                                                    { clear_current_scope(); }
#line 4665 "lalr1_fast.tab.c"
    break;

  case 285: /* BasicForStatement: For1SubRoutine Semicolon ForUpdate Rparen Statement  */
#line 1540 "parser/lalr1_fast.y"
                                                                                    { clear_current_scope(); }
#line 4671 "lalr1_fast.tab.c"
    break;

  case 286: /* BasicForStatement: For Lparen ForInit Semicolon Semicolon ForUpdate Rparen Statement  */
#line 1541 "parser/lalr1_fast.y"
                                                                                          { clear_current_scope(); }
#line 4677 "lalr1_fast.tab.c"
    break;

  case 287: /* BasicForStatement: For2SubRoutine Semicolon ForUpdate Rparen Statement  */
#line 1542 "parser/lalr1_fast.y"
                                                                            { clear_current_scope(); }
#line 4683 "lalr1_fast.tab.c"
    break;

  case 288: /* BasicForStatementNoShortIf: For Lparen Semicolon Semicolon Rparen StatementNoShortIf  */
#line 1545 "parser/lalr1_fast.y"
                                                                                         { clear_current_scope(); }
#line 4689 "lalr1_fast.tab.c"
    break;

  case 289: /* BasicForStatementNoShortIf: For Lparen ForInit Semicolon Semicolon Rparen StatementNoShortIf  */
#line 1546 "parser/lalr1_fast.y"
                                                                                         { clear_current_scope(); }
#line 4695 "lalr1_fast.tab.c"
    break;

  case 290: /* BasicForStatementNoShortIf: For1SubRoutine Semicolon Rparen StatementNoShortIf  */
#line 1547 "parser/lalr1_fast.y"
                                                                           { clear_current_scope(); }
#line 4701 "lalr1_fast.tab.c"
    break;

  case 291: /* BasicForStatementNoShortIf: For Lparen Semicolon Semicolon ForUpdate Rparen StatementNoShortIf  */
#line 1548 "parser/lalr1_fast.y"
                                                                                           { clear_current_scope(); }
#line 4707 "lalr1_fast.tab.c"
    break;

  case 292: /* BasicForStatementNoShortIf: For2SubRoutine Semicolon Rparen StatementNoShortIf  */
#line 1549 "parser/lalr1_fast.y"
                                                                           { clear_current_scope(); }
#line 4713 "lalr1_fast.tab.c"
    break;

  case 293: /* BasicForStatementNoShortIf: For1SubRoutine Semicolon ForUpdate Rparen StatementNoShortIf  */
#line 1550 "parser/lalr1_fast.y"
                                                                                      { clear_current_scope(); }
#line 4719 "lalr1_fast.tab.c"
    break;

  case 294: /* BasicForStatementNoShortIf: For Lparen ForInit Semicolon Semicolon ForUpdate Rparen StatementNoShortIf  */
#line 1551 "parser/lalr1_fast.y"
                                                                                                    { clear_current_scope(); }
#line 4725 "lalr1_fast.tab.c"
    break;

  case 295: /* BasicForStatementNoShortIf: For2SubRoutine Semicolon ForUpdate Rparen StatementNoShortIf  */
#line 1552 "parser/lalr1_fast.y"
                                                                                      { clear_current_scope(); }
#line 4731 "lalr1_fast.tab.c"
    break;

  case 303: /* EnhancedForStatementSubRoutine: For Lparen LocalVariableDeclaration Colon Expression  */
#line 1571 "parser/lalr1_fast.y"
                                                         { EnhancedForCondition((yyvsp[0].stack_entry)); }
#line 4737 "lalr1_fast.tab.c"
    break;

  case 304: /* EnhancedForStatement: EnhancedForStatementSubRoutine Rparen Statement  */
#line 1574 "parser/lalr1_fast.y"
                                                                          { }
#line 4743 "lalr1_fast.tab.c"
    break;

  case 305: /* EnhancedForStatementNoShortIf: EnhancedForStatementSubRoutine Rparen StatementNoShortIf  */
#line 1577 "parser/lalr1_fast.y"
                                                                                              { }
#line 4749 "lalr1_fast.tab.c"
    break;

  case 308: /* ReturnStatement: Return Expression Semicolon  */
#line 1593 "parser/lalr1_fast.y"
                                { }
#line 4755 "lalr1_fast.tab.c"
    break;

  case 309: /* ReturnStatement: Return Semicolon  */
#line 1594 "parser/lalr1_fast.y"
                      { }
#line 4761 "lalr1_fast.tab.c"
    break;

  case 310: /* ThrowStatement: Throw Expression Semicolon  */
#line 1597 "parser/lalr1_fast.y"
                                                { }
#line 4767 "lalr1_fast.tab.c"
    break;

  case 311: /* TryStatement: try_ Block Catches  */
#line 1601 "parser/lalr1_fast.y"
                                                { }
#line 4773 "lalr1_fast.tab.c"
    break;

  case 312: /* TryStatement: try_ Block Catches Finally  */
#line 1602 "parser/lalr1_fast.y"
                                                { }
#line 4779 "lalr1_fast.tab.c"
    break;

  case 313: /* TryStatement: try_ Block Finally  */
#line 1603 "parser/lalr1_fast.y"
                                                { }
#line 4785 "lalr1_fast.tab.c"
    break;

  case 314: /* Catches: Catches CatchClause  */
#line 1607 "parser/lalr1_fast.y"
                                                { }
#line 4791 "lalr1_fast.tab.c"
    break;

  case 315: /* Catches: CatchClause  */
#line 1608 "parser/lalr1_fast.y"
                                                { }
#line 4797 "lalr1_fast.tab.c"
    break;

  case 316: /* CatchClause: catch_ Lparen CatchFormalParameter Rparen Block  */
#line 1612 "parser/lalr1_fast.y"
                                                                    { }
#line 4803 "lalr1_fast.tab.c"
    break;

  case 317: /* CatchFormalParameter: CatchType VariableDeclaratorId  */
#line 1615 "parser/lalr1_fast.y"
                                                                { }
#line 4809 "lalr1_fast.tab.c"
    break;

  case 318: /* CatchFormalParameter: Final CatchType VariableDeclaratorId  */
#line 1616 "parser/lalr1_fast.y"
                                                                { }
#line 4815 "lalr1_fast.tab.c"
    break;

  case 319: /* CatchType: ClassOrInterfaceType  */
#line 1619 "parser/lalr1_fast.y"
                                         { }
#line 4821 "lalr1_fast.tab.c"
    break;

  case 320: /* CatchType: ClassOrInterfaceType Bitwise_or CatchType  */
#line 1620 "parser/lalr1_fast.y"
                                                                        { }
#line 4827 "lalr1_fast.tab.c"
    break;

  case 321: /* Finally: finally_ Block  */
#line 1624 "parser/lalr1_fast.y"
                                            { }
#line 4833 "lalr1_fast.tab.c"
    break;

  case 322: /* Int: INT  */
#line 1629 "parser/lalr1_fast.y"
            { (yyval.type) = get_type(__INT); }
#line 4839 "lalr1_fast.tab.c"
    break;

  case 323: /* Long: LONG  */
#line 1632 "parser/lalr1_fast.y"
            { (yyval.type) = get_type(__LONG); }
#line 4845 "lalr1_fast.tab.c"
    break;

  case 324: /* Byte: BYTE  */
#line 1635 "parser/lalr1_fast.y"
            { (yyval.type) = get_type(__BYTE); }
#line 4851 "lalr1_fast.tab.c"
    break;

  case 325: /* Short: SHORT  */
#line 1638 "parser/lalr1_fast.y"
              { (yyval.type) = get_type(__SHORT); }
#line 4857 "lalr1_fast.tab.c"
    break;

  case 326: /* Char: CHAR  */
#line 1641 "parser/lalr1_fast.y"
             { (yyval.type) = get_type(__CHAR); }
#line 4863 "lalr1_fast.tab.c"
    break;

  case 327: /* Float: FLOAT  */
#line 1644 "parser/lalr1_fast.y"
                        { (yyval.type) = get_type(__FLOAT); }
#line 4869 "lalr1_fast.tab.c"
    break;

  case 328: /* Double: DOUBLE  */
#line 1647 "parser/lalr1_fast.y"
                        { (yyval.type) = get_type(__DOUBLE); }
#line 4875 "lalr1_fast.tab.c"
    break;

  case 329: /* Boolean: BOOLEAN  */
#line 1650 "parser/lalr1_fast.y"
                        { (yyval.type) = get_type(__BOOLEAN); }
#line 4881 "lalr1_fast.tab.c"
    break;

  case 330: /* Var: VAR  */
#line 1653 "parser/lalr1_fast.y"
                        { (yyval.type) = get_type(__VAR); }
#line 4887 "lalr1_fast.tab.c"
    break;

  case 331: /* If: IF  */
#line 1656 "parser/lalr1_fast.y"
        { }
#line 4893 "lalr1_fast.tab.c"
    break;

  case 332: /* Else: ELSE  */
#line 1659 "parser/lalr1_fast.y"
            { }
#line 4899 "lalr1_fast.tab.c"
    break;

  case 333: /* While: WHILE  */
#line 1662 "parser/lalr1_fast.y"
                { increase_current_level(); }
#line 4905 "lalr1_fast.tab.c"
    break;

  case 334: /* For: FOR  */
#line 1665 "parser/lalr1_fast.y"
                { increase_current_level(); }
#line 4911 "lalr1_fast.tab.c"
    break;

  case 335: /* Break: BREAK  */
#line 1668 "parser/lalr1_fast.y"
              { }
#line 4917 "lalr1_fast.tab.c"
    break;

  case 336: /* Continue: CONTINUE  */
#line 1671 "parser/lalr1_fast.y"
                    { }
#line 4923 "lalr1_fast.tab.c"
    break;

  case 337: /* Void: VOID  */
#line 1674 "parser/lalr1_fast.y"
            { (yyval.type) = get_type(__VOID); }
#line 4929 "lalr1_fast.tab.c"
    break;

  case 338: /* New: NEW  */
#line 1677 "parser/lalr1_fast.y"
          { }
#line 4935 "lalr1_fast.tab.c"
    break;

  case 339: /* Return: RETURN  */
#line 1680 "parser/lalr1_fast.y"
                { }
#line 4941 "lalr1_fast.tab.c"
    break;

  case 340: /* Public: PUBLIC  */
#line 1683 "parser/lalr1_fast.y"
                 {}
#line 4947 "lalr1_fast.tab.c"
    break;

  case 341: /* Private: PRIVATE  */
#line 1686 "parser/lalr1_fast.y"
                  {}
#line 4953 "lalr1_fast.tab.c"
    break;

  case 342: /* Class: CLASS  */
#line 1689 "parser/lalr1_fast.y"
              { }
#line 4959 "lalr1_fast.tab.c"
    break;

  case 343: /* Static: STATIC  */
#line 1692 "parser/lalr1_fast.y"
                {}
#line 4965 "lalr1_fast.tab.c"
    break;

  case 344: /* Final: FINAL  */
#line 1695 "parser/lalr1_fast.y"
              {}
#line 4971 "lalr1_fast.tab.c"
    break;

  case 345: /* Assert: ASSERT  */
#line 1698 "parser/lalr1_fast.y"
                { }
#line 4977 "lalr1_fast.tab.c"
    break;

  case 346: /* This: THIS  */
#line 1701 "parser/lalr1_fast.y"
            { }
#line 4983 "lalr1_fast.tab.c"
    break;

  case 347: /* Instanceof: INSTANCEOF  */
#line 1704 "parser/lalr1_fast.y"
                        { }
#line 4989 "lalr1_fast.tab.c"
    break;

  case 348: /* super_: SUPER  */
#line 1707 "parser/lalr1_fast.y"
               { }
#line 4995 "lalr1_fast.tab.c"
    break;

  case 349: /* Throw: THROW  */
#line 1710 "parser/lalr1_fast.y"
              { }
#line 5001 "lalr1_fast.tab.c"
    break;

  case 350: /* Package: PACKAGE  */
#line 1722 "parser/lalr1_fast.y"
                  { }
#line 5007 "lalr1_fast.tab.c"
    break;

  case 351: /* Import: IMPORT  */
#line 1725 "parser/lalr1_fast.y"
                { }
#line 5013 "lalr1_fast.tab.c"
    break;

  case 352: /* do_: DO  */
#line 1728 "parser/lalr1_fast.y"
        { increase_current_level(); }
#line 5019 "lalr1_fast.tab.c"
    break;

  case 353: /* try_: TRY  */
#line 1734 "parser/lalr1_fast.y"
           { }
#line 5025 "lalr1_fast.tab.c"
    break;

  case 354: /* throws_: THROWS  */
#line 1736 "parser/lalr1_fast.y"
                 { }
#line 5031 "lalr1_fast.tab.c"
    break;

  case 355: /* catch_: CATCH  */
#line 1738 "parser/lalr1_fast.y"
               { }
#line 5037 "lalr1_fast.tab.c"
    break;

  case 356: /* finally_: FINALLY  */
#line 1740 "parser/lalr1_fast.y"
                   { }
#line 5043 "lalr1_fast.tab.c"
    break;

  case 357: /* synchronized_: SYNCHRONIZED  */
#line 1742 "parser/lalr1_fast.y"
                             { }
#line 5049 "lalr1_fast.tab.c"
    break;

  case 358: /* Plus: PLUS  */
#line 1748 "parser/lalr1_fast.y"
            { }
#line 5055 "lalr1_fast.tab.c"
    break;

  case 359: /* Minus: MINUS  */
#line 1751 "parser/lalr1_fast.y"
              { }
#line 5061 "lalr1_fast.tab.c"
    break;

  case 360: /* Div: DIV  */
#line 1754 "parser/lalr1_fast.y"
          { }
#line 5067 "lalr1_fast.tab.c"
    break;

  case 361: /* Asterik: ASTERIK  */
#line 1757 "parser/lalr1_fast.y"
                  { }
#line 5073 "lalr1_fast.tab.c"
    break;

  case 362: /* Modulo: MODULO  */
#line 1760 "parser/lalr1_fast.y"
                { }
#line 5079 "lalr1_fast.tab.c"
    break;

  case 363: /* Increment: INCREMENT  */
#line 1763 "parser/lalr1_fast.y"
                      { }
#line 5085 "lalr1_fast.tab.c"
    break;

  case 364: /* Decrement: DECREMENT  */
#line 1766 "parser/lalr1_fast.y"
                      { }
#line 5091 "lalr1_fast.tab.c"
    break;

  case 365: /* Geq: GEQ  */
#line 1769 "parser/lalr1_fast.y"
          { }
#line 5097 "lalr1_fast.tab.c"
    break;

  case 366: /* Leq: LEQ  */
#line 1772 "parser/lalr1_fast.y"
          { }
#line 5103 "lalr1_fast.tab.c"
    break;

  case 367: /* Gt: GT  */
#line 1775 "parser/lalr1_fast.y"
        { }
#line 5109 "lalr1_fast.tab.c"
    break;

  case 368: /* Lt: LT  */
#line 1778 "parser/lalr1_fast.y"
        { }
#line 5115 "lalr1_fast.tab.c"
    break;

  case 369: /* Neq: NEQ  */
#line 1781 "parser/lalr1_fast.y"
          { }
#line 5121 "lalr1_fast.tab.c"
    break;

  case 370: /* Deq: DEQ  */
#line 1784 "parser/lalr1_fast.y"
          { }
#line 5127 "lalr1_fast.tab.c"
    break;

  case 371: /* Bitwise_and: BITWISE_AND  */
#line 1787 "parser/lalr1_fast.y"
                          { }
#line 5133 "lalr1_fast.tab.c"
    break;

  case 372: /* Bitwise_or: BITWISE_OR  */
#line 1790 "parser/lalr1_fast.y"
                        { }
#line 5139 "lalr1_fast.tab.c"
    break;

  case 373: /* Bitwise_xor: BITWISE_XOR  */
#line 1793 "parser/lalr1_fast.y"
                          { }
#line 5145 "lalr1_fast.tab.c"
    break;

  case 374: /* Bitwise_complement: BITWISE_COMPLEMENT  */
#line 1796 "parser/lalr1_fast.y"
                                        { }
#line 5151 "lalr1_fast.tab.c"
    break;

  case 375: /* Left_shift: LEFT_SHIFT  */
#line 1799 "parser/lalr1_fast.y"
                        { }
#line 5157 "lalr1_fast.tab.c"
    break;

  case 376: /* Right_shift: RIGHT_SHIFT  */
#line 1802 "parser/lalr1_fast.y"
                          { }
#line 5163 "lalr1_fast.tab.c"
    break;

  case 377: /* Unsigned_right_shift: UNSIGNED_RIGHT_SHIFT  */
#line 1805 "parser/lalr1_fast.y"
                                            { }
#line 5169 "lalr1_fast.tab.c"
    break;

  case 378: /* And: AND  */
#line 1808 "parser/lalr1_fast.y"
          { }
#line 5175 "lalr1_fast.tab.c"
    break;

  case 379: /* Or: OR  */
#line 1811 "parser/lalr1_fast.y"
        { }
#line 5181 "lalr1_fast.tab.c"
    break;

  case 380: /* Not: NOT  */
#line 1814 "parser/lalr1_fast.y"
          { }
#line 5187 "lalr1_fast.tab.c"
    break;

  case 381: /* AssignmentOperator: ASSIGNMENT  */
#line 1817 "parser/lalr1_fast.y"
                                { }
#line 5193 "lalr1_fast.tab.c"
    break;

  case 382: /* Assign: ASSIGN  */
#line 1820 "parser/lalr1_fast.y"
               { }
#line 5199 "lalr1_fast.tab.c"
    break;

  case 383: /* Colon: COLON  */
#line 1822 "parser/lalr1_fast.y"
              { }
#line 5205 "lalr1_fast.tab.c"
    break;

  case 384: /* Qm: QM  */
#line 1825 "parser/lalr1_fast.y"
        { }
#line 5211 "lalr1_fast.tab.c"
    break;

  case 385: /* Lparen: LPAREN  */
#line 1828 "parser/lalr1_fast.y"
                { }
#line 5217 "lalr1_fast.tab.c"
    break;

  case 386: /* Rparen: RPAREN  */
#line 1831 "parser/lalr1_fast.y"
                { }
#line 5223 "lalr1_fast.tab.c"
    break;

  case 387: /* Lcurly: LCURLY  */
#line 1834 "parser/lalr1_fast.y"
                { }
#line 5229 "lalr1_fast.tab.c"
    break;

  case 388: /* Rcurly: RCURLY  */
#line 1837 "parser/lalr1_fast.y"
                { }
#line 5235 "lalr1_fast.tab.c"
    break;

  case 389: /* Lsquare: LSQUARE  */
#line 1840 "parser/lalr1_fast.y"
                  { }
#line 5241 "lalr1_fast.tab.c"
    break;

  case 390: /* Rsquare: RSQUARE  */
#line 1843 "parser/lalr1_fast.y"
                  { }
#line 5247 "lalr1_fast.tab.c"
    break;

  case 391: /* Semicolon: SEMICOLON  */
#line 1846 "parser/lalr1_fast.y"
                      { }
#line 5253 "lalr1_fast.tab.c"
    break;

  case 392: /* Comma: COMMA  */
#line 1849 "parser/lalr1_fast.y"
              { }
#line 5259 "lalr1_fast.tab.c"
    break;

  case 393: /* Dot: DOT  */
#line 1852 "parser/lalr1_fast.y"
          { }
#line 5265 "lalr1_fast.tab.c"
    break;

  case 394: /* Char_literal: CHAR_LITERAL  */
#line 1857 "parser/lalr1_fast.y"
                                { (yyval.stack_entry) = make_stackentry((yyvsp[0].str), __CHAR, yylineno); }
#line 5271 "lalr1_fast.tab.c"
    break;

  case 395: /* Boolean_literal: BOOLEAN_LITERAL  */
#line 1860 "parser/lalr1_fast.y"
                                  { (yyval.stack_entry) = make_stackentry((yyvsp[0].str), __BOOLEAN, yylineno); }
#line 5277 "lalr1_fast.tab.c"
    break;

  case 396: /* Null_literal: NULL_LITERAL  */
#line 1863 "parser/lalr1_fast.y"
                                { (yyval.stack_entry) = make_stackentry((yyvsp[0].str), yylineno); }
#line 5283 "lalr1_fast.tab.c"
    break;

  case 397: /* Integer_literal: INTEGER_LITERAL  */
#line 1866 "parser/lalr1_fast.y"
                                  { (yyval.stack_entry) = make_stackentry((yyvsp[0].str), __INT, yylineno); }
#line 5289 "lalr1_fast.tab.c"
    break;

  case 398: /* Fp_literal: FP_LITERAL  */
#line 1869 "parser/lalr1_fast.y"
                            { (yyval.stack_entry) = make_stackentry((yyvsp[0].str), __FLOAT, yylineno); }
#line 5295 "lalr1_fast.tab.c"
    break;

  case 399: /* String: STRING  */
#line 1872 "parser/lalr1_fast.y"
                            { (yyval.stack_entry) = make_stackentry((yyvsp[0].str), yylineno); }
#line 5301 "lalr1_fast.tab.c"
    break;

  case 400: /* Text_block: TEXT_BLOCK  */
#line 1875 "parser/lalr1_fast.y"
                                { (yyval.stack_entry) = make_stackentry((yyvsp[0].str), yylineno); }
#line 5307 "lalr1_fast.tab.c"
    break;

  case 401: /* Identifier: IDENTIFIER  */
#line 1878 "parser/lalr1_fast.y"
                                { (yyval.id) = make_identifier((yyvsp[0].str));}
#line 5313 "lalr1_fast.tab.c"
    break;

  case 402: /* endoffile: EOF_  */
#line 1881 "parser/lalr1_fast.y"
                 { }
#line 5319 "lalr1_fast.tab.c"
    break;


#line 5323 "lalr1_fast.tab.c"

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

#line 1883 "parser/lalr1_fast.y"


int yywrap()
{
    if (pass_no == 1) { 
        
        cout << "In yywrap Pass 1\n";
             /* dump_ST(1); */
        global_table->dump_table();
        verify_pass1();
        pass_no++;
        rewind(yyin);
        yylineno = 1; 
        current_scope = scope_global;
        offset = 0;
        global_modifier = 0b0;
        global_type = "";
        current_class = NULL;
        return 0;
    }
    else {
        cout << "In yywrap Pass 2\n";
        return 1;
    }
}

int main(int argc, char *argv[]) 
{
    current_table = new LocalSymbolTable();
    global_table = new GlobalSymbolTable();
    current_scope = scope_global;
    current_class = NULL;

    global_modifier = 0b0;
    pass_no = 1;
    intialize_types();
     /* argparse::ArgumentParser program("javap");

     struct args *_args = new struct args;


     program.add_argument("--input")
         .required()
         .help("java file to parse");

     program.add_argument("--output")
         .required()
         .help("output dot file");
  
    
     program.add_argument("--verbose")
         .help("increase output verbosity for parser")
         .default_value(false)
         .implicit_value(true); */

 /* 
     try {
         program.parse_args(argc, argv);
     }
     catch (const std::runtime_error &err) {
         std::cerr << "Line No: " <<  yylineno  << err.what() << std::endl;
         std::cerr << "Line No: " <<  yylineno  << program;
         std::exit(1);
     } */


     /* _args->input = (char*)(program.get<std::string>("--input").c_str()); */

  

     /* _args->output = (char*)(program.get<std::string>("--output").c_str()); */
 /* 
     if (program["--verbose"] == true) {
         _args->verbose = true;
     } */


     /* yydebug = 1; */
     /*
     if (_args->verbose)
         yydebug = 1; */

     /* yyin = fopen(_args->input, "r"); */
    yyin = fopen("Demo.java", "r");

    if(yyin == NULL) {
        cerr << "Line No: " <<  yylineno  << "FIle Not Found\n";
        exit(-1);
    }

         /* dotfile.open(_args->output);


         dotfile << "digraph AST {\n";
         dotfile << "node [fontname = courier, shape = box, colorscheme = paired6];\n";
         dotfile << "edge [color=blue];\n"; */

    do {
        yyparse();
    } while(!feof(yyin));

         
         /* dotfile << "}"; */

         /* dotfile.close(); */
         /* fclose(yyin); */
       
     /* } */
     return 0;
 }


/* int main(int argc, char *argv[]) {

    FILE* fp = fopen("demo.java", "r");

    yyin = fp;
        cout << "Hiiiiiiiiiiii I am in Pass " << pass_no << "\n";
        cout << "YYin Pointer: " << yyin << "\n";
    
        if(yyin == NULL) {
            cerr << "Line No: " <<  yylineno  << "FIle Not Found\n";
            exit(-1);
        }
        yyparse();

        dump_ST();

        pass_no++;

    fseek(fp, 0, SEEK_SET);
    yyrestart(yyin);

    yyin = fp;
    
        cout << "Hiiiiiiiiiiii I am in Pass " << pass_no << "\n";
        cout << "YYin Pointer: " << yyin << "\n";
    
        if(yyin == NULL) {
            cerr << "Line No: " <<  yylineno  << "FIle Not Found\n";
            exit(-1);
        }

        yyparse();

    fclose(fp);
    return 0;
} */

int yyerror(const char *s) {
    printf("syntax error: line %d: %s\n", yylineno, s);
    dotfile.close();
    exit(1);
}
