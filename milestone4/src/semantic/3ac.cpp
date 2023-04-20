#include <bits/stdc++.h>
#include <3ac.hpp>
#include <sstream>

#ifndef ACTIONS_FAST_H
    #include <actions_fast.hpp>
#endif

#ifndef __CODEGEN_H__
    #include <codegen.hpp>
#endif

using namespace std;

extern scope current_scope;

typedef struct entry3ac{
    string threeac="";
} entry3ac;

int loopnum=0;
int ifnum=0;
int tcount=0;
int paramcount=0;
int returncount = 0;
string threeac_file_name = "";
stringstream tacss;


vector<ThreeAC*> tacs;
vector<ThreeAC*> func_tacs;
vector<ThreeAC*> global_tacs;

ThreeAC::~ThreeAC() {}

Address::Address( string _name, addr_type _type){
    name = _name;
    type = _type;
}

Address::Address( long _value, addr_type _type){
    name = to_string(_value);
    type = _type;
}

Address::Address( SymTabEntry* _symbol ){
    name = _symbol->name;
    type = MEM;
    offset = _symbol->offset;
    size = _symbol->type->size;
}

Quad::Quad( Address* _result, string _operation, Address* _arg1, Address* _arg2){
    result = _result;
    operation = _operation;
    arg1 = _arg1;
    arg2 = _arg2;
}

Return::Return( Address * _retval, bool _push ){
    ret_value = _retval;
    push = _push;
}

Call::Call( string f_name, int arg_count ){
    function_name = f_name;
    arg_count = arg_count;
}

Label::Label(string _name){
    name = _name;
}

Goto::Goto(Label* _label){
    label = _label;
}

Arg::Arg(Address *_addr, int _offset ){
    arg = _addr;
    offset = _offset;
}

Comp::Comp(string _comp_operator, Address* _arg1, Address* _arg2, string _label){
    comp_operator = _comp_operator;
    arg1 = _arg1;
    arg2 = _arg2;
    label = _label;
}

Reg::Reg(string reg, int _size, bool _add){
    reg_name = reg;
    size = _size;
    add = _add;
}

Print::Print(Address* _arg1){
    arg1 = _arg1;
}

Allocmem::Allocmem(Address* _bytes, Address* _result){
    num_bytes = _bytes;
    result = _result;
}

Address* create_new_temp(){
    string name = T_LABEL + to_string(tcount++);
    Address* addr = new Address(name, TEMP);
    addr->size = CONSTANT_SIZE; // size of register for int operation 

    return addr;
}

Address* create_new_const(string val, int size){
    Address* addr = new Address(val, CONST);
    addr->size = size;

    return addr;
}

// if false
Address* create_new_mem(string name, int offset, int type_size){
    Address* addr = new Address(name, MEM);
    addr->size = type_size;
    addr->offset = offset;
    addr->absolute = false;

    return addr;
}

// if false
Address* create_new_mem(string name, int offset, Type* type){
    Address* addr = new Address(name, MEM);
    addr->size = type->size;
    addr->offset = offset;
    addr->absolute = false;

    return addr;
}

// if true
Address* create_new_mem(string name, Address* offset, Type* type){
    Address* addr = new Address(name, MEM);
    addr->size = type->size;
    addr->absolute = true;
    addr->abs_offset = offset;

    return addr;
}

Quad* create_new_quad(string operation, Address *arg1, Address *arg2,Address *result){
    Quad* quad = new Quad(result, operation, arg1, arg2);

    return quad;
}

Label* create_new_label(string name){
    Label* label = new Label(name);

    return label;
}

Goto* create_new_goto(string name){
    Label* label = create_new_label(name);
    Goto* _goto = new Goto(label);

    return _goto;
}

Arg* create_new_arg(Address* arg, int offset){
    Arg* _arg = new Arg(arg, offset);
    return _arg;
}

