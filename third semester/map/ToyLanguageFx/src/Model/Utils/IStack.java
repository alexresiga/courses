package Model.Utils;

import java.util.List;

public interface IStack<T> {
    void push(T elem);
    T pop();
    boolean isEmpty();
    String toString();
    List<T> getAll();
}
