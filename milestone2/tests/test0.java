public class A{
    public int x;
    public int y;
    public A (int a, int b){
        x = a + b ;
    }
    public void setX(int a){
        x = a;
    }
}

public class B extends A{
    public int z;
    public B(int a, int b){
        super(a,b);
        z= a;
    }
    public void setX(int a){
        x = 2*a;
    }
    public void setZ(int a){
        z = a;
    }
}


/*


Symbol	    Type	    Scope	    Offset
x.A	        int	        class	    0
y.A	        int	        class	    1
A.A	        cnstrctr	class	    N/A
setX.A	    void	    class	    N/A

Symbol	    Type	    Scope	    Offset
z.B	        int	        class	    2

*/