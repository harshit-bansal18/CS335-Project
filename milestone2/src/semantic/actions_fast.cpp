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
int new_offset = 0;
int dump_counter = 1;
unordered_map<string, Type *> defined_types;

int8_t set_modifier(int8_t curr_modf, int8_t new_modf) {
    if (curr_modf & new_modf) {
        cerr << "Line no: " << yylineno << " conflicting modifiers\n";
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

Type *check_constructor(string token, vector<Type*>& argument_type) {
    Type *t =  get_type(token);
    ClassDefinition *cls = t->class_def;
    if (cls->find_constructor(argument_type)){
        return t;
    }
    return NULL;
}

Type *check_function_in_class(string token, vector<Type *> &argument_type, string nature) {
    
    if (nature == CONSTRUCTOR) {
        return check_constructor(token, argument_type);
    }
    
    bool check_static = (current_scope == scope_method && current_table->method->is_static);
    unsigned int dot_count = 0, count = 0;
    for(int i = 0; i < token.size(); i++){
        if(token[i] == '.') dot_count ++;
    }

    const char* str = token.c_str();
    char *split_token = strtok((char*)str, ".");
    string tmp_str;
    ClassDefinition *cls;
    Type *ref_type;
    SymTabEntry *sym;
    

    if(dot_count == 0) {
        tmp_str = split_token;
        cls = current_class;
        MethodDefinition *mthd = cls->get_method_call(tmp_str, argument_type);

        if (!is_null(mthd)){
            if (check_static && !mthd->is_static) {
                cerr << "Error Line no: " << yylineno << ": error: cannot call non-static method " << token << " from static method\n";
                exit(1);
            }
            return mthd->ret_type;
        }
        else {
            cerr << "Error on line " << yylineno << " " << token << " not found in class " << cls->name << endl;
            exit(1);
        }
    }
    else {
        tmp_str = split_token;

        if (current_scope == scope_class)
            sym = current_class->get_var(tmp_str);
        else
            sym = current_table->get_symbol_from_class(tmp_str);
    
        if (is_null(sym)) {
            cerr << "Error Line No: "<<yylineno <<": variable not declared in this scope. Variable Name: " << tmp_str << endl;
            exit (1);
        }
        if (check_static && sym->is_instance_var && !sym->is_static) {
            cerr << "Error Line No: " << yylineno << ": error: non-static variable " << sym->name << " accessed in static method " << current_table->method_name << endl;
            exit(1);
        }

        ref_type = sym->type;

        if(is_null(ref_type)) {
            cerr << "Error Line No: "<< yylineno << " : Reference type of object is null. This should not happen\n";
            exit(-1);
        }

        if (!ref_type->is_class) {
            cerr << "Error Line No: " << yylineno << ":  "<< tmp_str << " : variable of non-reference type cannot be referenced" << endl;
            exit (1);
        }
        cls = ref_type->class_def;
        
        split_token = strtok(NULL, ".");
        count ++;
    

        while(split_token != NULL) {

            if (count != dot_count) {
                tmp_str = split_token;
                ref_type = cls->get_var_type(tmp_str);

                if(is_null(ref_type)) {
                    cerr << "Error Line No: " << yylineno << " : " << split_token << " is not a member of class " << cls->name << "\n";
                    exit(-1);
                }

                if(!ref_type->is_class){
                    cerr << "Error Line No: " << yylineno << " " << tmp_str << " : variable of non-reference type cannot be referenced" << endl;
                    exit (1);
                }
                cls = ref_type->class_def;
            }
            else {
                string mthd_name = split_token;
                // cout << "mthd name: " << mthd_name << " args: " << argument_type << endl;
                // cerr << "Args: ";
                // for (auto v:argument_type){
                //     cerr << v->name;
                //     for (int i = 0; i < v->arr_dim; i++) cerr << "[]";
                //     cerr << ", ";
                // }

                MethodDefinition *mthd = cls->get_method_call(mthd_name, argument_type);
                if (!is_null(mthd)){
                    return mthd->ret_type;
                }
                else {
                    cerr << "Error Line No: " << yylineno << " " << mthd_name << " not found in class " << cls->name << endl;
                    exit(1);
                }
            }
        
            split_token = strtok(NULL, ".");
            count++;
        }
    }

    return NULL;
}

////////////////////// Jaya Open //////////////////////////////////
// stackentry* get_variable_stackentry(vector< stackentry* > &stack, string token) {

// }

///////////////////////TODO////////////////////////////////////////////
stackentry *find_variable_in_class(string token, bool intialize) {
    SymTabEntry *sym;
    bool check_static;
    string name = token;
    unsigned int dot_count = 0, count = 0;
    for(int i = 0; i < token.size(); i++){
        if(token[i] == '.') dot_count ++;
    }
    check_static = (current_scope == scope_method && current_table->method->is_static);
    const char* str = token.c_str();
    char *split_token = strtok((char*)str, ".");
    string tmp_str;
    ClassDefinition *cls;
    Type *ref_type;
    
    if(dot_count == 0) {
        if (current_scope == scope_class) {
            sym = current_class->get_var(token);
        }
        else {
            sym = current_table->get_symbol_from_class(token);
        }
        if(is_null(sym)) {
            cerr << "Error on line " << yylineno << " " << name << ": variable not found. used on line " << yylineno << endl;
            exit(1);
        }

        if (check_static && sym->is_instance_var && !sym->is_static) {
            cerr << "Line No: " << yylineno << ": error: non-static variable " << sym->name << " accessed in static method " << current_table->method_name << endl;
            exit(1);
        }
        
        goto end;
    }
    else {
        tmp_str = split_token;

        if(current_scope == scope_class) {
            sym = current_class->get_var(tmp_str);
        } else {
            sym = current_table->get_symbol_from_class(tmp_str);
        }

        if (is_null(sym)) {
            cerr << "Error Line No: " << yylineno << "variable not declared in this scope " << tmp_str << endl;
            exit (1);
        }

        if (check_static && sym->is_instance_var && !sym->is_static) {
            cerr << "Error Line No: " << yylineno << ": error: non-static variable " << sym->name << " accessed in static method " << current_table->method_name << endl;
            exit(1);
        }
        ref_type = sym->type;
        if(is_null(ref_type)) {
            cerr << "Error Line No: " << yylineno << " : Reference type of object is null. This should not happen\n";
            exit(-1);
        }

        if (!ref_type->is_class) {
            cerr << "Error Line No: " << yylineno << " " << tmp_str << " : variable of non-reference type cannot be referenced" << endl;
            exit (1);
        }
        cls = ref_type->class_def;
        
        split_token = strtok(NULL, ".");
        count ++;

        while(split_token != NULL) {
            // cout << "split token: " << split_token << "\n";
            if (count != dot_count) {
                tmp_str = split_token;
                sym = cls->get_var(tmp_str);
                
                if(is_null(sym)) {
                    cerr << "Error Line No: " <<  yylineno << " : " << split_token << " is not a member of class " << cls->name << "\n";
                    exit(-1);
                }
                
                if(sym->is_private){
                    cerr << "Error Line No: " <<  yylineno << " : " << "Cannot access Private Variable " << split_token << " of class " << cls->name << " from its object\n";
                    exit(-1);
                }

                ref_type = sym->type;

                if(!ref_type->is_class){
                    cerr << "Error Line No: " <<  yylineno << " "<<tmp_str << " : variable of non-reference type cannot be referenced" << endl;
                    exit (1);
                }
                cls = ref_type->class_def;
            }
            else {
                string var_name = split_token;
                // cout << "var name: " << var_name << endl;
                sym = cls->get_var(var_name);
                if(is_null(sym)) {
                    cerr  << "Error on line " << yylineno << " " << name << ": variable not found. used on line " << yylineno << endl;
                    exit(1);
                }

                if(sym->is_private){
                    cerr << "Line No: " <<  yylineno << " : " << "Cannot access Private Variable " << split_token << " of class " << cls->name << " from its object\n";
                    exit(-1);
                }

                goto end;
            }

            split_token = strtok(NULL, ".");
            count++;
        }
    }
    
end:

    if(current_scope == scope_method && current_table->nature == CONSTRUCTOR) {
        if(intialize && sym->is_final && sym->is_final_initialized) {
            cerr << "Line No: "<<  yylineno << ": error: " << "Cannot assign value to final variable " << sym->name << "\n";
            exit(-1);
        }
        
    }
    else if (intialize && sym->is_final && (sym->is_instance_var || sym->is_final_initialized)) {
        cerr << " Line No: "<< yylineno << ": error: variable " << sym->name << " cannot be assigned here" << endl;
        exit(1);
    }
    
    sym->is_initialized = sym->is_initialized || intialize;
    sym->is_final_initialized = sym->is_initialized;

    if (sym->is_initialized) {
        stackentry *s = make_stackentry(name.c_str(), sym->type, sym->line_no);
        return s;
    }
    else {
        cerr << "Error Line No: " <<  name << ": variable not intialized. used on line " << yylineno << endl;
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
            cerr << "Error Line No: " <<  "this should never have happened. class " << token << " not found in pass 2" << endl;
            exit (1);
        }
        goto end;
    }
    new_class = new ClassDefinition(token, modifier, yylineno);
    switch (current_scope) {
        case scope_class:
            // inner classes not supported yet
            cerr << "Error Line No: " <<  "inner classes not supported yet" << endl;
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


void add_variable(string token, int8_t modifier, Type *type, int offset, bool is_fun_arg, bool initialized) {
    SymTabEntry *sym = new SymTabEntry(token, type, modifier, yylineno);
    sym->offset = offset;
    sym->is_initialized = initialized;
    sym->is_final_initialized  = initialized;
    switch (current_scope) {
        case scope_class:
            if(is_fun_arg) {
                current_table->add_to_table(sym, is_fun_arg);        
                return;
            }
            current_class->add_var(sym);
            break;
        case scope_method:
            current_table->add_to_table(sym, initialized);
            break;
    }
}

void add_function(string token, vector<Type*> &argument_type, Type* return_type, int8_t modifier) {
    if (pass_no == 2) {
        current_table->method_name = token;
        current_table->container_class = current_class;
        current_table->return_type = return_type;
        current_table->nature = FUNCTION;
        current_table->method = current_class->get_method(token, argument_type);
        freopen((DUMP_DIR + current_class->name + "." + token + "_" + to_string(dump_counter) + ".st").c_str(), "w", stdout);
        cout << "token,lexeme,type,modifiers,line_no,scope(inside function)\n";
        dump_counter++;
        return;
    }
    MethodDefinition *new_mthd = new MethodDefinition(token, argument_type, return_type, modifier, yylineno);
    current_class->add_method(new_mthd);
}

void add_constructor(string token, vector<Type*> &argument_type, int8_t modifier) {
    Type *ret_type =  get_type(__VOID);
    if (pass_no == 2) {
        current_table->method_name = token;
        current_table->container_class = current_class;
        current_table->return_type = ret_type;
        current_table->nature = CONSTRUCTOR;
        current_table->method = current_class->get_constructor(argument_type);
        freopen((DUMP_DIR + current_class->name + "." + token + "_" + to_string(dump_counter)+ ".st").c_str(), "w", stdout);
        cout << "token,lexeme,type,modifiers,line_no,scope(inside function)\n";
        dump_counter++;
        return;
    }

    if ((modifier & __STATIC) == __STATIC) {
        cerr << "Line No: " <<  yylineno << ": error: static modifier not allowed here\n";
        exit(1);
    }
    MethodDefinition *constr;
    constr = new MethodDefinition(token, argument_type, ret_type, modifier, yylineno);
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
        cerr << "Error Line No: " <<  yylineno << " " << name << " : type does not exist" << endl;
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
    this->argument_type.clear();
    this->nature = "";
    this->is_var_intialized = false;
    this->offset = 0;
}

stackentry *make_stackentry(const char *token, unsigned int line) {
    stackentry *s =  new stackentry(token, line);
    return s;
}

stackentry *make_stackentry(const char *token, Type *type, unsigned int line) {
    if (is_null(type)) {
        cerr << "Line No: " << yylineno <<"  Error: global type is null. this should not happen" << endl;
        exit (1);
    }
    stackentry *s = new stackentry(token, line);
    Type* t_new;
    if(type->is_pointer()) {
        t_new = new Type();
        *t_new = *type;
        s->type = t_new;
    } else {
        s->type = type;
    }
    return s;
}

void check_boolean(Type *t) {

    if(t->arr_dim) {
        cerr << "Line no: " << yylineno << "bad type: Type should be boolean\n";
        exit(1);
    }

    if (t->name != __BOOLEAN) {
        cerr << "Error on line " << yylineno << ". Type should be boolean\n";
        exit(1);
    }
}

void check_cast_types(Type *t1, Type *t2) {

    if(t1->name == __BOOLEAN && t2->name == __BOOLEAN) {
        if(t1->arr_dim != t2->arr_dim){
            cerr << "Line No: " << yylineno  << "incompatible types: " << t1->name << "cannot be converted to " << t2->name << "\n";
            exit (1);
        }

        return;
    }

    if(t1->is_numeric && t2->is_numeric) {
        if(t1->arr_dim != t2->arr_dim){
            cerr << "Line No: " << yylineno  << "incompatible types: " << t1->name << "cannot be converted to " << t2->name << "\n";
            exit (1);
        } else {
            if(t1->arr_dim!=0 && t2->arr_dim!=0 && (t1->name!=t2->name)){
                cerr << "Line No: " << yylineno  << "incompatible types: " << t1->name << "cannot be converted to " << t2->name << "\n";
                exit (1);
            } else {
                return;
            }
        }
    }

    if((t1->name == t2->name) && !t1->arr_dim && !t2->arr_dim ){
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
    unsigned int dims = e1->type->arr_dim + e2->type->arr_dim;
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

// stackentry *check_multiplicative_types(stackentry *e1, stackentry *e2) {

//     if(e1->type->arr_dim || e1->type->arr_dim) {
//         cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< cerr_type((e1)->type) << "\nsecond type: " << cerr_type((e2)->type) << "\n";
//         exit(1);
//     }
    
//     if(check_if_numeric_type(e1->type) && check_if_numeric_type(e2->type) ) {
//         stackentry* e = make_stackentry("",yylineno);
//         if(check_return_type((e1)->type, (e2)->type)) {
//             e->type = e1->type;
//             e->threeac = e1->threeac;
//         } else {
//             e->type = e2->type;
//             e->threeac = e2->threeac;
//         }
//         return e;
        
//     } else {
//         cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< cerr_type((e1)->type) << "\nsecond type: " << cerr_type((e2)->type) << "\n";
//         exit(1);
//     }
// }

stackentry* check_additive_types(stackentry* e1, stackentry* e2) {

    if(e1->type->arr_dim || e1->type->arr_dim) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< cerr_type((e1)->type) << "\nsecond type: " << cerr_type((e2)->type) << "\n";
        exit(1);
    }

    if(check_if_numeric_type(e1->type) && check_if_numeric_type(e2->type) ) {
        stackentry* e = make_stackentry("",yylineno);
        if(check_return_type((e1)->type, (e2)->type)) {
            e->type = e1->type;
            e->threeac = e1->threeac;
        } else {
            e->type = e2->type;
            e->threeac = e2->threeac;
        }
        return e;
    } else {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1);
    }
}

stackentry* ShiftExpression(stackentry* e1, stackentry* e2) {

    if(e1->type->arr_dim || e1->type->arr_dim) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< cerr_type((e1)->type) << "\nsecond type: " << cerr_type((e2)->type) << "\n";
        exit(1);
    }

    if((!check_primitive_types(e1->type)) || (!(check_primitive_types(e2->type)))) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1); 
    }

    if((e1->type->name == __DOUBLE || e1->type->name == __FLOAT || e1->type->name == __BOOLEAN) || (e2->type->name == __DOUBLE || e2->type->name == __FLOAT || e2->type->name == __BOOLEAN) ) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1);    
    }

    if(check_return_type(e1->type, e2->type)) 
            return e1;
        else
            return e2;
}

