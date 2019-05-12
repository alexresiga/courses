package Model.Expression;

import Model.Utils.IDictionary;
import Model.Utils.IHeap;

public abstract class Expression{
    abstract public Integer evaluate(IDictionary<String, Integer> symbolTable, IHeap heap);
    abstract public String toString();
}
