package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Model.Utils.ITuple;
import Exception.FileException;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements IStatement {
    private Expression exp;
    private String var;

    public ReadFile(Expression exp, String var){
        this.exp = exp;
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws IOException, FileException{
        int fd = this.exp.evaluate(programState.getSymbolTable(), programState.getHeap());
        ITuple<String, BufferedReader> buff =programState.getFileTable().get(fd);
        if( buff == null)
            throw new FileException("No such file descriptor: " + String.valueOf(fd));
        String line = buff.getSecond().readLine();
        int val = 0;
        if (line != null)
            val = Integer.valueOf(line);
        programState.getSymbolTable().put(this.var, val);
        return null;
    }

    @Override
    public String toString(){
        return "ReadFile(" + this.exp.toString() + ", " + this.var + ")";
    }
}
