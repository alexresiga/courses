package model.utils;

public interface IStack<T> {
    void push(T elem);
    T pop();
    boolean isEmpty();
    String toString();
}
