%{
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include <iomanip>
    #include <vector>
    #include <fstream>
    #include <argparse/argparse.hpp>
    
    #define YYDEBUG 1
    using namespace std;


    extern "C" int yylex();
    extern "C" FILE *yyin;
    extern "C" int yylineno;


    struct args {
        char *input;
        char *output;
        bool verbose;    
    };
    
    static int node_num=-1, scope=0;

    ofstream dotfile;

    int yyerror(const char *);

    struct symbol_struct {
        char *type;
        char *attr;
        int scope;
    };

    /*
    
    
    
    
    */

    struct method_meta_struct {
        char* method_name;
        char *class_name;
        map<string, *symbol_struct> *local_symbol;

    };

    void test 
    int create_node(char* label, vector<int> children_node_num){
        //A new node created with given label and edges from current node_num to all children_node_num
        dotfile << "node" << ++node_num << "[label=\"" << label << "\"];\n";
        for (auto& child : children_node_num){
            dotfile << "node" << node_num << " -> node" << child << ";\n";
        }
        dotfile.flush();
        return node_num;
    }

    int create_leaf(char* lexeme, char* token){

        if(strcmp(token, "STRING")==0){    
            
            dotfile << "node" << ++node_num << "[label=\"" << token << "(";

            dotfile << "\\\""; lexeme++;

            while(lexeme[0] != '"'){
                if(lexeme[0] == '\\'){
                    dotfile << "\\\\";
                }
                else{
                    dotfile << lexeme[0];
                }
                lexeme++;
            }

            dotfile << "\\\"";
            
            dotfile << ")\"];\n";

        }
        else if(strcmp(token, "TEXT_BLOCK")==0){   


            dotfile << "node" << ++node_num << "[label=\"" << token << "(";

            dotfile << "\\\""; lexeme++;   dotfile << "\\\""; lexeme++;  dotfile << "\\\""; lexeme++;

            while(lexeme[0] != '"' && lexeme[1] != '"' && lexeme[2] != '"'){
                if(lexeme[0] == '\\'){
                    dotfile << "\\\\";
                }
                else if(lexeme[0] == '"'){
                    dotfile << "\\\"";
                }
                else{
                    dotfile << lexeme[0];
                }
                lexeme++;
            }
            
            dotfile << "\\\"" ; dotfile << "\\\""; dotfile << "\\\"";

            dotfile << ")\"];\n";
                   
            
        }
        else
            dotfile << "node" << ++node_num << "[label=\"" << token << "(" << lexeme << ")\"];\n";
        
        dotfile.flush();
        return node_num;
    }

    int create_edges(int parent_node_num, vector<int> children_node_num){
        for (auto& child : children_node_num){
            dotfile << "node" << parent_node_num << "-> node" << child << ";\n";
        }
        dotfile.flush();
        return parent_node_num;
    }

    


    map<string, string> symbol_table;

    // Define a function to add a symbol to the table
    void add_symbol(string name, string type, int scope) {
        // string key = name + "." + to_string(scope);
        // if (symbol_table.count(key) > 0) {
        //     // symbol already exists in this scope
        //     // print error message and exit
        //     printf("Error: symbol '%s' already declared in this scope\n", name.c_str());
        //     exit(1);
        // } else {
        //     // add symbol to the table
        //     symbol_table[key] = type;
        // }
    }

    // Define a function to look up a symbol in the table
    int lookup_symbol(string name, int scope) {
        string key = name + "." + to_string(scope);
        if (symbol_table.count(key) > 0) {
            // symbol found in table, return its type
            return symbol_table[key];
        } else {
            // symbol not found in table, print error message and exit
            printf("Error: symbol '%s' not declared in this scope\n", name.c_str());
            exit(1);
        }
}
%}

%define parse.error verbose

%union {
    int num;
    double float_num;
    char* str;
}

%token<str> INT LONG BYTE CHAR SHORT FLOAT DOUBLE BOOLEAN VAR IF ELSE FOR WHILE BREAK CONTINUE VOID NEW RETURN PUBLIC PRIVATE CLASS STATIC FINAL SWITCH YIELD CATCH FINALLY SYNCHRONIZED ASSERT PLUS MINUS DIV MODULO INCREMENT DECREMENT GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_COMPLEMENT LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT AND OR NOT ASSIGNMENT ASSIGN COLON QM LPAREN RPAREN LCURLY RCURLY LSQUARE RSQUARE SEMICOLON COMMA DOT ARROW CHAR_LITERAL BOOLEAN_LITERAL NULL_LITERAL INTEGER_LITERAL FP_LITERAL STRING TEXT_BLOCK IDENTIFIER THIS INSTANCEOF SUPER THROW THROWS EOF_ IMPLEMENTS INTERFACE EXTENDS PACKAGE IMPORT ASTERIK DO TRY CASE DEFAULT

%left INCREMENT DECREMENT NOT BITWISE_COMPLEMENT ASTERIK DIV MODULO PLUS MINUS LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT  GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_XOR BITWISE_OR AND OR

%right ASSIGNMENT ASSIGN

