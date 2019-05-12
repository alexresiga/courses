package Model.Statement;

import Model.ProgramState;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewLock implements IStatement {

    private String var;

    private static Lock lock = new ReentrantLock();

    public NewLock(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        lock.lock();
        int freeAddress = programState.getLockAddress();
        programState.getSymbolTable().put(this.var, freeAddress);
        programState.getLockTable().put(freeAddress, -1);

        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("NewLock(%s)", this.var);
    }
}
