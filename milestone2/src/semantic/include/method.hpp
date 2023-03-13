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

    bool add_var(char*, symbol_data*);
};

class method_data{
    public:
    class_data *container_cls;
    struct scope *tmp_scope;
    int8_t modifier;
    map <char*, symbol_data*> table;

    method_data(class_data* container_cls ) {
        
    }

    bool add_var(char*, symbol_data*);
    char* generate_var_id(char*);
    bool set_modifier();

};