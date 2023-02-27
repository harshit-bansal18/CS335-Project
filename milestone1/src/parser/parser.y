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

    create_leaf()

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

%token ASSERT PLUS MINUS MUL DIV MODULO INCREMENT DECREMENT GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_COMPLEMENT LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT AND OR NOT ASSIGNMENT
%token DOUBLE_COLON COLON QM LPAREN RPAREN LCURLY RCURLY LSQUARE RSQUARE SEMICOLON COMMA DOT
%token CHAR_LITERAL BOOLEAN_LITERAL NULL_LITERAL INTEGER_LITERAL FP_LITERAL STRING TEXT_BLOCK

%token IDENTIFIER
%token THIS
%token INSTANCEOF
%token SUPER
%token DIAMOND
%token THROW
%token EOF_

%left INCREMENT DECREMENT
%left NOT BITWISE_COMPLEMENT
%left MUL DIV MODULO
%left PLUS MINUS
%left LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT 
%left GEQ LEQ GT LT NEQ DEQ
%left BITWISE_AND
%left BITWISE_XOR
%left BITWISE_OR
%left AND
%left OR
%left ASSIGNMENT

%start INPUT_JAVA
%%

INPUT_JAVA: Classes EOF_;
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
|   NumericType
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
    ClassType
|   ArrayType
;

/* ClassOrInterfaceType:
    ClassType
; */

ClassType:
    /* IDENTIFIER TypeArguments */
|   TypeName
/* |   ClassType DOT IDENTIFIER TypeArguments */
|   ClassType DOT IDENTIFIER
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
|   ClassType Dims
|   IDENTIFIER Dims
;

Dims:
    LSQUARE RSQUARE Dims
|   LSQUARE RSQUARE
;


/**********************/


/*
    Productions from Chapter 6 (Names)
*/

/* ModuleName:
    IDENTIFIER DOT ModuleName
|   IDENTIFIER
;

PackageName:
    IDENTIFIER DOT PackageName
|   IDENTIFIER
; */


// This is a Replacement for typename
/* IdentifiersDot:
    IDENTIFIER DOT IDENTIFIER
|   IDENTIFIER
; */

// IdentifiersDot
/*
    TypeName: ID.ID.ID.....
*/

TypeName:
    IDENTIFIER
|   IDENTIFIER DOT TypeName 
;
/* // IdentifiersDot
PackageOrTypeName:
    IDENTIFIER DOT PackageOrTypeName
|   IDENTIFIER   
;

// IdentifiersDot
TypeName:
    AmbiguousName DOT IDENTIFIER
|   IDENTIFIER
;

/* TypeName:
    UnqualifiedMethodIdentifier
; */

/* TypeName:
    IDENTIFIER
; */

// Identifiers
/* AmbiguousName:
    IDENTIFIER DOT AmbiguousName
|   IDENTIFIER
; */

// UnqualifiedMethodIdentifier:
//     IDENTIFIER
// ;
/**************************************/

/*
    Productions from Chapter 8 (Classes)
    
*/

Classes:    ClassDeclaration Classes
|           ClassDeclaration
;

ClassDeclaration:
    NormalClassDeclaration
;

NormalClassDeclaration:
    Modifiers CLASS IDENTIFIER ClassBody
|   CLASS IDENTIFIER ClassBody
;

Modifiers:
    AccessModifier NonAccessModifier
|   AccessModifier
|   NonAccessModifier
;

AccessModifier:
    PUBLIC | PRIVATE
;

NonAccessModifier:
    STATIC
;

ClassBody:
    LCURLY ClassBodyDeclarations RCURLY
|   LCURLY RCURLY
;

ClassBodyDeclarations:
    ClassBodyDeclaration ClassBodyDeclarations
|   ClassBodyDeclaration
;

ClassBodyDeclaration:
    ClassMemberDeclaration
|   InstanceInitializer
|   StaticInitializer
;

// Inner Classes and Interfaces are not supported
ClassMemberDeclaration:
    FieldDeclaration
|   MethodDeclaration
|   SEMICOLON
;

FieldDeclaration:
    Modifiers UnannType VariableDeclaratorList SEMICOLON
|   UnannType VariableDeclaratorList SEMICOLON
;

