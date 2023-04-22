class Argfunc {
    int x;
    int y = 1000;
    static int ins0;
    static int ins1;
    static byte ins2;
    static char ins3;

    Argfunc(int a, int b){
        System.out.println(a);
        System.out.println(b);
        x = a;
        y = b;
    }
    int func(int a, int b){
        System.out.println(a);
        System.out.println(b);
        x = b;
        return a;
    }

    int fun1(int a, int b){
        System.out.println(a);
        System.out.println(b);
        this.x = a;
        y = func(a,b);

        this.no_args();
        System.out.println(2000000000000000);
        System.out.println(ins1);
        System.out.println(ins2);
        System.out.println(ins3);
        System.out.println(x);

        return b;
    }
    Argfunc(){
        x = 10;
        // y = 100;
    }

    static void no_args(){
        ins1 = 101;
        ins2 = 2;
        ins3 = 'C';
    }
}

public class FuncTest{
    static int x;
    static int y;
    static int[][] arr;

    public static void main(){
        // int c = 5;
        // long x = get_int(c,c);
        // System.out.println(x);              // 7
        // Argfunc af = new Argfunc();
        // System.out.println(af.x);           // 10
        // System.out.println(af.y);           // 1000
        // af.func(1,2);
        // System.out.println(af.x);           // 2
        // af.fun1(3,4);
        // System.out.println(af.x);           // 4
        // System.out.println(af.y);           // 3
        // Argfunc af1 = new Argfunc(5,6);
        // System.out.println(af1.x);          // 5
        // System.out.println(af1.y);          // 6

        // int d = this.get_int(200,100);
        // System.out.println(d);  // 200

        // af1.fun1(10, 20);

        // Surprisingly this works, dunno how, maybe the system puts legitimate address in ebp+16
        int y = 5;
        arr = new int[1000][1000];
        arr[999][999]= 69;
        this.y = 100+10;
        System.out.println(this.y);
        System.out.println(y);
        System.out.println(arr[999][999]);

        short[] pass_arr = new int[1000];
        arr_func(pass_arr, 1000, 1000);

    }

    static int get_int(int a, int b) {
        return a/2+b;
    }

    static int arr_func(int[] arr, int lx, int ly){
        for(int i=0; i<lx; i++){
            arr[i] = i;
        }

        System.out.println(arr[10+20]);
    }
}