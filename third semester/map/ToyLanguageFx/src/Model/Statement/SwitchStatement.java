package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Model.Utils.IDictionary;
import Model.Utils.IHeap;
import Model.Utils.IStack;

public class SwitchStatement implements IStatement {
    private Expression condition;
    private Expression case1;
    private IStatement statement1;
    private Expression case2;
    private IStatement statement2;
    private IStatement defaultStatement;

    public SwitchStatement(Expression condition, Expression case1, IStatement statement1, Expression case2, IStatement statement2, IStatement defaultStatement){
        this.condition = condition;
        this.case1 = case1;
        this.statement1 = statement1;
        this.case2 = case2;
        this.statement2 = statement2;
        this.defaultStatement = defaultStatement;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        IStack<IStatement> exeStack = programState.getExeStack();
        IDictionary<String, Integer> symbolTable = programState.getSymbolTable();
        IHeap heap = programState.getHeap();

        Integer value = condition.evaluate(symbolTable, heap);
        Integer value1 = case1.evaluate(symbolTable, heap);
        Integer value2 = case2.evaluate(symbolTable, heap);
        IStatement newStatement;
        if (value.equals(value1))
            newStatement = statement1;
        else if (value.equals(value2))
            newStatement = statement2;
        else
            newStatement = defaultStatement;
        exeStack.push(newStatement);
        return null;
    }

    @Override
    public String toString(){
        return "switch(" + condition.toString() +")\n(case" + case1.toString() + ")" + statement1.toString() +
                ")\n(case" + case2.toString() + ")" + statement2.toString() + ")\n(default" + defaultStatement.toString()
                + ")";
    }
}
