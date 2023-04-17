#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <codegen.hpp>
#include <symbol_table_fast.hpp>

using namespace std;

MMU mmu;
map <instr_names, string> x86_instr = {(mov, "mov"),
                                        (add, "add"),
                                        (mul, "mul"),
                                    };
vector<AsmInstr> asm_instrs;

void push_instr(string name, string dst, string src) {
    AsmInstr instr;
    instr.name = name;
    instr.dst = dst;
    instr.src = src;
    asm_instrs.push_back(instr);
}

static inline string get_stack_addr(string pointer_name, int offset) {
    string addr = "";
    addr = to_string(offset) + "("pointer_name")";
    return addr;
}

string generate_asm_string(Address* addr) {
    string asm_code = "";
    if (addr->type == TEMP) {
        int offset = atoi(addr->name.substr(1,addr->name.length()));
        asm_code = get_stack_addr("\%esp", offset);
    }
    else if (addr->type == MEM) {
        asm_code = get_stack_addr("\%ebp",addr->offset);
    }
    else if (addr->type == CONST) {
        asm_code = "$" + to_string(addr->offset);
    }
    else {
        cerr << "Error: Invalid address type\n";
        exit(1);
    }
    return asm_code;
}

static inline string insert_load_mem(Address *mem_addr) {
    string dst, name, src;
    dst = get_free_register();
    name = x86_instr[mov];
    src = generate_asm_string(mem_addr);
    push_instr(name, dst, src);
    return dst;
}

// Returns if the operation is binary i.e has two operands.
static inline bool is_binary(string op) {
    char op_c = op[0];
    if (op_c == '+' || op_c == '-' || op_c == '*' || op_c == '/')
        return true;
    
    if (op == ">>" || op == "<<" || op == ">>>" )
        return true;
    
    return false;
}

string get_instr_name(string op) {

    if (op == "+int") 
        return x86_instr[addl];
    else if (op == "+long")
        return x86_instr[add];
    else if (op == "-int")
        return x86_instr[subl];
    else if (op == "-long")
        return x86_instr[sub];
    else if (op == "*int")
        return x86_instr[mull];
    else if (op == "=int")
        return x86_instr[movl];
    else if (op == "=long")
        return x86_instr[mov];
    else {
        return "";
    }
}

void process_arg(Arg *arg) {

}

void process_call(Call *call) {

}

void process_comp(Comp *comp) {
    Address *arg1 = quad->arg1;
    Address *arg2 = quad->arg2;
    if(arg1 == nullptr || arg2 == nullptr) {
        cerr << "Error: Comp instruction has null arguments\n";
        exit(1);
    }
    push_instr("cmp", insert_load_mem(arg1), insert_load_mem(arg2));
    
}

// Based on operation type choose asm instruction
// Check size of arguments
// Check type of arguments -> MEM, TEMP, CONST
void process_quad(Quad *quad) {
    // AsmInstr instr;
    // instr.name = get_instr_name(quad->operation); // more logic required for immidiate instructions like addi
    // if (is_null(quad->arg1)) {
    //     cerr << "i think this is an error\n";
    //     exit(1);
    // }

    // if (quad->arg1->type == TEMP)
    //     instr.dst = mmu.get_free_register();
    // else if (quad->arg1->type == MEM)
    //     instr.dst = 
    
    // For all binary operators, check if the arguments are memory, constants or temp
    // Handle differently for all the cases

    Address *arg1 = quad->arg1;
    Address *arg2 = quad->arg2;
    string src, dst;
    string name;
    if (arg1 != nullptr && arg2 != nullptr) {
        if (is_binary(quad->operation)) {
            // If both arguments are memory types, load one of them to register and then issue add operation
            // finally store the value of register
            name = get_instr_name(quad->operation);
            dst = insert_load_addr(arg1);
            src = generate_asm_string(arg2);
            push_instr(name, dst, src);
            spill_register(dst);
        }
    }
    else if (quad->arg1 != nullptr ) {

    }
    
}

void generate_method_asm(vector<ThreeAC *> &tac_instr) {
    Quad *quad_p;
    Arg  *arg_p;
    Label *label_p;
    Return *return_p;
    Call *call_p;

    for (auto instr: tac_instr) {
        quad_p = dynamic_cast<Quad *> (instr);
        if (quad_p != nullptr) {
            process_quad(quad_p);
            continue;
        }
        arg_p = dynamic_cast<Arg *> (instr);
        if (arg_p != nullptr) {
            process_arg(arg_p);
            continue;
        }

        label_p = dynamic_cast<Label *> (instr);
        if (label_p != nullptr) {
            process_label(label_p);
            continue;
        }
        return_p = dynamic_cast<Return *> (instr);
        if (return_p != nullptr) {
            process_return(return_p);
            continue;
        }
        call_p = dynamic_cast<Call *> (instr);
        if (call_p != nullptr) {
            process_call(call_p);
            continue;
        }

    }
}



get_reg(){
    // get a free register out of three registers

}