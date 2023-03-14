#define SYMBOL_H "symbol_h"
#include <iostream>
#include <string>

#ifndef METHOD_H
    #include <method.hpp>
#endif

#ifndef ACTIONS_H
    #include <actions.hpp>
#endif

using namespace std;

class symbol_data {
    public:


    method_data *container_mthd;

    string lexeme;
    int scope;
    int8_t modifier;
    type_t type;

    symbol_data(string _lexeme, int _scope, type_t _type, int8_t _modifier, bool is_ins_var) {
        if(is_ins_var)
            container_mthd = NULL;
        else 
            container_mthd = current_method;

        lexeme = _lexeme;
        scope = _scope;
        type = _type;
        modifier = _modifier;
    };

    bool set_modifier(int8_t);
};