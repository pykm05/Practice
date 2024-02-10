package interfaces;

public class Square extends Shape{
    public Square(double width) {
        super(width, 0);
    }
    @Override
    public double findArea() {
        return getWidth() * getWidth();
    }

    @Override
    public void sayName() {
        System.out.println("I am a square");
    }
}