stackentry* RelationalExpression(stackentry* e1, stackentry* e2) {

    if(e1->type->arr_dim || e1->type->arr_dim) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< cerr_type((e1)->type) << "\nsecond type: " << cerr_type((e2)->type) << "\n";
        exit(1);
    }

    if(check_if_numeric_type(e1->type) && check_if_numeric_type(e2->type) ) {
        return  make_stackentry("", get_type(__BOOLEAN), yylineno);
    } else {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1);
    }
}

stackentry* EqualityExpression(stackentry* e1, stackentry* e2) {

    if(e1->type->arr_dim || e1->type->arr_dim) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< cerr_type((e1)->type) << "\nsecond type: " << cerr_type((e2)->type) << "\n";
        exit(1);
    }

    if(!check_if_numeric_type(e1->type) || !check_if_numeric_type(e2->type)){
        if(e1->type->name != __BOOLEAN || e2->type->name != __BOOLEAN){
            cerr << "Line No: " <<  yylineno  << "incomparable types: " << cerr_type(e1->type) << " and " << cerr_type(e2->type) << "\n";
            exit(-1);
        }
    }

    return make_stackentry("", get_type(__BOOLEAN), yylineno);
}

stackentry* BitwiseExpression (stackentry* e1, stackentry* e2) {

    if(e1->type->arr_dim || e1->type->arr_dim) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< cerr_type((e1)->type) << "\nsecond type: " << cerr_type((e2)->type) << "\n";
        exit(1);
    }

    if((!check_primitive_types(e1->type)) || (!(check_primitive_types(e2->type)))) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1); 
    }

    if((e1->type->name == __DOUBLE || e1->type->name == __FLOAT || e1->type->name == __BOOLEAN) || (e2->type->name == __DOUBLE || e2->type->name == __FLOAT || e2->type->name == __BOOLEAN) ) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< e1->type << "\nsecond type: " << e2->type << "\n";
        exit(-1);    
    }

    if(check_return_type(e1->type, e2->type)) 
            return e1;
    else
        return e2;
}

