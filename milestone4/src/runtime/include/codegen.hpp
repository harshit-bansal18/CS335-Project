#include <bits/stdc++.h>
using namespace std;




class reg {
    public:
    bool is_used;
    Address* var; // if it is used which var used it
};

struct x86_regs {
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

