#include <bits/stdc++.h>
using namespace std;

typedef struct stackentry{
    int token;
    string threeac="";
}stackentry;

typedef struct entry3ac{
    string threeac="";
} entry3ac;

void emit(string op, string arg1, string arg2, string result){
    cout<<op<<" "<<arg1<<" "<<arg2<<" "<<result<<endl;
}

int loopnum=0;
int ifnum=0;
