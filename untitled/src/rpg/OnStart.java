package rpg;

import java.util.Scanner;
public class OnStart {
    public static String getName() {
        System.out.print("Enter your name: ");
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    public static char getRPGclass() {
        System.out.println("Choose your class:");
        Scanner scanner = new Scanner(System.in);
        boolean loop = true;
        char RPGclass = 0;
        do {
            try {
                System.out.print("Type p for paladin, k for knight, w for wizard: ");
                RPGclass = scanner.next().charAt(0);
                if (RPGclass != 'p' && RPGclass != 'k' && RPGclass !='w')  {
                    throw new NumberFormatException();
                }
                setStats(RPGclass);
                loop = confirm();
            }
            catch (NumberFormatException e) {
                System.out.println("Invalid input.");
            }
        }
        while(loop);
        return RPGclass;
    }

    private static void setStats(char RPGclass) {
        String type = "";
        switch(RPGclass) {
            case 'p' -> {
                type = "paladin";
                Player.health = 250;
                Player.attack = 35;
                Player.crit = 7;
            }
            case 'k' -> {
                type = "knight";
                Player.health = 200;
                Player.attack = 50;
                Player.crit = 9;
            }
            case 'w' -> {
                type = "wizard";
                Player.health = 150;
                Player.attack = 65;
                Player.crit = 11;
            }
        }
        System.out.println();
        System.out.println("Your stats as " + type + ":");
        System.out.println("Health: " + Player.health);
        System.out.println("Attack: " + Player.attack);
        System.out.println("Crit rate: " + Player.crit + "%");
    }
    private static boolean confirm() {
        char in = 0;
        boolean loop = true;
        do {
            try {
                System.out.println("Are you sure? (y/n): ");
                Scanner scanner = new Scanner(System.in);
                in = scanner.next().charAt(0);
                if (in != 'y' && in != 'n')  {
                    throw new NumberFormatException();
                }
                loop = false;
            }
            catch (NumberFormatException e) {
                System.out.println("Invalid input.");
            }
        }
        while (loop);

        return in != 'y';
    }

    public static void defineEnemy() {
        Enemy.alive = true;
        Enemy.health = 100;
        Enemy.attack = 15;
        Enemy.crit = 10;
    }
}
