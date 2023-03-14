#define ACTIONS_H "actions_h"

#include "class.hpp"
#include "method.hpp"
using namespace std;

typedef int type_t;

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
    if(val == "private")
        mod_val = 2;
    if(val ==)
}

