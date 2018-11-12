package model.Expression;

import model.utils.MyDictionary;

public interface Expression {
    int evaluate(MyDictionary<String, Integer> st);
    String toString();
}
