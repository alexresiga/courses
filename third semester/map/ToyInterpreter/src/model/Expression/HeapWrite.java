package model.Expression;

import exceptions.UnknownVariableException;
import model.utils.IDictionary;
import model.utils.IHeap;

public class HeapWrite implements Expression {

    private String var;
    private Expression expression;

    public HeapWrite(String var, Expression expression) {
        this.expression = expression;
        this.var = var;
    }


    @Override
    public int evaluate(IDictionary<String, Integer> st, IHeap<Integer> heap) throws UnknownVariableException{
        Integer address = st.get(this.var);
        int value = this.expression.evaluate(st, heap);
        if (address == null) {
            throw new NullPointerException("Invalid memory address at HeapWrite: " + this.toString());
        }
        heap.writeAddress(address, value);
        return address;
    }
}
