#include <bits/stdc++.h>
#include <3ac.hpp>
#include <sstream>

#ifndef ACTIONS_FAST_H
    #include <actions_fast.hpp>
#endif

using namespace std;

extern scope current_scope;

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

string field_access_3ac(string tac_name, int offset) {
    if (current_scope != scope_method)
        return "";

    string temp2 = get_temp();
    tacss << "= " << "*(" << tac_name << "+" << offset << ") " << temp2 << "\n";
    return temp2;
}

void dump_3ac(string filename){
    ofstream outss(filename.c_str());
    outss << tacss.str() << endl;
    tacss.clear();
    tacss.str(string());
    outss.close();
}   

int get_array_size(vector<string> array_dims){
    int size = 1;
    for(int i=0; i<array_dims.size(); i++){
        size *= stoi(array_dims[i]);
    }
    return size;
}