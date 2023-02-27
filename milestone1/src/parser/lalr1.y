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

%token INT LONG BYTE CHAR SHORT FLOAT DOUBLE BOOLEAN VAR

%token IF ELSE FOR WHILE BREAK CONTINUE

%token VOID NEW RETURN PUBLIC PRIVATE CLASS STATIC FINAL

%token ASSERT PLUS MINUS DIV MODULO INCREMENT DECREMENT GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_COMPLEMENT LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT AND OR NOT ASSIGNMENT
%token DOUBLE_COLON COLON QM LPAREN RPAREN LCURLY RCURLY LSQUARE RSQUARE SEMICOLON COMMA DOT
%token CHAR_LITERAL BOOLEAN_LITERAL NULL_LITERAL INTEGER_LITERAL FP_LITERAL STRING TEXT_BLOCK

%token IDENTIFIER
%token THIS
%token INSTANCEOF
%token SUPER
%token THROW
%token EOF_
%token IMPLEMENTS
%token INTERFACE
%token EXTENDS
%token PACKAGE
%token IMPORT
%token ASTERIK
%token DIAMOND

%left INCREMENT DECREMENT
%left NOT BITWISE_COMPLEMENT
%left ASTERIK DIV MODULO
%left PLUS MINUS
%left LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT 
%left GEQ LEQ GT LT NEQ DEQ
%left BITWISE_AND
%left BITWISE_XOR
%left BITWISE_OR
%left AND
%left OR
%left ASSIGNMENT

%start Program
%%

Program:
    CompilationUnit EOF_;

/*     Productions from Chapter 7 (Package and Modueles)           */
CompilationUnit:
    PackageDeclaration ImportDeclaration ClassOrInterfaceDeclarations
|   ImportDeclaration ClassOrInterfaceDeclarations
|   PackageDeclaration ClassOrInterfaceDeclarations
;

ClassOrInterfaceDeclarations:
    ClassOrInterfaceDeclaration
|   ClassOrInterfaceDeclarations ClassOrInterfaceDeclaration
;

ClassOrInterfaceDeclaration:
    ClassDeclaration
|   InterfaceDeclaration
;


PackageDeclaration:
    PACKAGE TypeName SEMICOLON
;

ImportDeclaration:
    IMPORT TypeName SEMICOLON
|   IMPORT TypeName DOT ASTERIK SEMICOLON
;

/*
    Productions from Chapter 4 (Types, values, and variables)
*/

/*
    7, 7.5, 'c', "string", text block, true/false, null
*/
Literal:    INTEGER_LITERAL
|           FP_LITERAL
|           CHAR_LITERAL
|           STRING
|           TEXT_BLOCK
|           BOOLEAN_LITERAL
|           NULL_LITERAL
;
/*
    Productions from Chapter 4 (Types, values, and variables)
*/

/*
    int, long, float, char, double, char, byte, short
*/
UnannType:
    PrimitiveType
;

PrimitiveType:      
    NumericType
|   BOOLEAN
;

NumericType:        
    IntegralType
|   FloatingPointType
;

IntegralType:       BYTE | SHORT | INT | LONG | CHAR ;

FloatingPointType:    FLOAT | DOUBLE ;

/*
    *   Identifier(id1, id2)
    *   ArrayType ()
*/
ReferenceType:
    ClassOrInterfaceType
|   ArrayType
;

ClassOrInterfaceType:
    TypeName
;

ClassType:
    ClassOrInterfaceType
;

InterfaceType:
    ClassOrInterfaceType
;

/*
    As of now remove arguments in <> type like in template to remove disambiguity from expressions of type a<b
*/
/* TypeArguments:
    LT TypeArgumentList GT
;

TypeArgumentList:
    TypeArgument COMMA TypeArgumentList
|   TypeArgument
;

TypeArgument:
    ReferenceType
; */

/* TypeVariable:
    IDENTIFIER
; */

ArrayType:
    PrimitiveType Dims
|   TypeName Dims
;

Dims:
    LSQUARE RSQUARE Dims
|   LSQUARE RSQUARE
;


/**********************/


/*
    Productions from Chapter 6 (Names)
*/

/* PackageName, TypeName, ExpressionName, MethodName, and AmbiguousName
    Replace them with TypenName
*/
TypeName:
    IDENTIFIER
|   TypeName DOT IDENTIFIER 
;


/**************************************/


Modifiers:
    Modifier
|   Modifiers Modifier
;

// *************Need to confirm it *******
Modifier:
    PUBLIC | PRIVATE | STATIC
;

/*
    Productions from Chapter 8 (Classes)
    
*/


ClassDeclaration:
    Modifiers CLASS IDENTIFIER ClassBody
