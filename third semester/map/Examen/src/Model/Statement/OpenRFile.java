package Model.Statement;

import Model.ProgramState;
import Model.Utils.ITuple;
import Model.Utils.Tuple;
import Exception.FileAlreadyOpenedExc;

import java.io.*;

public class OpenRFile implements IStatement {
    private static int fd = 1000;
    private String varFileID, fileName;

    public OpenRFile(String varFileID, String fileName){
        this.varFileID = varFileID;
        this.fileName = fileName;
    }

    public ProgramState execute(ProgramState programState) throws IOException, FileAlreadyOpenedExc{
        for (ITuple<String, BufferedReader> files: programState.getFileTable().values()){
            if (files.getFirst().contains(this.fileName)){
                throw new FileAlreadyOpenedExc("the file " + this.fileName + " is already opened");
            }
        }
        File file = new File(this.fileName);
        if(!file.exists()){
            throw new FileNotFoundException("the file " + this.fileName + " does not exist");
        }
        int newFD = ++OpenRFile.fd;
        programState.getFileTable().put(newFD, new Tuple<>(this.fileName, new BufferedReader(new FileReader(this.fileName))));
        programState.getSymbolTable().put(this.varFileID, newFD);

        return null;
    }

    @Override
    public String toString(){
        return "openRFile(" + this.varFileID + ", " + this.fileName + ")";
    }
}
