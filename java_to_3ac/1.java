// Online Java Compiler
// Use this editor to write, compile and run your Java code online

class HelloWorld {
    
    public static void main(String[] args) {
        B a = new B();
        System.out.println(a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.a.x);
    }
}
class B{
    A a= new A();
    int x=0;
    B(){
        System.out.println("Hello, World!");
    }
}
class A{
    B a= new B();
    int x=0;
    A(){
        System.out.println("Hello, World!");
    }
}