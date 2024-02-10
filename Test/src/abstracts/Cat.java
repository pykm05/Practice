package abstracts;

public class Cat extends Animal{
    public Cat() {
        super("nyan cat");
    }

    public void makeNoise() {
        System.out.print("Meow.");
    }
}
