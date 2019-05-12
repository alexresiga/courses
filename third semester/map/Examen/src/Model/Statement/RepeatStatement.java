package Model.Statement;

import Model.Expression.Expression;
import Model.Expression.NotExpression;
import Model.ProgramState;

public class RepeatStatement implements IStatement{
    private IStatement statement;
    private Expression expression;

    public RepeatStatement(IStatement statement, Expression expression){
        this.statement = statement;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        IStatement newStatement = new CompoundStatement(statement, new WhileStatement(new NotExpression(expression), statement));
        programState.getExeStack().push(newStatement);
        return null;
    }

    @Override
    public String toString(){
        return "repeat{ \n" + statement.toString() + "\n}until" + expression.toString();
    }
}
