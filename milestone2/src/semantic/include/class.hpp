#define CLASS_H "class_h"
#include <iostream>
#include <map>
#ifndef METHOD_H
    #include <method.hpp>
#endif

using namespace std;

class class_data {
    public:
    string   id;
    class_data *container_cls; // for inner classes
    class_data    *parent;
    map<string, method_data*>  methods;
    map<string, symbol_data*> instance_vars;
    map<string, class_data*> inner_class;
    int8_t modifier;

    class_data(string name) {
        parent = NULL;
        methods.clear();
        instance_vars.clear();
        inner_class.clear();
    };

    bool add_instance_var(string, symbol_data*);
    bool add_method(string, method_data*);
    bool add_inner_cls(string, class_data*);
    string generate_id(string);
    bool set_modifier(int8_t);
    void add_inner_class(int modifiers, char* name);
};


