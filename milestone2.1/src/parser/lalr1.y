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

    static int node_num=-1, scope=0;

    ofstream dotfile;

    int yyerror(const char *);



    struct stackentry {
        string token;           //key
        int scope;      
        int modifier;           //public, private, static, final
        string argument_type;   //argument list of function
        string type;            // type for variable and return type for function
        string nature;          // class or function or variable etc.
        int offset;
        int lineno;
    };

    string current_class="";




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

%}

%define parse.error verbose

%union {
    int num;
    double float_num;
    char* str;
    struct stackentry stack_entry;
}

%token<str> INT LONG BYTE CHAR SHORT FLOAT DOUBLE BOOLEAN VAR IF ELSE FOR WHILE BREAK CONTINUE VOID NEW RETURN PUBLIC PRIVATE CLASS STATIC FINAL SWITCH YIELD CATCH FINALLY SYNCHRONIZED ASSERT PLUS MINUS DIV MODULO INCREMENT DECREMENT GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_COMPLEMENT LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT AND OR NOT ASSIGNMENT ASSIGN COLON QM LPAREN RPAREN LCURLY RCURLY LSQUARE RSQUARE SEMICOLON COMMA DOT ARROW CHAR_LITERAL BOOLEAN_LITERAL NULL_LITERAL INTEGER_LITERAL FP_LITERAL STRING TEXT_BLOCK IDENTIFIER THIS INSTANCEOF SUPER THROW THROWS EOF_ IMPLEMENTS INTERFACE EXTENDS PACKAGE IMPORT ASTERIK DO TRY CASE DEFAULT

%left INCREMENT DECREMENT NOT BITWISE_COMPLEMENT ASTERIK DIV MODULO PLUS MINUS LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT  GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_XOR BITWISE_OR AND OR

%right ASSIGNMENT ASSIGN

%type<stack_entry> Program CompilationUnit ClassOrInterfaceDeclaration ClassOrInterfaceDeclarations PackageDeclaration ImportDeclaration Literal UnannType PrimitiveType NumericType IntegralType FloatingPointType ReferenceType  ClassOrInterfaceType ArrayType Dims TypeName Modifiers ClassDeclaration super_ Interfaces InterfaceTypeList ClassBody ClassBodyDeclarations ClassBodyDeclaration ClassMemberDeclaration FieldDeclaration VariableDeclaratorList VariableDeclarator VariableDeclaratorId VariableInitializer MethodDeclaration MethodHeader Declarator FormalParameterList FormalParameter MethodBody StaticInitializer ConstructorDeclaration ConstructorBody ExplicitConstructorInvocation ArrayInitializer VariableInitializerList InterfaceDeclaration InterfaceExtends InterfaceBody InterfaceMembers InterfaceMemberDeclaration InterfaceMethodDeclaration Primary PrimaryNoNewArray ClassInstanceCreationExpression FieldAccess ArrayAccess MethodInvocation ArgumentList ArrayCreationExpression DimExprs DimExpr Expression AssignmentExpression Assignment Assign LeftHandSide AssignmentOperator ConditionalExpression ConditionalOrExpression ConditionalAndExpression InclusiveOrExpression ExclusiveOrExpression AndExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression UnaryExpression PreIncrementExpression PreDecrementExpression UnaryExpressionNotPlusMinus PostfixExpression PostIncrementExpression PostDecrementExpression CastExpression Block BlockStatements BlockStatement Statement StatementNoShortIf StatementWithoutTrailingSubstatement EmptyStatement LabeledStatement LabeledStatementNoShortIf ExpressionStatement StatementExpression IfThenElseStatement IfThenElseStatementNoShortIf AssertStatement WhileStatement WhileStatementNoShortIf ForStatement ForStatementNoShortIf BasicForStatement BasicForStatementNoShortIf ForInit ForUpdate StatementExpressionList CommaStatementExpressions EnhancedForStatement EnhancedForStatementNoShortIf BreakStatement ContinueStatement ReturnStatement ThrowStatement IfThenStatement LocalVariableDeclaration LocalVariableDeclarationStatement Super Int Long Byte Char Short Float Double Boolean Var If Else For While Break Continue Void New Return Class Assert Plus Minus Div Modulo Increment Decrement Geq Leq Gt Lt Neq Deq Bitwise_and Bitwise_or Bitwise_xor Bitwise_complement Left_shift Right_shift Unsigned_right_shift And Or Not Colon Qm Lparen Rparen Lcurly Rcurly Lsquare Rsquare Semicolon Comma Dot This Instanceof Throw Implements Interface Extends Package Import Asterik SynchronizedStatement DoStatement TryStatement YieldStatement SwitchBlock SwitchBlockStatementGroup SwitchBlockStatementGroups SwitchLabel SwitchLabelColons SwitchRule SwitchRules SwitchStatement CatchClause Catches CatchFormalParameter CatchType Finally CaseConstant CaseConstants do_ switch_ yield_ try_ catch_ finally_ synchronized_ throws_ case_ default_ arrow_ endoffile ImportDeclarations Throws ExceptionType ExceptionTypeList CommaExceptionTypes Char_literal Boolean_literal Null_literal Integer_literal Fp_literal String Text_block Identifier Public Private Static Final Modifier

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
|   InterfaceDeclaration  { }
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
    // TypeName     {  }
    Identifier      { 
                        if(symmbol_table_pass1.find(($1).token) == symmbol_table_pass1.end()){
                            cerr<<"Error: Cannot find class "<<($1).token<<endl;
                            exit(1);
                        }
                        ($$).type = ($1).token;
                    }
