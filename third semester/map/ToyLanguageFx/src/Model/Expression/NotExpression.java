package Model.Expression;

import Model.Utils.IDictionary;
import Model.Utils.IHeap;

public class NotExpression extends Expression {
    private Expression expression;

    public NotExpression(Expression expression) {
        this.expression = expression;
    }

    @Override
    public Integer evaluate(IDictionary<String, Integer> symbolTable, IHeap heapTable) {
        return (expression.evaluate(symbolTable, heapTable) == 0) ? 1 : 0;

    }

    @Override
    public String toString() {
        return "!" + expression.toString();
    }
}
