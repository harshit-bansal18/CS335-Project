#ifndef THREEAC_H
    #define THREEAC_H

    #include <bits/stdc++.h>
    #include <string>
    #ifndef SYMBOL_TABLE_FAST_H
        #include <symbol_table_fast.hpp>
    #endif

    using namespace std;

    struct TypeName;

    class ThreeAC {
        public:
        int instr_no;

        ThreeAC(int ins);
    };

    class Address {
        public:
        string name;
        int size;
        bool is_valid;
    };

    typedef struct _address {
        Address *addr;
        struct _address *next_use;
    }_address;

    class Quad: public ThreeAC {
        public:
        _address arg1, arg2, result;
        string operation;

        Quad(Address *_arg1, Address *_arg2, Address *result, string op);

    };

    class Label: public ThreeAC {
        public:
        string name;
        unsigned int reference_count;
        Label(string name);
    };

    class Goto: public ThreeAC {
        Label *label;
        public:
            _address res;
    };

    class Arg: public ThreeAC {
    public:
        _address *arg;
        int num;
        Arg(Address *arg, int count);
    };

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