;


ArrayType:
    PrimitiveType Dims { ($$).type = ($1).type+($2).type; }
// |   TypeName Dims    { ($$).type}
|   Identifier Dims {  
                        if(symmbol_table_pass1.find(($1).token) == symmbol_table_pass1.end()){
                            cerr<<"Error: Cannot find class "<<($1).token<<endl;
                            exit(1);
                        }
                        ($$).type = ($1).token + ($2).type; 
                    }
;

Dims:
    Lsquare Rsquare Dims  { ($$).type = ($3).type + "*";}
|   Lsquare Rsquare  { ($$).type = "*";  }
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
                    
                }
|   TypeName Dot Identifier { 
                                $$ = find_field_in_class(symmbol_table_pass1[($1).type], ($3).token);
                                if($$.token == ""){
                                    cerr<<"Error: Cannot find field "<<($3).token<<" in class "<<symmbol_table_pass1[($1).type].name<<endl;
                                    exit(1);
                                }
                            }
;


/**************************************/


Modifiers:
    Modifier { ($$).modifier =  set_modifier(0, ($1).modifier);}
|   Modifiers Modifier { ($$).modifier =  set_modifier(($1).modifier, ($2).modifier); }
;

// *************Need to confirm it *******
Modifier:
    Public      { $$.modifier = __PUBLIC; } 
|   Private     { $$.modifier = __PRIVATE; }
|   Static      { $$.modifier = __STATIC; }
|   Final       { $$.modifier = __FINAL; }
;

/*
    Productions from Chapter 8 (Classes)
    
*/


ClassDeclaration:
    Modifiers Class Identifier {add_class(($1).modifier, ($3).token); current_class = ($3).token } ClassBody { current_class = ""; }
|   Class Identifier {add_class(0b0, ($2).token);} ClassBody { }
;

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
|   InterfaceDeclaration { }
;

FieldDeclaration:
    Modifiers {global_modifier = ($1).modifier;} UnannType {global_type = ($2).type;} VariableDeclaratorList Semicolon { global_modifier = ""; global_type =""; }
|   UnannType {global_type = ($1).type;} VariableDeclaratorList Semicolon { global_modifier = ""; global_type =""; }
;

VariableDeclaratorList:
    VariableDeclaratorList Comma VariableDeclarator {}
|   VariableDeclarator { }
;

VariableDeclarator:
    VariableDeclaratorId Assign VariableInitializer { 
                                                        add_variable(($1).token, global_modifier, ($1).type);
                                                        if(!check_return_type(($1).type),($2).type){
                                                            cerr<<"Error: Cannot assign "<<($2).type<<" to "<<($1).type<<endl;
                                                            exit(1);
                                                        }
                                                    }