Comp* create_new_comp(string comparator, Address* addr1, Address* addr2, string label){
    Comp* comp = new Comp(comparator, addr1, addr2, label);

    return comp;
}

Reg* create_new_reg(string reg, int _size, bool _add){
    Reg* _reg = new Reg(reg, _size, _add);

    return _reg;
}

Return * create_new_return( Address * retval, bool _push ){
    Return* ret = new Return(retval, _push);

    return ret;
}

Call* create_new_call( string f_name, int arg_count ){
    Call* call = new Call(f_name, arg_count);

    return call;
}

Print* create_new_print(Address* _arg1){
    Print* _print = new Print(_arg1);

    return _print;
}

Allocmem* create_new_allocmem(Address* _bytes, Address* _result){
    Allocmem* _allocmem = new Allocmem(_bytes, _result);

    return _allocmem;
}

///old /////////////////////////////////////

bool check_if_temp(Address* s){
    if(s->type == TEMP)
        return true;
    
    return false;
}

bool check_if_const(Address* s){
    if(s->type == CONST)
        return true;
        
    return false;
}

bool check_if_mem(Address* s){
    if(s->type == MEM)
        return true;
        
    return false;
}

void emit(ThreeAC* tac){
    if(current_scope != scope_class){
        // tacss << op << " "<<arg1<<" "<<arg2<<" "<<result<<"\n";
        tacs.push_back(tac);
    }    
}

Address* assignment_operator_3ac(Address* result , string op , Address* operand ){
    Address* temp = create_new_temp();
    string op_ = "";
    for(int i=0; i<op.length(); i++){
        if(op[i] == '=')
            break;
        op_ += op[i];
    }

    emit(create_new_quad(op_,result,operand, temp));
    emit(create_new_quad("=", temp, NULL, result));
    return result;
}

Address* assign_operator_3ac(Address* result , Address* operand ){

    if(check_if_const(operand) || check_if_temp(operand)){
        emit(create_new_quad("=", operand, NULL, result));   // in = always move will be called, result will be temp or mem location
        return result;
    }

    Address* temp = create_new_temp();
    emit(create_new_quad("=", operand , NULL, temp));
    emit(create_new_quad("=", temp, NULL, result));
    
    tcount++;
    return result;
}

Address* ternary_condition_3ac(Address* cond, Address* e1, Address* e2){
    Address* temp = create_new_temp();
    emit(create_new_comp("==", cond, create_new_const("0", CONSTANT_SIZE), T_LABEL + temp->name));
    emit(create_new_quad("=", e1, NULL, temp));
    emit(create_new_goto(TEND_LABEL+temp->name));
    emit(create_new_label(T_LABEL+temp->name));
    emit(create_new_quad("=", e2, NULL, temp));
    emit(create_new_label(TEND_LABEL+temp->name));
    return temp;
}

Address* binary_operator_3ac(Address* e1, string op, Address* e2){
    Address* temp = create_new_temp();
    emit(create_new_quad(op, e1, e2, temp));
    return temp;
}

Address* binary_bitwise_operator_3ac(Address* e1, string op, Address* e2){
    Address* temp = create_new_temp();
    emit(create_new_quad(op, e1, e2, temp));
    return temp;
}

Address* or_operator_3ac(Address* e1, Address* e2){
    Address* temp = create_new_temp();
    emit(create_new_comp("==", e1, create_new_const("0", CONSTANT_SIZE), T_LABEL + temp->name));

    emit(create_new_quad("=", e1, NULL, temp));
    emit(create_new_goto(TEND_LABEL+temp->name));

    emit(create_new_label(T_LABEL+temp->name)); 

    emit(create_new_quad("=", e2, NULL, temp));

    emit(create_new_label(TEND_LABEL+temp->name));
    return temp;
}

