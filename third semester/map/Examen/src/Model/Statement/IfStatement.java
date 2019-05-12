package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Model.Utils.IStack;

public class IfStatement implements IStatement{

    private Expression expression;
    private IStatement thenStatement;
    private IStatement elseStatement;

    public IfStatement(Expression expression, IStatement thenStatement, IStatement elseStatement){
        this.expression = expression;
        this.thenStatement = thenStatement;
        this.elseStatement = elseStatement;
    }

    @Override
    public ProgramState execute(ProgramState programState) {
        IStack<IStatement> stack = programState.getExeStack();
        int value = expression.evaluate(programState.getSymbolTable(), programState.getHeap());
        if (value != 0) stack.push(thenStatement);
        else stack.push(elseStatement);
        return null;
    }

    @Override
    public String toString() {
        return "if(" + expression.toString() + ")then(" + thenStatement.toString() +
                ")else(" + elseStatement.toString() + ")";
    }

}
