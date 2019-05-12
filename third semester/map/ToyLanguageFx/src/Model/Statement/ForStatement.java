package Model.Statement;

import Model.Expression.BooleanExp;
import Model.Expression.Expression;
import Model.Expression.VarExp;
import Model.ProgramState;
import Model.Utils.IStack;

public class ForStatement implements IStatement {
    private String var;
    private Expression expression1;
    private Expression expression2;
    private Expression expression3;
    private IStatement statement;

    public ForStatement(String var, Expression exp1, Expression exp2, Expression exp3, IStatement statement){
        this.var = var;
        this.expression1 = exp1;
        this.expression2 = exp2;
        this.expression3 = exp3;
        this.statement = statement;
    }

    public String toString(){
        return "for(" + var + "=" + expression1.toString() + ";" + var + "<" + expression2.toString() + ";"
                + var + "=" + expression3.toString() + ")" + statement.toString();
    }
    public ProgramState execute(ProgramState programState){
        IStack<IStatement> stack = programState.getExeStack();
        IStatement newStatement = new CompoundStatement(
                new AssignStatement(var, expression1),
                new WhileStatement(
                        new BooleanExp("<", new VarExp(var), expression2),
                        new CompoundStatement(
                                statement,
                                new AssignStatement(var, expression3)
                        )
                )
        );
        stack.push(newStatement);
        return null;
    }
}
