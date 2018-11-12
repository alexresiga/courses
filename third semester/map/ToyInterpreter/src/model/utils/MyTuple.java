package model.utils;

public class MyTuple<T1, T2> implements ITuple<T1, T2> {

    private T1 first;
    private T2 second;

    public MyTuple(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public T1 getFirst() {
        return this.first;
    }

    @Override
    public T2 getSecond() {
        return this.second;
    }

    @Override
    public String toString() {
        return this.first.toString();
    }

}