%type<num> Program CompilationUnit ClassOrInterfaceDeclaration ClassOrInterfaceDeclarations PackageDeclaration ImportDeclaration Literal UnannType PrimitiveType NumericType IntegralType FloatingPointType ReferenceType  ClassOrInterfaceType ArrayType Dims TypeName Modifiers ClassDeclaration super_ Interfaces InterfaceTypeList ClassBody ClassBodyDeclarations ClassBodyDeclaration ClassMemberDeclaration FieldDeclaration VariableDeclaratorList VariableDeclarator VariableDeclaratorId VariableInitializer MethodDeclaration MethodHeader Declarator FormalParameterList FormalParameter MethodBody StaticInitializer ConstructorDeclaration ConstructorBody ExplicitConstructorInvocation ArrayInitializer VariableInitializerList InterfaceDeclaration InterfaceExtends InterfaceBody InterfaceMembers InterfaceMemberDeclaration ConstantDeclaration InterfaceMethodDeclaration Primary PrimaryNoNewArray ClassInstanceCreationExpression FieldAccess ArrayAccess MethodInvocation ArgumentList ArrayCreationExpression DimExprs DimExpr Expression AssignmentExpression Assignment Assign LeftHandSide AssignmentOperator ConditionalExpression ConditionalOrExpression ConditionalAndExpression InclusiveOrExpression ExclusiveOrExpression AndExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression UnaryExpression PreIncrementExpression PreDecrementExpression UnaryExpressionNotPlusMinus PostfixExpression PostIncrementExpression PostDecrementExpression CastExpression Block BlockStatements BlockStatement Statement StatementNoShortIf StatementWithoutTrailingSubstatement EmptyStatement LabeledStatement LabeledStatementNoShortIf ExpressionStatement StatementExpression IfThenElseStatement IfThenElseStatementNoShortIf AssertStatement WhileStatement WhileStatementNoShortIf ForStatement ForStatementNoShortIf BasicForStatement BasicForStatementNoShortIf ForInit ForUpdate StatementExpressionList CommaStatementExpressions EnhancedForStatement EnhancedForStatementNoShortIf BreakStatement ContinueStatement ReturnStatement ThrowStatement IfThenStatement LocalVariableDeclaration LocalVariableDeclarationStatement Super Int Long Byte Char Short Float Double Boolean Var If Else For While Break Continue Void New Return Class Assert Plus Minus Div Modulo Increment Decrement Geq Leq Gt Lt Neq Deq Bitwise_and Bitwise_or Bitwise_xor Bitwise_complement Left_shift Right_shift Unsigned_right_shift And Or Not Colon Qm Lparen Rparen Lcurly Rcurly Lsquare Rsquare Semicolon Comma Dot This Instanceof Throw Implements Interface Extends Package Import Asterik SynchronizedStatement DoStatement TryStatement YieldStatement SwitchBlock SwitchBlockStatementGroup SwitchBlockStatementGroups SwitchLabel SwitchLabelColons SwitchRule SwitchRules SwitchStatement CatchClause Catches CatchFormalParameter CatchType Finally CaseConstant CaseConstants do_ switch_ yield_ try_ catch_ finally_ synchronized_ throws_ case_ default_ arrow_ endoffile ImportDeclarations Throws ExceptionType ExceptionTypeList CommaExceptionTypes

%type<str> Char_literal Boolean_literal Null_literal Integer_literal Fp_literal String Text_block Identifier
%type<str> Public Private Static Final Modifier
%start Program
%%

Program:
    CompilationUnit endoffile {$$ = create_node("Program", {$1, $2});}; 

/*     Productions from Chapter 7 (Package and Modueles)           */
CompilationUnit:
    PackageDeclaration ImportDeclarations ClassOrInterfaceDeclarations {$$ = create_node("CompilationUnit", {$1, $2, $3});}
|   ImportDeclarations ClassOrInterfaceDeclarations {$$ = create_node("CompilationUnit", {$1, $2});}
|   PackageDeclaration ClassOrInterfaceDeclarations {$$ = create_node("CompilationUnit", {$1, $2});}
|   ClassOrInterfaceDeclarations {$$ = create_node("Compilation Unit", {$1});}
;

ClassOrInterfaceDeclarations:
    ClassOrInterfaceDeclaration {$$ = $1;}
|   ClassOrInterfaceDeclarations ClassOrInterfaceDeclaration {$$ = create_node("ClassOrInterfaceDeclarations", {$1, $2});}
;

ClassOrInterfaceDeclaration:
    ClassDeclaration {$$ = $1;}
|   InterfaceDeclaration  {$$ = $1;}
;


PackageDeclaration:
    Package TypeName Semicolon {$$ = create_node("PackageDeclaration", {$1, $2, $3});}
;
ImportDeclarations:
    ImportDeclarations ImportDeclaration {$$ = create_node("ImportDeclarations", {$1, $2}); }
|   ImportDeclaration       { $$ = $1; }
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
Literal:    Integer_literal {$$ = $1;}
|           Fp_literal  {$$ = $1;}
|           Char_literal  {$$ = $1;}
|           String  {$$ = $1;}
|           Text_block  {$$ = $1;}
|           Boolean_literal  {$$ = $1;}
|           Null_literal  {$$ = $1;}
;
/*
    Productions from Chapter 4 (Types, values, and variables)
*/

/*
    int, long, float, char, double, char, byte, short
*/
UnannType:
    PrimitiveType   {$$ = $1; }
|   ReferenceType   {$$ = $1; }
;

PrimitiveType:      
    NumericType {$$ = $1; }
|   Boolean  {$$ = $1; }
;

NumericType:        
    IntegralType {$$ = $1; }
|   FloatingPointType  {$$ = $1; }
;

IntegralType:       Byte  {$$ = $1; }
|                   Short  {$$ = $1; }
|                   Int  {$$ = $1; }
|                   Long  {$$ = $1; }
|                   Char {$$ = $1; }
;

FloatingPointType:    Float { $$ = $1; }
|                     Double { $$ = $1; }
;

/*
    *   Identifier(id1, id2)
    *   ArrayType ()
*/
ReferenceType:
    ClassOrInterfaceType {$$ = $1; }
|   ArrayType {$$ = $1; }
;

ClassOrInterfaceType:
    TypeName    {$$ = $1; }
;


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
    Identifier  {$$ = $1; }
|   TypeName Dot Identifier {$$ = create_node("Dims", {$1, $2 , $3});}
;


/**************************************/


Modifiers:
    Modifier {$$ = $1; }
|   Modifiers Modifier {$$ = create_node("Modifiers", {$1, $2});}
;

// *************Need to confirm it *******
Modifier:
    Public      { $$ = $1; } 
|   Private     { $$ = $1; }
|   Static      { $$ = $1; }
|   Final       { $$ = $1; }
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
    Extends ClassOrInterfaceType {$$ = create_node("Super", {$1, $2});}
;

Interfaces:
    Implements InterfaceTypeList {$$ = create_node("Interfaces", {$1, $2});}
;

InterfaceTypeList:
    ClassOrInterfaceType {$$ = $1; }
|   InterfaceTypeList Comma ClassOrInterfaceType { $$ = create_node("InterfaceTypeList", {$1, $2, $3}); }
;

ClassBody:
    Lcurly ClassBodyDeclarations Rcurly {$$ = create_node("ClassBody", {$1, $2, $3});}
|   Lcurly Rcurly {$$ = create_node("ClassBody", {$1, $2});}
;

ClassBodyDeclarations:
    ClassBodyDeclarations ClassBodyDeclaration {$$ = create_node("ClassBodyDeclarations", {$1, $2});}
|   ClassBodyDeclaration {$$ = $1; }
;

ClassBodyDeclaration:
    ClassMemberDeclaration {$$ = $1; }
