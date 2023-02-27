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

    static int node_num=-1;

    int yyerror(const char *);

    int create_node(char* label, vector<int> children_node_num){
        //A new node created with given label and edges from current node_num to all children_node_num
        printf("node%d[label=\"%s\"];\n", ++node_num, label);
        for (auto& child : children_node_num){
            printf("node%d -> node%d;\n", node_num, child);
        }
        return node_num;
    }

    int create_leaf(char* lexeme, char* token){
        printf("node%d[label=\"%s(%s)\"];\n", ++node_num, token, lexeme);
        return node_num;
    }

%}

%define parse.error verbose

%union {
    int num;
    double float_num;
    char* str;
}

%token<str> INT LONG BYTE CHAR SHORT FLOAT DOUBLE BOOLEAN VAR

%token<str> IF ELSE FOR WHILE BREAK CONTINUE

%token<str> VOID NEW RETURN PUBLIC PRIVATE CLASS STATIC FINAL

%token<str> ASSERT PLUS MINUS DIV MODULO INCREMENT DECREMENT GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_COMPLEMENT LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT AND OR NOT ASSIGNMENT
%token<str> DOUBLE_COLON COLON QM LPAREN RPAREN LCURLY RCURLY LSQUARE RSQUARE SEMICOLON COMMA DOT
%token<str> CHAR_LITERAL BOOLEAN_LITERAL NULL_LITERAL INTEGER_LITERAL FP_LITERAL STRING TEXT_BLOCK

%token<str> IDENTIFIER
%token<str> THIS
%token<str> INSTANCEOF
%token<str> SUPER
%token<str> THROW
%token<str> EOF_
%token<str> IMPLEMENTS
%token<str> INTERFACE
%token<str> EXTENDS
%token<str> PACKAGE
%token<str> IMPORT
%token<str> ASTERIK
%token<str> DIAMOND

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


%type<num> Program
%type<num> CompilationUnit
%type<num> ClassOrInterfaceDeclaration
%type<num> ClassOrInterfaceDeclarations
%type<num> PackageDeclaration
%type<num> ImportDeclaration
%type<num> Literal
%type<num> UnannType
%type<num> PrimitiveType
%type<num> NumericType
%type<num> IntegralType
%type<num> FloatingPointType
%type<num> ReferenceType 
%type<num> ClassOrInterfaceType
%type<num> ClassType
%type<num> InterfaceType
%type<num> ArrayType
%type<num> Dims
%type<num> TypeName
%type<num> Modifiers
%type<num> Modifier
%type<num> ClassDeclaration
%type<num> super_
%type<num> Interfaces
%type<num> InterfaceTypeList
%type<num> ClassBody
%type<num> ClassBodyDeclarations
%type<num> ClassBodyDeclaration
%type<num> ClassMemberDeclaration
%type<num> FieldDeclaration
%type<num> VariableDeclaratorList
%type<num> VariableDeclarator
%type<num> VariableDeclaratorId
%type<num> VariableInitializer
%type<num> MethodDeclaration
%type<num> MethodHeader
%type<num> Declarator
%type<num> FormalParameterList
%type<num> FormalParameter
%type<num> MethodBody
%type<num> StaticInitializer
%type<num> ConstructorDeclaration
%type<num> ConstructorBody
%type<num> ExplicitConstructorInvocation
%type<num> ArrayInitializer
%type<num> VariableInitializerList
%type<num> InterfaceDeclaration
%type<num> InterfaceExtends
%type<num> InterfaceBody
%type<num> InterfaceMembers
%type<num> InterfaceMemberDeclaration
%type<num> ConstantDeclaration
%type<num> InterfaceMethodDeclaration
%type<num> Primary
%type<num> PrimaryNoNewArray
%type<num> ClassInstanceCreationExpression
%type<num> FieldAccess
%type<num> ArrayAccess
%type<num> MethodInvocation
%type<num> ArgumentListopt
%type<num> ArgumentList
%type<num> ArrayCreationExpression
%type<num> Dimsopt
%type<num> DimExprs
%type<num> DimExpr
%type<num> ExpressionOpts
%type<num> Expression
%type<num> AssignmentExpression
%type<num> Assignment
%type<num> LeftHandSide
%type<num> AssignmentOperator
%type<num> ConditionalExpression
%type<num> ConditionalOrExpression
%type<num> ConditionalAndExpression
%type<num> InclusiveOrExpression
%type<num> ExclusiveOrExpression
%type<num> AndExpression
%type<num> EqualityExpression
%type<num> RelationalExpression
%type<num> ShiftExpression
%type<num> AdditiveExpression
%type<num> MultiplicativeExpression
%type<num> UnaryExpression
%type<num> PreIncrementExpression
%type<num> PreDecrementExpression
%type<num> UnaryExpressionNotPlusMinus
%type<num> PostfixExpression
%type<num> PostIncrementExpression
%type<num> PostDecrementExpression
%type<num> CastExpression
%type<num> Block
%type<num> BlockStatements
%type<num> BlockStatement
%type<num> Statement
%type<num> StatementNoShortIf
%type<num> StatementWithoutTrailingSubstatement
%type<num> EmptyStatement
%type<num> LabeledStatement
%type<num> LabeledStatementNoShortIf
%type<num> ExpressionStatement
%type<num> StatementExpression
%type<num> IfThenElseStatement
%type<num> IfThenElseStatementNoShortIf
%type<num> AssertStatement
%type<num> WhileStatement
%type<num> WhileStatementNoShortIf
%type<num> ForStatement
%type<num> ForStatementNoShortIf
%type<num> BasicForStatement
%type<num> BasicForStatementNoShortIf
%type<num> ForInitOpt
%type<num> ForInit
%type<num> ForUpdateOpts
%type<num> ForUpdate
%type<num> StatementExpressionList
%type<num> CommaStatementExpressions
%type<num> EnhancedForStatement
%type<num> EnhancedForStatementNoShortIf
%type<num> BreakStatement
%type<num> ContinueStatement
%type<num> ReturnStatement
%type<num> ThrowStatement
%type<num> IdentifierOpts
%type<num> IfThenStatement
%type<num> LocalVariableDeclaration
%type<num> LocalVariableDeclarationStatement
%type<num> Super
%type<num> Int
%type<num> Long
%type<num> Byte
%type<num> Char
%type<num> Short
%type<num> Float
%type<num> Double
%type<num> Boolean
%type<num> Var
%type<num> If
%type<num> Else
%type<num> For
%type<num> While
%type<num> Break
%type<num> Continue
%type<num> Void
%type<num> New
%type<num> Return
%type<num> Public
%type<num>  Private
%type<num> Class
%type<num> Static
%type<num> Final
%type<num> Assert
%type<num> Plus
%type<num> Minus
%type<num> Div
%type<num> Modulo
%type<num> Increment
%type<num> Decrement
%type<num> Geq
%type<num> Leq
%type<num> Gt
%type<num> Lt
%type<num> Neq
%type<num> Deq
%type<num> Bitwise_and
%type<num> Bitwise_or
%type<num> Bitwise_xor
%type<num> Bitwise_complement
%type<num> Left_shift
%type<num> Right_shift
%type<num> Unsigned_right_shift
%type<num> And
%type<num> Or
%type<num> Not
%type<num> Double_colon
%type<num> Colon
%type<num> Qm
%type<num> Lparen
%type<num> Rparen
%type<num> Lcurly
%type<num> Rcurly
%type<num> Lsquare
%type<num> Rsquare
%type<num> Semicolon
%type<num> Comma
%type<num> Dot
%type<num> Char_literal
%type<num> Boolean_literal
%type<num> Null_literal
%type<num> Integer_literal
%type<num> Fp_literal
%type<num> String
%type<num> Text_block
%type<num> Identifier
%type<num> This
%type<num> Instanceof
%type<num> Throw
%type<num> Implements
%type<num> Interface
%type<num> Extends
%type<num> Package
%type<num> Import
%type<num> Asterik
%type<num> Diamond

