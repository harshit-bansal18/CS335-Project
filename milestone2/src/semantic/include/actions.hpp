#define ACTIONS_H "actions_h"

#include "class.hpp"
#include "method.hpp"
using namespace std;

typedef int type_t;

class_data* current_class;
method_data* current_method;
int scope = 0;

