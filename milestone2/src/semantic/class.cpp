#include <class.hpp>

using namespace std;

void class_data::add_instance_var(int modifier, string type, char* id) {

    string name = id;
    if(this->instance_vars.find(name) != this->instance_vars.end()) {
        cout << "Variable already declared\n";
        exit(-1);
    } 

    this->instance_vars[name] = new symbol_data(name, scope, type, (__modifier)modifier);
}

void class_data::add_inner_cls(string cls_id, class_data *cls) {
    this->inner_class.insert({cls_id, cls});
}

void class_data::add_method(string mthd_id, list<type_t> args, type_t ret_type) {
    
    if (this->methods.find(mthd_id) != this->methods.find) {
        cout << ""
    }
    this->methods.insert({mthd_id, mthd});
}

string generate_id(string) {
    
}

bool class_data::set_modifier(int8_t modf){
    if (modf & this->modifier) {
        cout << "conflicting modifiers" << endl;
        return false;
    }
    this->modifier = this->modifier | modf;
    return true;
}

void class_data::add_inner_class(int modifiers, string name){
    /* Check if the inner class name is same as container classes*/
    class_data* itr = current_class;
    while(itr!=NULL){
        if(itr->id == class_name){
            cout << "Inner Class Already present\n";
            exit(-1);
        }

        itr = itr->container_cls;
    }
    
    if(current_class->inner_class.find(class_name) != current_class->inner_class.end()){
        cout << "Inner Class Already present\n";
        exit(-1);
    }

    class_name = current_class->generate_id(class_name);
    current_class->inner_class[class_name] = new class_data(class_name, current_class);
    current_class = current_class->inner_class[class_name];
}