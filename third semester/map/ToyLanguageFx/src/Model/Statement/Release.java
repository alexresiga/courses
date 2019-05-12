package Model.Statement;

import Model.ProgramState;
import javafx.util.Pair;

import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Release implements IStatement {

    private String var;
    private static Lock lock = new ReentrantLock();

    public Release(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        lock.lock();
        Integer foundIndex = programState.getSymbolTable().get(this.var);
        if (foundIndex == null)
            throw new Exception("it is not found");

        Pair<Integer, List<Integer>> entry = programState.getSemaphoreTable().get(foundIndex);
        if (entry == null)
            throw new Exception("it's not found");
        Integer max = entry.getKey();
        List<Integer> list = entry.getValue();
        list.remove(programState.getThreadId());
        programState.getSemaphoreTable().put(foundIndex, new Pair<>(max, list));
        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("release(%s)", this.var);
    }
}
