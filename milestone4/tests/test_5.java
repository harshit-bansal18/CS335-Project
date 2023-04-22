// Object Implementation

public class Arg {
    int x=5;
    int a;
    int already_init = 11;
    long arr[][];

    Arg(int b) {
        a = 69;
        a++;
        ++a;
        x = 96;
        arr = new long[5][6];
        arr[1][2] = 26;
        
        System.out.println(arr[1][2]); // 26
        System.out.println(x); // 96
        int x = b;
        System.out.println(x); // 5
        System.out.println(this.a); // 71
    }

    int func(int a, int b){
        int x = 100;
        return x;
    }
}

public class FuncTest{
    public static void main(){
        Arg a1 = new Arg(5);
        a1.x = 20;
        System.out.println(a1.x); // 20
        System.out.println(a1.a); // 71
        System.out.println(a1.already_init); // 11 --> Not working yets

        a1.x = a1.func(500, 20);
        System.out.println(a1.x);
        System.out.println(a1.a);

    }
}