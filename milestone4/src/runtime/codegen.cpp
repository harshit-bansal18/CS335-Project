#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <codegen.hpp>
#include <symbol_table_fast.hpp>
#include <3ac.hpp>

using namespace std;

stringstream asm_ss;

map <instr_names, string> x86_instr = {
                                        {addq, "addq"},
                                        {mulq, "imulq"},
                                        {mull, "imull"},
                                        {movq, "movq"},
                                        {movl, "movl"},
                                        {subq, "subq"},
                                        {subl, "subl"},
                                        {modl, "idivl"},
                                        {modq, "idivq"},
                                        {idivl, "idivl"},
                                        {idivq, "idivq"},
                                        {negl, "negl"},
                                        {negq, "negq"},
                                        {jg, "jg"},
                                        {jl, "jl"},
                                        {je, "je"},
                                        {jne, "jne"}};

string get_free_register() {
    return "\%eax";
}

void push_instr(string name, string dst, string src) {

    asm_ss << name << "\t" << dst;
    if (src != "")
        asm_ss << ", " << src;

    asm_ss << "\n"; 
}

static inline string get_stack_addr(string pointer_name, int offset) {
    string addr = "";
    addr = to_string(offset) + "(" + pointer_name + ")";
    return addr;
}

string generate_asm_string(Address* addr) {
    string asm_code = "";
    if (addr->type == TEMP) {
        const char* name = addr->name.c_str();
        cout << "name: " << name << endl;
        char buf[10] = {'\0'};
        memcpy(buf, name + 1, strlen(name)-1);
        int offset = atoi(buf) - 4;
        asm_code = get_stack_addr("\%rsp", offset);
    }
    else if (addr->type == MEM) {
        asm_code = get_stack_addr("\%rbp",addr->offset);
    }
    else if (addr->type == CONST) {
        asm_code = "$" + addr->name;
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
    if(mem_addr->size == 4)
        name = x86_instr[movl];
    else if (mem_addr->size == 8)
        name = x86_instr[movq];
    src = generate_asm_string(mem_addr);
    push_instr(name, dst, src);
    return dst;
}

static inline void insert_store_mem(Address *mem_addr, string reg) {
    string dst, name;
    if(mem_addr->size == 4)
        name = x86_instr[movl];
    else if (mem_addr->size == 8)
        name = x86_instr[movq];
    dst = generate_asm_string(mem_addr);
    push_instr(name, dst, reg);
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

static inline bool is_unary(string op) {
    char op_c = op[0];
    if (op_c == '-' || op_c == '!')
        return true;

    return false;
}

string get_instr_name_unary(string op) {
    if (op == "-")
        return x86_instr[negl];
    else {
        return "";
    }
}
string get_instr_name_binary(string op, int size) {

    switch (size) {
    
    case 4:
        if (op == "+") 
            return x86_instr[addl];
        else if (op == "-")
            return x86_instr[subl];
        else if (op == "*")
            return x86_instr[mull];
        else if (op == "/")
            return x86_instr[idivl];
        else if (op == "\%")
            return x86_instr[modl];
        else if (op == ">")
            return x86_instr[jg];
        else if (op == "<")
            return x86_instr[jl];
        else if (op == ">=")
            return x86_instr[jge];
        else if (op == "<=")
            return x86_instr[jle];
        else if (op == "==")
            return x86_instr[je];
        else 
            return "";
        
    case 8:
        if (op == "+") 
            return x86_instr[addq];
        else if (op == "-")
            return x86_instr[subq];
        else if (op == "*")
            return x86_instr[mulq];
        else if (op == "/")
            return x86_instr[idivq];
        else if (op == "\%")
            return x86_instr[modq];
        else if (op == ">")
            return x86_instr[jg];
        else if (op == "<")
            return x86_instr[jl];
        else if (op == ">=")
            return x86_instr[jge];
        else if (op == "<=")
            return x86_instr[jle];
        else if (op == "==")
            return x86_instr[je];
        else 
            return "";

    }
 
    return "";
}

void process_arg(Arg *arg) {
    
}

void process_call(Call *call) {

}

void process_comp(Comp *comp) {
    Address *arg1 = comp->arg1;
    Address *arg2 = comp->arg2;
    if(arg1 == nullptr || arg2 == nullptr) {
        cerr << "Error: Comp instruction has null arguments\n";
        exit(1);
    }
    push_instr("cmp", insert_load_mem(arg1), insert_load_mem(arg2));
    push_instr(get_instr_name_binary(comp->comp_operator, arg1->size), comp->label, "");
}

// Based on operation type choose asm instruction
// Check size of arguments
// Check type of arguments -> MEM, TEMP, CONST
void process_quad(Quad *quad) {
    Address *arg1 = quad->arg1;
    Address *arg2 = quad->arg2;
    string src, dst;
    string name;
    if (arg1 != nullptr && arg2 != nullptr) {
        
        if (quad->operation[0] == '/' || quad->operation[0] == '\%') {
            name = get_instr_name_binary(quad->operation, arg1->size);
            // dst = insert_load_mem(arg1);
            push_instr(x86_instr[movl], "\%eax", generate_asm_string(arg1)); // dividend pushed in eax
            src = generate_asm_string(arg1);
            push_instr(name, src, "");
            if(quad->operation[0] == '/')
                insert_store_mem(quad->result, "\%eax");
            else if (quad->operation[0] == '\%')
                insert_store_mem(quad->result, "\%edx");
            else if (quad->operation[0] == '*')
                insert_store_mem(quad->result, dst);
        } 
        else if (is_binary(quad->operation)) {
            // If both arguments are memory types, load one of them to register and then issue add operation
            // finally store the value of register
            name = get_instr_name_binary(quad->operation, arg1->size);
            dst = insert_load_mem(arg1);
            src = generate_asm_string(arg2);
            push_instr(name, dst, src);
            insert_store_mem(quad->result, dst);
        }
        
    }
    // arg2 is null. Most likely a unary operation
    else if (arg1 != nullptr ) {
        if (is_unary(quad->operation)) {
            name = get_instr_name_unary(quad->operation);
            dst = insert_load_mem(arg1);
            push_instr(name, dst, "");
            insert_store_mem(quad->result, dst);
        }
        if (quad->operation == "="){
            if (arg1->size == 4)
                name = x86_instr[movl];
            else if (arg1->size == 8)
                name = x86_instr[movq];
            
            // if operator is "=", then also arg2 will be null
            if (arg1->type == CONST)
                src = generate_asm_string(arg1);
            else
                src = insert_load_mem(arg1);
            
            dst = generate_asm_string(quad->result);
            push_instr(name, dst, src);
        }
    }
    else {
        cerr << "Both arg1 and arg2 are null\n";
        exit(1);
    }
    
}

void process_label(Label *label) {
    
}

void process_return(Return* ret){
    
}

void method_footer() {
    asm_ss << "movl\t$0, \%eax\n";
    asm_ss << "ret\n";
}

void method_header() {
    asm_ss << "pushq\t%rbp\n";
    asm_ss << "movq\t%rsp, %rbp\n";
}

void generate_method_asm(vector<ThreeAC *> &tac_instr) {
    Quad *quad_p;
    Arg  *arg_p;
    Label *label_p;
    Return *return_p;
    Call *call_p;
    asm_ss.clear();
    asm_ss.str(string());

    method_header();
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
    method_footer();

    cout << asm_ss.str(); 

}