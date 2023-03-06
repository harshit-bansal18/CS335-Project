#define METHOD_H "method_h"
#include <map>

#ifndef SYMBOL_H
    #include <symbol.hpp>
#endif

#ifndef CLASS_H
    #include <class.hpp>
#endif


using namespace std;

struct scope {
    struct scope *parent;
    struct scope *child;
    map <string, symbol_data*> table;
};

class method_data{
    public:
    class_data *container_cls;
    struct scope *tmp_scope;
    int8_t modifier;
    map <char*, symbol_data*> table;

    method_data() {

    }

};