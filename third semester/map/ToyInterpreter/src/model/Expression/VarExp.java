package model.Expression;

import model.utils.IDictionary;
import model.utils.IHeap;

public class VarExp implements Expression {

    private String name;

    public VarExp(String name) {
        this.name = name;
    }

    public int evaluate(IDictionary<String, Integer> st, IHeap<Integer> heap) {
        if (st.contains(this.name)) {
            return st.get(this.name);
        }
        else {
            throw new RuntimeException("RuntimeException at " + this.toString() + " non existing variable");
        }
    }

    @Override
    public String toString() {
        return this.name;
    }
}
