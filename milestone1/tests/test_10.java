import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to the game of Hangman!\n");

        String[] words = {"computer", "programmer", "software", "debugger", "compiler", "developer"};
        String wordToGuess = words[(int) (Math.random() * words.length)];
        char[] hiddenWord = new char[wordToGuess.length()];

        for (int i = 0; i < hiddenWord.length; i++) {
            hiddenWord[i] = '_';
        }

        int triesLeft = 6;

        while (triesLeft > 0 && new String(hiddenWord).contains("_")) {
            System.out.println("You have " + triesLeft + " tries left. The word to guess is:");
            System.out.println(hiddenWord);
            System.out.print("Enter a letter: ");

            String input = scanner.nextLine();

            if (input.length() != 1) {
                System.out.println("Please enter a single letter.");
                continue;
            }

            char guess = input.charAt(0);
            boolean correctGuess = false;

            for (int i = 0; i < wordToGuess.length(); i++) {
                if (wordToGuess.charAt(i) == guess) {
                    hiddenWord[i] = guess;
                    correctGuess = true;
                }
            }

            if (!correctGuess) {
                System.out.println(guess + " is not in the word.");
                triesLeft--;
            }
        }

        if (triesLeft == 0) {
            System.out.println("You lose! The word was " + wordToGuess + ".");
        } else {
            System.out.println("Congratulations, you guessed the word!");
        }
    }
}
