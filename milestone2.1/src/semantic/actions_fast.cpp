

#include <iostream>
#include <bits/stdc++.h>
#include <macros.hpp>
#include <actions_fast.hpp>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

extern "C" int yylineno;
extern int pass_no;
extern int8_t global_modifier;

ClassDefinition *current_class;
LocalSymbolTable *current_table;
GlobalSymbolTable *global_table;

scope current_scope;

unordered_map<string, Type *> defined_types;

int8_t set_modifier(int8_t curr_modf, int8_t new_modf) {
    if (curr_modf & new_modf) {
        cerr << "conflicting modifiers\n";
        exit (1);
    }

    return (curr_modf | new_modf);
}

void increase_current_level() {
    current_table->increase_level();
}

bool check_primitive_types(Type *type) {
    return (type->is_primitive);
}

bool check_if_numeric_type(Type *type) {
    if (!type->is_numeric) {
        // cerr << "Line No: " <<  yylineno  << "Array dimensions should be numeric\n";
        // exit(1);
        return false;
    }

    return true;
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
    sym = current_table->get_symbol_from_class(tmp_str);

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


Type *check_constructor(string token, string argument_type) {
    Type *t =  get_type(token);
    ClassDefinition *cls = t->class_def;
    if (cls->find_constructor(argument_type)){
        return t;
    }
    return NULL;
}

Type *check_function_in_class(string token, string argument_type, string nature) {
    
    if (nature == CONSTRUCTOR) {
        return check_constructor(token, argument_type);
    }
    
    const char* str = token.c_str();
    char *split_token = strtok((char*)str, ".");
    unsigned int dot_count = 0, count = 0;
    ClassDefinition *cls;

    for(int i = 0; i < token.size(); i++){
        if(token[i] == '.') dot_count ++;
    }

    Type *ref_type = _get_final_ref_type(split_token, dot_count);
    
    if (is_null(ref_type))
        cls = current_class;
    
    else cls = ref_type->class_def;

    while(split_token != NULL) {
        
        if(count != dot_count){
           split_token = strtok(NULL, ".");
            count++;        
        } else {
            string mthd_name = split_token;
            MethodDefinition *mthd = cls->get_method(mthd_name, argument_type);
            if (!is_null(mthd)){
                return mthd->ret_type;
            }
        }
       
    }

    return NULL;
}

////////////////////// Jaya Open //////////////////////////////////
// stackentry* get_variable_stackentry(vector< stackentry* > &stack, string token) {

// }

///////////////////////TODO////////////////////////////////////////////
stackentry *find_variable_in_class(string name, bool intialize) {
    
    SymTabEntry *sym = current_table->get_symbol_from_class(name);
    if (is_null(sym)) {
        cerr << name << ": variable not found. used on line " << yylineno << endl;
        exit(1);
    }
    sym->is_initialized = intialize;
    if (sym->is_initialized) {
        stackentry *s = make_stackentry(name.c_str(), sym->line_no);
        s->type = sym->type;
        return s;
    }
    else {
        cerr << name << ": variable not intialized. used on line " << yylineno << endl;
        exit(1);
    }
}


// Function used when we need to add a new variable or declare a variable
bool find_variable_in_closest_function_scope( string token ) {
    if (!is_null(current_table->get_symbol_from_table(token)))
        return true;
    else return false;
}


void clear_current_scope( ) {
    current_table->clear_current_level();
}

void add_class(int8_t modifier, string token) {
    ClassDefinition *new_class ;
    if (pass_no == 2) {
        new_class = global_table->get_class(token);
        if (is_null(new_class)) {
            // should never happen
            cerr << "this should never have happened. class " << token << " not found in pass 2" << endl;
            exit (1);
        }
        goto end;
    }
    new_class = new ClassDefinition(token, modifier, yylineno);
    switch (current_scope) {
        case scope_class:
            // inner classes not supported yet
            cerr << "inner classes not supported yet" << endl;
            break;
        case scope_global:
            global_table->add_class(new_class);
            Type *t = new Type(token, new_class);
            add_to_defined_types(t);
            goto end;
            break;
    }
end:
    current_scope = scope_class;
    current_class = new_class;
}


void add_variable(string token, int8_t modifier, Type *type, bool is_fun_arg) {
    SymTabEntry *sym = new SymTabEntry(token, yylineno);
    sym->type = type;
    sym->modifier = modifier;
    switch (current_scope) {
        case scope_class:
            cout << sym->name << " " << sym->line_no << " " << sym->type->name << endl;
            current_class->add_var(sym);
            break;
        case scope_method:
            current_table->add_to_table(sym, is_fun_arg);
            break;
    }
}

void add_function(string token, string argument_type, Type* return_type, int8_t modifier) {
    if (pass_no == 2) {
        current_table->empty_table();
        current_table->method_name = token;
        current_table->container_class = current_class;
        return;
    }
    MethodDefinition *new_mthd = new MethodDefinition(token, argument_type, return_type, modifier, yylineno);
    new_mthd->defined = !current_class->is_interface;
    current_class->add_method(new_mthd);
}

void add_constructor(string token, string argument_type, int8_t modifier) {
    if (pass_no == 2) {
        current_table->empty_table();
        current_table->method_name = token;
        current_table->container_class = current_class;
        return;
    }

    MethodDefinition *constr;
    constr = new MethodDefinition(token, argument_type, NULL, modifier, yylineno);
    current_class->add_constructor(constr);
}

// Type *make_type(string name, bool is_numeric, size_t size) {
//     Type *t = new Type(name, is_numeric, size);
//     return t; 
// }

// Type *make_type(string name, ClassDefinition *cls) {
//     Type *t =  new Type(name, cls);
//     return t;
// }

Type *get_type(string name) {
    auto it = defined_types.find(name);
    if (it == defined_types.end()) {
        cerr << name << " : type does not exist" << endl;
        exit(1);
    }
    return it->second;
}

/*
    When TypeName is name of a class and is used to declares objects of a class (reference type)
    Since inner class is not supported yet, we can have only one identifier in the TypeName 
*/
Type *get_type(TypeName *tn) {
    assert(tn->names.size() == 1);
    return get_type(tn->names[0]->name);
}


/*
    make_type functions for array types are pending
*/

bool check_in_defined_types(Type *type) {
    auto it = defined_types.find(type->name);
    if (it == defined_types.end()) {
        return false;
    }
    return true;
}

Identifier *make_identifier(const char *name) {
    
    Identifier *id = new Identifier(name, yylineno);

    return id;

}


TypeName *make_typename(Identifier *id) {
    TypeName *t = new TypeName(id);
    return t;
}

void append_typename(Identifier *id, TypeName *tn) {
    tn->append_name(id);
}


stackentry::stackentry(const char *name, unsigned long line) {
    this->token = name;
    this->line_no = line;
    this->type  = NULL;
    this->scope_ = current_scope;
    this->modifier = (int8_t)0;
    this->argument_type = "";
    this->nature = "";
    this->is_var_intialized = false;
    this->offset = 0;
}

stackentry *make_stackentry(const char *token, unsigned int line) {
    stackentry *s =  new stackentry(token, line);
    return s;
}

stackentry *make_stackentry(const char *token, string type, unsigned int line) {
    stackentry *s = new stackentry(token, line);
    s->type = get_type(type);
    return s;
}

void check_boolean(Type *t) {
    assert(t == defined_types[__BOOLEAN]);
}

void check_cast_types(Type *t1, Type *t2) {
     if( ((t1 == defined_types[__BOOLEAN]) && (t2 == defined_types[__BOOLEAN])) ||
        (t1->is_numeric && t2->is_numeric)){
        return ;
    } else if(t1->name == t2->name){
        return;
    }
    else {
        cerr << "Line No: " << yylineno  << "incompatible types: " << t1->name << "cannot be converted to " << t2->name << "\n";
        exit (1);
    }

}

Type *get_array_type() {
    Type *t = new Type();
    t->arr_dim = 1;
    return t;
}

// Type *get_array_type(s)
Type *get_array_type(Type *t, stackentry *e) {
    Type *new_t = new Type();
    *new_t = *t;
    new_t->arr_dim = e->type->arr_dim;
    free(e->type);
    free(e);
    return new_t;
}

stackentry *increase_dims(stackentry *e) {
    if (!e->type->is_pointer()) {
        Type *t = e->type;
        e->type = get_array_type();
        return assign_arr_dim(t, e);
    }
    e->type->arr_dim++;
    return e;
}

stackentry *assign_arr_dim(stackentry *e1, stackentry *e2) {
    free(e2->type);
    free(e2);
    
    e1->type->arr_dim++;
    return e1;
}
stackentry *assign_arr_dim(Type *t, stackentry *e1, stackentry *e2) {
    unsigned int dims = e1->type->arr_dim++;
    *(e1->type) = *t;
    e1->type->arr_dim = dims;
    free(e2->type);
    free(e2);
    return e1;
}

stackentry *assign_arr_dim(Type *t, stackentry *e1) {
    unsigned int dims = e1->type->arr_dim;
    *(e1->type) = *t;
    e1->type->arr_dim = dims;
    return e1;
}

stackentry *check_multiplicative_types(stackentry *e1, stackentry *e2) {

    if(check_if_numeric_type(e1->type) && check_if_numeric_type(e2->type) ) {
        if(check_return_type((e1)->type, (e2)->type)) 
            return e1;
        else
            return e2;
    } else {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< (e1)->type << "\nsecond type: " << (e2)->type << "\n";
        exit(1);
    }
}

stackentry* check_additive_types(stackentry* e1, stackentry* e2) {

    if(check_if_numeric_type(e1->type) && check_if_numeric_type(e2->type) ) {
        if(check_return_type(e1->type, e2->type)) 
            return e1;
        else
            return e2;
    } else {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1);
    }
}

