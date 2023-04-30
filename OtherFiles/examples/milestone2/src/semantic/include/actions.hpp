#define ACTIONS_H "actions_h"

#include "class.hpp"
#include "method.hpp"
using namespace std;

typedef int type_t;

class_data* current_class;
method_data* current_method;
int scope = 0;

void incr_scope(){ /* go to next scope */
    scope ++;
}

void decr_scope(){
    scope --;
}

int set_modifiers(int modifier, char* val){
    int mod_val;

    if(val == "public")
        mod_val = 1;
    if(va)
}

