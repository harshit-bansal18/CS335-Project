
#ifndef SYMBOL_TABLE_FAST_H
#define SYMBOL_TABLE_FAST_H

#include <iostream>
#include <unordered_map>
#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <vector>

#include <macros.hpp>

#ifndef THREEAC_H
  #include <3ac.hpp>
#endif

using namespace std;

struct Address;
// #define VARIABLE "variable"
// #define FUNCTION "function"
// #define CONSTRUCTOR "constructor"
// #define OPEN_CONSTRUCTOR "open_constructor"
class ClassDefinition;
class MethodDefinition;
class SymTabEntry;
// class Type;

typedef struct Type {
  public:
  bool is_primitive;
  bool is_numeric;
  bool is_class;
  bool is_integral;
  // bool is_boolean;
  // bool is_int;
  // bool is_float;
  // bool is_char;
  // bool is_short;
  // bool is_double;

  unsigned int arr_dim;
  vector<Address*> arr_dim_val; 
  // stores array dimension values in reverse order 
  // eg. int a[2][3] => arr_dim_val = {3, 2}

  int size;
  string name;

  ClassDefinition *class_def;

  Type();
  Type(string, ClassDefinition*);
  Type(string, bool is_numeric, bool is_integral, size_t);
  // Type(string, bool is_numeric, size_t, unsigned int); // for array types
  // Type(string, ClassDefinition*, unsigned int); // for array types

  friend bool operator==(Type &obj1, Type &obj2);
  friend bool operator!=(Type &obj1, Type &obj2);

  bool is_pointer();
} Type;

class ClassDefinition {
  public:
  string name;
  unsigned long line_no;
  int8_t modifier;
  unordered_map<string, SymTabEntry *> inst_vars;
  unordered_map<string, deque< MethodDefinition *> &> methods;
  vector< MethodDefinition *> constructors;
  bool first_constructor_done;
  size_t class_width;
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

  ClassDefinition(string, int8_t, unsigned long);
  
  void add_method(MethodDefinition *method);
  // void add_inner_class(ClassDefinition *cls);
  void add_constructor(MethodDefinition *);
  void add_var(SymTabEntry*);
  Type *get_var_type(string);
  SymTabEntry* get_var(string);
  MethodDefinition *get_method(string, vector<Type*>&);
  MethodDefinition *get_method_call(string, vector<Type*>&);
  MethodDefinition find_constructor(vector<Type*>&);
  MethodDefinition *get_constructor(vector<Type *>&);
  void is_final_var_initialized();
};

class Terminal {
  public:
  string name;
  unsigned long line_no;
};

typedef struct Identifier {
  public:
  string name;
  Type *type;
  size_t offset;
  unsigned long line_no;
  bool is_initialized;
  Identifier(const char* name, unsigned long line_no);
} Identifier;

typedef struct TypeName {
    public:
    vector<Identifier *> names;
    Address* tac;
    TypeName(Identifier *id);
    void append_name(Identifier *id);
} TypeName;

class SymTabEntry {
  public:
    string name;
    int level;
    Type *type;
    Address* tac;
    unsigned long line_no;
    unsigned int col_no;
    size_t offset;
    int8_t modifier;
    bool is_initialized;
    bool is_private;
    bool is_static;
    bool is_final;
    bool is_instance_var;
    bool is_final_initialized;
    SymTabEntry( string name_parameter, Type *type, int8_t modf, unsigned int line_no);
};

// class FuncEnt : public SymTabEntry {
//   public:
//     string args;
//     FuncEnt( string name, string type, string args );
// };

class SymbolTable {

  public:
    SymbolTable();

    // unsigned int symbol_id;
    stringstream ss;
    // virtual SymTabEntry *get_symbol_from_table( string name );
    void delete_from_table( SymTabEntry *symbol );
    void print_table();
    // virtual void add_to_table( SymTabEntry *symbol );
};

#define LOCAL_SYM_MASK 	0x10000000
// #define GLOBAL_SYM_MASK 0x20000000
#define FUN_ARG_MASK 	0x40000000

class MethodDefinition {
  public:
  string name;
  vector<Type *> args;
  Type *ret_type;
  int8_t modifier;
  size_t method_width;
  // vector<Quad *> three_ac;
  unsigned long line_no;

  bool is_private;
  bool is_static;
  MethodDefinition();
  MethodDefinition(string, vector<Type*>&, Type*, int8_t, unsigned long );

};

class GlobalSymbolTable : public SymbolTable {
  public:
    size_t offset;

    GlobalSymbolTable();
    unordered_map<string, ClassDefinition *> classes;
    void add_class( ClassDefinition *cls );
    ClassDefinition *get_class( string name );
    void dump_table();
};

class LocalSymbolTable : public SymbolTable {


  public:
  int current_level;
    unordered_map<string, SymTabEntry *> sym_table;
    string method_name;
    size_t reqd_size;
    string nature;
    size_t offset;
    Type *return_type;
    ClassDefinition *container_class;
    MethodDefinition *method;
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

  
#endif