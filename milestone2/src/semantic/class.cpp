#include <class.hpp>

using namespace std;

void class_data::add_instance_var(char *var_id, symbol_data *sym) {
    this->instance_vars.insert({var_id, sym});
}

void class_data::add_inner_cls(char *cls_id, class_data *cls) {
    this->inner_class.insert({cls_id, cls});
}

void class_data::add_method(char *mthd_id, method_data *mthd) {
    this->methods.insert({mthd_id, mthd});
}

bool class_data::set_modifier(){}