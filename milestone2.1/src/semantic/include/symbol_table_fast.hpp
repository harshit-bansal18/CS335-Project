#include <iostream>
#include <map>

using namespace std;

class Type {
  public:
  bool is_primitive;
  bool is_class;
  string name;
  size_t size;

  Type() {
    
  }
};

class SymTabEntry {
  public:
    string name;
    int level;
    Type type;
    unsigned int line_no;
    unsigned int col_no;
    size_t offset;
	  unsigned int id;

    SymTabEntry( string name_parameter, unsigned int line_no);
};

class FuncEnt : public SymTabEntry {
  public:
    string args;
    FuncEnt( string name, string type, string args );
};

class SymbolTable {

  public:
    SymbolTable();

	unsigned int symbol_id;
    stringstream ss;
    virtual SymTabEntry *get_symbol_from_table( string name );
    void delete_from_table( SymTabEntry *symbol );
    void print_table();
    virtual void add_to_table( SymTabEntry *symbol );
};

#define LOCAL_SYM_MASK 	0x10000000
#define GLOBAL_SYM_MASK 0x20000000
#define FUN_ARG_MASK 	0x40000000

class MethodDefinition {
  public:
  list<Type>
}
class ClassSymbolTable : public SymbolTable {
  public:
	size_t offset;
    map<string, Type> inst_var_table;
    map<string, SymTabEntry *> methods;
    void add_symbol( DeclarationSpecifiers *declaration_specifiers,
                     Declarator *declarator, int *error );
    void add_to_table( SymTabEntry *symbol, bool redef, Identifier *id );
    SymTabEntry *get_symbol_from_table( string name );
};

class LocalSymbolTable : public SymbolTable {

  public:
    map<string, deque<SymTabEntry *> &> sym_table;
    string function_name;
    size_t reqd_size;
    int current_level;
    size_t offset;
	Type return_type;
    void increase_level();
    void clear_current_level();
    void empty_table();
    LocalSymbolTable();
    void add_to_table( SymTabEntry *symbol, Identifier *id , bool is_fun_arg );
    SymTabEntry *get_symbol_from_table( string name );
    void add_function( DeclarationSpecifiers *declaration_specifiers,
                       Declarator *declarator, int *error );
};