|   VariableDeclaratorId { 
                            add_variable(($1).token, global_modifier, ($1).type); 
                         }
;

VariableDeclaratorId:
    VariableDeclaratorId  Lsquare Rsquare { 
                                            ($$).token = ($1).token;
                                            ($$).type = ($1).type + "*";
                                          }
|   Identifier { 
                    ($$).type = global_type;
                    ($$).token = ($1).token;
                }
;

VariableInitializer:
    Expression { $$ = $1; }
|   ArrayInitializer { $$ = $1; }
;

//  ----------------------Continue---------------------------


MethodDeclaration:
    MethodHeader {
                    add_function(($1).token, ($1).argument_type, ($1).type, ($1).modifier);
                    
                } MethodBody { }
;

MethodHeader:
    Modifiers UnannType Declarator      { 
                                            ($$).modifier = ($1).modifier; 
                                            ($$).type = ($2).type; 
                                            ($$).token = ($3).token; 
                                            ($$).argument_type = ($3).argument_type;
                                        }
|   UnannType Declarator                  { 
                                            ($$).type = ($1).type; 
                                            ($$).token = ($2).token; 
                                            ($$).argument_type = ($2).argument_type;
                                          }
|   Modifiers Void Declarator             { 
                                            ($$).modifier = ($1).modifier; 
                                            ($$).type = "void"; 
                                            ($$).token = ($3).token; 
                                            ($$).argument_type = ($3).argument_type;
                                          }
|   Void Declarator                       { 
                                            ($$).modifier = ($1).modifier; 
                                            ($$).type = ($2).type; 
                                            ($$).token = ($3).token; 
                                            ($$).argument_type = ($3).argument_type;
                                          }
|   Modifiers UnannType Declarator Throws { 
                                            ($$).modifier = ($1).modifier; 
                                            ($$).type = ($2).type; 
                                            ($$).token = ($3).token; 
                                            ($$).argument_type = ($3).argument_type;
                                          }
|   UnannType Declarator Throws           { 
                                            ($$).modifier = ($1).modifier; 
                                            ($$).type = ($2).type; 
                                            ($$).token = ($3).token; 
                                            ($$).argument_type = ($3).argument_type;
                                          }
|   Modifiers Void Declarator Throws      { 
                                            ($$).modifier = ($1).modifier; 
                                            ($$).type = ($2).type; 
                                            ($$).token = ($3).token; 
                                            ($$).argument_type = ($3).argument_type;
                                          }
|   Void Declarator Throws                { 
                                            ($$).modifier = ($1).modifier; 
                                            ($$).type = ($2).type; 
                                            ($$).token = ($3).token; 
                                            ($$).argument_type = ($3).argument_type;
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
    Identifier { ($$).scope = current_scope; ($$).token =($1).token; } Lparen {current_scope++;} Rparen {current_scope--;} 
|   Identifier { ($$).scope = current_scope; ($$).token =($1).token; } Lparen {current_scope++;} FormalParameterList { ($$).argument_type = ($3).argument_type; } Rparen {current_scope--;}
;

FormalParameterList:
    FormalParameterList Comma FormalParameter {  }
|   FormalParameter { }
;

FormalParameter:
    UnannType {global_type = ($1).type;} VariableDeclaratorId { 
                                                                    global_type = ""; 
                                                                    ($$).argument_type = ($2).type;
                                                                    // add_variable(($2).token, "", ($2).type);
                                                                    temp_stack.push_back($2);
                                                               } 
;


MethodBody:
    Block { }
;

StaticInitializer:
    Static Block { }
;

ConstructorDeclaration:
    Modifiers Declarator ConstructorBody { }
|   Declarator ConstructorBody { }
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
|   Lcurly ExplicitConstructorInvocation BlockStatements Rcurly { }
|   Lcurly ExplicitConstructorInvocation Rcurly { }
|   Lcurly Rcurly { }
;

ExplicitConstructorInvocation:
    This Lparen Rparen { }
|   This Lparen ArgumentList Rparen { }
|   super_ Lparen Rparen { }
|   super_ Lparen ArgumentList Rparen { }
;

ArrayInitializer:
    Lcurly VariableInitializerList Rcurly { }
|   Lcurly Rcurly { }
|   Lcurly VariableInitializerList Comma Rcurly { }
|   Lcurly Comma Rcurly { }
;

VariableInitializerList:
    VariableInitializerList Comma VariableInitializer { }
|   VariableInitializer { }
;

/*     Productions from Chapter 9 - Interfaces      */

InterfaceDeclaration:
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
;

/*
    Productions from Chapter 15 (Expressions)
*/
// Java Expressions Grammer

Primary:    PrimaryNoNewArray { $$ = $1; }
|           ArrayCreationExpression { $$ = $1; }
;

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
                                                ($$).type = ($2).type; 
                                            }