stackentry* ShiftExpression(stackentry* e1, stackentry* e2) {

    if((!check_primitive_types(e1->type)) || (!(check_primitive_types(e2->type)))) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1); 
    }

    if((e1->type == defined_types[__DOUBLE] || e1->type == defined_types[__FLOAT] || e1->type == defined_types[__BOOLEAN]) || (e2->type == defined_types[__DOUBLE] || e2->type == defined_types[__FLOAT] || e2->type == defined_types[__BOOLEAN]) ) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1);    
    }

    if(check_return_type(e1->type, e2->type)) 
            return e1;
        else
            return e2;
}

stackentry* RelationalExpression(stackentry* e1, stackentry* e2) {
    if(check_if_numeric_type(e1->type) && check_if_numeric_type(e2->type) ) {
        return  make_stackentry("", __BOOLEAN, yylineno);
    } else {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1);
    }
}

stackentry* EqualityExpression(stackentry* e1, stackentry* e2) {
    if(!check_if_numeric_type(e1->type) || !check_if_numeric_type(e2->type)){
        if(e1->type != defined_types[__BOOLEAN] || e2->type != defined_types[__BOOLEAN]){
            cerr << "Line No: " <<  yylineno  << "incomparable types: " << e1->type << " and " << e2->type << "\n";
            exit(-1);
        }
    }

    return make_stackentry("", __BOOLEAN, yylineno);
}

