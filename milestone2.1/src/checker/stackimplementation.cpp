#include <bits/stdc++.h>

using namespace std;

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

map< string, vector< stackentry > > symmbol_table_pass1;
map< string, vector< stackentry > > symmbol_table_pass2;

#define PUBLIC 0b11
#define PRIVATE 0b10
#define STATIC 0b100
#define ABSTRACT 0b1000

// unordered_map<string, int8_t> modifiers = {{"public", PUBLIC},
//                                            {"private", PRIVATE},
//                                            {"static", STATIC},
//                                            {"abstract", ABSTRACT}};


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

void add_to_stack( vector< stackentry > &stack, string token, int scope, string type, int modifier, string nature, int offset) {
    stackentry entry;
    entry.token = token;
    entry.scope = scope;
    entry.type = type;
    entry.modifier = modifier;
    entry.nature = nature;
    entry.offset = offset_map[type];
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

bool check_in_current_scope( vector< stackentry > &stack, string token, int scope ) {
    for( int i = stack.size()-1; i >= 0; i--) {
        if( stack[i].scope == scope ) {
            if( stack[i].token == token ) {
                return true;
            }
        }
        else{
            break;
        }
    }
    return false;
}

stackentry check_in_stack( vector< stackentry > stack, string token ) {
    for( int i = stack.size()-1; i >= 0; i--) {
        if( stack[i].token == token ) {
            return stack[i];
        }
    }
    stackentry empty = {};
    return empty;
}

stackentry check_in_function( ){}


void check_var_decl()