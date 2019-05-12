package model.Statement;

import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.Expression.Expression;
import model.ProgramState;

public class IfStatement implements IStatement {

    private Expression expression;
    private IStatement thenS, elseS;

    public IfStatement(Expression expression, IStatement thenS, IStatement elseS) {
        this.expression = expression;
        this.elseS = elseS;
        this.thenS = thenS;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UnknownVariableException, MyBooleanException {
        if (expression.evaluate(state.getSymTable(), state.getHeap()) == 0) {

            state.getExeStack().push(elseS);
        } else {
            state.getExeStack().push(thenS);
        }
        return state;
    }

    @Override
    public String toString() {
        return String.format("if %s then %s else %s", expression.toString(), thenS.toString(), elseS.toString());
    }
}