|   CLASS IDENTIFIER ClassBody
|   Modifiers CLASS IDENTIFIER Interfaces ClassBody
|   CLASS IDENTIFIER Interfaces ClassBody
|    Modifiers CLASS IDENTIFIER Super ClassBody
|   CLASS IDENTIFIER Super ClassBody
|   Modifiers CLASS IDENTIFIER Interfaces Super ClassBody
|   CLASS IDENTIFIER Interfaces Super ClassBody
;

Super:
    EXTENDS ClassType
;

Interfaces:
    IMPLEMENTS InterfaceTypeList
;

InterfaceTypeList:
    InterfaceType
|   InterfaceTypeList COMMA InterfaceType
;

ClassBody:
    LCURLY ClassBodyDeclarations RCURLY
|   LCURLY RCURLY
;

ClassBodyDeclarations:
    ClassBodyDeclarations ClassBodyDeclaration
|   ClassBodyDeclaration
;

ClassBodyDeclaration:
    ClassMemberDeclaration
|   ConstructorDeclaration
|   StaticInitializer
;

// Inner Classes and Interfaces are not supported
ClassMemberDeclaration:
    FieldDeclaration
|   MethodDeclaration
;

FieldDeclaration:
    Modifiers UnannType VariableDeclaratorList SEMICOLON
|   UnannType VariableDeclaratorList SEMICOLON
;

VariableDeclaratorList:
    VariableDeclaratorList COMMA VariableDeclarator
|   VariableDeclarator
;

VariableDeclarator:
    VariableDeclaratorId ASSIGNMENT VariableInitializer
|   VariableDeclaratorId
;

VariableDeclaratorId:
    VariableDeclaratorId LSQUARE RSQUARE
|   IDENTIFIER
;

VariableInitializer:
    Expression
|   ArrayInitializer
;

MethodDeclaration:
    MethodHeader MethodBody
;

MethodHeader: // correct
    Modifiers UnannType Declarator
|   UnannType Declarator
|   Modifiers VOID Declarator
|   VOID Declarator
;

// didnt include dims
/* MethodDeclarator:
    IDENTIFIER LPAREN RPAREN
|   IDENTIFIER LPAREN FormalParameterList RPAREN
; */

/*
    Added in place  of MethodDeclarator and ConstructorDeclarator
*/
Declarator:
    IDENTIFIER LPAREN RPAREN
|   IDENTIFIER LPAREN FormalParameterList RPAREN
;

FormalParameterList:
    FormalParameterList COMMA FormalParameter
|   FormalParameter
;

FormalParameter:
    UnannType VariableDeclaratorId
;


MethodBody:
    Block
;

StaticInitializer:
    STATIC Block;
;

ConstructorDeclaration:
    Modifiers Declarator ConstructorBody
|   Declarator ConstructorBody
;

/*
    Use Declarator instead;
*/

/* ConstructorDeclarator:
    IDENTIFIER LPAREN FormalParameterList RPAREN
|   IDENTIFIER LPAREN RPAREN
; */

// ExplicitInvocation missed for now (this, super)
ConstructorBody:
    LCURLY BlockStatements RCURLY
|   LCURLY ExplicitConstructorInvocation BlockStatements RCURLY
|   LCURLY ExplicitConstructorInvocation RCURLY
|   LCURLY RCURLY
;

ExplicitConstructorInvocation:
    THIS LPAREN ArgumentListopt RPAREN
|   SUPER LPAREN ArgumentListopt RPAREN
;

ArrayInitializer:
    LCURLY VariableInitializerList RCURLY
|   LCURLY RCURLY
|   LCURLY VariableInitializerList COMMA RCURLY
|   LCURLY COMMA RCURLY
;

VariableInitializerList:
    VariableInitializerList COMMA VariableInitializer
|   VariableInitializer
;

/*     Productions from Chapter 9 - Interfaces      */

InterfaceDeclaration:
    Modifiers INTERFACE IDENTIFIER InterfaceExtends InterfaceBody
|   INTERFACE IDENTIFIER InterfaceExtends InterfaceBody
|   INTERFACE IDENTIFIER InterfaceBody
|   Modifiers INTERFACE IDENTIFIER  InterfaceBody
;

InterfaceExtends:
    EXTENDS InterfaceTypeList

InterfaceBody:
    LCURLY InterfaceMembers RCURLY
|   LCURLY RCURLY
;

InterfaceMembers:
    InterfaceMemberDeclaration
|   InterfaceMembers InterfaceMemberDeclaration
;

InterfaceMemberDeclaration:
    ConstantDeclaration
|   InterfaceMethodDeclaration
;

ConstantDeclaration:
    FieldDeclaration
;

InterfaceMethodDeclaration:
    MethodHeader SEMICOLON
;

/*
    Productions from Chapter 15 (Expressions)
*/
// Java Expressions Grammer

