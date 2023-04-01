public class TypeCheck1 {
    int a;
    float b = getA();
   
    public TypeCheck1(int a1, int b1) {
        // this.c = a1;
        b = b1;
    }

    public int getA() {
        return a;
    }

    public float getB() {
        return b;
    }

    public void setA(int a1) {
        a = a1;
    }

    public void setB(float b1) {
        b = b1;
    }

    public static void main(int[] args) {
        int [] a = new int[10];
        TypeCheck1 obj = new TypeCheck1(1, 2);
        float e;
        float f=14.9;
        float g=4.5;
        e=f+g;
        // Same names
        // int a = obj.a;
        float b = obj.b;

        // Different names
        int c = obj.a;
        float d = obj.b;
    }
}