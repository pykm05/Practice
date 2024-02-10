package abstracts;

public class Dog extends Animal{
    public Dog(String type) {
        super(type);
    }
    public void makeNoise() {
        System.out.print("Woof!");
    }
}