%start Program
%%

Program:
    CompilationUnit EOF_; 

/*     Productions from Chapter 7 (Package and Modueles)           */
CompilationUnit:
    PackageDeclaration ImportDeclaration ClassOrInterfaceDeclarations {$$ = create_node("CompilationUnit", {$1, $2, $3});}
|   ImportDeclaration ClassOrInterfaceDeclarations {$$ = create_node("CompilationUnit", {$1, $2});}
|   PackageDeclaration ClassOrInterfaceDeclarations {$$ = create_node("CompilationUnit", {$1, $2});}
|   ClassOrInterfaceDeclarations {$$ = create_node("Compilation Unit", {$1});}
;

ClassOrInterfaceDeclarations:
    ClassOrInterfaceDeclaration {$$ = create_node("ClassOrInterfaceDeclaration", {$1});}
|   ClassOrInterfaceDeclarations ClassOrInterfaceDeclaration {$$ = create_node("ClassOrInterfaceDeclarations", {$1, $2});}
;

ClassOrInterfaceDeclaration:
    ClassDeclaration {$$ = $1;}
|   InterfaceDeclaration  {$$ = $1;}
;


PackageDeclaration:
    Package TypeName Semicolon {$$ = create_node("PackageDeclaration", {$1, $2, $3});}
;

ImportDeclaration:
    Import TypeName Semicolon {$$ = create_node("ImportDeclaration", {$1, $2, $3});}
|   Import TypeName Dot Asterik Semicolon {$$ = create_node("ImportDeclaration", {$1, $2, $3, $4, $5});}
;

/*
    Productions from Chapter 4 (Types, values, and variables)
*/

/*
    7, 7.5, 'c', "string", text block, true/false, null
*/
Literal:    Integer_literal {$$ = create_node("Literal", {$1});}
|           Fp_literal  {$$ = create_node("Literal", {$1});}
|           Char_literal  {$$ = create_node("Literal", {$1});}
|           String  {$$ = create_node("Literal", {$1});}
|           Text_block  {$$ = create_node("Literal", {$1});}
|           Boolean_literal  {$$ = create_node("Literal", {$1});}
|           Null_literal  {$$ = create_node("Literal", {$1});}
;
/*
    Productions from Chapter 4 (Types, values, and variables)
*/

/*
    int, long, float, char, double, char, byte, short
*/
UnannType:
    PrimitiveType   {$$ = create_node("UnannType", {$1});}
;

PrimitiveType:      
    NumericType {$$ = create_node("PrimitiveType", {$1});}
|   Boolean  {$$ = create_node("PrimitiveType", {$1});}
;

NumericType:        
    IntegralType {$$ = create_node("NumericType", {$1});}
|   FloatingPointType  {$$ = create_node("NumericType", {$1});}
;

IntegralType:       Byte  { $$ = create_node("IntegralType", {$1}); }
|                   Short  { $$ = create_node("IntegralType", {$1}); }
|                   Int  { $$ = create_node("IntegralType", {$1}); }
|                   Long  { $$ = create_node("IntegralType", {$1}); }
|                   Char { $$ = create_node("IntegralType", {$1}); }
;

FloatingPointType:    Float { $$ = create_node("FloatingPointType", {$1}); }
|                     Double { $$ = create_node("FloatingPointType", {$1}); }
;

/*
    *   Identifier(id1, id2)
    *   ArrayType ()
*/
ReferenceType:
    ClassOrInterfaceType {$$ = create_node("ReferenceType", {$1});}
|   ArrayType {$$ = create_node("ReferenceType", {$1});}
;

ClassOrInterfaceType:
    TypeName    {$$ = create_node("ClassOrInterfaceType", {$1});}
;

ClassType:
    ClassOrInterfaceType    {$$ = create_node("ClassType", {$1});}
;

InterfaceType:
    ClassOrInterfaceType    {$$ = create_node("InterfaceType", {$1});}
;

/*
    As of now remove arguments in <> type like in template to remove disambiguity from expressions of type a<b
*/
/* TypeArguments:
    Lt TypeArgumentList Gt
;

TypeArgumentList:
    TypeArgument Comma TypeArgumentList
|   TypeArgument
;

TypeArgument:
    ReferenceType
; */

/* TypeVariable:
    Identifier
; */

ArrayType:
    PrimitiveType Dims {$$ = create_node("ArrayType", {$1, $2});}
|   TypeName Dims    {$$ = create_node("ArrayType", {$1, $2});}
;

Dims:
    Lsquare Rsquare Dims  {$$ = create_node("Dims", {$1, $2, $3});}
