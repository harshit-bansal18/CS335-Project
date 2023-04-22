// Complex java code which involves all kinds of loops and its features like nesting, break, continue, etc.

public class loops {
    public static void main() {
        // for loop
        for (int i = 0; i < 4; i++) {
            System.out.println(i);
        }

        // while loop
        int i = 0;
        while (i < 4) {
            System.out.println(i);
            i++;
        }

        // do while loop
        int j = 0;
        do {
            System.out.println(j);
            j++;
        } while (j < 4);

        // for each loop
        int[] arr = new int[4];
        for (int k=0; k<4; k++) {
            arr[k] = k+5;
            System.out.println(arr[k]);
        }

        // nested for loop
        for (int k = 0; k < 4; k++) {
            for (int l = 0; l < 4; l++) {
                System.out.println(k + l );
            }
        }

        // break statement
        for (int k = 0; k < 4; k++) {
            if (k == 2) {
                break;
            }
            System.out.println(k);
        }

        // continue statement
        for (int k = 0; k < 4; k++) {
            if (k == 2) {
                continue;
            }
            System.out.println(k);
        }
    }
}

// Output
