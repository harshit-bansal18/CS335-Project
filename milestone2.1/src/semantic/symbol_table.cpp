#include <bits/stdc++.h>
#include <cstring> 

#include "symbol_table.hpp"
#include <sstream>

extern "C" int yylineno;
using namespace std;

int current_scope=0, offset=0;

// map< string, vector< stackentry* > > symmbol_table_pass1;
// map< string, vector< stackentry* > > symmbol_table_pass2;
map< string, class_struct* > symmbol_table_pass1;
// map< string, vector< stackentry* > > symmbol_table_pass2;
map< string, int > width; // Each entry for Class has class name as key and total width of instance variables as entries

vector< stackentry* > temp_stack,current_stack;
stringstream text;

int8_t global_modifier = 0b0;
int global_offset = 0;
string global_type = "";
string current_class = "";
string current_method = "";
int pass_no = 1;

int class_width = 0, function_width = 0;// if current scope is zero increment class offset, if 1 increment function offset

map <string, int> type_priority = {
                                        {__DOUBLE, 6},
                                        {__FLOAT, 5},
                                        {__LONG, 4},
                                        {__INT, 3},
                                        {__SHORT, 2},
                                        {__BYTE, 1},
                                        {__CHAR, 1},
                                        // {__NULL, 0},
                                        {__BOOLEAN, -1}
                                    };

map<string, int> offset_map ={{"none", 0}, 
                            {"int", 4}, 
                            {"long", 8}, 
                            {"byte", 1}, 
                            {"char", 1}, 
                            {"short", 1}, 
                            {"float", 4}, 
                            {"double", 8}, 
                            {"boolean", 1}};

struct stackentry* new_entry(){
            struct stackentry* entry = new stackentry();
            entry->token = "";
            entry->scope = 0;
            entry->modifier = (int8_t)0;
            entry->argument_type = "";
            entry->type = "";
            entry->nature = "";
            entry->variable_init_status = "";
            entry->offset = 0;
            entry->lineno = yylineno;
            return entry;
}

int8_t set_modifier(int8_t curr_modf, int8_t new_modf) {
    
    if (curr_modf & new_modf) {
        cerr << "Line No: " <<  yylineno  << "conflicting modifiers" << endl;
        exit(1); 
    }
    return (curr_modf | new_modf);
}

bool check_primitive_types(string type){
    if(type == __DOUBLE || type == __FLOAT || type == __LONG || type == __INT || type == __SHORT || type == __BYTE || type == __CHAR || type == __BOOLEAN )
        return true;
    else 
        return false;
};

bool check_if_numeric_type(string type){
    if(type == __DOUBLE || type == __FLOAT || type == __LONG || type == __INT || type == __SHORT || type == __BYTE || type == __CHAR)
        return true;
    else 
        return false;
}

bool check_return_type(string type1, string type2){

    if(check_primitive_types(type1) && check_primitive_types(type2)){
        // Check for boolean type
        if(type1 == __BOOLEAN && type2 != __BOOLEAN) 
            return 0;
        else if(type1 != __BOOLEAN && type2 == __BOOLEAN)
            return 0;
        else if(type1 == __BOOLEAN && type2 == __BOOLEAN)
            return 1;
        
        // double > float > long > int > short(!char) > byte/char/
        // boolean - Cannot be typecasted into anything (boolean = boolean only possible)

        int type1_prio = type_priority[type1];
        int type2_prio = type_priority[type2];

        if(type2_prio <= type1_prio) {
            if(type2 == __CHAR && type1 == __SHORT)
                return 0;
            
            return 1;
        }

        return 0;
    } else if(!(check_primitive_types(type1)) && !(check_primitive_types(type2))){
        // Means both are class objects
        if(type1 == type2)
            return 1;
        else return 0;
    }

    return 0;
    
}


