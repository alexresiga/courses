package Repository;

import Model.ProgramState;
import Exception.FileException;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Repository implements IRepository{

    private List<ProgramState> programStateList;
    private String logFilePath;

    public Repository(String logFilePath) {
        programStateList = new ArrayList<>();
        this.logFilePath = logFilePath;
    }

    public Repository(List<ProgramState> programStateList, String logFilePath){
        this.programStateList = programStateList;
        this.logFilePath = logFilePath;
    }

    public Repository(ProgramState programState, String logFilePath){
        this.programStateList = new ArrayList<>();
        programStateList.add(programState);
        this.logFilePath = logFilePath;

    }
    @Override
    public void setProgramStateList(List<ProgramState> programStateList){this.programStateList = programStateList;}

    @Override
    public List<ProgramState> getProgramStateList(){return programStateList;}

    @Override
    public ProgramState getCurrentProgram(){
        return programStateList.get(programStateList.size()-1);
    }

    @Override
    public void logPrgStateExec(ProgramState programState){
        try{
            PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
            logFile.write(programState.toString());
            logFile.write("\n");
            logFile.close();
        }catch(IOException e){
            throw new FileException("Cannot open file");
        }
    }
    @Override
    public void logCommon(ProgramState programState){
        try{
            PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
            logFile.write(programState.toString2());
            logFile.write("\n-----------------------------------------------------");
            logFile.close();
        }catch(IOException e){
            throw new FileException("Cannot open file");
        }
    }

    @Override
    public void logPrgStateExec() throws FileException {
        try{
            PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
            ProgramState programState = this.getCurrentProgram();
            logFile.write(programState.toString());
            logFile.write("\n-----------------------------------------------------");
            logFile.close();
        }catch(IOException e){
            throw new FileException("Cannot open file");
        }

    }

    @Override
    public ProgramState getProgramState(int id){
        for (ProgramState entry: programStateList) {
            if (entry.getThreadId() == id)
                return entry;
        }
        return null;
    }

    @Override
    public void add(ProgramState programState){
        programStateList.add(programState);
    }

}