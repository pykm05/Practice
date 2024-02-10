package interfaces;

public class Main {
    // https://stackoverflow.com/questions/10040069/abstract-class-vs-interface-in-java#:~:text=Interface%20is%20used%20when%20you,same%20and%20some%20different%20functionality.

    public static void main(String[] args) {
        Shape[] shapes = new Shape[3];
        shapes[0] = new Square(5);
        shapes[1] = new Rectangle(2, 5);
        shapes[2] = new Circle(3);

        for(Shape i : shapes) {
            i.sayName();
            System.out.println(i.findArea());
        }
    }
}
