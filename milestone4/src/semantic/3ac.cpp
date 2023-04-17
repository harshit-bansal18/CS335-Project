#include <bits/stdc++.h>
#include <sstream>

#ifndef ACTIONS_FAST_H
    #include <actions_fast.hpp>
#endif

#include <3ac.hpp>

using namespace std;

extern scope current_scope;

vector< ThreeAC * > ta_code;
unsigned long long temporaries = 1;
#define WORD_SIZE 8

Label::Label(string _name){
	name = _name;
}

Label* create_new_label(string _name){
	Label* l = new Label(_name);
	ta_code.push_back(l);
	return l;
}

Quad::Quad ( Address * _result, string _operation, Address * _arg1, Address * _arg2 ) { 
	operation = _operation;
	result = _result;
    arg1 = _arg1;
    arg2 = _arg2;
};

/*
It will be called when using variable or temporary
*/
Address::Address(string _name, addr_type _type ) : name (_name) , size(0), type(_type), ta_instr(nullptr)  {};

/*
It will called when using constant values
*/
Address::Address(long _value, addr_type _type ) : name (to_string(_value)) , size(0), type(_type), ta_instr(nullptr) {};

Address * new_temp() {
	Address * addr = new Address("t" + to_string(temporaries), TEMP );
	addr->size = WORD_SIZE;
	addr->table_id = TEMP_ID_MASK | temporaries;
	temporaries++;
	// tac_info_table.insert({addr->table_id,TacInfo(false)});
	return addr;
}

Address * new_mem( SymTabEntry * symbol ) {
	Address * addr = new Address(symbol->name, MEM);
    addr->size = symbol->type->size;
    addr->offset = symbol->offset;
    // MEM location or identifiers have no table_id

	// tac_info_table.insert({addr->table_id,TacInfo(symbol)});
	// main_mem_unit.memory_locations.insert({addr->table_id,create_memory_location( symbol->name, symbol->id, symbol->offset, addr->size )});
	// if ( symbol->type.is_ea() ) {
	// 	set_is_ea( symbol->id );
	// }

	return addr;
}


static inline Address *create_new_addr_str(string name, addr_type _type) {
    Address *new_addr;
    new_addr = new Address(name, _type);
    return new_addr;
}

static inline Address *create_new_addr_const(long val, addr_type _type) {
    Address *new_addr;
    new_addr = new Address(val, _type);
    return new_addr;
}

static inline Quad *create_new_quad(Address *result, string op, Address *arg1, Address *arg2) {
    Quad *new_quad;
    // Perform any checks on arguments if required
    new_quad = new Quad(result, op, arg1, arg2);
    return new_quad;
}

Goto::Goto () : label(nullptr) { dead = false; };

Goto * create_new_goto() {
    Goto *new_goto;
    new_goto = new Goto();
    return new_goto;
}

Goto * create_new_goto(Label * label) {
    Goto *new_goto;
    new_goto = new Goto();
    new_goto->label = label;
    return new_goto;
}

Goto * create_new_goto_cond(bool condition) {
    Goto *new_goto;
    new_goto = new Goto();
    new_goto->condition = condition;
    return new_goto;
}

static inline Call * create_new_call( Address * addr , string f_name ){
    Call *new_call;
    new_call = new Call(addr, f_name);
    return new_call;
}

Return::Return( Address* _retval ) : ThreeAC() {
	ret_value = _retval;
}

static inline Return * create_new_return(Address * retval){
    Return * _return = new Return(retval);
	ta_code.push_back(_return);
	return _return;
}
// ##############################################################################################################

typedef struct entry3ac{
    string threeac="";
} entry3ac;

// typedef struct loopentry{
//     int loopnum;
// } loopentry;

// typedef struct ifentry{
//     int ifnum;
// } ifentry;

int loopnum=0;
int ifnum=0;
int tcount=0;
int paramcount=0;
string threeac_file_name = "";
// stringstream 3ac_stream(string());
stringstream tacss;

void emit(string op, string arg1, string arg2, string result){
    if(current_scope != scope_class)
        tacss << op << " "<<arg1<<" "<<arg2<<" "<<result<<"\n";
}

string get_temp(){
    string label = "t"+to_string(tcount);
    tcount ++;
    return label;
}

string assignment_operator_3ac(string result , string op , string operand ){
    string temp = get_temp();
    emit(op.substr(0,op.length() - 1),result,operand, temp);
    emit("=", temp, "", result);
    return result;
}

string assign_operator_3ac(string result , string operand ){
    string temp = get_temp();
    emit("=", operand , "", temp);
    emit("=", temp, "", result);
    tcount++;
    return result;
}

string ternary_condition_3ac(string cond, string e1, string e2){
    string temp = get_temp();
    emit("if", cond, "false", "goto(T" + temp+")" );
    emit("=", e1, "", temp);
    emit("goto(TEnd"+temp+")","","","");
    emit("\nT"+temp+":\n","","","");
    emit("=", e2, "", temp);
    emit("\nTEnd"+temp+":\n","","","");
    return temp;
}

