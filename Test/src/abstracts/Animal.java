package abstracts;

public abstract class Animal {
    public String animalType;

    public static void main(String []args) {
        Animal dog = new Dog("Bulldog");
        dog.makeNoise();

        Animal cat = new Cat();
        cat.makeNoise();
    }

    public Animal(String type) {
        this.animalType = type;
        System.out.print("I say... " + animalType);
    }

    public abstract void makeNoise();
}
