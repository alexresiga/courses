package Model.Expression;


import Exception.HeapException;
import Model.Utils.IDictionary;
import Model.Utils.IHeap;

public class ReadHeap extends Expression {
    private String name;

    public ReadHeap(String name){ this.name = name; }

    @Override
    public Integer evaluate(IDictionary<String, Integer> symbolTable, IHeap heap) {
        if (!symbolTable.containsKey(name))
            throw new HeapException("Variable does not exist");
        Integer address = symbolTable.get(name);
        if(!heap.exists(address))
            throw new HeapException("Variable not in the heap");
        return heap.get(address);
    }

    @Override
    public String toString(){
        return "readHeap(" + this.name + ")";
    }
}
