package model.utils;

import java.util.ArrayList;

public class MyList<T> implements IList<T> {

    private ArrayList<T> list;

    public MyList() {
        this.list = new ArrayList<>();
    }

    @Override
    public void add(T elem) {
        this.list.add(elem);
    }

    @Override
    public int size() {
        return list.size();
    }

    @Override
    public void remove(T elem) {
        list.remove(elem);
    }

    public String toString() {
        StringBuilder result = new StringBuilder();
        result.append("\nOUTPUT:\n");
        for(T elem: this.list)
            result.append(elem.toString()).append("\n");
        return result.toString();
    }
}
