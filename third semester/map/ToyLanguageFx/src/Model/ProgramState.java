package Model;

import Model.Statement.IStatement;
import Model.Utils.*;
import javafx.util.Pair;

import java.io.BufferedReader;
import java.util.List;

public class ProgramState {
    private IStack<IStatement> exeStack;
    private IList<Integer> outputList;
    private IDictionary<String, Integer> symbolTable;
    private IDictionary<Integer, ITuple<String, BufferedReader>> fileTable;
    private IHeap heap;
    private IDictionary<Integer, Pair<Integer, List<Integer>>> barrierTable;
    private Address address = new Address();
    private IDictionary<Integer, Integer> latchTable;
    private IDictionary<Integer, Pair<Integer, List<Integer>>> semaphoreTable;
    private IDictionary<Integer, Integer> lockTable;
    private Address semaphoreAddress = new Address();
    private Address latchAddress = new Address();
    private Address lockAddress = new Address();
    private Integer id = 1;

    public ProgramState(IStatement statement) {
        exeStack = new MyStack<>();
        symbolTable = new MyDictionary<>();
        outputList = new MyList<>();
        fileTable = new MyDictionary<>();
        heap = new MyHeap();
        barrierTable = new MyBarrier();
        latchTable = new MyLatch();
        semaphoreTable = new MySemaphore();
        lockTable = new MyLock();
        exeStack.push(statement);

    }


    public ProgramState(IStack<IStatement> exeStack,
                        IList<Integer> output,
                        IDictionary<String, Integer> symbolTable,
                        IDictionary<Integer, ITuple<String, BufferedReader>> fileTable,
                        IHeap heap,
                        IDictionary<Integer, Pair<Integer, List<Integer>>> barrierTable,
                        IDictionary<Integer, Integer> latchTable,
                        IDictionary<Integer, Pair<Integer, List<Integer>>> semaphoreTable,
                        IDictionary<Integer, Integer> lockTable,
                        IStatement st,
                        Integer id) {
        this.exeStack = exeStack;
        this.outputList = output;
        this.symbolTable = symbolTable;
        this.fileTable = fileTable;
        this.heap = heap;
        this.barrierTable = barrierTable;
        this.latchTable = latchTable;
        this.semaphoreTable = semaphoreTable;
        this.lockTable = lockTable;
        this.id = id;
        exeStack.push(st);
    }

    public IStack<IStatement> getExeStack() {
        return this.exeStack;
    }

    public IList<Integer> getOutputList() {
        return this.outputList;
    }

    public IDictionary<String, Integer> getSymbolTable() {
        return this.symbolTable;
    }

    public IDictionary<Integer, ITuple<String, BufferedReader>> getFileTable() {
        return this.fileTable;
    }

    public void addOutput(Integer number) {
        this.outputList.add(number);
    }

    public IHeap getHeap() {
        return this.heap;
    }

    public Integer getThreadId() {
        return this.id;
    }

    public IDictionary<Integer, Pair<Integer, List<Integer>>> getBarrierTable() {
        return barrierTable;
    }

    public int getAddress() {
        return address.getFreeAddress();
    }

    public int getLatchAddress() {
        return latchAddress.getFreeAddress();
    }

    public IDictionary<Integer, Integer> getLatchTable() {
        return latchTable;
    }

    public int getSemaphoreAddress() {
        return semaphoreAddress.getFreeAddress();
    }

    public IDictionary<Integer, Pair<Integer, List<Integer>>> getSemaphoreTable() {
        return semaphoreTable;
    }

    public int getLockAddress() {
        return lockAddress.getFreeAddress();
    }

    public IDictionary<Integer, Integer> getLockTable() {
        return lockTable;
    }

    public boolean isNotCompleted() {
        return !exeStack.isEmpty();
    }

    public ProgramState oneStep() throws Exception {
        if (exeStack.isEmpty())
            return null;
        IStatement crtStmt = exeStack.pop();
        return crtStmt.execute(this);
    }

    public String toString() {
       return "\n" + "Thread number: " + id.toString() + this.exeStack.toString() + "\nSYMBOL TABLE:" + this.symbolTable.toString();
    }

    public String toString2() {
        return "\n" + this.outputList.toString() + this.heap.toString();
    }
}