string binary_operator_3ac(string e1, string op, string e2){
    string temp = get_temp();
    emit(op, e1, e2, temp);
    return temp;
}

// string and_operator_3ac(string e1, string e2){
//     string temp = get_temp();
//     emit("if", e1, "false", "goto(T" + temp+")" );
//     emit("=", e1, "", temp);
//     emit("goto(TEnd"+temp+")","","","");
//     emit("\nT"+temp+":\n","","","");
//     emit("if", e2, "true", "goto(T" + temp+")" );
//     emit("=", e2, "", temp);
//     emit("=", "false", "", temp);
//     return temp;
// }

string deq_check_3ac(string e1, string e2){
    string temp = get_temp();
    emit("if", e1, e2, "goto(T" + temp+")" );
    emit("=", "false", "", temp);
    emit("goto(TEnd"+temp+")","","","");
    emit("\nT"+temp+":\n","","","");
    emit("=", "true", "", temp);
    emit("\nTEnd"+temp+":\n","","","");
    return temp;
}

string neq_check_3ac(string e1, string e2){
    string temp = get_temp();
    emit("if", e1, e2, "goto(T" + temp+")" );
    emit("=", "true", "", temp);
    emit("goto(TEnd"+temp+")","","","");
    emit("\nT"+temp+":\n","","","");
    emit("=", "false", "", temp);
    emit("\nTEnd"+temp+":\n","","","");
    return temp;
} // == , !=

string relation_check_3ac(string e1, string op, string e2){
    string temp = get_temp();
    emit(op, e1, e2, "goto(T" + temp+")" );
    emit("=", "false", "", temp);
    emit("goto(TEnd"+temp+")","","","");
    emit("\nT"+temp+":\n","","","");
    emit("=", "true", "", temp);
    emit("\nTEnd"+temp+":\n","","","");
    return temp;
} // < , > , <= , >=

string pre_increament_3ac(string e1){
    string temp = get_temp();
    emit("=", e1, "", temp);
    emit("+", temp, "1", e1);
    return temp;
}

string post_increament_3ac(string e1){
    string temp = get_temp();
    emit("+", e1, "1", temp);
    emit("=", temp, "", e1);
    return temp;
}

string pre_decreament_3ac(string e1){
    string temp = get_temp();
    emit("=", e1, "", temp);
    emit("-", temp, "1", e1);
    return temp;
}

string post_decreament_3ac(string e1){
    string temp = get_temp();
    emit("-", e1, "1", temp);
    emit("=", temp, "", e1);
    return temp;
}

Address *field_access_3ac(Address *tac_f, int offset) {
    Address *_addr1;
    if (current_scope != scope_method)
        return NULL;

    _addr1 = new_temp();
    // emit("+", tac_name, to_string(offset), temp2);
    // Harshit: Need to insert corresponding quad to method body.
    tacss << "= " << "*(" << tac_name << "+" << offset << ") " << temp2 << "\n";
    return _addr1;
}

/*
Harshit:
May also need to create Call pointer here is is_func is true
*/
// returns the last name in type_name vector
string type_name_3ac(TypeName *type_name, bool is_func) {
    auto ids =  type_name->names;
    string tmp = ids[0]->name;
    Address *arg1, *arg2;
    Quad *q;
    int num = ids.size();
    int n = num;
    if (is_func)
        n -= 1;
    
    for(int i = 1; i < n; i++) {
        Address *t = new_temp();
        arg1 = create_new_addr_str(tmp, TEMP);
        arg2 = create_new_addr_const(ids[i]->offset, TEMP);
        q = create_new_quad(t, "+", arg1, arg2);
        current_table->method->insert_threeac(q);
        // arg1 = tmp; arg2 = to_string(ids[i]->offset);
        emit("+", arg1->name, to_string(arg2->size), t->name);
        tmp = t;
    }
    
    if (num == 1)
        type_name->threeac = tmp;
    else 
        type_name->threeac = "*" + tmp;
    
    // Harshit-> Addr * needed?
    type_name->tac_addr = create_new_addr_str(type_name->threeac, TEMP);
    return ids[num-1]->name;
}

void dump_3ac(string fname){
    string filename = DUMP_DIR + fname + ".3ac";
    ofstream outss(filename.c_str());
    outss << fname << " : \n" << endl;
    outss << "push ebp" << endl;
    outss << "= esp ebp\n"<<endl;
    outss << tacss.str() << endl;
    tacss.clear();
    tacss.str(string());
    outss.close();
}   

string get_array_size(vector<string> array_dims){
    string size = get_temp();
    emit("=", "1", "", size);
    string temp = get_temp();
    
    for(int i=0; i<array_dims.size(); i++){
        emit("*", size, array_dims[i], temp);
        emit("=", temp, "", size);
    }
    return size;
}

