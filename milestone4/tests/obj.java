public class Arg {
    int x;
    int a;
}

public class ObjTest{
    public static void main(){
       Arg a1 = new Arg();
       a1.x = 20;
       System.out.println(a1.x);
       System.out.println(a1.a);
    }
}