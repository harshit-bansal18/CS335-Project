public class GFG {
    static int x;
    double z;
    Dummy dummy;
    int[][] arr;
    


    GFG(int x, double z){
        this.x = x;
        this.z = z;

        if(x < z)
            return;
        else 
            this.z = x+z;
    }

    static void sub(int a, int b, float c, char d, int e, boolean f, int h,  int i){
        return;
    }

    static int add(int a, int b){
        int sum = a + b;
        int arr[][] =  new int[3][4];

        x = 5;

        // Missing object reference here in 3ac
        sub(1,1,1,'c', 1, true, 2, 2);

        return 5;

        int dead_var = 2;
        int dead_var2 = 2;

    }

    static void main(){
        GFG obj1;

        GFG obj = new GFG(1, 1.5);
        // Object reference coming wrong in 3ac
        obj.x = 2;
        // obj.x = obj1.x;
       

        int a = 20;
        obj.x = a;
        // Error here
        a = obj.x;
        float b = 40;
        char c = 'a';
        boolean bool = true;
        // Object reference coming wrong in 3ac
        obj.arr =  new int[10][20];

        b = b+a;
        b = a+c;
        b = a+b+c;
        bool = (b  < a) ? true: false;

        obj.add(1, 12);
        // Object reference  passing wrong in 3ac
        sub(1, 2, obj.x, '4', 5, true, 7, 8);

        int i = 0;
        int j = 0;
        int k =  0;

        // Array reference wrong in 3ac
        i = obj.arr[i][j];

        int new_arr[][] = new int[200][300];
        i = new_arr[i][j];
    }
}

class Dummy {
        float a;
        int b;
        char c;
}