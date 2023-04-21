public class Arg {
    int x;
    int a;

    Arg(int b) {
        a = 69;
    }

    int func(int a, int b){
        int x = 100;
        return x;
    }
}

public class FuncTest{

    public static void main(){
        int c = 2+3;
        int a = get_int(20, c, 10*5); // 
        System.out.println(a);
        a = get_int(20); // 
        System.out.println(a);
    }

    static int get_int(int a) {
        return 10;
    }

    static int get_int(int a, int b, long c) {
        System.out.println(a); // 20
        System.out.println(b); // 5
        System.out.println(c); // 50
        int d = a+b; // 25
        System.out.println(d);
        int e = c/5; // 10
        System.out.println(e);
        return (c+d)*5 + c; // 425
    }
}