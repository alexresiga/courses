package model.Expression;

import model.utils.MyDictionary;

public class ConstExp implements Expression {

    private int value;

    public ConstExp(int value) {
        this.value = value;
    }

    public int evaluate(MyDictionary<String, Integer> st) {
        return this.value;
    }

    @Override
    public String toString() {
        return Integer.toString(this.value);
    }
}