|   New ClassOrInterfaceType Lparen ArgumentList Rparen {
                                                            ($$).type = ($2).type;

                                                            if(!check_function_in_class(symmbol_table_pass1[($2).token], ($2).token, ($4).type, "null", "function") ){
                                                                cerr<<"Unknown constructor used"<<endl;
                                                                exit(1);
                                                            }
                                                        }
;

FieldAccess:    Primary Dot Identifier  { 
                                            $$=find_field_in_class(symmbol_table_pass1[($1).type],$3)
                                        }
|               super_ Dot Identifier { }
|               TypeName Dot super_ Dot Identifier { }
;

ArrayAccess:    TypeName Lsquare Expression Rsquare { 
                                                        if( !($3).type = "int" ){
                                                            cerr<<"Array index must be integer"<<endl;
                                                            exit(1);
                                                        }
                                                        string id = ($1).type;
                                                        int l = id.length();
                                                        if( !id[l-1]=='*' ){
                                                            cerr<<"Array type must be pointer"<<endl;
                                                            exit(1);
                                                        }
                                                        id = id.substr(0, l-1);
                                                        ($$).type = id;
                                                    }
|               PrimaryNoNewArray Lsquare Expression Rsquare    { 
                                                                    if( !($3).type = "int" ){
                                                                        cerr<<"Array index must be integer"<<endl;
                                                                        exit(1);
                                                                    }
                                                                    string id = ($1).type;
                                                                    int l = id.length();
                                                                    if( !id[l-1]=='*' ){
                                                                        cerr<<"Array type must be pointer"<<endl;
                                                                        exit(1);
                                                                    }
                                                                    id = id.substr(0, l-1);
                                                                    ($$).type = id;
                                                                }
;
// A -> B Lsquare C Rsquare    $$.type = $1.type + "*"      $3.type = "int"

MethodInvocation:   TypeName Lparen Rparen { }
|                   TypeName Lparen ArgumentList Rparen { }
|                   Primary Dot Identifier Lparen Rparen { }
|                   Primary Dot Identifier Lparen ArgumentList Rparen { }
|                   super_ Dot Identifier Lparen Rparen { }
|                   super_ Dot Identifier Lparen ArgumentList Rparen { }
;
// A -> B Lparen Rparen    $$.type = $1.type    $1.nature = "function"     $1.argtype = ""
// A -> B Lparen C Rparen      $$.type = $1.type    $1.nature = "function"     $1.argtype = $3.type   This argtype will be string concatenation of arguments type with a " , " in between
// A -> B Dot C Lparen D Rparen    $$.type = $3.type    $1.nature = "class"    $3.nature = "function"    $3.argtype = $5.type
// A -> B Dot C Lparen Rparen    $$.type = $3.type    $1.nature = "class"    $3.nature = "function"    $3.argtype = ""

ArgumentList:       Expression  { }
|                   ArgumentList Comma Expression { }
;
// A -> B Comma C    $$.argtype = $1.argtype + " , " + $3.type

ArrayCreationExpression:    New PrimitiveType DimExprs Dims { }
|                           New ClassOrInterfaceType DimExprs Dims { }
|                           New PrimitiveType DimExprs { }
|                           New ClassOrInterfaceType DimExprs{ }
|                           New PrimitiveType Dims ArrayInitializer { }
|                           New ClassOrInterfaceType Dims ArrayInitializer { }
;
// ArrayCreationExpression -> new B C ArrayInitializer    $$.type = $2.type + ("*")*(stringtoint($3.type))
// ArrayCreationExpression -> new B C     $$.type = $2.type + ("*")*(stringtoint($3.type))
// ArrayCreationExpression -> new B C D    $$.type = $2.type + ("*")*(stringtoint($3.type) + stringtoint($3.type))


