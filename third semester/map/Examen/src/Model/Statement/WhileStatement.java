package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Model.Utils.IStack;

public class WhileStatement implements IStatement {


    private Expression expression;
    private IStatement statement;

    public WhileStatement(Expression expression, IStatement statement){
        this.expression = expression;
        this.statement = statement;
    }

    @Override
    public String toString() {
        return "while(" + expression.toString() + ")" + statement.toString();
    }

    @Override
    public ProgramState execute(ProgramState programState) {
        IStack<IStatement> stack = programState.getExeStack();
        int value = expression.evaluate(programState.getSymbolTable(), programState.getHeap());
        if (value != 0) {
            stack.push(this);
            stack.push(statement);
        }
        return null;
    }

}