Address* and_operator_3ac(Address* e1, Address* e2){
    Address* temp = create_new_temp();
    emit(create_new_comp("==", e1, create_new_const("1", CONSTANT_SIZE), T_LABEL + temp->name));

    emit(create_new_quad("=", e1, NULL, temp));
    emit(create_new_goto(TEND_LABEL+temp->name));

    emit(create_new_label(T_LABEL+temp->name));
    
    emit(create_new_quad("=", e2, NULL, temp));

    emit(create_new_label(TEND_LABEL+temp->name));
    return temp;
}

Address* deq_check_3ac(Address* e1, Address* e2){
    Address* temp = create_new_temp();
    emit(create_new_comp("==", e1, e2, T_LABEL + temp->name));
    emit(create_new_quad("=", create_new_const("0", CONSTANT_SIZE), NULL, temp));
    emit(create_new_goto(TEND_LABEL+temp->name));
    emit(create_new_label(T_LABEL+temp->name));
    emit(create_new_quad("=", create_new_const("1", CONSTANT_SIZE), NULL, temp));
    emit(create_new_label(TEND_LABEL+temp->name));
    return temp;
}

Address* neq_check_3ac(Address* e1, Address* e2){
    Address* temp = create_new_temp();
    emit(create_new_comp("==", e1, e2, T_LABEL + temp->name));
    emit(create_new_quad("=", create_new_const("1", CONSTANT_SIZE), NULL, temp));
    emit(create_new_goto(TEND_LABEL+temp->name));
    emit(create_new_label(T_LABEL+temp->name));
    emit(create_new_quad("=", create_new_const("0", CONSTANT_SIZE), NULL, temp));
    emit(create_new_label(TEND_LABEL+temp->name));
    return temp;
} // == , !=

Address* relation_check_3ac(Address* e1, string op, Address* e2){
    Address* temp = create_new_temp();
    emit(create_new_comp(op, e1, e2, T_LABEL + temp->name));
    emit(create_new_quad("=", create_new_const("0", CONSTANT_SIZE), NULL, temp));
    emit(create_new_goto(TEND_LABEL+temp->name));
    emit(create_new_label(T_LABEL+temp->name));
    emit(create_new_quad("=", create_new_const("1", CONSTANT_SIZE),NULL, temp));
    emit(create_new_label(TEND_LABEL+temp->name));
    return temp;
} // < , > , <= , >=

Address* post_increament_3ac(Address* e1){
    Address* temp = create_new_temp();
    emit(create_new_quad("=", e1, NULL, temp));
    emit(create_new_quad("+", temp, create_new_const("1", CONSTANT_SIZE), e1));
    return temp;
}

Address* pre_increament_3ac(Address* e1){
    Address* temp = create_new_temp();
    emit(create_new_quad("+", e1, create_new_const("1", CONSTANT_SIZE), temp));
    emit(create_new_quad("=", temp, NULL, e1));
    return temp;
}

Address* post_decreament_3ac(Address* e1){
    Address* temp = create_new_temp();
    emit(create_new_quad("=", e1, NULL, temp));
    emit(create_new_quad("-", temp, create_new_const("1", CONSTANT_SIZE), e1));
    return temp;
}

Address* pre_decreament_3ac(Address* e1){
    Address* temp = create_new_temp();
    emit(create_new_quad("-", e1, create_new_const("1", CONSTANT_SIZE), temp));
    emit(create_new_quad("=", temp, NULL, e1));
    return temp;
}

Address* field_access_3ac(Address* tac_name, int offset, Type* type, string id) {
    if (current_scope != scope_method)
        return NULL;

    Address* temp2 = create_new_temp();
    // emit("+", tac_name, to_string(offset), temp2);
    // tacss << "+" << "" << tac_name << "+" << offset << ") " << temp2 << "\n";
    emit(create_new_quad("+", tac_name, create_new_const(to_string(offset), CONSTANT_SIZE), temp2));
    Address* mem = create_new_mem(id, temp2, type);
    return mem;
}

