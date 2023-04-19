public class Arg {
    int x;
    int a;

    int func(int a, int b){
        int x = 100;
        return x;
    }
}

public class FuncTest{
    public static void main(){
        Arg a1 = new Arg();
        a1.x = 20;
        // System.out.println(a1.x);
        // System.out.println(a1.a);

        a1.x = a1.func(500, 20);
        System.out.println(a1.x);
        // System.out.println(a1.a);
        // int a = get_int();
        // System.out.println(a);
    }

    static int get_int() {
        int c = 20+30;

        int d = c/5;
        return (c+d)*5 + c;
    }
}