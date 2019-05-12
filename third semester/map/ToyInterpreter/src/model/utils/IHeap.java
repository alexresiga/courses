package model.utils;

import java.util.HashMap;
import java.util.Map;

public interface IHeap<T> {
    int allocate(T value);
    T readAddress(int address);
    void writeAddress(int address, T value);
    T deallocate(int address);
    void setMap(Map<Integer, T> map);
    HashMap<Integer, T> toMap();
    String toString();
}