|   ConstructorDeclaration {$$ = $1; }
|   StaticInitializer {$$ = $1; }
|   Block               {$$ = $1; }
;

// Inner Classes and Interfaces are not supported
ClassMemberDeclaration:
    FieldDeclaration {$$ = $1; }
|   MethodDeclaration {$$ = $1; }
|   ClassDeclaration  {$$ = $1;}
|   InterfaceDeclaration {$$ = $1;}
;

FieldDeclaration:
    Modifiers UnannType VariableDeclaratorList Semicolon {$$ = create_node("FieldDeclaration", {$1, $2, $3, $4});}
|   UnannType VariableDeclaratorList Semicolon {$$ = create_node("FieldDeclaration", {$1, $2, $3});}
;

VariableDeclaratorList:
    VariableDeclaratorList Comma VariableDeclarator {$$ = create_node("VariableDeclaratorList", {$1, $2, $3});}
|   VariableDeclarator {$$ = $1; }
;

VariableDeclarator:
    VariableDeclaratorId Assign VariableInitializer             {
                                                                    create_edges($2, {$1, $3});
                                                                    $$ = $2;
                                                                }
|   VariableDeclaratorId {$$ = $1; }
;

VariableDeclaratorId:
    VariableDeclaratorId Lsquare Rsquare {$$ = create_node("VariableDeclaratorId", {$1, $2, $3});}
|   Identifier {$$ = $1; }
;

VariableInitializer:
    Expression {$$ = $1; }
|   ArrayInitializer {$$ = $1; }
;

MethodDeclaration:
    MethodHeader MethodBody {$$ = create_node("MethodDeclaration", {$1, $2});}
;

MethodHeader: // correct
    Modifiers UnannType Declarator        {$$ = create_node("MethodHeader", {$1, $2, $3});}
|   UnannType Declarator                  {$$ = create_node("MethodHeader", {$1, $2});}
|   Modifiers Void Declarator             {$$ = create_node("MethodHeader", {$1, $2, $3});}
|   Void Declarator                       {$$ = create_node("MethodHeader", {$1, $2});}
|   Modifiers UnannType Declarator Throws {$$ = create_node("MethodHeader", {$1, $2, $3, $4});}
|   UnannType Declarator Throws           {$$ = create_node("MethodHeader", {$1, $2, $3});}
|   Modifiers Void Declarator Throws      {$$ = create_node("MethodHeader", {$1, $2, $3, $4});}
|   Void Declarator Throws                {$$ = create_node("MethodHeader", {$1, $2, $3});}
;

Throws:
    throws_ ExceptionTypeList             {$$ = create_node("Throws", {$1, $2});}       

ExceptionTypeList:
    ExceptionType                         {$$ = $1;}
|   ExceptionType CommaExceptionTypes     {$$ = create_node("ExceptionTypeList", {$1, $2});}
    
CommaExceptionTypes:
    CommaExceptionTypes Comma ExceptionType  {$$ = create_node("CommaExceptionTypes", {$1, $2, $3});}
|   Comma ExceptionType                      {$$ = create_node("CommaExceptionTypes", {$1, $2});} 

ExceptionType:
    ClassOrInterfaceType                    {$$ = $1;}


/*
    Added in place  of MethodDeclarator and ConstructorDeclarator
*/
Declarator:
    Identifier Lparen Rparen {$$ = create_node("Declarator", {$1, $2, $3});}
|   Identifier Lparen FormalParameterList Rparen {$$ = create_node("Declarator", {$1, $2, $3, $4});}
;

FormalParameterList:
    FormalParameterList Comma FormalParameter {$$ = create_node("FormalParameterList", {$1, $2, $3});}
|   FormalParameter {$$ = $1; }
;

FormalParameter:
    UnannType VariableDeclaratorId {$$ = create_node("FormalParameter", {$1, $2});}
;


MethodBody:
    Block {$$ = $1; }
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
    This Lparen Rparen {$$ = create_node("ExplicitConstructorInvocation", {$1, $2, $3});}
|   This Lparen ArgumentList Rparen {$$ = create_node("ExplicitConstructorInvocation", {$1, $2, $3, $4});}
|   super_ Lparen Rparen {$$ = create_node("ExplicitConstructorInvocation", {$1, $2, $3});}
|   super_ Lparen ArgumentList Rparen {$$ = create_node("ExplicitConstructorInvocation", {$1, $2, $3, $4});}
;

ArrayInitializer:
    Lcurly VariableInitializerList Rcurly { $$ = create_node("ArrayInitializer", {$1, $2, $3});}
|   Lcurly Rcurly { $$ = create_node("ArrayInitializer", {$1, $2});}
|   Lcurly VariableInitializerList Comma Rcurly { $$ = create_node("ArrayInitializer", {$1, $2, $3, $4});}
|   Lcurly Comma Rcurly { $$ = create_node("ArrayInitializer", {$1, $2, $3});}
;

VariableInitializerList:
    VariableInitializerList Comma VariableInitializer { $$ = create_node("VariableInitializerList", {$1, $2, $3});}
|   VariableInitializer {$$ = $1; }
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
    InterfaceMemberDeclaration {$$ = $1; }
|   InterfaceMembers InterfaceMemberDeclaration {$$ = create_node("InterfaceMembers", {$1, $2});}
;

InterfaceMemberDeclaration:
    ConstantDeclaration {$$ = $1; }
|   InterfaceMethodDeclaration {$$ = $1; }
;

ConstantDeclaration:
    FieldDeclaration {$$ = $1; }
;

InterfaceMethodDeclaration: 
    MethodHeader Semicolon {$$ = create_node("InterfaceMethodDeclaration", {$1, $2});}
;

/*
    Productions from Chapter 15 (Expressions)
*/
// Java Expressions Grammer

Primary:    PrimaryNoNewArray {$$ = $1; }
|           ArrayCreationExpression {$$ = $1; }
;
// A -> B   $$.type = $1.type

PrimaryNoNewArray:  Literal {$$ = $1; }
|                   This {$$ = $1; }
|                   Lparen Expression Rparen {$$ = create_node("PrimaryNoNewArray", {$1, $2, $3});} //Check Again
|                   ClassInstanceCreationExpression {$$ = $1; }
|                   FieldAccess {$$ = $1; }
|                   ArrayAccess {$$ = $1; }
|                   MethodInvocation {$$ = $1; }
;
// A -> Lparen B Rparen    $$.type = $2.type

