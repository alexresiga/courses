package model.Expression;

import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.utils.IDictionary;
import model.utils.IHeap;

public interface Expression {
    int evaluate(IDictionary<String, Integer> st, IHeap<Integer> heap) throws UnknownVariableException, MyBooleanException;
    String toString();
}
