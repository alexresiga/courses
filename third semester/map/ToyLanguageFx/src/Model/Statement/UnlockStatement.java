package Model.Statement;

import Model.ProgramState;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class UnlockStatement implements IStatement {

    private String var;
    private static Lock lock = new ReentrantLock();

    public UnlockStatement(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        lock.lock();
        Integer foundIndex = programState.getSymbolTable().get(this.var);
        if (foundIndex == null)
            throw new Exception("is not there");

        Integer value = programState.getLockTable().get(foundIndex);
        if (value == null)
            throw new Exception("not");

        if (value.equals(programState.getThreadId()))
            programState.getLockTable().put(foundIndex, -1);

        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("unlock(%s)", this.var);
    }
}