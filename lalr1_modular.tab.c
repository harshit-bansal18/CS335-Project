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
#line 1 "milestone4/src/parser/lalr1_modular.y"

    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include <iomanip>
    #include <vector>
    #include <fstream>
    #include <sstream>
    #include <stack>
    #include <argparse/argparse.hpp>
    #ifndef SYMBOL_TABLE_FAST_H
        #include "symbol_table_fast.hpp"
    #endif

    #ifndef ACTIONS_FAST_H
        #include "actions_fast.hpp"
    #endif

    #include "3ac.hpp"

    #define YYDEBUG 1
    using namespace std;

    struct args {
        char *input;
        char *output;
        bool verbose;    
    };

    extern "C" int yylex();
    extern "C" int yywrap();
    extern "C" FILE *yyin;
    extern "C" int yylineno;
    extern void yyrestart ( FILE *input_file  );
    extern int yylex_destroy ( void );

    extern vector<ThreeAC*> global_tacs;


    extern ClassDefinition *current_class;
    extern LocalSymbolTable *current_table;
    extern GlobalSymbolTable *global_table;

    extern scope current_scope;

    extern unordered_map<string, Type *> defined_types;

    extern int loopnum;
    extern int ifnum;
    extern int tcount;
    extern int paramcount;
    extern string threeac_file_name;

    int8_t global_modifier;
    Type* global_type;
    int pass_no = 1;
    stringstream text;
    vector<Address*> args;

    static int node_num=-1;

    ofstream dotfile;

    int yyerror(const char *);
    
    

#line 141 "lalr1_modular.tab.c"

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

#include "lalr1_modular.tab.h"
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
  YYSYMBOL_COLON = 50,                     /* COLON  */
  YYSYMBOL_QM = 51,                        /* QM  */
  YYSYMBOL_LPAREN = 52,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 53,                    /* RPAREN  */
  YYSYMBOL_LCURLY = 54,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 55,                    /* RCURLY  */
  YYSYMBOL_LSQUARE = 56,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 57,                   /* RSQUARE  */
  YYSYMBOL_SEMICOLON = 58,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 59,                     /* COMMA  */
  YYSYMBOL_DOT = 60,                       /* DOT  */
  YYSYMBOL_CHAR_LITERAL = 61,              /* CHAR_LITERAL  */
  YYSYMBOL_BOOLEAN_LITERAL = 62,           /* BOOLEAN_LITERAL  */
  YYSYMBOL_NULL_LITERAL = 63,              /* NULL_LITERAL  */
  YYSYMBOL_INTEGER_LITERAL = 64,           /* INTEGER_LITERAL  */
  YYSYMBOL_FP_LITERAL = 65,                /* FP_LITERAL  */
  YYSYMBOL_STRING = 66,                    /* STRING  */
  YYSYMBOL_TEXT_BLOCK = 67,                /* TEXT_BLOCK  */
  YYSYMBOL_IDENTIFIER = 68,                /* IDENTIFIER  */
  YYSYMBOL_THIS = 69,                      /* THIS  */
  YYSYMBOL_THROW = 70,                     /* THROW  */
  YYSYMBOL_EOF_ = 71,                      /* EOF_  */
  YYSYMBOL_ASTERIK = 72,                   /* ASTERIK  */
  YYSYMBOL_DO = 73,                        /* DO  */
  YYSYMBOL_PRINT = 74,                     /* PRINT  */
  YYSYMBOL_ASSIGN = 75,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_Program = 77,                   /* Program  */
  YYSYMBOL_CompilationUnit = 78,           /* CompilationUnit  */
  YYSYMBOL_ClassOrInterfaceDeclarations = 79, /* ClassOrInterfaceDeclarations  */
  YYSYMBOL_ClassOrInterfaceDeclaration = 80, /* ClassOrInterfaceDeclaration  */
  YYSYMBOL_ScopeIncrement = 81,            /* ScopeIncrement  */
  YYSYMBOL_Literal = 82,                   /* Literal  */
  YYSYMBOL_UnannTypeSubRoutine = 83,       /* UnannTypeSubRoutine  */
  YYSYMBOL_UnannType = 84,                 /* UnannType  */
  YYSYMBOL_PrimitiveType = 85,             /* PrimitiveType  */
  YYSYMBOL_NumericType = 86,               /* NumericType  */
  YYSYMBOL_IntegralType = 87,              /* IntegralType  */
  YYSYMBOL_FloatingPointType = 88,         /* FloatingPointType  */
  YYSYMBOL_ReferenceType = 89,             /* ReferenceType  */
  YYSYMBOL_ClassOrInterfaceType = 90,      /* ClassOrInterfaceType  */
  YYSYMBOL_ArrayType = 91,                 /* ArrayType  */
  YYSYMBOL_Dims = 92,                      /* Dims  */
  YYSYMBOL_TypeName = 93,                  /* TypeName  */
  YYSYMBOL_ModifiersUnannTypeSubRoutine = 94, /* ModifiersUnannTypeSubRoutine  */
  YYSYMBOL_Modifiers = 95,                 /* Modifiers  */
  YYSYMBOL_Modifier = 96,                  /* Modifier  */
  YYSYMBOL_ClassDeclaration = 97,          /* ClassDeclaration  */
  YYSYMBOL_98_1 = 98,                      /* $@1  */
  YYSYMBOL_99_2 = 99,                      /* $@2  */
  YYSYMBOL_ClassBody = 100,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 101,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 102,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 103,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 104,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclaratorList = 105,   /* VariableDeclaratorList  */
  YYSYMBOL_VariableDeclarator = 106,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 107,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 108,      /* VariableInitializer  */
  YYSYMBOL_MethodDeclaration = 109,        /* MethodDeclaration  */
  YYSYMBOL_110_3 = 110,                    /* $@3  */
  YYSYMBOL_MethodHeader = 111,             /* MethodHeader  */
  YYSYMBOL_DeclaratorSubRoutine = 112,     /* DeclaratorSubRoutine  */
  YYSYMBOL_Declarator = 113,               /* Declarator  */
  YYSYMBOL_FormalParameterList = 114,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 115,          /* FormalParameter  */
  YYSYMBOL_MethodBody = 116,               /* MethodBody  */
  YYSYMBOL_StaticInitializer = 117,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 118,   /* ConstructorDeclaration  */
  YYSYMBOL_119_4 = 119,                    /* $@4  */
  YYSYMBOL_120_5 = 120,                    /* $@5  */
  YYSYMBOL_ConstructorBody = 121,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation = 122, /* ExplicitConstructorInvocation  */
  YYSYMBOL_ArrayInitializer = 123,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializerList = 124,  /* VariableInitializerList  */
  YYSYMBOL_Primary = 125,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 126,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassInstanceCreationExpressionSubRoutine = 127, /* ClassInstanceCreationExpressionSubRoutine  */
  YYSYMBOL_ClassInstanceCreationExpression = 128, /* ClassInstanceCreationExpression  */
  YYSYMBOL_FieldAccess = 129,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 130,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 131,         /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 132,             /* ArgumentList  */
  YYSYMBOL_ArrayCreationExpression = 133,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 134,                 /* DimExprs  */
  YYSYMBOL_DimExpr = 135,                  /* DimExpr  */
  YYSYMBOL_Expression = 136,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 137,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 138,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 139,             /* LeftHandSide  */
  YYSYMBOL_ConditionalExpression = 140,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 141,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 142, /* ConditionalAndExpression  */
  YYSYMBOL_InclusiveOrExpression = 143,    /* InclusiveOrExpression  */
  YYSYMBOL_ExclusiveOrExpression = 144,    /* ExclusiveOrExpression  */
  YYSYMBOL_AndExpression = 145,            /* AndExpression  */
  YYSYMBOL_EqualityExpression = 146,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 147,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 148,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 149,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 150, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 151,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 152,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 153,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 154, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_PostfixExpression = 155,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 156,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 157,  /* PostDecrementExpression  */
  YYSYMBOL_CastExpression = 158,           /* CastExpression  */
  YYSYMBOL_Block = 159,                    /* Block  */
  YYSYMBOL_BlockStatements = 160,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 161,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclarationStatement = 162, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 163, /* LocalVariableDeclaration  */
  YYSYMBOL_164_6 = 164,                    /* $@6  */
  YYSYMBOL_165_7 = 165,                    /* $@7  */
  YYSYMBOL_166_8 = 166,                    /* $@8  */
  YYSYMBOL_167_9 = 167,                    /* $@9  */
  YYSYMBOL_Statement = 168,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 169,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 170, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_EmptyStatement = 171,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 172,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 173, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 174,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 175,      /* StatementExpression  */
  YYSYMBOL_IfCountIncrement = 176,         /* IfCountIncrement  */
  YYSYMBOL_IfThenStatementSubRoutine = 177, /* IfThenStatementSubRoutine  */
  YYSYMBOL_IfThenStatement = 178,          /* IfThenStatement  */
  YYSYMBOL_IfThenThreeACSubRoutine = 179,  /* IfThenThreeACSubRoutine  */
  YYSYMBOL_IfThenElseStatement = 180,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 181, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_AssertStatement = 182,          /* AssertStatement  */
  YYSYMBOL_WhileStatementSubRoutine = 183, /* WhileStatementSubRoutine  */
  YYSYMBOL_184_10 = 184,                   /* $@10  */
  YYSYMBOL_WhileStatement = 185,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 186,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DoStatement = 187,              /* DoStatement  */
  YYSYMBOL_188_11 = 188,                   /* $@11  */
  YYSYMBOL_189_12 = 189,                   /* $@12  */
  YYSYMBOL_190_13 = 190,                   /* $@13  */
  YYSYMBOL_ForStatement = 191,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 192,    /* ForStatementNoShortIf  */
  YYSYMBOL_For1SubRoutine = 193,           /* For1SubRoutine  */
  YYSYMBOL_For2SubRoutine = 194,           /* For2SubRoutine  */
  YYSYMBOL_For3SubRoutine = 195,           /* For3SubRoutine  */
  YYSYMBOL_For4SubRoutine = 196,           /* For4SubRoutine  */
  YYSYMBOL_For5SubRoutine = 197,           /* For5SubRoutine  */
  YYSYMBOL_For6SubRoutine = 198,           /* For6SubRoutine  */
  YYSYMBOL_For7SubRoutine = 199,           /* For7SubRoutine  */
  YYSYMBOL_For8SubRoutine = 200,           /* For8SubRoutine  */
  YYSYMBOL_For9SubRoutine = 201,           /* For9SubRoutine  */
  YYSYMBOL_For10SubRoutine = 202,          /* For10SubRoutine  */
  YYSYMBOL_For11SubRoutine = 203,          /* For11SubRoutine  */
  YYSYMBOL_For12SubRoutine = 204,          /* For12SubRoutine  */
  YYSYMBOL_For13SubRoutine = 205,          /* For13SubRoutine  */
  YYSYMBOL_For14SubRoutine = 206,          /* For14SubRoutine  */
  YYSYMBOL_BasicForStatement = 207,        /* BasicForStatement  */
  YYSYMBOL_BasicForStatementNoShortIf = 208, /* BasicForStatementNoShortIf  */
  YYSYMBOL_ForInit = 209,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 210,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 211,  /* StatementExpressionList  */
  YYSYMBOL_CommaStatementExpressions = 212, /* CommaStatementExpressions  */
  YYSYMBOL_EnhancedForStatementSubRoutine = 213, /* EnhancedForStatementSubRoutine  */
  YYSYMBOL_EnhancedForStatement = 214,     /* EnhancedForStatement  */
  YYSYMBOL_EnhancedForStatementNoShortIf = 215, /* EnhancedForStatementNoShortIf  */
  YYSYMBOL_BreakStatement = 216,           /* BreakStatement  */
  YYSYMBOL_ContinueStatement = 217,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 218,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 219,           /* ThrowStatement  */
  YYSYMBOL_Int = 220,                      /* Int  */
  YYSYMBOL_Long = 221,                     /* Long  */
  YYSYMBOL_Byte = 222,                     /* Byte  */
  YYSYMBOL_Short = 223,                    /* Short  */
  YYSYMBOL_Char = 224,                     /* Char  */
  YYSYMBOL_Float = 225,                    /* Float  */
  YYSYMBOL_Double = 226,                   /* Double  */
  YYSYMBOL_Boolean = 227,                  /* Boolean  */
  YYSYMBOL_Var = 228,                      /* Var  */
  YYSYMBOL_Else = 229,                     /* Else  */
  YYSYMBOL_While = 230,                    /* While  */
  YYSYMBOL_For = 231,                      /* For  */
  YYSYMBOL_do_ = 232,                      /* do_  */
  YYSYMBOL_Break = 233,                    /* Break  */
  YYSYMBOL_Continue = 234,                 /* Continue  */
  YYSYMBOL_Void = 235,                     /* Void  */
  YYSYMBOL_New = 236,                      /* New  */
  YYSYMBOL_Return = 237,                   /* Return  */
  YYSYMBOL_Public = 238,                   /* Public  */
  YYSYMBOL_Private = 239,                  /* Private  */
  YYSYMBOL_Class = 240,                    /* Class  */
  YYSYMBOL_Static = 241,                   /* Static  */
  YYSYMBOL_Final = 242,                    /* Final  */
  YYSYMBOL_Assert = 243,                   /* Assert  */
  YYSYMBOL_This = 244,                     /* This  */
  YYSYMBOL_Throw = 245,                    /* Throw  */
  YYSYMBOL_Plus = 246,                     /* Plus  */
  YYSYMBOL_Minus = 247,                    /* Minus  */
  YYSYMBOL_Div = 248,                      /* Div  */
  YYSYMBOL_Asterik = 249,                  /* Asterik  */
  YYSYMBOL_Modulo = 250,                   /* Modulo  */
  YYSYMBOL_Increment = 251,                /* Increment  */
  YYSYMBOL_Decrement = 252,                /* Decrement  */
  YYSYMBOL_Geq = 253,                      /* Geq  */
  YYSYMBOL_Leq = 254,                      /* Leq  */
  YYSYMBOL_Gt = 255,                       /* Gt  */
  YYSYMBOL_Lt = 256,                       /* Lt  */
  YYSYMBOL_Neq = 257,                      /* Neq  */
  YYSYMBOL_Deq = 258,                      /* Deq  */
  YYSYMBOL_Bitwise_and = 259,              /* Bitwise_and  */
  YYSYMBOL_Bitwise_or = 260,               /* Bitwise_or  */
  YYSYMBOL_Bitwise_xor = 261,              /* Bitwise_xor  */
  YYSYMBOL_Bitwise_complement = 262,       /* Bitwise_complement  */
  YYSYMBOL_Left_shift = 263,               /* Left_shift  */
  YYSYMBOL_Right_shift = 264,              /* Right_shift  */
  YYSYMBOL_Unsigned_right_shift = 265,     /* Unsigned_right_shift  */
  YYSYMBOL_And = 266,                      /* And  */
  YYSYMBOL_Or = 267,                       /* Or  */
  YYSYMBOL_Not = 268,                      /* Not  */
  YYSYMBOL_AssignmentOperator = 269,       /* AssignmentOperator  */
  YYSYMBOL_Assign = 270,                   /* Assign  */
  YYSYMBOL_Colon = 271,                    /* Colon  */
  YYSYMBOL_Qm = 272,                       /* Qm  */
  YYSYMBOL_Lparen = 273,                   /* Lparen  */
  YYSYMBOL_Rparen = 274,                   /* Rparen  */
  YYSYMBOL_Lcurly = 275,                   /* Lcurly  */
  YYSYMBOL_Rcurly = 276,                   /* Rcurly  */
  YYSYMBOL_Lsquare = 277,                  /* Lsquare  */
  YYSYMBOL_Rsquare = 278,                  /* Rsquare  */
  YYSYMBOL_Semicolon = 279,                /* Semicolon  */
  YYSYMBOL_Comma = 280,                    /* Comma  */
  YYSYMBOL_Dot = 281,                      /* Dot  */
  YYSYMBOL_Char_literal = 282,             /* Char_literal  */
  YYSYMBOL_Boolean_literal = 283,          /* Boolean_literal  */
  YYSYMBOL_Null_literal = 284,             /* Null_literal  */
  YYSYMBOL_Integer_literal = 285,          /* Integer_literal  */
  YYSYMBOL_Fp_literal = 286,               /* Fp_literal  */
  YYSYMBOL_String = 287,                   /* String  */
  YYSYMBOL_Text_block = 288,               /* Text_block  */
  YYSYMBOL_Identifier = 289,               /* Identifier  */
  YYSYMBOL_endoffile = 290                 /* endoffile  */
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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2645

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  215
/* YYNRULES -- Number of rules.  */
#define YYNRULES  371
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  560

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


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
      75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   332,   332,   339,   343,   344,   348,   367,   377,   378,
     379,   380,   381,   382,   383,   393,   400,   401,   405,   406,
     410,   411,   414,   415,   416,   417,   418,   421,   422,   430,
     431,   435,   439,   442,   448,   452,   470,   473,   482,   491,
     494,   501,   504,   507,   510,   522,   522,   523,   523,   540,
     541,   545,   546,   550,   551,   552,   553,   558,   559,   569,
     574,   575,   579,   580,   585,   598,   612,   619,   629,   630,
     637,   637,   666,   675,   682,   689,   745,   755,   763,   774,
     779,   785,   806,   830,   834,   838,   838,   854,   854,   883,
     884,   885,   886,   890,   901,   919,   931,   937,   948,   957,
     966,  1005,  1006,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1022,  1044,  1066,  1116,  1136,  1191,  1226,  1279,  1359,  1366,
    1367,  1376,  1388,  1415,  1431,  1462,  1467,  1475,  1497,  1500,
    1502,  1506,  1543,  1579,  1590,  1591,  1594,  1596,  1628,  1629,
    1637,  1638,  1646,  1647,  1655,  1656,  1664,  1665,  1673,  1678,
    1684,  1692,  1697,  1703,  1709,  1715,  1725,  1730,  1738,  1746,
    1757,  1762,  1787,  1814,  1819,  1844,  1869,  1896,  1897,  1898,
    1912,  1929,  1936,  1951,  1971,  1987,  2008,  2013,  2030,  2045,
    2048,  2052,  2058,  2059,  2062,  2077,  2099,  2116,  2138,  2149,
    2163,  2164,  2167,  2168,  2172,  2173,  2174,  2177,  2180,  2181,
    2181,  2182,  2182,  2183,  2183,  2183,  2187,  2188,  2189,  2190,
    2191,  2192,  2195,  2196,  2197,  2198,  2199,  2202,  2203,  2204,
    2205,  2206,  2207,  2208,  2210,  2212,  2222,  2225,  2228,  2231,
    2234,  2235,  2236,  2237,  2238,  2239,  2240,  2244,  2249,  2260,
    2271,  2280,  2288,  2296,  2306,  2306,  2317,  2326,  2336,  2338,
    2338,  2336,  2347,  2348,  2351,  2352,  2355,  2364,  2374,  2383,
    2392,  2399,  2408,  2415,  2424,  2433,  2441,  2450,  2458,  2466,
    2475,  2485,  2494,  2503,  2513,  2523,  2533,  2543,  2556,  2565,
    2573,  2580,  2590,  2600,  2610,  2620,  2632,  2633,  2636,  2639,
    2640,  2643,  2644,  2648,  2651,  2654,  2657,  2665,  2670,  2683,
    2695,  2727,  2730,  2733,  2736,  2739,  2742,  2745,  2748,  2751,
    2757,  2760,  2768,  2776,  2784,  2787,  2790,  2793,  2796,  2799,
    2802,  2805,  2808,  2811,  2814,  2817,  2829,  2866,  2869,  2872,
    2875,  2878,  2881,  2884,  2887,  2890,  2893,  2896,  2899,  2902,
    2905,  2908,  2911,  2914,  2917,  2920,  2923,  2926,  2929,  2932,
    2935,  2940,  2942,  2945,  2948,  2951,  2954,  2957,  2960,  2963,
    2966,  2969,  2972,  2977,  2985,  2998,  3006,  3014,  3022,  3030,
    3038,  3048
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
  "ASSIGNMENT", "COLON", "QM", "LPAREN", "RPAREN", "LCURLY", "RCURLY",
  "LSQUARE", "RSQUARE", "SEMICOLON", "COMMA", "DOT", "CHAR_LITERAL",
  "BOOLEAN_LITERAL", "NULL_LITERAL", "INTEGER_LITERAL", "FP_LITERAL",
  "STRING", "TEXT_BLOCK", "IDENTIFIER", "THIS", "THROW", "EOF_", "ASTERIK",
  "DO", "PRINT", "ASSIGN", "$accept", "Program", "CompilationUnit",
  "ClassOrInterfaceDeclarations", "ClassOrInterfaceDeclaration",
  "ScopeIncrement", "Literal", "UnannTypeSubRoutine", "UnannType",
  "PrimitiveType", "NumericType", "IntegralType", "FloatingPointType",
  "ReferenceType", "ClassOrInterfaceType", "ArrayType", "Dims", "TypeName",
  "ModifiersUnannTypeSubRoutine", "Modifiers", "Modifier",
  "ClassDeclaration", "$@1", "$@2", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "VariableDeclaratorList", "VariableDeclarator", "VariableDeclaratorId",
  "VariableInitializer", "MethodDeclaration", "$@3", "MethodHeader",
  "DeclaratorSubRoutine", "Declarator", "FormalParameterList",
  "FormalParameter", "MethodBody", "StaticInitializer",
  "ConstructorDeclaration", "$@4", "$@5", "ConstructorBody",
  "ExplicitConstructorInvocation", "ArrayInitializer",
  "VariableInitializerList", "Primary", "PrimaryNoNewArray",
  "ClassInstanceCreationExpressionSubRoutine",
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
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "IfCountIncrement", "IfThenStatementSubRoutine",
  "IfThenStatement", "IfThenThreeACSubRoutine", "IfThenElseStatement",
  "IfThenElseStatementNoShortIf", "AssertStatement",
  "WhileStatementSubRoutine", "$@10", "WhileStatement",
  "WhileStatementNoShortIf", "DoStatement", "$@11", "$@12", "$@13",
  "ForStatement", "ForStatementNoShortIf", "For1SubRoutine",
  "For2SubRoutine", "For3SubRoutine", "For4SubRoutine", "For5SubRoutine",
  "For6SubRoutine", "For7SubRoutine", "For8SubRoutine", "For9SubRoutine",
  "For10SubRoutine", "For11SubRoutine", "For12SubRoutine",
  "For13SubRoutine", "For14SubRoutine", "BasicForStatement",
  "BasicForStatementNoShortIf", "ForInit", "ForUpdate",
  "StatementExpressionList", "CommaStatementExpressions",
  "EnhancedForStatementSubRoutine", "EnhancedForStatement",
  "EnhancedForStatementNoShortIf", "BreakStatement", "ContinueStatement",
  "ReturnStatement", "ThrowStatement", "Int", "Long", "Byte", "Short",
  "Char", "Float", "Double", "Boolean", "Var", "Else", "While", "For",
  "do_", "Break", "Continue", "Void", "New", "Return", "Public", "Private",
  "Class", "Static", "Final", "Assert", "This", "Throw", "Plus", "Minus",
  "Div", "Asterik", "Modulo", "Increment", "Decrement", "Geq", "Leq", "Gt",
  "Lt", "Neq", "Deq", "Bitwise_and", "Bitwise_or", "Bitwise_xor",
  "Bitwise_complement", "Left_shift", "Right_shift",
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

