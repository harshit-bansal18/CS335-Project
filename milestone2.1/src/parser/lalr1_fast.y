%{
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
    

%}

%define parse.error verbose

%union {
    int num;
    int8_t b_no;
    double float_num;
    char* str;
    struct stackentry* stack_entry;
    struct Type *type;
    struct Identifier *id;
    // Type *type_;
}

%token<str> INT LONG BYTE CHAR SHORT FLOAT DOUBLE BOOLEAN VAR

%token<str> IF ELSE FOR WHILE BREAK CONTINUE

%token<str> VOID NEW RETURN PUBLIC PRIVATE CLASS STATIC FINAL CATCH FINALLY SYNCHRONIZED
/* %token <str> YIELD */
%token<str> ASSERT PLUS MINUS DIV MODULO INCREMENT DECREMENT GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_COMPLEMENT LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT AND OR NOT ASSIGNMENT
%token<str> COLON QM LPAREN RPAREN LCURLY RCURLY LSQUARE RSQUARE SEMICOLON COMMA DOT
%token<str> CHAR_LITERAL BOOLEAN_LITERAL NULL_LITERAL INTEGER_LITERAL FP_LITERAL STRING TEXT_BLOCK

%token<str> IDENTIFIER
%token<str> THIS
%token<str> INSTANCEOF
%token<str> SUPER
%token<str> THROW
%token<str> THROWS
%token<str> EOF_
/* %token<str> IMPLEMENTS
%token<str> INTERFACE
%token<str> EXTENDS */
%token<str> PACKAGE
%token<str> IMPORT
%token<str> ASTERIK
%token<str> DO
%token<str> TRY
/* %token<str> CASE
%token<str> DEFAULT
%token<str> SWITCH
%token<str> ARROW */

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
%right ASSIGNMENT ASSIGN

%type<stack_entry> Program
%type<stack_entry> CompilationUnit
%type<stack_entry> ClassOrInterfaceDeclaration
%type<stack_entry> ClassOrInterfaceDeclarations
%type<stack_entry> PackageDeclaration
%type<stack_entry> ImportDeclaration
%type<stack_entry> Literal
%type<type> UnannType
%type<type> PrimitiveType
%type<type> NumericType
%type<type> IntegralType
%type<type> FloatingPointType
%type<type> ReferenceType
%type<type> ClassOrInterfaceType
%type<type> ArrayType
%type<stack_entry> Dims
%type<stack_entry> TypeName
%type<stack_entry> ClassDeclaration
%type<stack_entry> super_
%type<stack_entry> ClassBody
%type<stack_entry> ClassBodyDeclarations
%type<stack_entry> ClassBodyDeclaration
%type<stack_entry> ClassMemberDeclaration
%type<stack_entry> FieldDeclaration
%type<stack_entry> VariableDeclaratorList
%type<stack_entry> VariableDeclarator
%type<stack_entry> VariableDeclaratorId
%type<stack_entry> VariableInitializer
%type<stack_entry> MethodDeclaration
%type<stack_entry> MethodHeader
%type<stack_entry> Declarator
%type<stack_entry> FormalParameterList
%type<stack_entry> FormalParameter
%type<stack_entry> MethodBody
%type<stack_entry> StaticInitializer
%type<stack_entry> ConstructorDeclaration
%type<stack_entry> ConstructorBody
%type<stack_entry> ExplicitConstructorInvocation
%type<stack_entry> ArrayInitializer
%type<stack_entry> VariableInitializerList
/* %type<stack_entry> InterfaceDeclaration
%type<stack_entry> InterfaceExtends
%type<stack_entry> InterfaceBody
%type<stack_entry> InterfaceMembers
%type<stack_entry> InterfaceMemberDeclaration
%type<stack_entry> InterfaceMethodDeclaration */
%type<stack_entry> Primary
%type<stack_entry> PrimaryNoNewArray
%type<stack_entry> ClassInstanceCreationExpression
%type<stack_entry> FieldAccess
%type<stack_entry> ArrayAccess
%type<stack_entry> MethodInvocation
%type<stack_entry> ArgumentList
%type<stack_entry> ArrayCreationExpression
%type<stack_entry> DimExprs
%type<stack_entry> DimExpr
%type<stack_entry> Expression
%type<stack_entry> AssignmentExpression
%type<stack_entry> Assignment
%type<stack_entry> Assign
%type<stack_entry> LeftHandSide
%type<stack_entry> AssignmentOperator
%type<stack_entry> ConditionalExpression
%type<stack_entry> ConditionalOrExpression
%type<stack_entry> ConditionalAndExpression
%type<stack_entry> InclusiveOrExpression
%type<stack_entry> ExclusiveOrExpression
%type<stack_entry> AndExpression
%type<stack_entry> EqualityExpression
%type<stack_entry> RelationalExpression
%type<stack_entry> ShiftExpression
%type<stack_entry> AdditiveExpression
%type<stack_entry> MultiplicativeExpression
%type<stack_entry> UnaryExpression
%type<stack_entry> PreIncrementExpression
%type<stack_entry> PreDecrementExpression
%type<stack_entry> UnaryExpressionNotPlusMinus
%type<stack_entry> PostfixExpression
%type<stack_entry> PostIncrementExpression
%type<stack_entry> PostDecrementExpression
%type<stack_entry> CastExpression
%type<stack_entry> Block
%type<stack_entry> BlockStatements
%type<stack_entry> BlockStatement
%type<stack_entry> Statement
%type<stack_entry> StatementNoShortIf
%type<stack_entry> StatementWithoutTrailingSubstatement
%type<stack_entry> EmptyStatement
%type<stack_entry> LabeledStatement
%type<stack_entry> LabeledStatementNoShortIf
%type<stack_entry> ExpressionStatement
%type<stack_entry> StatementExpression
%type<stack_entry> IfThenElseStatement
%type<stack_entry> IfThenElseStatementNoShortIf
%type<stack_entry> AssertStatement
%type<stack_entry> WhileStatement
%type<stack_entry> WhileStatementNoShortIf
%type<stack_entry> ForStatement
%type<stack_entry> ForStatementNoShortIf
%type<stack_entry> BasicForStatement
%type<stack_entry> BasicForStatementNoShortIf
%type<stack_entry> ForInit
%type<stack_entry> ForUpdate
%type<stack_entry> StatementExpressionList
%type<stack_entry> CommaStatementExpressions
%type<stack_entry> EnhancedForStatement
%type<stack_entry> EnhancedForStatementNoShortIf
%type<stack_entry> BreakStatement
%type<stack_entry> ContinueStatement
%type<stack_entry> ReturnStatement
%type<stack_entry> IfThenStatement
%type<stack_entry> LocalVariableDeclaration
%type<stack_entry> LocalVariableDeclarationStatement
%type<type> Int
%type<type> Long
%type<type> Byte
%type<type> Char
%type<type> Short
%type<type> Float
%type<type> Double
%type<type> Boolean
%type<type> Var
%type<type> Void
%type<stack_entry> If
%type<stack_entry> Else
%type<stack_entry> For
%type<stack_entry> While
%type<stack_entry> Break
%type<stack_entry> Continue
%type<stack_entry> New
%type<stack_entry> Return
%type<stack_entry> Class
%type<stack_entry> Assert
%type<stack_entry> Plus
%type<stack_entry> Minus
%type<stack_entry> Div
%type<stack_entry> Modulo
%type<stack_entry> Increment
%type<stack_entry> Decrement
%type<stack_entry> Geq
%type<stack_entry> Leq
%type<stack_entry> Gt
%type<stack_entry> Lt
%type<stack_entry> Neq
%type<stack_entry> Deq
%type<stack_entry> Bitwise_and
%type<stack_entry> Bitwise_or
%type<stack_entry> Bitwise_xor
%type<stack_entry> Bitwise_complement
%type<stack_entry> Left_shift
%type<stack_entry> Right_shift
%type<stack_entry> Unsigned_right_shift
%type<stack_entry> And
%type<stack_entry> Or
%type<stack_entry> Not
%type<stack_entry> Colon
%type<stack_entry> Qm
%type<stack_entry> Lparen
%type<stack_entry> Rparen
%type<stack_entry> Lcurly
%type<stack_entry> Rcurly
%type<stack_entry> Lsquare
%type<stack_entry> Rsquare
%type<stack_entry> Semicolon
%type<stack_entry> Comma
%type<stack_entry> Dot
%type<stack_entry> This
%type<stack_entry> Instanceof
%type<stack_entry> Throw
/* %type<stack_entry> Implements
%type<stack_entry> Interface
%type<stack_entry> Extends */
%type<stack_entry> Package
%type<stack_entry> Import
%type<stack_entry> Asterik
%type<stack_entry> SynchronizedStatement
%type<stack_entry> DoStatement
%type<stack_entry> TryStatement
// %type<stack_entry> SwitchBlock
// %type<stack_entry> SwitchBlockStatementGroup
// %type<stack_entry> SwitchBlockStatementGroups
// %type<stack_entry> SwitchLabel
// %type<stack_entry> SwitchLabelColons
// %type<stack_entry> SwitchRule
// %type<stack_entry> SwitchRules
// %type<stack_entry> SwitchStatement
%type<stack_entry> CatchClause
%type<stack_entry> Catches
%type<stack_entry> CatchFormalParameter
%type<stack_entry> CatchType
%type<stack_entry> Finally
// %type<stack_entry> CaseConstant
// %type<stack_entry> CaseConstants
%type<stack_entry> do_
/* %type<stack_entry> switch_ */
/* %type<stack_entry> yield_ */
%type<stack_entry> try_
%type<stack_entry> catch_
%type<stack_entry> finally_
%type<stack_entry> synchronized_
%type<stack_entry> throws_
/* %type<stack_entry> case_ */
/* %type<stack_entry> default_ */
/* %type<stack_entry> arrow_ */
%type<stack_entry> endoffile
%type<stack_entry> ImportDeclarations
%type<stack_entry> Throws
%type<stack_entry> ExceptionType
%type<stack_entry> ExceptionTypeList
%type<stack_entry> CommaExceptionTypes
%type<stack_entry> Char_literal
%type<stack_entry> Boolean_literal
%type<stack_entry> Null_literal
%type<stack_entry> Integer_literal
%type<stack_entry> Fp_literal
%type<stack_entry> String
%type<stack_entry> Text_block
%type<id> Identifier
%type<stack_entry> Public
%type<stack_entry> Private
%type<stack_entry> Static
%type<stack_entry> Final
/* %type<stack_entry> Interfaces */
/* %type<stack_entry> InterfaceTypeList */
%type<stack_entry> ThrowStatement
/* %type<stack_entry> YieldStatement */
/* %type<stack_entry> Super  */

