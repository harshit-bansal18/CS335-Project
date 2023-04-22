public class GFG {
    int x;
    int z;
    int[][] arr = new int[10][20];

    GFG(int x){
        for(int i=0; i<10; i++){
            for (int j=0; j<20; j++){
                arr[i][j] = i+j;
            }
        }
    }

    static int add(int a, int b){
        int sum = a + b;
        return sum;
    }

    static void main(){
        GFG obj = new GFG(1);
        obj.x = 2;

        int a = 20;
        int b = 40;
        char c = 'a';
        boolean bool = true;

        b = b+a;
        b = a+c;
        b = a+b+c;
        bool = (b  < a) ? true: false;

        System.out.println(obj.add(obj.arr[2][3], obj.arr[4][5]));
    }
}