string check_function_in_class( vector< stackentry* > &stack, string token, string argument_type, string nature){

    // cout << "In check function in class: " << yylineno  << " Func Name: " << token << " " << argument_type << " " << nature << "\n";

    int dot_count = 0, count = 0;
    for(int i = 0; i < token.size(); i++){
        if(token[i] == '.') dot_count ++;
    }

    const char* str = token.c_str();
    char* split_token = strtok((char*)str, ".");
    string type;
    stackentry* s ;


    // cout << "Dot count: " << dot_count << "Count: "<< count << "Split token: " << split_token << "\n";
    // cout << "Current Class: " << current_class << "\n";
    while(split_token != NULL) {
        if(count != dot_count){
            // cout << "#######################################\n";
            // dump_entry(stack);
            // cout << "#######################################\n";
            s = get_variable_stackentry(stack, (string)split_token);
            if(s->token == ""){
                cerr << "Line No: " <<  yylineno  << "No object found\n";
                exit(-1);
            }
            type = s->type;
            
            if(symmbol_table_pass1.find(type) == symmbol_table_pass1.end()) {
                cerr << "Line No: " <<  yylineno  << "Class of defined object does not exist\n";
                exit(-1);
            }

            stack = symmbol_table_pass1[type];
        } else {
            // cout << "In cond2\n";
            // dump_entry(stack);
            for( int i = stack.size()-1; i >= 0; i--) {
                // cout << split_token << " " <<stack[i]->token << " " << nature << " " << stack[i]->nature << " " <<  argument_type << " " << stack[i]->argument_type <<"\n";
                if(stack[i]!=NULL) {
                    if(stack[i]->token == split_token && stack[i]->nature==nature && stack[i]->argument_type == argument_type){
                        if(nature == CONSTRUCTOR)
                            return __VOID;
                        else
                            return stack[i]->type;
                    }  
                }
            }
            return "";
        }

        split_token = strtok(NULL, ".");
        count ++;
       
    }

    return 0;
}

////////////////////// Jaya Open //////////////////////////////////
stackentry* get_variable_stackentry(vector< stackentry* > &stack, string token) {
    for( int i = stack.size()-1; i >= 0; i--) {
        if(stack[i]->token == token && stack[i]->nature!=FUNCTION && stack[i]->nature!=CONSTRUCTOR){
            return stack[i];
        }
    }
    stackentry* empty = new_entry();
    return empty;
}

// Called when variable is used
stackentry* find_variable_in_class( vector< stackentry* > &stack, string token){
    
    cout << "in Find Variable: " << token << "\n"; 
    int dot_count = 0, count = 0;
    for(int i = 0; i < token.size(); i++){
        if(token[i] == '.') dot_count ++;
    }

    const char* str = token.c_str();
    char* split_token = strtok((char*)str, ".");
    string type;
    stackentry* s ;
    
    while(split_token != NULL) {
        if(count != dot_count){
            s = get_variable_stackentry(stack, split_token);
            if(s->token == ""){
                cerr << "Line No: " <<  yylineno << "No object found\n";
                exit(-1);
            }
            type = s->type;
            
            if(symmbol_table_pass1.find(type) == symmbol_table_pass1.end()) {
                cerr << "Line No: " <<  yylineno  << "Class of defined object does not exist\n";
                exit(-1);
            }

            stack = symmbol_table_pass1[type];
        } else {
            stackentry* s = get_variable_stackentry(stack, split_token);
            if(s->token == "") {
                cerr << "Line No: "<< yylineno << " Undeclared variable used\n";
                exit(-1);
            }

            return s;
        }
        split_token = strtok(NULL, ".");
        count ++;
    }

    return NULL;
}
////////////////////// Jaya Close /////////////////////////////////


// Function used when we need to add a new variable or declare a variable
bool find_variable_in_closest_function_scope( vector< stackentry* > &stack, string token, int scope ) {
    for( int i = stack.size()-1; i >= 0; i--) {
        if( stack[i]->nature != OPEN_FUNCTION && stack[i]->nature != OPEN_CONSTRUCTOR ) {
            if( stack[i]->token == token ) {
                return true;
            }
        }
        else {
            break;
        }
    }
    return false;
}