DimExprs:   DimExpr  { }
|           DimExprs DimExpr { }
;
// A -> B C    $$.type = $1.type + $2.type 

DimExpr:    Lsquare Expression Rsquare { }
;
// A -> Lsquare B Rsquare      $$.type = "*"

Expression:  AssignmentExpression { }

AssignmentExpression:   
    ConditionalExpression { }
|   Assignment { }
;

Assignment:
    LeftHandSide AssignmentOperator Expression  { }
    LeftHandSide Assign Expression              { }
;

LeftHandSide:
    TypeName { }
|   FieldAccess { }
|   ArrayAccess { }
;

ConditionalExpression:  ConditionalOrExpression { }
|                   ConditionalOrExpression Qm Expression Colon ConditionalExpression { } //Check Again
;

ConditionalOrExpression:    ConditionalAndExpression { }
|                   ConditionalOrExpression Or ConditionalAndExpression { }
;

ConditionalAndExpression:   InclusiveOrExpression { }
|                   ConditionalAndExpression And InclusiveOrExpression  { }
;

InclusiveOrExpression:  ExclusiveOrExpression { }
|                   InclusiveOrExpression Bitwise_or ExclusiveOrExpression  { }
;

ExclusiveOrExpression:  AndExpression   { }
|                   ExclusiveOrExpression Bitwise_xor AndExpression     { }
;

AndExpression:  EqualityExpression  { }
|                   AndExpression Bitwise_and EqualityExpression    { }
;

EqualityExpression: RelationalExpression { }
|                   EqualityExpression Deq RelationalExpression     { }
|                   EqualityExpression Neq RelationalExpression     { }
;

RelationalExpression:   ShiftExpression { }
|                   RelationalExpression Lt ShiftExpression         { }
|                   RelationalExpression Gt ShiftExpression         { }
|                   RelationalExpression Leq ShiftExpression        { }
|                   RelationalExpression Geq ShiftExpression        { }
|                   RelationalExpression Instanceof ReferenceType   { }
;

ShiftExpression:    AdditiveExpression { }
|                   ShiftExpression Left_shift AdditiveExpression   { }
|                   ShiftExpression Right_shift AdditiveExpression  { }
|                   ShiftExpression Unsigned_right_shift AdditiveExpression     { }
;

AdditiveExpression: MultiplicativeExpression { }
|                   AdditiveExpression Plus MultiplicativeExpression    { } 
|                   AdditiveExpression Minus MultiplicativeExpression   { }
;

MultiplicativeExpression:   UnaryExpression                             { }
|                   MultiplicativeExpression Asterik UnaryExpression    { }
|                   MultiplicativeExpression Div UnaryExpression        { }
|                   MultiplicativeExpression Modulo UnaryExpression     { }
;

UnaryExpression:    PreIncrementExpression      { }
|                   PreDecrementExpression      { }
|                   Plus UnaryExpression        { }
|                   Minus UnaryExpression       { }
|                   UnaryExpressionNotPlusMinus { }
;

PreIncrementExpression: Increment Primary       { }
|                       Increment TypeName      { }
;

PreDecrementExpression: Decrement Primary   { }
|                       Decrement TypeName  { }
;

UnaryExpressionNotPlusMinus:    PostfixExpression                   { }
|                               Bitwise_complement UnaryExpression  { }
|                               Not UnaryExpression                 { }
|                               CastExpression                      { }
;

PostfixExpression:  Primary                 { }
|                   TypeName                { }
|                   PostIncrementExpression { }
|                   PostDecrementExpression { }
;

PostIncrementExpression:    Primary Increment   { }
|                           TypeName Increment  { }
;

PostDecrementExpression:    Primary Decrement   { }
|                           TypeName Decrement  { }
;

