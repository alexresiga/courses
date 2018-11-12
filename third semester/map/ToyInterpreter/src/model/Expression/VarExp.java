package model.Expression;

import model.utils.MyDictionary;

public class VarExp implements Expression {

    private String name;

    public VarExp(String name) {
        this.name = name;
    }

    public int evaluate(MyDictionary<String, Integer> st) {
        if (st.contains(this.name)) {
            return st.get(this.name);
        }
        else {
            throw new RuntimeException("non existing variable");
        }
    }

    @Override
    public String toString() {
        return this.name;
    }
}