VariableDeclaratorList:
    VariableDeclarator COMMA VariableDeclaratorList
|   VariableDeclarator
;

VariableDeclarator:
    VariableDeclaratorId ASSIGNMENT VariableInitializer
|   VariableDeclaratorId
;

VariableDeclaratorId:
    IDENTIFIER Dims
|   IDENTIFIER
;

VariableInitializer:
    Expression
|   ArrayInitializer
;

MethodDeclaration:
    Modifiers MethodHeader MethodBody
;

MethodHeader:
    UnannType MethodDeclarator
|   VOID MethodDeclarator
;

MethodDeclarator:
    IDENTIFIER LPAREN ReceiverParameter COMMA FormalParameterList RPAREN
|   IDENTIFIER LPAREN FormalParameterList RPAREN
|   IDENTIFIER LPAREN RPAREN
;

ReceiverParameter:
    UnannType IDENTIFIER DOT THIS
|   UnannType THIS
;

FormalParameterList:
    FormalParameter COMMA FormalParameterList
|   FormalParameter
;

FormalParameter:
    VariableModifier UnannType VariableDeclaratorId
|   UnannType VariableDeclaratorId
;

VariableModifier:
    FINAL
;

MethodBody:
    Block
;

StaticInitializer:
    STATIC Block;
;

ArrayInitializer:
    LCURLY VariableInitializerList RCURLY
|   LCURLY RCURLY
|   LCURLY VariableInitializerList COMMA RCURLY
|   LCURLY COMMA RCURLY
;

VariableInitializerList:
    VariableInitializer COMMA VariableInitializerList
|   VariableInitializer
;

InstanceInitializer:
    Block
;

/*
    Productions from Chapter 15 (Expressions)
*/
// Java Expressions Grammer

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
|               TypeName Dims DOT CLASS
|               NumericType Dims DOT CLASS
|               BOOLEAN Dims DOT CLASS


ClassInstanceCreationExpression:    UnqualifiedClassInstanceCreationExpression
|                                   TypeName DOT UnqualifiedClassInstanceCreationExpression
|                                   Primary DOT UnqualifiedClassInstanceCreationExpression

UnqualifiedClassInstanceCreationExpression: NEW ClassOrInterfaceTypeToInstantiate LPAREN ArgumentList RPAREN ClassBody
|                                           NEW ClassOrInterfaceTypeToInstantiate LPAREN ArgumentList RPAREN
|                                           NEW ClassOrInterfaceTypeToInstantiate LPAREN RPAREN ClassBody
|                                           NEW ClassOrInterfaceTypeToInstantiate LPAREN RPAREN  
/* |                                           NEW TypeArguments ClassOrInterfaceTypeToInstantiate LPAREN ArgumentList RPAREN ClassBody
|                                           NEW TypeArguments ClassOrInterfaceTypeToInstantiate LPAREN ArgumentList RPAREN 
|                                           NEW TypeArguments ClassOrInterfaceTypeToInstantiate LPAREN RPAREN ClassBody
|                                           NEW TypeArguments ClassOrInterfaceTypeToInstantiate LPAREN RPAREN */


ClassOrInterfaceTypeToInstantiate: IDENTIFIER TypeArgumentsOrDiamond
|                                  IDENTIFIER
|                                  IDENTIFIER DotIdentifierPlus TypeArgumentsOrDiamond
|                                  IDENTIFIER DotIdentifierPlus

DotIdentifierPlus : DOT IDENTIFIER | DOT IDENTIFIER DotIdentifierPlus

TypeArgumentsOrDiamond: DIAMOND
/* |                       TypeArguments */

FieldAccess:    Primary DOT IDENTIFIER
|               SUPER DOT IDENTIFIER
|               TypeName DOT SUPER DOT IDENTIFIER

ArrayAccess:    TypeName LSQUARE Expression RSQUARE
|               PrimaryNoNewArray LSQUARE Expression RSQUARE 

MethodInvocation:   TypeName LPAREN ArgumentListopt RPAREN
|                   TypeName DOT IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   Primary DOT IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   SUPER DOT IDENTIFIER LPAREN ArgumentListopt RPAREN
|                   TypeName DOT SUPER DOT IDENTIFIER LPAREN ArgumentListopt RPAREN
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
|                   Expression CommaExpressionPlus

