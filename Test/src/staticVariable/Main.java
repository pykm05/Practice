package staticVariable;

public abstract class Main {
    static int staticVariable = 0;
    int instanceVariable = 0;

    public static void main(String[] args) {
        Main square = new Square();
        Main circle = new Circle();

        square.increaseCount();
        circle.increaseCount();

        // "square.staticVariable" can be written as just staticVariable since it is
        // associated with the class itself
        System.out.println("static square: " + square.staticVariable);
        System.out.println("instance square: " + square.instanceVariable);

        System.out.println("static circle: " + circle.staticVariable);
        System.out.println("instance circle: " + circle.instanceVariable);
    }
    public abstract void increaseCount();
}