CastExpression:     Lparen PrimitiveType Rparen UnaryExpression                 { }
|                   Lparen ReferenceType Rparen UnaryExpressionNotPlusMinus     { }
;


Block:    Lcurly Rcurly                 { }
|         Lcurly BlockStatements Rcurly { }
;

BlockStatements:    BlockStatements BlockStatement  { }
|                   BlockStatement                  { }
;

BlockStatement:
                    ClassOrInterfaceDeclaration { }
|                   LocalVariableDeclarationStatement   { }
|                   Statement   { }
;

LocalVariableDeclarationStatement:    LocalVariableDeclaration  Semicolon { }
;

LocalVariableDeclaration:    UnannType VariableDeclaratorList   { }
|                            Var       VariableDeclaratorList   { }
|                            Final UnannType VariableDeclaratorList { }
|                            Final  Var     VariableDeclaratorList  { }
;


Statement:          StatementWithoutTrailingSubstatement    { }
|                   LabeledStatement    { }
|                   IfThenStatement   { }
|                   IfThenElseStatement  { }
|                   WhileStatement  { }
|                   ForStatement    { }
;

StatementNoShortIf:     StatementWithoutTrailingSubstatement    { }
|                       LabeledStatementNoShortIf   { }
|                       IfThenElseStatementNoShortIf    { }
|                       WhileStatementNoShortIf { }
|                       ForStatementNoShortIf   { }
;

StatementWithoutTrailingSubstatement:   Block   { }
|                                       EmptyStatement  { }
|                                       ExpressionStatement { }
|                                       AssertStatement { }
|                                       BreakStatement  { }
|                                       ContinueStatement   { }
|                                       ReturnStatement { }
|                                       ThrowStatement  { }
|                                       SwitchStatement  { }
|                                       DoStatement   { }
|                                       SynchronizedStatement { }
|                                       YieldStatement  { }
|                                       TryStatement  { }
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

ExpressionStatement:    StatementExpression Semicolon   { }

StatementExpression:    Assignment  { }
|                       PreIncrementExpression  { }
|                       PreDecrementExpression  { }
|                       PostIncrementExpression { }
|                       PostDecrementExpression { }
|                       MethodInvocation        { }
|                       ClassInstanceCreationExpression  { }

IfThenStatement:    If Lparen Expression Rparen Statement   { }
;

IfThenElseStatement:    If Lparen Expression Rparen StatementNoShortIf Else Statement   { }
;

IfThenElseStatementNoShortIf:    If Lparen Expression Rparen StatementNoShortIf Else StatementNoShortIf  { }
;

AssertStatement:    Assert Expression Semicolon  { }
|                   Assert Expression Colon Expression Semicolon    { }
;

SwitchStatement:
                    switch_ Lparen Expression Rparen SwitchBlock    { }

SwitchBlock:
                    Lcurly SwitchRules Rcurly                       { }
|                   Lcurly SwitchBlockStatementGroups SwitchLabelColons Rcurly  { }
|                   Lcurly SwitchBlockStatementGroups Rcurly                { }
|                   Lcurly SwitchLabelColons Rcurly                         { }
|                   Lcurly Rcurly                                           { }
;

SwitchRules:
                    SwitchRules SwitchRule                                  { }
|                   SwitchRule                                              { }
;

SwitchRule:
                    SwitchLabel arrow_ Expression Semicolon                 { }
|                   SwitchLabel arrow_ Block                                { }
|                   SwitchLabel arrow_ ThrowStatement                       { }
;

SwitchBlockStatementGroups:
                    SwitchBlockStatementGroups SwitchBlockStatementGroup    { }
|                   SwitchBlockStatementGroup                               { }
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

WhileStatement:    While Lparen Expression Rparen Statement         { }
;

WhileStatementNoShortIf:    While Lparen Expression Rparen StatementNoShortIf   { }
;

DoStatement:
    do_ Statement While Lparen Expression Rparen Semicolon                  { }
;

ForStatement:       BasicForStatement   { }
|                   EnhancedForStatement    { }
;

ForStatementNoShortIf:    BasicForStatementNoShortIf    { }
|                   EnhancedForStatementNoShortIf   { }
;

