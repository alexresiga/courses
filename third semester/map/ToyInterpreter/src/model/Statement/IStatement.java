package model.Statement;

import exceptions.FileAlreadyOpenedException;
import model.ProgramState;
import java.io.FileNotFoundException;
import java.io.IOException;


public interface IStatement {

    ProgramState execute(ProgramState state) throws FileAlreadyOpenedException, IOException;

    String toString();
}
