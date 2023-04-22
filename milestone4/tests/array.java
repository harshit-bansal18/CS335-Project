public class Arraystest{
    int a = 0;
    public static void main(){
        long[] array = new long[10];
        long temp;
        long i=0;
        for(i =0; i<10; i++){
            array[i] = i;
            // i++;
        }
        for(i = 0; i < 10; i++){
            System.out.println(array[i]);
        }
    }
}