BasicForStatement:     For Lparen Semicolon Semicolon Rparen Statement  { }
|                      For Lparen ForInit Semicolon Semicolon Rparen Statement  { }
|                      For Lparen Semicolon Expression Semicolon Rparen Statement  { }
|                      For Lparen Semicolon Semicolon ForUpdate Rparen Statement  { }
|                      For Lparen ForInit Semicolon Expression Semicolon Rparen Statement  { }
|                      For Lparen Semicolon Expression Semicolon ForUpdate Rparen Statement  { }
|                      For Lparen ForInit Semicolon Semicolon ForUpdate Rparen Statement  { }
|                      For Lparen ForInit Semicolon Expression Semicolon ForUpdate Rparen Statement  { }
;

BasicForStatementNoShortIf:    For Lparen Semicolon Semicolon Rparen StatementNoShortIf  { }
|                      For Lparen ForInit Semicolon Semicolon Rparen StatementNoShortIf  { }
|                      For Lparen Semicolon Expression Semicolon Rparen StatementNoShortIf  { }
|                      For Lparen Semicolon Semicolon ForUpdate Rparen StatementNoShortIf  { }
|                      For Lparen ForInit Semicolon Expression Semicolon Rparen StatementNoShortIf  { }
|                      For Lparen Semicolon Expression Semicolon ForUpdate Rparen StatementNoShortIf  { }
|                      For Lparen ForInit Semicolon Semicolon ForUpdate Rparen StatementNoShortIf  { }
|                      For Lparen ForInit Semicolon Expression Semicolon ForUpdate Rparen StatementNoShortIf  { }
;

ForInit:    StatementExpressionList { }
|           LocalVariableDeclaration    { }
;

ForUpdate:    StatementExpressionList   { }
;

StatementExpressionList:    StatementExpression { }
|                           StatementExpression CommaStatementExpressions   { }
;

CommaStatementExpressions:   Comma StatementExpression CommaStatementExpressions    { }
|                            Comma StatementExpression  { }
;

EnhancedForStatement:    For Lparen LocalVariableDeclaration Colon Expression Rparen Statement  { }
;

EnhancedForStatementNoShortIf:    For Lparen LocalVariableDeclaration Colon Expression Rparen StatementNoShortIf    { }
;

BreakStatement:    Break Identifier Semicolon   { }
|                  Break Semicolon   { }
;

YieldStatement:     yield_ Expression Semicolon     { }
;

ContinueStatement:    Continue Identifier Semicolon  { }
|                     Continue Semicolon  { }
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

Int : INT { }
;

Long : LONG { }
;

Byte : BYTE { }
;

Short : SHORT { }
;

Char : CHAR { }
;

Float : FLOAT { }
;

Double : DOUBLE { }
;

Boolean : BOOLEAN { }
;

Var : VAR { }
;

If : IF { }
;

Else : ELSE { }
;

While : WHILE { }
;

For : FOR { }
;


Break : BREAK { }
;

Continue : CONTINUE { }
;

Void : VOID { }
;

New : NEW { }
;

Return : RETURN { }
;

Public : PUBLIC { }
;

Private : PRIVATE { }
;

Class : CLASS { }
;

Static : STATIC { }
;

Final : FINAL { }
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

Implements : IMPLEMENTS { }
;

Interface : INTERFACE { }
;

Extends : EXTENDS { }
;

Package : PACKAGE { }
;

Import : IMPORT { }
;

do_: DO { }

switch_ : SWITCH { }

yield_ : YIELD  { }

try_ : TRY { }

throws_ : THROWS { }

catch_ : CATCH { }

finally_ : FINALLY { }

synchronized_ : SYNCHRONIZED { }

case_ : CASE { }

default_ : DEFAULT { }

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

arrow_ : ARROW { }

Char_literal : CHAR_LITERAL { }
;

Boolean_literal : BOOLEAN_LITERAL { }
;

Null_literal : NULL_LITERAL { }
;

Integer_literal : INTEGER_LITERAL { }
;

Fp_literal : FP_LITERAL { }
;

String : STRING { }
;

Text_block : TEXT_BLOCK { }
;

Identifier : IDENTIFIER { }
;

endoffile : EOF_ { }

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