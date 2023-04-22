// Bubble Sort Example in Java

public class BubbleSortExample {  
    static int arr[] = new int[7];

    static void bubbleSort(int n) {  
        int temp = 0;  
         for(int i=0; i < n; i++){  
                for(int j=1; j < (n-i); j++){  
                        
                        System.out.println(arr[j-1]);
                        System.out.println(arr[j]);
                        
                        if(arr[j-1] > arr[j]){ 
                                
                                //swap elements  
                                temp = arr[j-1];  
                                arr[j-1] = arr[j];  
                                arr[j] = temp;  
                        }  
                          
                }  
         }  
    }  

    public static void main(int[] args) {  
                
                BubbleSortExample bubble = new BubbleSortExample();

                bubble.arr[0] = 3;
                bubble.arr[1] = 60;
                bubble.arr[2] = 35;
                bubble.arr[3] = 2;
                bubble.arr[4] = 45;
                bubble.arr[5] = 320;
                bubble.arr[6] = 5;  
                 
                for(int i=0; i < 7; i++){  
                    System.out.println(bubble.arr[i]);  
                }   
                  
                bubble.bubbleSort(7);//sorting array elements using bubble sort  
                 
                for(int i=0; i < 7; i++){  
                        System.out.println(bubble.arr[i]);  
                }  
   
        }  
}  