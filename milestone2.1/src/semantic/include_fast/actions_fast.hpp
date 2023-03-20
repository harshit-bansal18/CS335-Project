#ifndef ACTIONS_FAST_H
    #define ACTIONS_FAST_H
#endif

#ifndef MACROS_H 
    #include <macros.hpp>
#endif

#include <inttypes.h>
#include <symbol_table_fast.hpp>
#include <bits/stdc++.h>

using namespace std;
typedef enum {
    scope_global,
    scope_class,
    scope_method
} scope;

class stackentry {
    public:
    string token;           //key
    scope scope;              
    int8_t modifier;           //public, private, static, final
    string argument_type;   //argument list of function
    Type *type;            // type for variable and return type for function
    string nature;          // class or function or variable etc.
    bool is_var_intialized;
    int offset;
    unsigned long line_no;

    stackentry(const char *name, unsigned long line);

};

int8_t set_modifier(int8_t curr_modf, int8_t new_modf);
void increase_current_level();
bool check_primitive_types(Type *type);
bool check_if_numeric_type(Type *type);
bool check_return_type(Type *type1, Type *type2);
Type *check_function_in_class(string token, string argument_type, string nature);
stackentry *find_variable_in_class( string token, bool );
bool find_variable_in_closest_function_scope( string token );
void clear_current_scope( );
void add_class(int8_t modifier, string token);
void add_variable(string token, int8_t modifier, Type *type, bool is_fun_arg);
void add_function(string token, string argument_type, Type* return_type, int8_t modifier);
void add_constructor(string token, string argument_type, int8_t modifier);
Type *get_type(string name);
Identifier *make_identifier(const char *name);
TypeName *make_typename(Identifier *id) ;
void append_typename(Identifier *id, TypeName *tn);
stackentry *make_stackentry(const char *token, unsigned int);

stackentry *make_stackentry(const char *token, string type, unsigned int );

void check_boolean(Type *t);

void check_cast_types(Type *t1, Type *t2);
Type *get_array_type();
Type *get_array_type(string name);
stackentry *increase_dims(stackentry *e);

stackentry *assign_arr_dim(stackentry *e1, stackentry *e2);
stackentry *assign_arr_dim(Type *t, stackentry *e1, stackentry *e2);
stackentry *assign_arr_dim(Type *t, stackentry *e1);

stackentry *check_multiplicative_types(stackentry *e1, stackentry *e2);

stackentry* check_additive_types(stackentry* e1, stackentry* e2);

stackentry* ShiftExpression(stackentry* e1, stackentry* e2);

stackentry* RelationalExpression(stackentry* e1, stackentry* e2);

stackentry* EqualityExpression(stackentry* e1, stackentry* e2);

stackentry* BitwiseExpression (stackentry* e1, stackentry* e2);

stackentry* ConditionalExpression (stackentry* e1, stackentry* e2);
Type* ClassOrInterfaceType(stackentry* e1);
void VariableDeclarator(stackentry* e1, stackentry* e2, int rule_no);
void IfCondition(stackentry* e1);
void WhileCondition(stackentry* e1);
void AssertCondition(stackentry* e1);
void ForCondition(stackentry* e1);
void EnhancedForCondition(stackentry* e1);