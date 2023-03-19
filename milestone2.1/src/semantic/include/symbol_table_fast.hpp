#include <iostream>
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

class Type {
  public:
  bool is_primitive;
  bool is_numeric;
  bool is_class;
  string name;
  size_t size;

  ClassDefinition *class_def;

  Type();

  friend bool operator==(Type &obj1, Type &obj2);
  friend bool operator!=(Type &obj1, Type &obj2);

};

class Terminal {
  public:
  string name;
};

class TypeName {
  public:
  vector<Identifier *> names;
  TypeName(Identifier *id);
  void append_name(Identifier *id);
};

class Identifier : public Terminal {
  public:
  Identifier(const char *name);
  Identifier(const char* name, unsigned long line_no);
};

class SymTabEntry {
  public:
    string name;
    int level;
    Type *type;
    unsigned int line_no;
    unsigned int col_no;
    size_t offset;
	  unsigned int id;
    int8_t modifier;

    SymTabEntry( string name_parameter, unsigned int line_no);
};

// class FuncEnt : public SymTabEntry {
//   public:
//     string args;
//     FuncEnt( string name, string type, string args );
// };

class SymbolTable {

  public:
    SymbolTable();

	unsigned int symbol_id;
    // stringstream ss;
    virtual SymTabEntry *get_symbol_from_table( string name );
    void delete_from_table( SymTabEntry *symbol );
    void print_table();
    virtual void add_to_table( SymTabEntry *symbol );
};

#define LOCAL_SYM_MASK 	0x10000000
// #define GLOBAL_SYM_MASK 0x20000000
#define FUN_ARG_MASK 	0x40000000

class MethodDefinition {
  public:
  string name;
  list<Type *> args;
  Type *ret_type;
  int8_t modifier;
  string args_str;

  unsigned long line_no;

  bool defined;
  MethodDefinition();
  MethodDefinition(string, list<Type>, Type*);
  MethodDefinition(string, string, Type*, int8_t, unsigned long );

};

class ClassDefinition {
  public:
  string name;
  
  int8_t modifier;
  map<string, SymTabEntry *> inst_vars;
  map<string, deque< MethodDefinition *> &> methods;
  // map<string, ClassDefinition *> inner_classes;
  // list<ClassDefinition *> impl_interfaces;
  // ClassDefinition *parent;
  // ClassDefinition *container_class;

  bool is_interface;
  bool is_static;
  bool is_final;
  bool is_public;
  bool is_private;
  bool is_inner_class;

  ClassDefinition(string, int8_t);
  
  void add_method(MethodDefinition *method);
  void add_inner_class(ClassDefinition *cls);
  void add_var(SymTabEntry*);
  Type *get_var_type(string);
  SymTabEntry* get_var(stringg;=n)
  MethodDefinition *get_metd(string);
};

// class GlobalSymbolTable : public SymbolTable {
//   public:
// 	size_t offset;
//     map<string, Type> inst_var_table;
//     map<string, SymTabEntry *> methods;
//     void add_symbol( DeclarationSpecifiers *declaration_specifiers,
//                      Declarator *declarator, int *error );
//     void add_to_table( SymTabEntry *symbol, bool redef, Identifier *id );
//     SymTabEntry *get_symbol_from_table( string name );
// };

class LocalSymbolTable : public SymbolTable {

  public:
    map<string, SymTabEntry *> sym_table;
    string method_name;
    size_t reqd_size;
    int current_level;
    size_t offset;
	  Type *return_type;
    ClassDefinition *container_class;

    void increase_level();
    void clear_current_level();
    void empty_table();
    LocalSymbolTable();
    void add_to_table( SymTabEntry *symbol, bool is_fun_arg );
    SymTabEntry *get_symbol_from_table( string name );
    SymTabEntry *get_symbol_from_class( string name );
    // void add_function( DeclarationSpecifiers *declaration_specifiers,
                      //  Declarator *declarator, int *error );
  };
