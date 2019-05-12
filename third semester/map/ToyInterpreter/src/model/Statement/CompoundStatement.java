package model.Statement;

import model.ProgramState;
import model.utils.IStack;
import model.utils.MyStack;

public class CompoundStatement implements IStatement {

    private IStatement first, second;

    public CompoundStatement(IStatement first, IStatement second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public ProgramState execute(ProgramState state) {
        IStack<IStatement> stack = state.getExeStack();
        stack.push(this.second);
        stack.push(this.first);

        return state;
    }

    @Override
    public String toString() {
        return String.format("%s; %s", this.first.toString(), this.second.toString());
    }
}
