package Model.Statement;

import  Model.ProgramState;
import Exception.*;

import java.io.IOException;

public interface IStatement {
    String toString();
    ProgramState execute(ProgramState programState) throws Exception;
}
