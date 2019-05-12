package Model.Statement;

import Model.ProgramState;

public class Return implements IStatement {

    public Return(){}

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        programState.getSymbolTableStack().pop();

        return null;
    }

    @Override
    public String toString() {
        return "return";
    }
}
