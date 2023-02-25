%{
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

    void check_type_identifier(char *typeid) {
        if (!strcmp(typeid, "permits") ||
            !strcmp(typeid, "record") ||
            !strcmp(typeid, "sealed") ||
            !strcmp(typeid, "var") || 
            !strcmp(typeid, "yield"))
        {
            printf("%s not allowed here\n", typeid);
            throw_error("type identifier error\n", yylineno);
        }
    }

    void check_unq_mthd_id(char *id) {
        if (!strcmp(id, "yield")) {
            printf("%s not allowed here\n", id);
            throw_error("unqualified method identifier error\n", yylineno);
        }
    }



%}

%define parse.error verbose

%union {
    int num;
    double float_num;
    char* str;
}

%token CONST
%token INT
%token LONG
%token BYTE
%token CHAR
%token SHORT
%token FLOAT
%token DOUBLE
%token BOOLEAN
%token NEW
%token IF
%token ELSE
%token FOR
%token WHILE
%token BREAK
%token CONTINUE
%token VOID
%token RETURN
%token PUBLIC
%token PRIVATE
%token CLASS
%token INTERFACE
%token STATIC
%token FINAL
%token VAR
%token ASSERT
%token SWITCH
%token CASE
%token DEFAULT
%token PLUS
%token MINUS
%token MUL
%token DIV
%token MODULO
%token INCREMENT
%token DECREMENT
%token GEQ
%token LEQ
%token GT
%token LT
%token NEQ
%token DEQ
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_XOR
%token BITWISE_COMPLEMENT
%token LEFT_SHIFT
%token RIGHT_SHIFT
%token UNSIGNED_RIGHT_SHIFT
%token AND
%token OR
%token NOT
%token ASSIGNMENT
%token DOUBLE_COLON
%token COLON
%token QM
%token LPAREN
%token RPAREN
%token LCURLY
%token RCURLY
%token LSQUARE
%token RSQUARE
%token SEMICOLON
%token COMMA
%token DOT
%token CHAR_LITERAL
%token BOOLEAN_LITERAL
%token NULL_LITERAL
%token INTEGER_LITERAL
%token FP_LITERAL
%token STRING
%token TEXT_BLOCK
%token IDENTIFIER
%token EOL
%token THIS
%token INSTANCEOF
%token SUPER
%token DIAMOND

%%
Primary:    PrimaryNoNewArray
|           ArrayCreationExpression

PrimaryNoNewArray:  Literal
|                   ClassLiteral
|                   THIS
|                   TypeName DOT THIS
|                   LPAREN Expression RPAREN
|                   ClassInstanceCreationExpression
|                   FieldAccess
|                   ArrayAccess
|                   MethodInvocation
|                   MethodReference

ClassLiteral:   TypeName DOT CLASS
|               NumericType DOT CLASS
|               BOOLEAN DOT CLASS
|               VOID DOT CLASS
|               TypeName SqPlus DOT CLASS
|               NumericType SqPlus DOT CLASS
|               BOOLEAN SqPlus DOT CLASS

SqPlus:         LSQUARE RSQUARE
|               LSQUARE RSQUARE SqPlus

ClassInstanceCreationExpression:    UnqualifiedClassInstanceCreationExpression
|                                   ExpressionName DOT UnqualifiedClassInstanceCreationExpression
|                                   Primary DOT UnqualifiedClassInstanceCreationExpression

UnqualifiedClassInstanceCreationExpression: NEW TypeArguments ClassOrInterfaceTypeToInstantiate LPAREN ArgumentList RPAREN ClassBody
|                                           NEW TypeArguments ClassOrInterfaceTypeToInstantiate LPAREN ArgumentList RPAREN 
|                                           NEW TypeArguments ClassOrInterfaceTypeToInstantiate LPAREN RPAREN ClassBody
|                                           NEW TypeArguments ClassOrInterfaceTypeToInstantiate LPAREN RPAREN
|                                           NEW ClassOrInterfaceTypeToInstantiate LPAREN ArgumentList RPAREN ClassBody
|                                           NEW ClassOrInterfaceTypeToInstantiate LPAREN ArgumentList RPAREN
|                                           NEW ClassOrInterfaceTypeToInstantiate LPAREN RPAREN ClassBody
|                                           NEW ClassOrInterfaceTypeToInstantiate LPAREN RPAREN 

ClassOrInterfaceTypeToInstantiate: IDENTIFIER TypeArgumentsOrDiamond
|                                  IDENTIFIER
|                                  IDENTIFIER DotIdentifierPlus TypeArgumentsOrDiamond
|                                  IDENTIFIER DotIdentifierPlus

DotIdentifierPlus : DOT IDENTIFIER | DOT IDENTIFIER DotIdentifierPlus

TypeArgumentsOrDiamond: TypeArguments
|                       DIAMOND

FieldAccess:    Primary DOT IDENTIFIER
|               SUPER DOT IDENTIFIER
|               TypeName DOT SUPER DOT IDENTIFIER

ArrayAccess:    ExpressionName
|               PrimaryNoNewArray 
|               ExpressionName Expression
|               PrimaryNoNewArray Expression 

