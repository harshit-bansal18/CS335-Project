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


    extern int new_offset;
    stack<int> old_offsets;

    int8_t global_modifier;
    Type* global_type;
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
    char* threeac_label;
}

%token<str> INT LONG BYTE CHAR SHORT FLOAT DOUBLE BOOLEAN VAR

%token<str> IF ELSE FOR WHILE BREAK CONTINUE

%token<str> VOID NEW RETURN PUBLIC PRIVATE CLASS STATIC FINAL 
%token<str> ASSERT PLUS MINUS DIV MODULO INCREMENT DECREMENT GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_COMPLEMENT LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT AND OR NOT ASSIGNMENT
%token<str> COLON QM LPAREN RPAREN LCURLY RCURLY LSQUARE RSQUARE SEMICOLON COMMA DOT
%token<str> CHAR_LITERAL BOOLEAN_LITERAL NULL_LITERAL INTEGER_LITERAL FP_LITERAL STRING TEXT_BLOCK

%token<str> IDENTIFIER
%token<str> THIS
%token<str> THROW
%token<str> EOF_
%token<str> ASTERIK
%token<str> DO

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
%type<threeac_label> AssignmentOperator
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
%type ForInit
%type ForUpdate
%type<stack_entry> StatementExpressionList
%type<stack_entry> CommaStatementExpressions
%type<stack_entry> EnhancedForStatement
%type<stack_entry> EnhancedForStatementNoShortIf
%type BreakStatement
%type ContinueStatement
%type ReturnStatement
%type IfThenStatement
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
%type<stack_entry> This
%type Break
%type Continue
%type New
%type Return
%type Class
%type Assert
%type Plus
%type Minus
%type Div
%type Modulo
%type Increment
%type Decrement
%type Geq
%type Leq
%type Gt
%type Lt
%type Neq
%type Deq
%type Bitwise_and
%type Bitwise_or
%type Bitwise_xor
%type Bitwise_complement
%type Left_shift
%type Right_shift
%type Unsigned_right_shift
%type Asterik
%type And
%type Or
%type Not
%type Colon
%type Qm
%type Lparen
%type Rparen
%type Lcurly
%type Rcurly
%type Lsquare
%type Rsquare
%type Semicolon
%type Comma
%type Dot
%type<stack_entry> Throw
/* %type Package
%type Import */
/* %type SynchronizedStatement */
%type DoStatement
/* %type TryStatement
%type CatchClause
%type Catches
%type CatchFormalParameter
%type CatchType
%type Finally */
%type<num> do_
%type<stack_entry> endoffile
/* %type<stack_entry> ImportDeclarations */
%type<stack_entry> Char_literal
%type<stack_entry> Boolean_literal
%type<stack_entry> Null_literal
%type<stack_entry> Integer_literal
%type<stack_entry> Fp_literal
%type<stack_entry> String
%type<stack_entry> Text_block
%type<id> DeclaratorSubRoutine
%type<id> Identifier
%type<stack_entry> Public
%type<stack_entry> Private
%type<stack_entry> Static
%type<stack_entry> Final
%type<stack_entry> ThrowStatement
%type<stack_entry> UnannTypeSubRoutine
%type<stack_entry> ModifiersUnannTypeSubRoutine
// %type<num> If
%type Else
%type<num> For
%type<num> While
%type<num>IfThenStatementSubRoutine
%type<num>WhileStatementSubRoutine
%type<num>IfThenThreeACSubRoutine
%type<num> For1SubRoutine
%type<num> For2SubRoutine
%type<num> For3SubRoutine
%type<num> For4SubRoutine
%type<num> For5SubRoutine
%type<num> For6SubRoutine
%type<num> For7SubRoutine
%type<num> For8SubRoutine
%type<num> For9SubRoutine
%type<num> For10SubRoutine
%type<num> For11SubRoutine
%type<num> For12SubRoutine
%type<num> For13SubRoutine
%type<num> For14SubRoutine

%type<num> IfCountIncrement

%type<b_no> Modifier
%type<b_no> Modifiers

%start Program
%%

Program:
    CompilationUnit endoffile { }; 

/*     Productions from Chapter 7 (Package and Modueles)           */
CompilationUnit:
    /* PackageDeclaration ImportDeclarations ClassOrInterfaceDeclarations { }
|   ImportDeclarations ClassOrInterfaceDeclarations { }
|   PackageDeclaration ClassOrInterfaceDeclarations { } */
    ClassOrInterfaceDeclarations { }
;

ClassOrInterfaceDeclarations:
    ClassOrInterfaceDeclaration { }
|   ClassOrInterfaceDeclarations ClassOrInterfaceDeclaration { }
;

ClassOrInterfaceDeclaration:
    ClassDeclaration { }
/* |   InterfaceDeclaration  { } */
;


/* PackageDeclaration:
    Package TypeName Semicolon { }
;
ImportDeclarations:
    ImportDeclarations ImportDeclaration { }
|   ImportDeclaration       { }
;

ImportDeclaration:
    Import TypeName Semicolon { }
|   Import TypeName Dot Asterik Semicolon { }
; */

ScopeIncrement:
    %empty { increase_current_level(); }
;

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
    UnannType   { 
                    global_type = $1;

                    $$ = make_stackentry("", $1, yylineno);
                }
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
;

ArrayType:
    PrimitiveType Dims {    
                            $$ = get_array_type($1, $2);
                        }
|   TypeName Dims   { 
                        $$ = get_array_type(get_type(($1)->token), $2);
                    }
;

Dims:
    Lsquare Rsquare Dims    {  $$ = increase_dims($3); $$->threeac = "[]"+ $3->threeac ; }
|   Lsquare Rsquare { 
                        $$ = make_stackentry("", yylineno);
                        $$->type = get_array_type(); 
                        $$->threeac = "[]";
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
                    $$->threeac = $$->token;
                }
|   TypeName Dot Identifier {
                                $1->token = $1->token + "." + $3->name;
                                free($3);
                                $$ = $1;
                                $$->threeac = $$->token;
                            }
;


/**************************************/
ModifiersUnannTypeSubRoutine:
    Modifiers UnannType     { 
                                global_modifier = $1; 
                                global_type = $2;
                                $$ = make_stackentry("", $2, yylineno);
                                $$->modifier = $1;
                            }
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
    Modifiers Class Identifier { add_class($1, ($3)->name); free($3);} ClassBody { current_class = NULL; current_scope = scope_global; new_offset = 0; }
|   Class Identifier { add_class(0b0, ($2)->name); free($2);} ClassBody { current_class = NULL; current_scope = scope_global; new_offset = 0;}
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
    Lcurly ClassBodyDeclarations Rcurly {}
|   Lcurly Rcurly {}
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
|   MethodDeclaration   { 
                            // if(pass_no==2){
                            //     loopnum=0;
                            //     ifnum=0;
                            //     tcount=0;
                            //     paramcount=0;
                            //     threeac_file_name = DUMP_DIR + current_class->name + "." + ($1)->token + three_ac_type_dump(($1)->argument_type); + ".3ac";
                            //     dump_3ac(threeac_file_name);
                            // }
                        }
|   ClassDeclaration  { }
/* |   InterfaceDeclaration { } */
;

FieldDeclaration:
    ModifiersUnannTypeSubRoutine VariableDeclaratorList Semicolon { global_modifier = 0b0; global_type = NULL; free($1);}
|   UnannTypeSubRoutine VariableDeclaratorList Semicolon { global_type = NULL; free($1);}
;

VariableDeclaratorList:
    VariableDeclaratorList Comma VariableDeclarator {}
|   VariableDeclarator { }
;

// used to declare instance variables of class, hence will be invoked in both passes.
VariableDeclarator:
    VariableDeclaratorId Assign VariableInitializer {    
                                                        if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                                                            if(pass_no == 2){
                                                                // cerr << $1->threeac << " $3-> " << $3->threeac <<  endl;  
                                                                emit("=", $3->threeac, "", $1->threeac);
                                                            }
                                                            VariableDeclarator($1, $3, 1);
                                                        }
                                                    }
