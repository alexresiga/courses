package model.Expression;

import model.utils.IDictionary;
import model.utils.IHeap;

public class ConstExp implements Expression {

    private int value;

    public ConstExp(int value) {
        this.value = value;
    }

    public int evaluate(IDictionary<String, Integer> st, IHeap<Integer> heap) {
        return this.value;
    }

    @Override
    public String toString() {
        return Integer.toString(this.value);
    }
}
