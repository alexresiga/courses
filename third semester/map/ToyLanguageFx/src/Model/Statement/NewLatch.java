package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewLatch implements IStatement {

    private String var;
    private Expression expression;
    private static Lock lock = new ReentrantLock();

    public NewLatch(String var, Expression expression) {
        this.expression = expression;
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        lock.lock();
        int number = this.expression.evaluate(programState.getSymbolTable(), programState.getHeap());
        int freeAddress = programState.getLatchAddress();
        programState.getSymbolTable().put(this.var, freeAddress);
        programState.getLatchTable().put(freeAddress, number);

        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("NewLatch(%s, %s)", this.var, this.expression.toString());
    }
}