|   VariableDeclaratorId { 
                            if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                                if(pass_no == 2) $$ = $1;
                                VariableDeclarator($1, NULL, 2);
                            }
                         }
;

VariableDeclaratorId:
    VariableDeclaratorId  Lsquare Rsquare {     
                                                if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                                                    $$ = increase_dims($1);
                                                }
                                                if(pass_no==2)  $$->threeac = $1->threeac+"["+"]";                                    
                                          }
|   Identifier  {    
                    if((pass_no==1 && current_scope==scope_class) || (pass_no==2)) {
                        $$ = make_stackentry((($1)->name).c_str(), global_type, yylineno);

                        if(pass_no==2)  $$->threeac = $1->name;

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
                    current_scope = scope_method;
                    // if(pass_no==2){
                    //     threeac_file_name = current_class->name + "_" + ($1)->token + ".3ac";
                    //     emit("\n\n"+threeac_file_name+":\n\n","","","");
                    // }
                } MethodBody {  
                                current_scope = scope_class; 
                                current_table->empty_table(); 
                                new_offset = 0;
                                if(pass_no==2){
                                    // $$ = $1;
                                    loopnum=0;
                                    ifnum=0;
                                    tcount=0;
                                    paramcount=0;
                                    threeac_file_name = DUMP_DIR + current_class->name + "." +  ($1)->token + three_ac_type_dump(($1)->argument_type) + ".3ac";
                                    dump_3ac(threeac_file_name);
                                }
                            }
;

MethodHeader:
    ModifiersUnannTypeSubRoutine Declarator {
                                                struct stackentry* entry = make_stackentry( (($2)->token).c_str(), ($1)->type, yylineno);
                                                entry->token = ($2)->token;
                                                entry->modifier = ($1)->modifier; 
                                                entry->argument_type = ($2)->argument_type;
                                                $$ = entry; 
                                                global_modifier = 0b0;
                                                free($1);
                                            }
|   UnannTypeSubRoutine Declarator      { 
                                            struct stackentry* entry = make_stackentry((($2)->token).c_str(), ($1)->type, yylineno); 
                                            entry->token = ($2)->token;
                                            entry->argument_type = ($2)->argument_type;
                                            $$ = entry; 
                                            free($1);
                                        }
|   Modifiers Void Declarator           { 
                                            struct stackentry* entry = make_stackentry((($3)->token).c_str(), get_type(__VOID), yylineno);
                                            entry->token = ($3)->token;
                                            entry->modifier = $1; 
                                            entry->argument_type = ($3)->argument_type;
                                            $$ = entry;
                                        }
|   Void Declarator                     { 
                                            struct stackentry* entry = make_stackentry((($2)->token).c_str(), get_type(__VOID), yylineno);
                                            entry->argument_type = ($2)->argument_type;
                                            entry->token = ($2)->token;
                                            $$ = entry;
                                        }
/* |   Modifiers UnannType Declarator Throws { 
                                            struct stackentry* entry = make_stackentry((($3)->token).c_str(), $2, yylineno);
                                            entry->modifier = $1; 
                                            entry->argument_type = ($3)->argument_type;
                                            $$ = entry;
                                            // global_modifier = 0b0; global_type = NULL;
                                            // Throws ???????????????????????????????????????
                                          }
|   UnannType Declarator Throws           { 
                                            struct stackentry* entry = make_stackentry((($2)->token).c_str(), $1, yylineno);  
                                            entry->argument_type = ($2)->argument_type;
                                            $$ = entry;
                                            // global_type = NULL;
                                            // Throws ???????????????????????????????????????
                                          }
|   Modifiers Void Declarator Throws      { 
                                            struct stackentry* entry = make_stackentry((($3)->token).c_str(), get_type(__VOID), yylineno);
                                            entry->modifier = $1; 
                                            entry->argument_type = ($3)->argument_type;
                                            $$ = entry;
                                            // Throws ???????????????????????????????????????
                                          }
|   Void Declarator Throws                { 
                                            struct stackentry* entry = make_stackentry((($2)->token).c_str(), get_type(__VOID), yylineno);
                                            entry->argument_type = ($2)->argument_type;
                                            $$ = entry;
                                            // Throws ???????????????????????????????????????
                                          } */
;

/* Throws:
    throws_ ExceptionTypeList             { }       

ExceptionTypeList:
    ExceptionType                         { }
|   ExceptionType CommaExceptionTypes     { }
    
CommaExceptionTypes:
    CommaExceptionTypes Comma ExceptionType  { }
|   Comma ExceptionType                      { } 

ExceptionType:
    ClassOrInterfaceType                    { } */


/*
    Added in place  of MethodDeclarator and ConstructorDeclarator
*/

DeclaratorSubRoutine: 
    Identifier Lparen   {
                            $$ = $1;
                            if(pass_no==2){
                                current_scope = scope_method;
                                // threeac_file_name = current_class->name + "_" + ($1)->name + ".3ac";
                                // emit("\n\n"+threeac_file_name+":\n\n","","","");
                            }
                        }

Declarator:
    DeclaratorSubRoutine Rparen { $$ = make_stackentry(($1->name).c_str(), yylineno); free($1); }
|   DeclaratorSubRoutine FormalParameterList Rparen { $2->token =($1)->name; $$ = $2; free($1);}
;

FormalParameterList:
    FormalParameterList Comma FormalParameter {
                                                $1->argument_type.push_back(($3)->type);
                                                $$ = $1;
                                                free($3);
                                             }
|   FormalParameter {  $$ = $1; }
;

FormalParameter:
    UnannTypeSubRoutine VariableDeclaratorId {
                                                $$ = $2;
                                                $$->argument_type.push_back($2->type);
                                                global_type = NULL;
                                                if (pass_no == 2)
                                                    add_variable($2->token, 0b0, $2->type, new_offset, true, true);
                                                
                                                new_offset += ($2)->type->size;
                                                if(pass_no==2){
                                                    emit("popparam", $2->token, "", "");
                                                }
                                                free($1);
                                            }
|   Final UnannTypeSubRoutine VariableDeclaratorId {
                                                $$ = $3;
                                                $$->modifier = __FINAL;
                                                $$->argument_type.push_back($3->type);
                                                global_type = NULL;
                                                if (pass_no == 2)
                                                    add_variable($3->token, $$->modifier, $3->type, new_offset, true, true);
                                                
                                                new_offset += ($3)->type->size;
                                                if(pass_no==2){
                                                    emit("popparam", $3->token, "", "");
                                                }
                                                free($2);
                                            } 
;

MethodBody:
    Block { }
;

StaticInitializer:
    Static Block { }
;

ConstructorDeclaration:
    Modifiers Declarator { add_constructor(($2)->token, ($2)->argument_type, $1); current_scope = scope_method; } ConstructorBody { if (pass_no == 2){ check_final_vars(); } current_scope = scope_class; current_table->empty_table();
                                                                                                                                        if(pass_no==2){
                                                                                                                                                        // $$ = $1;
                                                                                                                                                        loopnum=0;
                                                                                                                                                        ifnum=0;
                                                                                                                                                        tcount=0;
                                                                                                                                                        paramcount=0;
                                                                                                                                                        threeac_file_name = DUMP_DIR + current_class->name + "." +  ($2)->token + three_ac_type_dump(($2)->argument_type) + ".3ac";
                                                                                                                                                        dump_3ac(threeac_file_name);
                                                                                                                                                    }
                                                                                                                                    }
|   Declarator { add_constructor(($1)->token, ($1)->argument_type, (int8_t) 0); current_scope = scope_method; } ConstructorBody  { if(pass_no == 2) {check_final_vars();} current_scope = scope_class; current_table->empty_table();
                                                                                                                                        if(pass_no==2){
                                                                                                                                                        // $$ = $1;
                                                                                                                                                        loopnum=0;
                                                                                                                                                        ifnum=0;
                                                                                                                                                        tcount=0;
                                                                                                                                                        paramcount=0;
                                                                                                                                                        threeac_file_name = DUMP_DIR + current_class->name + "." +  ($1)->token + three_ac_type_dump(($1)->argument_type) + ".3ac";
                                                                                                                                                        dump_3ac(threeac_file_name);
                                                                                                                                                    }
                                                                                                                                }
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
    Lcurly BlockStatements Rcurly { }
|   Lcurly ExplicitConstructorInvocation BlockStatements Rcurly {  }
|   Lcurly ExplicitConstructorInvocation Rcurly {   }
|   Lcurly Rcurly { }
;

ExplicitConstructorInvocation:
    This Lparen Rparen  {
                            // This is the default constructor of a class, hence always exists, no need to check anything
                            if(pass_no == 2){
                                vector <Type*> v;
                                if(is_null(check_function_in_class( current_class->name, v, CONSTRUCTOR))){
                                    cerr << "Line No: " <<  yylineno  << "No such constructor present in class\n";
                                    exit(-1);
                                }
                            }
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
/* |   super_ Lparen Rparen { }
|   super_ Lparen ArgumentList Rparen { } */
;

// { {8,3}, 4, {4,5} }
ArrayInitializer: // int a[] = {2,3,4,5,6};
    Lcurly VariableInitializerList Rcurly { 
                                            if(pass_no == 2) {
                                                $$ =$2;
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
                                                    vector<Type *>v;
                                                    if(is_null(check_function_in_class(($2)->name, v, CONSTRUCTOR))) {
                                                        cerr << "Line No: " <<  yylineno << "Unknown constructor used"<<endl;
                                                        exit(1);
                                                    }
                                                    $$ = make_stackentry("", ($2), yylineno);
                                                    $$->threeac = get_temp();
                                                    emit("newcall", ($2)->name, "0", $$->threeac);
                                                                
                                                } 
                                            }
|   New ClassOrInterfaceType Lparen ArgumentList Rparen {   
                                                            if(pass_no == 2){
                                                                if(is_null(check_function_in_class(($2)->name, ($4)->argument_type, CONSTRUCTOR))){
                                                                    cerr << "Line No: " <<  yylineno <<"Unknown constructor used"<<endl;
                                                                    exit(1);
                                                                }

                                                                $$ = make_stackentry("", ($2), yylineno);
                                                                $$->threeac = get_temp();
                                                                emit("newcall", ($2)->name, to_string(paramcount), $$->threeac);
                                                                paramcount=0;
                                                            }
                                                        }
;

// p.i -> f -> func(1).i.i
FieldAccess:    Primary Dot Identifier  {   
                                            if(pass_no == 2 ){
                                                $$ = find_variable_in_class($3->name, true);
                                                $$->threeac = $1->threeac + "." + $3->name;
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
                                                            Type *t = new Type();
                                                            *t = *(($1)->type);
                                                            if(!t->is_pointer()){
                                                                cerr << "Line No: " <<  yylineno <<"Type of variable must be array type"<<endl;
                                                                exit(1);
                                                            }
                                                            t->arr_dim--;
                                                            $$ = $1; 
                                                            $$->threeac = $1->threeac + "[" + $3->threeac + "]";
                                                            free($3);
                                                            $$->type = t; 
                                                        }
                                                    }
|               PrimaryNoNewArray Lsquare Expression Rsquare    {   
                                                        if(pass_no == 2 ){
                                                            if( !(($3)->type->is_integral)){
                                                                cerr << "Line No: " <<  yylineno <<"Array index must be integer"<<endl;
                                                                exit(-1);
                                                            }
                                                            // $1 = find_variable_in_class(($1)->token, false);           --> unecessary     

                                                            // string id = ($1)->type;
                                                            Type *t = new Type();
                                                            *t = *(($1)->type);
                                                            if(!t->is_pointer()){
                                                                cerr << "Line No: " <<  yylineno <<"Type of variable must be array type"<<endl;
                                                                exit(1);
                                                            }
                                                            t->arr_dim--;
                                                            free($3);
                                                            $$ = $1; 
                                                            $$->type = t;
                                                            $$->threeac = $1->threeac + "[" + $3->threeac + "]";
                                                        }
                                                    }
;
// A -> B Lsquare C Rsquare    $$.type = $1.type + "*"      $3.type = __INT

MethodInvocation:   TypeName Lparen Rparen  {    
                                                if(pass_no == 2 ){
                                                    vector<Type *> v;
                                                    Type* return_type = check_function_in_class(($1)->token, v, FUNCTION);
                                                    if(return_type == NULL){
                                                        cerr << "Line No: " <<  yylineno  << "Undeclared function called\n";
                                                        exit(-1);
                                                    }
                                                    $$ = make_stackentry("", yylineno); 
                                                    $$->type = return_type;
                                                    $$->threeac = get_temp();
                                                    emit("call", ($1)->token, "", $$->threeac );

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
                                                                $$->threeac = get_temp();
                                                                emit("call", ($1)->token , to_string(paramcount), $$->threeac);
                                                                paramcount=0;
                                                            }
                                                        }
|                   Primary Dot Identifier Lparen Rparen { }
|                   Primary Dot Identifier Lparen ArgumentList Rparen { }
/* |                   super_ Dot Identifier Lparen Rparen { }
|                   super_ Dot Identifier Lparen ArgumentList Rparen { } */
;
// A -> B Lparen Rparen    $$.type = $1.type    $1.nature = "function"     $1.argtype = ""
// A -> B Lparen C Rparen      $$.type = $1.type    $1.nature = "function"     $1.argtype = $3.type   This argtype will be string concatenation of arguments type with a " , " in between
// A -> B Dot C Lparen D Rparen    $$.type = $3.type    $1.nature = "class"    $3.nature = "function"    $3.argtype = $5.type
// A -> B Dot C Lparen Rparen    $$.type = $3.type    $1.nature = "class"    $3.nature = "function"    $3.argtype = ""

ArgumentList:       Expression  { 
                                    if(pass_no == 2 ){
                                        struct stackentry* entry = make_stackentry("", yylineno); 
                                        entry->argument_type.push_back(($1)->type);
                                        $$ = entry;
                                        emit("param" ,($1)->threeac,"","");
                                        paramcount++;
                                        free($1);
                                    }
                                }
|                   ArgumentList Comma Expression { 
                                                    if(pass_no == 2 ){
                                                        $1->argument_type.push_back($3->type);
                                                        $$ = $1;
                                                        emit("param" ,($3)->threeac,"","");
                                                        paramcount++;
                                                        free($3);
                                                    }
                                                  }
;
// A -> B Comma C    $$.argtype = $1.argtype + " , " + $3.type

ArrayCreationExpression:    New PrimitiveType DimExprs Dims         {  
                                                                        if(pass_no == 2 ){
                                                                                            $$ = assign_arr_dim($2, $3, $4); 
                                                                                            $$->threeac = $2->name + $3->threeac + $4->threeac;
                                                                                        } 
                                                                    }
|                           New ClassOrInterfaceType DimExprs Dims  {  
                                                                        if(pass_no == 2 ){
                                                                                            $$ = assign_arr_dim($2, $3, $4); 
                                                                                            $$->threeac = $2->name + $3->threeac + $4->threeac;
                                                                                        } 
                                                                    }
|                           New PrimitiveType DimExprs              {  
                                                                        if(pass_no == 2 ){
                                                                                            $$ = assign_arr_dim($2, $3); 
                                                                                            $$->threeac = $2->name + $3->threeac;
                                                                                        } 
                                                                    }
|                           New ClassOrInterfaceType DimExprs       {  
                                                                        if(pass_no == 2 ){
                                                                                            $$ = assign_arr_dim($2, $3); 
                                                                                            $$->threeac = $2->name + $3->threeac;
                                                                                        } 
                                                                    }
|                           New PrimitiveType Dims ArrayInitializer {  
                                                                        if(pass_no == 2 ){
                                                                                            $$ = assign_arr_dim($2, $3); 
                                                                                            $$->threeac = $2->name + $3->threeac;
                                                                                        } 
                                                                    }
|                           New ClassOrInterfaceType Dims ArrayInitializer {  
                                                                                if(pass_no == 2 ){
                                                                                                    $$ = assign_arr_dim($2, $3); 
                                                                                                    $$->threeac = $2->name + $3->threeac;
                                                                                                } 
                                                                            }
;
// ArrayCreationExpression -> new B C ArrayInitializer    $$.type = $2.type + ("*")*(stringtoint($3.type))
// ArrayCreationExpression -> new B C     $$.type = $2.type + ("*")*(stringtoint($3.type))
// ArrayCreationExpression -> new B C D    $$.type = $2.type + ("*")*(stringtoint($3.type) + stringtoint($3.type))

DimExprs:   DimExpr  { if(pass_no == 2) $$ = $1; }
|           DimExprs DimExpr {  if(pass_no == 2 ){  $$ = assign_arr_dim($1, $2); $$->threeac = $1->threeac + $2->threeac;  } }
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
                                                $$->threeac = "[" + ($2)->threeac + "]";
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

                                                        if(!($1->type->is_numeric) || !($3->type->is_numeric)) {
                                                            cerr << "Line No: " <<  yylineno  << " incompatible types for binary operator\n\t "<< cerr_type(($3)->type) << " \n \t " << cerr_type(($1)->type) <<"\n";
                                                            exit(-1);
                                                        }

                                                        if(!check_return_type(($1)->type, ($3)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(($3)->type) << " cannot be converted to " << cerr_type(($1)->type) <<"\n";
                                                            exit(-1);
                                                        }

                                                        if($1->type->arr_dim || $3->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << " incompatible types incompatible types for binary operator\n\t " << cerr_type(($3)->type) << "\n \t" << cerr_type(($1)->type) <<"\n";
                                                            exit(-1);
                                                        }

                                                        $$ = $1;
                                                        $$->threeac = assignment_operator_3ac($1->token, $2, $3->threeac);
                                                    }
                                                }
|   LeftHandSide Assign Expression              {   
                                                    if(pass_no == 2 ){  
                                                        if(!check_return_type(($1)->type, ($3)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(($3)->type) << " cannot be converted to " << cerr_type(($1)->type) <<"\n";
                                                            exit(-1);
                                                        }

                                                        if($1->type->is_numeric && $3->type->is_numeric){
                                                            if(($1->type->arr_dim || $3->type->arr_dim) && ($1->type->name!=$3->type->name)){
                                                                cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(($3)->type) << " cannot be converted to " << cerr_type(($1)->type) <<"\n";
                                                                exit(-1);
                                                            }
                                                        }

                                                        $$ = $1;
                                                        $$->threeac = assign_operator_3ac($1->token, $3->threeac);
                                                    }
                                                }
;

LeftHandSide:
    TypeName {  
                if(pass_no == 2 ){ 
                    struct stackentry* entry = find_variable_in_class(($1)->token, true);
                    $$ = entry;
                    
                }
            }
|   FieldAccess { if(pass_no == 2 ) $$ = $1; }
|   ArrayAccess { if(pass_no == 2 ) $$ = $1; }
;

ConditionalExpression:  ConditionalOrExpression { $$ = $1; }
|                   ConditionalOrExpression Qm Expression Colon ConditionalExpression {     
                                                                                            if(pass_no == 2 ){

                                                                                                if(($1)->type->arr_dim) {
                                                                                                    cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(($1)->type) << " cannot be converted to boolean\n";
                                                                                                    exit(-1);
                                                                                                }

                                                                                                if(($1)->type->name != __BOOLEAN){
                                                                                                    cerr << "Line No: " <<  yylineno  << " incompatible types: "<< cerr_type(($1)->type) << " cannot be converted to boolean\n";
                                                                                                    exit(-1);
                                                                                                }

                                                                                                if($3->type->name == __BOOLEAN || $5->type->name == __BOOLEAN) {
                                                                                                    if(!check_return_type($3->type, $5->type)){
                                                                                                        cerr << "Line No: " <<  yylineno  << "Non intersectionable type: " << cerr_type(($3)->type) << " and " << cerr_type(($5)->type) << "\n";
                                                                                                        exit(-1);
                                                                                                    }

                                                                                                    $$ = $3;
                                                                                                }
                                                                                                else {
                                                                                                    if(check_return_type(($3)->type, ($5)->type)) 
                                                                                                        $$ = $3;
                                                                                                    else
                                                                                                        $$ = $5;
                                                                                                }
                                                                                                $$->threeac = ternary_condition_3ac( $1->threeac, $3->threeac, $5->threeac);
                                                                                            }
                                                                                      } //Check Again
;

ConditionalOrExpression:    ConditionalAndExpression { if(pass_no == 2 ) $$ = $1; }
|                   ConditionalOrExpression Or ConditionalAndExpression {   
                                                                            if(pass_no == 2 ) {  
                                                                                $$ = ConditionalExpression($1, $3);
                                                                                $$->threeac = binary_operator_3ac($1->threeac, "OR", $3->threeac);
                                                                            }
                                                                        }
;

ConditionalAndExpression:   InclusiveOrExpression { if(pass_no == 2 ) $$ = $1; }
|                   ConditionalAndExpression And InclusiveOrExpression  {   
                                                                            if(pass_no == 2 ) {
                                                                                $$ = ConditionalExpression($1, $3);
                                                                                $$->threeac = binary_operator_3ac($1->threeac,"AND", $3->threeac);
                                                                            }
                                                                        }
;

InclusiveOrExpression:  ExclusiveOrExpression { if(pass_no == 2 ) $$ = $1; }
|                   InclusiveOrExpression Bitwise_or ExclusiveOrExpression  {   
                                                                                if(pass_no == 2 ){  
                                                                                    $$ = BitwiseExpression($1, $3);
                                                                                    $$->threeac = binary_operator_3ac($1->threeac, "|", $3->threeac);
                                                                                }
                                                                            }
;

ExclusiveOrExpression:  AndExpression   { if(pass_no == 2 ) $$ = $1; }
|                   ExclusiveOrExpression Bitwise_xor AndExpression     {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = BitwiseExpression($1, $3);
                                                                                $$->threeac = binary_operator_3ac($1->threeac, "^", $3->threeac);
                                                                            }
                                                                        }
;

AndExpression:  EqualityExpression  { if(pass_no == 2 ) $$ = $1; }
|                   AndExpression Bitwise_and EqualityExpression    {       
                                                                            if(pass_no == 2 ){  
                                                                                $$ = BitwiseExpression($1, $3);
                                                                                $$->threeac = binary_operator_3ac($1->threeac, "&", $3->threeac);
                                                                            }
                                                                        }
;

EqualityExpression: RelationalExpression { if(pass_no == 2 ) $$ = $1; }
|                   EqualityExpression Deq RelationalExpression     {   
                                                                        if(pass_no == 2 ){  
                                                                            $$ = EqualityExpression($1, $3);
                                                                            $$->threeac = deq_check_3ac($1->threeac, $3->threeac);
                                                                        }
                                                                    }
|                   EqualityExpression Neq RelationalExpression     {   
                                                                        if(pass_no == 2 ){  
                                                                            $$ = EqualityExpression($1, $3);
                                                                            $$->threeac = neq_check_3ac($1->threeac, $3->threeac);
                                                                        }
                                                                    }
;

RelationalExpression:   ShiftExpression { if(pass_no == 2 ) $$ = $1; }
|                   RelationalExpression Lt ShiftExpression         {       
                                                                            if(pass_no == 2 ){  
                                                                                $$ = RelationalExpression($1, $3);
                                                                                $$->threeac = relation_check_3ac($1->threeac, "<", $3->threeac);
                                                                            }
                                                                    }
|                   RelationalExpression Gt ShiftExpression         {       
                                                                            if(pass_no == 2 ){  
                                                                                $$ = RelationalExpression($1, $3);
                                                                                $$->threeac = relation_check_3ac($1->threeac, ">", $3->threeac);
                                                                            }
                                                                    }
|                   RelationalExpression Leq ShiftExpression        {        
                                                                            if(pass_no == 2 ){  
                                                                                $$ = RelationalExpression($1, $3);
                                                                                $$->threeac = relation_check_3ac($1->threeac,"<=", $3->threeac);
                                                                            }
                                                                    }
|                   RelationalExpression Geq ShiftExpression        {       
                                                                            if(pass_no == 2 ){  
                                                                                $$ = RelationalExpression($1, $3);
                                                                                $$->threeac = relation_check_3ac($1->threeac,">=", $3->threeac);
                                                                                           //Error Location $$ type mismatch
                                                                            }
                                                                    }
/* |                   RelationalExpression Instanceof ReferenceType   { } */
;

ShiftExpression:    AdditiveExpression { if(pass_no == 2 ) $$ = $1; }
|                   ShiftExpression Left_shift AdditiveExpression   {   
                                                                        if(pass_no == 2 ){  
                                                                            $$ = ShiftExpression($1, $3);
                                                                            $$->threeac = get_temp();
                                                                            emit("<<", ($1)->threeac, ($3)->threeac, ($$)->threeac);
                                                                        }
                                                                    }
|                   ShiftExpression Right_shift AdditiveExpression  {   
                                                                        if(pass_no == 2 ){  
                                                                            $$ = ShiftExpression($1, $3);
                                                                            $$->threeac = get_temp();
                                                                            emit(">>", ($1)->threeac, ($3)->threeac, ($$)->threeac);
                                                                        }
                                                                    }
|                   ShiftExpression Unsigned_right_shift AdditiveExpression     {   
                                                                                    if(pass_no == 2 ){  
                                                                                       $$ = ShiftExpression($1, $3);
                                                                                       $$->threeac = get_temp();
                                                                                       emit(">>>", ($1)->threeac, ($3)->threeac, ($$)->threeac);
                                                                                    }
                                                                                }
;

AdditiveExpression: MultiplicativeExpression { if(pass_no == 2 ) $$ = $1; }
|                   AdditiveExpression Plus MultiplicativeExpression    {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_additive_types($1, $3);
                                                                                $$->threeac = get_temp();
                                                                                if($$->type->name != $1->type->name){
                                                                                    string temp = get_temp();
                                                                                    emit("cast_to_"+$$->type->name, $1->threeac, temp,"");
                                                                                    emit("+"+$$->type->name, temp, ($3)->threeac, ($$)->threeac);
                                                                                }
                                                                                else if($$->type->name != $3->type->name){
                                                                                    string temp = get_temp();
                                                                                    emit("cast_to_"+$$->type->name, $3->threeac, temp,"");
                                                                                    emit("+"+$$->type->name, ($1)->threeac, temp, ($$)->threeac);
                                                                                }
                                                                                else
                                                                                    emit("+"+$$->type->name, ($1)->threeac, ($3)->threeac, ($$)->threeac);
                                                                            }
                                                                        } 
