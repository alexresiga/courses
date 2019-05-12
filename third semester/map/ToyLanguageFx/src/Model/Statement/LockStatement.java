package Model.Statement;

import Model.ProgramState;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockStatement implements IStatement {

    private String var;
    private static Lock lock = new ReentrantLock();

    public LockStatement(String var){
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        lock.lock();
        Integer foundIndex = programState.getSymbolTable().get(this.var);
        if (foundIndex == null)
            throw new Exception("not there");

        Integer value = programState.getLockTable().get(foundIndex);
        if (value == null)
            throw new Exception("not");

        if (value == -1)
            programState.getLockTable().put(foundIndex, programState.getThreadId());
        else
            programState.getExeStack().push(this);
        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("Lock(%s)", this.var);
    }
}
