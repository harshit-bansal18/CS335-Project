#ifndef ACTIONS_FAST_H
    #define ACTIONS_FAST_H


    #ifndef MACROS_H 
        #include <macros.hpp>
    #endif

    #ifndef SYMBOL_TABLE_FAST_H
        #include <symbol_table_fast.hpp>
    #endif
    #include <bits/stdc++.h>
    #include <vector>

    using namespace std;
    typedef enum {
        scope_global,
        scope_class,
        scope_method
    } scope;

    typedef struct stackentry{
        public:
        string token;           //key
        scope scope_;              
        int8_t modifier;           //public, private, static, final
        vector<Type *> argument_type;   //argument list of function
        Type *type;            // type for variable and return type for function
        string nature;          // class or function or variable etc.
        bool is_var_intialized;
        int offset;
        unsigned long line_no;
        string threeac;
        double expr_val;

        stackentry(const char *name, unsigned long line);

    } stackentry;

    Type *add_to_defined_types(Type *type);
    int8_t set_modifier(int8_t curr_modf, int8_t new_modf);
    void increase_current_level();
    bool check_primitive_types(Type *type);
    bool check_if_numeric_type(Type *type);
    bool check_return_type(Type *type1, Type *type2);
    Type *check_function_in_class(string token, vector<Type*> &argument_type, string nature);
    stackentry *find_variable_in_class( string token, bool );
    bool find_variable_in_closest_function_scope( string token );
    void clear_current_scope( );
    void add_class(int8_t modifier, string token);
    void add_variable(string token, int8_t modifier, Type *type, int offset, bool is_fun_arg, bool initialized);
    void add_function(string token, vector<Type*> &argument_type, Type* return_type, int8_t modifier);
    void add_constructor(string token, vector<Type*> &argument_type, int8_t modifier);
    Type *get_type(string name);
    Identifier *make_identifier(const char *name);
    TypeName *make_typename(Identifier *id) ;
    void append_typename(Identifier *id, TypeName *tn);
    stackentry *make_stackentry(const char *token, unsigned int);

    stackentry *make_stackentry(const char *token, Type *type, unsigned int );

    void check_boolean(Type *t);

    void check_cast_types(Type *t1, Type *t2);
    Type *get_array_type();
    Type *get_array_type(Type *t, stackentry *e);
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
    Type *add_to_defined_types(Type *);
    Type* ClassOrInterfaceType(stackentry* e1);
    void VariableDeclarator(stackentry* e1, stackentry* e2, int rule_no);
    void IfCondition(stackentry* e1);
    void WhileCondition(stackentry* e1);
    void AssertCondition(stackentry* e1);
    void ForCondition(stackentry* e1);
    void EnhancedForCondition(stackentry* e1);
    stackentry *find_variable_in_type(string name, Type *type);
    bool compare_argument_types(vector<Type*>&, vector<Type*>&);
    bool compare_argument_types_exact(vector<Type*>&, vector<Type*>&);
    void intialize_types();
    void verify_pass1();
    void check_final_vars();
    void print_modifier(int8_t mod);
    void print_type(Type* t);
    string cerr_type(Type*t);
    string three_ac_type_dump(vector<Type*> t);

#endif