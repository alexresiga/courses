package repository;

import model.ProgramState;

import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Repository implements IRepository {


    private ArrayList<ProgramState> states = new ArrayList<>();
    private String logFile;

    public Repository(String logFile) {
        this.logFile = logFile;
    }

    @Override
    public void add(ProgramState programState) {
        this.states.add(programState);
    }

    public ProgramState getCurrentState() {
        return states.get(states.size()-1);
    }

    @Override
    public void logProgramState() throws java.io.IOException {
        FileWriter writer  = new FileWriter(logFile, true);
        PrintWriter printWriter = new PrintWriter(writer);

        ProgramState current = this.getCurrentState();
        printWriter.print(current.toString());
        printWriter.print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printWriter.close();
    }

}