|   Lsquare Rsquare  {$$ = create_node("Dims", {$1, $2});}
;


/**********************/


/*
    Productions from Chapter 6 (Names)
*/

/* PackageName, TypeName, ExpressionName, MethodName, and AmbiguousName
    Replace them with TypenName
*/
TypeName:
    Identifier  {$$ = create_node("Dims", {$1});}
|   TypeName Dot Identifier {$$ = create_node("Dims", {$1, $2 , $3});}
;


/**************************************/


Modifiers:
    Modifier {$$ = create_node("Modifiers", {$1});}
|   Modifiers Modifier {$$ = create_node("Modifiers", {$1, $2});}
;

// *************Need to confirm it *******
Modifier:
    Public | Private | Static 
;

/*
    Productions from Chapter 8 (Classes)
    
*/


ClassDeclaration:
    Modifiers Class Identifier ClassBody {$$ = create_node("ClassDeclaration", {$1, $2, $3, $4});}
|   Class Identifier ClassBody {$$ = create_node("ClassDeclaration", {$1, $2, $3});}
|   Modifiers Class Identifier Interfaces ClassBody {$$ = create_node("ClassDeclaration", {$1, $2, $3, $4, $5});}
|   Class Identifier Interfaces ClassBody {$$ = create_node("ClassDeclaration", {$1, $2, $3, $4});}
|    Modifiers Class Identifier Super ClassBody {$$ = create_node("ClassDeclaration", {$1, $2, $3, $4, $5});}
|   Class Identifier Super ClassBody {$$ = create_node("ClassDeclaration", {$1, $2, $3, $4});}
|   Modifiers Class Identifier Interfaces Super ClassBody {$$ = create_node("ClassDeclaration", {$1, $2, $3, $4, $5, $6});}
|   Class Identifier Interfaces Super ClassBody {$$ = create_node("ClassDeclaration", {$1, $2, $3, $4, $5});}
;

Super:
    Extends ClassType {$$ = create_node("Super", {$1, $2});}
;

Interfaces:
    Implements InterfaceTypeList {$$ = create_node("Interfaces", {$1, $2});}
;

InterfaceTypeList:
    InterfaceType { $$ = create_node("InterfaceTypeList", {$1}); }
|   InterfaceTypeList Comma InterfaceType { $$ = create_node("InterfaceTypeList", {$1, $2, $3}); }
;

ClassBody:
    Lcurly ClassBodyDeclarations Rcurly {$$ = create_node("ClassBody", {$1, $2, $3});}
|   Lcurly Rcurly {$$ = create_node("ClassBody", {$1, $2});}
;

ClassBodyDeclarations:
    ClassBodyDeclarations ClassBodyDeclaration {$$ = create_node("ClassBodyDeclarations", {$1, $2});}
|   ClassBodyDeclaration {$$ = create_node("ClassBodyDeclarations", {$1});}
;

ClassBodyDeclaration:
    ClassMemberDeclaration {$$ = create_node("ClassBodyDeclaration", {$1});}
|   ConstructorDeclaration {$$ = create_node("ClassBodyDeclaration", {$1});}
|   StaticInitializer {$$ = create_node("ClassBodyDeclaration", {$1});}
;

// Inner Classes and Interfaces are not supported
ClassMemberDeclaration:
    FieldDeclaration {$$ = create_node("ClassMemberDeclaration", {$1});}
|   MethodDeclaration {$$ = create_node("ClassMemberDeclaration", {$1});}
;

FieldDeclaration:
    Modifiers UnannType VariableDeclaratorList Semicolon {$$ = create_node("FieldDeclaration", {$1, $2, $3, $4});}
|   UnannType VariableDeclaratorList Semicolon {$$ = create_node("FieldDeclaration", {$1, $2, $3});}
;

VariableDeclaratorList:
    VariableDeclaratorList Comma VariableDeclarator {$$ = create_node("VariableDeclaratorList", {$1, $2, $3});}
|   VariableDeclarator {$$ = create_node("VariableDeclaratorList", {$1});}
;

VariableDeclarator:
    VariableDeclaratorId AssignmentOperator VariableInitializer {$$ = create_node("VariableDeclarator", {$1, $2, $3});}
|   VariableDeclaratorId {$$ = create_node("VariableDeclarator", {$1});}
;

VariableDeclaratorId:
    VariableDeclaratorId Lsquare Rsquare {$$ = create_node("VariableDeclaratorId", {$1, $2, $3});}
|   Identifier {$$ = create_node("VariableDeclaratorId", {$1});}
;

VariableInitializer:
    Expression {$$ = create_node("VariableInitializer", {$1});}
|   ArrayInitializer {$$ = create_node("VariableInitializer", {$1});}
;

MethodDeclaration:
    MethodHeader MethodBody {$$ = create_node("MethodDeclaration", {$1, $2});}
;

MethodHeader: // correct
    Modifiers UnannType Declarator {$$ = create_node("MethodHeader", {$1, $2, $3});}
|   UnannType Declarator {$$ = create_node("MethodHeader", {$1, $2});}
|   Modifiers Void Declarator {$$ = create_node("MethodHeader", {$1, $2, $3});}
|   Void Declarator 
;

// didnt include dims
/* MethodDeclarator:
    Identifier Lparen Rparen
|   Identifier Lparen FormalParameterList Rparen
; */

/*
    Added in place  of MethodDeclarator and ConstructorDeclarator
*/
Declarator:
    Identifier Lparen Rparen {$$ = create_node("Declarator", {$1, $2, $3});}
|   Identifier Lparen FormalParameterList Rparen {$$ = create_node("Declarator", {$1, $2, $3, $4});}
;

FormalParameterList:
    FormalParameterList Comma FormalParameter {$$ = create_node("FormalParameterList", {$1, $2, $3});}
|   FormalParameter {$$ = create_node("FormalParameterList", {$1});}
;

FormalParameter:
    UnannType VariableDeclaratorId {$$ = create_node("FormalParameter", {$1, $2});}
;


MethodBody:
    Block {$$ = create_node("MethodBody", {$1});}
;

StaticInitializer:
    Static Block {$$ = create_node("StaticInitializer", {$1, $2});}
;

ConstructorDeclaration:
    Modifiers Declarator ConstructorBody {$$ = create_node("ConstructorDeclaration", {$1, $2, $3});}
