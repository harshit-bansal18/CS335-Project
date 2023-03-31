#include <bits/stdc++.h>
using namespace std;

#define REF_TYPE_SIZE 4

/**
* ActivationRecord:
*   Parameters -> space allocation for procedure arguments
*   Return Value -> space allocation for return value of current procedure
*   Control Link -> Pointer to caller procedure
*   Access Link -> Pointer to parent scope of current procedure
*   Saved Machine Status -> State of program registers, stack before calling this procedure
*   Local Data -> Variables declared in method scope
*   Temporaries -> Values arising from evaluation of expressions which cannot be held in registers
*/
class ActivationRecord {
    public:
    int args_space;
    int ret_space;
    ActivationRecord *control_link;
    ClassDefinition *access_link;
    MachineStatus old_state;
    int local_data_space;
    int tmp_space;
    ActivationRecord(vector<Type *> &args, Type *ret_type);

    void add_local_variable(SymTabEntry *entry);

    void store_value(Type *t); // We might need to replace this argument type

};

class RuntimeStack {
    public:
    unsigned long sp;
    unsigned long top_sp;
    vector<ActivationRecord *> stack;

    RuntimeStack();
    void push_activation_record(ActivationRecord *record, ClassDefinition *cls);
    void pop_activation_record();
    void store_on_stack(size_t bytes);
};

class MachineStatus {
    public:
    unsigned long sp;
    unsigned long top_sp;
};


struct x86_regs {
    // declare 32 x86 registers here


};