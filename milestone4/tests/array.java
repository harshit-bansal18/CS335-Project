public class Arraystest{
    int a = 0;
    public static void main(){
        long[] array = new long[10];
        long temp;
        long i=0;
        for(; i<10; ){
            array[i] = i;
            i++;
        }
        for(i = 0; i < 9; i++){
            temp = array[i];
            // System.out.println(temp);
            System.out.println(array[i+1]);
        }
    }
}