#define YYPACT_NINF (-410)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-237)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     344,  -410,  -410,  -410,  -410,  -410,    24,   -12,   344,  -410,
     344,  -410,  -410,  -410,  -410,   -21,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,   -21,  -410,  -410,  -410,    17,    17,  -410,
    -410,  1018,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,   -21,  -410,    20,  -410,  -410,  -410,  -410,
    -410,  -410,    53,   -21,   635,  -410,  1018,  -410,  -410,  -410,
    -410,  -410,   385,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,   -21,    17,  -410,  -410,    44,
     164,  -410,   -27,  -410,    44,  -410,  -410,    59,  -410,  -410,
     -21,   164,  -410,  -410,  -410,   -21,  -410,  -410,    17,  -410,
     -21,    61,  -410,   742,  -410,  -410,    17,  -410,    44,  -410,
    2046,  -410,  -410,  -410,  -410,  -410,   -21,  -410,  2363,    59,
    -410,    20,  -410,  -410,    17,  -410,  -410,  -410,    20,  -410,
    -410,   834,   -21,  -410,  2046,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,    58,  -410,  -410,   -21,   286,
      13,    20,  2391,    98,   -14,   -13,   116,  -410,  -410,     4,
    -410,  -410,  -410,  -410,  -410,  2046,  -410,  -410,    81,  -410,
    -410,  -410,  -410,  -410,    81,   136,    99,  -410,  2209,  -410,
    -410,    99,  -410,  -410,  -410,    81,  2499,  2499,  2499,  2419,
    2209,  2419,  2209,  2209,  2209,  2209,  2209,  2209,  2209,  -410,
      99,  -410,  -410,  -410,  -410,  -410,  -410,  -410,    44,  -410,
      81,    81,   742,  2419,   173,  2475,  -410,  2475,  1085,  1085,
    2475,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
     104,  -410,  -410,  -410,  -410,  -410,   172,  -410,  -410,    13,
    -410,  -410,  -410,  -410,  -410,  -410,    82,   121,   130,   131,
     141,   202,   239,   186,   217,     2,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  2475,  2475,  2475,  2475,  2118,  2261,
    -410,  -410,  -410,  -410,    20,  2046,  2046,    44,  -410,  2475,
     124,  -410,  -410,  2391,  2447,  -410,  -410,   -21,  2475,    61,
    -410,  -410,  -410,  2475,  2475,  -410,  -410,  -410,  -410,    44,
    -410,   150,  -410,  2209,  2499,   124,    99,  -410,  -410,    99,
    -410,    99,  -410,  -410,  -410,  -410,    81,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  2209,   -21,    44,  2190,  2209,
    -410,  -410,    20,    85,   126,    81,  -410,   742,   198,    81,
      81,    76,   126,  -410,  -410,    76,   126,    99,  -410,  2209,
    2475,  -410,  -410,  2475,  2475,  -410,  2475,  -410,  2475,  -410,
    2475,  -410,  2475,  -410,  -410,  2475,  2475,  -410,  -410,  -410,
    -410,  2475,  2475,  2475,  2475,  -410,  -410,  -410,  2475,  2475,
    2475,  2475,  2475,  -410,  -410,  -410,  2475,  2475,  2475,   150,
    -410,  -410,  -410,  -410,    70,    99,    55,  -410,    90,  -410,
     182,  2046,  -410,  -410,  2391,   166,    61,  -410,    59,    44,
      59,  -410,  2475,  -410,  -410,  2475,  2209,  -410,    99,  -410,
    -410,  1323,  -410,  -410,  -410,  -410,  -410,   124,  2475,   104,
      81,  -410,   231,  -410,   236,    20,  -410,  2475,    20,  -410,
    -410,   -21,  -410,  -410,  -410,  -410,  -410,   121,   104,   130,
     131,   141,   202,   239,   239,   186,   186,   186,   186,   217,
     217,   217,     2,     2,  -410,  -410,  -410,  2475,  2527,  -410,
    2312,  -410,  -410,    61,  -410,  -410,  -410,  -410,  2391,  -410,
    -410,  -410,  -410,   233,   248,  -410,  2209,  -410,    99,  -410,
    -410,  2209,  2209,  2209,  2209,  2209,  2209,  2209,  2209,  -410,
      99,  -410,   104,  -410,   124,  -410,  2475,  -410,  -410,  -410,
      59,   124,   -21,  2475,  -410,  -410,  -410,  -410,  -410,    61,
    -410,  -410,  -410,  -410,  2209,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  2209,  2209,  -410,  -410,    44,  -410,   124,
    -410,  -410,  -410,  -410,  -410,  2475,  -410,    99,    81,  -410
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   319,   320,   321,   322,   323,     0,     0,     3,     4,
       0,    39,     6,    41,    42,     0,    43,    44,     1,   371,
       2,     5,    40,     0,   370,    47,    45,     0,     0,   356,
      48,     0,    46,   301,   302,   303,   305,   304,   306,   307,
     308,   316,   357,     0,    15,    16,    18,    20,    21,    17,
      29,    30,    31,     0,     0,    59,     0,    52,    53,    57,
      58,    70,     0,    87,    55,    54,    56,    24,    25,    22,
      23,    26,    27,    28,    19,     0,    43,     7,    50,    36,
       0,    63,    65,    73,    67,   358,    32,     0,   362,    33,
       0,     0,    72,    38,    85,     0,    51,    49,     0,   355,
       0,     0,    80,     0,    77,    36,     0,    75,     0,    84,
     237,   354,    76,   360,   361,    61,     0,   351,     0,     0,
     359,    35,    37,    60,     0,    74,    71,    83,    81,    67,
      78,     0,     0,    88,   237,   309,   312,   311,   314,   315,
     317,   318,   324,   332,   333,   363,   364,   365,   366,   367,
     368,   369,   325,   326,   313,     0,   194,   103,     0,   133,
       0,   101,     0,   106,   107,   108,   109,   102,   230,     0,
     231,   232,   233,   234,   217,   237,   193,   195,     0,   196,
     206,   218,   207,   219,     0,     0,     0,   208,   237,   209,
     220,     0,   210,   225,   211,     0,     0,     0,     0,     0,
     237,     0,   237,   237,   237,   237,   237,   237,   237,   252,
       0,   253,   221,   222,   223,   224,   199,   244,     0,   248,
       0,     0,     0,     0,   201,     0,   104,     0,     0,     0,
       0,   190,   226,    10,    13,    14,     8,     9,    11,    12,
      36,    62,   327,   328,   343,   349,   181,    64,    69,   180,
     106,   109,    68,   128,   130,   129,   136,   138,   140,   142,
     144,   146,   148,   151,   156,   160,   163,   167,   168,   171,
     176,   182,   183,   179,     0,     0,     0,     0,     0,     0,
      66,    34,    86,    79,    82,   237,   237,   104,    92,     0,
     198,   185,   187,     0,     0,   184,   186,     0,     0,     0,
     121,   111,   350,     0,     0,   192,   191,   197,   229,     0,
       7,   133,   241,   237,     0,   289,     0,   288,   266,     0,
     263,     0,   264,   256,   258,   272,     0,   259,   270,   271,
     273,   274,   275,   276,   277,   237,     0,     0,     0,   237,
     296,   297,     0,     0,    31,     0,   299,     0,     0,     0,
       0,   173,   172,   107,   108,   175,   174,     0,   352,   237,
       0,   348,   353,     0,     0,   347,     0,   341,     0,   342,
       0,   340,     0,   338,   339,     0,     0,   334,   335,   336,
     337,     0,     0,     0,     0,   344,   345,   346,     0,     0,
       0,     0,     0,   329,   331,   330,     0,     0,     0,   181,
     169,   170,   177,   178,     0,     0,   181,   100,     0,    96,
       0,   237,    91,    89,     0,     0,     0,   116,     0,   113,
       0,   112,     0,   131,   132,     0,   237,   246,     0,   261,
     290,     0,   269,   265,   267,   257,   294,   200,     0,   287,
       0,   286,   201,   260,     0,   123,   125,     0,   124,   110,
     298,     0,   204,   243,   300,   105,   227,   139,     0,   141,
     143,   145,   147,   150,   149,   155,   154,   153,   152,   157,
     158,   159,   161,   162,   165,   164,   166,     0,     0,    95,
       0,    98,    90,     0,    93,   118,   117,   114,     0,   115,
     122,   238,   239,     0,   206,   213,   237,   214,     0,   215,
     216,   237,   237,   237,   237,   237,   237,   237,   237,   254,
       0,   255,    36,   268,   292,   245,     0,   262,   249,   126,
       0,   202,     0,     0,   188,   189,    99,    97,    94,     0,
     119,   310,   240,   242,   237,   280,   278,   279,   281,   282,
     283,   284,   285,   237,   237,   291,   293,     0,   127,   205,
     137,   120,   247,   295,   228,     0,   250,     0,     0,   251
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -410,  -410,  -410,  -410,    89,   -47,  -410,   -19,   214,  -195,
    -410,  -410,  -410,     5,    63,  -410,   -43,    37,  -410,    11,
      15,    21,  -410,  -410,   258,  -410,   234,  -410,  -410,   -52,
     171,   -78,  -273,  -410,  -410,  -410,  -410,    -3,  -410,   160,
    -410,  -410,  -410,  -410,  -410,   170,  -410,  -410,  -410,   744,
    -410,  -410,   804,   407,  1423,   925,  -280,  -410,   -48,  -283,
     622,  -410,   465,  -410,  -226,  -410,   -64,   -66,   -67,   -68,
     -65,  -127,  -104,  -155,  -138,  -219,   985,  1162,  -173,  -410,
    1336,  1435,  -410,   -10,  -124,  -168,  -410,   -30,  -410,  -410,
    -410,  -410,  1235,  2101,   118,  -410,  -410,  -410,  -410,  -179,
    -410,  -410,  -410,   698,  -410,  -410,  -410,   875,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  1053,  -410,  1111,  1180,  1349,  1401,  1421,  1455,
    1489,  -410,  -410,  -410,  -183,    -6,  -189,  1504,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,   -11,  -410,  -125,  -410,  -410,  -410,  -410,   279,
    -410,  -410,  -410,  -410,    16,    34,   -29,  -410,   200,  -410,
    -253,  -244,  -410,  -410,  -410,   -96,   -35,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,   174,  -409,  -410,   361,   408,   -24,
      66,   168,  -114,   -57,    57,  -151,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,   -15,  -410
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,     7,     8,   156,   110,   157,   158,    44,    45,
      46,    47,    48,    49,    50,    51,    89,   311,    53,    10,
      11,    12,    28,    27,    30,    56,    57,    58,    59,    80,
      81,    82,   247,    60,    98,    61,    62,    63,   101,   102,
     126,    64,    65,   124,   106,   133,   285,   248,   408,   249,
     161,   162,   250,   164,   165,   251,   299,   167,   445,   446,
     300,   253,   168,   169,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   174,   175,   176,   177,   178,   336,   347,
     348,   522,   179,   493,   180,   181,   182,   495,   183,   184,
     185,   186,   187,   188,   189,   497,   190,   191,   337,   192,
     499,   193,   339,   547,   557,   194,   500,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   509,   440,   316,   317,   430,   210,   211,   511,
     212,   213,   214,   215,    67,    68,    69,    70,    71,    72,
      73,    74,   216,   532,   217,   218,   219,   220,   221,    75,
     222,   223,    13,    14,    15,    16,    17,   225,   226,   227,
     274,   275,   396,   397,   398,   228,   229,   381,   382,   383,
     384,   375,   376,   372,   368,   370,   276,   388,   389,   390,
     366,   363,   277,   303,   118,   359,   364,   278,   104,    77,
      78,   360,   121,   232,   116,    90,   233,   234,   235,   236,
     237,   238,   239,   105,    20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    91,    86,    31,    31,   280,   407,   305,    26,   297,
     286,   391,    43,   416,   319,   321,    79,   315,   315,   315,
     392,    66,   128,   115,    18,    22,    23,   342,    84,    85,
     516,   393,   394,   103,   123,  -134,  -135,    43,    84,    79,
      83,    79,    54,   100,   143,   144,    66,    24,   117,   523,
      92,    94,    55,   302,   284,   400,   401,   402,   403,    19,
     108,  -134,  -135,   291,   295,    76,   109,    54,    52,    22,
      23,    29,   107,    88,   395,   122,    85,    55,   281,   117,
     108,   224,   134,   404,   132,   129,   143,   144,   127,     9,
      76,    52,   125,    52,   279,   240,   111,    21,   297,    52,
     134,   129,   103,   544,  -133,   224,   290,   111,   -31,    85,
     289,    85,   100,    88,    99,    88,   120,   129,   305,   240,
     114,   307,    97,    99,   292,   296,    85,   308,   111,   361,
    -133,   428,    85,   362,   483,   315,    88,   111,   314,   113,
      52,    85,   324,   129,   327,    42,   224,   159,   309,   114,
     291,  -236,    99,   295,   358,   246,  -236,  -236,   131,   315,
     240,   411,   519,   340,   341,   519,   346,   365,    52,  -235,
     367,   159,   369,   240,  -235,  -235,   231,   474,   475,   476,
     371,   143,   144,   114,  -203,   240,    88,   240,   240,   240,
     240,   240,   240,   240,   -44,   -44,   -44,   -44,   -44,   246,
     288,   297,   111,   143,   144,   297,    85,   526,   529,   135,
      88,   292,   159,    87,   296,   291,   391,   391,   391,   485,
      87,  -133,   113,   114,   111,   392,   392,   392,    85,   385,
     386,   387,    88,   469,   470,   471,   246,    42,   246,   373,
     374,   306,  -203,   305,   242,   243,   531,  -133,   463,   464,
     119,   137,   514,   472,   473,   279,   224,   224,   524,   344,
     246,  -212,   246,   426,   246,   351,   355,   246,    93,   435,
     240,   240,   377,   378,   379,   380,   292,   465,   466,   467,
     468,   443,   419,   405,   437,   343,    32,   241,   450,    87,
      96,   283,   453,   454,   282,   448,   119,   550,   240,   457,
     459,   460,   461,   291,   487,   525,   489,   462,   439,   442,
     291,   399,   399,   399,   399,   406,   246,   143,   144,   518,
     240,   129,   159,   159,   240,   545,   246,   294,   451,   298,
     246,   246,   441,    95,   287,   246,   410,   452,   111,     0,
     246,   246,    85,   304,   240,   409,    88,     0,     0,     0,
       0,   412,   413,     0,   -31,     0,   422,     0,     0,     0,
       0,    86,     0,     0,   292,     1,     2,     3,     4,     5,
       0,   292,   431,     0,     0,   159,     0,     0,     0,     0,
       0,     0,   224,   517,    52,     0,     0,     0,    33,    34,
      35,    36,    37,    38,    39,    40,   240,   246,     0,   521,
     399,   246,     0,   399,     0,   399,   548,   399,     0,   399,
       5,   512,   399,   399,     0,     0,     0,     0,   399,   399,
     399,   399,     0,     0,     0,   399,   399,   399,   399,   399,
       0,     0,     0,   399,   399,   399,   129,     0,    99,     0,
     112,     0,     0,     0,     0,   112,     0,     0,   159,     0,
       0,   246,   119,    24,     0,     0,   279,     0,     0,   246,
       0,     0,   246,     0,     0,   480,     0,     0,     0,   112,
     549,   230,     0,   422,   479,   246,   481,   482,     0,     0,
       0,   512,     0,     0,   246,     0,   512,   512,   512,   512,
     512,   512,   512,   512,     0,   230,     0,     0,     0,     0,
       0,   559,     0,     0,     0,     0,     0,   129,     0,   130,
     447,   447,     0,     0,   399,   399,     0,   246,     0,   512,
     293,     0,     0,     0,     0,   246,     0,     0,   512,   512,
       0,     0,     0,     0,     0,     0,   230,     0,     0,     0,
     422,     0,     0,     0,   494,     0,   527,     0,     0,   230,
       0,     0,     0,   246,     0,     0,     0,   230,   230,   230,
     399,   230,     0,   230,   230,   230,   230,   230,   230,   230,
     301,   431,    87,     0,   294,     0,     0,     0,     0,   338,
       0,     0,     0,   254,     0,     0,   422,     0,     0,   230,
     230,     0,   246,     0,   310,     0,     0,     0,     0,   313,
       0,     0,     0,     0,   318,   320,   322,   293,     0,     0,
       0,     0,     0,   447,   494,     0,   447,     0,   335,   494,
     494,   494,   494,   494,   494,   494,   494,   254,     0,     0,
       0,     0,     0,     0,     0,   353,   353,     0,    33,    34,
      35,    36,    37,    38,    39,    40,   230,   230,   414,     0,
       0,     0,   494,    41,     0,     0,     1,     2,     3,     4,
       5,   494,   494,     0,   254,     0,   254,     0,     0,     0,
     425,     0,   293,     0,   230,   230,     0,     0,     0,     0,
       0,   353,   353,   353,   353,     0,     0,     0,   254,     0,
     254,     0,   254,     0,     0,   254,   230,     0,   438,   230,
     230,   417,     0,    24,   449,     0,     0,   421,     0,     0,
       0,     0,   293,     0,     0,     0,   293,     0,     0,     0,
     230,     0,   429,     0,   432,     0,     0,   433,     0,   434,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     252,     0,     0,   254,   254,    33,    34,    35,    36,    37,
      38,    39,    40,     0,   254,     0,     0,     0,   254,   254,
     293,     0,     0,   254,     0,   455,     0,   293,   254,   254,
     353,     0,   230,   353,     0,   353,     0,   353,     0,   353,
     488,     0,   353,   353,     0,     0,     0,   230,   353,   353,
     353,   353,   230,     0,     0,   353,   353,   353,   353,   353,
       0,     0,     0,   353,   353,   353,     0,     0,     0,     0,
      24,     0,   477,   478,     0,     0,     0,     0,     0,     0,
       0,   323,   484,   326,   486,   254,     0,     0,     0,   254,
       0,     0,     0,     0,     0,     0,   513,    33,    34,    35,
      36,    37,    38,    39,    40,   345,     0,   349,     0,   350,
       0,     0,   357,     0,   160,     0,     0,   230,     0,     5,
       0,     0,   230,   230,   230,   230,   230,   230,   230,   230,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   254,
       0,     0,     0,     0,   353,   353,     0,   254,     0,     0,
     254,   528,     0,     0,     0,   230,   530,     0,     0,     0,
     357,   252,    24,   254,   230,   230,   534,     0,   555,     0,
       0,   415,   254,     0,   163,     0,   418,     0,   543,   160,
     420,     0,     0,     0,     0,   423,   424,     0,     0,     0,
     353,     0,   160,     0,     0,     0,     0,   551,   163,     0,
     160,   160,   160,     0,   160,   254,   160,   160,   160,   160,
     160,   160,   160,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,     0,   352,   356,     0,     0,     0,     0,     0,   163,
       0,   254,   418,     0,     0,     0,   458,     0,     0,     0,
       0,     0,   163,     0,     0,     0,     0,     0,     0,     0,
     163,   163,   163,     0,   163,     0,   163,   163,   163,   163,
     163,   163,   163,     0,     0,     0,     0,     0,     0,     0,
     254,    33,    34,    35,    36,    37,    38,    39,    40,   160,
     160,     0,     0,     0,     0,   166,    41,     0,     0,     1,
       2,     3,     4,     5,   490,     0,     0,   491,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   160,   166,
     515,     0,     0,     0,     0,     0,     0,     0,     0,   520,
       0,     0,    29,    42,     0,     0,     0,     0,     0,   160,
       0,     0,   160,   160,     0,     0,    24,     0,     0,   163,
     163,     0,     0,     0,     0,   170,     0,     0,     0,     0,
     166,     0,   252,   160,   140,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     0,     0,     0,   163,   163,   170,
       0,   166,   166,   166,   496,   166,     0,   166,   166,   166,
     166,   166,   166,   166,     0,     0,     0,   111,   546,   163,
       0,     0,   163,   163,     0,     0,   145,   146,   147,   148,
     149,   150,   151,    24,   152,   160,     0,     0,     0,   155,
     170,     0,     0,   163,     0,     0,     0,     0,     0,     0,
     160,     0,     0,   170,     0,   160,     0,   556,     0,     0,
       0,   170,   170,   170,     0,   170,     0,   170,   170,   170,
     170,   170,   170,   170,   496,     0,     0,     0,     0,   496,
     496,   496,   496,   496,   496,   496,   496,     0,     0,     0,
     166,   166,     0,     0,     0,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,   496,     0,     0,   163,     0,     0,   166,   166,
     160,   496,   496,     0,     0,   160,   160,   160,   160,   160,
     160,   160,   160,     0,     0,     0,     0,     0,     0,     0,
     166,     0,     0,   166,   166,     0,     0,     0,     0,     0,
     170,   170,   171,     0,     0,     0,     0,     0,   160,     0,
       0,     0,     0,     0,   166,     0,     0,   160,   160,     0,
       0,     0,     0,     0,     0,     0,   171,     0,   170,   170,
     163,   498,     0,     0,     0,   163,   163,   163,   163,   163,
     163,   163,   163,     0,     0,     0,     0,     0,     0,     0,
     170,     0,     0,   170,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   166,   171,   163,     0,
       0,     0,   140,     0,   170,     0,     0,   163,   163,     0,
     171,   166,     0,     0,   143,   144,   166,     0,   171,   171,
     171,     0,   171,     0,   171,   171,   171,   171,   171,   171,
     171,   498,     0,     0,     0,   111,   498,   498,   498,   498,
     498,   498,   498,   498,   145,   146,   147,   148,   149,   150,
     151,    24,   152,     0,     0,     0,   170,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   498,
       0,   170,     0,     0,     0,     0,   170,     0,   498,   498,
       0,   166,     0,   312,     0,     0,   166,   166,   166,   166,
     166,   166,   166,   166,     0,   325,     0,   328,   329,   330,
     331,   332,   333,   334,     0,     0,   172,   171,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
       0,     0,     0,     0,     0,     0,     0,     0,   166,   166,
     172,     0,     0,     0,     0,   171,   171,     0,     0,   501,
       0,   170,     0,     0,     0,     0,   170,   170,   170,   170,
     170,   170,   170,   170,     0,     0,     0,   171,     0,     0,
     171,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,     0,     0,     0,     0,     0,     0,     0,   170,
       0,   171,     0,     0,   172,     0,     0,     0,   170,   170,
       0,     0,   172,   172,   172,     0,   172,   502,   172,   172,
     172,   172,   172,   172,   172,   173,     0,     0,   427,   501,
       0,     0,     0,     0,   501,   501,   501,   501,   501,   501,
     501,   501,     0,     0,     0,     0,     0,     0,     0,   173,
     436,     0,     0,   171,   444,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   501,   171,     0,
       0,     0,     0,   171,   456,     0,   501,   501,     0,     0,
       0,     0,     0,     0,     0,     0,   503,   502,     0,     0,
     173,     0,   502,   502,   502,   502,   502,   502,   502,   502,
       0,   172,   172,   173,     0,     0,     0,     0,     0,     0,
       0,   173,   173,   173,     0,   173,     0,   173,   173,   173,
     173,   173,   173,   173,     0,   502,     0,     0,     0,   172,
     172,   354,   354,     0,   502,   502,     0,     0,   171,     0,
       0,   492,     0,   171,   171,   171,   171,   171,   171,   171,
     171,   172,     0,     0,   172,   172,   503,     0,     0,     0,
       0,   503,   503,   503,   503,   503,   503,   503,   503,     0,
       0,     0,     0,     0,     0,   172,   171,   354,   354,   354,
     354,     0,     0,     0,     0,   171,   171,     0,     0,     0,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
     173,   173,     0,   503,   503,     0,     0,     0,     0,     0,
       0,   312,     0,     0,     0,     0,   325,   328,   329,   330,
     331,   332,   333,   334,     0,     0,     0,   172,   173,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,     0,     0,     0,     0,   172,     0,   427,
     173,     0,     0,   173,   173,   504,     0,     0,   436,   456,
       0,     0,     0,     0,     0,     0,   354,     0,     0,   354,
       0,   354,     0,   354,   173,   354,     0,     0,   354,   354,
       0,     0,     0,     0,   354,   354,   354,   354,     0,     0,
       0,   354,   354,   354,   354,   354,     0,     0,     0,   354,
     354,   354,     0,     0,     0,     0,     0,   505,     0,     0,
       0,     0,   172,     0,     0,     0,     0,   172,   172,   172,
     172,   172,   172,   172,   172,   504,   173,   506,     0,     0,
     504,   504,   504,   504,   504,   504,   504,   504,     0,     0,
       0,   173,     0,     0,     0,     0,   173,     0,     0,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,   172,
     172,   507,     0,   504,     0,     0,     0,     0,     0,     0,
       0,     0,   504,   504,     0,     0,     0,   505,     0,     0,
     354,   354,   505,   505,   505,   505,   505,   505,   505,   505,
       0,     0,     0,     0,     0,   508,     0,   506,     0,     0,
       0,     0,   506,   506,   506,   506,   506,   506,   506,   506,
     510,   173,     0,     0,     0,   505,   173,   173,   173,   173,
     173,   173,   173,   173,   505,   505,   354,     0,     0,     0,
       0,   507,     0,     0,     0,   506,   507,   507,   507,   507,
     507,   507,   507,   507,   506,   506,     0,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   173,
       0,     0,     0,     0,     0,   508,     0,     0,     0,   507,
     508,   508,   508,   508,   508,   508,   508,   508,   507,   507,
     510,     0,     0,     0,     0,   510,   510,   510,   510,   510,
     510,   510,   510,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   508,     0,     0,     0,     0,     0,     0,
       0,     0,   508,   508,     0,     0,     0,     0,   510,     0,
       0,     0,     0,     0,     0,     0,     0,   510,   510,    33,
      34,    35,    36,    37,    38,    39,    40,   135,     0,     0,
     136,   137,   138,   139,     0,   140,   141,     1,     2,     3,
       4,     5,   142,     0,     0,     0,     0,   143,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
      29,    42,     0,     0,   113,     0,     0,   145,   146,   147,
     148,   149,   150,   151,    24,   152,   153,     0,     0,   154,
     155,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,   140,     0,     0,
       0,     0,     0,     0,     0,   242,   243,     0,     0,   143,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,     0,     0,     0,     0,     0,   245,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,   148,   149,   150,   151,    24,   152,     0,     0,
       0,     0,   155,    33,    34,    35,    36,    37,    38,    39,
      40,   135,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,   143,   144,   136,   137,   138,   139,     0,   140,   141,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
     143,   144,   111,     0,     0,     0,     0,     0,   113,     0,
       0,   145,   146,   147,   148,   149,   150,   151,    24,   152,
       0,   111,     0,    29,   155,     0,     0,   113,     0,     0,
     145,   146,   147,   148,   149,   150,   151,    24,   152,   153,
     140,     0,   154,   155,     0,     0,     0,     0,   242,   243,
       0,     0,   143,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,     0,     0,     0,     0,   245,
       0,     0,     0,   111,     0,    29,    42,     0,     0,     0,
     114,     0,   145,   146,   147,   148,   149,   150,   151,    24,
     152,   140,     0,     0,     0,   155,     0,     0,     0,   242,
     243,     0,     0,   143,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
     245,     0,     0,     0,   111,     0,    29,    42,     0,     0,
       0,     0,     0,   145,   146,   147,   148,   149,   150,   151,
      24,   152,   140,     0,     0,     0,   155,     0,     0,     0,
     242,   243,     0,     0,   143,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
     140,   245,     0,     0,     0,   111,     0,    29,   242,   243,
       0,     0,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    24,   152,   244,     0,     0,     0,   155,   140,   245,
       0,     0,     0,   111,    99,     0,   242,   243,     0,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    24,
     152,   244,     0,     0,     0,   155,   140,   245,     0,     0,
       0,   111,     0,     0,   242,   243,     0,   113,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    24,   152,   244,
       0,     0,     0,   155,   140,   245,     0,     0,     0,   111,
       0,     0,   242,   243,   120,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    24,   152,   244,   140,     0,
       0,   155,     0,   245,     0,     0,     0,   111,     0,     0,
     143,   144,     0,     0,     0,     0,   145,   146,   147,   148,
     149,   150,   151,    24,   152,     0,   140,     0,     0,   155,
       0,   111,    99,     0,     0,     0,     0,     0,     0,     0,
     145,   146,   147,   148,   149,   150,   151,    24,   152,   244,
       0,     0,     0,   155,     0,   245,     0,     0,     0,   111,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,   148,   149,   150,   151,    24,   152,   533,     0,     0,
       0,   155,   535,   536,   537,   538,   539,   540,   541,   542,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   552,     0,     0,     0,     0,
       0,     0,     0,     0,   553,   554
};

