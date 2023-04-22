public class Main
{
    int a=100;
    static int b = 10;
    static int [] arr = new int[10];
    static int geta(){
        return 5;
    }

    static int main(){
        // int b = geta();
        int c = 2+3;
        Main m = new Main();
        m.a = 5+6;
        System.out.println(b);
        System.out.println(m.a);
        System.out.println(m.arr[0]);
        return 0;
    }

    Main(){
        int b = 7;
        System.out.println(this.a);
    }

}
