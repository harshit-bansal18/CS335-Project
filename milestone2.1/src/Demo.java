class Me{}

public class Demo
{	
	public int b;
	public int a;
	Me m;
	
	void funny(Me m){}

	public static void main(int[] args) {
		// System.out.println("Hello World!");
		Me m = new Me();
		int a_ = 0;
		int b_ = 9;
		int ff = 0;
		int c = a_ + b_;
		funny(m);
	}
}

public class Example {
    int x;
    static double y;
    
    public void foo(int a, int b) {
        double c = 1.23;
        char d = 'x';
    }
    
    public static void example_f(int[] args) {
        int i = 42;
        int s = 2;
        Example e = new Example();
        e.foo(i, s);
    }
}