stackentry* ConditionalExpression (stackentry* e1, stackentry* e2) {

    if(e1->type->arr_dim || e1->type->arr_dim) {
        cerr << "Line No: " <<  yylineno  << "bad operand types for binary operator \n first type: "<< cerr_type((e1)->type) << "\nsecond type: " << cerr_type((e2)->type) << "\n";
        exit(1);
    }
    
    if(e1->type->name != __BOOLEAN || e2->type->name != __BOOLEAN){
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
            // cerr << __func__ << ": adding symbol: " << e1->token << " " << e1->type->name << endl;
            add_variable(e1->token, global_modifier, e1->type, new_offset, false, true);
            new_offset += e1->type->size;
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
    

            // cerr << e1->type->name << " " << e1->type->arr_dim << " " << e2->type->name << " " << e2->type->arr_dim << "\n";
    
            if(!check_return_type(e1->type,e2->type)){
                cerr << "Line No: " <<  yylineno <<"Error: Cannot assign "<< cerr_type(e2->type)<<" to "<< cerr_type(e1->type)<<endl;
                exit(1);
            }

    
        }

    } else {
        if ((pass_no == 1 && current_scope == scope_class) || (pass_no == 2 && current_scope == scope_method)){
            add_variable(e1->token, global_modifier, e1->type, new_offset, false, false);
            new_offset += e1->type->size;
        }
    }
}