|                   AdditiveExpression Minus MultiplicativeExpression   {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_additive_types($1, $3);
                                                                                $$->threeac = get_temp();
                                                                                if($$->type->name != $1->type->name){
                                                                                    string temp = get_temp();
                                                                                    emit("cast_to_"+$$->type->name, $1->threeac, temp,"");
                                                                                    emit("-"+$$->type->name, temp, ($3)->threeac, ($$)->threeac);
                                                                                }
                                                                                else if($$->type->name != $3->type->name){
                                                                                    string temp = get_temp();
                                                                                    emit("cast_to_"+$$->type->name, $3->threeac, temp,"");
                                                                                    emit("-"+$$->type->name, ($1)->threeac, temp, ($$)->threeac);
                                                                                }
                                                                                else
                                                                                    emit("-"+$$->type->name, ($1)->threeac, ($3)->threeac, ($$)->threeac);
                                                                            }
                                                                        }
;

MultiplicativeExpression:   UnaryExpression                             { if(pass_no == 2 ) $$ = $1; }
|                   MultiplicativeExpression Asterik UnaryExpression    {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_additive_types($1, $3);
                                                                                $$->threeac = get_temp();
                                                                                emit("*", ($1)->threeac, ($3)->threeac, ($$)->threeac);
                                                                            }
                                                                        }
