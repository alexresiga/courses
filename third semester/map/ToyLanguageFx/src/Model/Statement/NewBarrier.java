package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewBarrier implements IStatement {

    private String var;
    private Expression expression;
    private static Lock lock = new ReentrantLock();

    public NewBarrier(String var, Expression expression) {
        this.var = var;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState programState) {
        lock.lock();
        int number = this.expression.evaluate(programState.getSymbolTable(), programState.getHeap());
        int freeAddress = programState.getAddress();
        programState.getBarrierTable().put(freeAddress, new Pair<>(number, new ArrayList<>()));
        programState.getSymbolTable().put(this.var, freeAddress);
        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("NewBarrier(%s, %s)", this.var, this.expression.toString());
    }
}
