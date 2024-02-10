public class Thing {

    public static void main(String[] args) {
        detect("s", 1);
        detect(1);
//        String.format("This is an integer: %d", myInt);
//        String.format("This is an integer: %d and a string: %s", myInt, myString);
    }

    public static <T> void detect(T...args) {
        for (T string : args) {
            String thing = String.format("%s", string); // For demonstrative purposes
            System.out.printf("%s", thing);
        }
    }
}
