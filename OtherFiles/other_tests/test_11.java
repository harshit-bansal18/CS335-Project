// ERror 1

class Computer {
  int a;
  boolean b;
  Laptop l;
  Computer() {
    a = 20;
    b = false;
  }
 
  void computer_method() {
    int j = 0;
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
 
  public static void main(int[] args) {
    Computer my = new Computer();
    Laptop your = new Laptop();
   
    my.computer_method();
    your.laptop_method();
  }
}
class Laptop {
    int a[][]; 
    int b[][]={{1,3,4},{2,4,3},{1,2,4}};   
    final int c = 90;
  Laptop() {
    a = new int[4][5];
  }
 
  void laptop_method() {
        int row, col;
        int matrix[][] = new int[4][5];
        for (row = 0; row < 10; row++) {
            for (col = 0; col < 20; col++) {
 
                int n = matrix[row][col];
            }
        }
  }
}