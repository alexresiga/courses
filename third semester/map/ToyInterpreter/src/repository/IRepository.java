package repository;

import model.ProgramState;

public interface IRepository {

    void add(ProgramState state);

    void logProgramState()throws java.io.IOException;

}
