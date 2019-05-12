package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Model.Utils.IDictionary;

public class AssignStatement implements IStatement {
    private String name;
    private Expression expr;

    public AssignStatement(String name, Expression expr){
        this.name = name;
        this.expr = expr;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        IDictionary<String, Integer> symbolTable = programState.getSymbolTable();
        int val = expr.evaluate(symbolTable, programState.getHeap());
        if (symbolTable.containsKey(name)) {
            symbolTable.replace(name, val);
        }
        else
            symbolTable.put(name, val);
        return null;
    }

    @Override
    public String toString(){
        return name + " = " + expr.toString();
    }
}
