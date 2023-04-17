class A{

    TestEmployee1 c;
    int x;
    int[][] a = new int[5][5];
    A(int x){
        x = 5+10;
    }
}

class TestEmployee1 {

    int x;

    TestEmployee1(int x, int y){
        int zoo = 20;

        while(x < 20){
            y = x+zoo;
            x >>>= zoo;
        }

        for(int  i=0 ; i<20; i++){
            zoo += 1;
        }

        int i = 0;
        do{    
            i++;    
            x = x+y;
        }while(i<=10);    
    }

    static void f(int a, int b, int c, int d, int e, int f){ 

        int x = 20;
        int y = 10;
        x = a+y;

        f = 20;
    }

    public static int main() {
        // A obj = new A(5);

        // int arr[][] = new int[5][6];
        
        int a = 1, b = 2, c = 3, d= 4, e= 5,f=6;
        a = 10;

        if(a!=b){
            a = b;
        }
        // a = obj.c.x;
        // a = c;
        // a = 1;
        // a = b;

        // a = d /c;
        // b = 10+20;

        // boolean bool = true;
        // if(b<20 && a==10){
        //     int x = 20;
        //     a = x+20;
        //     return 10;
        // } else {
        //     int y = b+c;
        //     return y;
        // }

        // f(a, b, c, d, e , f);
    }
}

