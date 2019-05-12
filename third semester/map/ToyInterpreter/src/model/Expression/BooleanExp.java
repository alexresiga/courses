package model.Expression;

import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.utils.IDictionary;
import model.utils.IHeap;

public class BooleanExp implements Expression {

    private Expression op1, op2;
    private String operator;

    public BooleanExp(Expression expression1, String operator, Expression expression2) {
        this.op1 = expression1;
        this.op2 = expression2;
        this.operator = operator;
    }

    @Override
    public int evaluate(IDictionary<String, Integer> st, IHeap<Integer> heap) throws UnknownVariableException, MyBooleanException {
        int first = this.op1.evaluate(st, heap);
        int second = this.op2.evaluate(st, heap);

        switch (operator){
            default:
                throw new MyBooleanException("Invalid boolean expression at:" + this.toString());
            case "<":
                return (first < second) ? 1:0;
            case "<=":
                return (first <= second) ? 1:0;
            case "==":
                return (first == second) ? 1:0;
            case ">=":
                return (first >= second) ? 1:0;
            case ">":
                return (first > second) ? 1:0;
        }
    }

    @Override
    public String toString() {
        return String.format("%s %s %s", this.op1.toString(), this.operator, this.op2.toString());
    }
}
