package generic;

public class Grade<T> {
    private T[] score;

    public Grade(T[] score) {
        this.score = score;
    }

    public T[] getScore() {
        return score;
    }
}
