#include "method.hpp"
#include "actions.hpp"
#include "modifiers.hpp"

using namespace std;

bool method_data::dd_var(string var_name, symbol_data* var_data) {
    if(table.find(var_name) != table.end()){
      //variable in already present
        cout << "Variable already declared in scope\n";
        return false;
    }

    table[var_name] = var_data;
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
}