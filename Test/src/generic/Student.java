package generic;

public class Student {
    public static void main(String []args) {
        Integer[] profile = {9, 75,325};
        Double[] profile2 = {39.2};
        Grade<Integer> profileBox = new Grade<>(profile);
        Grade<Double> profileBox2 = new Grade<>(profile2);

        Integer[] retrievedProfile = profileBox.getScore();
        Double[] retrievedProfile2 = profileBox2.getScore();
        for (int test : retrievedProfile) {
            System.out.println(test);
        }
        for (double test : retrievedProfile2) {
            System.out.println(test);
        }
    }
}
