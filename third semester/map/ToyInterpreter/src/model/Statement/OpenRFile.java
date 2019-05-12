package model.Statement;

import exceptions.FileAlreadyOpenedException;
import model.ProgramState;
import model.utils.ITuple;
import model.utils.MyTuple;
import java.io.*;

public class OpenRFile implements IStatement {

    private static int fd = 420;
    private String filename, varFileID;

    public OpenRFile(String varFileID, String filename) {
        this.varFileID = varFileID;
        this.filename = filename;
    }

    public ProgramState execute(ProgramState state) throws FileAlreadyOpenedException, FileNotFoundException {
        for(ITuple<String, BufferedReader> files: state.getFileTable().values()) {
            if (files.getFirst().contains(this.filename)) {
                throw new FileAlreadyOpenedException("FileAlreadyOpenedException at: " + this.toString() + "\nthe file " + this.filename + " is already opened.");
            }
        }
        File file = new File(this.filename);
        if (!file.exists()) {
            throw new FileNotFoundException("FileNotFoundException at: " + this.toString() + "\nthe file " + this.filename + " does not exist");
        }

        int actualFD = ++OpenRFile.fd;

        state.getFileTable().put(actualFD, new MyTuple<>(this.filename, new BufferedReader(new FileReader(this.filename))));
        state.getSymTable().put(this.varFileID, actualFD);

        return state;
    }

    @Override
    public String toString() {
        return String.format("OpenRFile(%s, %s)", this.varFileID, this.filename);
    }
}