stackentry* BitwiseExpression (stackentry* e1, stackentry* e2) {
    if((!check_primitive_types(e1->type)) || (!(check_primitive_types(e2->type)))) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1); 
    }

    if((e1->type == defined_types[__DOUBLE] || e1->type == defined_types[__FLOAT] || e1->type == defined_types[__BOOLEAN]) || (e2->type == defined_types[__DOUBLE] || e2->type == defined_types[__FLOAT] || e2->type == defined_types[__BOOLEAN]) ) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1);    
    }

    if(check_return_type(e1->type, e2->type)) 
            return e1;
    else
        return e2;
}

stackentry* ConditionalExpression (stackentry* e1, stackentry* e2) {
    if(e1->type!= defined_types[__BOOLEAN] || e2->type!= defined_types[__BOOLEAN]){
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator '&&'\n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";         
        exit(-1);
    }

    return e1;
}

Type *add_to_defined_types(Type *type) {
    auto it = defined_types.find(type->name);
    if (it == defined_types.end()) {
        defined_types.insert( {type->name, type});
        return type;
    }
    else {
        if (pass_no == 1) {
            if (is_null(it->second->class_def)) {
                it->second->class_def = type->class_def;
                free(type);
                return it->second;
            }
        }
    }
    // should never reach here
    return NULL;
}

Type* get_type_pass1(string name) {
    auto it = defined_types.find(name);
    if (it == defined_types.end()) {
        // type not found
        // possible if class not parsed yet. make new type
        Type *t = new Type(name, NULL);
        add_to_defined_types(t);
        return t;
    }
    return it->second;
}

Type* ClassOrInterfaceType(stackentry* e1) {

    if( pass_no == 2){
        return get_type(e1->token);
    }
    
    return get_type_pass1(e1->token);
}

// stackentry* ArrayType(stackentry* e1, stackentry* e2, int rule_no) {

//     if(rule_no == 2){
//         if(pass_no == 2){
//             if(symmbol_table_pass1.find(e1->token) == symmbol_table_pass1.end()){
//                 cerr << "Line No: " <<  yylineno <<"Error: Cannot find class "<<e1->token<<endl;
//                 exit(1);
//             }
//         }

//         struct stackentry* entry = new_entry();
//         entry->type = e1->type+e2->type; 
//         return entry;
//     }

//     return NULL;
// }

