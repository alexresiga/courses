package Model.Statement;

import Model.Expression.ConstExp;
import Model.ProgramState;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class CountDown implements IStatement {

    private String var;
    private static Lock lock = new ReentrantLock();

    public CountDown(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        lock.lock();
        Integer foundIndex = programState.getSymbolTable().get(this.var);
        if (foundIndex == null)
            throw new Exception("not found");

        Integer entry = programState.getLatchTable().get(foundIndex);
        if (entry == null)
            throw new Exception("not found");

        if (entry > 0) {
            programState.getLatchTable().put(foundIndex, --entry);
            programState.getExeStack().push(new PrintStatement(new ConstExp(programState.getThreadId())));
        }
        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("CountDownLatch(%s)", this.var);
    }
}