%type<b_no> Modifier
%type<b_no> Modifiers
/* %type<type_> UnannType
%type<type_> PrimitiveType
%type<type_> NumericType
%type<type_> IntegralType
%type<type_> FloatingPointType
%type<type_> ReferenceType
%type<type_> ClassOrInterfaceType
%type<type_> ArrayType
%type<type_> Dims */

%start Program
%%

Program:
    CompilationUnit endoffile { }; 

/*     Productions from Chapter 7 (Package and Modueles)           */
CompilationUnit:
    PackageDeclaration ImportDeclarations ClassOrInterfaceDeclarations { }
|   ImportDeclarations ClassOrInterfaceDeclarations { }
|   PackageDeclaration ClassOrInterfaceDeclarations { }
|   ClassOrInterfaceDeclarations { }
;

ClassOrInterfaceDeclarations:
    ClassOrInterfaceDeclaration { }
|   ClassOrInterfaceDeclarations ClassOrInterfaceDeclaration { }
;

ClassOrInterfaceDeclaration:
    ClassDeclaration { }
/* |   InterfaceDeclaration  { } */
;


PackageDeclaration:
    Package TypeName Semicolon { }
;
ImportDeclarations:
    ImportDeclarations ImportDeclaration { }
|   ImportDeclaration       { }
;

ImportDeclaration:
    Import TypeName Semicolon { }
|   Import TypeName Dot Asterik Semicolon { }
;

ScopeIncrement:
    %empty { increase_current_level(); }
;

/* ScopeDecrement:
    %empty { current_scope--; }
; */

/*
    Productions from Chapter 4 (Types, values, and variables)
*/

/*
    7, 7.5, 'c', "string", text block, true/false, null
*/
Literal:    Integer_literal { $$ = $1; }
|           Fp_literal  { $$ = $1; }
|           Char_literal  { $$ = $1; }
|           String  { $$ = $1; }
|           Text_block  { $$ = $1; }
|           Boolean_literal  { $$ = $1; }
|           Null_literal  { $$ = $1; }
;
/*
    Productions from Chapter 4 (Types, values, and variables)
*/

/*
    int, long, float, char, double, char, byte, short
*/
UnannTypeSubRoutine:
    UnannType  { global_type = $1->name; }
;
UnannType:
    PrimitiveType   { $$ = $1; }
|   ReferenceType   { $$ = $1; }
;

PrimitiveType:      
    NumericType { $$ = $1; }
|   Boolean  { $$ = $1; }
;

NumericType:        
    IntegralType { $$ = $1; }
|   FloatingPointType  { $$ = $1; }
;

IntegralType:       Byte  { $$ = $1; }
|                   Short  { $$ = $1; }
|                   Int  { $$ = $1; }
|                   Long  { $$ = $1; }
|                   Char { $$ = $1; }
;

FloatingPointType:    Float { $$ = $1; }
|                     Double { $$ = $1; }
;

/*
    *   Identifier(id1, id2)
    *   ArrayType ()
*/
ReferenceType:
    ClassOrInterfaceType { $$ = $1; }
|   ArrayType { $$ = $1; }
;

ClassOrInterfaceType:
    TypeName     {  $$ = ClassOrInterfaceType($1); /* TypeName will not have any problem as it will not find enteries in the symbol table for name like A.B*/ }
    /* Identifier      { 
                        $$ = ClassOrInterfaceType($1);
                    } */
;

ArrayType:
    PrimitiveType Dims {    
                            $$ = get_array_type($1, $2);
                            cout << 
                       }
|   TypeName Dims   { 
                        $$ = get_array_type(get_type(($1)->token), $2);
                    }
/* |   Identifier Dims {  
                        $$ = ArrayType($1, $2, 2);
                    } */
;

Dims:
    Lsquare Rsquare Dims    {  $$ = increase_dims($3);}
|   Lsquare Rsquare { 
                        $$ = make_stackentry("", yylineno);
                        $$->type = get_array_type(); 
                    }
;

/**********************/


/*
    Productions from Chapter 6 (Names)
*/

/* PackageName, TypeName, ExpressionName, MethodName, and AmbiguousName
    Replace them with TypenName
*/
TypeName:
    Identifier  { 
                    $$ = make_stackentry((($1)->name).c_str(), yylineno);
                    free($1);
                }