void add_to_stack( vector< stackentry* > &stack, string token, int scope, string type, int modifier, string nature, int offset, string argument_type, string variable_init_status) {
    stackentry* entry = new_entry();
    entry->token = token;
    entry->scope = scope;
    entry->type = type;
    entry->modifier = modifier;
    entry->nature = nature;
    entry->offset = offset_map[type];
    entry->argument_type = argument_type;
    entry->variable_init_status = variable_init_status;
    // entry->lineno = lineno;
    stack.push_back(entry);
}

void clear_scope( vector< stackentry* > &stack, int scope ) {

    // cout << "Current Scope: " << current_scope << "\n";
    // cout << "scope: " << scope << "\n"; 

    for( int i = stack.size()-1; i >= 0; i--) {
        if( stack[i]->scope == scope ) {
            stack.pop_back();
        }
        else{
            break;
        }
    }

}

class_struct* create_class_entry(int8_t modifier, string token) {

    class_struct* class_entry = new class_struct();
    class_entry->token = token;
    class_entry->scope = 0;              
    class_entry->modifier = modifier;           //public, private, static, final
    class_entry->nature = CLASS;          // class or function or variable etc.
    class_entry->offset = 0;
    class_entry->lineno = yylineno;
    class_entry->parent_class = NULL;

    class_entry->instance_variables.clear();
    class_entry->class_methods.clear();

    return class_entry;
}

void add_class(int8_t modifier, string token) {
   
    if(pass_no == 1){
        cout << "Pass: " << pass_no << "\n";
        dump_ST(1);
        if(symmbol_table_pass1.find(token) != symmbol_table_pass1.end()){
            cerr << "Line No: " <<  yylineno  << "Class Already present\n";
            exit(-1);
        }

        symmbol_table_pass1[token] = create_class_entry(modifier, token);
        text << token << "," << modifier << "," << "" << "," << "" << ","  << "Class" << "," << 0 << "," << yylineno << endl;
    }
}

void add_variable(string token, int8_t modifier, string type, bool init_flag){

    cout << "ADd Variable: " << token << endl;
    if(pass_no == 1){
        if(current_scope == 0){
            if(! find_variable_in_closest_function_scope(symmbol_table_pass1[current_class], token, current_scope))
                add_to_stack(symmbol_table_pass1[current_class], token, current_scope, type, modifier, VARIABLE, 0, "", __INITIALIZED);
            else {
                cerr << "Line No: " <<  yylineno  << "Variable already present\n";
                exit(-1);
            }
        }
    } else {
        if(! find_variable_in_closest_function_scope(symmbol_table_pass2[current_class], token, current_scope)) {
            if(current_scope == 0)
                add_to_stack(symmbol_table_pass2[current_class], token, current_scope, type, modifier, VARIABLE, 0, "", __INITIALIZED);
            else if(init_flag)
                add_to_stack(symmbol_table_pass2[current_class], token, current_scope, type, modifier, VARIABLE, 0, "", __INITIALIZED);
            else
                add_to_stack(symmbol_table_pass2[current_class], token, current_scope, type, modifier, VARIABLE, 0, "", __UNINITIALIZED);
        } else {
            cerr << "Line No: " <<  yylineno  << "Variable already present\n";
            exit(-1);
        }

        text << token << "," << modifier << "," << "" << "," << type << ","  << "Variable" << "," << offset << "," << yylineno << endl;
    }
    // cout << "Out of Add Variable\n";
}