Primary:    PrimaryNoNewArray
|           ArrayCreationExpression
;

PrimaryNoNewArray:  Literal
|                   THIS
|                   LPAREN Expression RPAREN
|                   ClassInstanceCreationExpression
|                   FieldAccess
|                   ArrayAccess
|                   MethodInvocation
;


ClassInstanceCreationExpression:
    NEW ClassType LPAREN ArgumentListopt RPAREN
;



FieldAccess:    Primary DOT IDENTIFIER
|               SUPER DOT IDENTIFIER
;


ArrayAccess:    TypeName LSQUARE Expression RSQUARE
|               PrimaryNoNewArray LSQUARE Expression RSQUARE 
;

MethodInvocation:   TypeName LPAREN ArgumentListopt RPAREN
|                   Primary DOT IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   SUPER DOT IDENTIFIER LPAREN ArgumentListopt RPAREN
;

/*
Uncomment below rules when Allowing TypeArguments <> args.
Remove above 4 rules
*/
/* |                   TypeName DOT TypeArgumentsopt IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   Primary DOT TypeArgumentsopt IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   SUPER DOT TypeArgumentsopt IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   TypeName DOT SUPER DOT TypeArgumentsopt IDENTIFIER LPAREN ArgumentListopt RPAREN */

ArgumentListopt:    
|                   ArgumentList

/* TypeArgumentsopt: 
|                   TypeArguments */

ArgumentList:       Expression 
|                   ArgumentList COMMA Expression
;

ArrayCreationExpression:    NEW PrimitiveType DimExprs Dimsopt
|                           NEW ClassType DimExprs Dimsopt
|                           NEW PrimitiveType Dims ArrayInitializer
|                           NEW ClassType Dims ArrayInitializer
;

Dimsopt: 
|           Dims
;

DimExprs:   DimExpr 
|           DimExprs DimExpr
;

DimExpr:    LSQUARE Expression RSQUARE

ExpressionOpts: Expression
|
;

Expression:  AssignmentExpression

AssignmentExpression:   
    ConditionalExpression
|   Assignment
;

Assignment:
    LeftHandSide AssignmentOperator Expression
;

LeftHandSide:
    TypeName
|   FieldAccess
|   ArrayAccess
;

AssignmentOperator:  ASSIGNMENT
;

ConditionalExpression:  ConditionalOrExpression
|                   ConditionalOrExpression QM Expression COLON ConditionalExpression
;

ConditionalOrExpression:    ConditionalAndExpression
|                   ConditionalOrExpression OR ConditionalAndExpression
;

ConditionalAndExpression:   InclusiveOrExpression
|                   ConditionalAndExpression AND InclusiveOrExpression
;

InclusiveOrExpression:  ExclusiveOrExpression
|                   InclusiveOrExpression BITWISE_OR ExclusiveOrExpression
;

ExclusiveOrExpression:  AndExpression
|                   ExclusiveOrExpression BITWISE_XOR AndExpression
;

AndExpression:  EqualityExpression
|                   AndExpression BITWISE_AND EqualityExpression
;

EqualityExpression: RelationalExpression
|                   EqualityExpression DEQ RelationalExpression
|                   EqualityExpression NEQ RelationalExpression
;

RelationalExpression:   ShiftExpression
|                   RelationalExpression LT ShiftExpression
|                   RelationalExpression GT ShiftExpression
|                   RelationalExpression LEQ ShiftExpression
|                   RelationalExpression GEQ ShiftExpression
|                   RelationalExpression INSTANCEOF ReferenceType
;

/* InstanceofExpression:   RelationalExpression INSTANCEOF ReferenceType
|                   RelationalExpression INSTANCEOF Pattern */

ShiftExpression:    AdditiveExpression
|                   ShiftExpression LEFT_SHIFT AdditiveExpression
|                   ShiftExpression RIGHT_SHIFT AdditiveExpression
|                   ShiftExpression UNSIGNED_RIGHT_SHIFT AdditiveExpression
;

AdditiveExpression: MultiplicativeExpression
|                   AdditiveExpression PLUS MultiplicativeExpression
|                   AdditiveExpression MINUS MultiplicativeExpression
;

MultiplicativeExpression:   UnaryExpression
|                   MultiplicativeExpression ASTERIK UnaryExpression
|                   MultiplicativeExpression DIV UnaryExpression
|                   MultiplicativeExpression MODULO UnaryExpression
;

UnaryExpression:    PreIncrementExpression
|                   PreDecrementExpression
|                   PLUS UnaryExpression
|                   MINUS UnaryExpression
|                   UnaryExpressionNotPlusMinus
;

PreIncrementExpression: INCREMENT UnaryExpression
;

PreDecrementExpression: DECREMENT UnaryExpression
;

