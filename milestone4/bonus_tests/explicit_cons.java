

class Argfunc {
    int x;
    int y = 1000;
    Argfunc(int a, int b){
        this();

        System.out.println(a);
        System.out.println(b);
        x = a;
        y = b;
    }

    Argfunc(){
        this.x = 10;
        y = 20;
        System.out.println(x);
        System.out.println(y);
        // y = 100;
    }
}

public class FuncTest{
    public static void main(){
        Argfunc af = new Argfunc(100, 200);     
        System.out.println(af.y+100);
    }

    static int get_int(int a, int b) {
        return a/2+b;
    }
}