package model.Statement;

import model.Expression.Expression;
import model.ProgramState;
import model.utils.MyList;

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
    public ProgramState execute(ProgramState state) {

        MyList<Integer> out = state.getOutput();
        out.add(expression.evaluate(state.getSymTable()));
        return state;
    }
}
