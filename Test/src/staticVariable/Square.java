package staticVariable;

public class Square extends Main{
    public Square() {
        System.out.println("This is a square");
    }

    @Override
    public void increaseCount() {
        staticVariable++;
        instanceVariable++;
    }
}
