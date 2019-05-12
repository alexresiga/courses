package model.Statement;

import exceptions.FileAlreadyOpenedException;
import exceptions.MyBooleanException;
import exceptions.UnknownVariableException;
import model.ProgramState;
import java.io.IOException;


public interface IStatement {

    ProgramState execute(ProgramState state) throws UnknownVariableException, MyBooleanException, FileAlreadyOpenedException, IOException;

    String toString();
}
