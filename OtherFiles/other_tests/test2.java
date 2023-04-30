public class ForContinueExample {
   public static void main(String[] args) {
       String[] names = {"Mike", "Dustin", "Stranger", "Lucas", "Will"};
       for (int i = 0; i < names.length; i++) {
           if (names[i].equals("Stranger")) {
               System.out.println("I don't chat with strangers");
               continue;
           }
           System.out.println("Hello," + names[i]);
       }
   }
}