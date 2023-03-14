#include <bits/stdc++.h>

using namespace std;

struct stackentry {
    string token;           //key
    int scope;              
    int8_t modifier;           //public, private, static, final
    string argument_type;   //argument list of function
    string type;            // type for variable and return type for function
    string nature;          // class or function or variable etc.
    int offset;
    int lineno;
};

int current_scope=0, offset=0;

map< string, vector< stackentry > > symmbol_table_pass1;
map< string, vector< stackentry > > symmbol_table_pass2;

vector< stackentry > temp_stack;

int8_t global_modifier;
string global_type;
string current_class = "";
string current_method = "";

#define VARIABLE "variable"
#define FUNCTION "function"
#define OPEN_FUNCTION "open_function"

#define __PUBLIC 0b11
#define __PRIVATE 0b10
#define __STATIC 0b100
#define __ABSTRACT 0b1000

int8_t set_modifier(int8_t curr_modf, int8_t new_modf) {
    
    if (curr_modf & new_modf) {
        cerr << "conflicting modifiers" << endl;
        exit(1); 
    }
    return (curr_modf | new_modf);
}

map<string, int> offset_map ={{"none", 0}, 
                            {"int", 4}, 
                            {"long", 8}, 
                            {"byte", 1}, 
                            {"char", 1}, 
                            {"short", 1}, 
                            {"float", 4}, 
                            {"double", 8}, 
                            {"boolean", 1}};

bool check_return_type(string type1, string type2){
    if(type1==type2)    return 1;
    else                return 0;
}

bool check_function_in_class( vector< stackentry > &stack, string token, string argument_type, string return_type){
    for( int i = stack.size()-1; i >= 0; i--) {
        if(stack[i].token == token && stack[i].argument_type == argument_type && stack[i].type == return_type && stack[i].nature==FUNCTION){
            return 1;
        }
    }
    return 0;
}

stackentry find_variable_in_class( vector< stackentry > &stack, string token){
    for( int i = stack.size()-1; i >= 0; i--) {
        if(stack[i].token == token && stack[i].nature!="function"){
            return stack[i];
        }
    }
    stackentry empty = {};
    return empty;
}

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

bool find_variable_in_closest_function_scope( vector< stackentry > &stack, string token, int scope ) {
    for( int i = stack.size()-1; i >= 0; i--) {
        if( stack[i].nature != OPEN_FUNCTION ) {
            if( stack[i].token == token ) {
                return true;
            }
        }
        else {
            break;
        }
    }
    return false;
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

void add_to_stack( vector< stackentry > &stack, string token, int scope, string type, int modifier, string nature, int offset, string argument_type) {
    stackentry entry;
    entry.token = token;
    entry.scope = scope;
    entry.type = type;
    entry.modifier = modifier;
    entry.nature = nature;
    entry.offset = offset_map[type];
    entry.argument_type = argument_type;
    // entry.lineno = lineno;
    stack.push_back(entry);
}

void clear_current_scope( vector< stackentry > &stack, int scope ) {
    for( int i = stack.size()-1; i >= 0; i--) {
        if( stack[i].scope == scope ) {
            stack.pop_back();
        }
        else{
            break;
        }
    }
}

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

void add_class(int8_t modifier, string token) {
    if(symmbol_table_pass1.find(token) != symmbol_table_pass1.end()){
        cerr << "Class Already present\n";
        exit(-1);
    }
    vector <stackentry> class_data;
    symmbol_table_pass1[token] = class_data;
}

void add_variable(string token, int8_t modifier, string type){
    if(! find_variable_in_closest_function_scope(symmbol_table_pass2[current_class], token, current_scope)) {
        add_to_stack(symmbol_table_pass2[current_class], token, current_scope, type, modifier, VARIABLE, 0, "");
    } else {
        cerr << "Instance variable already present\n";
        exit(-1);
    }
}

void add_function(string token, string argument_type, string return_type, int8_t modifier) {
    if(check_function_in_class(symmbol_table_pass2[current_class], token, argument_type, return_type)){
        cerr << "Function already exists\n";
        exit(-1);
    } else {
        add_to_stack(symmbol_table_pass2[current_class], token, current_scope, return_type, modifier, OPEN_FUNCTION, 0, argument_type);
        // Add entries of temp_scope to actual scope
    }
}
