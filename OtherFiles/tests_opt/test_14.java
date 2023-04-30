// ERror 1

class Computer {
  int a;
  boolean b;
//   Laptop l;

  Computer() {
    a = 20;
    b = false;
  }
 
  void  main() {
    int j = 0;
    int count = 0;
    while(true){    
        for(int i=0; i<10; i++){
            if(i<20) 
                i++;
            
            count++;
        }
    }

    System.out.println(count);

    do {
        j++;
    } while (j < 6); 

    System.out.println(j);
  }
}