package rpg;

public class Enemy {
    public static boolean alive;
    public static float health;
    public static float attack;
    public static int crit;

    public Enemy() {

    }
    public static void respawn() {
        Enemy.alive = true;
        health = 100 * Game.multiplier;
        attack = 10 * Game.multiplier;
    }
}
