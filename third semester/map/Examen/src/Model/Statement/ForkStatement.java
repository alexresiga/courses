package Model.Statement;

import Model.ProgramState;
import Model.Utils.MyStack;

public class ForkStatement implements IStatement {

    private IStatement statement;
    private static int threadID = 1;

    public ForkStatement(IStatement statement){
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        return new ProgramState(new MyStack<>(), programState.getOutputList(), programState.getFileTable(), programState.getHeap(), programState.getSymbolTableStack(), programState.getProcTable(), this.statement, ++threadID);
    }

    @Override
    public String toString(){
        return "fork(" + this.statement.toString() + ")";
    }
}