// returns the last name in type_name vector
Address* type_name_3ac(TypeName *type_name, bool is_func) {
    auto ids =  type_name->names;
    Address* arg1 = create_new_mem(ids[0]->name, ids[0]->offset, ids[0]->type);
    Address* arg2;
    int num = ids.size();
    int n = num;
    if (is_func)
        n -= 1;
    
    for(int i = 1; i < n; i++) {
        Address* tmp = create_new_temp();
        emit(create_new_quad("=", arg1, NULL, tmp));
        Address* tmp1 = create_new_temp();
        emit(create_new_quad("+", tmp, create_new_const(to_string(ids[i]->offset), CONSTANT_SIZE), tmp1));
        arg1 = create_new_mem(ids[i]->name, tmp1, ids[i]->type);
    }

    // In case of function it returns object reference of the variable which called it
    // in a.fun1(), a

    // in case of a.b.fun1() or a.b.c, it returns memory location of c or b
    if(n >= 1)
        return arg1;

    return NULL;
    
    // for(int i = 1; i < n; i++) {
    //     Address* t = create_new_temp();
    //     arg1 = tmp; 
    //     arg2 = create_new_const(to_string(ids[i]->offset));

    //     emit(create_new_quad("+", arg1, arg2, t));
    //     tmp = t;
    // }

    // if(num == 1 || )
    
    // if (num == 1 || is_func)
    //     type_name->tac = tmp;
    // else 
    //     type_name->threeac = "*" + tmp;
    
    // return ids[num-1]->name;
}

Address* get_array_size(vector<Address*> array_dims, int start_i){
    Address* temp = create_new_temp();
    emit(create_new_quad("=", create_new_const("1", CONSTANT_SIZE), NULL, temp));
    Address* temp1;
    for(int i=start_i; i<array_dims.size(); i++){
        temp1 = create_new_temp();
        emit(create_new_quad("*", temp, array_dims[i], temp1));
        temp = temp1;
        // emit("=", temp1, "", temp);
    }
    return temp;
}

// string get_array_size(vector<string> array_dims, int start_i){
//     Address* temp = create_new_temp();
//     emit("=", "1", "", temp);
//     Address* temp1;
//     for(int i=start_i; i<array_dims.size(); i++){
//         temp1 = create_new_temp();
//         emit("*", temp, array_dims[i], temp1);
//         temp = temp1;
//         // emit("=", temp1, "", temp);
//     }
//     return temp;
// }

void insert_in_global_quads(ThreeAC* tac){
    global_tacs.push_back(tac);
    func_tacs.push_back(tac);
}

void dump_3ac(string fname, unsigned long func_local_space_size){
    // string filename = DUMP_DIR + fname + ".3ac";
    // ofstream outss(filename.c_str());
    // outss << fname << " : \n" << endl;
    
    cout << "Func name: " << fname << "\n";
    cout<<"Local var size: "<< func_local_space_size <<" , Temp size:" << tcount*CONSTANT_SIZE <<"\n";
    func_local_space_size += (tcount*CONSTANT_SIZE);
    
    insert_in_global_quads(create_new_label(fname));
    // Need function Header here
    // outss << "push ebp" << endl;
    // outss << "= esp ebp\n"<<endl;

    if(func_local_space_size) {
        insert_in_global_quads(create_new_reg(SP, func_local_space_size, false)); // space for local variables
    }
    
    for(auto tac: tacs)
        insert_in_global_quads(tac);
    
    tacs.clear();

    insert_in_global_quads(create_new_label("return"+to_string(returncount++)));
    
    if(func_local_space_size) {
        insert_in_global_quads(create_new_reg(SP, func_local_space_size, true)); // manipulate stack pointer to the top of stack removing local variables
    }

    // Add function footer
    // outss << "pop ebp" << endl;
    // outss << "ret" << endl;

    generate_method_asm(func_tacs);
    tcount = 0;
    func_tacs.clear();
}