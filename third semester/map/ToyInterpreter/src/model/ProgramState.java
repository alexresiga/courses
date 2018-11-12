package model;

import model.Statement.IStatement;
import model.utils.*;

import java.io.BufferedReader;


public class ProgramState {

    private MyStack<IStatement> exeStack;
    private MyList<Integer> Output;
    private MyDictionary<String, Integer> symTable;
    private IStatement originalProgram;
    private MyDictionary<Integer, MyTuple<String, BufferedReader>> fileTable;

    public ProgramState(MyStack<IStatement> exeStack, MyList<Integer> Output, MyDictionary<String, Integer> symTable, MyDictionary<Integer, MyTuple<String, BufferedReader>> fileTable,IStatement Program) {
        this.exeStack = exeStack;
        this.Output = Output;
        this.symTable = symTable;
        this.fileTable = fileTable;
        this.originalProgram = Program;
    }

    public MyDictionary<String, Integer> getSymTable() {
        return this.symTable;
    }

    public void setSymTable(MyDictionary<String, Integer> st) {
        this.symTable = st;
    }

    public MyStack<IStatement> getExeStack() {
        return this.exeStack;
    }

    public void setExeStack(MyStack<IStatement> exeStack) {
        this.exeStack = exeStack;
    }

    public MyList<Integer> getOutput() {
        return this.Output;
    }

    public void setOutput(MyList<Integer> output) {
        this.Output = output;
    }

    public MyDictionary<Integer, MyTuple<String, BufferedReader>> getFileTable() {
        return this.fileTable;
    }

    public void setFileTable(MyDictionary<Integer, MyTuple<String, BufferedReader>> fileTable) {
        this.fileTable = fileTable;
    }

    public IStatement getOriginalProgram() {
        return this.originalProgram;
    }

    public void setOriginalProgram(IStatement originalProgram) {
        this.originalProgram = originalProgram;
    }

    public String toString() {
        return this.exeStack.toString() + "\nSYM TABLE:\n" + this.symTable.toString() + this.Output.toString() + "\nFILE TABLE:\n" + this.fileTable.toString();
    }
}
