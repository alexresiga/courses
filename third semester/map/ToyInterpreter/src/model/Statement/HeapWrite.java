package model.Statement;

import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.Expression.Expression;
import model.ProgramState;


public class HeapWrite implements IStatement {

    private String var;
    private Expression expression;

    public HeapWrite(String var, Expression expression) {
        this.expression = expression;
        this.var = var;
    }


    @Override
    public ProgramState execute(ProgramState state) throws UnknownVariableException, MyBooleanException {
        Integer address = state.getSymTable().get(this.var);
        int value = this.expression.evaluate(state.getSymTable(), state.getHeap());
        if (address == null) {
            throw new NullPointerException("Invalid memory address at HeapWrite: " + this.toString());
        }
        state.getHeap().writeAddress(address, value);
        return state;
    }

    @Override
    public String toString() {
        return String.format("WriteHeap(%s, %s)", this.var, this.expression.toString());
    }
}
