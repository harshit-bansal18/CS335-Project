#define CLASS_H "class_h"
#include <iostream>
#include <map>
#ifndef METHOD_H
    #include <method.hpp>
#endif


using namespace std;

class class_data {
    public:
    char*   id;
    class_data    *parent;
    map<string, method_data*>  methods;
    map<string, symbol_data*> instance_vars;
    map<string, class_data*> inner_class;
    int8_t modifier;

    class_data(char* name) {
        parent = NULL;
        methods.clear();
        instance_vars.clear();
        inner_class.clear();
    };

    bool add_instance_var(char*, symbol_data*);
    bool add_method(char*, method_data*);
    bool add_inner_cls(char*, class_data*);
    char* generate_method_id(char*);
    char* generate_inst_var_id(char*);
    bool set_modifier(int8_t);
};


