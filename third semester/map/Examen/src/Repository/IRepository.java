package Repository;

import Model.ProgramState;
import Model.Utils.MyList;

import java.io.IOException;
import java.util.List;
import Exception.FileException;

public interface IRepository {
    ProgramState getCurrentProgram();
    List<ProgramState> getProgramStateList();
    void setProgramStateList(List<ProgramState> programStateList);
    void logPrgStateExec(ProgramState programState);
    void logCommon(ProgramState programState);
    void logPrgStateExec() throws FileException;
    ProgramState getProgramState(int id);
    void add(ProgramState programState);
}
