package model.utils;

import java.util.HashMap;
import java.util.Map;

public class MyHeap<T> implements IHeap<T> {

    private int memory;
    private HashMap<Integer, T> values;

    public MyHeap(HashMap<Integer, T> values) {
        this.values = values;
    }

    @Override
    public int allocate(T value) {
        ++ this.memory;
        this.values.put(this.memory, value);
        return this.memory;
    }

    @Override
    public T readAddress(int address) {
        return this.values.get(address);
    }

    @Override
    public void writeAddress(int address, T value) {
        this.values.put(address, value);
    }

    @Override
    public T deallocate(int address) {
        return this.values.remove(address);
    }

    @Override
    public HashMap<Integer, T> toMap() {
        return this.values;
    }

    @Override
    public void setMap(Map<Integer, T> map) {
        this.values = (HashMap<Integer, T>)map;

    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        for (Integer key: this.values.keySet())
            result.append(key.toString()).append("->").append(this.values.get(key).toString()).append("\n");

        return result.toString();
    }
}