void VariableDeclarator(stackentry* e1, stackentry* e2, int rule_no) {
    
    if(rule_no == 1){
                
        if ((pass_no == 1 && current_scope == scope_class) || (pass_no == 2 && current_scope == scope_method)) {
            add_variable(e1->token, global_modifier, e1->type, false);
            if(e2->type == NULL) {
                // Means a empty array declaration: int a[] = {}; which is perfectly valid
                // Make its type same as (1)->type
                e2->type = e1->type;
            }
        }

        if(pass_no == 2){

            if(e2->type->name == "") {
                e2->type = e1->type;
            }

            cout << e1->type->name << " " << e1->type->arr_dim << " " << e2->type->name << " " << e2->type->arr_dim << "\n";

            if(!check_return_type(e1->type,e2->type)){
                if(e1->type->arr_dim){
                    cerr << "Line No: " <<  yylineno <<"Error: Cannot assign "<<e2->type->name;
                    int count = 0;
                    while((count++) < e1->type->arr_dim) 
                        cout << "[]";
                    
                    cout <<" to "<<e1->type->name<<endl;
                }
                else 
                    cerr << "Line No: " <<  yylineno <<"Error: Cannot assign "<<e2->type->name<<" to "<<e1->type->name<<endl;
                exit(1);
            }
        }

    } else {
        if (pass_no == 1 || (pass_no == 2 && current_scope == scope_method))
            add_variable(e1->token, global_modifier, e1->type, 0);
    }
}

// void MethodDeclaration() {
    // cout << "In Method Declaration\n";
    // if(pass_no == 1){
    //     int l = symmbol_table_pass1[current_class].size(); 
    //     symmbol_table_pass1[current_class][l-1]->nature = FUNCTION;
    // } else {
    //     int l = symmbol_table_pass2[current_class].size(); 
    //     symmbol_table_pass2[current_class][l-1]->nature = FUNCTION;
    // }
// }

// void ConstructorDeclaration() {
    // if(pass_no == 1){
    //     int l = symmbol_table_pass1[current_class].size(); 
    //     symmbol_table_pass1[current_class][l-1]->nature = CONSTRUCTOR;
    // } else {
    //     int l = symmbol_table_pass2[current_class].size(); 
    //     symmbol_table_pass2[current_class][l-1]->nature = CONSTRUCTOR;
    // }
    
// }

void IfCondition(stackentry* e1){
    if(pass_no == 2 ){
        check_boolean(e1->type);
        // if(e1->type!=__BOOLEAN){
        //     cerr << "Line No: " <<  yylineno <<"incompatible if argument types: "+ e1->type +" cannot be converted to boolean";
        //     exit(1);
        // }
    } 
}

void AssertCondition(stackentry* e1) {
    if(pass_no == 2 ){
        check_boolean(e1->type);
        // if(e1->type!=__BOOLEAN){
        //     cerr << "Line No: " <<  yylineno <<"incompatible if argument types: "+ e1->type +" cannot be converted to boolean";
        //     exit(1);
        // }
    }
}

void WhileCondition(stackentry* e1) {
    if(pass_no == 2 ){
        check_boolean(e1->type);
        // if(e1->type!=__BOOLEAN){
        //     cerr << "Line No: " <<  yylineno <<"incompatible if argument types: "+ e1->type +" cannot be converted to boolean";
        //     exit(1);
        // }
    }
}

void ForCondition(stackentry* e1) {
    if(pass_no == 2){
        check_boolean(e1->type);
        // if(e1->type!=__BOOLEAN){
        //     cerr << "Line No: " <<  yylineno <<"incompatible if argument types: "+ e1->type +" cannot be converted to boolean";
        //     exit(1);
        // }
    }
}

void EnhancedForCondition(stackentry* e1){
    if(pass_no == 2){        
        if( !e1->type->is_pointer()){
            cerr << "Line No: " <<  yylineno <<"Array type must be pointer"<<endl;
            exit(1);
        }
    }
}

void intialize_types() {
    defined_types.clear();
    defined_types.insert( {__LONG, new Type(__LONG, true, true, 8)});
    defined_types.insert( { __INT, new Type(__INT, true, true, 4)} );
    defined_types.insert( {__BYTE, new Type(__BYTE, true, true, 1)});
    defined_types.insert( { __CHAR, new Type(__CHAR, true, true, 1)});
    defined_types.insert( {__SHORT, new Type(__SHORT, true, true, 2)});
    defined_types.insert( {__FLOAT, new Type(__FLOAT, true, false, 4)});
    defined_types.insert( {__DOUBLE, new Type(__DOUBLE, true, false, 8)});
    defined_types.insert( {__VAR, new Type(__VAR, false, false, 4)});
    defined_types.insert( {__BOOLEAN, new Type(__BOOLEAN, false, false, 1)});
    defined_types.insert( {__VOID, new Type(__VOID, false, false, 0)});
}

void verify_pass1() {
    for(auto it: defined_types) {
        if (it.second->is_class && is_null(it.second->class_def)) {
            cerr << it.second->name << ": invalid type" << endl;
            exit(1);
        }
    }
}

void print_modifier(int8_t mod) {

    if((mod & __PUBLIC) == __PUBLIC){
        cout << "public ";
    }else if((mod & __PRIVATE) == __PRIVATE)
        cout << "private ";
    
    if((mod & __STATIC) == __STATIC)
        cout << "static ";
    
    if((mod & __FINAL) == __FINAL)
        cout << "final ";
}
