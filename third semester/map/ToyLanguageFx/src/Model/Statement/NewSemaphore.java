package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewSemaphore implements IStatement {

    private String var;
    private Expression expression;
    private static Lock lock = new ReentrantLock();

    public NewSemaphore(String var, Expression expression) {
        this.var = var;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState programState) {
        lock.lock();
        int number = this.expression.evaluate(programState.getSymbolTable(), programState.getHeap());
        int freeAddress = programState.getSemaphoreAddress();
        programState.getSemaphoreTable().put(freeAddress, new Pair<>(number, new ArrayList<>()));
        programState.getSymbolTable().put(this.var, freeAddress);
        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("NewSemaphore(%s, %s)", this.var, this.expression.toString());
    }
}
