
#include <symbol_table_fast.hpp>
#include <iostream>
#include <bits/stdc++.h>
#include <marcos.hpp>
#include <deque>
#include <string>

using namespace std;

LocalSymbolTable::LocalSymbolTable() {

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

void ClassDefinition::add_var(SymTabEntry *symbol) {
    SymTabEntry *sym = get_var( symbol->name );
    if ( !is_null(sym) ) {
        free(symbol);
        cerr << "declaration of variable with same name, previous declarationn at line: " << sym->line_no << endl;
        free( symbol );
        exit (1);
    }

    inst_vars.insert( {symbol->name, symbol} );
}

SymTabEntry* ClassDefinition::get_var(string name) {
    SymTabEntry *sym;
    sym = inst_vars.find(name);
    return sym;
}

Type* ClassDefinition::get_var_type(string name) {
    SymTabEntry *sym;
    Type *type;
    sym = get_var(name);
    
    if (is_null(sym))
        return NULL;
    
    type = sym->type;

    return type;}


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

MethodDefinition::MethodDefinition(string name, string args, Type *ret, int8_t modf) {
    this->name = name;
    this->args_str = args;
    this->ret_type = ret;
    this->modifier = modf;
}


