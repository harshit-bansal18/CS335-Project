
#include <symbol_table_fast.hpp>
#ifndef ACTIONS_FAST_H
    #include <actions_fast.hpp>
#endif

#include <iostream>
#include <bits/stdc++.h>
#include <macros.hpp>
#include <deque>
#include <string>
#include <iomanip>

using namespace std;

extern "C" int yylineno;

SymbolTable::SymbolTable(){
}

SymTabEntry::SymTabEntry( string name_parameter, Type *type, int8_t modf, unsigned int line_no) {
    this->name = name_parameter;
    this->line_no = line_no;
    this->type = type;
    this->modifier = modf;
    this->is_initialized = false;
    this->is_final_initialized = false;
    this->is_final = false;
    this->is_private = false;
    this->is_static = false;

    if((modf & __PUBLIC) == __PUBLIC)
        this->is_private = false;
    else if((modf & __PRIVATE) == __PRIVATE)
        this->is_private = true;
    
    if((modf & __STATIC) == __STATIC)
        this->is_static = true;
    
    if ((modf & __FINAL) == __FINAL)
        this->is_final = true;
}

LocalSymbolTable::LocalSymbolTable() {
    sym_table.clear();
    current_level =0;
    ss.clear();
    ss.str(string());   
}

void LocalSymbolTable::increase_level() {
    current_level++;
    // cout << ss.str() << endl;
    // ss.clear();
    // ss.str(string());
}

void LocalSymbolTable::clear_current_level() {

    SymTabEntry *sym_entry;

    vector<string> keys;
    for (auto &it : sym_table) {
        
        sym_entry = it.second;
        
        if ( !sym_entry ) continue;

        else if (sym_entry->level == current_level ) {
            if(it.second == NULL) {
                cerr << "Error Line No: " << yylineno << ": " << __func__ << " : Null Pointer cant be freed\n";
                exit(1);
            }
            free(it.second);
            it.second = NULL;
            keys.push_back(it.first);
        }
    }
    for(auto k:keys) {
        sym_table.erase(k);
    }
    current_level--;

    //write to file now using stringstream
    cout << ss.str() << "\n";
    ss.clear();
    ss.str(string());
}

void LocalSymbolTable::empty_table() {
    sym_table.clear();
    current_level = 0;
    method_name = "";
    return_type = NULL;
    container_class = NULL;
    cout << ss.str() << endl;
    ss.clear();
    ss.str(string());
}

void LocalSymbolTable::add_to_table(SymTabEntry *symbol, bool is_fun_arg) {
    auto it = sym_table.find(symbol->name);
    if (it == sym_table.end()) {
        symbol->level = current_level;
        symbol->is_initialized = is_fun_arg;
        symbol->is_instance_var = false;
        sym_table.insert( {symbol->name, symbol} );

        ss << "Identifier," << symbol->name << "," << symbol->type->name;
        for(int count = 0; count < symbol->type->arr_dim; count++)
            ss << "[]";
        ss << ",";
        if ((symbol->modifier & __PUBLIC) == __PUBLIC)
            ss << "public ";
        else if ((symbol->modifier & __PRIVATE) == __PRIVATE)
            ss << "private ";
        
        if ((symbol->modifier & __STATIC) == __STATIC)
            ss << "static ";
        
        if((symbol->modifier & __FINAL) == __FINAL)
            ss << "final ";
        
        ss << "," << symbol->line_no << "," <<  symbol->level << "\n";

    }
    else  {
        cerr << "Error Line No: " << yylineno << ":identifier declared with same name. previous declaration at line: " << it->second->line_no << endl;
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
    this->first_constructor_done = false;
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
            if (compare_argument_types_exact(m->args, mthd->args)) {
                cerr << "Error Line No: " << yylineno << ":declaration of function with same again, previous declaration at line: " << m->line_no << endl;
                if(mthd == NULL) {
                    cerr << "Error Line No: " << yylineno << ": " << __func__ << " : Null Pointer cant be freed\n";
                    exit(1);
                }
                free(mthd);
                mthd = NULL;
                exit (1);
            }
        }
        q.push_front(mthd);
    }
}

