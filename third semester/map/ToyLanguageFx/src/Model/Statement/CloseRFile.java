package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Model.Utils.ITuple;
import Exception.*;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseRFile implements IStatement {
    private Expression exp;

    public CloseRFile(Expression exp){
        this.exp = exp;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws IOException, FileException{
        int fd = this.exp.evaluate(programState.getSymbolTable(), programState.getHeap());
        ITuple<String, BufferedReader> buff = programState.getFileTable().remove(fd);
        if ( buff == null)
            throw new FileException("there is no opened file with fd = " + fd);
        buff.getSecond().close();
        return null;
    }

    @Override
    public String toString(){
        return "closeRFile(" + this.exp.toString() + ")";
    }
}
