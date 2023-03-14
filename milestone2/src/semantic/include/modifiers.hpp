#include <unordered_map.h>
#include <string.h>

#define ACCESS 0b10
#define PUBLIC 0b11
#define PRIVATE 0b10
#define STATIC 0b100
#define ABSTRACT 0b1000

using namespace std;

unordered_map<string, int8_t> modifiers = {{"public", ACCESS}, {"private", ACCESS},,
                                            {"static", STATIC},
                                            {"abstract", ABSTRACT}};
                                             