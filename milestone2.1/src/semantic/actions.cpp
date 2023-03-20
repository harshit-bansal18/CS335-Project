#include "actions.hpp"

extern "C" int yylineno;
extern int current_scope, offset;

extern map< string, vector< stackentry* > > symmbol_table_pass1;
extern map< string, vector< stackentry* > > symmbol_table_pass2;

extern vector< stackentry* > temp_stack,current_stack;

extern int8_t global_modifier;
extern string global_type;
extern string current_class;
extern string current_method; 
extern int pass_no;

stackentry* ClassOrInterfaceType(stackentry* e1) {

    if(pass_no == 2) {
        if(symmbol_table_pass1.find(e1->token) == symmbol_table_pass1.end()) {
            cerr << "Line No: " << yylineno << " Class does not exist\n";
            exit(-1);
        }
    }

    stackentry* entry = new_entry();
    entry->type = e1->token;
    return entry;
}

stackentry* ArrayType(stackentry* e1, stackentry* e2, int rule_no) {

    if(rule_no == 2){
        if(pass_no == 2){
            if(symmbol_table_pass1.find(e1->token) == symmbol_table_pass1.end()){
                cerr << "Line No: " <<  yylineno <<"Error: Cannot find class "<<e1->token<<endl;
                exit(1);
            }
        }

        struct stackentry* entry = new_entry();
        entry->type = e1->type+e2->type; 
        return entry;
    }

    return NULL;
}

void VariableDeclarator(stackentry* e1, stackentry* e2, int rule_no) {
    
    if(rule_no == 1){
        add_variable(e1->token, global_modifier, e1->type, 1);
        if(e2->type == "") {
            // Means a empty array declaration: int a[] = {}; which is perfectly valid
            // Make its type same as (1)->type
            e2->type = e1->type;
        }

        if(pass_no == 2){
            if(!check_return_type(e1->type,e2->type)){
                cerr << "Line No: " <<  yylineno <<"Error: Cannot assign "<<e2->type<<" to "<<e1->type<<endl;
                exit(1);
            }
        }
    } else {
        add_variable(e1->token, global_modifier, e1->type, 0);
    }
}

void MethodDeclaration() {
    // cout << "In Method Declaration\n";
    if(pass_no == 1){
        int l = symmbol_table_pass1[current_class].size(); 
        symmbol_table_pass1[current_class][l-1]->nature = FUNCTION;
    } else {
        int l = symmbol_table_pass2[current_class].size(); 
        symmbol_table_pass2[current_class][l-1]->nature = FUNCTION;
    }
}

void ConstructorDeclaration() {
    if(pass_no == 1){
        int l = symmbol_table_pass1[current_class].size(); 
        symmbol_table_pass1[current_class][l-1]->nature = CONSTRUCTOR;
    } else {
        int l = symmbol_table_pass2[current_class].size(); 
        symmbol_table_pass2[current_class][l-1]->nature = CONSTRUCTOR;
    }
    
}

void IfCondition(stackentry* e1){
    if(pass_no == 2 ){
        if(e1->type!=__BOOLEAN){
            cerr << "Line No: " <<  yylineno <<"incompatible if argument types: "+ e1->type +" cannot be converted to boolean";
            exit(1);
        }
    } 
}

void AssertCondition(stackentry* e1) {
    if(pass_no == 2 ){
        if(e1->type!=__BOOLEAN){
            cerr << "Line No: " <<  yylineno <<"incompatible if argument types: "+ e1->type +" cannot be converted to boolean";
            exit(1);
        }
    }
}

void WhileCondition(stackentry* e1) {
    if(pass_no == 2 ){
        if(e1->type!=__BOOLEAN){
            cerr << "Line No: " <<  yylineno <<"incompatible if argument types: "+ e1->type +" cannot be converted to boolean";
            exit(1);
        }
    }
}

void ForCondition(stackentry* e1) {
    if(pass_no == 2){
        if(e1->type!=__BOOLEAN){
            cerr << "Line No: " <<  yylineno <<"incompatible if argument types: "+ e1->type +" cannot be converted to boolean";
            exit(1);
        }
    }
}

void EnhancedForCondition(stackentry* e1){
    if(pass_no == 2){
        string id = e1->type;
        if( !id[id.length() - 1]=='*' ){
            cerr << "Line No: " <<  yylineno <<"Array type must be pointer"<<endl;
            exit(1);
        }
    }
}