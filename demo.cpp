
using namespace std;

class Demo {
public:
    int a;
    char c;
};

int main(){
    // int a;
    // int b;
    
    // if(a < b)
    //     return 10;
        
    // if(a == 0){
    //     int k = 20;
    //     k += a - b * a;
    //     return k;
    // }
    // else if(a == 20){
    //     int k = 11;
    //     k += a + b / a;
    //     return 20;
    // }
    // else{ 
    //     int k = -1;
    //     k += a - b * a * b;
    //     return 8;
    // }

    Demo *d = new Demo();
    d->a = 23;
    d->c = 'a';
    return 0;
}