|   Declarator ConstructorBody {$$ = create_node("ConstructorDeclaration", {$1, $2});}
;

/*
    Use Declarator instead;
*/

/* ConstructorDeclarator:
    Identifier Lparen FormalParameterList Rparen
|   Identifier Lparen Rparen
; */

// ExplicitInvocation missed for now (this, super)
ConstructorBody:
    Lcurly BlockStatements Rcurly {$$ = create_node("ConstructorBody", {$1, $2, $3});}
|   Lcurly ExplicitConstructorInvocation BlockStatements Rcurly {$$ = create_node("ConstructorBody", {$1, $2, $3, $4});}
|   Lcurly ExplicitConstructorInvocation Rcurly {$$ = create_node("ConstructorBody", {$1, $2, $3});}
|   Lcurly Rcurly {$$ = create_node("ConstructorBody", {$1, $2});}
;

ExplicitConstructorInvocation:
    This Lparen ArgumentListopt Rparen {$$ = create_node("ExplicitConstructorInvocation", {$1, $2, $3, $4});}
|   super_ Lparen ArgumentListopt Rparen {$$ = create_node("ExplicitConstructorInvocation", {$1, $2, $3, $4});}
;

ArrayInitializer:
    Lcurly VariableInitializerList Rcurly { $$ = create_node("ArrayInitializer", {$1, $2, $3});}
|   Lcurly Rcurly { $$ = create_node("ArrayInitializer", {$1, $2});}
|   Lcurly VariableInitializerList Comma Rcurly { $$ = create_node("ArrayInitializer", {$1, $2, $3, $4});}
|   Lcurly Comma Rcurly { $$ = create_node("ArrayInitializer", {$1, $2, $3});}
;

VariableInitializerList:
    VariableInitializerList Comma VariableInitializer { $$ = create_node("VariableInitializerList", {$1, $2, $3});}
|   VariableInitializer { $$ = create_node("VariableInitializerList", {$1});}
;

/*     Productions from Chapter 9 - Interfaces      */

InterfaceDeclaration:
    Modifiers Interface Identifier InterfaceExtends InterfaceBody {$$ = create_node("InterfaceDeclaration", {$1, $2, $3, $4, $5});}
|   Interface Identifier InterfaceExtends InterfaceBody {$$ = create_node("InterfaceDeclaration", {$1, $2, $3, $4});}
|   Interface Identifier InterfaceBody {$$ = create_node("InterfaceDeclaration", {$1, $2, $3});}
|   Modifiers Interface Identifier  InterfaceBody {$$ = create_node("InterfaceDeclaration", {$1, $2, $3, $4});}
;

InterfaceExtends:
    Extends InterfaceTypeList {$$ = create_node("InterfaceExtends", {$1, $2});}

InterfaceBody:
    Lcurly InterfaceMembers Rcurly {$$ = create_node("InterfaceBody", {$1, $2, $3});}
|   Lcurly Rcurly {$$ = create_node("InterfaceBody", {$1, $2});}
;

InterfaceMembers:
    InterfaceMemberDeclaration {$$ = create_node("InterfaceMembers", {$1});}
|   InterfaceMembers InterfaceMemberDeclaration {$$ = create_node("InterfaceMembers", {$1, $2});}
;

InterfaceMemberDeclaration:
    ConstantDeclaration {$$ = create_node("InterfaceMemberDeclaration", {$1});}
|   InterfaceMethodDeclaration {$$ = create_node("InterfaceMemberDeclaration", {$1});}
;

ConstantDeclaration:
    FieldDeclaration {$$ = create_node("ConstantDeclaration", {$1});}
;

InterfaceMethodDeclaration: 
    MethodHeader Semicolon {$$ = create_node("InterfaceMethodDeclaration", {$1, $2});}
;

/*
    Productions from Chapter 15 (Expressions)
*/
// Java Expressions Grammer

Primary:    PrimaryNoNewArray {$$ = create_node("Primary", {$1});}
|           ArrayCreationExpression {$$ = create_node("Primary", {$1});}
;

PrimaryNoNewArray:  Literal {$$ = create_node("PrimaryNoNewArray", {$1});}
|                   This {$$ = create_node("PrimaryNoNewArray", {$1});}
|                   Lparen Expression Rparen {$$ = create_node("PrimaryNoNewArray", {$1, $2, $3});}
|                   ClassInstanceCreationExpression {$$ = create_node("PrimaryNoNewArray", {$1});}
|                   FieldAccess {$$ = create_node("PrimaryNoNewArray", {$1});}
|                   ArrayAccess {$$ = create_node("PrimaryNoNewArray", {$1});}
|                   MethodInvocation {$$ = create_node("PrimaryNoNewArray", {$1});}
;


ClassInstanceCreationExpression: 
    New ClassType Lparen ArgumentListopt Rparen {$$ = create_node("ClassInstanceCreationExpression", {$1, $2, $3, $4, $5});}
;



FieldAccess:    Primary Dot Identifier {$$ = create_node("FieldAccess", {$1, $2, $3});}
|               super_ Dot Identifier {$$ = create_node("FieldAccess", {$1, $2, $3});}
;


ArrayAccess:    TypeName Lsquare Expression Rsquare {$$ = create_node("ArrayAccess", {$1, $2, $3, $4});}
|               PrimaryNoNewArray Lsquare Expression Rsquare  {$$ = create_node("ArrayAccess", {$1, $2, $3, $4});}
;

MethodInvocation:   TypeName Lparen ArgumentListopt Rparen {$$ = create_node("MethodInvocation", {$1, $2, $3, $4});}
|                   Primary Dot Identifier Lparen ArgumentListopt Rparen {$$ = create_node("MethodInvocation", {$1, $2, $3, $4, $5});}
|                   super_ Dot Identifier Lparen ArgumentListopt Rparen {$$ = create_node("MethodInvocation", {$1, $2, $3, $4, $5});}
;

/*
Uncomment below rules when Allowing TypeArguments <> args.
Remove above 4 rules
*/
/* |                   TypeName Dot TypeArgumentsopt Identifier Lparen ArgumentListopt Rparen
|                   Primary Dot TypeArgumentsopt Identifier Lparen ArgumentListopt Rparen
|                   Super Dot TypeArgumentsopt Identifier Lparen ArgumentListopt Rparen
|                   TypeName Dot Super Dot TypeArgumentsopt Identifier Lparen ArgumentListopt Rparen */

