
#include <symbol_table_fast.hpp>
#ifndef ACTIONS_FAST_H
    #include <actions_fast.hpp>
#endif

#include <iostream>
#include <bits/stdc++.h>
#include <macros.hpp>
#include <deque>
#include <string>

using namespace std;

SymbolTable::SymbolTable(){
}

SymTabEntry::SymTabEntry( string name_parameter, unsigned int line_no) {
    this->name = name_parameter;
    this->line_no = line_no;
    this->is_initialized = false;
}

LocalSymbolTable::LocalSymbolTable() {
    sym_table.clear();
    current_level =0;
}

void LocalSymbolTable::increase_level() {
    current_level++;
}

void LocalSymbolTable::clear_current_level() {
    SymTabEntry *sym_entry;

    for (auto &it : sym_table) {
        sym_entry = it.second;
        if ( !sym_entry ) continue;

        else if (sym_entry->level == current_level ) {
            free(it.second);
            sym_table.erase(it.first);
        }
    }

    current_level--;
    //write to file now using stringstream
}

void LocalSymbolTable::empty_table() {
    sym_table.clear();
    current_level = 0;
    method_name = "";
    return_type = NULL;
    container_class = NULL;
}

void LocalSymbolTable::add_to_table(SymTabEntry *symbol, bool is_fun_arg) {
    auto it = sym_table.find(symbol->name);
    if (it == sym_table.end()) {
        symbol->level = current_level;
        symbol->is_initialized = is_fun_arg;
        sym_table.insert( {symbol->name, symbol} );
    }
    else  {
        cerr << "identifier declared with same name. previous declaration at line: " << it->second->line_no << endl;
        exit (1);
    }
}

SymTabEntry* LocalSymbolTable::get_symbol_from_table(string name) {
    auto it = sym_table.find(name);
    if (it == sym_table.end()) {
        return NULL;
    }
    return it->second;
}

SymTabEntry* LocalSymbolTable::get_symbol_from_class(string name) {
    SymTabEntry *sym;

    sym = get_symbol_from_table(name);
    if (!is_null(sym))
        return sym;


    sym = container_class->get_var(name);

    /*
        Check for parent classes when using inheritence 
    */
    return sym;
}

ClassDefinition::ClassDefinition(string name, int8_t modf, unsigned long line) {
    this->name = name;
    this->modifier = modf;
    this->line_no = line;
    inst_vars.clear();
    methods.clear();
    constructors.clear();
    /*
        set bools here if required
    */

}

void ClassDefinition::add_method(MethodDefinition *mthd) {
    auto it = methods.find(mthd->name);
    if (it == methods.end()) {
        deque<MethodDefinition *> &q = *new deque< MethodDefinition *>;
        q.push_front( mthd );
        methods.insert( {mthd->name, q} );
    }
    else {
        deque<MethodDefinition *> &q = it->second;
        for (auto &m : q) {
            if (m->args_str == mthd->args_str) {
                cerr << "declaration of function with same again, previous declaration at line: " << m->line_no << endl;
                free(mthd);
                exit (1);
            }
        }
        q.push_front(mthd);
    }
}

void ClassDefinition::add_constructor(MethodDefinition *constr) {
    if (constr->name != this->name) {
        free(constr);
        cerr << constr->name << "does not match " << this->name << ". constructor name should be same as class name" << endl;
        exit (1);
    }
    for (auto c : constructors) {
        if (c->args_str == constr->args_str) {
            free(constr);
            cerr << "multiple definitions of constructor found. first defined at line: " << c->line_no << endl;
            exit (1);
        } 
    }
    constructors.push_back(constr);
}

void ClassDefinition::add_var(SymTabEntry *symbol) {
    SymTabEntry *sym = get_var( symbol->name );
    if ( !is_null(sym) ) {
        free(symbol);
        cerr << "declaration of variable with same name, previous declaration at line: " << sym->line_no << endl;
        exit (1);
    }

    symbol->is_initialized = true;
    inst_vars.insert( {symbol->name, symbol} );
}

SymTabEntry* ClassDefinition::get_var(string name) {
    auto it = inst_vars.find(name);
    if (it == inst_vars.end()) {
        return NULL;
    }
    return it->second;
}

Type* ClassDefinition::get_var_type(string name) {
    SymTabEntry *sym;
    Type *type;
    sym = get_var(name);
    
    if (is_null(sym))
        return NULL;
    
    type = sym->type;

    return type;
}


