public class Arraystest{
    int a = 0;

    static void fun1() {
        int a = 3;
        int b = (a>3)?2:4;
        System.out.println(b);
    }

    static void fun2() {
        int a = 3;
        int b = (a>3)?2:4;
        System.out.println(b);
    }

    public static void main(){
        fun1();
        fun2();
    }
}