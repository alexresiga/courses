package model;

import model.Statement.IStatement;
import model.utils.*;

import java.io.BufferedReader;


public class ProgramState {

    private IStack<IStatement> exeStack;
    private IList<Integer> Output;
    private IDictionary<String, Integer> symTable;
    private IStatement originalProgram;
    private IDictionary<Integer, ITuple<String, BufferedReader>> fileTable;
    private IHeap<Integer> heap;

    public ProgramState(IStack<IStatement> exeStack, IList<Integer> Output, IDictionary<String, Integer> symTable, IDictionary<Integer, ITuple<String, BufferedReader>> fileTable, IHeap<Integer> heap, IStatement Program) {
        this.exeStack = exeStack;
        this.Output = Output;
        this.symTable = symTable;
        this.fileTable = fileTable;
        this.originalProgram = Program;
        this.heap = heap;
        
    }


    public IDictionary<String, Integer> getSymTable() {
        return this.symTable;
    }

    public void setSymTable(IDictionary<String, Integer> st) {
        this.symTable = st;
    }

    public IStack<IStatement> getExeStack() {
        return this.exeStack;
    }

    public void setExeStack(IStack<IStatement> exeStack) {
        this.exeStack = exeStack;
    }

    public IList<Integer> getOutput() {
        return this.Output;
    }

    public void setOutput(IList<Integer> output) {
        this.Output = output;
    }

    public IDictionary<Integer, ITuple<String, BufferedReader>> getFileTable() {
        return this.fileTable;
    }

    public void setFileTable(IDictionary<Integer, ITuple<String, BufferedReader>> fileTable) {
        this.fileTable = fileTable;
    }

    public IHeap<Integer> getHeap() {
        return this.heap;
    }

    public void setHeap(IHeap<Integer> heap) {
        this.heap = heap;
    }

    public IStatement getOriginalProgram() {
        return this.originalProgram;
    }

    public void setOriginalProgram(IStatement originalProgram) {
        this.originalProgram = originalProgram;
    }

    public String toString() {
        return this.exeStack.toString() + "\nSYM TABLE:\n" + this.symTable.toString() + this.Output.toString() + "\nFILE TABLE:\n" + this.fileTable.toString() + "\nHEAP:\n" + this.heap.toString();
    }
}
