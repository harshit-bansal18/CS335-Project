
#include <symbol_table_fast.hpp>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define is_null(ptr) (ptr == NULL)

ClassDefinition *curr_class;
LocalSymbolTable *curr_table;

typedef enum {
    scope_global,
    scope_class,
    scope_method
} scope;

scope curr_scope;


int8_t set_modifier(int8_t curr_modf, int8_t new_modf) {
    if (curr_modf & new_modf) {
        cerr << "conflicting modifiers\n";
        exit (1);
    }

    return (curr_modf | new_modf);
}

bool check_primitive_types(Type *type) {
    return (type->is_primitive);
}

bool check_if_numeric_type(Type *type) {
    return (type->is_numeric);
}

bool check_return_type(Type *type1, Type *type2) {
    Type t1 = *type1;
    Type t2 = *type2;
    return (t1 == t2);
}

Type *_get_final_ref_type(char *split_token, unsigned int dot_count) {
    
    Type *type;
    string tmp_str;
    ClassDefinition *cls;
    SymTabEntry *sym;

    int count = 0;

    if (count == dot_count)
        return NULL;
   
    tmp_str = split_token;
    sym = curr_table->get_symbol_from_table(tmp_str);

    if (is_null(sym)) {
        cerr << "variable not declared in this scope " << tmp_str << endl;
        exit (1);
    }

    type = sym->type;
    if (!type->is_class) {
        cerr << tmp_str << " : variable of non-reference type cannot be referenced" << endl;
        exit (1);
    }
    cls = type->class_def;
    
    split_token = strtok(NULL, ".");
    count ++;

    while(split_token != NULL) {
        if (count != dot_count) {
            tmp_str =  split_token;
            type = cls->get_var_type(tmp_str);
            if(!type->is_class){
                cerr << tmp_str << " : variable of non-reference type cannot be referenced" << endl;
                exit (1);
            }
            cls = type->class_def;
            split_token = strtok(NULL, ".");
            count++;
        }
        else 
            return type;
    }

    // should not reach here
    return NULL;
}


Type *check_function_in_class(string token, string argument_type, string nature) {
    
    const char* str = token.c_str();
    char *split_token = strtok((char*)str, ".");
    unsigned int dot_count = 0, count = 0;
    ClassDefinition *cls;

    for(int i = 0; i < token.size(); i++){
        if(token[i] == '.') dot_count ++;
    }

    Type *ref_type = _get_final_ref_type(split_token, dot_count);
    cls = ref_type->class_def;

    while(split_token != NULL) {
        
        if(count != dot_count){
           split_token = strtok(NULL, ".");
            count++;        
        } else {
            string mthd_name = split_token;
            MethodDefinition *mthd = cls->get_method(mthd_name);
            if (mthd->args_str == argument_type){
                return mthd->ret_type;
            }
        }
       
    }

    return NULL;
}

////////////////////// Jaya Open //////////////////////////////////
// stackentry* get_variable_stackentry(vector< stackentry* > &stack, string token) {

// }

SymTabEntry *find_variable_in_class( string token) {

    SymTabEntry *sym = curr_table->get_symbol_from_class(token);
    return sym;
}
////////////////////// Jaya Close /////////////////////////////////


// Function used when we need to add a new variable or declare a variable
bool find_variable_in_closest_function_scope( string token ) {
    if (!is_null(curr_table->get_symbol_from_table(token)))
        return true;
    else return false;
}


void clear_current_scope( ) {
    curr_table->clear_current_level();
}

void add_class(int8_t modifier, string token) {
    ClassDefinition *new_class = new ClassDefinition(token, modifier);
    switch (curr_scope) {
        case scope_class:
    }
}


void add_variable(string token, int8_t modifier, Type *type, unsigned long line_no, bool is_fun_arg) {
    SymTabEntry *sym = new SymTabEntry(token, line_no);
    sym->type = type;
    sym->modifier = modifier;   
    switch (curr_scope) {
        case scope_class:
            curr_class->add_var(token, type, modifier);
            break;
        case scope_method:
            curr_table->add_to_table(sym, is_fun_arg);
            break;
    }

}

void add_function(string token, string argument_type, Type* return_type, int8_t modifier, unsigned long line_no) {
    MethodDefinition *mthd;
    mthd = curr_class->get_method(token);
    if (mthd->args_str == argument_type) {
        cerr << "same function declared again. previous declaration at line: " << mthd->line_no << endl;
        exit (1);
    }
    MethodDefinition *new_mthd = new MethodDefinition(token, argument_type, return_type, modifier, line_no);
    curr_class->add_method(new_mthd, !curr_class->is_interface);
    curr_table->reset_table();
}

void add_constructor(string token, string argument_type, string return_type, int8_t modifier, int scope) {
    
}