package superClass;

public class Moyu extends Cube{
    private final int cornerCut = 45;
    public Moyu() {
        System.out.println("A Moyu cube.");
    }

    public int getCornerCut() {
        return cornerCut;
    }
}