void ClassDefinition::add_constructor(MethodDefinition *constr) {
    if (constr->name != this->name) {
        if(constr == NULL) {
            cerr << "Error Line No: " << yylineno << ": " << __func__ << " : Null Pointer cant be freed\n";
            exit(1);
        }
        free(constr);
        constr = NULL;
        cerr << "Error Line No: " << yylineno << ":" << constr->name << "does not match " << this->name << ". constructor name should be same as class name" << endl;
        exit (1);
    }
    for (auto c : constructors) {
        if (compare_argument_types_exact(c->args, constr->args)) {
            if(constr == NULL) {
                cerr << "Error Line No: " << yylineno << ": " << __func__ << " : Null Pointer cant be freed\n";
                exit(1);
            }
            free(constr);
            constr = NULL;
            cerr << "Error Line No: " << yylineno << ":multiple definitions of constructor found. first defined at line: " << c->line_no << endl;
            exit (1);
        } 
    }
    constructors.push_back(constr);
}

void ClassDefinition::add_var(SymTabEntry *symbol) {
    /* Check if instance variable is declared with same class types in current class*/
    if (symbol->type->name == this->name) {
        cerr << "Error on line " << yylineno << ": variable of same class declared in the class instance variables\n";
        exit(1);
    }
    /* Check for previous declaration of instance variable with same name*/
    SymTabEntry *sym = get_var( symbol->name );
    if ( !is_null(sym) ) {
        if(symbol == NULL) {
            cerr << "Error Line No: " << yylineno << ": " << __func__ << " : Null Pointer cant be freed\n";
            exit(1);
        }
        free(symbol);
        symbol = NULL;
        cerr << "Error Line No: " << yylineno << ":declaration of variable with same name, previous declaration at line: " << sym->line_no << endl;
        exit (1);
    }
    
    symbol->is_initialized = true;
    symbol->is_instance_var = true;
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


MethodDefinition *ClassDefinition::get_method_call(string name, vector<Type *> &args) {
    auto it = methods.find(name);
    if (it == methods.end()) {
        return NULL;
    }
    else {
        for( auto m: it->second) {
            if (compare_argument_types_exact(m->args, args)) {
                return m;
            }
        }
        for( auto m: it->second) {
            if (compare_argument_types(m->args, args)) {
                return m;
            }
        }
    }
    return NULL;
}
MethodDefinition* ClassDefinition::get_method(string name, vector<Type*> &args) {

    auto it = methods.find(name);
    if (it == methods.end()) {
        return NULL;
    }
    else {
        for( auto m: it->second) {
            if (compare_argument_types_exact(m->args, args)) {
                return m;
            }
        }
    }
    return NULL;
}

bool ClassDefinition::find_constructor(vector<Type*> &args) {
    if (constructors.empty() && args.empty())
        return true;
    
    for( auto c: constructors) {
        if (compare_argument_types(c->args, args)) {
            return true;
        }
    }
    
    return false;
}

MethodDefinition *ClassDefinition::get_constructor(vector<Type*> &args) {
    
    for(auto c : constructors) {
        if (compare_argument_types_exact(c->args, args)) {
            return c;
        }
    }

    return NULL;
}

void ClassDefinition::is_final_var_initialized() {
    

    for(auto sym : inst_vars) {
        if (sym.second->is_final && !sym.second->is_final_initialized) {
            cerr << "Error Line No: " << yylineno << ": "<< name << ": final variable " << sym.second->name << " is not initialized in the constructor\n";
            exit(1);
        }
        sym.second->is_final_initialized = !first_constructor_done;
    }
    if (!first_constructor_done) first_constructor_done = true;
}

MethodDefinition::MethodDefinition(string name, vector<Type *> &args, Type *ret, int8_t modf, unsigned long line) {
    this->name = name;
    this->args = args;
    this->ret_type = ret;
    this->modifier = modf;
    this->line_no = line;
    
    if((modf & __PUBLIC) == __PUBLIC)
        this->is_private = false;
    else if((modf & __PRIVATE) == __PRIVATE)
        this->is_private = true;
    
    if((modf & __STATIC) == __STATIC)
        this->is_static = true;
     
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
    // cout << obj1.is_primitive << " " << obj2.is_primitive << "\n";
    // cout << obj1.is_numeric << " " << obj2.is_numeric << "\n";
    // cout << obj1.arr_dim << " " << obj2.arr_dim << "\n";

    if (obj1.is_class && obj2.is_class) {
        // both are ref types
        return ((obj1.name == obj2.name) && (obj1.arr_dim == obj2.arr_dim));
    }
    else if( obj1.is_primitive && obj2.is_primitive ) {
        if (obj1.is_numeric && obj2.is_numeric) {
            if(obj1.name == __SHORT && obj2.name == __CHAR){
                return false;
            }

            if(obj1.is_integral && !(obj2.is_integral)){
                return false;
            }

            return (obj1.size >= obj2.size) && (obj1.arr_dim == obj2.arr_dim);
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
        if(cls == NULL) {
            cerr << "Error Line No: " << yylineno << ": " << __func__ << " : Null Pointer cant be freed\n";
            exit(1);
        }
        free(cls);
        cls = NULL;
        cerr << "Error Line No: " << yylineno << " :class declared with same name again. previous declaration at line: " << it->second->line_no << endl;
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
    // cout << "Name" << "\t \t" << "Scope" << "\t \t" << "Modifier" << "\t \t" << "Nature" << "\t \t" << "Offset" << "\t \t" << "Line Num" << "\t \t" << "\n";
    for(auto it : classes) {
        // print classes information
        // std::cout << "############################CLASS##################################\n";
        cls = it.second;
        freopen((DUMP_DIR + cls->name + ".st").c_str(), "w", stdout);

        std::cout << cls->name << "\t \t" << 0 << "\t \t";
        print_modifier(cls->modifier);
        cout << "\t \t" << "Class" << "\t \t" << "#print sum of ins var" << "\t \t" << cls->line_no << "\t \t" << "\n";


        if (cls->inst_vars.empty()) {
            cout << "~~~~~~~~~~~instance variables not prsent~~~~~~~~~~~~~~~~~~~\n";
        } else{
            cout << "~~~~~~~~~~~~~~~INSTANCE_VARIABLES~~~~~~~~~~~~~~~~\n";
            SymTabEntry* ins;
            for (auto it2:cls->inst_vars) {
                ins = it2.second;
                cout << ins->name << "\t \t" << ins->level << "\t \t" ;
                print_modifier(ins->modifier);
                cout << "\t \t" << "Variable" << "\t \t" << ins->offset << "\t \t" << ins->line_no << "\t \t" << "\n";
                cout << "Extra Information: \n";
                cout << "\t Is Initialised: " << ins->is_initialized << "\n";
                print_type(ins->type);
                cout << "\n";
            }
        }

        cout << "\n\n";
        cout << "~~~~~~~~~~~~~~~CLASS_METHODS~~~~~~~~~~~~~~~~\n";
        for( auto it2: cls->methods) {
            auto &q = it2.second;
            for (auto it3 : q) {
                cout << it3->name << "\t \t" << 0 << "\t \t";
                print_modifier(it3->modifier);
                cout << "\t \t" << "Function" << "\t \t" << 0 << "\t \t" << it3->line_no << "\t \t" << "\n";
                cout << "Extra Information: \n";
                cout << "Return Type: ";
                print_type(it3->ret_type);
                cout << "Args Str: ";
                for(auto t:it3->args) cout << t->name << " ";
                cout << "\n";
            }
        }   
        cout << "\n\n";
        cout << "~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~\n";
        for(auto it2: cls->constructors) {
            cout << it2->name << "\t \t" << 0 << "\t \t";
                print_modifier(it2->modifier);
                cout << "\t \t" << "Constructor" << "\t \t" << 0 << "\t \t" << it2->line_no << "\t \t" << "\n";
                cout << "Extra Information: \n";
                cout << "Args Str: ";
                for(auto t:it2->args) cout << t->name << " ";
                cout << "\n";
        }

        cout << "############################CLASS_ENd##################################\n\n";
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