MethodDefinition* ClassDefinition::get_method(string name, string args) {

    auto it = methods.find(name);
    if (it == methods.end()) {
        return NULL;
    }
    else {
        for( auto &m: it->second) {
            if (m->args_str == args) {
                return m;
            }
        }
    }
    return NULL;
}

bool ClassDefinition::find_constructor(string args) {
    if (constructors.empty() && args == "")
        return true;
    
    for( auto c: constructors) {
        if (c->args_str == args) {
            return true;
        }
    }
    
    return false;
}

MethodDefinition::MethodDefinition(string name, string args, Type *ret, int8_t modf, unsigned long line) {
    this->name = name;
    this->args_str = args;
    this->ret_type = ret;
    this->modifier = modf;
    this->line_no = line;
}

Type::Type() {
    //empty constructor
    this->name = "";
    this->class_def = NULL;
}

Type::Type(string name, ClassDefinition *cls) {
    this->name = name;
    this->class_def = cls;
    this->is_primitive = false;
    this->is_numeric = false;
    this->is_class = true;
    this->is_integral = false;
}

// Type::Type(string name, bool is_numeric, size_t size) {
//     this->name = name;
//     this->is_numeric = is_numeric;
//     this->is_integral = false;
//     this->size = size;
//     this->is_primitive = true;
//     this->is_class = false;
//     this->class_def = NULL;
// }

Type::Type(string name, bool is_numeric, bool is_integral, size_t size) {
    this->name = name;
    this->is_numeric = is_numeric;
    this->is_integral = is_integral;
    this->size = size;
    this->is_primitive = true;
    this->is_class = false;
    this->class_def = NULL;
}

bool Type::is_pointer() {
    return (arr_dim != 0);
}

bool operator==(Type &obj1, Type &obj2) {
    // cout << "Type Names: " << obj1.name << " " << obj2.name << "\n";
    
    if (obj1.is_class && obj2.is_class) {
        // both are ref types
        return ((obj1.name == obj2.name) && (obj1.arr_dim == obj2.arr_dim));
    }
    else if( obj1.is_primitive && obj2.is_primitive ) {
        if (obj1.is_numeric && obj2.is_numeric) {
            if(obj1.name == __SHORT && obj2.name == __CHAR){
                return false;
            }
            return (obj1.size > obj2.size) && (obj1.arr_dim == obj2.arr_dim);
        }
        else return ((obj1.name == obj2.name) && (obj1.arr_dim == obj2.arr_dim));
    }

    return false;
}

bool operator!=(Type &obj1, Type &obj2) {
    return !(obj1 == obj2);
}

GlobalSymbolTable::GlobalSymbolTable() {
    this->classes.clear();
    this->offset = 0;
}

void GlobalSymbolTable::add_class( ClassDefinition *cls ) {
    auto it = classes.find(cls->name);
    if ( it != classes.end() ) {
        free(cls);
        cerr << "class declared with same name again. previous declaration at line: " << it->second->line_no << endl;
        exit (1);
    }

    classes.insert( {cls->name, cls} );
    
}

ClassDefinition *GlobalSymbolTable::get_class( string name ) {
    auto it = classes.find(name);
    if(it == classes.end()) {
        return NULL;
    }
    return it->second;
}

void GlobalSymbolTable::dump_table() {
    ClassDefinition *cls;
    for(auto it : classes) {
        // print classes information
        cls = it.second;
        cout << cls->name << endl;
        cout << "modifier: ";
        print_modifier(cls->modifier);
        cout << endl;
        cout << "entering for loop" <<  endl;
        if (cls->inst_vars.empty()) {
            cout << "instance variables not prsent\n";
        }
        for (auto it2:cls->inst_vars) {
            cout << it2.second->name << endl;
            cout << "Type: " << it2.second->type->name << endl;
        }
        cout << "entering for loop 2" <<  endl;
        for( auto it2: cls->methods) {
            auto &q = it2.second;
            for (auto it3 : q) {
                cout << it3->name << " args: " << it3->args_str << "ret type: " << it3->ret_type->name << "modifier: " << it3->modifier <<  endl;
            }
        }   
        cout << "entering for loop 3" <<  endl;
        
        for(auto it2: cls->constructors) {
            cout << it2->name << " args: " << it2->args_str << "ret type: " << it2->ret_type->name << "modifier: " << it2->modifier <<  endl;
        }

    }
}

Identifier::Identifier(const char *name, unsigned long line) {
    this->name = name;
    this->line_no = line;
}

TypeName::TypeName(Identifier *id) {
    this->names.push_back(id);
}

void TypeName::append_name(Identifier *id) {
    this->names.push_back(id);
}
