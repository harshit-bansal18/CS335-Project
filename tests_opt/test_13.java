class Computer {
    int a;
    static Laptop l;

    int c;

    static int main(int[] args) {
        int d;

        // Typename -> check variable in class
        double a = l.c.a;

        // check function in class
        l.lappy(2,2,'a');

        l.lappy(a);

        l.c.func();

        // No function as such
        l.no_func(1,3);
    }

    void func() {}
}

class Laptop {

    Computer c;

    int lappy(int a, double b, char c){

    }

    int lappy(double a){

    }
}