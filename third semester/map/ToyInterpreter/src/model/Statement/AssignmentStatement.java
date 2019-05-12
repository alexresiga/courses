package model.Statement;

import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.Expression.Expression;
import model.ProgramState;
import model.utils.IDictionary;
import model.utils.IStack;
import model.utils.MyDictionary;
import model.utils.MyStack;

public class AssignmentStatement implements IStatement {

    private String name;
    private Expression expression;

    public AssignmentStatement(String name, Expression expression) {
        this.name = name;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UnknownVariableException, MyBooleanException {

        IDictionary<String, Integer> symTable = state.getSymTable();
        int value = expression.evaluate(symTable, state.getHeap());
        symTable.put(name, value);
        return state;
    }

    @Override
    public String toString() {
        return this.name + " = " + this.expression.toString();
    }
}