ClassInstanceCreationExpression: 
    New ClassOrInterfaceType Lparen Rparen {$$ = create_node("ClassInstanceCreationExpression", {$1, $2, $3, $4});}
|   New ClassOrInterfaceType Lparen ArgumentList Rparen {$$ = create_node("ClassInstanceCreationExpression", {$1, $2, $3, $4, $5});}
;
// A -> new B Lparen Rparen    $$.type = $2.type + "*"
// A -> new B Lparen C Rparen    $$.type = $2.type + "*"   $4.type = "int"

FieldAccess:    Primary Dot Identifier {$$ = create_node("FieldAccess", {$1, $2, $3});}
|               super_ Dot Identifier {$$ = create_node("FieldAccess", {$1, $2, $3});}
|               TypeName Dot super_ Dot Identifier {$$ = create_node("FieldAccess", {$1, $2, $3, $4, $5});}
;
// ?????............????? 

ArrayAccess:    TypeName Lsquare Expression Rsquare {$$ = create_node("ArrayAccess", {$1, $2, $3, $4});}
|               PrimaryNoNewArray Lsquare Expression Rsquare  {$$ = create_node("ArrayAccess", {$1, $2, $3, $4});}
;
// A -> B Lsquare C Rsquare    $$.type = $1.type + "*"      $3.type = "int"

MethodInvocation:   TypeName Lparen Rparen {$$ = create_node("MethodInvocation", {$1, $2, $3});}
|                   TypeName Lparen ArgumentList Rparen {$$ = create_node("MethodInvocation", {$1, $2, $3, $4});}
|                   Primary Dot Identifier Lparen Rparen {$$ = create_node("MethodInvocation", {$1, $2, $3, $4, $5});}
|                   Primary Dot Identifier Lparen ArgumentList Rparen {$$ = create_node("MethodInvocation", {$1, $2, $3, $4, $5, $6});}
|                   super_ Dot Identifier Lparen Rparen {$$ = create_node("MethodInvocation", {$1, $2, $3, $4, $5});}
|                   super_ Dot Identifier Lparen ArgumentList Rparen {$$ = create_node("MethodInvocation", {$1, $2, $3, $4, $5, $6});}
;
// A -> B Lparen Rparen    $$.type = $1.type    $1.nature = "function"     $1.argtype = ""
// A -> B Lparen C Rparen      $$.type = $1.type    $1.nature = "function"     $1.argtype = $3.type   This argtype will be string concatenation of arguments type with a " , " in between
// A -> B Dot C Lparen D Rparen    $$.type = $3.type    $1.nature = "class"    $3.nature = "function"    $3.argtype = $5.type
// A -> B Dot C Lparen Rparen    $$.type = $3.type    $1.nature = "class"    $3.nature = "function"    $3.argtype = ""

ArgumentList:       Expression  {$$ = $1; }
|                   ArgumentList Comma Expression { $$ = create_node("ArgumentList", {$1, $2, $3});}
;
// A -> B Comma C    $$.argtype = $1.argtype + " , " + $3.type

ArrayCreationExpression:    New PrimitiveType DimExprs Dims { $$ = create_node("ArrayCreationExpression", {$1, $2, $3, $4});}
|                           New ClassOrInterfaceType DimExprs Dims { $$ = create_node("ArrayCreationExpression", {$1, $2, $3, $4});}
|                           New PrimitiveType DimExprs { $$ = create_node("ArrayCreationExpression", {$1, $2, $3});}
|                           New ClassOrInterfaceType DimExprs{ $$ = create_node("ArrayCreationExpression", {$1, $2, $3});}
|                           New PrimitiveType Dims ArrayInitializer { $$ = create_node("ArrayCreationExpression", {$1, $2, $3, $4});}
|                           New ClassOrInterfaceType Dims ArrayInitializer { $$ = create_node("ArrayCreationExpression", {$1, $2, $3, $4});}
;
// ArrayCreationExpression -> new B C ArrayInitializer    $$.type = $2.type + ("*")*(stringtoint($3.type))
// ArrayCreationExpression -> new B C     $$.type = $2.type + ("*")*(stringtoint($3.type))
// ArrayCreationExpression -> new B C D    $$.type = $2.type + ("*")*(stringtoint($3.type) + stringtoint($3.type))


DimExprs:   DimExpr  {$$ = $1; }
|           DimExprs DimExpr { $$ = create_node("DimExprs", {$1, $2});}
;
// A -> B C    $$.type = $1.type + $2.type 

DimExpr:    Lsquare Expression Rsquare { $$ = create_node("DimExpr", {$1, $2, $3});}
;
// A -> Lsquare B Rsquare      $$.type = "*"

Expression:  AssignmentExpression {$$ = $1; }

AssignmentExpression:   
    ConditionalExpression {$$ = $1; }
|   Assignment {$$ = $1; }
;

Assignment:
    LeftHandSide AssignmentOperator Expression  {
                                                    create_edges($2, {$1, $3});
                                                    $$ = $2;
                                                }
    LeftHandSide Assign Expression              {
                                                    create_edges($2, {$1, $3});
                                                    $$ = $2;
                                                }
;

LeftHandSide:
    TypeName {$$ = $1; }
|   FieldAccess {$$ = $1; }
|   ArrayAccess {$$ = $1; }
;

ConditionalExpression:  ConditionalOrExpression {$$ = $1; }
|                   ConditionalOrExpression Qm Expression Colon ConditionalExpression { $$ = create_node("ConditionalExpression", {$1, $2, $3, $4, $5});} //Check Again
;

ConditionalOrExpression:    ConditionalAndExpression {$$ = $1; }
|                   ConditionalOrExpression Or ConditionalAndExpression {
                                                                            create_edges($2, {$1, $3});
                                                                            $$ = $2;
                                                                        } 
;

ConditionalAndExpression:   InclusiveOrExpression {$$ = $1; }
|                   ConditionalAndExpression And InclusiveOrExpression  {
                                                                            create_edges($2, {$1, $3});
                                                                            $$ = $2;
                                                                        } 
;

InclusiveOrExpression:  ExclusiveOrExpression {$$ = $1; }
|                   InclusiveOrExpression Bitwise_or ExclusiveOrExpression  {
                                                                                create_edges($2, {$1, $3});
                                                                                $$ = $2;
                                                                            } 
;

ExclusiveOrExpression:  AndExpression   {$$ = $1; }
|                   ExclusiveOrExpression Bitwise_xor AndExpression     {
                                                                            create_edges($2, {$1, $3});
                                                                            $$ = $2;
                                                                        }
