public class GFG {
    int x;
    double z;
    int[][] arr;

    GFG(float x){

    }

    static void add(int a, int b){
        int sum = a + b;
        // return sum;
    }

    static void main(){
        GFG obj = new GFG(1);
        obj.x = 2;
        obj.arr =  new int[5][6];

        int a = 20;
        float b = 40;
        char c = 'a';
        boolean bool = true;

        b = b+a;
        b = a+c;
        b = a+b+c;
        bool = (b  < a) ? true: false;

        obj.add(1, 12);
    }
}