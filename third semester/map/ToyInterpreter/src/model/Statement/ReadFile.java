package model.Statement;

import exceptions.FileAlreadyOpenedException;
import exceptions.FileNotOpenedException;
import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.Expression.Expression;
import model.ProgramState;
import model.utils.ITuple;
import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements IStatement {

    private Expression expFileID;
    private String varName;

    public ReadFile(Expression expFileID, String varName) {
        this.expFileID = expFileID;
        this.varName = varName;
    }

    @Override
    public ProgramState execute(ProgramState state) throws UnknownVariableException, FileAlreadyOpenedException, FileNotOpenedException, IOException, MyBooleanException {
        int fd = this.expFileID.evaluate(state.getSymTable(), state.getHeap());
        ITuple<String, BufferedReader> file = state.getFileTable().get(fd);
        if (file == null) {
            throw new FileNotOpenedException("FileNotOpenedException at: " + this.toString() + "\nNo such file descriptor: " + String.valueOf(fd));
        }
        String line = file.getSecond().readLine();
        int val = 0;
        if (line != null) {
            val = Integer.valueOf(line);
        }
        state.getSymTable().put(this.varName, val);

        return null;
    }

    @Override
    public String toString() {
        return String.format("ReadFile(%s, %s)", this.expFileID.toString(), this.varName);
    }
}
