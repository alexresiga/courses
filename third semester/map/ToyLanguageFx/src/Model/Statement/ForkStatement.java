package Model.Statement;

import Model.ProgramState;
import Model.Utils.IStack;
import Model.Utils.MyStack;

public class ForkStatement implements IStatement {

    private IStatement statement;
    private static int threadID = 1;

    public ForkStatement(IStatement statement){
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        return new ProgramState(
                new MyStack<>(), programState.getOutputList(), programState.getSymbolTable().cloneDictionary(),
                programState.getFileTable(), programState.getHeap(), programState.getBarrierTable(), programState.getLatchTable(), programState.getSemaphoreTable(), programState.getLockTable(), this.statement, ++threadID);
    }

    @Override
    public String toString(){
        return "fork(" + this.statement.toString() + ")";
    }
}
