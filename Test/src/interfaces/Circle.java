package interfaces;

public class Circle extends Shape{
    public Circle(int radius) {
        super(radius, 0);
    }

    @Override
    public double findArea() {
        return getWidth() * getWidth() * Math.PI;
    }

    @Override
    public void sayName() {
        System.out.println("I am a circle");
    }
}
