#include <stdio.h>

int f(int a,  int b) {
    int x = a+b;
    return x;
}

int main(void) {
    int x = 5, y = 3;
    int z;
    z = x * y;
    z = x / y;
    z = x % y;
    int a = 5, b = 6;
    f(a, b);
    return 0;
}

