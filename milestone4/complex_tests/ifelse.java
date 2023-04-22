// Complex multiconditional if-else nested java code involving all kind of operators:
// if, else, else if, ==, !=, >, <, >=, <=, &&, ||, !, +, -, *, /, %, ++, --, +=, -=, *=, /=, %=

public class ifelse {
    public static void main(){
        boolean h = true;
        int i = 1;
        int c = 2;
        int d = 3;
        int e = 4;
        int f = 5;
        int g = 6;

        if(i!=1){
            System.out.println(1000);
        }

        if( !h && i != 0
					&& c != d
					&& e + f < g ){
            long a = 293989;
            long b = a&a;
            System.out.println(b);
        }
        else{
            System.out.println(2);
        }
    }
}