|   TypeName Dot Identifier {
                                $1->token = $1->token + "." + $3->name;
                                free($3);
                                $$ = $1;
                            }
;


/**************************************/
ModifiersUnannTypeSubRoutine:
    Modifiers UnannType     { global_modifier = $1; global_type = ($2)->name; }
;

Modifiers:
    Modifier {  
                $$ = set_modifier(0, $1);
            }
|   Modifiers Modifier  { 
                            $$ = set_modifier($1, $2);
                        }
;

// *************Need to confirm it *******
Modifier:
    Public      { 
                    $$ = __PUBLIC;
                } 
|   Private     { 
                    $$ = __PRIVATE;    
                }
|   Static      { 
                    $$ = __STATIC;    
                }
|   Final       { 
                    $$ = __FINAL;    
                }
;

/*
    Productions from Chapter 8 (Classes)
    
*/


ClassDeclaration:
    Modifiers Class Identifier { add_class($1, ($3)->name);} ClassBody { current_class = NULL; current_scope = scope_global; }
|   Class Identifier { add_class(0b0, ($2)->name);} ClassBody { current_class = NULL; current_scope = scope_global;}
;

/* Super:
    Extends ClassOrInterfaceType
; */

/* Interfaces:
    Implements InterfaceTypeList
;

InterfaceTypeList:
    ClassOrInterfaceType
|   InterfaceTypeList Comma ClassOrInterfaceType
; */

ClassBody:
    Lcurly ClassBodyDeclarations Rcurly
|   Lcurly Rcurly
;

ClassBodyDeclarations:
    ClassBodyDeclarations ClassBodyDeclaration { }
|   ClassBodyDeclaration { }
;

ClassBodyDeclaration:
    ClassMemberDeclaration { }
|   ConstructorDeclaration { }
|   StaticInitializer { }
|   Block               { }
;

// Inner Classes and Interfaces are not supported
ClassMemberDeclaration:
    FieldDeclaration { }
|   MethodDeclaration { }
|   ClassDeclaration  { }
/* |   InterfaceDeclaration { } */
;

FieldDeclaration:
    ModifiersUnannTypeSubRoutine VariableDeclaratorList Semicolon { global_modifier = 0b0; global_type =""; }
|   UnannTypeSubRoutine VariableDeclaratorList Semicolon { global_type =""; }
;

VariableDeclaratorList:
    VariableDeclaratorList Comma VariableDeclarator {}
|   VariableDeclarator { }
;

// used to declare instance variables of class, hence will be invoked in both passes.
VariableDeclarator:
    VariableDeclaratorId Assign VariableInitializer {    
                                                        if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) VariableDeclarator($1, $3, 1);
                                                    }
|   VariableDeclaratorId { 
                            if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) VariableDeclarator($1, NULL, 2);
                         }
;

VariableDeclaratorId:
    VariableDeclaratorId  Lsquare Rsquare {     
                                                if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                                                    $$ = increase_dims($1);
                                                }                                               
                                          }
|   Identifier  {    
                    if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                        $$ = make_stackentry((($1)->name).c_str(), global_type, yylineno);
                        free($1);
                    }
                }
;

VariableInitializer:
    Expression { $$ = $1; }
|   ArrayInitializer { $$ = $1; }
;

//  ----------------------Continue---------------------------


MethodDeclaration:
    MethodHeader{
                    add_function(($1)->token, ($1)->argument_type, ($1)->type, ($1)->modifier);   
                } MethodBody
;

MethodHeader:
    ModifiersUnannTypeSubRoutine Declarator {
                                            struct stackentry* entry = make_stackentry( (($2)->token).c_str(), global_type, yylineno);
                                            entry->modifier = global_modifier; 
                                            entry->argument_type = ($2)->argument_type;
                                            $$ = entry; 
                                            global_modifier = 0b0; global_type ="";
                                        }
|   UnannTypeSubRoutine Declarator      { 
                                            struct stackentry* entry = make_stackentry((($2)->token).c_str(), global_type, yylineno); 
                                            entry->argument_type = ($2)->argument_type;
                                            $$ = entry;
                                            global_type = "";
                                        }
|   Modifiers Void Declarator           { 
                                            struct stackentry* entry = make_stackentry((($3)->token).c_str(), __VOID, yylineno);
                                            entry->modifier = $1; 
                                            entry->argument_type = ($3)->argument_type;
                                            $$ = entry;
                                        }
|   Void Declarator                     { 
                                            struct stackentry* entry = make_stackentry((($2)->token).c_str(), __VOID, yylineno);
                                            entry->argument_type = ($2)->argument_type;
                                            $$ = entry;
                                        }
|   ModifiersUnannTypeSubRoutine Declarator Throws { 
                                            struct stackentry* entry = make_stackentry((($2)->token).c_str(), global_type, yylineno);
                                            entry->modifier = global_modifier; 
                                            entry->argument_type = ($2)->argument_type;
                                            $$ = entry;
                                            global_modifier = 0b0; global_type ="";
                                            // Throws ???????????????????????????????????????
                                          }
|   UnannTypeSubRoutine Declarator Throws           { 
                                            struct stackentry* entry = make_stackentry((($2)->token).c_str(), global_type, yylineno);  
                                            entry->argument_type = ($2)->argument_type;
                                            $$ = entry;
                                            global_type = "";
                                            // Throws ???????????????????????????????????????
                                          }
|   Modifiers Void Declarator Throws      { 
                                            struct stackentry* entry = make_stackentry((($3)->token).c_str(), __VOID, yylineno);
                                            entry->modifier = $1; 
                                            entry->argument_type = ($3)->argument_type;
                                            $$ = entry;
                                            // Throws ???????????????????????????????????????
                                          }
|   Void Declarator Throws                { 
                                            struct stackentry* entry = make_stackentry((($2)->token).c_str(), __VOID, yylineno);
                                            entry->argument_type = ($2)->argument_type;
                                            $$ = entry;
                                            // Throws ???????????????????????????????????????
                                          }
;

Throws:
    throws_ ExceptionTypeList             { }       

ExceptionTypeList:
    ExceptionType                         { }
|   ExceptionType CommaExceptionTypes     { }
    
CommaExceptionTypes:
    CommaExceptionTypes Comma ExceptionType  { }
|   Comma ExceptionType                      { } 

ExceptionType:
    ClassOrInterfaceType                    { }


/*
    Added in place  of MethodDeclarator and ConstructorDeclarator
*/
Declarator:
    Identifier Lparen Rparen                    { $$ = make_stackentry(($1->name).c_str(), yylineno); free($1); }
|   Identifier Lparen FormalParameterList Rparen { $3->token =($1)->name; $$ = $3; }
;

FormalParameterList:
    FormalParameterList Comma FormalParameter {
                                                $1->argument_type = ($1)->argument_type + "," + ($3)->argument_type;
                                                $$ = $1;
                                                free($3);
                                             }
|   FormalParameter {  $$ = $1; }
;

FormalParameter:
    UnannTypeSubRoutine VariableDeclaratorId {
                                                $$ = $2;
                                                global_type = "";
                                                if (pass_no == 2 && current_scope == scope_class)
                                                    add_variable($2->token, 0b0, $2->type, true);
                                            } 
;

MethodBody:
    Block { }
;

StaticInitializer:
    Static Block { }
;

ConstructorDeclaration:
    Modifiers Declarator { add_constructor(($2)->token, ($2)->argument_type, $1); } ConstructorBody {}
|   Declarator { add_constructor(($1)->token, ($1)->argument_type, (int8_t) 0); } ConstructorBody {}
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
    Lcurly ScopeIncrement BlockStatements Rcurly { if(pass_no == 2) { clear_current_scope(); } }
