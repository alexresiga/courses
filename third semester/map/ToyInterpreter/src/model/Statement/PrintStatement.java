package model.Statement;

import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.Expression.Expression;
import model.ProgramState;
import model.utils.IList;

public class PrintStatement implements IStatement {

    private Expression expression;

    public PrintStatement(Expression expression) {
        this.expression = expression;
    }

    @Override
    public String toString() {
        return String.format("print(%s)", this.expression.toString());
    }

    @Override
    public ProgramState execute(ProgramState state) throws UnknownVariableException, MyBooleanException {

        IList<Integer> out = state.getOutput();
        out.add(expression.evaluate(state.getSymTable(), state.getHeap()));
        return state;
    }
}
