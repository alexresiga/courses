package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Model.Utils.IStack;

public class ConditionalStatement implements IStatement{
    private String var;
    private Expression condition;
    private Expression trueCondition;
    private Expression falseCondition;

    public ConditionalStatement(String var, Expression cond, Expression trueCond, Expression falseCond){
        this.var = var;
        this.condition = cond;
        this.trueCondition = trueCond;
        this.falseCondition = falseCond;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        IStack<IStatement> exeStack = programState.getExeStack();
        IStatement newStatement = new IfStatement(condition, new AssignStatement(var, trueCondition), new AssignStatement(var, falseCondition));
        exeStack.push(newStatement);
        return null;
    }

    @Override
    public String toString(){
        return var + " = " + condition.toString() + "?" + trueCondition.toString() + ": " + falseCondition.toString();

    }
}
