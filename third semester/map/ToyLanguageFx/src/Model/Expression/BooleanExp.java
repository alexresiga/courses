package Model.Expression;

import Model.Utils.IDictionary;
import Model.Utils.IHeap;
import Exception.*;

public class BooleanExp extends Expression {

    private String operator;
    private Expression exp1;
    private Expression exp2;

    public BooleanExp(String operator, Expression exp1, Expression exp2){
        this.operator = operator;
        this.exp1 = exp1;
        this.exp2 = exp2;
    }

    @Override
    public String toString(){return  "" + exp1.toString() + operator + exp2.toString();}

    @Override
    public Integer evaluate(IDictionary<String, Integer> symbolTable, IHeap heap) {
        Integer first = this.exp1.evaluate(symbolTable, heap);
        Integer second = this.exp2.evaluate(symbolTable, heap);

        switch (this.operator) {
            case ">":
                if (first > second)
                    return 1;
                else
                    return 0;
            case ">=":
                if (first >= second)
                    return 1;
                else
                    return 0;
            case "<":
                if (first < second)
                    return 1;
                else
                    return 0;
            case "<=":
                if (first <= second)
                    return 1;
                else
                    return 0;
            case "==":
                if (first.equals(second))
                    return 1;
                else
                    return 0;
            case "!=":
                if (!first.equals(second))
                    return 1;
                else
                    return 0;
            default:
                throw new InvalidExpressionError("invalid expression");
        }
    }
}

