#define SYMBOL_H "symbol_h"
#include <iostream>

#ifndef METHOD_H
    #include <method.hpp>
#endif

using namespace std;



typedef char* type_;

class symbol_data {
    public:

    method_data *container_mthd;

    char *lexeme;
    int scope;
    int8_t modifier;
    type_ t;

    symbol_data() {

    }  
};