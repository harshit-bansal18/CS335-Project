public class TypeCheck1 {
    int a;
    long b;
   
    public TypeCheck1(int a1, int b1) {
        a = a1;
        b = b1;
    }

    public int getA() {
        return a;
    }

    public long getB() {
        return b;
    }

    public void setA(int a1) {
        a = a1;
    }

    public void setB(long b1) {
        b = b1;
    }

    public static void main(int[] args) {
        TypeCheck1 obj = new TypeCheck1(1, 2);
        // Same names
        int a = obj.a;
        int b = obj.b;

        // Different names
        int c = obj.a;
        int d = obj.b;

        System.out.println(c);
        System.out.println(d);
    }
}