package model.Statement;

import exceptions.FileAlreadyOpenedException;
import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.Expression.Expression;
import model.ProgramState;

public class WhileStatement implements IStatement {

    private Expression expression;
    private IStatement statement;

    public WhileStatement(Expression expression, IStatement statement) {
        this.expression = expression;
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws FileAlreadyOpenedException, UnknownVariableException, MyBooleanException {
        if (this.expression.evaluate(state.getSymTable(), state.getHeap()) != 0) {
            state.getExeStack().push(this);
            state.getExeStack().push(this.statement);
        }

        return state;
    }

    @Override
    public String toString() {
        return String.format("while(%s) do %s", this.expression.toString(), this.statement.toString());
    }
}
