public class RecursionExample3 {  
    static int factorial(int n){      
          if (n == 1)      
            return 1;      
          else      
            return(n * factorial(n-1));      
    }    
    static int factorial1(int n){      
          if (n == 1)      
            return 1;      
          else      
            return(n * factorial(n-1));      
    }    
    static int factorial2(int n){      
          if (n == 1)      
            return 1;      
          else      
            return(n * factorial(n-1));      
    }    
    static int factorial3(int n){      
          if (n == 1)      
            return 1;      
          else      
            return(n * factorial(n-1));      
    }    
    static int factorial4(int n){      
          if (n == 1)      
            return 1;      
          else      
            return(n * factorial(n-1));      
    }      
  
    public static void main(int[] args) {  
        factorial(5);  
    }  
}  