void add_function(string token, string argument_type, string return_type, int8_t modifier) {

    cout << "Add Function: " << token << "\n";
    if(pass_no == 1){
        if(check_function_in_class(symmbol_table_pass1[current_class], token, argument_type, FUNCTION) != ""){
            cerr << "Line No: " <<  yylineno  << "Function already exists\n";
            exit(-1);
        }  
        else {
            add_to_stack(symmbol_table_pass1[current_class], token, current_scope, return_type, modifier, FUNCTION, 0, argument_type, "");
        }
    } else {
        if(check_function_in_class(symmbol_table_pass2[current_class], token, argument_type, FUNCTION) != ""){
            cerr << "Line No: " <<  yylineno  << "Function already exists\n";
            exit(-1);
        }
        else {
            add_to_stack(symmbol_table_pass2[current_class], token, current_scope, return_type, modifier, OPEN_FUNCTION, 0, argument_type, "");
        }

        text << token << "," << modifier << "," << argument_type << "," << return_type << ","  << "Function" << "," << 0 << "," << yylineno << endl;
    }

    // Add entries of temp_scope to actual scope
    current_scope++;
    for(int i=0; i<temp_stack.size(); i++) {
        add_variable(temp_stack[i]->token, temp_stack[i]->modifier, temp_stack[i]->type, 1);
    }
    current_scope--;
    temp_stack.clear();
    
}

void add_constructor(string token, string argument_type, string return_type, int8_t modifier, int scope) {

    cout << "Add Constructor: " << token << "\n";
    if(token != current_class) {
        /*Mismatch in current class name and constructor name*/
        cerr << "Line No: " <<  yylineno  << "Mismatch in current class name and constructor name\n";
        exit(-1);
    }

    if(pass_no == 1){
        if(check_function_in_class(symmbol_table_pass1[current_class], token, argument_type, CONSTRUCTOR) != ""){
            cerr << "Line No: " <<  yylineno  << "Constructor already exists\n";
            exit(-1);
        } else {
            add_to_stack(symmbol_table_pass1[current_class], token, current_scope, return_type, modifier, CONSTRUCTOR, 0, argument_type, "");
        }
    }    
    else {
        if(check_function_in_class(symmbol_table_pass2[current_class], token, argument_type, CONSTRUCTOR) != ""){
            cerr << "Line No: " <<  yylineno  << "Constructor already exists\n";
            exit(-1);
        } else {
             add_to_stack(symmbol_table_pass2[current_class], token, scope, return_type, modifier, OPEN_CONSTRUCTOR, 0, argument_type, "");
        }

        text << token << "," << modifier << "," << argument_type << "," << return_type << ","  << "Constructor" << "," << 0 << "," << yylineno << endl;
    }

    // Add entries of temp_scope to actual scope
    current_scope++;
    for(int i=0; i<temp_stack.size(); i++) {
        add_variable(temp_stack[i]->token, temp_stack[i]->modifier, temp_stack[i]->type, 1);
    }
    current_scope--;
    temp_stack.clear();
}

void dump_symbol(stackentry* v) {
    if(v == NULL)
        cout << "Null Pointer\n";
    else {
        cout << "\tToken: "<< v->token << "\n" 
            // << "\t: " << v->scope << "\n" 
            << "\tModifier: " << v->modifier << "\n" 
            << "\tArgument Type: " << v->argument_type << "\n" 
            << "\tType/Return Type: " << v->type << "\n" 
            << "\tNature: " << v->nature << "\n" 
            // << "\t: " << v->variable_init_status << "\n" 
            << "\tOffset: " << v->offset << "\n" 
            << "\tLineNo.: " << v->lineno << "\n\n"   ;
    }
}

void dump_entry(vector<stackentry*> vec){

    for(int j=0; j<vec.size(); j++){
        dump_symbol(vec[j]);
    }
}

void dump_ST(int num) {
    if(num == 1){
        vector<stackentry*> v;
        for (auto i : symmbol_table_pass1){
            cout << i.first << ":\n";
            v = i.second;
            dump_entry(v);
        }
    }
    else {
        vector<stackentry*> v;
        for (auto i : symmbol_table_pass2){
            cout << i.first << ":\n";
            v = i.second;
            dump_entry(v);
        }
    }
        
}

void dump_SS() {
    cout << "Token" << "," << "Modifier" << "," << "Argument_Type" << "," << "Type/Return Type" << "," << "Nature" << "," << "Offset" << "," << "Line Num" << "\n";
    cout << text.rdbuf();
}

