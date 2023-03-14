#include <actions.hpp>
#include <class.hpp>
#include <method.hpp>

#define INT "int"
#define FLOAT "float"
#define LONG "long"
#define SHORT "byte"
#define BYTE "byte"
#define DOUBLE "double"
#define BOOLEAN  "boolean"
#define CHAR "char"

typedef enum {
    s_class,
    s_method,
    s_tmp,
    s_null
}scope_type;

typedef enum {
    k_method,
    k_var    
}entity_kind;

class_data* current_class;
method_data* current_method;
scope *current_tmp_scope;

list<type_t> types;

scope_type curr_scope;
;

__unann_type global_type = __unann_type::__none;
int global_modifier = 0;
int scope = 0;

void inc_scope(){
    scope++;
}

void dec_scope() {
    scope--;
}

void append_type(list<type_t> &type_list, type_t new_type) {
    type_list.push_back(new_type);
}

void add_method(string mthd_name, list<type_t> &args_list, type_t ret_type) {
    if (curr_scope != s_class) {
        cout << "something seriously wrong here" << endl;
        exit(1);
    }
    string id = current_class->generate_id(mthd_name);
    current_class->add_method(id, args_list, ret_type);
}

void add_var(string var_name, type_t var_type) {
    string var_id;

    if (curr_scope == s_class) {
        var_id = current_class->generate_inst_var_id(var_name);    
        current_class->add_instance_var(var_id, var_type);
    }
    else if (curr_scope == s_method) {
        var_id = current_method->generate_var_id(var_name);
        current_method->add_var(var_id, var_type);
    }
    else if (curr_scope == s_tmp) {
        var_id = current_method->generate_var_id(var_name);
        current_tmp_scope->add_var(var_id, var_type);        
    }
    else {
        cout << "error in current scope. should not happen" << endl;
        exit(1);
    }
}

/* Here type is just single string*/
void check_type (type_t _type) {
    // Returns first token
    string token = strtok(str, "-");
   
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }
    if (types.find(_type) == types.end()){
        if(current_class->inner_class[])
    }
}

void check_method_call(type_t _type, string mthd_name) {
    // Here _type must be valid
    class_data *cls = 
}

void create_class_entry(int modifiers, char* name) {
    string class_name = name;

    if(scope == 0 && current_class == NULL) {
        if(global_class_list.find(class_name) != global_class_list.end()){
            cout << "Global Class Already present\n";
            exit(-1);
        }

        global_class_list[class_name] = new class_data(class_name, NULL);
        // types.push_back(class_name);
        current_class = global_class_list[class_name];
    }
    else {
        // string cls_id = current_class->
        current_class->add_inner_class(modifiers, class_name);
        // types.push_back(class_name);
        current_class = current_class->inner_class[class_name];
    }

    return;
}

void initialize_types() {
    types.push_back(INT);
    types.push_back(FLOAT);
    types.push_back(DOUBLE);
    types.push_back(CHAR);
    types.push_back(BYTE);
    types.push_back(LONG);
    types.push_back(BOOLEAN);
    types.push_back(SHORT);
}

int return_from_class(){
    current_class = current_class->container_cls;
}