ArgumentListopt:    
|                   ArgumentList { $$ = create_node("ArgumentListopt", {$1});}

/* TypeArgumentsopt: 
|                   TypeArguments */

ArgumentList:       Expression  { $$ = create_node("ArgumentList", {$1});}
|                   ArgumentList Comma Expression { $$ = create_node("ArgumentList", {$1, $2, $3});}
;

ArrayCreationExpression:    New PrimitiveType DimExprs Dimsopt { $$ = create_node("ArrayCreationExpression", {$1, $2, $3, $4});}
|                           New ClassType DimExprs Dimsopt { $$ = create_node("ArrayCreationExpression", {$1, $2, $3, $4});}
|                           New PrimitiveType Dims ArrayInitializer { $$ = create_node("ArrayCreationExpression", {$1, $2, $3, $4});}
|                           New ClassType Dims ArrayInitializer { $$ = create_node("ArrayCreationExpression", {$1, $2, $3, $4});}
;

Dimsopt: 
|           Dims { $$ = create_node("Dimsopt", {$1});}
;

DimExprs:   DimExpr  { $$ = create_node("DimExprs", {$1});}
|           DimExprs DimExpr { $$ = create_node("DimExprs", {$1, $2});}
;

DimExpr:    Lsquare Expression Rsquare { $$ = create_node("DimExpr", {$1, $2, $3});}

ExpressionOpts: Expression { $$ = create_node("ExpressionOpts", {$1});}
|
;

Expression:  AssignmentExpression { $$ = create_node("Expression", {$1});}

AssignmentExpression:   
    ConditionalExpression { $$ = create_node("AssignmentExpression", {$1});}
|   Assignment { $$ = create_node("AssignmentExpression", {$1});}
;

Assignment:
    LeftHandSide AssignmentOperator Expression { $$ = create_node("Assignment", {$1, $2, $3});}
;

LeftHandSide:
    TypeName { $$ = create_node("LeftHandSide", {$1});}
|   FieldAccess { $$ = create_node("LeftHandSide", {$1});}
|   ArrayAccess { $$ = create_node("LeftHandSide", {$1});}
;

ConditionalExpression:  ConditionalOrExpression { $$ = create_node("ConditionalExpression", {$1});}
|                   ConditionalOrExpression Qm Expression Colon ConditionalExpression { $$ = create_node("ConditionalExpression", {$1, $2, $3, $4, $5});}
;

ConditionalOrExpression:    ConditionalAndExpression { $$ = create_node("ConditionalOrExpression", {$1});}
|                   ConditionalOrExpression Or ConditionalAndExpression { $$ = create_node("ConditionalOrExpression", {$1, $2, $3});}
;

ConditionalAndExpression:   InclusiveOrExpression { $$ = create_node("ConditionalAndExpression", {$1});}
|                   ConditionalAndExpression And InclusiveOrExpression { $$ = create_node("ConditionalAndExpression", {$1, $2, $3});}
;

InclusiveOrExpression:  ExclusiveOrExpression { $$ = create_node("InclusiveOrExpression", {$1});}
|                   InclusiveOrExpression Bitwise_or ExclusiveOrExpression { $$ = create_node("InclusiveOrExpression", {$1, $2, $3});}
;

ExclusiveOrExpression:  AndExpression   { $$ = create_node("ExclusiveOrExpression", {$1});}
|                   ExclusiveOrExpression Bitwise_xor AndExpression { $$ = create_node("ExclusiveOrExpression", {$1, $2, $3});}
;

AndExpression:  EqualityExpression  { $$ = create_node("AndExpression", {$1});}
|                   AndExpression Bitwise_and EqualityExpression { $$ = create_node("InclusiveOrExpression", {$1});}
;

EqualityExpression: RelationalExpression { $$ = create_node("EqualityExpression", {$1});}
|                   EqualityExpression Deq RelationalExpression { $$ = create_node("EqualityExpression", {$1, $2, $3});}
|                   EqualityExpression Neq RelationalExpression { $$ = create_node("EqualityExpression", {$1, $2, $3});}
;

RelationalExpression:   ShiftExpression { $$ = create_node("RelationalExpression", {$1});}
|                   RelationalExpression Lt ShiftExpression { $$ = create_node("RelationalExpression", {$1, $2, $3});}
|                   RelationalExpression Gt ShiftExpression { $$ = create_node("RelationalExpression", {$1, $2, $3});}
|                   RelationalExpression Leq ShiftExpression { $$ = create_node("RelationalExpression", {$1, $2, $3});}
|                   RelationalExpression Geq ShiftExpression { $$ = create_node("RelationalExpression", {$1, $2, $3});}
|                   RelationalExpression Instanceof ReferenceType { $$ = create_node("RelationalExpression", {$1, $2, $3});}
;

/* InstanceofExpression:   RelationalExpression Instanceof ReferenceType
|                   RelationalExpression Instanceof Pattern */

ShiftExpression:    AdditiveExpression { $$ = create_node("ShiftExpression", {$1});}
|                   ShiftExpression Left_shift AdditiveExpression { $$ = create_node("ShiftExpression", {$1, $2, $3});}
|                   ShiftExpression Right_shift AdditiveExpression { $$ = create_node("ShiftExpression", {$1, $2, $3});}
|                   ShiftExpression Unsigned_right_shift AdditiveExpression { $$ = create_node("ShiftExpression", {$1, $2, $3});}
;

AdditiveExpression: MultiplicativeExpression { $$ = create_node("AdditiveExpression", {$1});}
|                   AdditiveExpression Plus MultiplicativeExpression { $$ = create_node("AdditiveExpression", {$1, $2, $3});} 
|                   AdditiveExpression Minus MultiplicativeExpression   { $$ = create_node("AdditiveExpression", {$1, $2, $3});}
;

MultiplicativeExpression:   UnaryExpression { $$ = create_node("MultiplicativeExpression", {$1});}
|                   MultiplicativeExpression Asterik UnaryExpression { $$ = create_node("MultiplicativeExpression", {$1, $2, $3});}
|                   MultiplicativeExpression Div UnaryExpression { $$ = create_node("MultiplicativeExpression", {$1, $2, $3});}
|                   MultiplicativeExpression Modulo UnaryExpression { $$ = create_node("MultiplicativeExpression", {$1, $2, $3});}
;

