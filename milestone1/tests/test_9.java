import java.util.Scanner;

public class RandomJavaCode {
  
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    
    // declare variables
    int num1, num2, sum;
    String name;
    
    // get user input
    System.out.print("Enter your name: ");
    name = input.nextLine();
    System.out.print("Enter the first number: ");
    num1 = input.nextInt();
    System.out.print("Enter the second number: ");
    num2 = input.nextInt();
    
    // perform arithmetic operations
    sum = num1 + num2;
    int difference = num1 - num2;
    double quotient = num1 / (double) num2;
    
    // print results
    System.out.println("Hello, " + name + "!");
    System.out.println("The sum of " + num1 + " and " + num2 + " is " + sum);
    System.out.println("The difference between " + num1 + " and " + num2 + " is " + difference);
    System.out.println("The quotient of " + num1 + " and " + num2 + " is " + quotient);
    
    // use conditional statements
    if (sum > 0) {
      System.out.println("The sum is positive.");
    } else if (sum < 0) {
      System.out.println("The sum is negative.");
    } else {
      System.out.println("The sum is zero.");
    }
    
    // use a loop
    for (int i = 0; i < sum; i++) {
      System.out.print("*");
    }
    System.out.println();
    
    // use arrays
    int[] numbers = {num1, num2, sum, difference};
    for (int i = 0; i < numbers.length; i++) {
      System.out.println("Number " + (i+1) + ": " + numbers[i]);
    }
    
    // use a method
    int product = multiply(num1, num2);
    System.out.println("The product of " + num1 + " and " + num2 + " is " + product);
  }
  
  public static int multiply(int a, int b) {
    return a * b;
  }
}
