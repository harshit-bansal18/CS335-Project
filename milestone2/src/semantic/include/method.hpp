#define METHOD_H "method_h"
#include <map>
#include <string>

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

    bool add_var(string, symbol_data*);
};

class method_data{
    public:
    string id;
    class_data *container_cls;
    struct scope *tmp_scope;
    int8_t modifier;
    map <string, symbol_data*> table;

    method_data(int8_t modifier_) {
        container_cls = current_class;
        modifier = modifier;
        table.clear();
    }

    bool add_var(string, symbol_data*);
    string generate_var_id(string);
    bool set_modifier();

};