void end_current_class(){
    width[current_class] = class_width;
    current_class = "";
    class_width = 0;
}

// void end_current_function(){
//     width[current_class+"."+current_method] = function_width;
//     current_method = "";
//     function_width = 0;
// }


/*

    // stackentry check_in_stack( vector< stackentry > stack, string token ) {
    //     for( int i = stack.size()-1; i >= 0; i--) {
    //         if( stack[i].token == token ) {
    //             return stack[i];
    //         }
    //     }
    //     stackentry empty = {};
    //     return empty;
    // }

    // bool find_variable_in_current_scope( vector< stackentry > &stack, string token, int scope ) {
    //     for( int i = stack.size()-1; i >= 0; i--) {
    //         if( stack[i].scope == scope ) {
    //             if( stack[i].token == token && stack[i].nature!="function" ) {
    //                 return true;
    //             }
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     return false;
    // }


    // bool check_in_current_scope( vector< stackentry > &stack, string token, int scope ) {
    //     for( int i = stack.size()-1; i >= 0; i--) {
    //         if( stack[i].scope == scope ) {
    //             if( stack[i].token == token ) {
    //                 return true;
    //             }
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     return false;
    // }


    // Function used for checking when variable is used

    // -----------MG---------------------

    // stackentry __find_variable_without_dot_in_class( vector< stackentry > &stack, string token){
    //     for( int i = stack.size()-1; i >= 0; i--) {
    //         if(stack[i].token == token && stack[i].nature!=FUNCTION && stack[i].nature!=CONSTRUCTOR ){
    //             return stack[i];
    //         }
    //     }
    //     stackentry empty = {};
    //     return empty;
    // }   

    // stackentry find_variable_in_class(vector< stackentry > &stack, string token){
    //     istringstream iss(token);
    //     std::vector<std::string> tkns;
    //     std::string tkn;
    //     while (std::getline(iss, tkn, '.')) {
    //         if (!tkn.empty())
    //             tkns.push_back(tkn);
    //     }
    //     return func2(stack, tkns);
    // }

    // stackentry func2(vector< stackentry > &stack, vector<string> tkns){
    //     if(tkns.size() == 1)
    //         return __find_variable_without_dot_in_class(stack, tkns[0]);
        
    //     stackentry s = __find_variable_without_dot_in_class(stack, tkns[0]);
    //     if(s.token == "") {
    //         exit(1);
    //     }
    //     else{
    //         tkns.erase(tkns.begin());
    //         stack = symmbol_table_pass1[s.type];
    //         return func2(stack, tkns);
    //     }
    // }

    // bool __check_function_without_dot_in_class(vector< stackentry > &stack, string token, string argument_type, string nature){
    //     for( int i = stack.size()-1; i >= 0; i--) {
    //         if(stack[i].token == token && stack[i].nature==nature && stack[i].argument_type == argument_type){
    //             return 1;
    //         }
    //     }
    //     return 0;
    // }

    // bool check_function_in_class(vector< stackentry > &stack, string token, string argument_type, string nature){
    //     istringstream iss(token);
    //     std::vector<std::string> tkns;
    //     std::string tkn;
    //     while (std::getline(iss, tkn, '.')) {
    //         if (!tkn.empty())
    //             tkns.push_back(tkn);
    //     }
    //     return func3(stack, tkns, argument_type, nature);
    // }

    // bool func3(vector< stackentry > &stack, vector<string> tkns, string argument_type, string nature){
    //     if(tkns.size() == 1)
    //         return __check_function_without_dot_in_class(stack, tkns[0], argument_type, nature);
        
    //     stackentry s = __find_variable_without_dot_in_class(stack, tkns[0]);
    //     if(s.token == "") {
    //         exit(1);
    //     }
    //     else{
    //         tkns.erase(tkns.begin());
    //         stack = symmbol_table_pass1[s.type];
    //         return func3(stack, tkns,  argument_type, nature);
    //     }
    // }

*/