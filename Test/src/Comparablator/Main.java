package Comparablator;

public class Main{
    // https://www.digizol.com/2008/07/java-sorting-comparator-vs-comparable.html

    public static void main(String[] args) {
        Employee[] employees = new Employee[3];
        employees[0] = new Employee("Jared", 2, 16);
        employees[1] = new Employee("Aaaaa", 1, 48);
        System.out.println("Name ID Age");


        for(Employee e : employees) {
            System.out.println(e.getName() + " " + e.getId());
        }
    }
}

