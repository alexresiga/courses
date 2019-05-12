package model.Statement;

import exceptions.FileNotOpenedException;
import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.Expression.Expression;
import model.ProgramState;
import model.utils.ITuple;
import model.utils.MyTuple;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseRFile implements IStatement {
    private Expression expression;

    public CloseRFile(Expression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws IOException, UnknownVariableException, MyBooleanException {

        int fd = this.expression.evaluate(state.getSymTable(), state.getHeap());
        ITuple<String, BufferedReader> file = state.getFileTable().remove(fd);
        if (file == null) {
            throw new FileNotOpenedException(String.format("FileNotOpenedException at: %s\nThere is no file opened with descriptor: %d", this.toString(), fd));
        }
        file.getSecond().close();
        return state;
    }

    @Override
    public String toString() {
        return String.format("CloseRFile(%s)", this.expression.toString());
    }
}
