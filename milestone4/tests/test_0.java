class TestEmployee1 {
    int x = 2+3;
    public static int main() {  
            long k = 1000000;
            long a=0;
            int c = 5<<2;
            System.out.println(c);
            long d = 4;
            a = (c+20)*(1<<2);
            System.out.println(a);
            if(a == 160){
                System.out.println(d);
                a=5/((2+3*8)%(5+0));
                
            }
            System.out.println(a);

            for(int i=0; i<10; i++){
                int j = 0;
                while(j<10){
                    if(j++<5)
                        System.out.println(k);
                }
                System.out.println(j);
                System.out.println(i);
            }

            
            long b = a+d/c%2 ;
            if(a!=b){
                a = b;
            }
    }
}