;

AndExpression:  EqualityExpression  {$$ = $1; }
|                   AndExpression Bitwise_and EqualityExpression    {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
;

EqualityExpression: RelationalExpression {$$ = $1; }
|                   EqualityExpression Deq RelationalExpression     {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
|                   EqualityExpression Neq RelationalExpression     {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
;

RelationalExpression:   ShiftExpression {$$ = $1; }
|                   RelationalExpression Lt ShiftExpression         {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
|                   RelationalExpression Gt ShiftExpression         {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
|                   RelationalExpression Leq ShiftExpression        {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
|                   RelationalExpression Geq ShiftExpression        {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
|                   RelationalExpression Instanceof ReferenceType   {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
;

ShiftExpression:    AdditiveExpression {$$ = $1; }
|                   ShiftExpression Left_shift AdditiveExpression   {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
|                   ShiftExpression Right_shift AdditiveExpression  {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
|                   ShiftExpression Unsigned_right_shift AdditiveExpression     {
                                                                                    create_edges($2, {$1, $3});
                                                                                    $$ = $2;
                                                                                }
;

AdditiveExpression: MultiplicativeExpression {$$ = $1; }
|                   AdditiveExpression Plus MultiplicativeExpression {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                     } 
|                   AdditiveExpression Minus MultiplicativeExpression   {
                                                                            create_edges($2, {$1, $3});
                                                                            $$ = $2;
                                                                        }
;

MultiplicativeExpression:   UnaryExpression {$$ = $1; }
|                   MultiplicativeExpression Asterik UnaryExpression    {
                                                                            create_edges($2, {$1, $3});
                                                                            $$ = $2;
                                                                        }
|                   MultiplicativeExpression Div UnaryExpression    {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
|                   MultiplicativeExpression Modulo UnaryExpression     {
                                                                        create_edges($2, {$1, $3});
                                                                        $$ = $2;
                                                                    }
;

UnaryExpression:    PreIncrementExpression {$$ = $1; }
|                   PreDecrementExpression {$$ = $1; }
|                   Plus UnaryExpression    { $$ = create_node("UnaryExpression", {$1, $2});}
|                   Minus UnaryExpression   { $$ = create_node("UnaryExpression", {$1, $2});}
|                   UnaryExpressionNotPlusMinus {$$ = $1; }
;

PreIncrementExpression: Increment Primary   { $$ = create_node("PreIncrementExpression", {$1, $2});}
|                       Increment TypeName   { $$ = create_node("PreIncrementExpression", {$1, $2});}
;

PreDecrementExpression: Decrement Primary  { $$ = create_node("PreDecrementExpression", {$1, $2});}
|                       Decrement TypeName  { $$ = create_node("PreDecrementExpression", {$1, $2});}
;

UnaryExpressionNotPlusMinus:    PostfixExpression   {$$ = $1; }
|                               Bitwise_complement UnaryExpression  { $$ = create_node("UnaryExpressionNotPlusMinus", {$1, $2});}
|                               Not UnaryExpression { $$ = create_node("UnaryExpressionNotPlusMinus", {$1, $2});}
|                               CastExpression  {$$ = $1; }
;

PostfixExpression:  Primary {$$ = $1; }
|                   TypeName    {$$ = $1; }
|                   PostIncrementExpression {$$ = $1; }
|                   PostDecrementExpression {$$ = $1; }
;

PostIncrementExpression:    Primary Increment { $$ = create_node("PostIncrementExpression", {$1, $2});}
|                           TypeName Increment  { $$ = create_node("PostIncrementExpression", {$1, $2});}
;

PostDecrementExpression:    Primary Decrement { $$ = create_node("PostDecrementExpression", {$1, $2});}
|                           TypeName Decrement { $$ = create_node("PostDecrementExpression", {$1, $2});}
;

CastExpression:     Lparen PrimitiveType Rparen UnaryExpression { $$ = create_node("CastExpression", {$1, $2, $3, $4});}
|                   Lparen ReferenceType Rparen UnaryExpressionNotPlusMinus  { $$ = create_node("CastExpression", {$1, $2, $3, $4});}
;


Block:    Lcurly Rcurly { $$ = create_node("Block", {$1, $2});}
|         Lcurly BlockStatements Rcurly { $$ = create_node("Block", {$1, $2, $3});}
;

BlockStatements:    BlockStatements BlockStatement  { $$ = create_node("BlockStatements", {$1, $2});}
|                   BlockStatement  {$$ = $1; }
;

BlockStatement:
                    ClassOrInterfaceDeclaration {$$ = $1;}
|                   LocalVariableDeclarationStatement   {$$ = $1; }
|                   Statement   {$$ = $1; }
;

LocalVariableDeclarationStatement:    LocalVariableDeclaration  Semicolon { $$ = create_node("LocalVariableDeclarationStatement", {$1, $2});}
;

LocalVariableDeclaration:    UnannType VariableDeclaratorList   { $$ = create_node("LocalVariableDeclaration", {$1, $2});}
|                            Var       VariableDeclaratorList   { $$ = create_node("LocalVariableDeclaration", {$1, $2});}
|                            Final UnannType VariableDeclaratorList { $$ = create_node("LocalVariableDeclaration", {$1, $2, $3});}
|                            Final  Var     VariableDeclaratorList  { $$ = create_node("LocalVariableDeclaration", {$1, $2, $3});}
;


Statement:          StatementWithoutTrailingSubstatement    {$$ = $1; }
|                   LabeledStatement    {$$ = $1; }
|                   IfThenStatement   {$$ = $1; }
|                   IfThenElseStatement  {$$ = $1; }
|                   WhileStatement  {$$ = $1; }
|                   ForStatement    {$$ = $1; }
;

StatementNoShortIf:     StatementWithoutTrailingSubstatement    {$$ = $1; }
|                       LabeledStatementNoShortIf   {$$ = $1; }
|                       IfThenElseStatementNoShortIf    {$$ = $1; }
|                       WhileStatementNoShortIf {$$ = $1; }
|                       ForStatementNoShortIf   {$$ = $1; }
;

StatementWithoutTrailingSubstatement:   Block   {$$ = $1; }
|                                       EmptyStatement  {$$ = $1; }
|                                       ExpressionStatement {$$ = $1; }
|                                       AssertStatement {$$ = $1; }
|                                       BreakStatement  {$$ = $1; }
|                                       ContinueStatement   {$$ = $1; }
|                                       ReturnStatement {$$ = $1; }
|                                       ThrowStatement  {$$ = $1; }
|                                       SwitchStatement  { $$ = $1;}
|                                       DoStatement   { $$ = $1;}
|                                       SynchronizedStatement { $$ = $1;}
|                                       YieldStatement  { $$ = $1;}
|                                       TryStatement  { $$ = $1;}
;

SynchronizedStatement:
                        synchronized_ Lparen Expression Rparen Block { $$ = create_node("SynchronizedStatement", {$1, $2, $3, $4, $5});}
;

EmptyStatement:    Semicolon    {$$ = $1; }
;

LabeledStatement:    Identifier Colon Statement   { $$ = create_node("LabeledStatement", {$1, $2, $3});}
;

LabeledStatementNoShortIf:    Identifier Colon StatementNoShortIf   { $$ = create_node("LabeledStatementNoShortIf", {$1, $2, $3});}
;

ExpressionStatement:    StatementExpression Semicolon   { $$ = create_node("ExpressionStatement", {$1, $2});}

StatementExpression:    Assignment  {$$ = $1; }
|                       PreIncrementExpression  {$$ = $1; }
|                       PreDecrementExpression  {$$ = $1; }
|                       PostIncrementExpression {$$ = $1; }
|                       PostDecrementExpression {$$ = $1; }
|                       MethodInvocation        {$$ = $1; }
|                       ClassInstanceCreationExpression  {$$ = $1; }

IfThenStatement:    If Lparen Expression Rparen Statement   { $$ = create_node("IfThenStatement", {$1, $2, $3, $4, $5});}
;

IfThenElseStatement:    If Lparen Expression Rparen StatementNoShortIf Else Statement   { $$ = create_node("IfThenElseStatement", {$1, $2, $3, $4, $5, $6, $7});}
;

IfThenElseStatementNoShortIf:    If Lparen Expression Rparen StatementNoShortIf Else StatementNoShortIf  { $$ = create_node("IfThenElseStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7});}
;

AssertStatement:    Assert Expression Semicolon  { $$ = create_node("AssertStatement", {$1, $2, $3});}
|                   Assert Expression Colon Expression Semicolon    { $$ = create_node("AssertStatement", {$1, $2, $3, $4, $5});}
;

SwitchStatement:
                    switch_ Lparen Expression Rparen SwitchBlock    {
                                                                       $$ = create_node("SwitchStatement", {$1, $2, $3, $4, $5});
                                                                    }

SwitchBlock:
                    Lcurly SwitchRules Rcurly                       { $$ = create_node("SwitchBlock", {$1, $2, $3});}
|                   Lcurly SwitchBlockStatementGroups SwitchLabelColons Rcurly  { $$ = create_node("SwitchBlock", {$1, $2, $3, $4});}
|                   Lcurly SwitchBlockStatementGroups Rcurly                { $$ = create_node("SwitchBlock", {$1, $2, $3});}
|                   Lcurly SwitchLabelColons Rcurly                         { $$ = create_node("SwitchBlock", {$1, $2, $3});}
|                   Lcurly Rcurly                                           { $$ = create_node("SwitchBlock", {$1, $2});}
;

SwitchRules:
                    SwitchRules SwitchRule                                  { $$ = create_node("SwitchRules", {$1, $2});}
|                   SwitchRule                                              { $$ = $1;}
;

SwitchRule:
                    SwitchLabel arrow_ Expression Semicolon                 { $$ = create_node("SwitchRule", {$1, $2, $3, $4});}
|                   SwitchLabel arrow_ Block                                { $$ = create_node("SwitchRule", {$1, $2, $3});}
|                   SwitchLabel arrow_ ThrowStatement                       { $$ = create_node("SwitchRule", {$1, $2, $3});}
;

SwitchBlockStatementGroups:
                    SwitchBlockStatementGroups SwitchBlockStatementGroup    { $$ = create_node("AssertStatement", {$1, $2});}
|                   SwitchBlockStatementGroup                               { $$ = $1;}
;

SwitchBlockStatementGroup:
                    SwitchLabelColons BlockStatements                       { $$ = create_node("SwitchBlockStatementGroup", {$1, $2});}

SwitchLabelColons:
                    SwitchLabelColons SwitchLabel Colon                     { $$ = create_node("SwitchLabelColons", {$1, $2, $3});}
|                   SwitchLabel Colon                                       { $$ = create_node("SwitchLabelColons", {$1, $2});}
;

SwitchLabel:
                    case_ CaseConstants                                     { $$ = create_node("SwitchLabel", {$1, $2});}
|                   default_                                                { $$ = $1;}

CaseConstants:
                    CaseConstants Comma CaseConstant                        { $$ = create_node("CaseConstants", {$1, $2, $3});}
|                   CaseConstant                                            { $$ = $1;}
;

CaseConstant:
                    ConditionalExpression                                   { $$ = $1;}
;

WhileStatement:    While Lparen Expression Rparen Statement         {
                                                                        $$ = create_node("WhileStatement", {$1, $2, $3, $4, $5});
                                                                    }
;

WhileStatementNoShortIf:    While Lparen Expression Rparen StatementNoShortIf   {
                                                                                    $$ = create_node("WhileStatementNoShortIf", {$1, $2, $3, $4, $5});
                                                                                }
;

DoStatement:
    do_ Statement While Lparen Expression Rparen Semicolon                  { $$ = create_node("DoStatement", {$1, $2, $3, $4, $5, $6, $7});}
;

ForStatement:       BasicForStatement   {$$ = $1; }
|                   EnhancedForStatement    {$$ = $1; }
;

ForStatementNoShortIf:    BasicForStatementNoShortIf    {$$ = $1; }
|                   EnhancedForStatementNoShortIf   {$$ = $1; }
;

BasicForStatement:     For Lparen Semicolon Semicolon Rparen Statement  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6});}
|                      For Lparen ForInit Semicolon Semicolon Rparen Statement  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6, $7});}
|                      For Lparen Semicolon Expression Semicolon Rparen Statement  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6, $7});}
|                      For Lparen Semicolon Semicolon ForUpdate Rparen Statement  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6, $7});}
|                      For Lparen ForInit Semicolon Expression Semicolon Rparen Statement  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6, $7, $8});}
|                      For Lparen Semicolon Expression Semicolon ForUpdate Rparen Statement  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6, $7, $8});}
|                      For Lparen ForInit Semicolon Semicolon ForUpdate Rparen Statement  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6, $7, $8});}
|                      For Lparen ForInit Semicolon Expression Semicolon ForUpdate Rparen Statement  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6, $7, $8, $9});}
;

