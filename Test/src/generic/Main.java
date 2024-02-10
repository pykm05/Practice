package generic;

public class Main {
    public static void main(String[] args) {
        Box<Integer> intBox = new Box<>(42, 30);

        int boxValue = intBox.getValue();
        System.out.println(boxValue);
    }
}
