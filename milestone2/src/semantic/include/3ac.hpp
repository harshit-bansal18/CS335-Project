#include <bits/stdc++.h>
using namespace std;


// typedef struct entry3ac{
//     string threeac="";
// } entry3ac;

// typedef struct loopentry{
//     int loopnum;
// } loopentry;

// typedef struct ifentry{
//     int ifnum;
// } ifentry;

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