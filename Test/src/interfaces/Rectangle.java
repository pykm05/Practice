package interfaces;

public class Rectangle extends Shape{
    public Rectangle(int width, int height) {
        super(width, height);
    }

    @Override
    public double findArea() {
        return getWidth() * getHeight();
    }

    @Override
    public void sayName() {
        System.out.println("I am a rectangle");
    }
}
