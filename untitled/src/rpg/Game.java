package rpg;
import java.util.Scanner;
public class Game {
    public static int round;
    public static float multiplier = 1;
    public static boolean gameContinue = true;
    static boolean roundIncomplete = true;

    public static void begin() {
        while (gameContinue) {
            for (int i = 0; i < 2; i++) {
                combatPhase();
            }
            System.out.println("You win!");
            gameContinue = false;
        }
    }

    public static void combatPhase() {
        roundIncomplete = true;
        System.out.println("A new enemy has appeared!");
        while (roundIncomplete) {
            playerPhase();
            enemyPhase();
            roundRefresh();
        }
    }

    public static int playerPhase() {
        boolean playerTurn = true;
        while (playerTurn) {
            if (Player.health < 0) {
                roundIncomplete = false;
                return 0;
            }
            System.out.println();
            System.out.print("a for attack, b for block, i for inspect: ");
            Scanner scanner = new Scanner(System.in);
            char choice = 0;
            do {
                try {
                    choice = scanner.next().charAt(0);
                    if (choice != 'a' && choice != 'b' && choice != 'i')  {
                        throw new NumberFormatException();
                    }
                }
                catch (NumberFormatException e) {
                    System.out.println("Invalid input.");
                }
            }
            while (false);

            switch(choice) {
                case 'a' -> {
                    System.out.println(Player.name + " attacks for " + Player.attack + " damage.");
                    Enemy.health -= Player.attack;
                    playerTurn = false;
                }
                case 'b' -> {
                    System.out.println("Block");
                    playerTurn = false;
                }
                case 'i' -> {
                    System.out.println("Enemy stats:");
                    System.out.println("Health: " + Enemy.health);
                    System.out.println("Attack: " + Enemy.attack);
                    System.out.println("Crit: " + Enemy.crit + "%");
                }
            }
        }

        return 1;
    }

    public static int enemyPhase() {
        if (Enemy.health <= 0) {
            System.out.println("Enemy defeated!");
            roundIncomplete = false;
            Enemy.alive = false;

            return 0;
        }
        Player.health -= Enemy.attack;
        System.out.println("Monster attacks for 10 dmg");
        return 1;
    }

    public static void roundRefresh() {
        if (!roundIncomplete) {
            Enemy.respawn();
        }
    }
}
