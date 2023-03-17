class Me{}

public class HelloWorld
{	
	void funny(Me m){}

	public static void main(int[] args) {
		// System.out.println("Hello World!");
		Me m = new Me();
		funny(m);
	}
}