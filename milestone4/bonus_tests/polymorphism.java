public class StaticPolymorphismDemo {
    public static void main() {
        StaticPolymorphismDemo demo = new StaticPolymorphismDemo();
        int a = 2;
        int b = 3;
        int c = 4;
        long d = 5;
        long e = 6;
        System.out.println(demo.add(a, b));         // Add1
        System.out.println(demo.add(a, b, c));      // Add2
        System.out.println(demo.add(d, e));         // Add3
        System.out.println(demo.add(a, e));         // Add4

    }

    // Add1
    public int add(int a, int b) {
        return a + b;
    }

    // Add2
    public int add(int a, int b, int c) {
        return a + b + c;
    }

    // Add3
    public long add(long a, long b) {
        return a + b;
    }

    // Add4
    public long add(int a, long b) {
        return a + b;
    }
}
