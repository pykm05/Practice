package interfaces;

public abstract class Shape implements ShapeRevealer {
    // Unlike Lab 8, height and width aren't being resized, so height and width are declared final
    // because they are not changed after they are initialized by the constructors
    private final double height;
    private final double width;

    public Shape(double width, double height) {
        this.height = height;
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public double getWidth() {
        return width;
    }

    public abstract double findArea();
}
