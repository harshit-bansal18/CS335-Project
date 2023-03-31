#include <activation_record.hpp>
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <symbol_table_fast.hpp>

using namespace std;


RuntimeStack *runtime_stack;



void
ActivationRecord::store_value(Type *t) {
    // this is a temporary value we might need to store because register is not available
    int bytes;
    if (t->is_pointer()) 
        bytes = REF_TYPE_SIZE;
    else 
        bytes = t->size;
    
    runtime_stack->store_on_stack(bytes);
}

void
ActivationRecord::add_local_variable(SymTabEntry *entry) {
    Type *t = entry->type;
    int inc;
    if (t->is_pointer())
        inc = REF_TYPE_SIZE;
    else 
        inc = t->size;
    
    local_data_space += inc;
    runtime_stack->store_on_stack(inc);
}

ActivationRecord::ActivationRecord(vector<Type *> &args, Type *ret_type) {
    args_space = 0;
    ret_space = 0;

    for(auto t: args) {
        if (t->is_pointer())
            args_space += REF_TYPE_SIZE;
        else
            args_space += t->size;
    }
    ret_space = ret_type->size;
}


void
RuntimeStack::pop_activation_record() {
    int n = stack.size() - 1;
    sp = stack[n]->old_state.sp;
    top_sp = stack[n]->old_state.top_sp;
    free(stack[n]);
    stack.pop_back();
}


void
RuntimeStack::push_activation_record(ActivationRecord *record, ClassDefinition *cls) {
    int n = stack.size() - 1;
    MachineStatus ms;
    ms.sp = sp;
    ms.top_sp = top_sp;
    record->control_link = stack[n];
    record->access_link = cls;
    record->old_state = ms;
    
    //update sp and top_sp
    sp = sp + record->args_space + record->ret_space + sizeof(record->control_link) + sizeof(record->access_link) + sizeof(ms);
    top_sp = sp;
    stack.push_back(record);
}

void
RuntimeStack::store_on_stack(size_t bytes) {
    top_sp += bytes;
}

RuntimeStack::RuntimeStack() {
    stack.clear();
    sp = NULL;
    top_sp = NULL;
}