UnaryExpression:    PreIncrementExpression { $$ = create_node("UnaryExpression", {$1});}
|                   PreDecrementExpression { $$ = create_node("UnaryExpression", {$1});}
|                   Plus UnaryExpression    { $$ = create_node("UnaryExpression", {$1, $2});}
|                   Minus UnaryExpression   { $$ = create_node("UnaryExpression", {$1, $2});}
|                   UnaryExpressionNotPlusMinus { $$ = create_node("UnaryExpression", {$1});}
;

PreIncrementExpression: Increment UnaryExpression   { $$ = create_node("PreIncrementExpression", {$1, $2});}
;

PreDecrementExpression: Decrement UnaryExpression  { $$ = create_node("PreDecrementExpression", {$1, $2});}
;

UnaryExpressionNotPlusMinus:    PostfixExpression   { $$ = create_node("UnaryExpressionNotPlusMinus", {$1});}
|                               Bitwise_complement UnaryExpression  { $$ = create_node("UnaryExpressionNotPlusMinus", {$1, $2});}
|                               Not UnaryExpression { $$ = create_node("UnaryExpressionNotPlusMinus", {$1, $2});}
|                               CastExpression  { $$ = create_node("UnaryExpressionNotPlusMinus", {$1});}
;

PostfixExpression:  Primary { $$ = create_node("PostfixExpression", {$1});}
|                   TypeName    { $$ = create_node("PostfixExpression", {$1});}
|                   PostIncrementExpression { $$ = create_node("PostfixExpression", {$1});}
|                   PostDecrementExpression { $$ = create_node("PostfixExpression", {$1});}
;

PostIncrementExpression:    PostfixExpression Increment { $$ = create_node("PostIncrementExpression", {$1, $2});}
;

PostDecrementExpression:    PostfixExpression Decrement { $$ = create_node("PostDecrementExpression", {$1, $2});}
;

CastExpression:     Lparen PrimitiveType Rparen UnaryExpression { $$ = create_node("CastExpression", {$1, $2, $3, $4});}
|                   Lparen PrimitiveType Dims Rparen UnaryExpression    { $$ = create_node("CastExpression", {$1, $2, $3, $4, $5});}
|                   Lparen Expression Rparen UnaryExpressionNotPlusMinus    { $$ = create_node("CastExpression", {$1, $2, $3, $4});}
|                   Lparen TypeName Dims Rparen UnaryExpressionNotPlusMinus { $$ = create_node("CastExpression", {$1, $2, $3, $4, $5});}
;



/*  
    * Production
    * Chapter 14: (Blocks, Statements, and Patterns)
*/


Block:    Lcurly Rcurly { $$ = create_node("Block", {$1, $2});}
|         Lcurly BlockStatements Rcurly { $$ = create_node("Block", {$1, $2, $3});}
;

BlockStatements:    BlockStatements BlockStatement  { $$ = create_node("BlockStatements", {$1, $2});}
|                   BlockStatement  { $$ = create_node("BlockStatements", {$1});}
;

BlockStatement:     
                    LocalVariableDeclarationStatement   { $$ = create_node("BlockStatement", {$1});}
|                   Statement   { $$ = create_node("BlockStatement", {$1});}
;

/* LocalClassDeclaration:    ClassDeclaration
; */


LocalVariableDeclarationStatement:    LocalVariableDeclaration  { $$ = create_node("LocalVariableDeclarationStatement", {$1});}
;

LocalVariableDeclaration:    UnannType VariableDeclaratorList   { $$ = create_node("LocalVariableDeclaration", {$1, $2});}
;


Statement:          StatementWithoutTrailingSubstatement    { $$ = create_node("Statement", {$1});}
|                   LabeledStatement    { $$ = create_node("Statement", {$1});}
|                   IfThenStatement   { $$ = create_node("Statement", {$1});}
|                   IfThenElseStatement  { $$ = create_node("Statement", {$1});}
|                   WhileStatement  { $$ = create_node("Statement", {$1});}
|                   ForStatement    { $$ = create_node("Statement", {$1});}
;

StatementNoShortIf:     StatementWithoutTrailingSubstatement    { $$ = create_node("StatementNoShortIf", {$1});}
|                       LabeledStatementNoShortIf   { $$ = create_node("StatementNoShortIf", {$1});}
|                       IfThenElseStatementNoShortIf    { $$ = create_node("StatementNoShortIf", {$1});}
|                       WhileStatementNoShortIf { $$ = create_node("StatementNoShortIf", {$1});}
|                       ForStatementNoShortIf   { $$ = create_node("StatementNoShortIf", {$1});}
;

StatementWithoutTrailingSubstatement:   Block   { $$ = create_node("StatementWithoutTrailingSubstatement", {$1});}
|                                       EmptyStatement  { $$ = create_node("StatementWithoutTrailingSubstatement", {$1});}
|                                       ExpressionStatement { $$ = create_node("StatementWithoutTrailingSubstatement", {$1});}
|                                       AssertStatement { $$ = create_node("StatementWithoutTrailingSubstatement", {$1});}
|                                       BreakStatement  { $$ = create_node("StatementWithoutTrailingSubstatement", {$1});}
|                                       ContinueStatement   { $$ = create_node("StatementWithoutTrailingSubstatement", {$1});}
|                                       ReturnStatement { $$ = create_node("StatementWithoutTrailingSubstatement", {$1});}
|                                       ThrowStatement  { $$ = create_node("StatementWithoutTrailingSubstatement", {$1});}
;

EmptyStatement:    Semicolon    { $$ = create_node("EmptyStatement", {$1});}
;

LabeledStatement:    Identifier Colon Statement   { $$ = create_node("LabeledStatement", {$1, $2, $3});}
;

LabeledStatementNoShortIf:    Identifier Colon StatementNoShortIf   { $$ = create_node("LabeledStatementNoShortIf", {$1, $2, $3});}
;

ExpressionStatement:    StatementExpression Semicolon   { $$ = create_node("ExpressionStatement", {$1, $2});}

