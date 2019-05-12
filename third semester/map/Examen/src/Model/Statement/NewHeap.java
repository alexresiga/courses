package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Model.Utils.IHeap;

public class NewHeap implements IStatement {
    private String varName;
    private Expression exp;

    public NewHeap(String varName, Expression exp){
        this.varName = varName;
        this.exp = exp;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        Integer value = this.exp.evaluate(programState.getSymbolTable(), programState.getHeap());
        IHeap heap = programState.getHeap();
        heap.add(value);
        Integer address = heap.getAddress(value);
        if (programState.getSymbolTable().containsKey(this.varName)){
            programState.getSymbolTable().replace(this.varName, address);
        }
        else
            programState.getSymbolTable().put(this.varName, address);
        return null;
    }

    @Override
    public String toString(){
        return "NewHeap(" + this.varName + "," + this.exp.toString() + ")";
    }

}
