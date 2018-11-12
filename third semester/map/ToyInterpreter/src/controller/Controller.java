package controller;

import exceptions.EmptyStackException;
import model.ProgramState;
import model.Statement.IStatement;
import model.utils.MyStack;
import repository.Repository;

import java.io.IOException;

public class Controller {

    private Repository repo;

    public Controller(Repository repository) {
        this.repo = repository;
    }

    public void addState(ProgramState programState) {
        this.repo.add(programState);

    }

    private ProgramState oneStep(ProgramState state) throws EmptyStackException, IOException {

        MyStack<IStatement> stack = state.getExeStack();
        if (stack.isEmpty()) {
            throw new EmptyStackException("empty stack");
        }
        IStatement currentStatement = stack.pop();

        return currentStatement.execute(state);
    }

    public void allSteps() throws java.io.IOException {
        ProgramState programState = this.repo.getCurrentState();
        while (!programState.getExeStack().isEmpty()) {
            oneStep(programState);
            this.repo.logProgramState();
        }
    }

}
