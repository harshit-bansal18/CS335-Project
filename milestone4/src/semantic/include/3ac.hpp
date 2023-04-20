#ifndef THREEAC_H
#define THREEAC_H

#include <bits/stdc++.h>
#include <string>
#ifndef SYMBOL_TABLE_FAST_H
    #include <symbol_table_fast.hpp>
#endif

#define SP "rsp"

#define CONSTANT_SIZE 8
#define POINTER_SIZE 8
#define REF_TYPE_SIZE 8

#define ENDLOOP_LABEL "end_loop"
#define IF_LABEL "if"
#define ELSE_LABEL "else"
#define ENDIF_LABEL "end_if"
#define LOOP_LABEL  "loop"
#define ENDFOR_LABEL "end_for"
#define FORBODY_LABEL "for_body"
#define FORUPDATE_LABEL "for_update"
#define FORCOND_LABEL "for_cond"
#define T_LABEL     "t"
#define TEND_LABEL "t_end"

using namespace std;

struct TypeName;
struct Type;
class SymTabEntry;

typedef enum {
    TEMP,
    MEM,
    CONST,  
} addr_type;

typedef struct Address {
    string name;
    int size;
    // ThreeAC *ta_instr;
    addr_type type;
    // unsigned int table_id;
    
    bool absolute;
    int offset;   // only in case of memory regions if not absolute
    Address* abs_offset; // only in case of memory regions if absolute, use directly no ebp required

    Address( string _name, addr_type _type);
    Address( long _value, addr_type _type);
    Address( SymTabEntry* _symbol );
} Address;

class ThreeAC {
    public:    

        virtual ~ThreeAC();
};

class Quad: public ThreeAC{
    public:
        Address *result;
        Address *arg1;
        Address *arg2;
        string operation;

        Quad( Address* _result, string _operation, Address* _arg1, Address* _arg2);
};

class Return: public ThreeAC {
    public:
        Address *ret_value;  // can be null if func doesnt return anything 
                            // in case of pop, it is the address where to store the return registeer(rax) value
        // In case of pop, mov instruction will be used
        // In case of push, mov inst along with (goto ret) will be used
        bool push; // true if calling return 5, false when popping the value at caller function from return reg
        Return( Address * _retval, bool _push );
};

class Call: public ThreeAC {
    public:
        string function_name;
        int arg_count;

        Call( string f_name, int arg_count );

};

class Label: public ThreeAC {
public:
    string name;

    Label(string _name);
};

class Goto: public ThreeAC {
public:
    Label *label;

    Goto(Label* _label);
};

// used when to push argument in the stack
// Used by the caller function
class Arg: public ThreeAC {
public:
    Address *arg;
    int offset; 

    Arg(Address *_addr, int _offset );
};

class Comp: public ThreeAC{
    public:
        string comp_operator;
        Address* arg1;
        Address* arg2;
        string label;   // Label to jump if condition satisfies as by comp_operator(je, jge, jg...)

        Comp(string _comp_operator, Address* _arg1, Address* _arg2, string _label);
};

class Reg: public ThreeAC {
    public:
        string reg_name;
        int size;
        bool add; // true if add or shrink the stack else false

    Reg(string reg, int _size, bool _add);
};

class Print: public ThreeAC {
    public:
        Address* arg1;

    Print(Address* _arg1);
};

class Allocmem: public ThreeAC {
    public:
        Address* num_bytes;
        Address* result;
    Allocmem(Address* _bytes, Address* _result);
};

Address* create_new_temp();
Address* create_new_const(string val, int size);
Address* create_new_mem(string name, int offset, int type_size);  // if absolute = false
Address* create_new_mem(string name, int offset, Type* type);  // if absolute = false
Address* create_new_mem(string name, Address* offset, Type* type);   // if absolute = true
Quad* create_new_quad(string operation, Address *arg1, Address *arg2, Address *result);
Label* create_new_label(string name);
Goto* create_new_goto(string name);
Arg* create_new_arg(Address* arg, int offset);
Comp* create_new_comp(string comparator, Address* addr1, Address* addr2, string label);
Reg* create_new_reg(string reg, int _size, bool _add);  // increment-decrement the stack pointer
Return * create_new_return( Address * retval, bool _push );
Call* create_new_call( string f_name, int arg_count );
Print* create_new_print(Address* _arg1);
Allocmem* create_new_allocmem(Address* _bytes, Address* _result);

void emit(ThreeAC* tac);

Address* assignment_operator_3ac(Address* result , string op , Address* operand );

Address* assign_operator_3ac(Address* result , Address* operand );

Address* ternary_condition_3ac(Address* cond, Address* e1, Address* e2);

Address* binary_operator_3ac(Address* e1, string op, Address* e2);

Address* binary_bitwise_operator_3ac(Address* e1, string op, Address* e2);

Address* and_operator_3ac(Address* e1, Address* e2);

Address* or_operator_3ac(Address* e1, Address* e2);

Address* deq_check_3ac(Address* e1, Address* e2);

Address* neq_check_3ac(Address* e1, Address* e2);

Address* relation_check_3ac(Address* e1, string op, Address* e2);

Address* pre_increament_3ac(Address* e1);

Address* post_increament_3ac(Address* e1);
Address* pre_decreament_3ac(Address* e1);

Address* post_decreament_3ac(Address* e1);

Address* get_array_size(vector<Address*> array_dims, int start_i);

Address* field_access_3ac(Address* cls_name, int offset, Type* type, string id);

Address* type_name_3ac(TypeName* type_name, bool is_func);

void insert_in_global_quads(ThreeAC* tac);
void dump_3ac(string filename, unsigned long func_local_space_size);
void dump_class_3ac(string classname, unsigned long classsize);
bool check_if_temp(Address *s);
bool check_if_const(Address *s);
bool check_if_mem(Address* s);

#endif