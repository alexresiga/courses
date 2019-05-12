package model.Expression;

import exceptions.DivisionByZero;
import exceptions.MyArithmeticException;
import exceptions.UnknownVariableException;
import model.utils.IDictionary;
import model.utils.IHeap;

public class ArithExp implements Expression {
    private Expression op1, op2;
    private char operator;

    public ArithExp(char operator,Expression op1, Expression op2) {
        this.op1 = op1;
        this.op2 = op2;
        this.operator = operator;
    }

    public int evaluate(IDictionary<String, Integer> st, IHeap<Integer> heap) throws UnknownVariableException, DivisionByZero, MyArithmeticException {
        int first = this.op1.evaluate(st, heap);
        int second = this.op2.evaluate(st, heap);

        switch (this.operator) {
            case '+':
                return first + second;

            case '-':
                return first - second;

            case '*':
                return first * second;

            case '/':
                if (second == 0) {
                    throw new DivisionByZero("division by zero.");
                }
                return first/second;

            default:
                throw new MyArithmeticException("invalid arithmetic expression");
        }
    }

    @Override
    public String toString() {
        return String.format("%s%s%s", this.op1.toString(), this.operator, this.op2.toString());
    }
}
