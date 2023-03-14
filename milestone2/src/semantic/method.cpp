#include "method.hpp"
#include "actions.hpp"
#include "modifiers.hpp"

using namespace std;

bool method_data::dd_var(string var_name, symbol_data* var_data) {
    if(this->table.find(var_name) != this->table.end()){
      //variable in already present
        cout << "Variable already declared in scope\n";
        return false;
    }

    this->table[var_name] = var_data;
    return true;
}

string method_data::generate_var_id(string var_name) {
    return current_method+"."+var_name;
}

bool method_data::set_modifier(int8_t modf) {
    if (modf && this->modifier) {
        cout << "conflicting modifiers" << endl;
        return false;
    }

    this->modifier = this->modifier | modf;
    return true;
}

bool method_data::check_valid_decl(string var_id) {
    /*
        check for previous declaration in this method, if found throw error
    */
    if (this->table.find(var_id) != this->table.end()) {
        cout << "variable already declared in this scope" << endl;
        return false;
    }
    return true;
}

bool method_data::check_valid_access(string var_id, type_t var_type) {
    auto itr = this->table.find(var_id);
    if (itr == this->table.end()) {
        itr = 
    }
}