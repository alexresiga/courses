package Model.Statement;

import Model.ProgramState;
import javafx.util.Pair;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Await implements IStatement {

    private String var;
    private static Lock lock = new ReentrantLock();


    public Await(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        lock.lock();
        Integer foundIndex = programState.getSymbolTable().get(this.var);

        if (foundIndex == null) {
            throw new Exception("does not exist in symTable");
        }

        Pair<Integer, List<Integer>> entry = programState.getBarrierTable().get(foundIndex);

        if (entry == null)
            throw new Exception("not existing entry");
        Integer n1 = entry.getKey();
        List<Integer> list = entry.getValue();
        if (list.size() < n1)
            if (list.contains(programState.getThreadId()))
                programState.getExeStack().push(this);
            else {
                list.add(programState.getThreadId());
                programState.getBarrierTable().put(foundIndex, new Pair<>(n1, list));
                programState.getExeStack().push(this);
            }

        lock.unlock();
        return null;
    }

    @Override
    public String toString() {
        return String.format("BarrierAwait(%s)", this.var);
    }
}
