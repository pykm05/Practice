package generic;

public class Box<T> {
    private T value;

    public Box(T... value) {
        for (T thing : value) {
            this.value = thing;
        }
    }

    public T getValue() {
        Class<?> elementType = value.getClass();
        System.out.println(elementType);
        return value;
    }
}