StatementExpression:    Assignment  { $$ = create_node("StatementExpression", {$1});}
|                       PreIncrementExpression  { $$ = create_node("StatementExpression", {$1});}
|                       PreDecrementExpression  { $$ = create_node("StatementExpression", {$1});}
|                       PostIncrementExpression { $$ = create_node("StatementExpression", {$1});}
|                       PostDecrementExpression { $$ = create_node("StatementExpression", {$1});}
|                       MethodInvocation        { $$ = create_node("StatementExpression", {$1});}
|                       ClassInstanceCreationExpression  { $$ = create_node("StatementExpression", {$1});}

IfThenStatement:    If Lparen Expression Rparen Statement   { $$ = create_node("IfThenStatement", {$1, $2, $3, $4, $5});}
;

IfThenElseStatement:    If Lparen Expression Rparen StatementNoShortIf Else Statement   { $$ = create_node("IfThenElseStatement", {$1, $2, $3, $4, $5, $6, $7});}
;

IfThenElseStatementNoShortIf:    If Lparen Expression Rparen StatementNoShortIf Else StatementNoShortIf  { $$ = create_node("IfThenElseStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7});}
;

AssertStatement:    Assert Expression Semicolon  { $$ = create_node("AssertStatement", {$1, $2, $3});}
|                   Assert Expression Colon Expression Semicolon    { $$ = create_node("AssertStatement", {$1, $2, $3, $4, $5});}
;

WhileStatement:    While Lparen Expression Rparen Statement  { $$ = create_node("WhileStatement", {$1, $2, $3, $4, $5});}
;

WhileStatementNoShortIf:    While Lparen Expression Rparen StatementNoShortIf   { $$ = create_node("WhileStatementNoShortIf", {$1, $2, $3, $4, $5});}
;

ForStatement:       BasicForStatement   { $$ = create_node("ForStatement", {$1});}
|                   EnhancedForStatement    { $$ = create_node("ForStatement", {$1});}
;

ForStatementNoShortIf:    BasicForStatementNoShortIf    { $$ = create_node("ForStatementNoShortIf", {$1});}
|                   EnhancedForStatementNoShortIf   { $$ = create_node("ForStatementNoShortIf", {$1});}
;

BasicForStatement:     For Lparen ForInitOpt Semicolon ExpressionOpts Semicolon ForUpdateOpts Rparen Statement  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6, $7, $8});}
;

