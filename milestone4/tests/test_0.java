class TestEmployee1 {
    int x = 2+3;
    public static int main() {  
            long k = 1000000;
            long a=0;
            int c = 5<<2;
            System.out.println(c); // 20
            long d = 4;
            a = (c+20)*(1<<2); 
            System.out.println(a); // 160
            if(a == 160){
                System.out.println(d); // 4
                a=5/((2+3*8)%(5+0)); 
                
            }
            System.out.println(a); // 5

            for(int i=0; i<10; i++){
                for(int j=0; j<10; j++)
                    System.out.println(i+j);
            }

            
            long b = a+d/c%2 ;
            if(a!=b){
                a = b;
            }
    }
}