|   Lcurly ScopeIncrement ExplicitConstructorInvocation BlockStatements Rcurly { if(pass_no == 2) { clear_current_scope();} }
|   Lcurly ScopeIncrement ExplicitConstructorInvocation Rcurly { if(pass_no == 2) { clear_current_scope(); } }
|   Lcurly ScopeIncrement Rcurly { if(pass_no == 2) { clear_current_scope(); } }
;

ExplicitConstructorInvocation:
    This Lparen Rparen  {
                            // This is the default constructor of a class, hence always exists, no need to check anything
                        }
|   This Lparen ArgumentList Rparen {
                                        // Check if any constructor exists with the same argument type
                                        if(pass_no == 2){
                                            if(is_null(check_function_in_class( current_class->name, ($3)->argument_type, CONSTRUCTOR))){
                                                cerr << "Line No: " <<  yylineno  << "No such constructor present in class\n";
                                                exit(-1);
                                            }
                                        }
                                    }
|   super_ Lparen Rparen { }
|   super_ Lparen ArgumentList Rparen { }
;

// { {8,3}, 4, {4,5} }
ArrayInitializer: // int a[] = {2,3,4,5,6};
    Lcurly VariableInitializerList Rcurly { 
                                            if(pass_no == 2) {
                                                if ($2->type->is_pointer()) {
                                                    $$ = increase_dims($2);
                                                } else {
                                                    $$->type = get_array_type();
                                                    $$ = assign_arr_dim($2->type, $$);
                                                }
                                            }
                                          }         //type wont remain same
|   Lcurly Rcurly { /*empty array*/
                    if(pass_no == 2){ 
                        $$ = make_stackentry("", yylineno); 
                        $$->type = get_array_type();
                    }
                 }
|   Lcurly VariableInitializerList Comma Rcurly { 
                                                    if(pass_no == 2) {
                                                        $$ = $2; 
                                                        if ($2->type->is_pointer()) {
                                                            $$ = increase_dims($2);
                                                        } else {
                                                            $$->type = get_array_type();
                                                            $$ = assign_arr_dim($2->type, $$);
                                                        }
                                                    }
                                                }
|   Lcurly Comma Rcurly {   
                            if(pass_no == 2){
                                $$ = make_stackentry("", yylineno);
                                $$->type = get_array_type();
                            }
                        }
;

VariableInitializerList:
    VariableInitializerList Comma VariableInitializer {     
                                                            if(pass_no == 2){
                                                                if(check_return_type(($1)->type,($3)->type)){
                                                                    $$ = $1;
                                                                } else if(check_return_type(($3)->type,($1)->type)) {
                                                                    $$ = $3;
                                                                }
                                                            }
                                                      }
|   VariableInitializer { if(pass_no ==2 ) $$ = $1; }
;

/*     Productions from Chapter 9 - Interfaces      */

/* InterfaceDeclaration:
    Modifiers Interface Identifier InterfaceExtends InterfaceBody { }
|   Interface Identifier InterfaceExtends InterfaceBody { }
|   Interface Identifier InterfaceBody { }
|   Modifiers Interface Identifier  InterfaceBody { }
;

InterfaceExtends:
    Extends InterfaceTypeList { }

InterfaceBody:
    Lcurly InterfaceMembers Rcurly { }
|   Lcurly Rcurly { }
;

InterfaceMembers:
    InterfaceMemberDeclaration { }
|   InterfaceMembers InterfaceMemberDeclaration { }
;

InterfaceMemberDeclaration:
    FieldDeclaration { }
|   InterfaceMethodDeclaration { }
;

InterfaceMethodDeclaration: 
    MethodHeader Semicolon { }
; */

/*
    Productions from Chapter 15 (Expressions)
*/
// Java Expressions Grammer

Primary:    PrimaryNoNewArray { $$ = $1; }
|           ArrayCreationExpression { $$ = $1; }
;

// $$.type exists
PrimaryNoNewArray:  Literal { $$ = $1; }
|                   This { $$ = $1; }
|                   Lparen Expression Rparen { $$ = $2; }
|                   ClassInstanceCreationExpression { $$ = $1; }
|                   FieldAccess { $$ = $1; }
|                   ArrayAccess { $$ = $1; }
|                   MethodInvocation { $$ = $1; }
;

ClassInstanceCreationExpression: 
    New ClassOrInterfaceType Lparen Rparen  {
                                                if(pass_no == 2){
                                                    if(is_null(check_function_in_class(($2)->name, "", CONSTRUCTOR))) {
                                                        cerr << "Line No: " <<  yylineno << "Unknown constructor used"<<endl;
                                                        exit(1);
                                                    }
                                                    $$ = make_stackentry("", ($2)->name, yylineno);
                                                } 
                                            }
|   New ClassOrInterfaceType Lparen ArgumentList Rparen {   
                                                            if(pass_no == 2){
                                                                if(is_null(check_function_in_class(($2)->name, ($4)->argument_type, CONSTRUCTOR))){
                                                                    cerr << "Line No: " <<  yylineno <<"Unknown constructor used"<<endl;
                                                                    exit(1);
                                                                }

                                                                $$ = make_stackentry("", ($2)->name, yylineno);
                                                            }
                                                        }
;

FieldAccess:    Primary Dot Identifier  {   
                                            if(pass_no == 2 ){
                                                $$ = find_variable_in_class($3->name, true);
                                                free($3);
                                            }
                                        }
// |               super_ Dot Identifier { }
// |               TypeName Dot super_ Dot Identifier { }
/* ; */

ArrayAccess:    TypeName Lsquare Expression Rsquare {   
                                                        if(pass_no == 2 ){
                                                            if( !(($3)->type->is_integral)){
                                                                cerr << "Line No: " <<  yylineno <<"Array index must be integer"<<endl;
                                                                exit(-1);
                                                            }
                                                            $1 = find_variable_in_class(($1)->token, false);                

                                                            // string id = ($1)->type;
                                                            Type *t = $1->type;
                                                            if(!t->is_pointer()){
                                                                cerr << "Line No: " <<  yylineno <<"Type of variable must be array type"<<endl;
                                                                exit(1);
                                                            }
                                                            t->arr_dim--;
                                                            free($3);
                                                            $$ = $1; 
                                                        }
                                                    }
|               PrimaryNoNewArray Lsquare Expression Rsquare    {   
                                                        if(pass_no == 2 ){
                                                            if( !(($3)->type->is_integral)){
                                                                cerr << "Line No: " <<  yylineno <<"Array index must be integer"<<endl;
                                                                exit(-1);
                                                            }
                                                            $1 = find_variable_in_class(($1)->token, false);                

                                                            // string id = ($1)->type;
                                                            Type *t = $1->type;
                                                            if(!t->is_pointer()){
                                                                cerr << "Line No: " <<  yylineno <<"Type of variable must be array type"<<endl;
                                                                exit(1);
                                                            }
                                                            t->arr_dim--;
                                                            free($3);
                                                            $$ = $1; 
                                                        }
                                                    }
;
// A -> B Lsquare C Rsquare    $$.type = $1.type + "*"      $3.type = __INT

MethodInvocation:   TypeName Lparen Rparen {    
                                                if(pass_no == 2 ){
                                                    Type* return_type = check_function_in_class(($1)->token, "", FUNCTION);
                                                    if(return_type == NULL){
                                                        cerr << "Line No: " <<  yylineno  << "Undeclared function called\n";
                                                        exit(-1);
                                                    }
                                                    $$ = make_stackentry("", yylineno); 
                                                    $$->type = return_type;
                                                }
                                            }
