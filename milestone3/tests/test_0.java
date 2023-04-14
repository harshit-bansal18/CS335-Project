class A{
    int[][] a = new int[5][5];
    A(int x){
        x = 5;
    }
}

class TestEmployee1 {
    public static void main() {
        // double [][]a = new double [5][6];
        // a[2][3] = 5;
        A obj = new A(5);
        int a = obj.a[2][3];
        obj.a[2][3] = 1;
    }
}

