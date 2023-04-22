public class MultiDimensionalArray {
    public static void main() {
        int[][][] threeDimensionalArray = new int[3][4][5]; // 3 x 4 x 5 integer array

        // Assign values to threeDimensionalArray
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 5; k++) {
                    threeDimensionalArray[i][j][k] = (i + 1) * (j + 1) * (k + 1);
                }
            }
        }

        // Print values of threeDimensionalArray
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 5; k++) {
                    System.out.println(threeDimensionalArray[i][j][k]);
                }
                System.out.println(100000001);
            }
            System.out.println(200000002);
        }
    }
}
