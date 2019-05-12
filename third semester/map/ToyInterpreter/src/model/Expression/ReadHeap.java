package model.Expression;

import exceptions.UnknownVariableException;
import model.utils.IDictionary;
import model.utils.IHeap;

public class ReadHeap implements Expression {

    private String var;

    public ReadHeap(String var) {
        this.var = var;
    }

    @Override
    public int evaluate(IDictionary<String, Integer> st, IHeap<Integer> heap) throws UnknownVariableException{

        Integer address = st.get(this.var);
        if (address == null) {
            throw new UnknownVariableException("Unknown Variable Exception(ReadHeap) at: " + this.toString());
        }
        Integer heap_value = heap.readAddress(address);
        if (heap_value == null) {
            throw new NullPointerException("There is no such memory address\nError at ReadHeap: " + this.toString());
        }
        return heap_value;
    }

    @Override
    public String toString() {
        return String.format("ReadHeap(%s)", this.var);
    }
}
