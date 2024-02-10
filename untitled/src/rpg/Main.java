package rpg;

public class Main {
    public static void main(String[] args) {
        Player.name = OnStart.getName();
        Player.RPGclass = OnStart.getRPGclass();

        OnStart.defineEnemy();

        Game.begin();
    }
}
