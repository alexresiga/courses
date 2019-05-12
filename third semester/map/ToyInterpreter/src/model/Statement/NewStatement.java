package model.Statement;

import exceptions.FileAlreadyOpenedException;
import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.Expression.Expression;
import model.ProgramState;


public class NewStatement implements IStatement {

    private String var;
    private Expression expression;

    public NewStatement(String var, Expression expression) {
        this.expression = expression;
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UnknownVariableException, FileAlreadyOpenedException, MyBooleanException {
        int res = this.expression.evaluate(state.getSymTable(), state.getHeap());
        int loc = state.getHeap().allocate(res);
        state.getSymTable().put(this.var, loc);

        return state;
    }

    @Override
    public String toString() {
        return String.format("new(%s, %s)", this.var, this.expression.toString());
    }
}
