package Model.Statement;

import Model.ProgramState;
import Model.Utils.IStack;

public class CompoundStatement implements IStatement {
    private IStatement statement1;
    private IStatement statement2;

    public CompoundStatement(IStatement statement1, IStatement statement2){
        this.statement1 = statement1;
        this.statement2 = statement2;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        IStack<IStatement> ExeStack = programState.getExeStack();
        ExeStack.push(this.statement2);
        ExeStack.push(this.statement1);
        return null;
    }

    @Override
    public String toString() {
        return  statement1.toString() + "; " + statement2.toString();
    }
}
