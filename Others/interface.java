// package abc;

// import java.utils.*;
// public static class BubbleSort {
//     public static void main(int hello, int args []) {
//         int a;
//         float b = (float) a++; 
//         System.out.println("Hello"+"World");
//     }
// }

interface FirstInterface {
  public void myMethod(); // interface method
}

interface SecondInterface {
  public void myOtherMethod(); // interface method
}

class DemoClass implements FirstInterface, SecondInterface {
  public void myMethod() {
    System.out.println("Some text..");
  }
  public void myOtherMethod() {
    System.out.println("Some other text...");
  }
}

class Main {
  public static void main(String[] args) {
    DemoClass myObj = new DemoClass();
    myObj.myMethod();
    myObj.myOtherMethod();
  }
}

class ReverseNumberExample2   
{   
    public static void main(int args[])   
    {   
        int a = (b.a.c)a++;
        
        int number = 123456, reverse = 0;  
    //we have not mentioned the initialization part of the for loop  
        for( ;number != 0; number=number/10)   
        {  
            int remainder = number % 10;  
            reverse = reverse * 10 + remainder;  
        }

        class BuzzNumberExample {   
    
            // create checkNumber() method that returns true when it founds number Buzz   
            static boolean checkNumber(int number)   
            {   
                // check whether the number ends with 7, is divisible by 7 or not  
                if(number % 10 == 7 || number % 7 == 0)  
                    return true;    //returns true when the number is Buzz  
                else  
                    return false;   //returns flase when the number is not Buzz  
            }   
            
            // main() method start  
            public static void main(int args[])   
            {     
                int n1, n2;  
                
                //create scanner class object to get input from user  
                Scanner sc=new Scanner(System.in);  
                Scanner a;
                a = new Scanner();
                
                //show custom message  
                System.out.println("Enter first number");  
                
                //store user entered value into variable n1  
                n1 = sc.nextInt();  
                
                //show custom message  
                System.out.println("Enter second number");  
                
                //store user entered value into variable n2  
                n2 = sc.nextInt();  
                int a = "Hello" + "Jaya";
                if (checkNumber(n1))   
                    System.out.println(n1 + " is a Buzz number");   
                else  
                    System.out.println(n1 + " is not a Buzz number");   
                if (checkNumber(n2))   
                    System.out.println(n2 + " is a Buzz number");   
                else  
                    System.out.println(n2 + " is not a Buzz number");   
            }   
        }

        // Scanner a;
        System.out.println("The reverse of the given number is: " + "Hello");  
    }  
}

//import required classes and packages  
import Java.util.*;   
import java.io.*;   
import java.util.Scanner;  
  
//create BuzzNumberExample class to check whether the given number is Buzz number or not  
class BuzzNumberExample {   
    
    // create checkNumber() method that returns true when it founds number Buzz   
    static boolean checkNumber(int number)   
    {   
        // check whether the number ends with 7, is divisible by 7 or not  
        if(number % 10 == 7 || number % 7 == 0)  
            return true;    //returns true when the number is Buzz  
        else  
            return false;   //returns flase when the number is not Buzz  
    }   
    
    // main() method start  
    public static void main(int args[])   
    {     
        int n1, n2;  
          
        //create scanner class object to get input from user  
        Scanner sc=new Scanner(System.in);  
          
        //show custom message  
        System.out.println("Enter first number");  
          
        //store user entered value into variable n1  
        n1 = sc.nextInt();  
          
        //show custom message  
        System.out.println("Enter second number");  
          
        //store user entered value into variable n2  
        n2 = sc.nextInt();  
          
        if (checkNumber(n1))   
            System.out.println(n1 + " is a Buzz number");   
        else  
            System.out.println(n1 + " is not a Buzz number");   
        if (checkNumber(n2))   
            System.out.println(n2 + " is a Buzz number");   
        else  
            System.out.println(n2 + " is not a Buzz number");   
    }   
}