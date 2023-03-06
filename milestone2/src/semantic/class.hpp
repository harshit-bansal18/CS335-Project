#define CLASS_H "class_h"
#include <iostream>
#include <map>
#ifndef METHOD_H
    #include <method.hpp>
#endif


using namespace std;

class class_data {
    public:
    class_data    *parent;
    map<string, method_data*>  methods;
    map<string, symbol_data*> instance_vars;
    map<string, class_data*> inner_clss;
    int8_t modifier;

    class_data() {
        parent = NULL;
        methods.clear();
        instance_vars.clear();
        inner_clss.clear();
    };

};