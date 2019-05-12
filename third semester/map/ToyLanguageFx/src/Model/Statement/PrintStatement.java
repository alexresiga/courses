package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;

public class PrintStatement implements IStatement{
    private Expression expression;

    public PrintStatement(Expression expression){

        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        programState.addOutput(expression.evaluate(programState.getSymbolTable(), programState.getHeap()));
        return null;
    }

    @Override
    public String toString(){
        return "print(" + expression + ")";
    }
}
