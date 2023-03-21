class Me{
	Me(int b){
		int a;
		a= 20;
		b = 5;
		double[] b_ = {20,4};
		return;
	}

	Me() {}

	void func1() {
		return ;
	}
}

public class Demo
{
	public long b ;
	public boolean a = false;
    public double c = 20.0;
	public static Me m = new Me();
    public double[] array = {};
	double [][]array1 = new double[3][];
	
    public Demo(int a1, int b1) {
        this.c = a1;
        this.b = b1;
    }

	void funny(){
		int a = 12;
		int b = 23;

		int i;
		for(int j = 0; j < 10; j++) {
			i = 9;
			int d = i << 2;
			for(int k=2; k<5; k++){
				if(k==2){
					return;
				} else {
					continue;
				}
			}
		}

		if(true) {
			int x = 20;
		} else {
			int x = 40;
		}
	}

	int funny(int m) {
		return 3;
	}

	public static void main(int[] args) {
		// System.out.println("Hello World!");
		Me m = new Me();
		int a_ = 0;
		int b_ = 9;
		int ff = 0;
		int c = a_ + b_;
		// funny(c);
	}
}

class Example {
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
