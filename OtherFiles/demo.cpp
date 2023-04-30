#include <stdio.h>
#include <stdlib.h>

// void fun() {
//     int b = 34;
// }

// int hi(){
//     return 1;
// }

    long geta(long a){
        printf("%ld",a);
        return a;
    }

    long geta(long a[][5+2*3/4][7], int b[][4]){
        // printf("%ld",a);
        return a[1][2][3];
    }            

    int main(){
        long b = geta(1);
        // int c = 2;
        printf("%ld",b);

        // how does gcc handle this ?
        long x = 100;
        // long a[] = new long[x];
        // or 
        long a[x];

        return 0;
    }

// int main(){
//     // int a=0;
//     // int c = 20;
//     int  a = hi();
//     fun();
// }