CommaExpressionPlus: COMMA Expression | COMMA Expression CommaExpressionPlus

MethodReference:    TypeName DOUBLE_COLON IDENTIFIER
|                   Primary DOUBLE_COLON IDENTIFIER
|                   ReferenceType DOUBLE_COLON IDENTIFIER
|                   SUPER DOUBLE_COLON  IDENTIFIER
|                   TypeName DOT SUPER DOUBLE_COLON IDENTIFIER
|                   ClassType DOUBLE_COLON NEW
/*
Uncomment below rules when Allowing TypeArguments <> args.
Remove above 4 rules
*/
/* |                   TypeName DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   Primary DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   ReferenceType DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   SUPER DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   TypeName DOT SUPER DOUBLE_COLON TypeArgumentsopt IDENTIFIER
|                   ClassType DOUBLE_COLON TypeArgumentsopt NEW */
|                   ArrayType DOUBLE_COLON NEW

ArrayCreationExpression:    NEW PrimitiveType DimExprs Dimsopt
|                           NEW ClassType DimExprs Dimsopt
|                           NEW PrimitiveType Dims ArrayInitializer
|                           NEW ClassType Dims ArrayInitializer

Dimsopt: 
|           Dims

DimExprs:   DimExpr | DimExpr DimExprs

DimExpr:    LSQUARE Expression RSQUARE

ExpressionOpts: Expression
|
;

Expression:  AssignmentExpression

AssignmentExpression:   ConditionalExpression
|                   Assignment

Assignment: TypeName AssignmentOperator Expression
|           FieldAccess AssignmentOperator Expression
|           ArrayAccess AssignmentOperator Expression

AssignmentOperator:  ASSIGNMENT

ConditionalExpression:  ConditionalOrExpression
|                   ConditionalOrExpression QM Expression COLON ConditionalExpression

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

EqualityExpression: RelationalExpression
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

AdditiveExpression: MultiplicativeExpression
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
|                               BITWISE_COMPLEMENT UnaryExpression
|                               NOT UnaryExpression
|                               CastExpression

PostfixExpression:  Primary
|                   TypeName
|                   PostIncrementExpression
|                   PostDecrementExpression

PostIncrementExpression:    PostfixExpression INCREMENT

PostDecrementExpression:    PostfixExpression DECREMENT

CastExpression:     LPAREN PrimitiveType RPAREN UnaryExpression
|                   LPAREN ReferenceType RPAREN UnaryExpressionNotPlusMinus




/*  
    * Production
    * Chapter 14: (Blocks, Statements, and Patterns)
*/


Block:    LCURLY RCURLY
|         LCURLY BlockStatements RCURLY
;

BlockStatements:    BlockStatement BlockStatements
|                   BlockStatement
;

BlockStatement:     LocalClassDeclaration
|                   LocalVariableDeclarationStatement
|                   Statement
;

LocalClassDeclaration:    ClassDeclaration
;


LocalVariableDeclarationStatement:    LocalVariableDeclaration
;

LocalVariableDeclaration:    VariableModifiers LocalVariableType VariableDeclaratorList
|                            LocalVariableType VariableDeclaratorList
;

VariableModifiers:       VariableModifier VariableModifiers
|                        VariableModifier
;

LocalVariableType:   UnannType
|                    VAR
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

BasicForStatement:     FOR LPAREN ForInitOpts SEMICOLON ExpressionOpts SEMICOLON ForUpdateOpts RPAREN Statement
;

BasicForStatementNoShortIf:    FOR LPAREN ForInitOpts SEMICOLON ExpressionOpts SEMICOLON ForUpdateOpts RPAREN StatementNoShortIf
;

ForInitOpts:    ForInit
|
;

ForInit:    StatementExpressionList
|           LocalVariableDeclaration

ForUpdateOpts:  ForUpdate
|
;

ForUpdate:    StatementExpressionList

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

ReturnStatement:    RETURN TypeName SEMICOLON
|                   RETURN SEMICOLON
;

ThrowStatement:    THROW Expression SEMICOLON
;

IdentifierOpts:     IDENTIFIER
|
;

Pattern:            TypePattern
;

TypePattern:        LocalVariableDeclaration
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
