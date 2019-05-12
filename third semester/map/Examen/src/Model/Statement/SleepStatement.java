package Model.Statement;

import Model.ProgramState;
import Model.Utils.IStack;

public class SleepStatement implements IStatement{
    private Integer value;

    public SleepStatement(Integer value){
        this.value = value;
    }

    @Override
    public ProgramState execute(ProgramState programState){
        if (value != 0){
            IStack<IStatement> exeStack = programState.getExeStack();
            exeStack.push(new SleepStatement(--value));
        }
        return null;
    }

    @Override
    public String toString(){
        return "sleep(" + value.toString() + ")";
    }

}
