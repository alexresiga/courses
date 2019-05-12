package Model.Expression;

import Model.Utils.IDictionary;
import Exception.DivisionByZeroError;
import Exception.InvalidExpressionError;
import Model.Utils.IHeap;

public class ArithExp extends Expression {
    private char operator;
    private Expression exp1;
    private Expression exp2;


    public ArithExp(char operator, Expression exp1, Expression exp2){
        this.operator = operator;
        this.exp1 = exp1;
        this.exp2 = exp2;
    }

    @Override
    public Integer evaluate(IDictionary<String, Integer> symbolTable, IHeap heap){
        Integer left = this.exp1.evaluate(symbolTable, heap);
        Integer right = this.exp2.evaluate(symbolTable, heap);
        switch (this.operator){
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '/':
                if (right == 0){
                    throw new DivisionByZeroError("division by 0");
                }
                return left/right;
            case '*':
                return left*right;
            default:
                throw new InvalidExpressionError("invalid expression");
        }
    }

    @Override
    public String toString(){
        return "" + exp1.toString() + operator + exp2.toString();
    }
}
