package Model.Utils;

import java.util.List;

public interface IList<T> {
    boolean add(T elem);
    void clear();
    int size();
    boolean isEmpty();
    T get(int id);
    String toString();
    List<T> getAll();
}
