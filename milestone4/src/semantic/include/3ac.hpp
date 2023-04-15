#ifndef THREEAC_H
    #define THREEAC_H

    #include <bits/stdc++.h>
    #include <string>
    #ifndef SYMBOL_TABLE_FAST_H
        #include <symbol_table_fast.hpp>
    #endif

    using namespace std;

    struct TypeName;

    #define TEMP_ID_MASK 0x80000000

    typedef enum {
        TEMP,
        MEM,
        CONST,  
    } addr_type;

    class ThreeAC {
        public:
        
    };

    class Address {
        public:
            string name;
            int size;
            ThreeAC *ta_instr;
            addr_type type;
            unsigned int table_id;


            Address( string name, addr_type type);
            Address( long value, addr_type type);
    };

    class Quad: public ThreeAC{
        public:
            Address *result;
            Address *arg1;
            Address *arg2;
            string operation;

            Quad( Address *result, string operation, Address *arg1, Address *arg2);

    };

    class Return: public ThreeAC {
        public:
            Address *ret_value;

            Return( Address * _retval );

        friend Return * create_new_return( Address * retval );
    };

    class Call: public ThreeAC {
        public:
            Address *retval;
            string function_name;

            Call( Address * _addr, string f_name );

    };

    class Label;

    class Goto: public ThreeAC {
        Label *label;
    public:
        bool condition;

        friend Goto * create_new_goto_cond( bool condition );
        friend Goto * create_new_goto( Label * label);
        friend void process_goto( Goto * g );
    };

    class Label: public ThreeAC {
    public:
        string name;

        Label(string _name);
    };

    class Arg: public ThreeAC {
    public:
        Address *arg;
        int num;
    
        Arg(Address *_addr, int count );
    };
    
    typedef enum _const_type {
        INT3 = 1,
        FLOAT3
    } CONST_TYPE;

    #define SAVE_REGS( E, t1, t2 ) { \
        if ( (t1)->type == TEMP || (t1)->type == MEM ) { \
            (E)->res = (t1); \
            (E)->res->type = TEMP; \
        } else if ( (t2)->type == TEMP || (t2)->type == MEM ){ \
            (E)->res = (t2); \
            (E)->res->type = TEMP; \
        } else { \
            (E)->res = new_temp(); \
        } \
    }

    /* Add functions here*/
    static inline Address *create_new_addr();

    static inline Quad *create_new_quad(Address *result, string op, Address *arg1, Address *arg2);

    static inline Goto * create_new_goto();
    Goto * create_new_goto(Label * label);
    Goto * create_new_goto_cond(bool condition);

    static inline Label * create_new_label(string _name);

    static inline Address * new_temp();
    static inline Address * new_mem(SymTabEntry * symbol);

    template <typename T>
    static inline Address * new_const(T val, CONST_TYPE con ) {
        return new Address(to_string(val), CON);
    }

    static inline Call * create_new_call( Address * addr , string f_name );

    static inline Return * create_new_return(Address * retval);
    static inline create_new_arg(Address *_addr, int count);
    /**/


// #################################################################################################//
    void emit(string op, string arg1, string arg2, string result);

    string get_temp();

    string assignment_operator_3ac(string result , string op , string operand );

    string assign_operator_3ac(string result , string operand );

    string ternary_condition_3ac(string cond, string e1, string e2);

    string binary_operator_3ac(string e1, string op, string e2);

    // string and_operator_3ac(string e1, string e2){
    //     string temp = get_temp();
    //     emit("if", e1, "false", "goto(T" + temp+")" );
    //     emit("=", e1, "", temp);
    //     emit("goto(TEnd"+temp+")","","","");
    //     emit("T"+temp+":","","","");
    //     emit("if", e2, "true", "goto(T" + temp+")" );
    //     emit("=", e2, "", temp);
    //     emit("=", "false", "", temp);
    //     return temp;
    // }

    string deq_check_3ac(string e1, string e2);

    string neq_check_3ac(string e1, string e2);

    string relation_check_3ac(string e1, string op, string e2);

    string pre_increament_3ac(string e1);

    string post_increament_3ac(string e1);
    string pre_decreament_3ac(string e1);

    string post_decreament_3ac(string e1);

    void dump_3ac(string filename);

    string get_array_size(vector<string> array_dims);

    string field_access_3ac(string cls_name, int offset);

    string type_name_3ac(TypeName* type_name, bool is_func);


#endif