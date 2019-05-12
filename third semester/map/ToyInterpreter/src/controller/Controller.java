package controller;

import exceptions.EmptyStackException;
import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.Expression.VarExp;
import model.ProgramState;
import model.Statement.CloseRFile;
import model.Statement.IStatement;
import model.utils.IStack;
import repository.Repository;
import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class Controller {

    private Repository repo;

    public Controller(Repository repository) {
        this.repo = repository;
    }

    public void addState(ProgramState programState) {
        this.repo.add(programState);

    }

    private ProgramState oneStep(ProgramState state) throws UnknownVariableException, EmptyStackException, IOException, MyBooleanException {

        IStack<IStatement> stack = state.getExeStack();
        if (stack.isEmpty()) {
            throw new EmptyStackException("empty stack");
        }
        IStatement currentStatement = stack.pop();

        return currentStatement.execute(state);
    }

    public void allSteps() throws UnknownVariableException, java.io.IOException, MyBooleanException {
        ProgramState programState = this.repo.getCurrentState();
        try {
            while (!programState.getExeStack().isEmpty()) {
                oneStep(programState);
                programState.getHeap().setMap(this.conservativeGarbageCollector(programState.getSymTable().values(), programState.getHeap().toMap()));
                this.repo.logProgramState();
            }
        } finally {
            programState.getSymTable().keys().stream().filter(key -> programState.getFileTable().contains(programState.getSymTable().get(key))).map(item -> {
                try {
                    return new CloseRFile(new VarExp(item)).execute(programState);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return null;
            }).forEach(item -> {
                try {
                    this.repo.logProgramState();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });

        }

    }

    private Map<Integer, Integer> conservativeGarbageCollector(Collection<Integer> symTableValues, Map<Integer, Integer> heap) {
        return heap.entrySet().stream().filter(item -> symTableValues.contains(item.getKey())).collect(Collectors.toMap(HashMap.Entry::getKey, Map.Entry::getValue));
    }

}
