package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Exception.HeapException;

public class WriteHeap implements IStatement {
    private String name;
    private Expression exp;

    public WriteHeap(String name, Expression exp){
        this.name = name;
        this.exp = exp;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        if(programState.getHeap().exists(programState.getSymbolTable().get(this.name)))
            programState.getHeap().replace(programState.getSymbolTable().get(this.name),
                    this.exp.evaluate(programState.getSymbolTable(), programState.getHeap()));
        else
            throw new HeapException("Invalid heap address");
        return null;
    }

    @Override
    public String toString(){
        return "WriteHeap(" + this.name + "," + this.exp.toString() + ")";
    }
}