// void MethodDeclaration() {
    // cerr << "In Method Declaration\n";
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

Type *find_variable_in_type(string name, Type *type) {
    if(!type->is_class) {
        cerr << "Error on line " << yylineno << ". cannot reference non-reference type " << cerr_type(type) <<  endl;
        exit(1);    
    }

    ClassDefinition *cls = type->class_def;
    SymTabEntry *sym = cls->get_var(name);
    if (is_null(sym)) {
        cerr << "Error on line " << yylineno << ". " << name << " not present in class " << cls->name << endl;
        exit(1);
    }
    return sym->type;
}


bool compare_argument_types(vector<Type *> &t1, vector<Type *> &t2) {
    int l1 = t1.size();
    if(l1 != t2.size())
        return false;
    
    for(int i=0; i < l1; i++) {
        if (!check_return_type(t1[i], t2[i]))
            return false;
    }

    return true;
}

bool __check_type_equality(Type *t1, Type *t2) {
    return (t1->name == t2->name) && (t1->arr_dim == t2->arr_dim);
}

bool compare_argument_types_exact(vector<Type *> &t1, vector<Type *> &t2) {
    int l1 = t1.size();
    if(l1 != t2.size())
        return false;
    
    for(int i=0; i < l1; i++) {
        if (!__check_type_equality(t1[i], t2[i]))
            return false;
    }

    return true;
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
            cerr << "Error Line No: " << yylineno << " " << it.second->name << ": invalid type" << endl;
            exit(1);
        }
    }
}

void check_final_vars() {
    current_class->is_final_var_initialized();
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

void print_type(Type* t) {
    cout << "\t Type_Name: " << t->name << "\tType_Size:" <<  t->size << "\tType_ArrDim"<<  t->arr_dim <<"\n";
}

string cerr_type(Type*t) {
    cerr << t->name;
    int count = 0;
    while((count++) < t->arr_dim) 
        cerr << "[]";
    
    return "";
}

string three_ac_type_dump(vector<Type*> t) {
    string r = "";
    for(int i=0; i<t.size(); i++){
        r+="_";
        r+=t[i]->name;
        r+=to_string(t[i]->arr_dim);
    }
    return r;
}


// 3ac functions