|                   TypeName Lparen ArgumentList Rparen {   
                                                            if(pass_no == 2 ){
                                                                Type* return_type = check_function_in_class(($1)->token, ($3)->argument_type, FUNCTION);
                                                                if(return_type == NULL){
                                                                    cerr << "Line No: " <<  yylineno  << "Undeclared function called\n";
                                                                    exit(-1);
                                                                }
                                                                $$ = make_stackentry("", yylineno); 
                                                                $$->type = return_type;
                                                            }
                                                        }
|                   Primary Dot Identifier Lparen Rparen { }
|                   Primary Dot Identifier Lparen ArgumentList Rparen { }
|                   super_ Dot Identifier Lparen Rparen { }
|                   super_ Dot Identifier Lparen ArgumentList Rparen { }
;
// A -> B Lparen Rparen    $$.type = $1.type    $1.nature = "function"     $1.argtype = ""
// A -> B Lparen C Rparen      $$.type = $1.type    $1.nature = "function"     $1.argtype = $3.type   This argtype will be string concatenation of arguments type with a " , " in between
// A -> B Dot C Lparen D Rparen    $$.type = $3.type    $1.nature = "class"    $3.nature = "function"    $3.argtype = $5.type
// A -> B Dot C Lparen Rparen    $$.type = $3.type    $1.nature = "class"    $3.nature = "function"    $3.argtype = ""

ArgumentList:       Expression  { 
                                    if(pass_no == 2 ){
                                        struct stackentry* entry = make_stackentry("", yylineno); 
                                        entry->argument_type = ($1)->type->name; 
                                        $$ = entry; 
                                    }
                                }
|                   ArgumentList Comma Expression { 
                                                    if(pass_no == 2 ){      
                                                        struct stackentry* entry = make_stackentry("", yylineno); 
                                                        entry->argument_type = ($1)->argument_type + "," + ($2)->type->name; 
                                                        $$ = entry; 
                                                    }
                                                  }
;
// A -> B Comma C    $$.argtype = $1.argtype + " , " + $3.type

ArrayCreationExpression:    New PrimitiveType DimExprs Dims         {  if(pass_no == 2 ){  $$ = assign_arr_dim($2, $3, $4); } }
|                           New ClassOrInterfaceType DimExprs Dims  {  if(pass_no == 2 ){  $$ = assign_arr_dim($2, $3, $4); } }
|                           New PrimitiveType DimExprs              {  if(pass_no == 2 ){  $$ = assign_arr_dim($2, $3); } }
|                           New ClassOrInterfaceType DimExprs       {  if(pass_no == 2 ){  $$ = assign_arr_dim($2, $3); } }
|                           New PrimitiveType Dims ArrayInitializer {  if(pass_no == 2 ){  $$ = assign_arr_dim($2, $3); } }
|                           New ClassOrInterfaceType Dims ArrayInitializer {  if(pass_no == 2 ){  $$ = assign_arr_dim($2, $3); } }
;
// ArrayCreationExpression -> new B C ArrayInitializer    $$.type = $2.type + ("*")*(stringtoint($3.type))
// ArrayCreationExpression -> new B C     $$.type = $2.type + ("*")*(stringtoint($3.type))
// ArrayCreationExpression -> new B C D    $$.type = $2.type + ("*")*(stringtoint($3.type) + stringtoint($3.type))

DimExprs:   DimExpr  { if(pass_no == 2) $$ = $1; }
|           DimExprs DimExpr {  if(pass_no == 2 ){  $$ = assign_arr_dim($1, $2);} }
;
// A -> B C    $$.type = $1.type + $2.type 

DimExpr:    Lsquare Expression Rsquare {    
                                            if(pass_no == 2 ){  
                                                if(!check_if_numeric_type(($2)->type)) {
                                                    cerr << "Line No: " << yylineno << "Array dimension must be integer\n";
                                                    exit(-1);
                                                }

                                                if(!(($2)->type->is_integral)) {
                                                    cerr << "Line No: " << yylineno << "Array dimension must be integer\n";
                                                    exit(-1);
                                                }

                                                $$ = make_stackentry("", yylineno);
                                                $$->type = get_array_type();
                                            }
                                        }
                                        
;
// A -> Lsquare B Rsquare      $$.type = "*"

Expression:  AssignmentExpression { if(pass_no == 2 ) $$ = $1; }

AssignmentExpression:   
    ConditionalExpression { if(pass_no == 2 ) $$ = $1; }
|   Assignment { if(pass_no == 2 ) $$ = $1; }
;

