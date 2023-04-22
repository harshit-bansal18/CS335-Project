public class DoWhileLoopExample {
    public static void main(int[] args) {
        int count = 0;
        do {
            System.out.println(count);
            count++;
            for (int i = 0; i < count; i++) {
                for (int j = 0; j < count; j++) {
                    System.out.println(j);
                }
                System.out.println(0);
            }
        } while (count < 5);
    }
}
