class Argfunc {
    int x;
    int y = 1000;
    Argfunc(){
        x = 10;
    }
    Argfunc(int a, int b){
        x = a;
        y = b;
    }
    int func(int a, int b){
        x = b;
        return a;
    }
    int fun1(int a, int b){
        this.x = a;
        y = func(a,b);
        return b;
    }
}

public class FuncTest{
    public static void main(){
        long x = get_int();
        System.out.println(x);              // 7
        Argfunc af = new Argfunc();
        System.out.println(af.x);           // 10
        System.out.println(af.y);           // 1000
        af.func(1,2);
        System.out.println(af.x);           // 2
        af.fun1(3,4);
        System.out.println(af.x);           // 3
        System.out.println(af.y);           // 4
        Argfunc af1 = new Argfunc(5,6);
        System.out.println(af1.x);          // 5
        System.out.println(af1.y);          // 6
    }

    static int get_int() {
        return 7;
    }
}