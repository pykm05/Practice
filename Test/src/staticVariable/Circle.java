package staticVariable;

public class Circle extends Main{
    public Circle() {
        System.out.println("This is a circle");
    }

    @Override
    public void increaseCount() {
        staticVariable++;
        instanceVariable++;
    }
}
