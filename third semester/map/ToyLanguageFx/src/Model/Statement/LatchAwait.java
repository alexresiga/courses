package Model.Statement;

import Model.ProgramState;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LatchAwait implements IStatement {

    private String var;
    private static Lock lock = new ReentrantLock();


    public LatchAwait(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        lock.lock();
        Integer fIndex = programState.getSymbolTable().get(this.var);
        if (fIndex == null)
            throw new Exception("is not found");

        Integer entry = programState.getLatchTable().get(fIndex);
        if (entry == null)
            throw new Exception("is not found");

        if (entry > 0) {
            programState.getExeStack().push(this);
        }
        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("LatchAwait(%s)", this.var);
    }
}