BasicForStatementNoShortIf:    For Lparen ForInitOpt Semicolon ExpressionOpts Semicolon ForUpdateOpts Rparen StatementNoShortIf { $$ = create_node("BasicForStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7, $8});}
;

ForInitOpt:    ForInit  { $$ = create_node("ForInitOpt", {$1});}
|
;

ForInit:    StatementExpressionList { $$ = create_node("ForInit", {$1});}
|           LocalVariableDeclaration    { $$ = create_node("ForInit", {$1});}
;

ForUpdateOpts:  ForUpdate   { $$ = create_node("ForUpdateOpts", {$1});}
|
;

ForUpdate:    StatementExpressionList   { $$ = create_node("ForUpdate", {$1});}
;

StatementExpressionList:    StatementExpression { $$ = create_node("StatementExpressionList", {$1});}
|                           StatementExpression CommaStatementExpressions   { $$ = create_node("StatementExpressionList", {$1, $2});}
;

CommaStatementExpressions:   Comma StatementExpression CommaStatementExpressions    { $$ = create_node("CommaStatementExpressions", {$1, $2, $3});}
|                            Comma StatementExpression  { $$ = create_node("CommaStatementExpressions", {$1, $2});}
;

EnhancedForStatement:    For Lparen LocalVariableDeclaration Colon Expression Rparen Statement  { $$ = create_node("EnhancedForStatement", {$1, $2, $3, $4, $5, $6, $7});}
;

EnhancedForStatementNoShortIf:    For Lparen LocalVariableDeclaration Colon Expression Rparen StatementNoShortIf    { $$ = create_node("EnhancedForStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7});}
;

BreakStatement:    Break IdentifierOpts Semicolon   { $$ = create_node("BreakStatement", {$1, $2, $3});}
;

ContinueStatement:    Continue IdentifierOpts Semicolon  { $$ = create_node("ContinueStatement", {$1, $2, $3});}
;

ReturnStatement:
    Return ExpressionOpts Semicolon { $$ = create_node("ReturnStatement", {$1, $2, $3});}
;

ThrowStatement:    Throw Expression Semicolon   { $$ = create_node("ThrowStatement", {$1, $2, $3});}
;

IdentifierOpts:     Identifier  { $$ = create_node("IdentifierOpts", {$1});}
|
;

// Non-Terminals for representing terminals

Int : INT { $$ = create_leaf($1, "INT"); }
;

Long : LONG { $$ = create_leaf($1, "LONG"); }
;

Byte : BYTE { $$ = create_leaf($1, "BYTE"); }
;

Short : SHORT { $$ = create_leaf($1, "SHORT"); }
;

Char : CHAR { $$ = create_leaf($1, "CHAR"); }
;

Float : FLOAT { $$ = create_leaf($1, "FLOAT"); }
;

Double : DOUBLE { $$ = create_leaf($1, "DOUBLE"); }
;

Boolean : BOOLEAN { $$ = create_leaf($1, "BOOLEAN"); }
;

Var : VAR { $$ = create_leaf($1, "VAR"); }
;

If : IF { $$ = create_leaf($1, "IF"); }
;

Else : ELSE { $$ = create_leaf($1, "ELSE"); }
;

While : WHILE { $$ = create_leaf($1, "WHILE"); }
;

For : FOR { $$ = create_leaf($1, "FOR"); }
;


Break : BREAK { $$ = create_leaf($1, "BREAK"); }
;

Continue : CONTINUE { $$ = create_leaf($1, "CONTINUE"); }
;

Void : VOID { $$ = create_leaf($1, "VOID"); }
;

New : NEW { $$ = create_leaf($1, "NEW"); }
;

Return : RETURN { $$ = create_leaf($1, "RETURN"); }
;

Public : PUBLIC { $$ = create_leaf($1, "PUBLIC"); }
;

Private : PRIVATE { $$ = create_leaf($1, "PRIVATE"); }
;

Class : CLASS { $$ = create_leaf($1, "Keyword"); }
;

Static : STATIC { $$ = create_leaf($1, "STATIC"); }
;

Final : FINAL { $$ = create_leaf($1, "FINAL"); }
;


Assert : ASSERT { $$ = create_leaf($1, "ASSERT"); }
;



Plus : PLUS { $$ = create_leaf($1, "PLUS"); }
;

Minus : MINUS { $$ = create_leaf($1, "MINUS"); }
;

Div : DIV { $$ = create_leaf($1, "DIV"); }
;

Modulo : MODULO { $$ = create_leaf($1, "MODULO"); }
;

Increment : INCREMENT { $$ = create_leaf($1, "INCREMENT"); }
;

Decrement : DECREMENT { $$ = create_leaf($1, "DECREMENT"); }
;

Geq : GEQ { $$ = create_leaf($1, "GEQ"); }
;

Leq : LEQ { $$ = create_leaf($1, "LEQ"); }
;

Gt : GT { $$ = create_leaf($1, "GT"); }
;

Lt : LT { $$ = create_leaf($1, "LT"); }
;

Neq : NEQ { $$ = create_leaf($1, "NEQ"); }
;

Deq : DEQ { $$ = create_leaf($1, "DEQ"); }
;

Bitwise_and : BITWISE_AND { $$ = create_leaf($1, "BITWISE_AND"); }
;

Bitwise_or : BITWISE_OR { $$ = create_leaf($1, "BITWISE_OR"); }
;

Bitwise_xor : BITWISE_XOR { $$ = create_leaf($1, "BITWISE_XOR"); }
;

Bitwise_complement : BITWISE_COMPLEMENT { $$ = create_leaf($1, "BITWISE_COMPLEMENT"); }
;

Left_shift : LEFT_SHIFT { $$ = create_leaf($1, "LEFT_SHIFT"); }
;

Right_shift : RIGHT_SHIFT { $$ = create_leaf($1, "RIGHT_SHIFT"); }
;

Unsigned_right_shift : UNSIGNED_RIGHT_SHIFT { $$ = create_leaf($1, "UNSIGNED_RIGHT_SHIFT"); }
;

And : AND { $$ = create_leaf($1, "AND"); }
;

Or : OR { $$ = create_leaf($1, "OR"); }
;

Not : NOT { $$ = create_leaf($1, "NOT"); }
;

AssignmentOperator:  ASSIGNMENT { $$ = create_leaf($1, "ASSIGNMENT"); }
;


Double_colon : DOUBLE_COLON { $$ = create_leaf($1, "DOUBLE_COLON"); }
;

Colon : COLON { $$ = create_leaf($1, "COLON"); }
;

Qm : QM { $$ = create_leaf($1, "QM"); }
;

Lparen : LPAREN { $$ = create_leaf($1, "LPAREN"); }
;

Rparen : RPAREN { $$ = create_leaf($1, "RPAREN"); }
;

Lcurly : LCURLY { $$ = create_leaf($1, "LCURLY"); }
;

Rcurly : RCURLY { $$ = create_leaf($1, "RCURLY"); }
;

Lsquare : LSQUARE { $$ = create_leaf($1, "LSQUARE"); }
;

Rsquare : RSQUARE { $$ = create_leaf($1, "RSQUARE"); }
;

Semicolon : SEMICOLON { $$ = create_leaf($1, "SEMICOLON"); }
;

Comma : COMMA { $$ = create_leaf($1, "COMMA"); }
;

Dot : DOT { $$ = create_leaf($1, "DOT"); }
;

Char_literal : CHAR_LITERAL { $$ = create_leaf($1, "CHAR_LITERAL"); }
;

Boolean_literal : BOOLEAN_LITERAL { $$ = create_leaf($1, "BOOLEAN_LITERAL"); }
;

Null_literal : NULL_LITERAL { $$ = create_leaf($1, "NULL_LITERAL"); }
;

Integer_literal : INTEGER_LITERAL { $$ = create_leaf($1, "INTEGER_LITERAL"); }
;

Fp_literal : FP_LITERAL { $$ = create_leaf($1, "FP_LITERAL"); }
;

String : STRING { $$ = create_leaf($1, "STRING"); }
;

Text_block : TEXT_BLOCK { $$ = create_leaf($1, "TEXT_BLOCK"); }
;

Identifier : IDENTIFIER { $$ = create_leaf($1, "IDENTIFIER"); }
;

This : THIS { $$ = create_leaf($1, "THIS"); }
;

Instanceof : INSTANCEOF { $$ = create_leaf($1, "INSTANCEOF"); }
;

super_ : SUPER { $$ = create_leaf($1, "SUPER"); }
;

Throw : THROW { $$ = create_leaf($1, "THROW"); }
;

Implements : IMPLEMENTS { $$ = create_leaf($1, "IMPLEMENTS"); }
;

Interface : INTERFACE { $$ = create_leaf($1, "INTERFACE"); }
;

Extends : EXTENDS { $$ = create_leaf($1, "EXTENDS"); }
;

Package : PACKAGE { $$ = create_leaf($1, "PACKAGE"); }
;

Import : IMPORT { $$ = create_leaf($1, "IMPORT"); }
;

Asterik : ASTERIK { $$ = create_leaf($1, "ASTERIK"); }
;

Diamond : DIAMOND { $$ = create_leaf($1, "DIAMOND"); }
;


%%

// int main(int argc, char* argv[]) {
//     if (argc != 2) {
//         cout << "format: ./build/run <file name>" << endl;
//         exit (1);
//     }
//     yyin = fopen(argv[1], "r");

//     yydebug = 1;

//     printf("digraph AST {\n");
//     printf("node [shape=circle,fontname=\"Courier-Bold\",fontsize=16];\n");
//     printf("edge [color=blue];\n");

//     do {
//         yyparse();
//     } while(!feof(yyin));

//     printf("}");

//     /* Print Stats*/
//     /* print_stats(); */

//     return 0;
// }

int main() {
    printf("digraph AST {\n");
    printf("node [shape=circle,fontname=\"Courier-Bold\",fontsize=12];\n");
    printf("edge [color=blue];\n");

    do {
        yyparse();
    } while(!feof(yyin));

    printf("}");
    return 0;
}

int yyerror(const char *s) {
    printf("syntax error: line %d: %s\n", yylineno, s);
    exit(1);
}
