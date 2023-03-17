
#include <bits/stdc++.h>
#include <cstring> 

#include "symbol_table.hpp"

extern "C" int yylineno;
using namespace std;

int current_scope=0, offset=0;

map< string, vector< stackentry* > > symmbol_table_pass1;
map< string, vector< stackentry* > > symmbol_table_pass2;

vector< stackentry* > temp_stack,current_stack;

int8_t global_modifier;
string global_type;
string current_class = "";
string current_method = "";
int pass_no = 1;

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

        if(type2_prio < type1_prio) {
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

    const char* str = token.c_str();
    char* split_token = strtok((char*)str, ".");
    string type;
    stackentry* s ;
    int dot_count = 0, count = 0;

    for(int i = 0; i < token.size(); i++){
        if(token[i] == '.') dot_count ++;
    }

    while(split_token != NULL) {
        
        if(count != dot_count){
            s = get_variable_stackentry(stack, split_token);
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
            split_token = strtok(NULL, ".");
            count ++;
        } else {
            for( int i = stack.size()-1; i >= 0; i--) {
                if(stack[i]->token == token && stack[i]->nature==nature && stack[i]->argument_type == argument_type){
                    return stack[i]->type;
                }
            }
            return "";
        }
       
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

stackentry* find_variable_in_class( vector< stackentry* > &stack, string token){
    
    const char* str = token.c_str();
    char* split_token = strtok((char*)str, ".");
    string type;
    stackentry* s ;
    
    while(split_token != NULL) {
        
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
        split_token = strtok(NULL, ".");
    }

    return s;
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

void clear_current_scope( vector< stackentry* > &stack, int scope ) {
    for( int i = stack.size()-1; i >= 0; i--) {
        if( stack[i]->scope == scope ) {
            stack.pop_back();
        }
        else{
            break;
        }
    }
}

void add_class(int8_t modifier, string token) {
   
    if(pass_no == 1){
        if(symmbol_table_pass1.find(token) != symmbol_table_pass1.end()){
            cerr << "Line No: " <<  yylineno  << "Class Already present\n";
            exit(-1);
        }

        vector <stackentry*> class_data;
        symmbol_table_pass1[token] = class_data;
    } else {
        // Just a sanity check, duplicated classes is checked in the first pass, hence this condition will never fail in pass2.

        if(symmbol_table_pass2.find(token) != symmbol_table_pass2.end()){
            cerr << "Line No: " <<  yylineno  << "Class Already present\n";
            exit(-1);
        }
        
        vector <stackentry*> class_data;
        symmbol_table_pass2[token] = class_data;
    }
        
}

void add_variable(string token, int8_t modifier, string type, bool init_flag){

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
    }
}

void add_function(string token, string argument_type, string return_type, int8_t modifier) {
    if(check_function_in_class(symmbol_table_pass1[current_class], token, argument_type, FUNCTION) != ""){
        cerr << "Line No: " <<  yylineno  << "Function already exists\n";
        exit(-1);
    } else {
        if(pass_no == 1)
            add_to_stack(symmbol_table_pass1[current_class], token, current_scope, return_type, modifier, OPEN_FUNCTION, 0, argument_type, "");
        else 
            add_to_stack(symmbol_table_pass2[current_class], token, current_scope, return_type, modifier, OPEN_FUNCTION, 0, argument_type, "");

        // Add entries of temp_scope to actual scope
        current_scope++;
        for(int i=0; i<temp_stack.size(); i++) {
            add_variable(temp_stack[i]->token, temp_stack[i]->modifier, temp_stack[i]->type, 1);
        }
        current_scope--;
        temp_stack.clear();
    }
}

void add_constructor(string token, string argument_type, string return_type, int8_t modifier, int scope) {

    if(token != current_class) {
        /*Mismatch in current class name and constructor name*/
        cerr << "Line No: " <<  yylineno  << "Mismatch in current class name and constructor name\n";
        exit(-1);
    }

    if(check_function_in_class(symmbol_table_pass1[current_class], token, argument_type, CONSTRUCTOR) != ""){
        cerr << "Line No: " <<  yylineno  << "Constructor already exists\n";
        exit(-1);
    } else {
        if(pass_no == 1)
            add_to_stack(symmbol_table_pass1[current_class], token, scope, return_type, modifier, OPEN_CONSTRUCTOR, 0, argument_type, "");
        else 
            add_to_stack(symmbol_table_pass2[current_class], token, scope, return_type, modifier, OPEN_CONSTRUCTOR, 0, argument_type, "");
            
        // Add entries of temp_scope to actual scope
        current_scope++;
        for(int i=0; i<temp_stack.size(); i++) {
            add_variable(temp_stack[i]->token, temp_stack[i]->modifier, temp_stack[i]->type, 1);
        }
        current_scope--;
        temp_stack.clear();
    }
}


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