public class WhileExample2 {    
    public static void main(int[] args) {
        int j = 20;   
    // setting the infinite while loop by passing true to the condition  
        while(true){    
            for(int i=0; i<10; i++){
                if(i<20) 
                    i++;
            }
        }

        do {
            j++;
        } while (j < 6); 
    }
}    