Assignment:
    LeftHandSide AssignmentOperator Expression  {   
                                                    if(pass_no == 2 ){  
                                                        if(!check_return_type(($1)->type, ($3)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "incompatible types: "<< ($1)->type << "cannot be converted to " << ($3)->type <<"\n";
                                                            exit(-1);
                                                        }

                                                        $$ = $1;
                                                    }
                                                }
|   LeftHandSide Assign Expression              {   
                                                    if(pass_no == 2 ){  
                                                        if(!check_return_type(($1)->type, ($3)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "incompatible types: "<< ($1)->type << "cannot be converted to " << ($3)->type <<"\n";
                                                            exit(-1);
                                                        }

                                                        $$ = $1;
                                                    }
                                                }
;

LeftHandSide:
    TypeName {  
                if(pass_no == 2 ){  
                    // struct stackentry* entry = find_variable_in_class(symmbol_table_pass2[current_class], ($1)->token);
                    // entry->variable_init_status = __INITIALIZED;
                    // $$ = entry;
                    
                }
            }
|   FieldAccess { if(pass_no == 2 ) $$ = $1; }
|   ArrayAccess { if(pass_no == 2 ) $$ = $1; }
;

ConditionalExpression:  ConditionalOrExpression { $$ = $1; }
|                   ConditionalOrExpression Qm Expression Colon ConditionalExpression {     
                                                                                            if(pass_no == 2 ){
                                                                                                if(($1)->type != defined_types[__BOOLEAN]){
                                                                                                    cerr << "Line No: " <<  yylineno  << "incompatible types: "<< ($1)->type << "cannot be converted to boolean\n";
                                                                                                    exit(-1);
                                                                                                }

                                                                                                if((($3)->type == defined_types[__BOOLEAN]) && (($5)->type == defined_types[__BOOLEAN])) {
                                                                                                    $$ = $3;
                                                                                                } else if (((($3)->type == defined_types[__BOOLEAN]) && (($5)->type != defined_types[__BOOLEAN])) || ((($3)->type != defined_types[__BOOLEAN]) && (($5)->type == defined_types[__BOOLEAN]))) {
                                                                                                    cerr << "Line No: " <<  yylineno  << "Non intersectionable type: " << ($3)->type << " and " << ($5)->type << "\n";
                                                                                                    exit(-1);
                                                                                                } else {
                                                                                                    if(check_return_type(($3)->type, ($5)->type)) 
                                                                                                        $$ = $3;
                                                                                                    else
                                                                                                        $$ = $5;
                                                                                                }
                                                                                            }
                                                                                      } //Check Again
;

ConditionalOrExpression:    ConditionalAndExpression { if(pass_no == 2 ) $$ = $1; }
|                   ConditionalOrExpression Or ConditionalAndExpression {   
                                                                            if(pass_no == 2 ) {  
                                                                                $$ = ConditionalExpression($1, $3);
                                                                            }
                                                                        }
;

ConditionalAndExpression:   InclusiveOrExpression { if(pass_no == 2 ) $$ = $1; }
|                   ConditionalAndExpression And InclusiveOrExpression  {   
                                                                            if(pass_no == 2 ) {
                                                                                $$ = ConditionalExpression($1, $3);
                                                                            }
                                                                        }
;

InclusiveOrExpression:  ExclusiveOrExpression { if(pass_no == 2 ) $$ = $1; }
|                   InclusiveOrExpression Bitwise_or ExclusiveOrExpression  {   
                                                                                if(pass_no == 2 ){  
                                                                                    $$ = BitwiseExpression($1, $3);
                                                                                }
                                                                            }
;

ExclusiveOrExpression:  AndExpression   { if(pass_no == 2 ) $$ = $1; }
|                   ExclusiveOrExpression Bitwise_xor AndExpression     {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = BitwiseExpression($1, $3);
                                                                            }
                                                                        }
;

AndExpression:  EqualityExpression  { if(pass_no == 2 ) $$ = $1; }
|                   AndExpression Bitwise_and EqualityExpression    {       
                                                                            if(pass_no == 2 ){  
                                                                                $$ = BitwiseExpression($1, $3);
                                                                            }
                                                                        }
;

EqualityExpression: RelationalExpression { if(pass_no == 2 ) $$ = $1; }
|                   EqualityExpression Deq RelationalExpression     {   
                                                                        if(pass_no == 2 ){  
                                                                            EqualityExpression($1, $3);
                                                                        }
                                                                    }
|                   EqualityExpression Neq RelationalExpression     {   
                                                                        if(pass_no == 2 ){  
                                                                            EqualityExpression($1, $3);
                                                                        }
                                                                    }
;

RelationalExpression:   ShiftExpression { if(pass_no == 2 ) $$ = $1; }
|                   RelationalExpression Lt ShiftExpression         {       
                                                                            if(pass_no == 2 ){  
                                                                                $$ = RelationalExpression($1, $3);
                                                                            }
                                                                    }
|                   RelationalExpression Gt ShiftExpression         {       
                                                                            if(pass_no == 2 ){  
                                                                                $$ = RelationalExpression($1, $3);
                                                                            }
                                                                    }
|                   RelationalExpression Leq ShiftExpression        {        
                                                                            if(pass_no == 2 ){  
                                                                                $$ = RelationalExpression($1, $3);
                                                                            }
                                                                    }
|                   RelationalExpression Geq ShiftExpression        {       
                                                                            if(pass_no == 2 ){  
                                                                                $$ = RelationalExpression($1, $3);
                                                                            }
                                                                    }
|                   RelationalExpression Instanceof ReferenceType   { }
;

ShiftExpression:    AdditiveExpression { if(pass_no == 2 ) $$ = $1; }
|                   ShiftExpression Left_shift AdditiveExpression   {   
                                                                        if(pass_no == 2 ){  
                                                                            $$ = ShiftExpression($1, $3);
                                                                        }
                                                                    }
|                   ShiftExpression Right_shift AdditiveExpression  {   
                                                                        if(pass_no == 2 ){  
                                                                            $$ = ShiftExpression($1, $3);
                                                                        }
                                                                    }
|                   ShiftExpression Unsigned_right_shift AdditiveExpression     {   
                                                                                    if(pass_no == 2 ){  
                                                                                       $$ = ShiftExpression($1, $3);
                                                                                    }
                                                                                }
;

AdditiveExpression: MultiplicativeExpression { if(pass_no == 2 ) $$ = $1; }
|                   AdditiveExpression Plus MultiplicativeExpression    {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_additive_types($1, $3);
                                                                            }
                                                                        } 
|                   AdditiveExpression Minus MultiplicativeExpression   {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_additive_types($1, $3);
                                                                            }
                                                                        }
;

MultiplicativeExpression:   UnaryExpression                             { if(pass_no == 2 ) $$ = $1; }
|                   MultiplicativeExpression Asterik UnaryExpression    {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_multiplicative_types($1, $3);
                                                                            }
                                                                        }
|                   MultiplicativeExpression Div UnaryExpression        {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_multiplicative_types($1, $3);
                                                                            }
                                                                        }
|                   MultiplicativeExpression Modulo UnaryExpression     {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_multiplicative_types($1, $3);
                                                                            }
                                                                        }
;

UnaryExpression:    PreIncrementExpression      { if(pass_no == 2 ) $$ = $1; }
|                   PreDecrementExpression      { if(pass_no == 2 ) $$ = $1; }
|                   Plus UnaryExpression        {   
                                                    if(pass_no == 2 ){  
                                                        check_if_numeric_type(($2)->type);
                                                        $$ = $1;
                                                    }
                                                }
|                   Minus UnaryExpression       {   
                                                    if(pass_no == 2 ){   
                                                        check_if_numeric_type(($2)->type);
                                                        $$ = $1;
                                                    }
                                                }
|                   UnaryExpressionNotPlusMinus { if(pass_no == 2 ) $$ = $1; }
;

PreIncrementExpression: Increment Primary       {   
                                                    if(pass_no == 2 ){  
                                                        check_if_numeric_type(($2)->type);
                                                        $$ = $1;
                                                    }
                                                }
|                       Increment TypeName      {   
                                                    if(pass_no == 2 ){  
                                                        $$ = find_variable_in_class(($2)->token, false);
                                                        check_if_numeric_type(($$)->type);
                                                    }
                                                }
;

PreDecrementExpression: Decrement Primary   {       
                                                    if(pass_no == 2 ){   
                                                        check_if_numeric_type(($2)->type);
                                                        $$ = $1;
                                                    }
                                            }
|                       Decrement TypeName  {       
                                                    if(pass_no == 2 ){  
                                                        $$ = find_variable_in_class(($2)->token, false);
                                                        check_if_numeric_type(($$)->type);
                                                    }
                                            }
;

UnaryExpressionNotPlusMinus:    PostfixExpression                   { if(pass_no == 2 ) $$ = $1; }
|                               Bitwise_complement UnaryExpression  {   
                                                                        if(pass_no == 2 ){  
                                                                            check_boolean($2->type);
                                                                            $$ = $2;
                                                                        }
                                                                    }
|                               Not UnaryExpression                 {   
                                                                        if(pass_no == 2 ){  
                                                                            check_boolean($2->type);
                                                                            $$ = $2;
                                                                        }
                                                                    }
|                               CastExpression                      { if(pass_no == 2 ) $$ = $1; }
;

PostfixExpression:  Primary                 { if(pass_no == 2 ) $$ = $1; }
|                   TypeName                { if(pass_no == 2 ) $$ = find_variable_in_class(($1)->token, false); }
|                   PostIncrementExpression { if(pass_no == 2 ) $$ = $1; }
|                   PostDecrementExpression { if(pass_no == 2 ) $$ = $1; }
;

