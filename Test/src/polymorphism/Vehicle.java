package polymorphism;
public class Vehicle {
    public void startEngine() {
        System.out.println("Vehicles release carbon emissions");
    }

    public static void main(String[] args) {
        Vehicle[] vehicle = new Vehicle[3];
        vehicle[0] = new Motorcycle();
        vehicle[1] = new Car();
        vehicle[2] = new Vehicle();

        vehicle[0].startEngine();
        vehicle[1].startEngine();
        vehicle[2].startEngine();
    }
}
