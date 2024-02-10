package rpg;

public class Player {
    public static char RPGclass;
    public static String name;
    public static int health;
    public static int attack;
    public static int crit;
    public static boolean alive = true;

    public Player() {
        if (health <= 0 && (Game.gameContinue)) {
            alive = false;
            System.out.println(name + " has fallen.");
        }
    }
}
