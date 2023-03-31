public class SyntaxCheck {
    public static void main(int[] args) {
        int a = 100, b = 0;
    }
    public boolean GFG(int x){
        int a = 20;
        return GFG(a);
    }

    public int GFG1(int y){
        boolean b = GFG(2);

        if (true) {
            int x ;
        }
        else {
            int x;
        }
    }
}