static const yytype_int16 yycheck[] =
{
      15,    53,    45,    27,    28,   119,   279,   175,    23,   160,
     134,   264,    31,   293,   197,   198,    31,   196,   197,   198,
     264,    31,   100,    80,     0,    10,    10,   222,    43,    56,
     439,    29,    30,    62,    91,    49,    49,    56,    53,    54,
      43,    56,    31,    62,    31,    32,    56,    68,    75,   458,
      53,    54,    31,    49,   132,   274,   275,   276,   277,    71,
      75,    75,    75,   159,   160,    31,    76,    56,    31,    54,
      54,    54,    75,    60,    72,    90,    56,    56,   121,    75,
      95,   110,   106,   278,   103,   100,    31,    32,    98,     0,
      56,    54,    95,    56,   118,   110,    52,     8,   249,    62,
     124,   116,   131,   512,    49,   134,   158,    52,    53,    56,
      52,    56,   131,    60,    53,    60,    57,   132,   286,   134,
      59,   178,    56,    53,   159,   160,    56,   184,    52,    47,
      75,   314,    56,    51,   414,   314,    60,    52,   195,    58,
     103,    56,   199,   158,   201,    55,   175,   110,    12,    59,
     246,    53,    53,   249,    50,   118,    58,    59,   101,   338,
     175,   285,   445,   220,   221,   448,   223,    46,   131,    53,
      40,   134,    41,   188,    58,    59,   110,   396,   397,   398,
      39,    31,    32,    59,    11,   200,    60,   202,   203,   204,
     205,   206,   207,   208,    21,    22,    23,    24,    25,   162,
     134,   352,    52,    31,    32,   356,    56,   480,   488,    11,
      60,   246,   175,    45,   249,   311,   469,   470,   471,    53,
      52,    49,    58,    59,    52,   469,   470,   471,    56,    43,
      44,    45,    60,   388,   389,   390,   199,    55,   201,    37,
      38,   175,    11,   411,    27,    28,    13,    75,   375,   376,
      82,    15,   431,   391,   392,   279,   285,   286,   477,   222,
     223,    13,   225,   310,   227,   228,   229,   230,    54,   326,
     285,   286,    33,    34,    35,    36,   311,   381,   382,   383,
     384,   338,   297,   278,   336,   222,    28,   116,   345,   121,
      56,   131,   349,   350,   124,   343,   128,   523,   313,   363,
     366,   368,   370,   399,   418,   478,   420,   372,   338,   338,
     406,   274,   275,   276,   277,   278,   279,    31,    32,   444,
     335,   336,   285,   286,   339,   514,   289,   159,   347,   161,
     293,   294,   338,    54,   134,   298,   279,   348,    52,    -1,
     303,   304,    56,   169,   359,   279,    60,    -1,    -1,    -1,
      -1,   285,   286,    -1,    68,    -1,   299,    -1,    -1,    -1,
      -1,   404,    -1,    -1,   399,    21,    22,    23,    24,    25,
      -1,   406,   315,    -1,    -1,   338,    -1,    -1,    -1,    -1,
      -1,    -1,   411,   440,   347,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,   411,   360,    -1,   451,
     363,   364,    -1,   366,    -1,   368,   520,   370,    -1,   372,
      25,   426,   375,   376,    -1,    -1,    -1,    -1,   381,   382,
     383,   384,    -1,    -1,    -1,   388,   389,   390,   391,   392,
      -1,    -1,    -1,   396,   397,   398,   451,    -1,    53,    -1,
      79,    -1,    -1,    -1,    -1,    84,    -1,    -1,   411,    -1,
      -1,   414,   284,    68,    -1,    -1,   480,    -1,    -1,   422,
      -1,    -1,   425,    -1,    -1,   408,    -1,    -1,    -1,   108,
     522,   110,    -1,   416,   408,   438,   410,   411,    -1,    -1,
      -1,   496,    -1,    -1,   447,    -1,   501,   502,   503,   504,
     505,   506,   507,   508,    -1,   134,    -1,    -1,    -1,    -1,
      -1,   558,    -1,    -1,    -1,    -1,    -1,   522,    -1,   101,
     342,   343,    -1,    -1,   477,   478,    -1,   480,    -1,   534,
     159,    -1,    -1,    -1,    -1,   488,    -1,    -1,   543,   544,
      -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,
     483,    -1,    -1,    -1,   426,    -1,   480,    -1,    -1,   188,
      -1,    -1,    -1,   516,    -1,    -1,    -1,   196,   197,   198,
     523,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     162,   514,   404,    -1,   406,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,   118,    -1,    -1,   529,    -1,    -1,   228,
     229,    -1,   555,    -1,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,   197,   198,   246,    -1,    -1,
      -1,    -1,    -1,   445,   496,    -1,   448,    -1,   210,   501,
     502,   503,   504,   505,   506,   507,   508,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   229,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,   285,   286,   287,    -1,
      -1,    -1,   534,    18,    -1,    -1,    21,    22,    23,    24,
      25,   543,   544,    -1,   199,    -1,   201,    -1,    -1,    -1,
     309,    -1,   311,    -1,   313,   314,    -1,    -1,    -1,    -1,
      -1,   274,   275,   276,   277,    -1,    -1,    -1,   223,    -1,
     225,    -1,   227,    -1,    -1,   230,   335,    -1,   337,   338,
     339,   293,    -1,    68,   343,    -1,    -1,   299,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   355,    -1,    -1,    -1,
     359,    -1,   314,    -1,   316,    -1,    -1,   319,    -1,   321,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,   278,   279,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,   289,    -1,    -1,    -1,   293,   294,
     399,    -1,    -1,   298,    -1,   357,    -1,   406,   303,   304,
     363,    -1,   411,   366,    -1,   368,    -1,   370,    -1,   372,
     419,    -1,   375,   376,    -1,    -1,    -1,   426,   381,   382,
     383,   384,   431,    -1,    -1,   388,   389,   390,   391,   392,
      -1,    -1,    -1,   396,   397,   398,    -1,    -1,    -1,    -1,
      68,    -1,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   199,   414,   201,   416,   360,    -1,    -1,    -1,   364,
      -1,    -1,    -1,    -1,    -1,    -1,   428,     3,     4,     5,
       6,     7,     8,     9,    10,   223,    -1,   225,    -1,   227,
      -1,    -1,   230,    -1,   110,    -1,    -1,   496,    -1,    25,
      -1,    -1,   501,   502,   503,   504,   505,   506,   507,   508,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   414,
      -1,    -1,    -1,    -1,   477,   478,    -1,   422,    -1,    -1,
     425,   483,    -1,    -1,    -1,   534,   488,    -1,    -1,    -1,
     278,   279,    68,   438,   543,   544,   498,    -1,   547,    -1,
      -1,   289,   447,    -1,   110,    -1,   294,    -1,   510,   175,
     298,    -1,    -1,    -1,    -1,   303,   304,    -1,    -1,    -1,
     523,    -1,   188,    -1,    -1,    -1,    -1,   529,   134,    -1,
     196,   197,   198,    -1,   200,   480,   202,   203,   204,   205,
     206,   207,   208,   488,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,    -1,    -1,
      -1,    -1,   228,   229,    -1,    -1,    -1,    -1,    -1,   175,
      -1,   516,   360,    -1,    -1,    -1,   364,    -1,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,   198,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     555,     3,     4,     5,     6,     7,     8,     9,    10,   285,
     286,    -1,    -1,    -1,    -1,   110,    18,    -1,    -1,    21,
      22,    23,    24,    25,   422,    -1,    -1,   425,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   134,
     438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,   335,
      -1,    -1,   338,   339,    -1,    -1,    68,    -1,    -1,   285,
     286,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
     175,    -1,   480,   359,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,   313,   314,   134,
      -1,   196,   197,   198,   426,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,    -1,    52,   516,   335,
      -1,    -1,   338,   339,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,   411,    -1,    -1,    -1,    74,
     175,    -1,    -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,
     426,    -1,    -1,   188,    -1,   431,    -1,   555,    -1,    -1,
      -1,   196,   197,   198,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   496,    -1,    -1,    -1,    -1,   501,
     502,   503,   504,   505,   506,   507,   508,    -1,    -1,    -1,
     285,   286,    -1,    -1,    -1,   411,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,    -1,   534,    -1,    -1,   431,    -1,    -1,   313,   314,
     496,   543,   544,    -1,    -1,   501,   502,   503,   504,   505,
     506,   507,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     335,    -1,    -1,   338,   339,    -1,    -1,    -1,    -1,    -1,
     285,   286,   110,    -1,    -1,    -1,    -1,    -1,   534,    -1,
      -1,    -1,    -1,    -1,   359,    -1,    -1,   543,   544,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,   313,   314,
     496,   426,    -1,    -1,    -1,   501,   502,   503,   504,   505,
     506,   507,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     335,    -1,    -1,   338,   339,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   411,   175,   534,    -1,
      -1,    -1,    19,    -1,   359,    -1,    -1,   543,   544,    -1,
     188,   426,    -1,    -1,    31,    32,   431,    -1,   196,   197,
     198,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   496,    -1,    -1,    -1,    52,   501,   502,   503,   504,
     505,   506,   507,   508,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,   411,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   534,
      -1,   426,    -1,    -1,    -1,    -1,   431,    -1,   543,   544,
      -1,   496,    -1,   188,    -1,    -1,   501,   502,   503,   504,
     505,   506,   507,   508,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   110,   285,   286,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   534,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,   544,
     134,    -1,    -1,    -1,    -1,   313,   314,    -1,    -1,   426,
      -1,   496,    -1,    -1,    -1,    -1,   501,   502,   503,   504,
     505,   506,   507,   508,    -1,    -1,    -1,   335,    -1,    -1,
     338,   339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   534,
      -1,   359,    -1,    -1,   188,    -1,    -1,    -1,   543,   544,
      -1,    -1,   196,   197,   198,    -1,   200,   426,   202,   203,
     204,   205,   206,   207,   208,   110,    -1,    -1,   313,   496,
      -1,    -1,    -1,    -1,   501,   502,   503,   504,   505,   506,
     507,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     335,    -1,    -1,   411,   339,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   534,   426,    -1,
      -1,    -1,    -1,   431,   359,    -1,   543,   544,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   426,   496,    -1,    -1,
     175,    -1,   501,   502,   503,   504,   505,   506,   507,   508,
      -1,   285,   286,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,   198,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,    -1,   534,    -1,    -1,    -1,   313,
     314,   228,   229,    -1,   543,   544,    -1,    -1,   496,    -1,
      -1,   426,    -1,   501,   502,   503,   504,   505,   506,   507,
     508,   335,    -1,    -1,   338,   339,   496,    -1,    -1,    -1,
      -1,   501,   502,   503,   504,   505,   506,   507,   508,    -1,
      -1,    -1,    -1,    -1,    -1,   359,   534,   274,   275,   276,
     277,    -1,    -1,    -1,    -1,   543,   544,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   534,    -1,    -1,    -1,    -1,    -1,
     285,   286,    -1,   543,   544,    -1,    -1,    -1,    -1,    -1,
      -1,   496,    -1,    -1,    -1,    -1,   501,   502,   503,   504,
     505,   506,   507,   508,    -1,    -1,    -1,   411,   313,   314,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   426,    -1,    -1,    -1,    -1,   431,    -1,   534,
     335,    -1,    -1,   338,   339,   426,    -1,    -1,   543,   544,
      -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,   366,
      -1,   368,    -1,   370,   359,   372,    -1,    -1,   375,   376,
      -1,    -1,    -1,    -1,   381,   382,   383,   384,    -1,    -1,
      -1,   388,   389,   390,   391,   392,    -1,    -1,    -1,   396,
     397,   398,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,
      -1,    -1,   496,    -1,    -1,    -1,    -1,   501,   502,   503,
     504,   505,   506,   507,   508,   496,   411,   426,    -1,    -1,
     501,   502,   503,   504,   505,   506,   507,   508,    -1,    -1,
      -1,   426,    -1,    -1,    -1,    -1,   431,    -1,    -1,    -1,
     534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,
     544,   426,    -1,   534,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,   544,    -1,    -1,    -1,   496,    -1,    -1,
     477,   478,   501,   502,   503,   504,   505,   506,   507,   508,
      -1,    -1,    -1,    -1,    -1,   426,    -1,   496,    -1,    -1,
      -1,    -1,   501,   502,   503,   504,   505,   506,   507,   508,
     426,   496,    -1,    -1,    -1,   534,   501,   502,   503,   504,
     505,   506,   507,   508,   543,   544,   523,    -1,    -1,    -1,
      -1,   496,    -1,    -1,    -1,   534,   501,   502,   503,   504,
     505,   506,   507,   508,   543,   544,    -1,    -1,    -1,   534,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,   544,
      -1,    -1,    -1,    -1,    -1,   496,    -1,    -1,    -1,   534,
     501,   502,   503,   504,   505,   506,   507,   508,   543,   544,
     496,    -1,    -1,    -1,    -1,   501,   502,   503,   504,   505,
     506,   507,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   534,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,   544,    -1,    -1,    -1,    -1,   534,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,   544,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    73,
      74,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    74,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    32,    14,    15,    16,    17,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      31,    32,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    52,    -1,    54,    74,    -1,    -1,    58,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      19,    -1,    73,    74,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    -1,    54,    55,    -1,    -1,    -1,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    19,    -1,    -1,    -1,    74,    -1,    -1,    -1,    27,
      28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    19,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      27,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      19,    48,    -1,    -1,    -1,    52,    -1,    54,    27,    28,
      -1,    -1,    31,    32,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    42,    -1,    -1,    -1,    74,    19,    48,
      -1,    -1,    -1,    52,    53,    -1,    27,    28,    -1,    -1,
      31,    32,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    42,    -1,    -1,    -1,    74,    19,    48,    -1,    -1,
      -1,    52,    -1,    -1,    27,    28,    -1,    58,    31,    32,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    42,
      -1,    -1,    -1,    74,    19,    48,    -1,    -1,    -1,    52,
      -1,    -1,    27,    28,    57,    -1,    31,    32,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    42,    19,    -1,
      -1,    74,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    19,    -1,    -1,    74,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    42,
      -1,    -1,    -1,    74,    -1,    48,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   496,    -1,    -1,
      -1,    74,   501,   502,   503,   504,   505,   506,   507,   508,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   534,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   543,   544
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    21,    22,    23,    24,    25,    77,    78,    79,    80,
      95,    96,    97,   238,   239,   240,   241,   242,     0,    71,
     290,    80,    96,   240,    68,   289,   289,    99,    98,    54,
     100,   275,   100,     3,     4,     5,     6,     7,     8,     9,
      10,    18,    55,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    93,    94,    95,    97,   101,   102,   103,   104,
     109,   111,   112,   113,   117,   118,   159,   220,   221,   222,
     223,   224,   225,   226,   227,   235,   241,   275,   276,   289,
     105,   106,   107,   113,   289,    56,    92,   277,    60,    92,
     281,   105,   113,    84,   113,   235,   102,   276,   110,    53,
      83,   114,   115,   242,   274,   289,   120,   113,   289,   159,
      81,    52,   273,    58,    59,   279,   280,    75,   270,   277,
      57,   278,   289,   279,   119,   113,   116,   159,   107,   289,
     274,   280,    83,   121,   275,    11,    14,    15,    16,    17,
      19,    20,    26,    31,    32,    61,    62,    63,    64,    65,
      66,    67,    69,    70,    73,    74,    80,    82,    83,    93,
     125,   126,   127,   128,   129,   130,   131,   133,   138,   139,
     152,   153,   156,   157,   159,   160,   161,   162,   163,   168,
     170,   171,   172,   174,   175,   176,   177,   178,   179,   180,
     182,   183,   185,   187,   191,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     213,   214,   216,   217,   218,   219,   228,   230,   231,   232,
     233,   234,   236,   237,   242,   243,   244,   245,   251,   252,
     273,   276,   279,   282,   283,   284,   285,   286,   287,   288,
     289,   106,    27,    28,    42,    48,    93,   108,   123,   125,
     128,   131,   136,   137,   138,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   246,   247,   262,   268,   273,   275,
     278,    92,   121,   115,   107,   122,   160,   244,   276,    52,
     105,   251,   252,   273,   277,   251,   252,   281,   277,   132,
     136,   274,    49,   269,   270,   161,   276,   279,   279,    12,
     274,    93,   168,   274,   279,   175,   210,   211,   274,   210,
     274,   210,   274,   136,   279,   168,   136,   279,   168,   168,
     168,   168,   168,   168,   168,   274,   164,   184,   273,   188,
     279,   279,    85,    90,    93,   136,   279,   165,   166,   136,
     136,    93,   125,   129,   130,    93,   125,   136,    50,   271,
     277,    47,    51,   267,   272,    46,   266,    40,   260,    41,
     261,    39,   259,    37,    38,   257,   258,    33,    34,    35,
      36,   253,   254,   255,   256,    43,    44,    45,   263,   264,
     265,   246,   247,    29,    30,    72,   248,   249,   250,    93,
     151,   151,   151,   151,    85,    89,    93,   108,   124,   276,
     280,   160,   276,   276,   273,   136,   132,   274,   136,   289,
     136,   274,   280,   136,   136,   273,    81,   168,   210,   274,
     212,   280,   274,   274,   274,   279,   168,   105,   273,   163,
     209,   211,   242,   279,   168,   134,   135,   277,   134,   273,
     279,    83,   228,   279,   279,   274,   168,   142,   136,   143,
     144,   145,   146,   147,   147,   148,   148,   148,   148,   149,
     149,   149,   150,   150,   151,   151,   151,   274,   274,   276,
     280,   276,   276,   132,   274,    53,   274,   278,   273,   278,
     136,   136,   168,   169,   170,   173,   179,   181,   183,   186,
     192,   198,   200,   201,   202,   203,   204,   205,   206,   208,
     213,   215,   289,   274,   175,   136,   271,   279,   230,   135,
     136,   105,   167,   271,   151,   154,   108,   276,   274,   132,
     274,    13,   229,   169,   274,   169,   169,   169,   169,   169,
     169,   169,   169,   274,   271,   212,   136,   189,   278,   105,
     140,   274,   169,   169,   169,   273,   136,   190,   274,   279
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    76,    77,    78,    79,    79,    80,    81,    82,    82,
      82,    82,    82,    82,    82,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    90,    91,    91,    92,    92,    93,    93,    94,    95,
      95,    96,    96,    96,    96,    98,    97,    99,    97,   100,
     100,   101,   101,   102,   102,   102,   102,   103,   103,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     110,   109,   111,   111,   111,   111,   112,   113,   113,   114,
     114,   115,   115,   116,   117,   119,   118,   120,   118,   121,
     121,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     124,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     127,   128,   128,   129,   130,   130,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   136,   137,
     137,   138,   138,   139,   139,   139,   140,   140,   141,   141,
     142,   142,   143,   143,   144,   144,   145,   145,   146,   146,
     146,   147,   147,   147,   147,   147,   148,   148,   148,   148,
     149,   149,   149,   150,   150,   150,   150,   151,   151,   151,
     151,   151,   152,   152,   153,   153,   154,   154,   154,   154,
     155,   155,   155,   155,   156,   156,   157,   157,   158,   158,
     159,   159,   160,   160,   161,   161,   161,   162,   163,   164,
     163,   165,   163,   166,   167,   163,   168,   168,   168,   168,
     168,   168,   169,   169,   169,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   171,   172,   173,   174,
     175,   175,   175,   175,   175,   175,   175,   176,   177,   178,
     179,   180,   181,   182,   184,   183,   185,   186,   188,   189,
     190,   187,   191,   191,   192,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   207,   207,   207,   207,   207,   207,   207,   208,   208,
     208,   208,   208,   208,   208,   208,   209,   209,   210,   211,
     211,   212,   212,   213,   214,   215,   216,   217,   218,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     2,     1,     3,     2,     1,
       2,     1,     1,     1,     1,     0,     5,     0,     4,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     3,     1,     3,     1,     1,     1,
       0,     3,     2,     2,     3,     2,     2,     2,     3,     3,
       1,     2,     3,     1,     2,     0,     4,     0,     3,     3,
       4,     3,     2,     3,     4,     3,     2,     4,     3,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     2,     3,     3,     4,     4,     3,     4,     4,     5,
       6,     1,     3,     3,     3,     1,     2,     3,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     2,
       2,     1,     2,     2,     2,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     4,     4,
       3,     4,     2,     1,     1,     1,     1,     2,     2,     0,
       3,     0,     4,     0,     0,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     4,
       5,     2,     2,     3,     0,     4,     3,     3,     0,     0,
       0,    10,     1,     1,     1,     1,     2,     3,     2,     2,
       3,     3,     4,     2,     2,     3,     2,     3,     4,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       2,     3,     2,     5,     3,     3,     2,     2,     3,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 332 "milestone4/src/parser/lalr1_modular.y"
                              { }
#line 2595 "lalr1_modular.tab.c"
    break;

  case 3: /* CompilationUnit: ClassOrInterfaceDeclarations  */
#line 339 "milestone4/src/parser/lalr1_modular.y"
                                 { }
#line 2601 "lalr1_modular.tab.c"
    break;

  case 4: /* ClassOrInterfaceDeclarations: ClassOrInterfaceDeclaration  */
#line 343 "milestone4/src/parser/lalr1_modular.y"
                                { }
#line 2607 "lalr1_modular.tab.c"
    break;

  case 5: /* ClassOrInterfaceDeclarations: ClassOrInterfaceDeclarations ClassOrInterfaceDeclaration  */
#line 344 "milestone4/src/parser/lalr1_modular.y"
                                                             { }
#line 2613 "lalr1_modular.tab.c"
    break;

  case 6: /* ClassOrInterfaceDeclaration: ClassDeclaration  */
#line 348 "milestone4/src/parser/lalr1_modular.y"
                     { }
#line 2619 "lalr1_modular.tab.c"
    break;

  case 7: /* ScopeIncrement: %empty  */
#line 367 "milestone4/src/parser/lalr1_modular.y"
           { increase_current_level(); }
#line 2625 "lalr1_modular.tab.c"
    break;

  case 8: /* Literal: Integer_literal  */
#line 377 "milestone4/src/parser/lalr1_modular.y"
                            { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2631 "lalr1_modular.tab.c"
    break;

  case 9: /* Literal: Fp_literal  */
#line 378 "milestone4/src/parser/lalr1_modular.y"
                        { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2637 "lalr1_modular.tab.c"
    break;

  case 10: /* Literal: Char_literal  */
#line 379 "milestone4/src/parser/lalr1_modular.y"
                          { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2643 "lalr1_modular.tab.c"
    break;

  case 11: /* Literal: String  */
#line 380 "milestone4/src/parser/lalr1_modular.y"
                    { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2649 "lalr1_modular.tab.c"
    break;

  case 12: /* Literal: Text_block  */
#line 381 "milestone4/src/parser/lalr1_modular.y"
                        { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2655 "lalr1_modular.tab.c"
    break;

  case 13: /* Literal: Boolean_literal  */
#line 382 "milestone4/src/parser/lalr1_modular.y"
                             { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2661 "lalr1_modular.tab.c"
    break;

  case 14: /* Literal: Null_literal  */
#line 383 "milestone4/src/parser/lalr1_modular.y"
                          { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 2667 "lalr1_modular.tab.c"
    break;

  case 15: /* UnannTypeSubRoutine: UnannType  */
#line 393 "milestone4/src/parser/lalr1_modular.y"
                { 
                    global_type = (yyvsp[0].type);

                    (yyval.stack_entry) = make_stackentry("", (yyvsp[0].type), yylineno);
                }
#line 2677 "lalr1_modular.tab.c"
    break;

  case 16: /* UnannType: PrimitiveType  */
#line 400 "milestone4/src/parser/lalr1_modular.y"
                    { (yyval.type) = (yyvsp[0].type); }
#line 2683 "lalr1_modular.tab.c"
    break;

  case 17: /* UnannType: ReferenceType  */
#line 401 "milestone4/src/parser/lalr1_modular.y"
                    { (yyval.type) = (yyvsp[0].type); }
#line 2689 "lalr1_modular.tab.c"
    break;

  case 18: /* PrimitiveType: NumericType  */
#line 405 "milestone4/src/parser/lalr1_modular.y"
                { (yyval.type) = (yyvsp[0].type); }
#line 2695 "lalr1_modular.tab.c"
    break;

  case 19: /* PrimitiveType: Boolean  */
#line 406 "milestone4/src/parser/lalr1_modular.y"
             { (yyval.type) = (yyvsp[0].type); }
#line 2701 "lalr1_modular.tab.c"
    break;

  case 20: /* NumericType: IntegralType  */
#line 410 "milestone4/src/parser/lalr1_modular.y"
                 { (yyval.type) = (yyvsp[0].type); }
#line 2707 "lalr1_modular.tab.c"
    break;

  case 21: /* NumericType: FloatingPointType  */
#line 411 "milestone4/src/parser/lalr1_modular.y"
                       { (yyval.type) = (yyvsp[0].type); }
#line 2713 "lalr1_modular.tab.c"
    break;

  case 22: /* IntegralType: Byte  */
#line 414 "milestone4/src/parser/lalr1_modular.y"
                          { (yyval.type) = (yyvsp[0].type); }
#line 2719 "lalr1_modular.tab.c"
    break;

  case 23: /* IntegralType: Short  */
#line 415 "milestone4/src/parser/lalr1_modular.y"
                           { (yyval.type) = (yyvsp[0].type); }
#line 2725 "lalr1_modular.tab.c"
    break;

  case 24: /* IntegralType: Int  */
#line 416 "milestone4/src/parser/lalr1_modular.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 2731 "lalr1_modular.tab.c"
    break;

  case 25: /* IntegralType: Long  */
#line 417 "milestone4/src/parser/lalr1_modular.y"
                          { (yyval.type) = (yyvsp[0].type); }
#line 2737 "lalr1_modular.tab.c"
    break;

  case 26: /* IntegralType: Char  */
#line 418 "milestone4/src/parser/lalr1_modular.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 2743 "lalr1_modular.tab.c"
    break;

  case 27: /* FloatingPointType: Float  */
#line 421 "milestone4/src/parser/lalr1_modular.y"
                            { (yyval.type) = (yyvsp[0].type); }
#line 2749 "lalr1_modular.tab.c"
    break;

  case 28: /* FloatingPointType: Double  */
#line 422 "milestone4/src/parser/lalr1_modular.y"
                             { (yyval.type) = (yyvsp[0].type); }
#line 2755 "lalr1_modular.tab.c"
    break;

  case 29: /* ReferenceType: ClassOrInterfaceType  */
#line 430 "milestone4/src/parser/lalr1_modular.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 2761 "lalr1_modular.tab.c"
    break;

  case 30: /* ReferenceType: ArrayType  */
#line 431 "milestone4/src/parser/lalr1_modular.y"
              { (yyval.type) = (yyvsp[0].type); }
#line 2767 "lalr1_modular.tab.c"
    break;

  case 31: /* ClassOrInterfaceType: TypeName  */
#line 435 "milestone4/src/parser/lalr1_modular.y"
                 {  (yyval.type) = ClassOrInterfaceType((yyvsp[0].type_name)); /* TypeName will not have any problem as it will not find enteries in the symbol table for name like A.B*/ }
#line 2773 "lalr1_modular.tab.c"
    break;

  case 32: /* ArrayType: PrimitiveType Dims  */
#line 439 "milestone4/src/parser/lalr1_modular.y"
                       {    
                            (yyval.type) = get_array_type((yyvsp[-1].type), (yyvsp[0].stack_entry));
                        }
#line 2781 "lalr1_modular.tab.c"
    break;

  case 33: /* ArrayType: TypeName Dims  */
#line 442 "milestone4/src/parser/lalr1_modular.y"
                    { 
                        (yyval.type) = get_array_type(get_type(((yyvsp[-1].type_name))->names[0]->name), (yyvsp[0].stack_entry));
                    }
#line 2789 "lalr1_modular.tab.c"
    break;

  case 34: /* Dims: Lsquare Rsquare Dims  */
#line 448 "milestone4/src/parser/lalr1_modular.y"
                            {   
                                (yyval.stack_entry) = increase_dims((yyvsp[0].stack_entry)); 
                                // $$->tac = "[]"+ $3->tac ; 
                            }
#line 2798 "lalr1_modular.tab.c"
    break;

  case 35: /* Dims: Lsquare Rsquare  */
#line 452 "milestone4/src/parser/lalr1_modular.y"
                    { 
                        (yyval.stack_entry) = make_stackentry("", yylineno);
                        (yyval.stack_entry)->type = get_array_type(); 
                        // $$->tac = "[]";
                    }
#line 2808 "lalr1_modular.tab.c"
    break;

  case 36: /* TypeName: Identifier  */
#line 470 "milestone4/src/parser/lalr1_modular.y"
                { 
                    (yyval.type_name) = new TypeName((yyvsp[0].id));
                }
#line 2816 "lalr1_modular.tab.c"
    break;

  case 37: /* TypeName: TypeName Dot Identifier  */
#line 473 "milestone4/src/parser/lalr1_modular.y"
                            {
                               (yyvsp[-2].type_name)->append_name((yyvsp[0].id));
                               (yyval.type_name) = (yyvsp[-2].type_name);
                            }
#line 2825 "lalr1_modular.tab.c"
    break;

  case 38: /* ModifiersUnannTypeSubRoutine: Modifiers UnannType  */
#line 482 "milestone4/src/parser/lalr1_modular.y"
                            { 
                                global_modifier = (yyvsp[-1].b_no); 
                                global_type = (yyvsp[0].type);
                                (yyval.stack_entry) = make_stackentry("", (yyvsp[0].type), yylineno);
                                (yyval.stack_entry)->modifier = (yyvsp[-1].b_no);
                            }
#line 2836 "lalr1_modular.tab.c"
    break;

  case 39: /* Modifiers: Modifier  */
#line 491 "milestone4/src/parser/lalr1_modular.y"
             {  
                (yyval.b_no) = set_modifier(0, (yyvsp[0].b_no));
            }
#line 2844 "lalr1_modular.tab.c"
    break;

  case 40: /* Modifiers: Modifiers Modifier  */
#line 494 "milestone4/src/parser/lalr1_modular.y"
                        { 
                            (yyval.b_no) = set_modifier((yyvsp[-1].b_no), (yyvsp[0].b_no));
                        }
#line 2852 "lalr1_modular.tab.c"
    break;

  case 41: /* Modifier: Public  */
#line 501 "milestone4/src/parser/lalr1_modular.y"
                { 
                    (yyval.b_no) = __PUBLIC;
                }
#line 2860 "lalr1_modular.tab.c"
    break;

  case 42: /* Modifier: Private  */
#line 504 "milestone4/src/parser/lalr1_modular.y"
                { 
                    (yyval.b_no) = __PRIVATE;    
                }
#line 2868 "lalr1_modular.tab.c"
    break;

  case 43: /* Modifier: Static  */
#line 507 "milestone4/src/parser/lalr1_modular.y"
                { 
                    (yyval.b_no) = __STATIC;    
                }
#line 2876 "lalr1_modular.tab.c"
    break;

  case 44: /* Modifier: Final  */
#line 510 "milestone4/src/parser/lalr1_modular.y"
                { 
                    (yyval.b_no) = __FINAL;    
                }
#line 2884 "lalr1_modular.tab.c"
    break;

  case 45: /* $@1: %empty  */
#line 522 "milestone4/src/parser/lalr1_modular.y"
                               { add_class((yyvsp[-2].b_no), ((yyvsp[0].id))->name); free((yyvsp[0].id));}
#line 2890 "lalr1_modular.tab.c"
    break;

  case 46: /* ClassDeclaration: Modifiers Class Identifier $@1 ClassBody  */
#line 522 "milestone4/src/parser/lalr1_modular.y"
                                                                                 { current_class = NULL; current_scope = scope_global; }
#line 2896 "lalr1_modular.tab.c"
    break;

  case 47: /* $@2: %empty  */
#line 523 "milestone4/src/parser/lalr1_modular.y"
                     { add_class(0b0, ((yyvsp[0].id))->name); free((yyvsp[0].id));}
#line 2902 "lalr1_modular.tab.c"
    break;

  case 48: /* ClassDeclaration: Class Identifier $@2 ClassBody  */
#line 523 "milestone4/src/parser/lalr1_modular.y"
                                                                        { current_class = NULL; current_scope = scope_global;}
#line 2908 "lalr1_modular.tab.c"
    break;

  case 49: /* ClassBody: Lcurly ClassBodyDeclarations Rcurly  */
#line 540 "milestone4/src/parser/lalr1_modular.y"
                                        {}
#line 2914 "lalr1_modular.tab.c"
    break;

  case 50: /* ClassBody: Lcurly Rcurly  */
#line 541 "milestone4/src/parser/lalr1_modular.y"
                  {}
#line 2920 "lalr1_modular.tab.c"
    break;

  case 51: /* ClassBodyDeclarations: ClassBodyDeclarations ClassBodyDeclaration  */
#line 545 "milestone4/src/parser/lalr1_modular.y"
                                               { }
#line 2926 "lalr1_modular.tab.c"
    break;

  case 52: /* ClassBodyDeclarations: ClassBodyDeclaration  */
#line 546 "milestone4/src/parser/lalr1_modular.y"
                         { }
#line 2932 "lalr1_modular.tab.c"
    break;

  case 53: /* ClassBodyDeclaration: ClassMemberDeclaration  */
#line 550 "milestone4/src/parser/lalr1_modular.y"
                           { }
#line 2938 "lalr1_modular.tab.c"
    break;

  case 54: /* ClassBodyDeclaration: ConstructorDeclaration  */
#line 551 "milestone4/src/parser/lalr1_modular.y"
                           { }
#line 2944 "lalr1_modular.tab.c"
    break;

  case 55: /* ClassBodyDeclaration: StaticInitializer  */
#line 552 "milestone4/src/parser/lalr1_modular.y"
                      { }
#line 2950 "lalr1_modular.tab.c"
    break;

  case 56: /* ClassBodyDeclaration: Block  */
#line 553 "milestone4/src/parser/lalr1_modular.y"
                        { }
#line 2956 "lalr1_modular.tab.c"
    break;

  case 57: /* ClassMemberDeclaration: FieldDeclaration  */
#line 558 "milestone4/src/parser/lalr1_modular.y"
                     { }
#line 2962 "lalr1_modular.tab.c"
    break;

  case 58: /* ClassMemberDeclaration: MethodDeclaration  */
#line 559 "milestone4/src/parser/lalr1_modular.y"
                        { 
                            // if(pass_no==2){
                            //     loopnum=0;
                            //     ifnum=0;
                            //     tcount=0;
                            //     paramcount=0;
                            //     threeac_file_name =current_class->name + "." + ($1)->token + three_ac_type_dump(($1)->argument_type); ;
                            //     dump_3ac(threeac_file_name);
                            // }
                        }
#line 2977 "lalr1_modular.tab.c"
    break;

  case 59: /* ClassMemberDeclaration: ClassDeclaration  */
#line 569 "milestone4/src/parser/lalr1_modular.y"
                      { }
#line 2983 "lalr1_modular.tab.c"
    break;

  case 60: /* FieldDeclaration: ModifiersUnannTypeSubRoutine VariableDeclaratorList Semicolon  */
#line 574 "milestone4/src/parser/lalr1_modular.y"
                                                                  { global_modifier = 0b0; global_type = NULL; free((yyvsp[-2].stack_entry));}
#line 2989 "lalr1_modular.tab.c"
    break;

  case 61: /* FieldDeclaration: UnannTypeSubRoutine VariableDeclaratorList Semicolon  */
#line 575 "milestone4/src/parser/lalr1_modular.y"
                                                         { global_type = NULL; free((yyvsp[-2].stack_entry));}
#line 2995 "lalr1_modular.tab.c"
    break;

  case 62: /* VariableDeclaratorList: VariableDeclaratorList Comma VariableDeclarator  */
#line 579 "milestone4/src/parser/lalr1_modular.y"
                                                    {}
#line 3001 "lalr1_modular.tab.c"
    break;

  case 63: /* VariableDeclaratorList: VariableDeclarator  */
#line 580 "milestone4/src/parser/lalr1_modular.y"
                       { }
#line 3007 "lalr1_modular.tab.c"
    break;

  case 64: /* VariableDeclarator: VariableDeclaratorId Assign VariableInitializer  */
#line 585 "milestone4/src/parser/lalr1_modular.y"
                                                    {    
                                                        if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                                                            VariableDeclarator((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry), 1);
                                                            if(pass_no == 2){
                                                                (yyvsp[-2].stack_entry)->tac = create_new_mem((yyvsp[-2].stack_entry)->token, current_table->offset, (yyvsp[-2].stack_entry)->type);

                                                                assign_operator_3ac((yyvsp[-2].stack_entry)->tac, (yyvsp[0].stack_entry)->tac);   // JAYA

                                                                (yyval.stack_entry) = (yyvsp[-2].stack_entry); // JAYA
                                                            }
                                                            if(pass_no == 2 && (yyvsp[-2].stack_entry)->type->is_pointer()) (yyvsp[-2].stack_entry)->type->arr_dim_val = (yyvsp[0].stack_entry)->type->arr_dim_val;
                                                        }
                                                    }
#line 3025 "lalr1_modular.tab.c"
    break;

  case 65: /* VariableDeclarator: VariableDeclaratorId  */
#line 598 "milestone4/src/parser/lalr1_modular.y"
                         { 
                            if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                                VariableDeclarator((yyvsp[0].stack_entry), NULL, 2);
                                if(pass_no == 2) {
                                    (yyvsp[0].stack_entry)->tac = create_new_mem((yyvsp[0].stack_entry)->token, current_table->offset, (yyvsp[0].stack_entry)->type);

                                    (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                }

                            }
                         }
#line 3041 "lalr1_modular.tab.c"
    break;

  case 66: /* VariableDeclaratorId: VariableDeclaratorId Lsquare Rsquare  */
#line 612 "milestone4/src/parser/lalr1_modular.y"
                                          {     
                                                if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                                                    (yyval.stack_entry) = increase_dims((yyvsp[-2].stack_entry));
                                                }
                                                // if(pass_no==2)  $$->tac = $1->tac+"["+"]";     
                                                if(pass_no==2)  (yyval.stack_entry)->tac = (yyvsp[-2].stack_entry)->tac;                                    
                                          }
#line 3053 "lalr1_modular.tab.c"
    break;

  case 67: /* VariableDeclaratorId: Identifier  */
#line 619 "milestone4/src/parser/lalr1_modular.y"
                {    
                    if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                        (yyval.stack_entry) = make_stackentry((((yyvsp[0].id))->name).c_str(), global_type, yylineno);

                        free((yyvsp[0].id));
                    }
                }
#line 3065 "lalr1_modular.tab.c"
    break;

  case 68: /* VariableInitializer: Expression  */
#line 629 "milestone4/src/parser/lalr1_modular.y"
               { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3071 "lalr1_modular.tab.c"
    break;

  case 69: /* VariableInitializer: ArrayInitializer  */
#line 630 "milestone4/src/parser/lalr1_modular.y"
                     { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3077 "lalr1_modular.tab.c"
    break;

  case 70: /* $@3: %empty  */
#line 637 "milestone4/src/parser/lalr1_modular.y"
                {
                    add_function(((yyvsp[0].stack_entry))->token, ((yyvsp[0].stack_entry))->argument_type, ((yyvsp[0].stack_entry))->type, ((yyvsp[0].stack_entry))->modifier);   
                    tcount = 0;
                    current_scope = scope_method;
                    // if(pass_no==2){
                    //     threeac_file_name = current_class->name + "_" + ($1)->token ;
                    //     emit("\n\n"+threeac_file_name+":\n\n","","","");
                    // }
                }
#line 3091 "lalr1_modular.tab.c"
    break;

  case 71: /* MethodDeclaration: MethodHeader $@3 MethodBody  */
#line 645 "milestone4/src/parser/lalr1_modular.y"
                             {  
                                current_scope = scope_class; 
                                if(pass_no==2){
                                    current_table->offset = -1 * current_table->offset;
                                    unsigned long local_var_size = current_table->offset;
                                    current_table->empty_table(); 
                                    // $$ = $1;
                                    loopnum=0;
                                    ifnum=0;
                                    // tcount=0;
                                    paramcount=0;
                                    if(((yyvsp[-2].stack_entry))->token == "main")
                                        threeac_file_name = (yyvsp[-2].stack_entry)->token;
                                    else
                                        threeac_file_name =threeac_filename(current_class->name, ((yyvsp[-2].stack_entry))->token , ((yyvsp[-2].stack_entry))->argument_type) ;
                                    dump_3ac(threeac_file_name, local_var_size);
                                }
                            }
#line 3114 "lalr1_modular.tab.c"
    break;

  case 72: /* MethodHeader: ModifiersUnannTypeSubRoutine Declarator  */
#line 666 "milestone4/src/parser/lalr1_modular.y"
                                            {
                                                struct stackentry* entry = make_stackentry( (((yyvsp[0].stack_entry))->token).c_str(), ((yyvsp[-1].stack_entry))->type, yylineno);
                                                entry->token = ((yyvsp[0].stack_entry))->token;
                                                entry->modifier = ((yyvsp[-1].stack_entry))->modifier; 
                                                entry->argument_type = ((yyvsp[0].stack_entry))->argument_type;
                                                (yyval.stack_entry) = entry; 
                                                global_modifier = 0b0;
                                                free((yyvsp[-1].stack_entry));
                                            }
#line 3128 "lalr1_modular.tab.c"
    break;

  case 73: /* MethodHeader: UnannTypeSubRoutine Declarator  */
#line 675 "milestone4/src/parser/lalr1_modular.y"
                                        { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[0].stack_entry))->token).c_str(), ((yyvsp[-1].stack_entry))->type, yylineno); 
                                            entry->token = ((yyvsp[0].stack_entry))->token;
                                            entry->argument_type = ((yyvsp[0].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry; 
                                            free((yyvsp[-1].stack_entry));
                                        }
#line 3140 "lalr1_modular.tab.c"
    break;

  case 74: /* MethodHeader: Modifiers Void Declarator  */
#line 682 "milestone4/src/parser/lalr1_modular.y"
                                        { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[0].stack_entry))->token).c_str(), get_type(__VOID), yylineno);
                                            entry->token = ((yyvsp[0].stack_entry))->token;
                                            entry->modifier = (yyvsp[-2].b_no); 
                                            entry->argument_type = ((yyvsp[0].stack_entry))->argument_type;
                                            (yyval.stack_entry) = entry;
                                        }
#line 3152 "lalr1_modular.tab.c"
    break;

  case 75: /* MethodHeader: Void Declarator  */
#line 689 "milestone4/src/parser/lalr1_modular.y"
                                        { 
                                            struct stackentry* entry = make_stackentry((((yyvsp[0].stack_entry))->token).c_str(), get_type(__VOID), yylineno);
                                            entry->argument_type = ((yyvsp[0].stack_entry))->argument_type;
                                            entry->token = ((yyvsp[0].stack_entry))->token;
                                            (yyval.stack_entry) = entry;
                                        }
#line 3163 "lalr1_modular.tab.c"
    break;

  case 76: /* DeclaratorSubRoutine: Identifier Lparen  */
#line 745 "milestone4/src/parser/lalr1_modular.y"
                        {
                            (yyval.id) = (yyvsp[-1].id);
                            if(pass_no==2){
                                current_scope = scope_method;
                                // threeac_file_name = current_class->name + "_" + ($1)->name ;
                                // emit("\n\n"+threeac_file_name+":\n\n","","","");
                            }
                        }
#line 3176 "lalr1_modular.tab.c"
    break;

  case 77: /* Declarator: DeclaratorSubRoutine Rparen  */
#line 755 "milestone4/src/parser/lalr1_modular.y"
                                { 
                                    (yyval.stack_entry) = make_stackentry(((yyvsp[-1].id)->name).c_str(), yylineno); 
                                    free((yyvsp[-1].id)); 
                                    if(pass_no == 2){
                                        current_table->offset = 0;
                                        paramcount = 0;
                                    }
                                }
#line 3189 "lalr1_modular.tab.c"
    break;

  case 78: /* Declarator: DeclaratorSubRoutine FormalParameterList Rparen  */
#line 763 "milestone4/src/parser/lalr1_modular.y"
                                                    { 
                                                        (yyvsp[-1].stack_entry)->token =((yyvsp[-2].id))->name; (yyval.stack_entry) = (yyvsp[-1].stack_entry); 
                                                        free((yyvsp[-2].id));
                                                        if(pass_no == 2){
                                                            current_table->offset = 0;
                                                            paramcount = 0;
                                                        }
                                                    }
#line 3202 "lalr1_modular.tab.c"
    break;

  case 79: /* FormalParameterList: FormalParameterList Comma FormalParameter  */
#line 774 "milestone4/src/parser/lalr1_modular.y"
                                              {
                                                (yyvsp[-2].stack_entry)->argument_type.push_back(((yyvsp[0].stack_entry))->type);
                                                (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                free((yyvsp[0].stack_entry));
                                             }
#line 3212 "lalr1_modular.tab.c"
    break;

  case 80: /* FormalParameterList: FormalParameter  */
#line 779 "milestone4/src/parser/lalr1_modular.y"
                    {  
                        (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                    }
#line 3220 "lalr1_modular.tab.c"
    break;

  case 81: /* FormalParameter: UnannTypeSubRoutine VariableDeclaratorId  */
#line 785 "milestone4/src/parser/lalr1_modular.y"
                                             {
                                                (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                (yyval.stack_entry)->argument_type.push_back((yyvsp[0].stack_entry)->type);
                                                global_type = NULL;
                                                if (pass_no == 2){
                                                    if(paramcount == 0)
                                                        current_table ->offset = 20;
                                                    add_variable((yyvsp[0].stack_entry)->token, 0b0, (yyvsp[0].stack_entry)->type, current_table->offset, true, true);

                                                    current_table->offset += 8;
                                                    // JAYA
                                                    // if($2->type->is_pointer())
                                                    //     current_table->offset += REF_TYPE_SIZE;
                                                    // else
                                                    //     current_table->offset += $2->type->size;

                                                    paramcount ++;
                                                }

                                                free((yyvsp[-1].stack_entry));
                                            }
#line 3246 "lalr1_modular.tab.c"
    break;

  case 82: /* FormalParameter: Final UnannTypeSubRoutine VariableDeclaratorId  */
#line 806 "milestone4/src/parser/lalr1_modular.y"
                                                   {
                                                (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                (yyval.stack_entry)->modifier = __FINAL;
                                                (yyval.stack_entry)->argument_type.push_back((yyvsp[0].stack_entry)->type);
                                                global_type = NULL;
                                                if (pass_no == 2){
                                                    if(paramcount == 0)
                                                        current_table ->offset = 20;
                                                    add_variable((yyvsp[0].stack_entry)->token, (yyval.stack_entry)->modifier, (yyvsp[0].stack_entry)->type, current_table->offset, true, true);
                                                    
                                                    current_table->offset += 8;
                                                    // JAYA
                                                    // if($2->type->is_pointer())
                                                    //     current_table->offset += REF_TYPE_SIZE;
                                                    // else
                                                    //     current_table->offset += $2->type->size;
                                                    paramcount ++;
                                                }
                                                
                                                free((yyvsp[-1].stack_entry));
                                            }
#line 3272 "lalr1_modular.tab.c"
    break;

  case 83: /* MethodBody: Block  */
#line 830 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 3278 "lalr1_modular.tab.c"
    break;

  case 84: /* StaticInitializer: Static Block  */
#line 834 "milestone4/src/parser/lalr1_modular.y"
                 { }
#line 3284 "lalr1_modular.tab.c"
    break;

  case 85: /* $@4: %empty  */
#line 838 "milestone4/src/parser/lalr1_modular.y"
                         { add_constructor(((yyvsp[0].stack_entry))->token, ((yyvsp[0].stack_entry))->argument_type, (yyvsp[-1].b_no)); tcount = 0; current_scope = scope_method; }
#line 3290 "lalr1_modular.tab.c"
    break;

  case 86: /* ConstructorDeclaration: Modifiers Declarator $@4 ConstructorBody  */
#line 838 "milestone4/src/parser/lalr1_modular.y"
                                                                                                                                              {current_scope = scope_class;
                                                                                                                                        if(pass_no==2){
                                                                                                                                            // $$ = $1;
                                                                                                                                            check_final_vars();
                                                                                                                                            current_table->offset = -1 * current_table->offset;
                                                                                                                                            unsigned long local_vars_size = current_table->offset;
                                                                                                                                            current_table->empty_table();
                                                                                                                                            loopnum=0;
                                                                                                                                            ifnum=0;
                                                                                                                                            // tcount=0;
                                                                                                                                            paramcount=0;
                                                                                                                                            // threeac_file_name =current_class->name + "." +  ($2)->token + three_ac_type_dump(($2)->argument_type) ;
                                                                                                                                            threeac_file_name =threeac_filename(current_class->name ,  ((yyvsp[-2].stack_entry))->token ,((yyvsp[-2].stack_entry))->argument_type) ;
                                                                                                                                            dump_3ac(threeac_file_name, local_vars_size);
                                                                                                                                        }
                                                                                                                                    }
#line 3311 "lalr1_modular.tab.c"
    break;

  case 87: /* $@5: %empty  */
#line 854 "milestone4/src/parser/lalr1_modular.y"
               { add_constructor(((yyvsp[0].stack_entry))->token, ((yyvsp[0].stack_entry))->argument_type, (int8_t) 0); tcount = 0; current_scope = scope_method; }
#line 3317 "lalr1_modular.tab.c"
    break;

  case 88: /* ConstructorDeclaration: Declarator $@5 ConstructorBody  */
#line 854 "milestone4/src/parser/lalr1_modular.y"
                                                                                                                                             { current_scope = scope_class;
                                                                                                                                        if(pass_no==2){
                                                                                                                                            // $$ = $1;
                                                                                                
                                                                                                                                            check_final_vars();
                                                                                                                                            current_table->offset = -1 * current_table->offset;
                                                                                                                                            unsigned long local_vars_size = current_table->offset;
                                                                                                                                            current_table->empty_table();
                                                                                                                                            loopnum=0;
                                                                                                                                            ifnum=0;
                                                                                                                                            // tcount=0;
                                                                                                                                            paramcount=0;
                                                                                                                                            threeac_file_name =threeac_filename(current_class->name , ((yyvsp[-2].stack_entry))->token , ((yyvsp[-2].stack_entry))->argument_type) ;
                                                                                                                                            dump_3ac(threeac_file_name, local_vars_size);
                                                                                                                                        }
                                                                                                                                }
#line 3338 "lalr1_modular.tab.c"
    break;

  case 89: /* ConstructorBody: Lcurly BlockStatements Rcurly  */
#line 883 "milestone4/src/parser/lalr1_modular.y"
                                  { }
#line 3344 "lalr1_modular.tab.c"
    break;

  case 90: /* ConstructorBody: Lcurly ExplicitConstructorInvocation BlockStatements Rcurly  */
#line 884 "milestone4/src/parser/lalr1_modular.y"
                                                                {  }
#line 3350 "lalr1_modular.tab.c"
    break;

  case 91: /* ConstructorBody: Lcurly ExplicitConstructorInvocation Rcurly  */
#line 885 "milestone4/src/parser/lalr1_modular.y"
                                                {   }
#line 3356 "lalr1_modular.tab.c"
    break;

  case 92: /* ConstructorBody: Lcurly Rcurly  */
#line 886 "milestone4/src/parser/lalr1_modular.y"
                  { }
#line 3362 "lalr1_modular.tab.c"
    break;

  case 93: /* ExplicitConstructorInvocation: This Lparen Rparen  */
#line 890 "milestone4/src/parser/lalr1_modular.y"
                        {
                            // This is the default constructor of a class, hence always exists, no need to check anything
                            if(pass_no == 2){
                                vector <Type*> v;
                                auto method_def_pair = check_function_in_class( current_class->name, v, CONSTRUCTOR);
                                if(is_null(method_def_pair.first)){
                                    cerr << "Line No: " <<  yylineno  << "No such constructor present in class\n";
                                    exit(-1);
                                }
                            }
                        }
#line 3378 "lalr1_modular.tab.c"
    break;

  case 94: /* ExplicitConstructorInvocation: This Lparen ArgumentList Rparen  */
#line 901 "milestone4/src/parser/lalr1_modular.y"
                                    {
                                        // Check if any constructor exists with the same argument type
                                        if(pass_no == 2){
                                            auto method_def_pair = check_function_in_class( current_class->name, ((yyvsp[-1].stack_entry))->argument_type, CONSTRUCTOR);
                                            if(is_null(method_def_pair.first)){
                                                cerr << "Line No: " <<  yylineno  << "No such constructor present in class\n";
                                                exit(-1);
                                            }

                                            args.clear();
                                        }
                                    }
#line 3395 "lalr1_modular.tab.c"
    break;

  case 95: /* ArrayInitializer: Lcurly VariableInitializerList Rcurly  */
#line 919 "milestone4/src/parser/lalr1_modular.y"
                                          { 
                                            if(pass_no == 2) {
                                                (yyval.stack_entry) =(yyvsp[-1].stack_entry);
                                                if ((yyvsp[-1].stack_entry)->type->is_pointer()) {
                                                    (yyval.stack_entry) = increase_dims((yyvsp[-1].stack_entry));
                                                } else {
                                                    (yyval.stack_entry)->type = get_array_type();
                                                    (yyval.stack_entry) = assign_arr_dim((yyvsp[-1].stack_entry)->type, (yyval.stack_entry));
                                                }
                                                
                                            }
                                          }
#line 3412 "lalr1_modular.tab.c"
    break;

  case 96: /* ArrayInitializer: Lcurly Rcurly  */
#line 931 "milestone4/src/parser/lalr1_modular.y"
                  { /*empty array*/
                    if(pass_no == 2){ 
                        (yyval.stack_entry) = make_stackentry("", yylineno); 
                        (yyval.stack_entry)->type = get_array_type();
                    }
                 }
#line 3423 "lalr1_modular.tab.c"
    break;

  case 97: /* ArrayInitializer: Lcurly VariableInitializerList Comma Rcurly  */
#line 937 "milestone4/src/parser/lalr1_modular.y"
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
#line 3439 "lalr1_modular.tab.c"
    break;

  case 98: /* ArrayInitializer: Lcurly Comma Rcurly  */
#line 948 "milestone4/src/parser/lalr1_modular.y"
                        {   
                            if(pass_no == 2){
                                (yyval.stack_entry) = make_stackentry("", yylineno);
                                (yyval.stack_entry)->type = get_array_type();
                            }
                        }
#line 3450 "lalr1_modular.tab.c"
    break;

  case 99: /* VariableInitializerList: VariableInitializerList Comma VariableInitializer  */
#line 957 "milestone4/src/parser/lalr1_modular.y"
                                                      {     
                                                            if(pass_no == 2){
                                                                if(check_return_type(((yyvsp[-2].stack_entry))->type,((yyvsp[0].stack_entry))->type)){
                                                                    (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                                } else if(check_return_type(((yyvsp[0].stack_entry))->type,((yyvsp[-2].stack_entry))->type)) {
                                                                    (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                                }
                                                            }
                                                      }
#line 3464 "lalr1_modular.tab.c"
    break;

  case 100: /* VariableInitializerList: VariableInitializer  */
#line 966 "milestone4/src/parser/lalr1_modular.y"
                        { if(pass_no ==2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3470 "lalr1_modular.tab.c"
    break;

  case 101: /* Primary: PrimaryNoNewArray  */
#line 1005 "milestone4/src/parser/lalr1_modular.y"
                              { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3476 "lalr1_modular.tab.c"
    break;

  case 102: /* Primary: ArrayCreationExpression  */
#line 1006 "milestone4/src/parser/lalr1_modular.y"
                                    {       
                                        (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                                    }
#line 3484 "lalr1_modular.tab.c"
    break;

  case 103: /* PrimaryNoNewArray: Literal  */
#line 1012 "milestone4/src/parser/lalr1_modular.y"
                            { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3490 "lalr1_modular.tab.c"
    break;

  case 104: /* PrimaryNoNewArray: This  */
#line 1013 "milestone4/src/parser/lalr1_modular.y"
                         { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3496 "lalr1_modular.tab.c"
    break;

  case 105: /* PrimaryNoNewArray: Lparen Expression Rparen  */
#line 1014 "milestone4/src/parser/lalr1_modular.y"
                                             { (yyval.stack_entry) = (yyvsp[-1].stack_entry); }
#line 3502 "lalr1_modular.tab.c"
    break;

  case 106: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 1015 "milestone4/src/parser/lalr1_modular.y"
                                                    { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3508 "lalr1_modular.tab.c"
    break;

  case 107: /* PrimaryNoNewArray: FieldAccess  */
#line 1016 "milestone4/src/parser/lalr1_modular.y"
                                { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3514 "lalr1_modular.tab.c"
    break;

  case 108: /* PrimaryNoNewArray: ArrayAccess  */
#line 1017 "milestone4/src/parser/lalr1_modular.y"
                                { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3520 "lalr1_modular.tab.c"
    break;

  case 109: /* PrimaryNoNewArray: MethodInvocation  */
#line 1018 "milestone4/src/parser/lalr1_modular.y"
                                     { (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 3526 "lalr1_modular.tab.c"
    break;

  case 110: /* ClassInstanceCreationExpressionSubRoutine: New ClassOrInterfaceType Lparen  */
#line 1022 "milestone4/src/parser/lalr1_modular.y"
                                    {if(pass_no == 2) {
                                        (yyval.stack_entry) = make_stackentry("", ((yyvsp[-1].type)), yylineno);
                                        (yyval.stack_entry)->tac = create_new_temp();

                                        emit(create_new_allocmem(create_new_const(to_string((yyvsp[-1].type)->class_def->class_width), 4), (yyval.stack_entry)->tac));
                                        
                                        // JAYA allocmem
                                        // Reg* reg = create_new_reg(SP, 4, false); // space for arguments  -> width
                                        // emit(reg);
                                        
                                        // Arg* arg = create_new_arg(create_new_const(to_string($2->class_def->class_width), 4), 4);
                                        // emit(arg); 
                                        // Call* call = create_new_call("allocmem", 1);
                                        // emit(call);
                                        // // Get return value
                                        // Return* ret = create_new_return($$->tac, false);  // get object reference
                                        // emit(ret);
                                        // reg = create_new_reg(SP, 4, true);    // remove space for arguments
                                        // emit(ret);  
                                    }}
#line 3551 "lalr1_modular.tab.c"
    break;

  case 111: /* ClassInstanceCreationExpression: ClassInstanceCreationExpressionSubRoutine Rparen  */
#line 1044 "milestone4/src/parser/lalr1_modular.y"
                                                      {
                                                if(pass_no == 2){
                                                    vector<Type *>v;
                                                    auto func_pair = check_function_in_class(((yyvsp[-1].stack_entry))->type->name, v, CONSTRUCTOR);
                                                    if(is_null(func_pair.first)) {
                                                        cerr << "Line No: " <<  yylineno << "Unknown constructor used"<<endl;
                                                        exit(1);
                                                    }
                                                    (yyval.stack_entry) = (yyvsp[-1].stack_entry);

                                                    int args_size = 4;
                                                    for(int i=0; i<func_pair.second.size(); i++){
                                                        args_size += func_pair.second[i]->size;
                                                    }
                                                    emit(create_new_reg(SP, args_size,false));
                                                    emit(create_new_arg((yyval.stack_entry)->tac, 0));
                                                    emit(create_new_call(threeac_filename(((yyvsp[-1].stack_entry))->type->name, ((yyvsp[-1].stack_entry))->type->name, func_pair.second), 1));
                                                    emit(create_new_reg(SP, args_size, true));
                                                    // emit("=","popparam", $$->tac,"");
                                                                
                                                } 
                                            }
#line 3578 "lalr1_modular.tab.c"
    break;

  case 112: /* ClassInstanceCreationExpression: ClassInstanceCreationExpressionSubRoutine ArgumentList Rparen  */
#line 1066 "milestone4/src/parser/lalr1_modular.y"
                                                                  {   
                                                            if(pass_no == 2){
                                                                
                                                                auto func_pair = check_function_in_class(((yyvsp[-2].stack_entry))->type->name, ((yyvsp[-1].stack_entry))->argument_type, CONSTRUCTOR);
                                                                
                                                                if(is_null(func_pair.first)){
                                                                    cerr << "Line No: " <<  yylineno <<"Unknown constructor used"<<endl;
                                                                    exit(1);
                                                                }
                                                                
                                                                (yyval.stack_entry) = (yyvsp[-2].stack_entry);

                                                                int args_size = 0;
                                                                for(int i=0; i<func_pair.second.size(); i++){
                                                                    // cerr << (func_pair.second[i]->name) << "\n";
                                                                    args_size += func_pair.second[i]->size;
                                                                }

                                                                emit(create_new_reg(SP, args_size,false));  // space for args

                                                                int local_args_sum = 0;

                                                                for(int i = 0; i<args.size(); i++){
                                                                    if((!check_if_temp(args[i]) && (!check_if_const(args[i])))){
                                                                        Address* temp = create_new_temp();
                                                                        
                                                                        emit(create_new_quad("=", args[i], NULL, temp));
                                                                        emit(create_new_arg(temp, local_args_sum));
                                                                    }else {
                                                                         emit(create_new_arg(args[i], local_args_sum));
                                                                    }
                                                                    local_args_sum += func_pair.second[i]->size;   
                                                                }

                                                                args.clear();

                                                                emit(create_new_reg(SP, args_size,false));  // space for obejct reference
                                                                emit(create_new_arg((yyval.stack_entry)->tac, local_args_sum));
                                                                emit(create_new_call(threeac_filename(((yyvsp[-2].stack_entry))->type->name, ((yyvsp[-2].stack_entry))->type->name, func_pair.second), paramcount+1));
                                                                emit(create_new_reg(SP, args_size+4, true));
                                                                // emit("=","popparam", $$->tac,"");
                                                                paramcount=0;

                                                                args.clear();
                                                            }
                                                        }
#line 3629 "lalr1_modular.tab.c"
    break;

  case 113: /* FieldAccess: Primary Dot Identifier  */
#line 1116 "milestone4/src/parser/lalr1_modular.y"
                                        {   
                                            if(pass_no == 2 ){
                                                (yyval.stack_entry) = find_variable_in_type((yyvsp[0].id)->name, (yyvsp[-2].stack_entry)->type);
                                                (yyvsp[-2].stack_entry)->tac = create_new_temp();
                                                if((yyvsp[-2].stack_entry)->token == "this") {
                                                    // Special handling for this
                                                    Address* mem = create_new_mem("", 16, 4);
                                                    emit(create_new_quad("=", mem, NULL, (yyvsp[-2].stack_entry)->tac));
                                                }
                                                (yyval.stack_entry)->tac = field_access_3ac((yyvsp[-2].stack_entry)->tac, (yyval.stack_entry)->offset, (yyval.stack_entry)->type, (yyvsp[0].id)->name);

                                                // free_type($1->type);
                                                free((yyvsp[-2].stack_entry));
                                                free((yyvsp[0].id));
                                            }
                                        }
#line 3650 "lalr1_modular.tab.c"
    break;

  case 114: /* ArrayAccess: TypeName Lsquare Expression Rsquare  */
#line 1136 "milestone4/src/parser/lalr1_modular.y"
                                                    {   
                                                        if(pass_no == 2 ){
                                                            
                                                            if( !(((yyvsp[-1].stack_entry))->type->is_integral)){
                                                                cerr << "Line No: " <<  yylineno <<"Array index must be integer"<<endl;
                                                                exit(-1);
                                                            }
                                                           
                                                            (yyval.stack_entry) = find_variable_in_class((yyvsp[-3].type_name), false);                
                                                            
                                                            // string id = ($1)->type;
                                                            Type *t = new Type();
                                                            
                                                            *t = *(((yyval.stack_entry))->type);


                                                            if(!t->is_pointer()){
                                                                cerr << "Line No: " <<  yylineno <<"Type of variable must be array type"<<endl;
                                                                exit(1);
                                                            }
                                                            
                                                            t->arr_dim--;
                                                            // $$->tac = $1->tac + "[" + $3->tac + "]";
                                                            
                                                            (yyvsp[-3].type_name)->tac = type_name_3ac((yyvsp[-3].type_name), false);
                                                            Address* temp1 = get_array_size(t->arr_dim_val, t->arr_dim_val.size() - t->arr_dim - 1);  // 1*3 here
                                                            Address* temp3 = create_new_temp();
                                                            emit(create_new_quad("*", temp1, (yyvsp[-1].stack_entry)->tac, temp3));
                                                            Address* temp2 = create_new_temp();
                                                            emit(create_new_quad("+", (yyvsp[-3].type_name)->tac, temp3, temp2));

                                                            // if a.b is a 1-d int array of dim 10
                                                            // for a.b[1] , t->arr_dim is now 0
                                                            // $$->arr_dim_val = {10,4}
                                                            // pointer to a.b array stored in $1->tac
                                                            // result should be:
                                                            // temp1 = $3->tac * $$->arr_dim_val[1]
                                                            // temp2 =  $1->tac + temp1
                                                            // $$->tac = * temp2
                                                            if(!t->is_pointer()){
                                                                (yyval.stack_entry)->tac = create_new_mem("", temp2, t);
                                                            }
                                                            // a.b is 3d int array of dimention 2,3,4 
                                                            // for a.b[1] , t->arr_dim is now 2
                                                            // $$->arr_dim_val = {2,3,4,4}
                                                            // pointer to a.b stored in $1->tac.
                                                            // result should be:
                                                            else{
                                                                (yyval.stack_entry)->tac = temp2;
                                                            }

                                                            (yyval.stack_entry)->type = t;
                                                            free((yyvsp[-1].stack_entry));
                                                        }
                                                    }
#line 3710 "lalr1_modular.tab.c"
    break;

  case 115: /* ArrayAccess: PrimaryNoNewArray Lsquare Expression Rsquare  */
#line 1191 "milestone4/src/parser/lalr1_modular.y"
                                                                {   
                                                        if(pass_no == 2 ){
                                                            if( !(((yyvsp[-1].stack_entry))->type->is_integral)){
                                                                cerr << "Line No: " <<  yylineno <<"Array index must be integer"<<endl;
                                                                exit(-1);
                                                            }

                                                            Type *t = new Type();
                                                            *t = *(((yyvsp[-3].stack_entry))->type);
                                                            if(!t->is_pointer()){
                                                                cerr << "Line No: " <<  yylineno <<"Type of variable must be array type"<<endl;
                                                                exit(1);
                                                            }
                                                            t->arr_dim--;
                                                            (yyval.stack_entry) = (yyvsp[-3].stack_entry); 
                                                            (yyval.stack_entry)->type = t;

                                                            Address* temp1 = get_array_size(t->arr_dim_val, t->arr_dim_val.size() - t->arr_dim - 1);  // 1*3 here
                                                            Address* temp3 = create_new_temp();
                                                            emit(create_new_quad("*", temp1, (yyvsp[-1].stack_entry)->tac, temp3));
                                                            Address* temp2 = create_new_temp();
                                                            emit(create_new_quad("+", (yyvsp[-3].stack_entry)->tac, temp3, temp2));
                                                            
                                                            if(!t->is_pointer()){
                                                                (yyval.stack_entry)->tac = create_new_mem("", temp2, t);
                                                            }
                                                            else{
                                                                (yyval.stack_entry)->tac = temp2;
                                                            }
                                                            
                                                            free((yyvsp[-1].stack_entry));
                                                        }
                                                    }
#line 3748 "lalr1_modular.tab.c"
    break;

  case 116: /* MethodInvocation: TypeName Lparen Rparen  */
#line 1226 "milestone4/src/parser/lalr1_modular.y"
                                            {    
                                                if(pass_no == 2 ){
                                                    vector<Type *> v;
                                                    
                                                    auto method_def_pair = check_function_in_class((yyvsp[-2].type_name), v, FUNCTION);
                                                    if(is_null(method_def_pair.first)){
                                                        cerr << "Line No: " <<  yylineno  << "Undeclared function called\n";
                                                        exit(1);
                                                    }
                                                    // Previously was wrong here. Return type directly used
                                                    // Maybe if return type was array then code was wrong here
                                                    // whenever making new stackentry of given type, use only this function
                                                    // do not manually assign type
                                                    (yyvsp[-2].type_name)->tac = type_name_3ac((yyvsp[-2].type_name), true);
                                                    string mname = ((yyvsp[-2].type_name)->names[(((yyvsp[-2].type_name))->names).size() - 1])->name;  
                                                    (yyval.stack_entry) = make_stackentry("", method_def_pair.first, yylineno);
                                                    (yyval.stack_entry)->tac = create_new_temp();
                                                    int names_size = ((yyvsp[-2].type_name))->names.size();
                                                    string method_name;

                                                    int ret_type_size = 0;

                                                    if(method_def_pair.first->is_class)
                                                        ret_type_size +=  method_def_pair.first->class_def->class_width;
                                                    else if(method_def_pair.first->is_pointer())
                                                        ret_type_size += REF_TYPE_SIZE;
                                                    else
                                                        ret_type_size += method_def_pair.first->size;
                                                    
                                                    
                                                    emit (create_new_reg(SP, 4, false));  // Space for obj refernce
        
                                                    if(names_size > 1){
                                                        emit(create_new_arg((yyvsp[-2].type_name)->tac, 0)); // Push object reference in stack
                                                        method_name = threeac_filename(((yyvsp[-2].type_name))->names[names_size-2]->type->name, mname, method_def_pair.second);
                                                    } else {

                                                        // This means same class function call within class, hence get reference from stack
                                                        Address* temp = create_new_temp();
                                                        Address* mem = create_new_mem("", 16, 4);
                                                        emit(create_new_quad("=", mem, NULL, temp));
                                                        emit(create_new_arg(temp, 0));
                                                        method_name = threeac_filename(current_class->name, mname, method_def_pair.second);
                                                    }

                                                    emit(create_new_call(method_name, paramcount+1));
                                                    emit(create_new_reg(SP, 4, true));   // remove space for object reference which was passed as argument
                                                    if(method_def_pair.first->name !=__VOID){
                                                        emit(create_new_return((yyval.stack_entry)->tac, false)); // get value returned by the callee function
                                                    }
                                                    paramcount=0;
                                                }
                                            }
#line 3806 "lalr1_modular.tab.c"
    break;

  case 117: /* MethodInvocation: TypeName Lparen ArgumentList Rparen  */
#line 1279 "milestone4/src/parser/lalr1_modular.y"
                                                        {   
                                                            if(pass_no == 2 ){
                                                                
                                                                //Mohit's code
                                                                // if($1->names[0]->name == "System" && $1->names[1]->name == "out" && $1->names[2]->name == "println"){
                                                                //     emit(create_new_print($3->tac, true));
                                                                //     // $$ = make_stackentry("", new Type(__VOID), yylineno);
                                                                //     // $$->tac = create_new_temp();
                                                                // }
                                                                // else{
                                                                //Mohit's code ends
                                                                // 
                                                                auto method_def_pair = check_function_in_class((yyvsp[-3].type_name), ((yyvsp[-1].stack_entry))->argument_type, FUNCTION);
                                                                if(is_null(method_def_pair.first)){
                                                                    cerr << "Line No: " <<  yylineno  << "Undeclared function called\n";
                                                                    exit(-1);
                                                                }
                                                                (yyvsp[-3].type_name)->tac = type_name_3ac((yyvsp[-3].type_name), true);
                                                                string mname = ((yyvsp[-3].type_name)->names[(((yyvsp[-3].type_name))->names).size() - 1])->name;  
                                                                (yyval.stack_entry) = make_stackentry("", method_def_pair.first, yylineno); 
                                                                (yyval.stack_entry)->tac = create_new_temp();

                                                                int local_args_sum = 0;
                                                                for(int i =0; i<method_def_pair.second.size();i++){
                                                                    local_args_sum += method_def_pair.second[i]->size;
                                                                }

                                                                emit(create_new_reg(SP, local_args_sum, false));   // Space for args
                                                                local_args_sum = 0;

                                                                for(int i = 0; i<args.size(); i++){
                                                                    if((!check_if_temp(args[i]) && (!check_if_const(args[i])))){
                                                                        Address* temp = create_new_temp();
                                                                        
                                                                        emit(create_new_quad("=", args[i], NULL, temp));
                                                                        emit(create_new_arg(temp, local_args_sum));
                                                                    }else {
                                                                         emit(create_new_arg(args[i], local_args_sum));
                                                                    }
                                                                    local_args_sum += method_def_pair.second[i]->size;   
                                                                }

                                                                args.clear();

                                                                int names_size = ((yyvsp[-3].type_name))->names.size();
                                                                string method_name;

                                                                int ret_type_size = 0;

                                                                if(method_def_pair.first->is_class)
                                                                    ret_type_size +=  method_def_pair.first->class_def->class_width;
                                                                else if(method_def_pair.first->is_pointer())
                                                                    ret_type_size += REF_TYPE_SIZE;
                                                                else
                                                                    ret_type_size += method_def_pair.first->size;
                                                                
                                                                
                                                                emit (create_new_reg(SP, 4, false));  // Space for obj refernce
                    
                                                                if(names_size > 1){
                                                                    emit(create_new_arg((yyvsp[-3].type_name)->tac, 0)); // Push object reference in stack
                                                                    method_name = threeac_filename(((yyvsp[-3].type_name))->names[names_size-2]->type->name, mname, method_def_pair.second);
                                                                } else {
                                                                    Address* temp = create_new_temp();
                                                                    Address* mem = create_new_mem("", 16, 4);
                                                                    emit(create_new_quad("=", mem, NULL, temp));
                                                                    emit(create_new_arg(temp, 0));
                                                                    method_name = threeac_filename(current_class->name, mname, method_def_pair.second);
                                                                }

                                                                emit(create_new_call(method_name, paramcount+1));
                                                                emit(create_new_reg(SP, 4, true));   // remove space for object reference which was passed as argument
                                                                if(method_def_pair.first->name !=__VOID){
                                                                    emit(create_new_return((yyval.stack_entry)->tac, false)); // get value returned by the callee function
                                                                }
                                                                emit(create_new_reg(SP, local_args_sum, true)); // remove space for arguments
                                                                paramcount=0;
                                                                // }
                                                            }
                                                        }
#line 3891 "lalr1_modular.tab.c"
    break;

  case 118: /* MethodInvocation: PRINT LPAREN Expression RPAREN  */
#line 1359 "milestone4/src/parser/lalr1_modular.y"
                                                        { 
                                                            if(pass_no == 2){
                                                                emit(create_new_print((yyvsp[-1].stack_entry)->tac));
                                                                // $$ = make_stackentry("", new Type(__VOID), yylineno);
                                                                // $$->tac = create_new_temp();
                                                            }
                                                        }
#line 3903 "lalr1_modular.tab.c"
    break;

  case 119: /* MethodInvocation: Primary Dot Identifier Lparen Rparen  */
#line 1366 "milestone4/src/parser/lalr1_modular.y"
                                                         { }
#line 3909 "lalr1_modular.tab.c"
    break;

  case 120: /* MethodInvocation: Primary Dot Identifier Lparen ArgumentList Rparen  */
#line 1367 "milestone4/src/parser/lalr1_modular.y"
                                                                      { if(pass_no == 2) args.clear(); }
#line 3915 "lalr1_modular.tab.c"
    break;

  case 121: /* ArgumentList: Expression  */
#line 1376 "milestone4/src/parser/lalr1_modular.y"
                                { 
                                    if(pass_no == 2 ){
                                        struct stackentry* entry = make_stackentry("", yylineno); 
                                        entry->argument_type.push_back(((yyvsp[0].stack_entry))->type);
                                        (yyval.stack_entry) = entry;
                                        cout << "Args size: " << args.size() << "\n";
                                        args.push_back(((yyvsp[0].stack_entry))->tac);
                                        // emit("pushparam" ,($1)->tac,"","");
                                        paramcount++;
                                        free((yyvsp[0].stack_entry));
                                    }
                                }
#line 3932 "lalr1_modular.tab.c"
    break;

  case 122: /* ArgumentList: ArgumentList Comma Expression  */
#line 1388 "milestone4/src/parser/lalr1_modular.y"
                                                  { 
                                                    if(pass_no == 2 ){
                                                        (yyvsp[-2].stack_entry)->argument_type.push_back((yyvsp[0].stack_entry)->type);
                                                        (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                        args.push_back(((yyvsp[0].stack_entry))->tac);
                                                        // emit("pushparam" ,($3)->tac,"","");
                                                        paramcount++;
                                                        free((yyvsp[0].stack_entry));
                                                    }
                                                  }
#line 3947 "lalr1_modular.tab.c"
    break;

  case 123: /* ArrayCreationExpression: New PrimitiveType DimExprs  */
#line 1415 "milestone4/src/parser/lalr1_modular.y"
                                                                   {  
                                                                        if(pass_no == 2 ){
                                                                                            (yyval.stack_entry) = assign_arr_dim((yyvsp[-1].type), (yyvsp[0].stack_entry)); 
                                                                                            (yyval.stack_entry)->type->arr_dim_val.push_back(create_new_const(to_string((yyvsp[-1].type)->size), 4));
                                                                                            Address* size = get_array_size((yyvsp[0].stack_entry)->type->arr_dim_val,0);
                                                                                            (yyval.stack_entry)->tac = create_new_temp();
                                                                                            
                                                                                            emit(create_new_allocmem(size, (yyval.stack_entry)->tac));
                                                                                            // JAYA allocmem
                                                                                            // emit(create_new_reg(SP, 4, false)); // space for arguments
                                                                                            // emit(create_new_arg(size,0));
                                                                                            // emit(create_new_call("allocmem", 1)); 
                                                                                            // emit(create_new_return($$->tac, false));  // get object reference
                                                                                            // emit(create_new_reg(SP, 4, true)); // remove space for arguments
                                                                                        } 
                                                                    }
#line 3968 "lalr1_modular.tab.c"
    break;

  case 124: /* ArrayCreationExpression: New ClassOrInterfaceType DimExprs  */
#line 1431 "milestone4/src/parser/lalr1_modular.y"
                                                                    {  
                                                                        if(pass_no == 2 ){
                                                                                            (yyval.stack_entry) = assign_arr_dim((yyvsp[-1].type), (yyvsp[0].stack_entry)); 
                                                                                            (yyval.stack_entry)->type->arr_dim_val.push_back(create_new_const(to_string((yyvsp[-1].type)->size), 4));
                                                                                            // $$->tac = $2->name + $3->tac;
                                                                                            Address* size = get_array_size((yyvsp[0].stack_entry)->type->arr_dim_val,0);
                                                                                            (yyval.stack_entry)->tac = create_new_temp();
                                                                                            emit(create_new_allocmem(size, (yyval.stack_entry)->tac));
                                                                                            // JAYA allocmem
                                                                                            // emit(create_new_reg(SP, 4, false)); // space for arguments
                                                                                            // emit(create_new_arg(size,0));
                                                                                            // emit(create_new_call("allocmem", 1)); 
                                                                                            // emit(create_new_return($$->tac, false));  // get object reference
                                                                                            // emit(create_new_reg(SP, 4, true)); // remove space for arguments
                                                                                        } 
                                                                    }
#line 3989 "lalr1_modular.tab.c"
    break;

  case 125: /* DimExprs: DimExpr  */
#line 1462 "milestone4/src/parser/lalr1_modular.y"
                    { if(pass_no == 2) {
                            (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                            (yyval.stack_entry)->type->arr_dim_val.push_back((yyvsp[0].stack_entry)->tac);
                        }
                    }
#line 3999 "lalr1_modular.tab.c"
    break;

  case 126: /* DimExprs: DimExprs DimExpr  */
#line 1467 "milestone4/src/parser/lalr1_modular.y"
                            {  if(pass_no == 2 ){  
                                    (yyval.stack_entry) = assign_arr_dim((yyvsp[-1].stack_entry), (yyvsp[0].stack_entry)); 
                                    // $$->tac = $1->tac + $2->tac;  
                                } 
                            }
#line 4009 "lalr1_modular.tab.c"
    break;

  case 127: /* DimExpr: Lsquare Expression Rsquare  */
#line 1475 "milestone4/src/parser/lalr1_modular.y"
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
                                                // $$->tac = "[" + ($2)->tac + "]";
                                                (yyval.stack_entry)->tac = ((yyvsp[-1].stack_entry))->tac;
                                            }
                                        }
#line 4032 "lalr1_modular.tab.c"
    break;

  case 128: /* Expression: AssignmentExpression  */
#line 1497 "milestone4/src/parser/lalr1_modular.y"
                                  { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4038 "lalr1_modular.tab.c"
    break;

  case 129: /* AssignmentExpression: ConditionalExpression  */
#line 1500 "milestone4/src/parser/lalr1_modular.y"
                          { if(pass_no == 2 ) { (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                  } }
#line 4045 "lalr1_modular.tab.c"
    break;

  case 130: /* AssignmentExpression: Assignment  */
#line 1502 "milestone4/src/parser/lalr1_modular.y"
               { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4051 "lalr1_modular.tab.c"
    break;

  case 131: /* Assignment: LeftHandSide AssignmentOperator Expression  */
#line 1506 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){

                                                        if(!((yyvsp[-2].stack_entry)->type->is_numeric) || !((yyvsp[0].stack_entry)->type->is_numeric)) {
                                                            cerr << "Line No: " <<  yylineno  << " incompatible types for binary operator\n\t "<< cerr_type(((yyvsp[0].stack_entry))->type) << " \n \t " << cerr_type(((yyvsp[-2].stack_entry))->type) <<"\n";
                                                            exit(-1);
                                                        }

                                                        if(!check_return_type(((yyvsp[-2].stack_entry))->type, ((yyvsp[0].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(((yyvsp[0].stack_entry))->type) << " cannot be converted to " << cerr_type(((yyvsp[-2].stack_entry))->type) <<"\n";
                                                            exit(-1);
                                                        }

                                                        if((yyvsp[-2].stack_entry)->type->arr_dim || (yyvsp[0].stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << " incompatible types incompatible types for binary operator\n\t " << cerr_type(((yyvsp[0].stack_entry))->type) << "\n \t" << cerr_type(((yyvsp[-2].stack_entry))->type) <<"\n";
                                                            exit(-1);
                                                        }

                                                        (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                        if((yyvsp[-2].stack_entry)->type->name == (yyvsp[0].stack_entry)->type->name) {
                                                            // Harshit $1->token to $1->tac 
                                                            (yyval.stack_entry)->tac = assignment_operator_3ac((yyvsp[-2].stack_entry)->tac, (yyvsp[-1].threeac_label), (yyvsp[0].stack_entry)->tac);
                                                        }
                                                        else {
                                                            Address* temp = create_new_temp();
                                                            // Harshit: removing cast
                                                            // emit(create_new_quad("cast_to_" + $1->type->name, $3->tac, NULL, temp));
                                                            emit(create_new_quad("cast", (yyvsp[0].stack_entry)->tac, NULL, temp));
                                                            // Harshit $1->token to $1->tac
                                                            (yyval.stack_entry)->tac = assignment_operator_3ac((yyvsp[-2].stack_entry)->tac, (yyvsp[-1].threeac_label), temp);
                                                        }

                                                        if((yyvsp[0].stack_entry)->type->arr_dim_val.size()>0){
                                                            (yyvsp[-2].stack_entry)->type->arr_dim_val = (yyvsp[0].stack_entry)->type->arr_dim_val;
                                                        }
                                                    }
                                                }
#line 4093 "lalr1_modular.tab.c"
    break;

  case 132: /* Assignment: LeftHandSide Assign Expression  */
#line 1543 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        if(!check_return_type(((yyvsp[-2].stack_entry))->type, ((yyvsp[0].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(((yyvsp[0].stack_entry))->type) << " cannot be converted to " << cerr_type(((yyvsp[-2].stack_entry))->type) <<"\n";
                                                            exit(-1);
                                                        }

                                                        if((yyvsp[-2].stack_entry)->type->is_numeric && (yyvsp[0].stack_entry)->type->is_numeric){
                                                            if(((yyvsp[-2].stack_entry)->type->arr_dim || (yyvsp[0].stack_entry)->type->arr_dim) && ((yyvsp[-2].stack_entry)->type->name!=(yyvsp[0].stack_entry)->type->name)){
                                                                cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(((yyvsp[0].stack_entry))->type) << " cannot be converted to " << cerr_type(((yyvsp[-2].stack_entry))->type) <<"\n";
                                                                exit(-1);
                                                            }
                                                        }

                                                        (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                        if((yyvsp[-2].stack_entry)->type->name == (yyvsp[0].stack_entry)->type->name) {
                                                            // Harshit
                                                            (yyval.stack_entry)->tac = assign_operator_3ac((yyvsp[-2].stack_entry)->tac, (yyvsp[0].stack_entry)->tac);
                                                        }
                                                        else {
                                                            Address* temp = create_new_temp();
                                                            // Harshit: removing cast
                                                            // emit(create_new_quad("cast_to_" + $1->type->name, $3->tac, NULL, temp));
                                                            emit(create_new_quad("cast", (yyvsp[0].stack_entry)->tac, NULL, temp));
                                                            // Harshit
                                                            (yyval.stack_entry)->tac = assign_operator_3ac((yyvsp[-2].stack_entry)->tac, temp);
                                                        }
                                                        if((yyvsp[0].stack_entry)->type->arr_dim_val.size()>0){
                                                            (yyvsp[-2].stack_entry)->type->arr_dim_val = (yyvsp[0].stack_entry)->type->arr_dim_val;
                                                        }
                                                    }
                                                }
#line 4130 "lalr1_modular.tab.c"
    break;

  case 133: /* LeftHandSide: TypeName  */
#line 1579 "milestone4/src/parser/lalr1_modular.y"
             {  
                if(pass_no == 2 ){ 
                    // $$ = find_variable_reference_in_class($1, true);
                    // Direct refernce of SymTabEntry Type* has been provided here.
                    // Careful manipulation required
                    struct stackentry* entry = find_variable_in_class((yyvsp[0].type_name), true);
                    (yyval.stack_entry) = entry;
                    (yyval.stack_entry)->tac = type_name_3ac((yyvsp[0].type_name), false);  // in a.b.c it returns c, in a it returns a
                    // $$->tac  = create_new_mem(entry->token, entry->offset, entry->type);
                }
            }
#line 4146 "lalr1_modular.tab.c"
    break;

  case 134: /* LeftHandSide: FieldAccess  */
#line 1590 "milestone4/src/parser/lalr1_modular.y"
                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4152 "lalr1_modular.tab.c"
    break;

  case 135: /* LeftHandSide: ArrayAccess  */
#line 1591 "milestone4/src/parser/lalr1_modular.y"
                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4158 "lalr1_modular.tab.c"
    break;

  case 136: /* ConditionalExpression: ConditionalOrExpression  */
#line 1594 "milestone4/src/parser/lalr1_modular.y"
                                                { if(pass_no == 2 ) { (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                  } }
#line 4165 "lalr1_modular.tab.c"
    break;

  case 137: /* ConditionalExpression: ConditionalOrExpression Qm Expression Colon ConditionalExpression  */
#line 1596 "milestone4/src/parser/lalr1_modular.y"
                                                                                      {     
                                                                                            if(pass_no == 2 ){

                                                                                                if(((yyvsp[-4].stack_entry))->type->arr_dim) {
                                                                                                    cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(((yyvsp[-4].stack_entry))->type) << " cannot be converted to boolean\n";
                                                                                                    exit(-1);
                                                                                                }

                                                                                                if(((yyvsp[-4].stack_entry))->type->name != __BOOLEAN){
                                                                                                    cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(((yyvsp[-4].stack_entry))->type) << " cannot be converted to boolean\n";
                                                                                                    exit(-1);
                                                                                                }

                                                                                                if((yyvsp[-2].stack_entry)->type->name == __BOOLEAN || (yyvsp[0].stack_entry)->type->name == __BOOLEAN) {
                                                                                                    if(!check_return_type((yyvsp[-2].stack_entry)->type, (yyvsp[0].stack_entry)->type)){
                                                                                                        cerr << "Line No: " <<  yylineno  << "Non intersectionable type: " << cerr_type(((yyvsp[-2].stack_entry))->type) << " and " << cerr_type(((yyvsp[0].stack_entry))->type) << "\n";
                                                                                                        exit(-1);
                                                                                                    }

                                                                                                    (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                                                                }
                                                                                                else {
                                                                                                    if(check_return_type(((yyvsp[-2].stack_entry))->type, ((yyvsp[0].stack_entry))->type)) 
                                                                                                        (yyval.stack_entry) = (yyvsp[-2].stack_entry);
                                                                                                    else
                                                                                                        (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                                                                }
                                                                                                (yyval.stack_entry)->tac = ternary_condition_3ac( (yyvsp[-4].stack_entry)->tac, (yyvsp[-2].stack_entry)->tac, (yyvsp[0].stack_entry)->tac);
                                                                                            }
                                                                                      }
#line 4200 "lalr1_modular.tab.c"
    break;

  case 138: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 1628 "milestone4/src/parser/lalr1_modular.y"
                                                     { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4206 "lalr1_modular.tab.c"
    break;

  case 139: /* ConditionalOrExpression: ConditionalOrExpression Or ConditionalAndExpression  */
#line 1629 "milestone4/src/parser/lalr1_modular.y"
                                                                        {   
                                                                            if(pass_no == 2 ) {  
                                                                                (yyval.stack_entry) = ConditionalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = or_operator_3ac((yyvsp[-2].stack_entry)->tac, (yyvsp[0].stack_entry)->tac);
                                                                            }
                                                                        }
#line 4217 "lalr1_modular.tab.c"
    break;

  case 140: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 1637 "milestone4/src/parser/lalr1_modular.y"
                                                  { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4223 "lalr1_modular.tab.c"
    break;

  case 141: /* ConditionalAndExpression: ConditionalAndExpression And InclusiveOrExpression  */
#line 1638 "milestone4/src/parser/lalr1_modular.y"
                                                                        {   
                                                                            if(pass_no == 2 ) {
                                                                                (yyval.stack_entry) = ConditionalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = and_operator_3ac((yyvsp[-2].stack_entry)->tac, (yyvsp[0].stack_entry)->tac);
                                                                            }
                                                                        }
#line 4234 "lalr1_modular.tab.c"
    break;

  case 142: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 1646 "milestone4/src/parser/lalr1_modular.y"
                                              { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4240 "lalr1_modular.tab.c"
    break;

  case 143: /* InclusiveOrExpression: InclusiveOrExpression Bitwise_or ExclusiveOrExpression  */
#line 1647 "milestone4/src/parser/lalr1_modular.y"
                                                                            {   
                                                                                if(pass_no == 2 ){  
                                                                                    (yyval.stack_entry) = BitwiseExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                    (yyval.stack_entry)->tac = binary_bitwise_operator_3ac((yyvsp[-2].stack_entry)->tac, "|", (yyvsp[0].stack_entry)->tac);
                                                                                }
                                                                            }
#line 4251 "lalr1_modular.tab.c"
    break;

  case 144: /* ExclusiveOrExpression: AndExpression  */
#line 1655 "milestone4/src/parser/lalr1_modular.y"
                                        { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4257 "lalr1_modular.tab.c"
    break;

  case 145: /* ExclusiveOrExpression: ExclusiveOrExpression Bitwise_xor AndExpression  */
#line 1656 "milestone4/src/parser/lalr1_modular.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = BitwiseExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = binary_bitwise_operator_3ac((yyvsp[-2].stack_entry)->tac, "^", (yyvsp[0].stack_entry)->tac);
                                                                            }
                                                                        }
#line 4268 "lalr1_modular.tab.c"
    break;

  case 146: /* AndExpression: EqualityExpression  */
#line 1664 "milestone4/src/parser/lalr1_modular.y"
                                    { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4274 "lalr1_modular.tab.c"
    break;

  case 147: /* AndExpression: AndExpression Bitwise_and EqualityExpression  */
#line 1665 "milestone4/src/parser/lalr1_modular.y"
                                                                    {       
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = BitwiseExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = binary_bitwise_operator_3ac((yyvsp[-2].stack_entry)->tac, "&", (yyvsp[0].stack_entry)->tac);
                                                                            }
                                                                        }
#line 4285 "lalr1_modular.tab.c"
    break;

  case 148: /* EqualityExpression: RelationalExpression  */
#line 1673 "milestone4/src/parser/lalr1_modular.y"
                                                                    { 
                                                                        if(pass_no == 2 )   {
                                                                                                (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                                                                                            } 
                                                                    }
#line 4295 "lalr1_modular.tab.c"
    break;

  case 149: /* EqualityExpression: EqualityExpression Deq RelationalExpression  */
#line 1678 "milestone4/src/parser/lalr1_modular.y"
                                                                    {   
                                                                        if(pass_no == 2 ){  
                                                                            (yyval.stack_entry) = EqualityExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            (yyval.stack_entry)->tac = deq_check_3ac((yyvsp[-2].stack_entry)->tac, (yyvsp[0].stack_entry)->tac);
                                                                        }
                                                                    }
#line 4306 "lalr1_modular.tab.c"
    break;

  case 150: /* EqualityExpression: EqualityExpression Neq RelationalExpression  */
#line 1684 "milestone4/src/parser/lalr1_modular.y"
                                                                    {   
                                                                        if(pass_no == 2 ){  
                                                                            (yyval.stack_entry) = EqualityExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            (yyval.stack_entry)->tac = neq_check_3ac((yyvsp[-2].stack_entry)->tac, (yyvsp[0].stack_entry)->tac);
                                                                        }
                                                                    }
#line 4317 "lalr1_modular.tab.c"
    break;

  case 151: /* RelationalExpression: ShiftExpression  */
#line 1692 "milestone4/src/parser/lalr1_modular.y"
                                                                    { 
                                                                        if(pass_no == 2 )   {
                                                                                                (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                                                                                            } 
                                                                    }
#line 4327 "lalr1_modular.tab.c"
    break;

  case 152: /* RelationalExpression: RelationalExpression Lt ShiftExpression  */
#line 1697 "milestone4/src/parser/lalr1_modular.y"
                                                                    {       
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = RelationalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = relation_check_3ac((yyvsp[-2].stack_entry)->tac, "<", (yyvsp[0].stack_entry)->tac);
                                                                            }
                                                                    }
#line 4338 "lalr1_modular.tab.c"
    break;

  case 153: /* RelationalExpression: RelationalExpression Gt ShiftExpression  */
#line 1703 "milestone4/src/parser/lalr1_modular.y"
                                                                    {       
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = RelationalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = relation_check_3ac((yyvsp[-2].stack_entry)->tac, ">", (yyvsp[0].stack_entry)->tac);
                                                                            }
                                                                    }
#line 4349 "lalr1_modular.tab.c"
    break;

  case 154: /* RelationalExpression: RelationalExpression Leq ShiftExpression  */
#line 1709 "milestone4/src/parser/lalr1_modular.y"
                                                                    {        
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = RelationalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = relation_check_3ac((yyvsp[-2].stack_entry)->tac,"<=", (yyvsp[0].stack_entry)->tac);
                                                                            }
                                                                    }
#line 4360 "lalr1_modular.tab.c"
    break;

  case 155: /* RelationalExpression: RelationalExpression Geq ShiftExpression  */
#line 1715 "milestone4/src/parser/lalr1_modular.y"
                                                                    {       
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = RelationalExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = relation_check_3ac((yyvsp[-2].stack_entry)->tac,">=", (yyvsp[0].stack_entry)->tac);
                                                                                           //Error Location $$ type mismatch
                                                                            }
                                                                    }
#line 4372 "lalr1_modular.tab.c"
    break;

  case 156: /* ShiftExpression: AdditiveExpression  */
#line 1725 "milestone4/src/parser/lalr1_modular.y"
                                                                    { 
                                                                        if(pass_no == 2 )   {
                                                                                                (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                                                                                            } 
                                                                    }
#line 4382 "lalr1_modular.tab.c"
    break;

  case 157: /* ShiftExpression: ShiftExpression Left_shift AdditiveExpression  */
#line 1730 "milestone4/src/parser/lalr1_modular.y"
                                                                    {   
                                                                        if(pass_no == 2 ){
                                                                            Address* temp = create_new_temp();
                                                                            emit(create_new_quad("<<", ((yyvsp[-2].stack_entry))->tac, ((yyvsp[0].stack_entry))->tac, temp));
                                                                            (yyval.stack_entry) = ShiftExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            (yyval.stack_entry)->tac = temp;
                                                                        }
                                                                    }
#line 4395 "lalr1_modular.tab.c"
    break;

  case 158: /* ShiftExpression: ShiftExpression Right_shift AdditiveExpression  */
#line 1738 "milestone4/src/parser/lalr1_modular.y"
                                                                    {   
                                                                        if(pass_no == 2 ){  
                                                                            Address* temp = create_new_temp();
                                                                            (yyval.stack_entry) = ShiftExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                            emit(create_new_quad(">>", ((yyvsp[-2].stack_entry))->tac, ((yyvsp[0].stack_entry))->tac, temp));
                                                                            (yyval.stack_entry)->tac = temp;    
                                                                        }
                                                                    }
#line 4408 "lalr1_modular.tab.c"
    break;

  case 159: /* ShiftExpression: ShiftExpression Unsigned_right_shift AdditiveExpression  */
#line 1746 "milestone4/src/parser/lalr1_modular.y"
                                                                                {   
                                                                                    if(pass_no == 2 ){
                                                                                          
                                                                                        Address* temp = create_new_temp();
                                                                                        (yyval.stack_entry) = ShiftExpression((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                        emit(create_new_quad(">>>", ((yyvsp[-2].stack_entry))->tac, ((yyvsp[0].stack_entry))->tac, temp));
                                                                                        (yyval.stack_entry)->tac = temp;  
                                                                                    }
                                                                                }
#line 4422 "lalr1_modular.tab.c"
    break;

  case 160: /* AdditiveExpression: MultiplicativeExpression  */
#line 1757 "milestone4/src/parser/lalr1_modular.y"
                                                                    { 
                                                                        if(pass_no == 2 )   {
                                                                                                (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                                                                                            } 
                                                                    }
#line 4432 "lalr1_modular.tab.c"
    break;

  case 161: /* AdditiveExpression: AdditiveExpression Plus MultiplicativeExpression  */
#line 1762 "milestone4/src/parser/lalr1_modular.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_additive_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = create_new_temp();
                                                                                if((yyval.stack_entry)->type->name != (yyvsp[-2].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // Harshit: removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $1->tac, NULL, temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[-2].stack_entry)->tac, NULL, temp));
                                                                                    // emit(create_new_quad("+"+$$->type->name, temp, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("+", temp, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else if((yyval.stack_entry)->type->name != (yyvsp[0].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // Harshit: removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $3->tac,NULL, temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[0].stack_entry)->tac,NULL, temp));
                                                                                    // emit(create_new_quad("+"+$$->type->name, ($1)->tac, temp, ($$)->tac));
                                                                                     emit(create_new_quad("+", ((yyvsp[-2].stack_entry))->tac, temp, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else
                                                                                    // emit(create_new_quad("+"+$$->type->name, ($1)->tac, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("+", ((yyvsp[-2].stack_entry))->tac, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                            }
                                                                        }
#line 4462 "lalr1_modular.tab.c"
    break;

  case 162: /* AdditiveExpression: AdditiveExpression Minus MultiplicativeExpression  */
#line 1787 "milestone4/src/parser/lalr1_modular.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_additive_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = create_new_temp();
                                                                                if((yyval.stack_entry)->type->name != (yyvsp[-2].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $1->tac, NULL, temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[-2].stack_entry)->tac, NULL, temp));
                                                                                    // emit(create_new_quad("-"+$$->type->name, temp, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("-", temp, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else if((yyval.stack_entry)->type->name != (yyvsp[0].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // Harshit: removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $3->tac,NULL, temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[0].stack_entry)->tac,NULL, temp));
                                                                                    // emit(create_new_quad("-"+$$->type->name, ($1)->tac, temp, ($$)->tac));
                                                                                    emit(create_new_quad("-", ((yyvsp[-2].stack_entry))->tac, temp, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else
                                                                                    // emit(create_new_quad("-"+$$->type->name, ($1)->tac, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("-", ((yyvsp[-2].stack_entry))->tac, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                            }
                                                                        }
#line 4492 "lalr1_modular.tab.c"
    break;

  case 163: /* MultiplicativeExpression: UnaryExpression  */
#line 1814 "milestone4/src/parser/lalr1_modular.y"
                                                                    { 
                                                                        if(pass_no == 2 )   {
                                                                                                (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                                                                                            } 
                                                                    }
#line 4502 "lalr1_modular.tab.c"
    break;

  case 164: /* MultiplicativeExpression: MultiplicativeExpression Asterik UnaryExpression  */
#line 1819 "milestone4/src/parser/lalr1_modular.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_additive_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = create_new_temp();
                                                                                if((yyval.stack_entry)->type->name != (yyvsp[-2].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // Harshit: removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $1->tac, NULL, temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[-2].stack_entry)->tac, NULL, temp));
                                                                                    // emit(create_new_quad("*"+$$->type->name, temp, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("*", temp, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else if((yyval.stack_entry)->type->name != (yyvsp[0].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // Harshit: removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $3->tac, NULL, temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[0].stack_entry)->tac, NULL, temp));
                                                                                    // emit(create_new_quad("*"+$$->type->name, ($1)->tac, temp, ($$)->tac));
                                                                                    emit(create_new_quad("*", ((yyvsp[-2].stack_entry))->tac, temp, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else
                                                                                    // emit(create_new_quad("*"+$$->type->name, ($1)->tac, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("*", ((yyvsp[-2].stack_entry))->tac, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                            }
                                                                        }
#line 4532 "lalr1_modular.tab.c"
    break;

  case 165: /* MultiplicativeExpression: MultiplicativeExpression Div UnaryExpression  */
#line 1844 "milestone4/src/parser/lalr1_modular.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_additive_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = create_new_temp();
                                                                                if((yyval.stack_entry)->type->name != (yyvsp[-2].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // Harshit: removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $1->tac, NULL,temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[-2].stack_entry)->tac, NULL,temp));
                                                                                    // emit(create_new_quad("/"+$$->type->name, temp, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("/", temp, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else if((yyval.stack_entry)->type->name != (yyvsp[0].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // Harshit: removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $3->tac, NULL,temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[0].stack_entry)->tac, NULL,temp));
                                                                                    // emit(create_new_quad("/"+$$->type->name, ($1)->tac, temp, ($$)->tac));
                                                                                    emit(create_new_quad("/", ((yyvsp[-2].stack_entry))->tac, temp, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else
                                                                                    // emit(create_new_quad("/"+$$->type->name, ($1)->tac, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("/", ((yyvsp[-2].stack_entry))->tac, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                            }
                                                                        }
#line 4562 "lalr1_modular.tab.c"
    break;

  case 166: /* MultiplicativeExpression: MultiplicativeExpression Modulo UnaryExpression  */
#line 1869 "milestone4/src/parser/lalr1_modular.y"
                                                                        {   
                                                                            if(pass_no == 2 ){  
                                                                                (yyval.stack_entry) = check_additive_types((yyvsp[-2].stack_entry), (yyvsp[0].stack_entry));
                                                                                (yyval.stack_entry)->tac = create_new_temp();
                                                                                if((yyval.stack_entry)->type->name != (yyvsp[-2].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // Harshit: removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $1->tac, NULL, temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[-2].stack_entry)->tac, NULL, temp));
                                                                                    // emit(create_new_quad("%"+$$->type->name, temp, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("%", temp, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else if((yyval.stack_entry)->type->name != (yyvsp[0].stack_entry)->type->name){
                                                                                    Address* temp = create_new_temp();
                                                                                    // Harshit: removing cast
                                                                                    // emit(create_new_quad("cast_to_"+$$->type->name, $3->tac, NULL, temp));
                                                                                    emit(create_new_quad("cast", (yyvsp[0].stack_entry)->tac, NULL, temp));
                                                                                    // emit(create_new_quad("%"+$$->type->name, ($1)->tac, temp, ($$)->tac));
                                                                                    emit(create_new_quad("%", ((yyvsp[-2].stack_entry))->tac, temp, ((yyval.stack_entry))->tac));
                                                                                }
                                                                                else
                                                                                    // emit(create_new_quad("%"+$$->type->name, ($1)->tac, ($3)->tac, ($$)->tac));
                                                                                    emit(create_new_quad("%", ((yyvsp[-2].stack_entry))->tac, ((yyvsp[0].stack_entry))->tac, ((yyval.stack_entry))->tac));
                                                                            }
                                                                        }
#line 4592 "lalr1_modular.tab.c"
    break;

  case 167: /* UnaryExpression: PreIncrementExpression  */
#line 1896 "milestone4/src/parser/lalr1_modular.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4598 "lalr1_modular.tab.c"
    break;

  case 168: /* UnaryExpression: PreDecrementExpression  */
#line 1897 "milestone4/src/parser/lalr1_modular.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4604 "lalr1_modular.tab.c"
    break;

  case 169: /* UnaryExpression: Plus UnaryExpression  */
#line 1898 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        if((yyvsp[0].stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << " :bad operand type " << cerr_type((yyvsp[0].stack_entry)->type) <<" for unary operator '+'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyvsp[0].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                    }
                                                }
#line 4623 "lalr1_modular.tab.c"
    break;

  case 170: /* UnaryExpression: Minus UnaryExpression  */
#line 1912 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){   
                                                        if((yyvsp[0].stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << " : bad operand type " << cerr_type((yyvsp[0].stack_entry)->type) <<" for unary operator '-'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyvsp[0].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        Address *tmp = create_new_temp();
                                                        emit(create_new_quad("-", ((yyvsp[0].stack_entry))->tac, NULL, tmp));
                                                        (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                        (yyval.stack_entry)->tac = tmp;
                                                    }
                                                }
#line 4645 "lalr1_modular.tab.c"
    break;

  case 171: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 1929 "milestone4/src/parser/lalr1_modular.y"
                                                                    { 
                                                                        if(pass_no == 2 )   {
                                                                                                (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                                                                                            } 
                                                                    }
#line 4655 "lalr1_modular.tab.c"
    break;

  case 172: /* PreIncrementExpression: Increment Primary  */
#line 1936 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        if((yyvsp[0].stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyvsp[0].stack_entry)->type) <<" for unary operator '++'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyvsp[0].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                        (yyval.stack_entry)->tac = pre_increament_3ac((yyvsp[0].stack_entry)->tac);
                                                    }
                                                }
#line 4675 "lalr1_modular.tab.c"
    break;

  case 173: /* PreIncrementExpression: Increment TypeName  */
#line 1951 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        (yyval.stack_entry) = find_variable_in_class((yyvsp[0].type_name), false);

                                                        if((yyval.stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyval.stack_entry)->type) <<" for unary operator '++'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyval.stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        (yyvsp[0].type_name)->tac = type_name_3ac((yyvsp[0].type_name), false);
                                                        // $2->tac = create_new_mem($$->token, $$->offset, $$->type);
                                                        (yyval.stack_entry)->tac = pre_increament_3ac((yyvsp[0].type_name)->tac); 
                                                    }
                                                }
#line 4698 "lalr1_modular.tab.c"
    break;

  case 174: /* PreDecrementExpression: Decrement Primary  */
#line 1971 "milestone4/src/parser/lalr1_modular.y"
                                            {       
                                                    if(pass_no == 2 ){   
                                                        if((yyvsp[0].stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyvsp[0].stack_entry)->type) <<" for unary operator '--'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyvsp[0].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                        (yyval.stack_entry)->tac = pre_decreament_3ac((yyvsp[0].stack_entry)->tac);
                                                    
                                                    }
                                            }
#line 4719 "lalr1_modular.tab.c"
    break;

  case 175: /* PreDecrementExpression: Decrement TypeName  */
#line 1987 "milestone4/src/parser/lalr1_modular.y"
                                            {       
                                                    if(pass_no == 2 ){  
                                                        (yyval.stack_entry) = find_variable_in_class((yyvsp[0].type_name), false);
                                                        if((yyval.stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyval.stack_entry)->type) <<" for unary operator '+'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyval.stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        (yyvsp[0].type_name)->tac = type_name_3ac((yyvsp[0].type_name), false);

                                                        // $2->tac = create_new_mem($$->token, $$->offset, $$->type);
                                                        
                                                        (yyval.stack_entry)->tac = pre_decreament_3ac((yyvsp[0].type_name)->tac);
                                                    }
                                            }
#line 4743 "lalr1_modular.tab.c"
    break;

  case 176: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 2008 "milestone4/src/parser/lalr1_modular.y"
                                                                    { 
                                                                        if(pass_no == 2 )   {
                                                                                                (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                                                                                            } 
                                                                    }
#line 4753 "lalr1_modular.tab.c"
    break;

  case 177: /* UnaryExpressionNotPlusMinus: Bitwise_complement UnaryExpression  */
#line 2013 "milestone4/src/parser/lalr1_modular.y"
                                                                    {   
                                                                        if(pass_no == 2 ){ 
                                                                            if((yyvsp[0].stack_entry)->type->arr_dim) {
                                                                                cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyvsp[0].stack_entry)->type) <<" for unary operator '~'\n";
                                                                                exit(1);
                                                                            } 

                                                                            if(!(yyvsp[0].stack_entry)->type->is_integral){
                                                                                cerr << "unary Expression type must be integral\n";
                                                                                exit(1);
                                                                            }
                                                                            (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                                            (yyval.stack_entry)->tac = create_new_temp();
                                                                            emit(create_new_quad("~", ((yyvsp[0].stack_entry))->tac, NULL, ((yyval.stack_entry))->tac));
                                                                            
                                                                        }
                                                                    }
#line 4775 "lalr1_modular.tab.c"
    break;

  case 178: /* UnaryExpressionNotPlusMinus: Not UnaryExpression  */
#line 2030 "milestone4/src/parser/lalr1_modular.y"
                                                                    {   
                                                                        if(pass_no == 2 ){ 
                                                                            if((yyvsp[0].stack_entry)->type->arr_dim) {
                                                                                cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyvsp[0].stack_entry)->type) <<" for unary operator '!'\n";
                                                                                exit(1);
                                                                            } 

                                                                            check_boolean((yyvsp[0].stack_entry)->type);
                                                                            
                                                                            (yyval.stack_entry) = (yyvsp[0].stack_entry);
                                                                            (yyval.stack_entry)->tac = create_new_temp();
                                                                            emit(create_new_quad("!", ((yyvsp[0].stack_entry))->tac, NULL, ((yyval.stack_entry))->tac));
                                                                            
                                                                        }
                                                                    }
#line 4795 "lalr1_modular.tab.c"
    break;

  case 179: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 2045 "milestone4/src/parser/lalr1_modular.y"
                                                                    { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4801 "lalr1_modular.tab.c"
    break;

  case 180: /* PostfixExpression: Primary  */
#line 2048 "milestone4/src/parser/lalr1_modular.y"
                                            { if(pass_no == 2 ) {
                                                                    (yyval.stack_entry) = (yyvsp[0].stack_entry); 
                                                                }
                                            }
#line 4810 "lalr1_modular.tab.c"
    break;

  case 181: /* PostfixExpression: TypeName  */
#line 2052 "milestone4/src/parser/lalr1_modular.y"
                                            {   if(pass_no == 2 ) {
                                                    (yyval.stack_entry) = find_variable_in_class((yyvsp[0].type_name), false);
                                                    (yyval.stack_entry)->tac = type_name_3ac((yyvsp[0].type_name), false);
                                                    // $$->tac = create_new_mem($$->token, $$->offset, $$->type);
                                                }
                                            }
#line 4821 "lalr1_modular.tab.c"
    break;

  case 182: /* PostfixExpression: PostIncrementExpression  */
#line 2058 "milestone4/src/parser/lalr1_modular.y"
                                            { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4827 "lalr1_modular.tab.c"
    break;

  case 183: /* PostfixExpression: PostDecrementExpression  */
#line 2059 "milestone4/src/parser/lalr1_modular.y"
                                            { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 4833 "lalr1_modular.tab.c"
    break;

  case 184: /* PostIncrementExpression: Primary Increment  */
#line 2062 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        if((yyvsp[-1].stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyvsp[-1].stack_entry)->type) <<" for unary operator '++'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyvsp[-1].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '++' \n first type: "<< ((yyvsp[-1].stack_entry))->type << "\n";
                                                            exit(-1);
                                                        }
                                                        (yyval.stack_entry) = (yyvsp[-1].stack_entry);
                                                        (yyval.stack_entry)->tac = post_increament_3ac((yyvsp[-1].stack_entry)->tac);
                                                    }
                                                }
#line 4853 "lalr1_modular.tab.c"
    break;

  case 185: /* PostIncrementExpression: TypeName Increment  */
#line 2077 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){  
                                                        (yyval.stack_entry) = find_variable_in_class((yyvsp[-1].type_name), false);

                                                        if((yyval.stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyval.stack_entry)->type) <<" for unary operator '++'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyval.stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '++' \n first type: "<< ((yyval.stack_entry))->type << "\n";
                                                            exit(-1);
                                                        }
                                                        (yyvsp[-1].type_name)->tac = type_name_3ac((yyvsp[-1].type_name), false);

                                                        // $1->tac = create_new_mem($$->token, $$->offset, $$->type);
                                                        
                                                        (yyval.stack_entry)->tac = post_increament_3ac((yyvsp[-1].type_name)->tac);
                                                    }
                                                }
#line 4878 "lalr1_modular.tab.c"
    break;

  case 186: /* PostDecrementExpression: Primary Decrement  */
#line 2099 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){

                                                        if((yyvsp[-1].stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyvsp[-1].stack_entry)->type) <<" for unary operator '--'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyvsp[-1].stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '--' \n first type: "<< ((yyvsp[-1].stack_entry))->type << "\n";
                                                            exit(-1);
                                                        }
                                                        
                                                        (yyval.stack_entry) = (yyvsp[-1].stack_entry);
                                                        (yyval.stack_entry)->tac = post_decreament_3ac((yyvsp[-1].stack_entry)->tac);
                                                    }
                                                }
#line 4900 "lalr1_modular.tab.c"
    break;

  case 187: /* PostDecrementExpression: TypeName Decrement  */
#line 2116 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2 ){

                                                        (yyval.stack_entry) = find_variable_in_class((yyvsp[-1].type_name), false);

                                                        if((yyval.stack_entry)->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type((yyval.stack_entry)->type) <<" for unary operator '--'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(((yyval.stack_entry))->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '--' \n first type: "<< ((yyval.stack_entry))->type << "\n";
                                                            exit(-1);
                                                        }
                                                        (yyvsp[-1].type_name)->tac = type_name_3ac((yyvsp[-1].type_name), false);
                                                        // $1->tac = create_new_mem($$->token, $$->offset, $$->type);

                                                        (yyval.stack_entry)->tac = post_decreament_3ac((yyvsp[-1].type_name)->tac);
                                                    }
                                                }
#line 4925 "lalr1_modular.tab.c"
    break;

  case 188: /* CastExpression: Lparen PrimitiveType Rparen UnaryExpression  */
#line 2138 "milestone4/src/parser/lalr1_modular.y"
                                                                                {   
                                                                                    if(pass_no == 2 ){
                                                                                        check_cast_types((yyvsp[-2].type), (yyvsp[0].stack_entry)->type);
                                                                                        (yyval.stack_entry) = make_stackentry("", (yyvsp[-2].type), yylineno);
                                                                                        (yyval.stack_entry)->tac = create_new_temp();
                                                                                        // Harshit: removing cast
                                                                                        // emit(create_new_quad("cast_to_" + $2->name, $4->tac, NULL, $$->tac));
                                                                                        emit(create_new_quad("cast", (yyvsp[0].stack_entry)->tac, NULL, (yyval.stack_entry)->tac));
                                                                                        // emit($4->type->name + "to_" + $2->name, $4->tac, "", $$->tac);
                                                                                    }
                                                                                }
#line 4941 "lalr1_modular.tab.c"
    break;

  case 189: /* CastExpression: Lparen ReferenceType Rparen UnaryExpressionNotPlusMinus  */
#line 2149 "milestone4/src/parser/lalr1_modular.y"
                                                                                {   
                                                                                    if(pass_no == 2 ){
                                                                                        check_cast_types((yyvsp[-2].type), (yyvsp[0].stack_entry)->type);
                                                                                        (yyval.stack_entry) = make_stackentry("", (yyvsp[-2].type), yylineno);
                                                                                        (yyval.stack_entry)->tac = create_new_temp();
                                                                                        // Harshit: removing cast
                                                                                        // emit(create_new_quad("cast_to_" + $2->name, $4->tac, NULL, $$->tac));
                                                                                        emit(create_new_quad("cast", (yyvsp[0].stack_entry)->tac, NULL, (yyval.stack_entry)->tac));
                                                                                        // emit($4->type->name + "to_" + $2->name, $4->tac, "", $$->tac);
                                                                                    }
                                                                                }
#line 4957 "lalr1_modular.tab.c"
    break;

  case 190: /* Block: Lcurly ScopeIncrement Rcurly  */
#line 2163 "milestone4/src/parser/lalr1_modular.y"
                                       { if(pass_no == 2 ){ clear_current_scope(); } }
#line 4963 "lalr1_modular.tab.c"
    break;

  case 191: /* Block: Lcurly ScopeIncrement BlockStatements Rcurly  */
#line 2164 "milestone4/src/parser/lalr1_modular.y"
                                                       { if(pass_no == 2 ){ clear_current_scope(); } }
#line 4969 "lalr1_modular.tab.c"
    break;

  case 192: /* BlockStatements: BlockStatements BlockStatement  */
#line 2167 "milestone4/src/parser/lalr1_modular.y"
                                                    { }
#line 4975 "lalr1_modular.tab.c"
    break;

  case 193: /* BlockStatements: BlockStatement  */
#line 2168 "milestone4/src/parser/lalr1_modular.y"
                                                    { }
#line 4981 "lalr1_modular.tab.c"
    break;

  case 194: /* BlockStatement: ClassOrInterfaceDeclaration  */
#line 2172 "milestone4/src/parser/lalr1_modular.y"
                                                { }
#line 4987 "lalr1_modular.tab.c"
    break;

  case 195: /* BlockStatement: LocalVariableDeclarationStatement  */
#line 2173 "milestone4/src/parser/lalr1_modular.y"
                                                        { }
#line 4993 "lalr1_modular.tab.c"
    break;

  case 196: /* BlockStatement: Statement  */
#line 2174 "milestone4/src/parser/lalr1_modular.y"
                                { }
#line 4999 "lalr1_modular.tab.c"
    break;

  case 197: /* LocalVariableDeclarationStatement: LocalVariableDeclaration Semicolon  */
#line 2177 "milestone4/src/parser/lalr1_modular.y"
                                                                          { if(pass_no == 2 ){ global_type = NULL; global_modifier= 0b0;} }
#line 5005 "lalr1_modular.tab.c"
    break;

  case 198: /* LocalVariableDeclaration: UnannTypeSubRoutine VariableDeclaratorList  */
#line 2180 "milestone4/src/parser/lalr1_modular.y"
                                                                          { global_type = NULL; free((yyvsp[-1].stack_entry)); }
#line 5011 "lalr1_modular.tab.c"
    break;

  case 199: /* $@6: %empty  */
#line 2181 "milestone4/src/parser/lalr1_modular.y"
                                      { if(pass_no == 2 ) global_type = get_type(__VAR); }
#line 5017 "lalr1_modular.tab.c"
    break;

  case 200: /* LocalVariableDeclaration: Var $@6 VariableDeclaratorList  */
#line 2181 "milestone4/src/parser/lalr1_modular.y"
                                                                                                                     { }
#line 5023 "lalr1_modular.tab.c"
    break;

  case 201: /* $@7: %empty  */
#line 2182 "milestone4/src/parser/lalr1_modular.y"
                                   { if(pass_no == 2 ) global_modifier = __FINAL; }
#line 5029 "lalr1_modular.tab.c"
    break;

  case 202: /* LocalVariableDeclaration: Final $@7 UnannTypeSubRoutine VariableDeclaratorList  */
#line 2182 "milestone4/src/parser/lalr1_modular.y"
                                                                                                                               { global_type = NULL; free((yyvsp[-1].stack_entry)); }
#line 5035 "lalr1_modular.tab.c"
    break;

  case 203: /* $@8: %empty  */
#line 2183 "milestone4/src/parser/lalr1_modular.y"
                                   { if(pass_no == 2 ) global_modifier = __FINAL; }
#line 5041 "lalr1_modular.tab.c"
    break;

  case 204: /* $@9: %empty  */
#line 2183 "milestone4/src/parser/lalr1_modular.y"
                                                                                           { if(pass_no == 2 ) global_type = get_type(__VAR); }
#line 5047 "lalr1_modular.tab.c"
    break;

  case 205: /* LocalVariableDeclaration: Final $@8 Var $@9 VariableDeclaratorList  */
#line 2183 "milestone4/src/parser/lalr1_modular.y"
                                                                                                                                                                         { }
#line 5053 "lalr1_modular.tab.c"
    break;

  case 206: /* Statement: StatementWithoutTrailingSubstatement  */
#line 2187 "milestone4/src/parser/lalr1_modular.y"
                                                           {}
#line 5059 "lalr1_modular.tab.c"
    break;

  case 207: /* Statement: LabeledStatement  */
#line 2188 "milestone4/src/parser/lalr1_modular.y"
                                       {}
#line 5065 "lalr1_modular.tab.c"
    break;

  case 208: /* Statement: IfThenStatement  */
#line 2189 "milestone4/src/parser/lalr1_modular.y"
                                      {}
#line 5071 "lalr1_modular.tab.c"
    break;

  case 209: /* Statement: IfThenElseStatement  */
#line 2190 "milestone4/src/parser/lalr1_modular.y"
                                        {}
#line 5077 "lalr1_modular.tab.c"
    break;

  case 210: /* Statement: WhileStatement  */
#line 2191 "milestone4/src/parser/lalr1_modular.y"
                                    {}
#line 5083 "lalr1_modular.tab.c"
    break;

  case 211: /* Statement: ForStatement  */
#line 2192 "milestone4/src/parser/lalr1_modular.y"
                                   {}
#line 5089 "lalr1_modular.tab.c"
    break;

  case 212: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 2195 "milestone4/src/parser/lalr1_modular.y"
                                                               {}
#line 5095 "lalr1_modular.tab.c"
    break;

  case 213: /* StatementNoShortIf: LabeledStatementNoShortIf  */
#line 2196 "milestone4/src/parser/lalr1_modular.y"
                                                   {}
#line 5101 "lalr1_modular.tab.c"
    break;

  case 214: /* StatementNoShortIf: IfThenElseStatementNoShortIf  */
#line 2197 "milestone4/src/parser/lalr1_modular.y"
                                                        {}
#line 5107 "lalr1_modular.tab.c"
    break;

  case 215: /* StatementNoShortIf: WhileStatementNoShortIf  */
#line 2198 "milestone4/src/parser/lalr1_modular.y"
                                                {}
#line 5113 "lalr1_modular.tab.c"
    break;

  case 216: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 2199 "milestone4/src/parser/lalr1_modular.y"
                                               {}
#line 5119 "lalr1_modular.tab.c"
    break;

  case 217: /* StatementWithoutTrailingSubstatement: Block  */
#line 2202 "milestone4/src/parser/lalr1_modular.y"
                                                {}
#line 5125 "lalr1_modular.tab.c"
    break;

  case 218: /* StatementWithoutTrailingSubstatement: EmptyStatement  */
#line 2203 "milestone4/src/parser/lalr1_modular.y"
                                                        {}
#line 5131 "lalr1_modular.tab.c"
    break;

  case 219: /* StatementWithoutTrailingSubstatement: ExpressionStatement  */
#line 2204 "milestone4/src/parser/lalr1_modular.y"
                                                            {}
#line 5137 "lalr1_modular.tab.c"
    break;

  case 220: /* StatementWithoutTrailingSubstatement: AssertStatement  */
#line 2205 "milestone4/src/parser/lalr1_modular.y"
                                                        {}
#line 5143 "lalr1_modular.tab.c"
    break;

  case 221: /* StatementWithoutTrailingSubstatement: BreakStatement  */
#line 2206 "milestone4/src/parser/lalr1_modular.y"
                                                        {}
#line 5149 "lalr1_modular.tab.c"
    break;

  case 222: /* StatementWithoutTrailingSubstatement: ContinueStatement  */
#line 2207 "milestone4/src/parser/lalr1_modular.y"
                                                          {}
#line 5155 "lalr1_modular.tab.c"
    break;

  case 223: /* StatementWithoutTrailingSubstatement: ReturnStatement  */
#line 2208 "milestone4/src/parser/lalr1_modular.y"
                                                        {}
#line 5161 "lalr1_modular.tab.c"
    break;

  case 224: /* StatementWithoutTrailingSubstatement: ThrowStatement  */
#line 2210 "milestone4/src/parser/lalr1_modular.y"
                                                       {}
#line 5167 "lalr1_modular.tab.c"
    break;

  case 225: /* StatementWithoutTrailingSubstatement: DoStatement  */
#line 2212 "milestone4/src/parser/lalr1_modular.y"
                                                      {}
#line 5173 "lalr1_modular.tab.c"
    break;

  case 226: /* EmptyStatement: Semicolon  */
#line 2222 "milestone4/src/parser/lalr1_modular.y"
                                { }
#line 5179 "lalr1_modular.tab.c"
    break;

  case 227: /* LabeledStatement: Identifier Colon Statement  */
#line 2225 "milestone4/src/parser/lalr1_modular.y"
                                                  { }
#line 5185 "lalr1_modular.tab.c"
    break;

  case 228: /* LabeledStatementNoShortIf: Identifier Colon StatementNoShortIf  */
#line 2228 "milestone4/src/parser/lalr1_modular.y"
                                                                    { }
#line 5191 "lalr1_modular.tab.c"
    break;

  case 229: /* ExpressionStatement: StatementExpression Semicolon  */
#line 2231 "milestone4/src/parser/lalr1_modular.y"
                                                        { (yyval.stack_entry) = (yyvsp[-1].stack_entry); }
#line 5197 "lalr1_modular.tab.c"
    break;

  case 230: /* StatementExpression: Assignment  */
#line 2234 "milestone4/src/parser/lalr1_modular.y"
                                    { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 5203 "lalr1_modular.tab.c"
    break;

  case 231: /* StatementExpression: PreIncrementExpression  */
#line 2235 "milestone4/src/parser/lalr1_modular.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 5209 "lalr1_modular.tab.c"
    break;

  case 232: /* StatementExpression: PreDecrementExpression  */
#line 2236 "milestone4/src/parser/lalr1_modular.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 5215 "lalr1_modular.tab.c"
    break;

  case 233: /* StatementExpression: PostIncrementExpression  */
#line 2237 "milestone4/src/parser/lalr1_modular.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 5221 "lalr1_modular.tab.c"
    break;

  case 234: /* StatementExpression: PostDecrementExpression  */
#line 2238 "milestone4/src/parser/lalr1_modular.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 5227 "lalr1_modular.tab.c"
    break;

  case 235: /* StatementExpression: MethodInvocation  */
#line 2239 "milestone4/src/parser/lalr1_modular.y"
                                                { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 5233 "lalr1_modular.tab.c"
    break;

  case 236: /* StatementExpression: ClassInstanceCreationExpression  */
#line 2240 "milestone4/src/parser/lalr1_modular.y"
                                                         { if(pass_no == 2 ) (yyval.stack_entry) = (yyvsp[0].stack_entry); }
#line 5239 "lalr1_modular.tab.c"
    break;

  case 237: /* IfCountIncrement: %empty  */
#line 2244 "milestone4/src/parser/lalr1_modular.y"
            {
                if(pass_no==2) (yyval.num) = ifnum++;
            }
#line 5247 "lalr1_modular.tab.c"
    break;

  case 238: /* IfThenStatementSubRoutine: IfCountIncrement IF Lparen Expression  */
#line 2249 "milestone4/src/parser/lalr1_modular.y"
                                             { 
                                if(pass_no == 2){
                                    IfCondition((yyvsp[0].stack_entry)); 
                                    (yyval.num) = (yyvsp[-3].num);
                                    Address* temp = create_new_temp();    /// WHYYYYYY??
                                    emit(create_new_comp("==" , (yyvsp[0].stack_entry)->tac , create_new_const("0", 4), ELSE_LABEL + to_string((yyvsp[-3].num))));
                                    emit(create_new_label(IF_LABEL+to_string((yyvsp[-3].num))));
                                }
                            }
#line 5261 "lalr1_modular.tab.c"
    break;

  case 239: /* IfThenStatement: IfThenStatementSubRoutine Rparen ScopeIncrement Statement  */
#line 2260 "milestone4/src/parser/lalr1_modular.y"
                                                                                {   
                                                                                    if(pass_no == 2){
                                                                                        
                                                                                        clear_current_scope(); 
                                                                                        emit(create_new_goto(ENDIF_LABEL + to_string((yyvsp[-3].num))));
                                                                                        emit(create_new_label(ELSE_LABEL+to_string((yyvsp[-3].num))));
                                                                                        emit(create_new_label(ENDIF_LABEL + to_string((yyvsp[-3].num)) ));
                                                                                    }
                                                                                }
#line 5275 "lalr1_modular.tab.c"
    break;

  case 240: /* IfThenThreeACSubRoutine: IfThenStatementSubRoutine Rparen ScopeIncrement StatementNoShortIf Else  */
#line 2271 "milestone4/src/parser/lalr1_modular.y"
                                                                                                    {   
                                                                                                        if(pass_no == 2)  {
                                                                                                            emit(create_new_goto(ENDIF_LABEL + to_string((yyvsp[-4].num))));
                                                                                                            emit(create_new_label(ELSE_LABEL+to_string((yyvsp[-4].num))));
                                                                                                            (yyval.num) = (yyvsp[-4].num);
                                                                                                        }
                                                                                                    }
#line 5287 "lalr1_modular.tab.c"
    break;

  case 241: /* IfThenElseStatement: IfThenThreeACSubRoutine Statement  */
#line 2280 "milestone4/src/parser/lalr1_modular.y"
                                                            {   
                                                                if(pass_no == 2){
                                                                    emit(create_new_label(ENDIF_LABEL + to_string((yyvsp[-1].num)) ));
                                                                    clear_current_scope(); 
                                                                }
                                                            }
#line 5298 "lalr1_modular.tab.c"
    break;

  case 242: /* IfThenElseStatementNoShortIf: IfThenThreeACSubRoutine StatementNoShortIf  */
#line 2288 "milestone4/src/parser/lalr1_modular.y"
                                                                            {   
                                                                                if(pass_no == 2){
                                                                                    emit(create_new_label(ENDIF_LABEL + to_string((yyvsp[-1].num)) ));
                                                                                    clear_current_scope(); 
                                                                                }
                                                                            }
#line 5309 "lalr1_modular.tab.c"
    break;

  case 243: /* AssertStatement: Assert Expression Semicolon  */
#line 2296 "milestone4/src/parser/lalr1_modular.y"
                                                {   
                                                    if(pass_no == 2){
                                                        AssertCondition((yyvsp[-1].stack_entry)); 
                                                        emit(create_new_comp("==", (yyvsp[-1].stack_entry)->tac, create_new_const("0", 4) , "exit"));
                                                    }
                                                }
#line 5320 "lalr1_modular.tab.c"
    break;

  case 244: /* $@10: %empty  */
#line 2306 "milestone4/src/parser/lalr1_modular.y"
          {if(pass_no ==2) emit(create_new_label(LOOP_LABEL + to_string((yyvsp[0].num))));}
#line 5326 "lalr1_modular.tab.c"
    break;

  case 245: /* WhileStatementSubRoutine: While $@10 Lparen Expression  */
#line 2307 "milestone4/src/parser/lalr1_modular.y"
                          {
                                if(pass_no == 2){
                                    WhileCondition((yyvsp[0].stack_entry)); 
                                    (yyval.num) = (yyvsp[-3].num);
                                    
                                    emit(create_new_comp("==", (yyvsp[0].stack_entry)->tac, create_new_const("0", 4), ENDLOOP_LABEL+to_string((yyvsp[-3].num))));
                                }
                            }
#line 5339 "lalr1_modular.tab.c"
    break;

  case 246: /* WhileStatement: WhileStatementSubRoutine Rparen Statement  */
#line 2317 "milestone4/src/parser/lalr1_modular.y"
                                                             {   
                                                                    if(pass_no == 2){
                                                                        emit(create_new_goto(LOOP_LABEL+to_string((yyvsp[-2].num))));
                                                                        emit(create_new_label(ENDLOOP_LABEL+to_string((yyvsp[-2].num))));
                                                                        clear_current_scope(); 
                                                                    }
                                                            }
#line 5351 "lalr1_modular.tab.c"
    break;

  case 247: /* WhileStatementNoShortIf: WhileStatementSubRoutine Rparen StatementNoShortIf  */
#line 2326 "milestone4/src/parser/lalr1_modular.y"
                                                                                {   
                                                                                    if(pass_no == 2){         
                                                                                        emit(create_new_goto(LOOP_LABEL+to_string((yyvsp[-2].num))));
                                                                                        emit(create_new_label(ENDLOOP_LABEL+to_string((yyvsp[-2].num))));                                                                           
                                                                                        clear_current_scope(); 
                                                                                    }
                                                                                }
#line 5363 "lalr1_modular.tab.c"
    break;

  case 248: /* $@11: %empty  */
#line 2336 "milestone4/src/parser/lalr1_modular.y"
        {
            if(pass_no == 2) emit(create_new_label(LOOP_LABEL + to_string((yyvsp[0].num)) ));  
        }
#line 5371 "lalr1_modular.tab.c"
    break;

  case 249: /* $@12: %empty  */
#line 2338 "milestone4/src/parser/lalr1_modular.y"
                          {if(pass_no == 2) loopnum--;}
#line 5377 "lalr1_modular.tab.c"
    break;

  case 250: /* $@13: %empty  */
#line 2338 "milestone4/src/parser/lalr1_modular.y"
                                                                          {     
                                                    if(pass_no == 2){ 
                                                        check_boolean((yyvsp[0].stack_entry)->type); 
                                                        emit(create_new_comp("== ", (yyvsp[0].stack_entry)->tac,create_new_const("1", 4) , LOOP_LABEL+ to_string((yyvsp[-6].num))));
                                                        emit(create_new_label(ENDLOOP_LABEL+to_string((yyvsp[-6].num))));
                                                    }
                                            }
#line 5389 "lalr1_modular.tab.c"
    break;

  case 251: /* DoStatement: do_ $@11 Statement While $@12 Lparen Expression $@13 Rparen Semicolon  */
#line 2344 "milestone4/src/parser/lalr1_modular.y"
                                                                { if(pass_no == 2) clear_current_scope(); }
#line 5395 "lalr1_modular.tab.c"
    break;

  case 256: /* For1SubRoutine: For5SubRoutine Expression  */
#line 2355 "milestone4/src/parser/lalr1_modular.y"
                                            { 
                                    if(pass_no == 2){
                                        ForCondition((yyvsp[0].stack_entry)); 
                                        emit(create_new_comp("==", (yyvsp[0].stack_entry)->tac, create_new_const("0", 4), ENDFOR_LABEL+ to_string((yyvsp[-1].num))));
                                        emit(create_new_comp("==", (yyvsp[0].stack_entry)->tac, create_new_const("1", 4), FORBODY_LABEL+ to_string((yyvsp[-1].num))));
                                        (yyval.num) = (yyvsp[-1].num);
                                    }
                                }
#line 5408 "lalr1_modular.tab.c"
    break;

  case 257: /* For2SubRoutine: For7SubRoutine Expression Semicolon  */
#line 2364 "milestone4/src/parser/lalr1_modular.y"
                                                      { 
                                    if(pass_no == 2){
                                        ForCondition((yyvsp[-1].stack_entry)); 
                                        emit(create_new_comp("==", (yyvsp[-1].stack_entry)->tac, create_new_const("0", 4), ENDFOR_LABEL+ to_string((yyvsp[-2].num))));
                                        emit(create_new_comp("==", (yyvsp[-1].stack_entry)->tac, create_new_const("1", 4), FORBODY_LABEL+ to_string((yyvsp[-2].num))));
                                        /*3ac Update*/ emit(create_new_label(FORUPDATE_LABEL + to_string((yyvsp[-2].num)) ));
                                        (yyval.num) = (yyvsp[-2].num);
                                    }
                                }
#line 5422 "lalr1_modular.tab.c"
    break;

  case 258: /* For3SubRoutine: For5SubRoutine Semicolon  */
#line 2374 "milestone4/src/parser/lalr1_modular.y"
                                         {  
                                            if(pass_no == 2){
                                                
                                                emit(create_new_goto(FORBODY_LABEL+ to_string((yyvsp[-1].num))));
                                                /*3ac Update*/ emit(create_new_label(FORUPDATE_LABEL + to_string((yyvsp[-1].num)) ));
                                                (yyval.num) = (yyvsp[-1].num);
                                            }
                                        }
#line 5435 "lalr1_modular.tab.c"
    break;

  case 259: /* For4SubRoutine: For7SubRoutine Semicolon  */
#line 2383 "milestone4/src/parser/lalr1_modular.y"
                                            {   
                                                if(pass_no == 2){
                                                    
                                                    emit(create_new_goto(FORBODY_LABEL+ to_string((yyvsp[-1].num))));
                                                    /*3ac Update*/ emit(create_new_label(FORUPDATE_LABEL + to_string((yyvsp[-1].num)) ));
                                                    (yyval.num) = (yyvsp[-1].num);
                                                }
                                            }
#line 5448 "lalr1_modular.tab.c"
    break;

  case 260: /* For5SubRoutine: For Lparen Semicolon  */
#line 2392 "milestone4/src/parser/lalr1_modular.y"
                                        {   
                                            if(pass_no == 2){
                                                emit(create_new_label(FORCOND_LABEL + to_string((yyvsp[-2].num)) ));
                                                (yyval.num) = (yyvsp[-2].num);
                                            }
                                        }
#line 5459 "lalr1_modular.tab.c"
    break;

  case 261: /* For6SubRoutine: For1SubRoutine Semicolon Rparen  */
#line 2399 "milestone4/src/parser/lalr1_modular.y"
                                                   {
                                        if(pass_no == 2){
                                            emit(create_new_label(FORUPDATE_LABEL + to_string((yyvsp[-2].num)) ));  // Not Required // Just for notation and clarity
                                            emit(create_new_goto(FORCOND_LABEL+ to_string((yyvsp[-2].num))));
                                            emit(create_new_label(FORBODY_LABEL + to_string((yyvsp[-2].num))));
                                            (yyval.num) = (yyvsp[-2].num);
                                        }
                                    }
#line 5472 "lalr1_modular.tab.c"
    break;

  case 262: /* For7SubRoutine: For Lparen ForInit Semicolon  */
#line 2408 "milestone4/src/parser/lalr1_modular.y"
                                                { 
                                            if(pass_no == 2){
                                                emit(create_new_label(FORCOND_LABEL + to_string((yyvsp[-3].num)) ));
                                                (yyval.num) = (yyvsp[-3].num);
                                            }
                                    }
#line 5483 "lalr1_modular.tab.c"
    break;

  case 263: /* For8SubRoutine: For3SubRoutine Rparen  */
#line 2415 "milestone4/src/parser/lalr1_modular.y"
                                      { 
                                        if(pass_no == 2){
                                            emit(create_new_label(FORUPDATE_LABEL + to_string((yyvsp[-1].num)) ));  // Not Required // Just for notation and clarity
                                            emit(create_new_goto(FORCOND_LABEL+ to_string((yyvsp[-1].num))));
                                            emit(create_new_label(FORBODY_LABEL + to_string((yyvsp[-1].num))));
                                            (yyval.num) = (yyvsp[-1].num);
                                        }
                                    }
#line 5496 "lalr1_modular.tab.c"
    break;

  case 264: /* For9SubRoutine: For4SubRoutine Rparen  */
#line 2424 "milestone4/src/parser/lalr1_modular.y"
                                       {    
                                            if(pass_no == 2){
                                                emit(create_new_label(FORUPDATE_LABEL + to_string((yyvsp[-1].num)) ));  // Not Required // Just for notation and clarity
                                                emit(create_new_goto(FORCOND_LABEL+ to_string((yyvsp[-1].num))));
                                                emit(create_new_label(FORBODY_LABEL + to_string((yyvsp[-1].num))));
                                                (yyval.num) = (yyvsp[-1].num);
                                            }
                                        }
#line 5509 "lalr1_modular.tab.c"
    break;

  case 265: /* For10SubRoutine: For3SubRoutine ForUpdate Rparen  */
#line 2433 "milestone4/src/parser/lalr1_modular.y"
                                                 {  
                                                    if(pass_no == 2){
                                                        emit(create_new_goto(FORCOND_LABEL+ to_string((yyvsp[-2].num))));
                                                        emit(create_new_label(FORBODY_LABEL + to_string((yyvsp[-2].num))));
                                                        (yyval.num) = (yyvsp[-2].num);
                                                    }
                                                }
#line 5521 "lalr1_modular.tab.c"
    break;

  case 266: /* For11SubRoutine: For2SubRoutine Rparen  */
#line 2441 "milestone4/src/parser/lalr1_modular.y"
                                       {  
                                                    if(pass_no == 2){
                                                        emit(create_new_label(FORUPDATE_LABEL + to_string((yyvsp[-1].num)) ));  // Not Required // Just for notation and clarity
                                                        emit(create_new_goto(FORCOND_LABEL+ to_string((yyvsp[-1].num))));
                                                        emit(create_new_label(FORBODY_LABEL + to_string((yyvsp[-1].num))));
                                                        (yyval.num) = (yyvsp[-1].num);
                                                    }
                                                }
#line 5534 "lalr1_modular.tab.c"
    break;

  case 267: /* For12SubRoutine: For4SubRoutine ForUpdate Rparen  */
#line 2450 "milestone4/src/parser/lalr1_modular.y"
                                                 {  
                                                    if(pass_no == 2){
                                                        emit(create_new_goto(FORCOND_LABEL+ to_string((yyvsp[-2].num))));
                                                        emit(create_new_label(FORBODY_LABEL + to_string((yyvsp[-2].num))));
                                                        (yyval.num) = (yyvsp[-2].num);
                                                    }
                                                }
#line 5546 "lalr1_modular.tab.c"
    break;

  case 268: /* For13SubRoutine: For1SubRoutine Semicolon ForUpdate Rparen  */
#line 2458 "milestone4/src/parser/lalr1_modular.y"
                                                             {  
                                                                if(pass_no == 2){
                                                                    emit(create_new_goto(FORCOND_LABEL+ to_string((yyvsp[-3].num))));
                                                                    emit(create_new_label(FORBODY_LABEL + to_string((yyvsp[-3].num))));
                                                                    (yyval.num) = (yyvsp[-3].num);
                                                                }
                                                            }
#line 5558 "lalr1_modular.tab.c"
    break;

  case 269: /* For14SubRoutine: For2SubRoutine ForUpdate Rparen  */
#line 2466 "milestone4/src/parser/lalr1_modular.y"
                                                 {    
                                                                if(pass_no == 2){
                                                                    emit(create_new_goto(FORCOND_LABEL+ to_string((yyvsp[-2].num))));
                                                                    emit(create_new_label(FORBODY_LABEL + to_string((yyvsp[-2].num))));
                                                                    (yyval.num) = (yyvsp[-2].num);
                                                                }
                                                            }
#line 5570 "lalr1_modular.tab.c"
    break;

  case 270: /* BasicForStatement: For8SubRoutine Statement  */
#line 2475 "milestone4/src/parser/lalr1_modular.y"
                                                 {              
                                                                if(pass_no == 2){
                                                                     
                                                                    emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                    emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }
#line 5584 "lalr1_modular.tab.c"
    break;

  case 271: /* BasicForStatement: For9SubRoutine Statement  */
#line 2485 "milestone4/src/parser/lalr1_modular.y"
                                                  { 
                                                    if(pass_no == 2){
                                                         
                                                        emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                        emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                        // $$ = $1;
                                                        clear_current_scope();
                                                    }
                                                }
#line 5598 "lalr1_modular.tab.c"
    break;

  case 272: /* BasicForStatement: For6SubRoutine Statement  */
#line 2494 "milestone4/src/parser/lalr1_modular.y"
                                                      {      
                                                            if(pass_no == 2){
                                                                 
                                                                emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                // $$ = $1;
                                                                clear_current_scope();
                                                            }
                                                        }
#line 5612 "lalr1_modular.tab.c"
    break;

  case 273: /* BasicForStatement: For10SubRoutine Statement  */
#line 2503 "milestone4/src/parser/lalr1_modular.y"
                                                   {    
                                                        if(pass_no == 2){
                                                             
                                                            emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                            emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                            // $$ = $1;
                                                            clear_current_scope();
                                                        }
                                                    }
#line 5626 "lalr1_modular.tab.c"
    break;

  case 274: /* BasicForStatement: For11SubRoutine Statement  */
#line 2513 "milestone4/src/parser/lalr1_modular.y"
                                                  {     
                                                        if(pass_no == 2){
                                                             
                                                            emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                            emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                            // $$ = $1;
                                                            clear_current_scope();
                                                        }
                                                    }
#line 5640 "lalr1_modular.tab.c"
    break;

  case 275: /* BasicForStatement: For12SubRoutine Statement  */
#line 2523 "milestone4/src/parser/lalr1_modular.y"
                                                  {     
                                                        if(pass_no == 2){
                                                             
                                                            emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                            emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                            // $$ = $1;
                                                            clear_current_scope();
                                                        }
                                                    }
#line 5654 "lalr1_modular.tab.c"
    break;

  case 276: /* BasicForStatement: For13SubRoutine Statement  */
#line 2533 "milestone4/src/parser/lalr1_modular.y"
                                                  { 
                                                    if(pass_no == 2){
                                                         
                                                        emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                        emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                        // $$ = $1;
                                                        clear_current_scope();
                                                    }
                                                }
#line 5668 "lalr1_modular.tab.c"
    break;

  case 277: /* BasicForStatement: For14SubRoutine Statement  */
#line 2543 "milestone4/src/parser/lalr1_modular.y"
                                                       {    
                                                            if(pass_no == 2){
                                                                 
                                                                emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                // $$ = $1;
                                                                clear_current_scope();
                                                            }
                                                        }
#line 5682 "lalr1_modular.tab.c"
    break;

  case 278: /* BasicForStatementNoShortIf: For8SubRoutine StatementNoShortIf  */
#line 2556 "milestone4/src/parser/lalr1_modular.y"
                                                          {     
                                                                if(pass_no == 2){  
                                                                    emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                    emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }
#line 5695 "lalr1_modular.tab.c"
    break;

  case 279: /* BasicForStatementNoShortIf: For9SubRoutine StatementNoShortIf  */
#line 2565 "milestone4/src/parser/lalr1_modular.y"
                                                          {     
                                                                if(pass_no == 2){
                                                                    emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                    emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }
#line 5708 "lalr1_modular.tab.c"
    break;

  case 280: /* BasicForStatementNoShortIf: For6SubRoutine StatementNoShortIf  */
#line 2573 "milestone4/src/parser/lalr1_modular.y"
                                                               {    if(pass_no == 2){
                                                                        emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                        emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                        // $$ = $1;
                                                                        clear_current_scope();
                                                                    }
                                                                }
#line 5720 "lalr1_modular.tab.c"
    break;

  case 281: /* BasicForStatementNoShortIf: For10SubRoutine StatementNoShortIf  */
#line 2580 "milestone4/src/parser/lalr1_modular.y"
                                                           {    
                                                                if(pass_no == 2){        
                                                                     
                                                                    emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                    emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }
#line 5734 "lalr1_modular.tab.c"
    break;

  case 282: /* BasicForStatementNoShortIf: For11SubRoutine StatementNoShortIf  */
#line 2590 "milestone4/src/parser/lalr1_modular.y"
                                                           {    
                                                                if(pass_no == 2){
                                                                     
                                                                    emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                    emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }
#line 5748 "lalr1_modular.tab.c"
    break;

  case 283: /* BasicForStatementNoShortIf: For12SubRoutine StatementNoShortIf  */
#line 2600 "milestone4/src/parser/lalr1_modular.y"
                                                           {    
                                                                if(pass_no == 2){
                                                                     
                                                                    emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                    emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }
#line 5762 "lalr1_modular.tab.c"
    break;

  case 284: /* BasicForStatementNoShortIf: For13SubRoutine StatementNoShortIf  */
#line 2610 "milestone4/src/parser/lalr1_modular.y"
                                                           {    
                                                                if(pass_no == 2){
                                                                     
                                                                    emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                    emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }
#line 5776 "lalr1_modular.tab.c"
    break;

  case 285: /* BasicForStatementNoShortIf: For14SubRoutine StatementNoShortIf  */
#line 2620 "milestone4/src/parser/lalr1_modular.y"
                                                                {   
                                                                    if(pass_no == 2){
                                                                         
                                                                        emit(create_new_goto(FORUPDATE_LABEL + to_string((yyvsp[-1].num))));
                                                                        emit(create_new_label(ENDFOR_LABEL + to_string((yyvsp[-1].num)) )); 
                                                                        // $$ = $1;
                                                                        clear_current_scope();
                                                                    }
                                                                }
#line 5790 "lalr1_modular.tab.c"
    break;

  case 286: /* ForInit: StatementExpressionList  */
#line 2632 "milestone4/src/parser/lalr1_modular.y"
                                        {}
#line 5796 "lalr1_modular.tab.c"
    break;

  case 287: /* ForInit: LocalVariableDeclaration  */
#line 2633 "milestone4/src/parser/lalr1_modular.y"
                                       {}
#line 5802 "lalr1_modular.tab.c"
    break;

  case 288: /* ForUpdate: StatementExpressionList  */
#line 2636 "milestone4/src/parser/lalr1_modular.y"
                                       {}
#line 5808 "lalr1_modular.tab.c"
    break;

  case 289: /* StatementExpressionList: StatementExpression  */
#line 2639 "milestone4/src/parser/lalr1_modular.y"
                                                {}
#line 5814 "lalr1_modular.tab.c"
    break;

  case 290: /* StatementExpressionList: StatementExpression CommaStatementExpressions  */
#line 2640 "milestone4/src/parser/lalr1_modular.y"
                                                                           {}
#line 5820 "lalr1_modular.tab.c"
    break;

  case 291: /* CommaStatementExpressions: Comma StatementExpression CommaStatementExpressions  */
#line 2643 "milestone4/src/parser/lalr1_modular.y"
                                                                                   {}
#line 5826 "lalr1_modular.tab.c"
    break;

  case 292: /* CommaStatementExpressions: Comma StatementExpression  */
#line 2644 "milestone4/src/parser/lalr1_modular.y"
                                                       {}
#line 5832 "lalr1_modular.tab.c"
    break;

  case 293: /* EnhancedForStatementSubRoutine: For Lparen LocalVariableDeclaration Colon Expression  */
#line 2648 "milestone4/src/parser/lalr1_modular.y"
                                                         { if(pass_no == 2) EnhancedForCondition((yyvsp[0].stack_entry)); }
#line 5838 "lalr1_modular.tab.c"
    break;

  case 294: /* EnhancedForStatement: EnhancedForStatementSubRoutine Rparen Statement  */
#line 2651 "milestone4/src/parser/lalr1_modular.y"
                                                                          { if(pass_no == 2) emit(create_new_goto(FORUPDATE_LABEL+to_string(loopnum-1))); }
#line 5844 "lalr1_modular.tab.c"
    break;

  case 295: /* EnhancedForStatementNoShortIf: EnhancedForStatementSubRoutine Rparen StatementNoShortIf  */
#line 2654 "milestone4/src/parser/lalr1_modular.y"
                                                                                              { if(pass_no == 2) emit(create_new_goto(FORUPDATE_LABEL+to_string(loopnum-1))); }
#line 5850 "lalr1_modular.tab.c"
    break;

  case 296: /* BreakStatement: Break Semicolon  */
#line 2657 "milestone4/src/parser/lalr1_modular.y"
                                   { if(pass_no == 2) emit(create_new_goto(ENDLOOP_LABEL+to_string(loopnum-1))); }
#line 5856 "lalr1_modular.tab.c"
    break;

  case 297: /* ContinueStatement: Continue Semicolon  */
#line 2665 "milestone4/src/parser/lalr1_modular.y"
                                        { if(pass_no == 2) emit(create_new_goto(LOOP_LABEL+to_string(loopnum-1)));}
#line 5862 "lalr1_modular.tab.c"
    break;

  case 298: /* ReturnStatement: Return Expression Semicolon  */
#line 2670 "milestone4/src/parser/lalr1_modular.y"
                                {   
                                    if(pass_no == 2){
                                        if(!check_return_type(current_table->return_type, ((yyvsp[-1].stack_entry))->type)) {
                                            cerr << "Cannot return " << cerr_type(((yyvsp[-1].stack_entry))->type) << " from function whose return type is " << cerr_type(current_table->return_type) << "\n";
                                            exit(-1);
                                        }
                                        // emit("return" , $2->tac,"","");

                                        // Move return value to eax
                                        emit(create_new_return((yyvsp[-1].stack_entry)->tac, true));
                                        emit(create_new_goto("ret"));
                                    }
                                }
#line 5880 "lalr1_modular.tab.c"
    break;

  case 299: /* ReturnStatement: Return Semicolon  */
#line 2683 "milestone4/src/parser/lalr1_modular.y"
                      {     
                            if(pass_no == 2){
                                if(!check_return_type(current_table->return_type, get_type(__VOID))) {
                                            cerr << "Cannot return " << __VOID << " from function whose return type is " << cerr_type(current_table->return_type) << "\n";
                                            exit(-1);
                                }
                                // emit("return","","","");
                                emit(create_new_goto("ret"));
                            }
                     }
#line 5895 "lalr1_modular.tab.c"
    break;

  case 300: /* ThrowStatement: Throw Expression Semicolon  */
#line 2695 "milestone4/src/parser/lalr1_modular.y"
                                                { }
#line 5901 "lalr1_modular.tab.c"
    break;

  case 301: /* Int: INT  */
#line 2727 "milestone4/src/parser/lalr1_modular.y"
            { (yyval.type) = get_type(__INT); }
#line 5907 "lalr1_modular.tab.c"
    break;

  case 302: /* Long: LONG  */
#line 2730 "milestone4/src/parser/lalr1_modular.y"
            { (yyval.type) = get_type(__LONG); }
#line 5913 "lalr1_modular.tab.c"
    break;

  case 303: /* Byte: BYTE  */
#line 2733 "milestone4/src/parser/lalr1_modular.y"
            { (yyval.type) = get_type(__BYTE); }
#line 5919 "lalr1_modular.tab.c"
    break;

  case 304: /* Short: SHORT  */
#line 2736 "milestone4/src/parser/lalr1_modular.y"
              { (yyval.type) = get_type(__SHORT); }
#line 5925 "lalr1_modular.tab.c"
    break;

  case 305: /* Char: CHAR  */
#line 2739 "milestone4/src/parser/lalr1_modular.y"
             { (yyval.type) = get_type(__CHAR); }
#line 5931 "lalr1_modular.tab.c"
    break;

  case 306: /* Float: FLOAT  */
#line 2742 "milestone4/src/parser/lalr1_modular.y"
                        { (yyval.type) = get_type(__FLOAT); }
#line 5937 "lalr1_modular.tab.c"
    break;

  case 307: /* Double: DOUBLE  */
#line 2745 "milestone4/src/parser/lalr1_modular.y"
                        { (yyval.type) = get_type(__DOUBLE); }
#line 5943 "lalr1_modular.tab.c"
    break;

  case 308: /* Boolean: BOOLEAN  */
#line 2748 "milestone4/src/parser/lalr1_modular.y"
                        { (yyval.type) = get_type(__BOOLEAN); }
#line 5949 "lalr1_modular.tab.c"
    break;

  case 309: /* Var: VAR  */
#line 2751 "milestone4/src/parser/lalr1_modular.y"
                        { (yyval.type) = get_type(__VAR); }
#line 5955 "lalr1_modular.tab.c"
    break;

  case 310: /* Else: ELSE  */
#line 2757 "milestone4/src/parser/lalr1_modular.y"
            { }
#line 5961 "lalr1_modular.tab.c"
    break;

  case 311: /* While: WHILE  */
#line 2760 "milestone4/src/parser/lalr1_modular.y"
                { 
                    if(pass_no == 2){
                        increase_current_level(); 
                        (yyval.num) = loopnum++;
                    }
                }
#line 5972 "lalr1_modular.tab.c"
    break;

  case 312: /* For: FOR  */
#line 2768 "milestone4/src/parser/lalr1_modular.y"
                {   
                    if(pass_no == 2){
                        increase_current_level(); 
                        (yyval.num) = loopnum++; 
                    }
                }
#line 5983 "lalr1_modular.tab.c"
    break;

  case 313: /* do_: DO  */
#line 2776 "milestone4/src/parser/lalr1_modular.y"
                {   
                    if(pass_no == 2){
                        increase_current_level(); 
                        (yyval.num) = loopnum++; 
                    }
                }
#line 5994 "lalr1_modular.tab.c"
    break;

  case 314: /* Break: BREAK  */
#line 2784 "milestone4/src/parser/lalr1_modular.y"
              { }
#line 6000 "lalr1_modular.tab.c"
    break;

  case 315: /* Continue: CONTINUE  */
#line 2787 "milestone4/src/parser/lalr1_modular.y"
                    { }
#line 6006 "lalr1_modular.tab.c"
    break;

  case 316: /* Void: VOID  */
#line 2790 "milestone4/src/parser/lalr1_modular.y"
            { (yyval.type) = get_type(__VOID); }
#line 6012 "lalr1_modular.tab.c"
    break;

  case 317: /* New: NEW  */
#line 2793 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 6018 "lalr1_modular.tab.c"
    break;

  case 318: /* Return: RETURN  */
#line 2796 "milestone4/src/parser/lalr1_modular.y"
                { }
#line 6024 "lalr1_modular.tab.c"
    break;

  case 319: /* Public: PUBLIC  */
#line 2799 "milestone4/src/parser/lalr1_modular.y"
                 {}
#line 6030 "lalr1_modular.tab.c"
    break;

  case 320: /* Private: PRIVATE  */
#line 2802 "milestone4/src/parser/lalr1_modular.y"
                  {}
#line 6036 "lalr1_modular.tab.c"
    break;

  case 321: /* Class: CLASS  */
#line 2805 "milestone4/src/parser/lalr1_modular.y"
              { }
#line 6042 "lalr1_modular.tab.c"
    break;

  case 322: /* Static: STATIC  */
#line 2808 "milestone4/src/parser/lalr1_modular.y"
                {}
#line 6048 "lalr1_modular.tab.c"
    break;

  case 323: /* Final: FINAL  */
#line 2811 "milestone4/src/parser/lalr1_modular.y"
              {}
#line 6054 "lalr1_modular.tab.c"
    break;

  case 324: /* Assert: ASSERT  */
#line 2814 "milestone4/src/parser/lalr1_modular.y"
                { }
#line 6060 "lalr1_modular.tab.c"
    break;

  case 325: /* This: THIS  */
#line 2817 "milestone4/src/parser/lalr1_modular.y"
            { 
                struct stackentry* entry = make_stackentry("this", get_type(current_class->name), yylineno); 
                (yyval.stack_entry) = entry;
            }
#line 6069 "lalr1_modular.tab.c"
    break;

  case 326: /* Throw: THROW  */
#line 2829 "milestone4/src/parser/lalr1_modular.y"
              { }
#line 6075 "lalr1_modular.tab.c"
    break;

  case 327: /* Plus: PLUS  */
#line 2866 "milestone4/src/parser/lalr1_modular.y"
            { }
#line 6081 "lalr1_modular.tab.c"
    break;

  case 328: /* Minus: MINUS  */
#line 2869 "milestone4/src/parser/lalr1_modular.y"
              { }
#line 6087 "lalr1_modular.tab.c"
    break;

  case 329: /* Div: DIV  */
#line 2872 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 6093 "lalr1_modular.tab.c"
    break;

  case 330: /* Asterik: ASTERIK  */
#line 2875 "milestone4/src/parser/lalr1_modular.y"
                  { }
#line 6099 "lalr1_modular.tab.c"
    break;

  case 331: /* Modulo: MODULO  */
#line 2878 "milestone4/src/parser/lalr1_modular.y"
                { }
#line 6105 "lalr1_modular.tab.c"
    break;

  case 332: /* Increment: INCREMENT  */
#line 2881 "milestone4/src/parser/lalr1_modular.y"
                      { }
#line 6111 "lalr1_modular.tab.c"
    break;

  case 333: /* Decrement: DECREMENT  */
#line 2884 "milestone4/src/parser/lalr1_modular.y"
                      { }
#line 6117 "lalr1_modular.tab.c"
    break;

  case 334: /* Geq: GEQ  */
#line 2887 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 6123 "lalr1_modular.tab.c"
    break;

  case 335: /* Leq: LEQ  */
#line 2890 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 6129 "lalr1_modular.tab.c"
    break;

  case 336: /* Gt: GT  */
#line 2893 "milestone4/src/parser/lalr1_modular.y"
        { }
#line 6135 "lalr1_modular.tab.c"
    break;

  case 337: /* Lt: LT  */
#line 2896 "milestone4/src/parser/lalr1_modular.y"
        { }
#line 6141 "lalr1_modular.tab.c"
    break;

  case 338: /* Neq: NEQ  */
#line 2899 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 6147 "lalr1_modular.tab.c"
    break;

  case 339: /* Deq: DEQ  */
#line 2902 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 6153 "lalr1_modular.tab.c"
    break;

  case 340: /* Bitwise_and: BITWISE_AND  */
#line 2905 "milestone4/src/parser/lalr1_modular.y"
                          { }
#line 6159 "lalr1_modular.tab.c"
    break;

  case 341: /* Bitwise_or: BITWISE_OR  */
#line 2908 "milestone4/src/parser/lalr1_modular.y"
                        { }
#line 6165 "lalr1_modular.tab.c"
    break;

  case 342: /* Bitwise_xor: BITWISE_XOR  */
#line 2911 "milestone4/src/parser/lalr1_modular.y"
                          { }
#line 6171 "lalr1_modular.tab.c"
    break;

  case 343: /* Bitwise_complement: BITWISE_COMPLEMENT  */
#line 2914 "milestone4/src/parser/lalr1_modular.y"
                                        { }
#line 6177 "lalr1_modular.tab.c"
    break;

  case 344: /* Left_shift: LEFT_SHIFT  */
#line 2917 "milestone4/src/parser/lalr1_modular.y"
                        { }
#line 6183 "lalr1_modular.tab.c"
    break;

  case 345: /* Right_shift: RIGHT_SHIFT  */
#line 2920 "milestone4/src/parser/lalr1_modular.y"
                          { }
#line 6189 "lalr1_modular.tab.c"
    break;

  case 346: /* Unsigned_right_shift: UNSIGNED_RIGHT_SHIFT  */
#line 2923 "milestone4/src/parser/lalr1_modular.y"
                                            { }
#line 6195 "lalr1_modular.tab.c"
    break;

  case 347: /* And: AND  */
#line 2926 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 6201 "lalr1_modular.tab.c"
    break;

  case 348: /* Or: OR  */
#line 2929 "milestone4/src/parser/lalr1_modular.y"
        { }
#line 6207 "lalr1_modular.tab.c"
    break;

  case 349: /* Not: NOT  */
#line 2932 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 6213 "lalr1_modular.tab.c"
    break;

  case 350: /* AssignmentOperator: ASSIGNMENT  */
#line 2935 "milestone4/src/parser/lalr1_modular.y"
                                {   
                                    strcpy((yyval.threeac_label), (yyvsp[0].str));
                                }
#line 6221 "lalr1_modular.tab.c"
    break;

  case 351: /* Assign: ASSIGN  */
#line 2940 "milestone4/src/parser/lalr1_modular.y"
               { }
#line 6227 "lalr1_modular.tab.c"
    break;

  case 352: /* Colon: COLON  */
#line 2942 "milestone4/src/parser/lalr1_modular.y"
              { }
#line 6233 "lalr1_modular.tab.c"
    break;

  case 353: /* Qm: QM  */
#line 2945 "milestone4/src/parser/lalr1_modular.y"
        { }
#line 6239 "lalr1_modular.tab.c"
    break;

  case 354: /* Lparen: LPAREN  */
#line 2948 "milestone4/src/parser/lalr1_modular.y"
                { }
#line 6245 "lalr1_modular.tab.c"
    break;

  case 355: /* Rparen: RPAREN  */
#line 2951 "milestone4/src/parser/lalr1_modular.y"
                { }
#line 6251 "lalr1_modular.tab.c"
    break;

  case 356: /* Lcurly: LCURLY  */
#line 2954 "milestone4/src/parser/lalr1_modular.y"
                { }
#line 6257 "lalr1_modular.tab.c"
    break;

  case 357: /* Rcurly: RCURLY  */
#line 2957 "milestone4/src/parser/lalr1_modular.y"
                { }
#line 6263 "lalr1_modular.tab.c"
    break;

  case 358: /* Lsquare: LSQUARE  */
#line 2960 "milestone4/src/parser/lalr1_modular.y"
                  { }
#line 6269 "lalr1_modular.tab.c"
    break;

  case 359: /* Rsquare: RSQUARE  */
#line 2963 "milestone4/src/parser/lalr1_modular.y"
                  { }
#line 6275 "lalr1_modular.tab.c"
    break;

  case 360: /* Semicolon: SEMICOLON  */
#line 2966 "milestone4/src/parser/lalr1_modular.y"
                      { }
#line 6281 "lalr1_modular.tab.c"
    break;

  case 361: /* Comma: COMMA  */
#line 2969 "milestone4/src/parser/lalr1_modular.y"
              { }
#line 6287 "lalr1_modular.tab.c"
    break;

  case 362: /* Dot: DOT  */
#line 2972 "milestone4/src/parser/lalr1_modular.y"
          { }
#line 6293 "lalr1_modular.tab.c"
    break;

  case 363: /* Char_literal: CHAR_LITERAL  */
#line 2977 "milestone4/src/parser/lalr1_modular.y"
                                { 
                                    (yyval.stack_entry) = make_stackentry((yyvsp[0].str), get_type(__CHAR), yylineno); 
                                    if(pass_no == 2){
                                        (yyval.stack_entry)->tac = create_new_const((yyvsp[0].str), 8);
                                    }
                                }
#line 6304 "lalr1_modular.tab.c"
    break;

  case 364: /* Boolean_literal: BOOLEAN_LITERAL  */
#line 2985 "milestone4/src/parser/lalr1_modular.y"
                                  { 
                                    (yyval.stack_entry) = make_stackentry((yyvsp[0].str), get_type(__BOOLEAN), yylineno); 
                                    cout << (yyvsp[0].str);
                                    if(pass_no == 2){
                                        if((yyvsp[0].str) == "true")
                                            (yyval.stack_entry)->tac = create_new_const(to_string(1), 8);
                                        else 
                                            (yyval.stack_entry)->tac = create_new_const(to_string(0), 8);

                                    }
                                }
#line 6320 "lalr1_modular.tab.c"
    break;

  case 365: /* Null_literal: NULL_LITERAL  */
#line 2998 "milestone4/src/parser/lalr1_modular.y"
                                { 
                                    (yyval.stack_entry) = make_stackentry((yyvsp[0].str), yylineno); 
                                    if(pass_no == 2){
                                        (yyval.stack_entry)->tac = create_new_const((yyvsp[0].str), 0);
                                    }
                                }
#line 6331 "lalr1_modular.tab.c"
    break;

  case 366: /* Integer_literal: INTEGER_LITERAL  */
#line 3006 "milestone4/src/parser/lalr1_modular.y"
                                  { 
                                    (yyval.stack_entry) = make_stackentry((yyvsp[0].str), get_type(__INT), yylineno);
                                    if(pass_no == 2){
                                        (yyval.stack_entry)->tac = create_new_const((yyvsp[0].str), 8);
                                    } 
                                }
#line 6342 "lalr1_modular.tab.c"
    break;

  case 367: /* Fp_literal: FP_LITERAL  */
#line 3014 "milestone4/src/parser/lalr1_modular.y"
                            { 
                                    (yyval.stack_entry) = make_stackentry((yyvsp[0].str), get_type(__FLOAT), yylineno); 
                                    if(pass_no == 2){
                                        (yyval.stack_entry)->tac = create_new_const((yyvsp[0].str), 4);
                                    }
                                }
#line 6353 "lalr1_modular.tab.c"
    break;

  case 368: /* String: STRING  */
#line 3022 "milestone4/src/parser/lalr1_modular.y"
                            { 
                                    (yyval.stack_entry) = make_stackentry((yyvsp[0].str), yylineno); 
                                    if(pass_no == 2){
                                        (yyval.stack_entry)->tac = create_new_const((yyvsp[0].str), 4);
                                    }
                                }
#line 6364 "lalr1_modular.tab.c"
    break;

  case 369: /* Text_block: TEXT_BLOCK  */
#line 3030 "milestone4/src/parser/lalr1_modular.y"
                                { 
                                    (yyval.stack_entry) = make_stackentry((yyvsp[0].str), yylineno); 
                                    if(pass_no == 2){
                                        (yyval.stack_entry)->tac = create_new_const((yyvsp[0].str), 4);
                                    }
                                }
#line 6375 "lalr1_modular.tab.c"
    break;

  case 370: /* Identifier: IDENTIFIER  */
#line 3038 "milestone4/src/parser/lalr1_modular.y"
                                { 
                                    (yyval.id) = make_identifier((yyvsp[0].str));
                                }
#line 6383 "lalr1_modular.tab.c"
    break;

  case 371: /* endoffile: EOF_  */
#line 3048 "milestone4/src/parser/lalr1_modular.y"
                 { }
#line 6389 "lalr1_modular.tab.c"
    break;


#line 6393 "lalr1_modular.tab.c"

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

#line 3050 "milestone4/src/parser/lalr1_modular.y"


void reset_global_params() {
    // cerr << "In yywrap Pass "<< pass_no << "\n";

    global_table->dump_table();
    verify_pass1();
    pass_no++;

    // fclose(yyin);
    // yyin = fopen(filename.c_str(), "r");
    // rewind(yyin);
    yylineno = 1; 
    current_scope = scope_global;
    global_modifier = 0b0;
    global_type = NULL;
    current_class = NULL;
}

string print_(Address* addr){
    if(addr!= NULL)
        return addr->name;
    return "";
}

void print_3ac(){
    Quad *quad_p;
    Arg  *arg_p;
    Label *label_p;
    Return *return_p;
    Call *call_p;
    Goto* goto_p;
    Reg* reg_p;
    Comp* comp_p;

    for (auto instr: global_tacs) {
        quad_p = dynamic_cast<Quad *> (instr);
        if (quad_p != nullptr) {
            cout << "Quad: " <<  quad_p->operation << " " << print_(quad_p->arg1) << " " << print_(quad_p->arg2) << " " << print_(quad_p->result) << "\n";
            continue;
        }
        arg_p = dynamic_cast<Arg *> (instr);
        if (arg_p != nullptr) {
            cout << "Arg: " << print_(arg_p->arg) << " " << arg_p->offset << "\n";
            continue;
        }

        label_p = dynamic_cast<Label *> (instr);
        if (label_p != nullptr) {
            cout << "Label: " << label_p->name << "\n";
            continue;
        }
        return_p = dynamic_cast<Return *> (instr);
        if (return_p != nullptr) {
            cout << "Return: " << print_(return_p->ret_value) << " " << return_p->push << "\n";
            continue;
        }
        call_p = dynamic_cast<Call *> (instr);
        if (call_p != nullptr) {
            cout << "Call: " << call_p->function_name << " " << call_p->arg_count << "\n";
            continue;
        }

        goto_p = dynamic_cast<Goto *> (instr);
        if (goto_p != nullptr) {
            cout << "Goto: " << goto_p->label->name << "\n";
            continue;
        }

        reg_p = dynamic_cast<Reg *> (instr);
        if (reg_p != nullptr) {
            cout << "Reg: " << reg_p->reg_name << " " <<  reg_p->size << " " << reg_p->add << "\n";
            continue;
        }

        comp_p = dynamic_cast<Comp *> (instr);
        if (comp_p != nullptr) {
            cout << "Comp: " << comp_p->comp_operator << " " << print_(comp_p->arg1) << " " << print_(comp_p->arg2) << " " << comp_p->label << "\n";
            continue;
        }

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
    argparse::ArgumentParser program("javas");

    struct args *_args = new struct args;


    program.add_argument("--input")
        .required()
        .help("java file to parse");

    /* program.add_argument("--output")
    
        .help("output dot file"); */

    program.add_argument("--verbose")
        .help("increase output verbosity for parser")
        .default_value(false)
        .implicit_value(true);

 
    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err) {
        std::cerr << "Line No: " <<  yylineno  << err.what() << std::endl;
        std::cerr << "Line No: " <<  yylineno  << program;
        std::exit(1);
    }


    _args->input = (char*)(program.get<std::string>("--input").c_str());

  

    /* _args->output = (char*)(program.get<std::string>("--output").c_str()); */
 
    if (program["--verbose"] == true) {
        _args->verbose = true;
        yydebug = 1;
    } 
    
    

    yyin = fopen(_args->input, "r");

    if(yyin == NULL) {
        cerr << "Line No: " <<  yylineno  << "FIle Not Found\n";
        exit(-1);
    }

    do {
        yyparse();
    } while(!feof(yyin));

    fclose(yyin);
    
    reset_global_params();
    
    yylex_destroy();
    
    yyin = fopen(_args->input, "r");

    do {
        yyparse();
    } while(!feof(yyin));

    print_3ac();



    return 0;
 }

int yyerror(const char *s) {
    cerr << "syntax error: line " << yylineno << ": " << s << "\n";
    dotfile.close();
    exit(1);
}