MethodInvocation:   MethodName LPAREN ArgumentListopt RPAREN
|                   TypeName DOT TypeArgumentsopt IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   ExpressionName DOT TypeArgumentsopt IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   Primary DOT TypeArgumentsopt IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   SUPER DOT TypeArgumentsopt IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   TypeName DOT SUPER DOT TypeArgumentsopt IDENTIFIER LPAREN ArgumentListopt RPAREN

ArgumentListopt:    
|                   ArgumentList

TypeArgumentsopt: 
|                   TypeArguments

ArgumentList:       Expression 
|                   Expression CommaExpressionPlus

CommaExpressionPlus: COMMA Expression | COMMA Expression CommaExpressionPlus

MethodReference:    ExpressionName DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   Primary DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   ReferenceType DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   SUPER DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   TypeName DOT SUPER DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   ClassType DOUBLE_COLON TypeArgumentsopt NEW
|                   ArrayType DOUBLE_COLON NEW

ArrayCreationExpression:    NEW PrimitiveType DimExprs Dimsopt
|                           NEW ClassType DimExprs Dimsopt
|                           NEW PrimitiveType Dims ArrayInitializer
|                           NEW ClassType Dims ArrayInitializer

Dimsopt: 
|           Dims

DimExprs:   DimExpr | DimExpr DimExprs

DimExpr:    
|           Expression

Expression:  AssignmentExpression

// LambdaExpression:   LambdaParameters -> LambdaBody

// LambdaParameters:   LPAREN [ LambdaParameterList ] RPAREN
// |                   IDENTIFIER

// LambdaParameterList:    LambdaParameter {, LambdaParameter}
// |                   IDENTIFIER {, IDENTIFIER}

// LambdaParameter:    {VariableModifier} LambdaParameterType VariableDeclaratorId
// |                   VariableArityParameter

// LambdaParameterType:    UnannType
// |                   var

// LambdaBody: Expression
// |                   Block

AssignmentExpression:   ConditionalExpression
|                   Assignment

Assignment: LeftHandSide AssignmentOperator Expression

LeftHandSide:       ExpressionName
|                   FieldAccess
|                   ArrayAccess

AssignmentOperator:  ASSIGNMENT

ConditionalExpression:  ConditionalOrExpression
|                   ConditionalOrExpression QM Expression COLON ConditionalExpression
// |                   ConditionalOrExpression QM Expression : LambdaExpression

ConditionalOrExpression:    ConditionalAndExpression
|                   ConditionalOrExpression OR ConditionalAndExpression

ConditionalAndExpression:   InclusiveOrExpression
|                   ConditionalAndExpression AND InclusiveOrExpression

InclusiveOrExpression:  ExclusiveOrExpression
|                   InclusiveOrExpression BITWISE_OR ExclusiveOrExpression

ExclusiveOrExpression:  AndExpression
|                   ExclusiveOrExpression BITWISE_XOR AndExpression

AndExpression:  EqualityExpression
|                   AndExpression BITWISE_AND EqualityExpression
|                   EqualityExpression: RelationalExpression
|                   EqualityExpression DEQ RelationalExpression
|                   EqualityExpression NEQ RelationalExpression

RelationalExpression:   ShiftExpression
|                   RelationalExpression LT ShiftExpression
|                   RelationalExpression GT ShiftExpression
|                   RelationalExpression LEQ ShiftExpression
|                   RelationalExpression GEQ ShiftExpression
|                   InstanceofExpression

InstanceofExpression:   RelationalExpression INSTANCEOF ReferenceType
|                   RelationalExpression INSTANCEOF Pattern

ShiftExpression:    AdditiveExpression
|                   ShiftExpression LEFT_SHIFT AdditiveExpression
|                   ShiftExpression RIGHT_SHIFT AdditiveExpression
|                   ShiftExpression UNSIGNED_RIGHT_SHIFT AdditiveExpression
|                   AdditiveExpression: MultiplicativeExpression
|                   AdditiveExpression PLUS MultiplicativeExpression
|                   AdditiveExpression MINUS MultiplicativeExpression

MultiplicativeExpression:   UnaryExpression
|                   MultiplicativeExpression MUL UnaryExpression
|                   MultiplicativeExpression DIV UnaryExpression
|                   MultiplicativeExpression MODULO UnaryExpression

UnaryExpression:    PreIncrementExpression
|                   PreDecrementExpression
|                   PLUS UnaryExpression
|                   MINUS UnaryExpression
|                   UnaryExpressionNotPlusMinus

PreIncrementExpression: INCREMENT UnaryExpression

PreDecrementExpression: DECREMENT UnaryExpression

UnaryExpressionNotPlusMinus:    PostfixExpression
|                   BITWISE_COMPLEMENT UnaryExpression
|                   NOT UnaryExpression
|                   CastExpression
// |                   SwitchExpression

PostfixExpression:  Primary
|                   ExpressionName
|                   PostIncrementExpression
|                   PostDecrementExpression

PostIncrementExpression:    PostfixExpression INCREMENT

PostDecrementExpression:    PostfixExpression DECREMENT

CastExpression:     LPAREN PrimitiveType RPAREN UnaryExpression
|                   LPAREN ReferenceType RPAREN UnaryExpressionNotPlusMinus
// |                   LPAREN ReferenceType  RPAREN LambdaExpression

// SwitchExpression:   SWITCH LPAREN Expression RPAREN SwitchBlock

ConstantExpression:     Expression

%%