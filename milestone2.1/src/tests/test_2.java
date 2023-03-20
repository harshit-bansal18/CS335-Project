public class TypeCheck1 {
    int a;
    float b;
   
    public TypeCheck1(int a1, int b1) {
        // this.c = a1;
        this.b = b1;
    }

    public int getA() {
        return this.a;
    }

    public float getB() {
        return this.b;
    }

    public void setA(int a1) {
        this.a = a1;
    }

    public void setB(float b1) {
        this.b = b1;
    }

    public static void main(int[] args) {
        TypeCheck1 obj = new TypeCheck1(1, 2);
        float e;
        float f=14.9;
        float g=4.5;
        e=f+g;
        // Same names
        int a = obj.a;
        float b = obj.b;

        // Different names
        int c = obj.a;
        float d = obj.b;
    }
}