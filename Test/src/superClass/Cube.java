package superClass;

public abstract class Cube {
    public Cube() {
        System.out.println("I am a cube.");
    }

    public static void main(String[] args) {
        Cube gan = new GAN();
        Moyu moyu = new Moyu();

//        System.out.println(gan.getCornerCut());
//        System.out.println(moyu.getCornerCut());
    }
    public abstract int getCornerCut();
}
