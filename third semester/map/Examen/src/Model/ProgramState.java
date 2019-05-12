package Model;

import Model.Expression.ArithExp;
import Model.Expression.VarExp;
import Model.Statement.AssignStatement;
import Model.Statement.CompoundStatement;
import Model.Statement.IStatement;
import Model.Statement.PrintStatement;
import Model.Utils.*;
import javafx.util.Pair;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ProgramState {
    private IStack<IStatement> exeStack;
    private IList<Integer> outputList;
    private IDictionary<String, Integer> symbolTable;
    private IDictionary<Integer, ITuple<String, BufferedReader>> fileTable;
    private IHeap heap;
    private IStack<IDictionary<String, Integer>> symbolTableStack;
    private IDictionary<String, Pair<List<String>, IStatement>> procTable;
    private Integer id = 1;

    public ProgramState(IStatement statement) {
        exeStack = new MyStack<>();
        symbolTableStack = new MyStack<>();
        outputList = new MyList<>();
        fileTable = new MyDictionary<>();
        heap = new MyHeap();
        procTable = new MyDictionary<>();
        exeStack.push(statement);
        procTable.put("sum", new Pair<>(new ArrayList<>(Arrays.asList("a", "b")), new CompoundStatement(new AssignStatement("v", new ArithExp('+', new VarExp("a"), new VarExp("b"))), new PrintStatement(new VarExp("v")))));
        procTable.put("product", new Pair<>(new ArrayList<>(Arrays.asList("a", "b")), new CompoundStatement(new AssignStatement("v", new ArithExp('*', new VarExp("a"), new VarExp("b"))), new PrintStatement(new VarExp("v")))));
        symbolTableStack.push(new MyDictionary<>());
        symbolTable = symbolTableStack.peek();
    }


    public ProgramState(IStack<IStatement> exeStack,
                        IList<Integer> output,
                        IDictionary<Integer, ITuple<String, BufferedReader>> fileTable,
                        IHeap heap,
                        IStack<IDictionary<String, Integer>> symbolTableStack,
                        IDictionary<String, Pair<List<String>, IStatement>> procTable,
                        IStatement st,
                        Integer id) {
        this.exeStack = exeStack;
        this.outputList = output;
        this.fileTable = fileTable;
        this.heap = heap;
        this.symbolTableStack = symbolTableStack;
        this.procTable = procTable;
        this.id = id;
        exeStack.push(st);
        procTable.put("sum", new Pair<>(new ArrayList<>(Arrays.asList("a", "b")), new CompoundStatement(new AssignStatement("v", new ArithExp('+', new VarExp("a"), new VarExp("b"))), new PrintStatement(new VarExp("v")))));
        procTable.put("product", new Pair<>(new ArrayList<>(Arrays.asList("a", "b")), new CompoundStatement(new AssignStatement("v", new ArithExp('*', new VarExp("a"), new VarExp("b"))), new PrintStatement(new VarExp("v")))));
        this.symbolTable = this.symbolTableStack.peek();
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

    public void setSymbolTable(IDictionary<String, Integer> symbolTable) {
        this.symbolTable = symbolTable;
    }

    public IStack<IDictionary<String, Integer>> getSymbolTableStack() {
        return symbolTableStack;
    }

    public IDictionary<String, Pair<List<String>, IStatement>> getProcTable() {
        return procTable;
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
