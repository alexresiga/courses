package model.utils;

public interface IList<T> {

    void add(T elem);
    void remove(T elem);
    int size();
    String toString();
}
