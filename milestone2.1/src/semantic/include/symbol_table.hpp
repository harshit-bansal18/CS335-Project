#ifndef SYMBOL_TABLE_H
    #define SYMBOL_TABLE_H
#endif

#include <bits/stdc++.h>
#include <cstring> 

using namespace std;

typedef struct class_struct {
    string token;           //key
    int scope;              
    int8_t modifier;           //public, private, static, final
    string nature;          // class or function or variable etc.
    int offset;
    int lineno;
    class_struct* parent_class;

    map<string, stackentry*> instance_variables;
    map<string, stackentry*> class_methods;
}class_struct;

typedef struct method_struct {
    class_struct* parent_class;
    string token;           //key
    int scope;              
    int8_t modifier;           //public, private, static, final
    string argument_type;   //argument list of function
    string type;            // type for variable and return type for function
    string nature;          // class or function or variable etc.
    string variable_init_status;
    int offset;
    int lineno;

    map<string, stackentry*> local_method_scope;
} method_struct;

typedef struct stackentry {
    string token;           //key
    int scope;              
    int8_t modifier;           //public, private, static, final
    string argument_type;   //argument list of function
    string type;            // type for variable and return type for function
    string nature;          // class or function or variable etc.
    string variable_init_status;
    int offset;
    int lineno;
} stackentry;

// class Type {
//   public:
//   bool isPrimitive;
//   bool isClass;
//   string type;
// };

#define CLASS "class"
#define VARIABLE "variable"
#define FUNCTION "function"
#define OPEN_FUNCTION "open_function"
#define CONSTRUCTOR "constructor"
#define OPEN_CONSTRUCTOR "open_constructor"

#define __PUBLIC 0b11
#define __PRIVATE 0b10
#define __STATIC 0b100
#define __FINAL 0b1000

#define __DOUBLE "double"
#define __FLOAT "float"
#define __LONG "long"
#define __INT "int"
#define __SHORT "short"
#define __BYTE "byte"
#define __CHAR "char"
// #define __NULL "null"
#define __BOOLEAN "boolean"
#define __VAR "var"
#define __VOID "void"

#define __INITIALIZED "initialized"
#define __UNINITIALIZED "uninitialized"



struct stackentry* new_entry();

int8_t set_modifier(int8_t curr_modf, int8_t new_modf);

bool check_primitive_types(string type);

bool check_if_numeric_type(string type);

bool check_return_type(string type1, string type2);

string check_function_in_class( vector< stackentry* > &stack, string token, string argument_type, string nature);

////////////////////// Jaya Open //////////////////////////////////
stackentry* get_variable_stackentry(vector< stackentry* > &stack, string token);

stackentry* find_variable_in_class( vector< stackentry* > &stack, string token);
////////////////////// Jaya Close /////////////////////////////////


// Function used when we need to add a new variable or declare a variable
bool find_variable_in_closest_function_scope( vector< stackentry* > &stack, string token, int scope );

void add_to_stack( vector< stackentry* > &stack, string token, int scope, string type, int modifier, string nature, int offset, string argument_type, string variable_init_status);

void clear_scope( vector< stackentry* > &stack, int scope );

class_struct* create_class_entry();

void add_class(int8_t modifier, string token);


void add_variable(string token, int8_t modifier, string type, bool init_flag);

void add_function(string token, string argument_type, string return_type, int8_t modifier) ;

void add_constructor(string token, string argument_type, string return_type, int8_t modifier, int scope);

void dump_symbol(stackentry* v);
void dump_entry(vector<stackentry*> v);
void dump_ST(int );
void dump_SS();