|                   MultiplicativeExpression Div UnaryExpression        {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_additive_types($1, $3);
                                                                                $$->threeac = get_temp();
                                                                                emit("/", ($1)->threeac, ($3)->threeac, ($$)->threeac);
                                                                            }
                                                                        }
|                   MultiplicativeExpression Modulo UnaryExpression     {   
                                                                            if(pass_no == 2 ){  
                                                                                $$ = check_additive_types($1, $3);
                                                                                $$->threeac = get_temp();
                                                                                emit("%", ($1)->threeac, ($3)->threeac, ($$)->threeac);
                                                                            }
                                                                        }
;

UnaryExpression:    PreIncrementExpression      { if(pass_no == 2 ) $$ = $1; }
|                   PreDecrementExpression      { if(pass_no == 2 ) $$ = $1; }
|                   Plus UnaryExpression        {   
                                                    if(pass_no == 2 ){  
                                                        if($2->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << " :bad operand type " << cerr_type($2->type) <<" for unary operator '+'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(($2)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        $$ = $2;
                                                    }
                                                }
|                   Minus UnaryExpression       {   
                                                    if(pass_no == 2 ){   
                                                        if($2->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << " : bad operand type " << cerr_type($2->type) <<" for unary operator '-'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(($2)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        $$ = $2;
                                                        $$->threeac = get_temp();
                                                        emit("uminus", ($2)->threeac, "", ($$)->threeac);
                                                    }
                                                }
|                   UnaryExpressionNotPlusMinus { if(pass_no == 2 ) $$ = $1; }
;

PreIncrementExpression: Increment Primary       {   
                                                    if(pass_no == 2 ){  
                                                        if($2->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($2->type) <<" for unary operator '++'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(($2)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        $$ = $2;
                                                        $$->threeac = pre_increament_3ac($$->token);
                                                    }
                                                }
|                       Increment TypeName      {   
                                                    if(pass_no == 2 ){  
                                                        $$ = find_variable_in_class(($2)->token, false);

                                                        if($$->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($$->type) <<" for unary operator '++'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(($$)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        $$->threeac = pre_increament_3ac($$->token); 
                                                    }
                                                }
;

PreDecrementExpression: Decrement Primary   {       
                                                    if(pass_no == 2 ){   
                                                        if($2->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($2->type) <<" for unary operator '--'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(($2)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        $$ = $2;
                                                        $$->threeac = pre_decreament_3ac($$->token);
                                                    
                                                    }
                                            }
|                       Decrement TypeName  {       
                                                    if(pass_no == 2 ){  
                                                        $$ = find_variable_in_class(($2)->token, false);
                                                        if($$->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($$->type) <<" for unary operator '+'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(($$)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "unary Expression Type should be numeric\n";
                                                            exit(1);
                                                        }
                                                        $$->threeac = pre_decreament_3ac($$->token);
                                                    }
                                            }
;

UnaryExpressionNotPlusMinus:    PostfixExpression                   { if(pass_no == 2 ) $$ = $1; }
|                               Bitwise_complement UnaryExpression  {   
                                                                        if(pass_no == 2 ){ 
                                                                            if($2->type->arr_dim) {
                                                                                cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($2->type) <<" for unary operator '~'\n";
                                                                                exit(1);
                                                                            } 

                                                                            if(!$2->type->is_integral){
                                                                                cerr << "unary Expression type must be integral\n";
                                                                                exit(1);
                                                                            }
                                                                            $$ = $2;
                                                                            $$->threeac = get_temp();
                                                                            emit("~", ($2)->threeac, "", ($$)->threeac);
                                                                        }
                                                                    }
|                               Not UnaryExpression                 {   
                                                                        if(pass_no == 2 ){ 
                                                                            if($2->type->arr_dim) {
                                                                                cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($2->type) <<" for unary operator '!'\n";
                                                                                exit(1);
                                                                            } 

                                                                            check_boolean($2->type);
                                                                            $$ = $2;
                                                                            $$->threeac = get_temp();
                                                                            emit("!", ($2)->threeac, "", ($$)->threeac);
                                                                        }
                                                                    }
|                               CastExpression                      { if(pass_no == 2 ) $$ = $1; }
;

PostfixExpression:  Primary                 { if(pass_no == 2 ) $$ = $1; }
|                   TypeName                {   if(pass_no == 2 ) {
                                                    $$ = find_variable_in_class(($1)->token, false); 
                                                    $$->threeac = ($1)->threeac; 
                                                }
                                            }
|                   PostIncrementExpression { if(pass_no == 2 ) $$ = $1; }
|                   PostDecrementExpression { if(pass_no == 2 ) $$ = $1; }
;

PostIncrementExpression:    Primary Increment   {   
                                                    if(pass_no == 2 ){  
                                                        if($1->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($1->type) <<" for unary operator '++'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(($1)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '++' \n first type: "<< ($1)->type << "\n";
                                                            exit(-1);
                                                        }
                                                        $$ = $1;
                                                        $$->threeac = post_increament_3ac($$->token);
                                                    }
                                                }
|                           TypeName Increment  {   
                                                    if(pass_no == 2 ){  
                                                        $$ = find_variable_in_class(($1)->token, false);

                                                        if($$->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($$->type) <<" for unary operator '++'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(($$)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '++' \n first type: "<< ($1)->type << "\n";
                                                            exit(-1);
                                                        }
                                                        $$->threeac = post_increament_3ac($$->token);
                                                    }
                                                }
;

PostDecrementExpression:    Primary Decrement   {   
                                                    if(pass_no == 2 ){

                                                        if($1->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($1->type) <<" for unary operator '--'\n";
                                                            exit(1);
                                                        }

                                                        if(!check_if_numeric_type(($1)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '--' \n first type: "<< ($1)->type << "\n";
                                                            exit(-1);
                                                        }
                                                        
                                                        $$ = $1;
                                                        $$->threeac = post_decreament_3ac($$->token);
                                                    }
                                                }
|                           TypeName Decrement  {   
                                                    if(pass_no == 2 ){
                                                        if($1->type->arr_dim) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand type " << cerr_type($1->type) <<" for unary operator '--'\n";
                                                            exit(1);
                                                        }

                                                        $$ = find_variable_in_class(($1)->token, false);
                                                        if(!check_if_numeric_type(($$)->type)) {
                                                            cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '--' \n first type: "<< ($1)->type << "\n";
                                                            exit(-1);
                                                        }
                                                        $$->threeac = post_decreament_3ac($$->token);
                                                    }
                                                }
;

CastExpression:     Lparen PrimitiveType Rparen UnaryExpression                 {   
                                                                                    if(pass_no == 2 ){
                                                                                        check_cast_types($2, $4->type);
                                                                                        $$ = make_stackentry("", $2, yylineno);
                                                                                        $$->threeac = get_temp();
                                                                                        emit("cast_to_" + $2->name, $4->threeac, "", $$->threeac);
                                                                                        // emit($4->type->name + "to_" + $2->name, $4->threeac, "", $$->threeac);
                                                                                    }
                                                                                }
|                   Lparen ReferenceType Rparen UnaryExpressionNotPlusMinus     {   
                                                                                    if(pass_no == 2 ){
                                                                                        check_cast_types($2, $4->type);
                                                                                        $$ = make_stackentry("", $2, yylineno);
                                                                                        $$->threeac = get_temp();
                                                                                        emit("cast_to_" + $2->name, $4->threeac, "", $$->threeac);
                                                                                        // emit($4->type->name + "to_" + $2->name, $4->threeac, "", $$->threeac);
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

LocalVariableDeclarationStatement:    LocalVariableDeclaration  Semicolon { if(pass_no == 2 ){ global_type = NULL; global_modifier= 0b0;} }
;

LocalVariableDeclaration:    UnannTypeSubRoutine VariableDeclaratorList   { global_type = NULL; free($1); }
|                            Var      { if(pass_no == 2 ) global_type = get_type(__VAR); }  VariableDeclaratorList   { }
|                            Final { if(pass_no == 2 ) global_modifier = __FINAL; } UnannTypeSubRoutine VariableDeclaratorList { global_type = NULL; free($3); }
|                            Final { if(pass_no == 2 ) global_modifier = __FINAL; } Var    { if(pass_no == 2 ) global_type = get_type(__VAR); }  VariableDeclaratorList  { }
;


Statement:          StatementWithoutTrailingSubstatement   {}
|                   LabeledStatement   {}
|                   IfThenStatement   {}
|                   IfThenElseStatement {} 
|                   WhileStatement  {}
|                   ForStatement   {}
;

StatementNoShortIf:     StatementWithoutTrailingSubstatement   {}
|                       LabeledStatementNoShortIf  {}
|                       IfThenElseStatementNoShortIf    {}   
|                       WhileStatementNoShortIf {}
|                       ForStatementNoShortIf  {}
;

StatementWithoutTrailingSubstatement:   Block   {}
|                                       EmptyStatement  {}
|                                       ExpressionStatement {} 
|                                       AssertStatement {}
|                                       BreakStatement  {}
|                                       ContinueStatement {}   
|                                       ReturnStatement {}
|                                       ThrowStatement {}
// |                                       SwitchStatement  
|                                       DoStatement   {}
/* |                                       SynchronizedStatement {} */
// |                                       YieldStatement  
/* |                                       TryStatement  {} */
;

/* SynchronizedStatement:
                        synchronized_ Lparen Expression Rparen Block { }
; */

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

IfCountIncrement:
    %empty  {
                if(pass_no==2) $$ = ifnum++;
            }
;
IfThenStatementSubRoutine:
    IfCountIncrement IF Lparen Expression    { 
                                if(pass_no == 2){
                                    IfCondition($4); 
                                    $$ = $1;
                                    emit("if " , $4->threeac , "false", "goto(Else" + to_string($1) + ")");
                                    emit("\nIf"+to_string($1)+":\n", "", "", "");
                                }
                            }
;

IfThenStatement:    IfThenStatementSubRoutine Rparen ScopeIncrement Statement   {   
                                                                                    if(pass_no == 2){
                                                                                        // cout << "If" << current_table->current_level << "\n\n";
                                                                                        clear_current_scope(); 
                                                                                        emit("goto(EndIf" + to_string($1) + ")", "", "", "");
                                                                                        emit("\nElse"+to_string($1)+":\n", "", "", "");
                                                                                        emit("\nEndIf" + to_string($1) + ":\n", "", "", "");
                                                                                    }
                                                                                }
;

IfThenThreeACSubRoutine: IfThenStatementSubRoutine Rparen ScopeIncrement StatementNoShortIf Else    {   
                                                                                                        if(pass_no == 2)  {
                                                                                                            emit("goto(EndIf" + to_string($1) + ")", "", "", "");
                                                                                                            emit("\nElse"+to_string($1)+":\n", "", "", "");
                                                                                                            $$ = $1;
                                                                                                        }
                                                                                                    }
;

IfThenElseStatement:    IfThenThreeACSubRoutine Statement   {   
                                                                if(pass_no == 2){
                                                                    emit("\nEndIf" + to_string($1) + ":\n", "", "", "");
                                                                    clear_current_scope(); 
                                                                }
                                                            }
;

IfThenElseStatementNoShortIf:   IfThenThreeACSubRoutine StatementNoShortIf  {   
                                                                                if(pass_no == 2){
                                                                                    emit("\nEndIf" + to_string($1) + ":\n", "", "", "");
                                                                                    clear_current_scope(); 
                                                                                }
                                                                            }
;

AssertStatement:    Assert Expression Semicolon {   
                                                    if(pass_no == 2){
                                                        AssertCondition($2); 
                                                        emit("If", $2->threeac, "false" , "goto(exit)");
                                                    }
                                                }
/* |                   Assert Expression Colon Expression Semicolon    { AssertCondition($2); } */
;

WhileStatementSubRoutine:
    While Lparen Expression {
                                if(pass_no == 2){
                                    WhileCondition($3); 
                                    $$ = $1;
                                    emit("\nLoop" + to_string($1) + ":\n","","","");
                                    emit("If ", $3->threeac, "false", "goto(Endloop"+to_string($1)+")");
                                }
                            }
;

WhileStatement:    WhileStatementSubRoutine Rparen Statement {   
                                                                    if(pass_no == 2){
                                                                        emit("goto(Loop"+to_string($1)+")", "", "", "");
                                                                        emit("\nEndloop"+to_string($1)+":\n","","","");
                                                                        clear_current_scope(); 
                                                                    }
                                                            }
;

WhileStatementNoShortIf:    WhileStatementSubRoutine Rparen StatementNoShortIf  {   
                                                                                    if(pass_no == 2){         
                                                                                        emit("goto(Loop"+to_string($1)+")", "", "", "");
                                                                                        emit("\nEndloop"+to_string($1)+":\n","","","");                                                                           
                                                                                        clear_current_scope(); 
                                                                                    }
                                                                                }
;

DoStatement:
    do_ {
            if(pass_no == 2) emit("\nLoop" + to_string($1) + ":\n","","","");  
        } Statement While {if(pass_no == 2) loopnum--;} Lparen Expression {     
                                                    if(pass_no == 2){ 
                                                        check_boolean($7->type); 
                                                        emit("If ", $7->threeac,"true" , "goto(Loop"+ to_string($1)+")");
                                                        emit("\nEndloop"+to_string($1)+":\n","","","");
                                                    }
                                            } Rparen Semicolon  { if(pass_no == 2) clear_current_scope(); }
;

ForStatement:       BasicForStatement   
|                   EnhancedForStatement 
;

ForStatementNoShortIf:    BasicForStatementNoShortIf  
|                   EnhancedForStatementNoShortIf 
;

For1SubRoutine: For5SubRoutine Expression   { 
                                    if(pass_no == 2){
                                        ForCondition($2); 
                                        emit("If", $2->threeac, "false", "goto(EndFor"+ to_string($1)+")");
                                        emit("If", $2->threeac, "true", "goto(ForBody"+ to_string($1)+")");
                                        $$ = $1;
                                    }
                                }
;
For2SubRoutine: For7SubRoutine Expression Semicolon   { 
                                    if(pass_no == 2){
                                        ForCondition($2); 
                                        emit("If", $2->threeac, "false", "goto(EndFor"+ to_string($1)+")");
                                        emit("If", $2->threeac, "true", "goto(ForBody"+ to_string($1)+")");
                                        /*3ac Update*/ emit("\nForUpdate" + to_string($1) + ":\n","","","");
                                        $$ = $1;
                                    }
                                }
;
For3SubRoutine: For5SubRoutine Semicolon {  
                                            if(pass_no == 2){
                                                
                                                emit("goto(ForBody"+ to_string($1)+")","","","");
                                                /*3ac Update*/ emit("\nForUpdate" + to_string($1) + ":\n","","","");
                                                $$ = $1;
                                            }
                                        }
;
For4SubRoutine:    For7SubRoutine Semicolon {   
                                                if(pass_no == 2){
                                                    
                                                    emit("goto(ForBody"+ to_string($1)+")","","","");
                                                    /*3ac Update*/ emit("\nForUpdate" + to_string($1) + ":\n","","","");
                                                    $$ = $1;
                                                }
                                            }
;
For5SubRoutine: For Lparen Semicolon    {   
                                            if(pass_no == 2){
                                                emit("ForCondition" + to_string($1) + ":\n","","","");
                                                $$ = $1;
                                            }
                                        } 
;
For6SubRoutine:    For1SubRoutine Semicolon Rparen {
                                        if(pass_no == 2){
                                            emit("\nForUpdate" + to_string($1) + ":\n","","","");  // Not Required // Just for notation and clarity
                                            emit("goto(ForCond"+ to_string($1)+")","","","");
                                            emit("\nForBody" + to_string($1)+ ":\n","","","");
                                            $$ = $1;
                                        }
                                    }
;
For7SubRoutine: For Lparen ForInit Semicolon    { 
                                            if(pass_no == 2){
                                                emit("\nForCondition" + to_string($1) + ":\n","","","");
                                                $$ = $1;
                                            }
                                    }
;
For8SubRoutine: For3SubRoutine Rparen { 
                                        if(pass_no == 2){
                                            emit("\nForUpdate" + to_string($1) + ":\n","","","");  // Not Required // Just for notation and clarity
                                            emit("goto(ForCond"+ to_string($1)+")","","","");
                                            emit("\nForBody" + to_string($1)+ ":\n","","","");
                                            $$ = $1;
                                        }
                                    }

For9SubRoutine: For4SubRoutine Rparen  {    
                                            if(pass_no == 2){
                                                emit("\nForUpdate" + to_string($1) + ":\n","","","");  // Not Required // Just for notation and clarity
                                                emit("goto(ForCond"+ to_string($1)+")","","","");
                                                emit("\nForBody" + to_string($1)+ ":\n","","","");
                                                $$ = $1;
                                            }
                                        } 

For10SubRoutine: For3SubRoutine ForUpdate Rparen {  
                                                    if(pass_no == 2){
                                                        emit("goto(ForCond"+ to_string($1)+")","","","");
                                                        emit("\nForBody" + to_string($1)+ ":\n","","","");
                                                        $$ = $1;
                                                    }
                                                }

For11SubRoutine: For2SubRoutine Rparen {  
                                                    if(pass_no == 2){
                                                        emit("\nForUpdate" + to_string($1) + ":\n","","","");  // Not Required // Just for notation and clarity
                                                        emit("goto(ForCond"+ to_string($1)+")","","","");
                                                        emit("\nForBody" + to_string($1)+ ":\n","","","");
                                                        $$ = $1;
                                                    }
                                                }

For12SubRoutine: For4SubRoutine ForUpdate Rparen {  
                                                    if(pass_no == 2){
                                                        emit("goto(ForCond"+ to_string($1)+")","","","");
                                                        emit("\nForBody" + to_string($1)+ ":\n","","","");
                                                        $$ = $1;
                                                    }
                                                }

For13SubRoutine: For1SubRoutine Semicolon ForUpdate  Rparen  {  
                                                                if(pass_no == 2){
                                                                    emit("goto(ForCond"+ to_string($1)+")","","","");
                                                                    emit("\nForBody" + to_string($1)+ ":\n","","","");
                                                                    $$ = $1;
                                                                }
                                                            }

For14SubRoutine: For2SubRoutine ForUpdate Rparen {    
                                                                if(pass_no == 2){
                                                                    emit("goto(ForCond"+ to_string($1)+")","","","");
                                                                    emit("\nForBody" + to_string($1)+ ":\n","","","");
                                                                    $$ = $1;
                                                                }
                                                            }
;

BasicForStatement:      For8SubRoutine Statement {              
                                                                if(pass_no == 2){
                                                                     
                                                                    emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                    emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }

|                       For9SubRoutine  Statement { 
                                                    if(pass_no == 2){
                                                         
                                                        emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                        emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                        // $$ = $1;
                                                        clear_current_scope();
                                                    }
                                                }
|                       For6SubRoutine Statement      {      
                                                            if(pass_no == 2){
                                                                 
                                                                emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                // $$ = $1;
                                                                clear_current_scope();
                                                            }
                                                        }
|                       For10SubRoutine  Statement {    
                                                        if(pass_no == 2){
                                                             
                                                            emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                            emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                            // $$ = $1;
                                                            clear_current_scope();
                                                        }
                                                    }

|                       For11SubRoutine Statement {     
                                                        if(pass_no == 2){
                                                             
                                                            emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                            emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                            // $$ = $1;
                                                            clear_current_scope();
                                                        }
                                                    } 

|                       For12SubRoutine Statement {     
                                                        if(pass_no == 2){
                                                             
                                                            emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                            emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                            // $$ = $1;
                                                            clear_current_scope();
                                                        }
                                                    }

|                       For13SubRoutine Statement { 
                                                    if(pass_no == 2){
                                                         
                                                        emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                        emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                        // $$ = $1;
                                                        clear_current_scope();
                                                    }
                                                }

|                       For14SubRoutine Statement      {    
                                                            if(pass_no == 2){
                                                                 
                                                                emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                // $$ = $1;
                                                                clear_current_scope();
                                                            }
                                                        }

;

BasicForStatementNoShortIf:    
                        For8SubRoutine StatementNoShortIf {     
                                                                if(pass_no == 2){  
                                                                    emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                    emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }

|                       For9SubRoutine StatementNoShortIf {     
                                                                if(pass_no == 2){
                                                                    emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                    emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }
|                       For6SubRoutine StatementNoShortIf      {    if(pass_no == 2){
                                                                        emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                        emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                        // $$ = $1;
                                                                        clear_current_scope();
                                                                    }
                                                                }
|                       For10SubRoutine StatementNoShortIf {    
                                                                if(pass_no == 2){        
                                                                     
                                                                    emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                    emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }

|                       For11SubRoutine StatementNoShortIf {    
                                                                if(pass_no == 2){
                                                                     
                                                                    emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                    emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            } 

|                       For12SubRoutine StatementNoShortIf {    
                                                                if(pass_no == 2){
                                                                     
                                                                    emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                    emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }

|                       For13SubRoutine StatementNoShortIf {    
                                                                if(pass_no == 2){
                                                                     
                                                                    emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                    emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                    // $$ = $1;
                                                                    clear_current_scope();
                                                                }
                                                            }

|                       For14SubRoutine StatementNoShortIf      {   
                                                                    if(pass_no == 2){
                                                                         
                                                                        emit("goto(ForUpdate" + to_string($1) + ")","","","");
                                                                        emit("\nEndFor" + to_string($1) + ":\n","","",""); 
                                                                        // $$ = $1;
                                                                        clear_current_scope();
                                                                    }
                                                                }

;

ForInit:    StatementExpressionList     {}
|           LocalVariableDeclaration   {}
;

ForUpdate:    StatementExpressionList  {}
;

StatementExpressionList:    StatementExpression {}
|                           StatementExpression CommaStatementExpressions  {}
;

CommaStatementExpressions:   Comma StatementExpression CommaStatementExpressions   {}
|                            Comma StatementExpression {}
;

EnhancedForStatementSubRoutine:
    For Lparen LocalVariableDeclaration Colon Expression { if(pass_no == 2) EnhancedForCondition($5); }
;

EnhancedForStatement:    EnhancedForStatementSubRoutine Rparen Statement  { if(pass_no == 2) emit("goto(ForUpdate"+to_string(loopnum-1)+")","","",""); }
;

EnhancedForStatementNoShortIf:    EnhancedForStatementSubRoutine Rparen StatementNoShortIf    { if(pass_no == 2) emit("goto(ForUpdate"+to_string(loopnum-1)+")","","",""); }
;

BreakStatement:    Break Semicolon { if(pass_no == 2) emit("goto(EndLoop"+to_string(loopnum-1)+")","","",""); }
                //    Break Identifier Semicolon   { }
                 
;

/* YieldStatement:     yield_ Expression Semicolon     { }
; */

ContinueStatement:   Continue Semicolon { if(pass_no == 2) emit("goto(Loop"+to_string(loopnum-1)+")","","","");}
                    //   Continue Identifier Semicolon  { }                   
;

ReturnStatement:
    Return Expression Semicolon {   
                                    if(pass_no == 2){
                                        if(!check_return_type(current_table->return_type, ($2)->type)) {
                                            cout << "Cannot return " << cerr_type(($2)->type) << " from function whose return type is " << cerr_type(current_table->return_type) << "\n";
                                            exit(-1);
                                        }
                                        emit("return" , $2->threeac,"","");
                                    }
                                }
|   Return  Semicolon {     
                            if(pass_no == 2){
                                if(!check_return_type(current_table->return_type, get_type(__VOID))) {
                                            cout << "Cannot return " << __VOID << " from function whose return type is " << cerr_type(current_table->return_type) << "\n";
                                            exit(-1);
                                }
                                emit("return","","","");
                            }
                     }
;

ThrowStatement:    Throw Expression Semicolon   { }
;

/* TryStatement:
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
; */

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

/* If : IF { }
; */

Else : ELSE { }
;

While : WHILE   { 
                    if(pass_no == 2){
                        increase_current_level(); 
                        $$ = loopnum++;
                    }
                }
;

For : FOR       {   
                    if(pass_no == 2){
                        increase_current_level(); 
                        $$ = loopnum++; 
                    }
                }
;

do_: DO         {   
                    if(pass_no == 2){
                        increase_current_level(); 
                        $$ = loopnum++; 
                    }
                }
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

This : THIS { 
                struct stackentry* entry = make_stackentry("", get_type(current_class->name), yylineno); 
                $$ = entry;
            }
;

/* Instanceof : INSTANCEOF { }
; */

/* super_ : SUPER { } */
;

Throw : THROW { }
;

/* Implements : IMPLEMENTS { }
;

Interface : INTERFACE { }
;

Extends : EXTENDS { }
; */

/* Package : PACKAGE { }
;

Import : IMPORT { }
; */


/* switch_ : SWITCH { } */

/* yield_ : YIELD  { } */

/* try_ : TRY { } */

/* throws_ : THROWS { } */

/* catch_ : CATCH { } */

/* finally_ : FINALLY { }

synchronized_ : SYNCHRONIZED { } */

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

AssignmentOperator:  ASSIGNMENT { $$ = $1; }
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

Char_literal : CHAR_LITERAL     { 
                                    $$ = make_stackentry($1, get_type(__CHAR), yylineno); 
                                    if(pass_no == 2){
                                        $$->threeac = $1;
                                    }
                                }
;

Boolean_literal : BOOLEAN_LITERAL { 
                                    $$ = make_stackentry($1, get_type(__BOOLEAN), yylineno); 
                                    if(pass_no == 2){
                                        $$->threeac = $1;
                                    }
                                }
;

Null_literal : NULL_LITERAL     { 
                                    $$ = make_stackentry($1, yylineno); 
                                    if(pass_no == 2){
                                        $$->threeac = $1;
                                    }
                                }
;

Integer_literal : INTEGER_LITERAL { 
                                    $$ = make_stackentry($1, get_type(__INT), yylineno);
                                    if(pass_no == 2){
                                        $$->threeac = $1;
                                    } 
                                }
;

Fp_literal : FP_LITERAL     { 
                                    $$ = make_stackentry($1, get_type(__FLOAT), yylineno); 
                                    if(pass_no == 2){
                                        $$->threeac = $1;
                                    }
                                }
;

String : STRING             { 
                                    $$ = make_stackentry($1, yylineno); 
                                    if(pass_no == 2){
                                        $$->threeac = $1;
                                    }
                                }
;

Text_block : TEXT_BLOCK         { 
                                    $$ = make_stackentry($1, yylineno); 
                                    if(pass_no == 2){
                                        $$->threeac = $1;
                                    }
                                }
;

Identifier : IDENTIFIER         { 
                                    $$ = make_identifier($1);
                                }
;

endoffile : EOF_ { }

%%

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
    new_offset = 0;
    global_modifier = 0b0;
    global_type = NULL;
    current_class = NULL;
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
    cout << "Syntactic\t Lexeme \t Type \t Modifiers \t Line No \t Scope level\n";
    
    yylex_destroy();
    
    yyin = fopen(_args->input, "r");

    do {
        yyparse();
    } while(!feof(yyin));

    return 0;
 }

int yyerror(const char *s) {
    cerr << "syntax error: line " << yylineno << ": " << s << "\n";
    dotfile.close();
    exit(1);
}