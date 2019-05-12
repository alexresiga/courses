package repository;

import model.ProgramState;

import java.util.List;

public interface IRepository {

    void add(ProgramState state);

    void logProgramState()throws java.io.IOException;

    List<ProgramState> getProgramList();

    void setProgramList(List<ProgramState> programList);

}