PostIncrementExpression:    Primary Increment   {   
                                                    if(pass_no == 2 ){  
                                                        if(!check_if_numeric_type(($1)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '++' \n first type: "<< ($1)->type << "\n";
                                                            exit(-1);
                                                        }
                                                        $$ = $1;
                                                    }
                                                }
|                           TypeName Increment  {   
                                                    if(pass_no == 2 ){  
                                                        $$ = find_variable_in_class(($1)->token, false);
                                                        if(!check_if_numeric_type(($$)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '++' \n first type: "<< ($1)->type << "\n";
                                                            exit(-1);
                                                        }
                                                    }
                                                }
;

PostDecrementExpression:    Primary Decrement   {   
                                                    if(pass_no == 2 ){
                                                        if(!check_if_numeric_type(($1)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '--' \n first type: "<< ($1)->type << "\n";
                                                            exit(-1);
                                                        }
                                                        
                                                        $$ = $1;
                                                    }
                                                }
|                           TypeName Decrement  {   
                                                    if(pass_no == 2 ){
                                                        $$ = find_variable_in_class(($1)->token, false);
                                                        if(!check_if_numeric_type(($$)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '--' \n first type: "<< ($1)->type << "\n";
                                                            exit(-1);
                                                        }
                                                    }
                                                }
;

CastExpression:     Lparen PrimitiveType Rparen UnaryExpression                 {   
                                                                                    if(pass_no == 2 ){
                                                                                        check_cast_types($2, $4->type);
                                                                                        $$ = make_stackentry("", $2->name, yylineno);
                                                                                    }
                                                                                }
|                   Lparen ReferenceType Rparen UnaryExpressionNotPlusMinus     {   
                                                                                    if(pass_no == 2 ){
                                                                                        check_cast_types($2, $4->type);
                                                                                        $$ = make_stackentry("", $2->name, yylineno);
                                                                                    }
                                                                                }
;


Block:    Lcurly ScopeIncrement Rcurly { if(pass_no == 2 ){ clear_current_scope(); } }
|         Lcurly ScopeIncrement BlockStatements Rcurly { if(pass_no == 2 ){ clear_current_scope(); } }
;

BlockStatements:    BlockStatements BlockStatement  { }
|                   BlockStatement                  { }
;

BlockStatement:
                    ClassOrInterfaceDeclaration { }
|                   LocalVariableDeclarationStatement   { }
|                   Statement   { }
;

LocalVariableDeclarationStatement:    LocalVariableDeclaration  Semicolon { if(pass_no == 2 ){ global_type = ""; global_modifier= 0b0;} }
;

LocalVariableDeclaration:    UnannTypeSubRoutine VariableDeclaratorList   { global_type = ""; }
|                            Var      { if(pass_no == 2 ) global_type = __VAR; }  VariableDeclaratorList   { }
|                            Final { if(pass_no == 2 ) global_modifier = __FINAL; } UnannTypeSubRoutine VariableDeclaratorList { global_type = ""; }
|                            Final { if(pass_no == 2 ) global_modifier = __FINAL; } Var    { if(pass_no == 2 ) global_type = __VAR; }  VariableDeclaratorList  { }
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
// |                                       SwitchStatement  
|                                       DoStatement   
|                                       SynchronizedStatement 
// |                                       YieldStatement  
|                                       TryStatement  
;

SynchronizedStatement:
                        synchronized_ Lparen Expression Rparen Block { }
;

EmptyStatement:    Semicolon    { }
;

LabeledStatement:    Identifier Colon Statement   { }
;

LabeledStatementNoShortIf:    Identifier Colon StatementNoShortIf   { }
;

ExpressionStatement:    StatementExpression Semicolon   { $$ = $1; }
;

StatementExpression:    Assignment  { if(pass_no == 2 ) $$ = $1; }
|                       PreIncrementExpression  { if(pass_no == 2 ) $$ = $1; }
|                       PreDecrementExpression  { if(pass_no == 2 ) $$ = $1; }
|                       PostIncrementExpression { if(pass_no == 2 ) $$ = $1; }
|                       PostDecrementExpression { if(pass_no == 2 ) $$ = $1; }
|                       MethodInvocation        { if(pass_no == 2 ) $$ = $1; }
|                       ClassInstanceCreationExpression  { if(pass_no == 2 ) $$ = $1; }
;

IfThenStatementSubRoutine:
    If Lparen Expression  { IfCondition($3); }
;

IfThenStatement:    IfThenStatementSubRoutine Rparen ScopeIncrement Statement   { clear_current_scope(); }
;

IfThenElseStatement:    IfThenStatementSubRoutine Rparen ScopeIncrement StatementNoShortIf Else Statement   { clear_current_scope(); }
;

IfThenElseStatementNoShortIf:    IfThenStatementSubRoutine Rparen ScopeIncrement StatementNoShortIf Else StatementNoShortIf  { clear_current_scope(); }
;

AssertStatement:    Assert Expression Semicolon { AssertCondition($2); }
|                   Assert Expression Colon Expression Semicolon    { AssertCondition($2); }
;

/*

SwitchStatement:
                    switch_ Lparen Expression Rparen SwitchBlock    {   
                                                                        if(pass_no == 2) {
                                                                            if(($2)->type!=__INT && ($2)->type!=__SHORT && ($2)->type!=__CHAR){
                                                                                cerr << "Line No: " <<  yylineno <<"incompatible if argument types: "+ ($2)->type +" cannot be converted to boolean";
                                                                                exit(1);
                                                                            }
                                                                        }
                                                                    }

SwitchBlock:
                    Lcurly ScopeIncrement SwitchRules Rcurly                                    { clear_current_scope(); }
|                   Lcurly ScopeIncrement SwitchBlockStatementGroups SwitchLabelColons Rcurly   { clear_current_scope(); }
|                   Lcurly ScopeIncrement SwitchBlockStatementGroups Rcurly                     { clear_current_scope(); }
|                   Lcurly ScopeIncrement SwitchLabelColons Rcurly                              { clear_current_scope(); }
|                   Lcurly ScopeIncrement Rcurly                                                { clear_current_scope(); }
;

SwitchRules:
                    SwitchRules SwitchRule
|                   SwitchRule            
;

SwitchRule:                                         /////////////God knows what the hell is this////////////
                    SwitchLabel arrow_ Expression Semicolon                 { }
|                   SwitchLabel arrow_ Block                                { }
|                   SwitchLabel arrow_ ThrowStatement                       { }
;

SwitchBlockStatementGroups:
                    SwitchBlockStatementGroups SwitchBlockStatementGroup
|                   SwitchBlockStatementGroup                           
;

SwitchBlockStatementGroup:
                    SwitchLabelColons BlockStatements                       { }

SwitchLabelColons:
                    SwitchLabelColons SwitchLabel Colon                     { }
|                   SwitchLabel Colon                                       { }
;

SwitchLabel:
                    case_ CaseConstants                                     { }
|                   default_                                                { }

CaseConstants:
                    CaseConstants Comma CaseConstant                        { }
|                   CaseConstant                                            { }
;

CaseConstant:
                    ConditionalExpression                                   { }
;
*/

WhileStatementSubRoutine:
    While Lparen Expression { WhileCondition($3); }
;

WhileStatement:    WhileStatementSubRoutine Rparen Statement { clear_current_scope(); }
;

WhileStatementNoShortIf:    WhileStatementSubRoutine Rparen StatementNoShortIf { clear_current_scope(); }
;

DoStatement:
    do_ Statement While Lparen Expression {     
                                                if(pass_no == 2){ check_boolean($3->type); }
                                            } Rparen Semicolon  { clear_current_scope(); }
;

ForStatement:       BasicForStatement   
|                   EnhancedForStatement 
;

ForStatementNoShortIf:    BasicForStatementNoShortIf  
|                   EnhancedForStatementNoShortIf 
;

For1SubRoutine:
    For Lparen Semicolon Expression          { ForCondition($4); }
;

For2SubRoutine:
    For Lparen ForInit Semicolon Expression    { ForCondition($5);}
;

BasicForStatement:     For Lparen Semicolon Semicolon Rparen Statement                  { clear_current_scope(); }
|                      For Lparen ForInit Semicolon Semicolon Rparen Statement          { clear_current_scope(); }
|                      For1SubRoutine Semicolon Rparen Statement                    { clear_current_scope(); }
|                      For Lparen Semicolon Semicolon ForUpdate Rparen Statement    { clear_current_scope(); }
|                      For2SubRoutine Semicolon Rparen Statement                    { clear_current_scope(); }
|                      For1SubRoutine Semicolon ForUpdate Rparen Statement          { clear_current_scope(); }
|                      For Lparen ForInit Semicolon Semicolon ForUpdate Rparen Statement  { clear_current_scope(); }
|                      For2SubRoutine Semicolon ForUpdate Rparen Statement  { clear_current_scope(); }
;

BasicForStatementNoShortIf:    For Lparen Semicolon Semicolon Rparen StatementNoShortIf  { clear_current_scope(); }
|                      For Lparen ForInit Semicolon Semicolon Rparen StatementNoShortIf  { clear_current_scope(); }
|                      For1SubRoutine Semicolon Rparen StatementNoShortIf  { clear_current_scope(); }
|                      For Lparen Semicolon Semicolon ForUpdate Rparen StatementNoShortIf  { clear_current_scope(); }
|                      For2SubRoutine Semicolon Rparen StatementNoShortIf  { clear_current_scope(); }
|                      For1SubRoutine Semicolon ForUpdate Rparen StatementNoShortIf   { clear_current_scope(); }
|                      For Lparen ForInit Semicolon Semicolon ForUpdate Rparen StatementNoShortIf   { clear_current_scope(); }
|                      For2SubRoutine Semicolon ForUpdate Rparen StatementNoShortIf   { clear_current_scope(); }
;

ForInit:    StatementExpressionList
|           LocalVariableDeclaration   
;

ForUpdate:    StatementExpressionList  
;

StatementExpressionList:    StatementExpression
|                           StatementExpression CommaStatementExpressions  
;

CommaStatementExpressions:   Comma StatementExpression CommaStatementExpressions   
|                            Comma StatementExpression 
;

EnhancedForStatementSubRoutine:
    For Lparen LocalVariableDeclaration Colon Expression { EnhancedForCondition($5); }
;

EnhancedForStatement:    EnhancedForStatementSubRoutine Rparen Statement  { }
;

EnhancedForStatementNoShortIf:    EnhancedForStatementSubRoutine Rparen StatementNoShortIf    { }
;

BreakStatement:    Break Semicolon 
                //    Break Identifier Semicolon   { }
                 
;

/* YieldStatement:     yield_ Expression Semicolon     { }
; */

ContinueStatement:   Continue Semicolon
                    //   Continue Identifier Semicolon  { }                   
;

ReturnStatement:
    Return Expression Semicolon { }
|   Return  Semicolon { }
;

ThrowStatement:    Throw Expression Semicolon   { }
;

TryStatement:
                    try_ Block Catches          { }
|                   try_ Block Catches Finally  { }
|                   try_ Block Finally          { }
;

Catches:
                    Catches CatchClause         { }
|                   CatchClause                 { }
;

CatchClause:
                    catch_ Lparen CatchFormalParameter Rparen Block { }

CatchFormalParameter:
                    CatchType VariableDeclaratorId              { }
|                   Final CatchType VariableDeclaratorId        { }

CatchType:
                    ClassOrInterfaceType { }
|                   ClassOrInterfaceType Bitwise_or CatchType           { }
;

Finally:
                    finally_ Block          { }
;

// Non-Terminals for representing terminals

Int : INT   { $$ = get_type(__INT); }
;

Long : LONG { $$ = get_type(__LONG); }
;

Byte : BYTE { $$ = get_type(__BYTE); }
;

Short : SHORT { $$ = get_type(__SHORT); }
;

Char : CHAR  { $$ = get_type(__CHAR); }
;

Float : FLOAT           { $$ = get_type(__FLOAT); }
;

Double : DOUBLE         { $$ = get_type(__DOUBLE); }
;

Boolean : BOOLEAN       { $$ = get_type(__BOOLEAN); }
;

Var : VAR               { $$ = get_type(__VAR); }
;

If : IF { }
;

Else : ELSE { }
;

While : WHILE   { increase_current_level(); }
;

For : FOR       { increase_current_level(); }
;

Break : BREAK { }
;

Continue : CONTINUE { }
;

Void : VOID { $$ = get_type(__VOID); }
;

New : NEW { }
;

Return : RETURN { }
;

Public : PUBLIC  {}// done above setting value
;

Private : PRIVATE {}
;

Class : CLASS { }
;

Static : STATIC {}
;

Final : FINAL {}
;

Assert : ASSERT { }
;

This : THIS { }
;

Instanceof : INSTANCEOF { }
;

super_ : SUPER { }
;

Throw : THROW { }
;

/* Implements : IMPLEMENTS { }
;

Interface : INTERFACE { }
;

Extends : EXTENDS { }
; */

Package : PACKAGE { }
;

Import : IMPORT { }
;

do_: DO { increase_current_level(); }

/* switch_ : SWITCH { } */

/* yield_ : YIELD  { } */

try_ : TRY { }

throws_ : THROWS { }

catch_ : CATCH { }

finally_ : FINALLY { }

synchronized_ : SYNCHRONIZED { }

/* case_ : CASE { } */

/* default_ : DEFAULT { } */

Plus : PLUS { }
;

Minus : MINUS { }
;

Div : DIV { }
;

Asterik : ASTERIK { }
;

Modulo : MODULO { }
;

Increment : INCREMENT { }
;

Decrement : DECREMENT { }
;

Geq : GEQ { }
;

Leq : LEQ { }
;

Gt : GT { }
;

Lt : LT { }
;

Neq : NEQ { }
;

Deq : DEQ { }
;

Bitwise_and : BITWISE_AND { }
;

Bitwise_or : BITWISE_OR { }
;

Bitwise_xor : BITWISE_XOR { }
;

Bitwise_complement : BITWISE_COMPLEMENT { }
;

Left_shift : LEFT_SHIFT { }
;

Right_shift : RIGHT_SHIFT { }
;

Unsigned_right_shift : UNSIGNED_RIGHT_SHIFT { }
;

And : AND { }
;

Or : OR { }
;

Not : NOT { }
;

AssignmentOperator:  ASSIGNMENT { }
;

Assign: ASSIGN { }

Colon : COLON { }
;

Qm : QM { }
;

Lparen : LPAREN { }
;

Rparen : RPAREN { }
;

Lcurly : LCURLY { }
;

Rcurly : RCURLY { }
;

Lsquare : LSQUARE { }
;

Rsquare : RSQUARE { }
;

Semicolon : SEMICOLON { }
;

Comma : COMMA { }
;

Dot : DOT { }
;

/* arrow_ : ARROW { } */

Char_literal : CHAR_LITERAL     { $$ = make_stackentry($1, __CHAR, yylineno); }
;

Boolean_literal : BOOLEAN_LITERAL { $$ = make_stackentry($1, __BOOLEAN, yylineno); }
;

Null_literal : NULL_LITERAL     { $$ = make_stackentry($1, yylineno); }
;

Integer_literal : INTEGER_LITERAL { $$ = make_stackentry($1, __INT, yylineno); }
;

Fp_literal : FP_LITERAL     { $$ = make_stackentry($1, __FLOAT, yylineno); }
;

String : STRING             { $$ = make_stackentry($1, yylineno); }
;

Text_block : TEXT_BLOCK         { $$ = make_stackentry($1, yylineno); }
;

Identifier : IDENTIFIER         { $$ = make_identifier($1);}
;

endoffile : EOF_ { }

%%

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