BasicForStatementNoShortIf:    For Lparen Semicolon Semicolon Rparen StatementNoShortIf  { $$ = create_node("BasicForStatementNoShortIf", {$1, $2, $3, $4, $5, $6});}
|                      For Lparen ForInit Semicolon Semicolon Rparen StatementNoShortIf  { $$ = create_node("BasicForStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7});}
|                      For Lparen Semicolon Expression Semicolon Rparen StatementNoShortIf  { $$ = create_node("BasicForStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7});}
|                      For Lparen Semicolon Semicolon ForUpdate Rparen StatementNoShortIf  { $$ = create_node("BasicForStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7});}
|                      For Lparen ForInit Semicolon Expression Semicolon Rparen StatementNoShortIf  { $$ = create_node("BasicForStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7, $8});}
|                      For Lparen Semicolon Expression Semicolon ForUpdate Rparen StatementNoShortIf  { $$ = create_node("BasicForStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7, $8});}
|                      For Lparen ForInit Semicolon Semicolon ForUpdate Rparen StatementNoShortIf  { $$ = create_node("BasicForStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7, $8});}
|                      For Lparen ForInit Semicolon Expression Semicolon ForUpdate Rparen StatementNoShortIf  { $$ = create_node("BasicForStatement", {$1, $2, $3, $4, $5, $6, $7, $8, $9});}
;

ForInit:    StatementExpressionList {$$ = $1; }
|           LocalVariableDeclaration    {$$ = $1; }
;

ForUpdate:    StatementExpressionList   {$$ = $1; }
;

StatementExpressionList:    StatementExpression {$$ = $1; }
|                           StatementExpression CommaStatementExpressions   { $$ = create_node("StatementExpressionList", {$1, $2});}
;

CommaStatementExpressions:   Comma StatementExpression CommaStatementExpressions    { $$ = create_node("CommaStatementExpressions", {$1, $2, $3});}
|                            Comma StatementExpression  { $$ = create_node("CommaStatementExpressions", {$1, $2});}
;

EnhancedForStatement:    For Lparen LocalVariableDeclaration Colon Expression Rparen Statement  { $$ = create_node("EnhancedForStatement", {$1, $2, $3, $4, $5, $6, $7});}
;

EnhancedForStatementNoShortIf:    For Lparen LocalVariableDeclaration Colon Expression Rparen StatementNoShortIf    { $$ = create_node("EnhancedForStatementNoShortIf", {$1, $2, $3, $4, $5, $6, $7});}
;

BreakStatement:    Break Identifier Semicolon   { $$ = create_node("BreakStatement", {$1, $2, $3});}
|                  Break Semicolon   { $$ = create_node("BreakStatement", {$1, $2});}
;

YieldStatement:     yield_ Expression Semicolon     { $$ = create_node("YieldStatement", {$1, $2, $3});}
;

ContinueStatement:    Continue Identifier Semicolon  { $$ = create_node("ContinueStatement", {$1, $2, $3});}
|                     Continue Semicolon  { $$ = create_node("ContinueStatement", {$1, $2});}
;

ReturnStatement:
    Return Expression Semicolon { $$ = create_node("Return", {$1, $2, $3});}
|   Return  Semicolon { $$ = create_node("Return", {$1, $2});}
;

ThrowStatement:    Throw Expression Semicolon   { $$ = create_node("ThrowStatement", {$1, $2, $3});}
;

TryStatement:
                    try_ Block Catches          { $$ = create_node("TryStatement", {$1, $2, $3});}
|                   try_ Block Catches Finally  { $$ = create_node("TryStatement", {$1, $2, $3, $4});}
|                   try_ Block Finally          { $$ = create_node("TryStatement", {$1, $2, $3});}
;

Catches:
                    Catches CatchClause         { $$ = create_node("Catches", {$1, $2});}
|                   CatchClause                 { $$ = $1;}
;

CatchClause:
                    catch_ Lparen CatchFormalParameter Rparen Block { $$ = create_node("CatchClause", {$1, $2, $3, $4, $5});}

CatchFormalParameter:
                    CatchType VariableDeclaratorId              { $$ = create_node("CatchFormalParameter", {$1, $2});}
|                   Final CatchType VariableDeclaratorId        { $$ = create_node("CatchFormalParameter", {$1, $2, $3});}

CatchType:
                    ClassOrInterfaceType { $$ = $1;}
|                   ClassOrInterfaceType Bitwise_or CatchType           {
                                                                            $$ = create_node("CatchType", {$1, $2, $3});
                                                                        }
;

Finally:
                    finally_ Block          { $$ = create_node("Finally", {$1, $2});}
;



// Non-Terminals for representing terminals

Int : INT { $$ = create_leaf($1, "Keyword"); }
;

Long : LONG { $$ = create_leaf($1, "Keyword"); }
;

Byte : BYTE { $$ = create_leaf($1, "Keyword"); }
;

Short : SHORT { $$ = create_leaf($1, "Keyword"); }
;

Char : CHAR { $$ = create_leaf($1, "Keyword"); }
;

Float : FLOAT { $$ = create_leaf($1, "Keyword"); }
;

Double : DOUBLE { $$ = create_leaf($1, "Keyword"); }
;

Boolean : BOOLEAN { $$ = create_leaf($1, "Keyword"); }
;

Var : VAR { $$ = create_leaf($1, "Keyword"); }
;

If : IF { $$ = create_leaf($1, "Keyword"); }
;

Else : ELSE { $$ = create_leaf($1, "Keyword"); }
;

While : WHILE { $$ = create_leaf($1, "Keyword"); }
;

For : FOR { $$ = create_leaf($1, "Keyword"); }
;


Break : BREAK { $$ = create_leaf($1, "Keyword"); }
;

Continue : CONTINUE { $$ = create_leaf($1, "Keyword"); }
;

Void : VOID { $$ = create_leaf($1, "Keyword"); }
;

New : NEW { $$ = create_leaf($1, "Keyword"); }
;

Return : RETURN { $$ = create_leaf($1, "Keyword"); }
;

Public : PUBLIC { $$ = $1; }
;

Private : PRIVATE { $$ = $1; }
;

Class : CLASS { $$ = create_leaf($1, "Keyword"); }
;

Static : STATIC { $$ = $1; }
;

Final : FINAL { $$ = $1; }
;

Assert : ASSERT { $$ = create_leaf($1, "Keyword"); }
;

This : THIS { $$ = create_leaf($1, "Keyword"); }
;

Instanceof : INSTANCEOF { $$ = create_leaf($1, "Keyword"); }
;

super_ : SUPER { $$ = $1; }
;

Throw : THROW { $$ = create_leaf($1, "Keyword"); }
;

Implements : IMPLEMENTS { $$ = create_leaf($1, "Keyword"); }
;

Interface : INTERFACE { $$ = create_leaf($1, "Keyword"); }
;

Extends : EXTENDS { $$ = create_leaf($1, "Keyword"); }
;

Package : PACKAGE { $$ = create_leaf($1, "Keyword"); }
;

Import : IMPORT { $$ = create_leaf($1, "Keyword"); }
;

do_: DO { $$ = create_leaf($1, "Keyword");}

switch_ : SWITCH { $$ =  create_leaf($1, "Keyword");}

yield_ : YIELD  { $$ =  create_leaf($1, "Keyword");}

try_ : TRY { $$ =  create_leaf($1, "Keyword");}

throws_ : THROWS { $$ =  create_leaf($1, "Keyword");}

catch_ : CATCH { $$ =  create_leaf($1, "Keyword");}

finally_ : FINALLY { $$ =  create_leaf($1, "Keyword");}

synchronized_ : SYNCHRONIZED { $$ = create_leaf($1, "Keyword"); }

case_ : CASE { $$ = create_leaf($1, "Keyword"); }

default_ : DEFAULT { $$ = $1; }

Plus : PLUS { $$ = create_leaf($1, "Operator"); }
;

Minus : MINUS { $$ = create_leaf($1, "Operator"); }
;

Div : DIV { $$ = create_leaf($1, "Operator"); }
;

Asterik : ASTERIK { $$ = create_leaf($1, "Operator"); }
;

Modulo : MODULO { $$ = create_leaf($1, "Operator"); }
;

Increment : INCREMENT { $$ = create_leaf($1, "Operator"); }
;

Decrement : DECREMENT { $$ = create_leaf($1, "Operator"); }
;

Geq : GEQ { $$ = create_leaf($1, "Operator"); }
;

Leq : LEQ { $$ = create_leaf($1, "Operator"); }
;

Gt : GT { $$ = create_leaf($1, "Operator"); }
;

Lt : LT { $$ = create_leaf($1, "Operator"); }
;

Neq : NEQ { $$ = create_leaf($1, "Operator"); }
;

Deq : DEQ { $$ = create_leaf($1, "Operator"); }
;

Bitwise_and : BITWISE_AND { $$ = create_leaf($1, "Operator"); }
;

Bitwise_or : BITWISE_OR { $$ = create_leaf($1, "Operator"); }
;

Bitwise_xor : BITWISE_XOR { $$ = create_leaf($1, "Operator"); }
;

Bitwise_complement : BITWISE_COMPLEMENT { $$ = create_leaf($1, "Operator"); }
;

Left_shift : LEFT_SHIFT { $$ = create_leaf($1, "Operator"); }
;

Right_shift : RIGHT_SHIFT { $$ = create_leaf($1, "Operator"); }
;

Unsigned_right_shift : UNSIGNED_RIGHT_SHIFT { $$ = create_leaf($1, "Operator"); }
;

And : AND { $$ = create_leaf($1, "Operator"); }
;

Or : OR { $$ = create_leaf($1, "Operator"); }
;

Not : NOT { $$ = create_leaf($1, "Operator"); }
;

AssignmentOperator:  ASSIGNMENT { $$ = create_leaf($1, "Operator"); }
;

Assign: ASSIGN { $$ = create_leaf($1, "Operator"); }

Colon : COLON { $$ = create_leaf($1, "Operator"); }
;

Qm : QM { $$ = create_leaf($1, "Operator"); }
;

Lparen : LPAREN { $$ = create_leaf($1, "Separator"); }
;

Rparen : RPAREN { $$ = create_leaf($1, "Separator"); }
;

Lcurly : LCURLY { $$ = create_leaf($1, "Separator"); }
;

Rcurly : RCURLY { $$ = create_leaf($1, "Separator"); }
;

Lsquare : LSQUARE { $$ = create_leaf($1, "Separator"); }
;

Rsquare : RSQUARE { $$ = create_leaf($1, "Separator"); }
;

Semicolon : SEMICOLON { $$ = create_leaf($1, "Separator"); }
;

Comma : COMMA { $$ = create_leaf($1, "Separator"); }
;

Dot : DOT { $$ = create_leaf($1, "Separator"); }
;

arrow_ : ARROW { $$ = create_leaf($1, "Separator"); }

Char_literal : CHAR_LITERAL { $$ = $1; }
;

Boolean_literal : BOOLEAN_LITERAL { $$ = $1; }
;

Null_literal : NULL_LITERAL { $$ = $1; }
;

Integer_literal : INTEGER_LITERAL { $$ = $1; }
;

Fp_literal : FP_LITERAL { $$ = $1; }
;

String : STRING { $$ = $1; }
;

Text_block : TEXT_BLOCK { $$ = $1; }
;

Identifier : IDENTIFIER { $$ = $1;}
;

endoffile : EOF_ { $$ = create_leaf("<EOF>", "EOF"); }

%%

void handle_signal(int s) {
    printf("Received signal %d\n", s);

    fflush(stdout);
    exit(1);
}



int main(int argc, char *argv[]) {

    argparse::ArgumentParser program("javap");

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
        .implicit_value(true);


    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }


    _args->input = (char*)(program.get<std::string>("--input").c_str());

  

    _args->output = (char*)(program.get<std::string>("--output").c_str());

    if (program["--verbose"] == true) {
        _args->verbose = true;
    }


    yydebug = 0;
    
    if (_args->verbose)
        yydebug = 1;

    
    yyin = fopen(_args->input, "r");
    
    dotfile.open(_args->output);


    dotfile << "digraph AST {\n";
    dotfile << "node [fontname = courier, shape = box, colorscheme = paired6];\n";
    dotfile << "edge [color=blue];\n";

    do {
        yyparse();
    } while(!feof(yyin));

    dotfile << "}";

    dotfile.close();
    return 0;
}

int yyerror(const char *s) {
    printf("syntax error: line %d: %s\n", yylineno, s);
    dotfile.close();
    exit(1);
}