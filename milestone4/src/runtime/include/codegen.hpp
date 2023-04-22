#ifndef __CODEGEN_H__
#define __CODEGEN_H__

#include <bits/stdc++.h>
#include <3ac.hpp>
#include <vector>

using namespace std;

#define CAST "cast"
#define MALLOC "malloc"
#define EMPTY_STR ""

// List all the registers
typedef enum {
    
}REG;

typedef enum {
    movl,
    mov,
    call,
    ret,
    addq,
    addl,
    addi,
    subl,
    subq,
    mulq,
    mull,
    pop,
    push,
    je, //<label> (jump when equal)
    jne, //<label> (jump when not equal)
    jz, // <label> (jump when last result was zero)
    jg, // <label> (jump when greater than)
    jge,// <label> (jump when greater than or equal to)
    jl, // <label> (jump when less than)
    jle, //<label> (jump when less than or equal to)
    jmp, // unconditional jump
    negl, // <register/Mem> example int a = -b/ negl %eax; movl %a %eax
    modq,
    movq,
    idivl,
    idivq,
    modl,
    negq,
    shlq,
    shrq,
    sarq,
    notq,
    andq,
    orq,
    xorq,
    logicalnot
}instr_names;


class AsmInstr {
public:
    string name;
    string dst;
    string src;
    // string src2;
};

//  Memory Management Unit
class MMU {
public:

    string get_free_reg();
    void set_free_reg(string reg);
};

class reg {
    public:
    bool is_used;
    // Address* var; // if it is used which var used it
};

struct x86_reg {
    // declare 32 x86 registers here
    reg rax;
    reg rcx;
    reg rdx;
    reg rsi;
    reg rdi;
    reg rsp;
    reg rbp;
    reg r8;
    reg r9;
    reg r10;
    reg r11;
    reg r12;
    reg r13;
    reg r14;
    reg r15;

};

string get_free_register();
static inline string insert_load_mem(Address *mem_addr);

void generate_method_asm(vector<ThreeAC *> &tac_instr);
#endif