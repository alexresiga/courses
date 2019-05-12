package Model.Expression;

import Model.Utils.IDictionary;
import Model.Utils.IHeap;

public class VarExp extends Expression {
    private String name;

    public VarExp(String name){
        this.name = name;
    }

    @Override
    public Integer evaluate(IDictionary<String, Integer> symbolTable, IHeap heap) {
        return symbolTable.get(name);
    }

    @Override
    public String toString(){
        return name;
    }

}