UnaryExpressionNotPlusMinus:    PostfixExpression
|                               BITWISE_COMPLEMENT UnaryExpression
|                               NOT UnaryExpression
|                               CastExpression
;

PostfixExpression:  Primary
|                   TypeName
|                   PostIncrementExpression
|                   PostDecrementExpression
;
PostIncrementExpression:    PostfixExpression INCREMENT
;

PostDecrementExpression:    PostfixExpression DECREMENT
;

CastExpression:     LPAREN PrimitiveType RPAREN UnaryExpression
|                   LPAREN PrimitiveType Dims RPAREN UnaryExpression
|                   LPAREN Expression RPAREN UnaryExpressionNotPlusMinus
|                   LPAREN TypeName Dims RPAREN UnaryExpressionNotPlusMinus
;



/*  
    * Production
    * Chapter 14: (Blocks, Statements, and Patterns)
*/


Block:    LCURLY RCURLY
|         LCURLY BlockStatements RCURLY
;

BlockStatements:    BlockStatements BlockStatement
|                   BlockStatement
;

BlockStatement:     
                    LocalVariableDeclarationStatement
|                   Statement
;

/* LocalClassDeclaration:    ClassDeclaration
; */


LocalVariableDeclarationStatement:    LocalVariableDeclaration
;

LocalVariableDeclaration:    UnannType VariableDeclaratorList
;


Statement:          StatementWithoutTrailingSubstatement
|                   LabeledStatement
|                   IfThenStatement
|                   IfThenElseStatement
|                   WhileStatement
|                   ForStatement
;

StatementNoShortIf:     StatementWithoutTrailingSubstatement
|                       LabeledStatementNoShortIf
|                       IfThenElseStatementNoShortIf
|                       WhileStatementNoShortIf
|                       ForStatementNoShortIf
;

StatementWithoutTrailingSubstatement:   Block
|                                       EmptyStatement
|                                       ExpressionStatement
|                                       AssertStatement
|                                       BreakStatement
|                                       ContinueStatement
|                                       ReturnStatement
|                                       ThrowStatement
;

EmptyStatement:    SEMICOLON
;

LabeledStatement:    IDENTIFIER COLON Statement
;

LabeledStatementNoShortIf:    IDENTIFIER COLON StatementNoShortIf
;

ExpressionStatement:    StatementExpression SEMICOLON

StatementExpression:    Assignment
|                       PreIncrementExpression
|                       PreDecrementExpression
|                       PostIncrementExpression
|                       PostDecrementExpression
|                       MethodInvocation
|                       ClassInstanceCreationExpression

IfThenStatement:    IF LPAREN Expression RPAREN Statement
;

IfThenElseStatement:    IF LPAREN Expression RPAREN StatementNoShortIf ELSE Statement
;

IfThenElseStatementNoShortIf:    IF LPAREN Expression RPAREN StatementNoShortIf ELSE StatementNoShortIf
;

AssertStatement:    ASSERT Expression SEMICOLON
|                   ASSERT Expression COLON Expression SEMICOLON
;

WhileStatement:    WHILE LPAREN Expression RPAREN Statement
;

WhileStatementNoShortIf:    WHILE LPAREN Expression RPAREN StatementNoShortIf
;

ForStatement:       BasicForStatement
|                   EnhancedForStatement
;

ForStatementNoShortIf:    BasicForStatementNoShortIf
|                   EnhancedForStatementNoShortIf
;

BasicForStatement:     FOR LPAREN ForInitOpt SEMICOLON ExpressionOpts SEMICOLON ForUpdateOpts RPAREN Statement
;

BasicForStatementNoShortIf:    FOR LPAREN ForInitOpt SEMICOLON ExpressionOpts SEMICOLON ForUpdateOpts RPAREN StatementNoShortIf
;

ForInitOpt:    ForInit
|
;

ForInit:    StatementExpressionList
|           LocalVariableDeclaration
;

ForUpdateOpts:  ForUpdate
|
;

ForUpdate:    StatementExpressionList
;

StatementExpressionList:    StatementExpression
|                           StatementExpression CommaStatementExpressions
;

CommaStatementExpressions:   COMMA StatementExpression CommaStatementExpressions
|                            COMMA StatementExpression
;

EnhancedForStatement:    FOR LPAREN LocalVariableDeclaration COLON Expression RPAREN Statement
;

EnhancedForStatementNoShortIf:    FOR LPAREN LocalVariableDeclaration COLON Expression RPAREN StatementNoShortIf
;

BreakStatement:    BREAK IdentifierOpts SEMICOLON
;

ContinueStatement:    CONTINUE IdentifierOpts SEMICOLON
;

ReturnStatement:
    RETURN ExpressionOpts SEMICOLON
;

ThrowStatement:    THROW Expression SEMICOLON
;

IdentifierOpts:     IDENTIFIER
|
;



%%

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
