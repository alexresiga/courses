package model.Statement;

import model.Expression.Expression;
import model.ProgramState;
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
    public ProgramState execute(ProgramState state) {
        MyStack<IStatement> stack = state.getExeStack();

        MyDictionary<String, Integer> symTable = state.getSymTable();
        int value = expression.evaluate(symTable);
        symTable.put(name, value);
        return state;
    }

    @Override
    public String toString() {
        return this.name + " = " + this.expression.toString();
    }
}
