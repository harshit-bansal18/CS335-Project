public class Singleton {
    int g=3;
    int d;
    int arr[][] = new int[20][5];

    Singleton(){

    }

    Singleton(int m, int c)
    {   
        // System.out.println(g);
        this.g = 5;
        // System.out.println(g);

        for(int i=0; i<20; i++){
            for(int j=0; j<5; j++)
                arr[i][j] = i+j;
        }

        int k = 15;
        System.out.println(arr[k][4]);

        arr = new int[2][3];

        System.out.println(arr[0][0]);
    }
    int yo(int a,int b)
    {
        return a+b;
    }

    public static void main()
    {
        int arr[][] = new int[20][5];
        Singleton s=new Singleton(10, 20);
        for(int i=0; i<20; i++){
            for(int j=0; j<5; j++){
                arr[i][j] = i+j;
                // if(i==15 && j==4)
                    // System.out.println(arr[i][j]);
            }
        }

        int k = 15;
        // System.out.println(10000);
        // System.out.println(k);
        // System.out.println(10000);
        // for(int i=0;i<5;i++)
            // System.out.println(arr[k/][i]);
        // System.out.println(10000);
        
    }
    void a()
    {
        int a=3;
        int b=4;
        int c=a+b;
    }
}