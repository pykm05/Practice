package Comparablator;

import java.util.Comparator;

public class Employee implements Comparator<Employee>{
    private String name;
    private int id;
    private int age;

    public Employee(String name, int id, int age) {
        this.name = name;
        this.id = id;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public int getId() {
        return id;
    }

    @Override
    public int compare(Employee o1, Employee o2) {
        return o1.id - o2.id;
    }
}
