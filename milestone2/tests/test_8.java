public class Main {

  public static void main(int[] args) {
    int number = 34;
    boolean flag = false;
    for (int i = 2; i <= number / 2; ++i) {

      // condition for i to be a prime number
      if (checkPrime(i)) {

        // condition for n-i to be a prime number
        if (checkPrime(number - i)) {
          flag = true;
        }

      }
    }
  }
  // Function to check prime number
  static boolean checkPrime(int num) {
    boolean isPrime = true;

    for (int i = 2; i <= num / 2; ++i) {
      if (num % i == 0) {
        isPrime = false;
        break;
      }
    }

    return isPrime;
  }
}