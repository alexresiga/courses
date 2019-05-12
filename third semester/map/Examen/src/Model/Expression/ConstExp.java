package Model.Expression;


import Model.Utils.IDictionary;
import Model.Utils.IHeap;

public class ConstExp extends Expression{
    private Integer value;

    public ConstExp(Integer value){
        this.value = value;
    }

    @Override
    public Integer evaluate(IDictionary<String, Integer> symbolTable, IHeap heap){
        return this.value;
    }

    @Override
    public String toString(){
        return value.toString();
    }
}
