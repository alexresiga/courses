package Model.Statement;

import Model.Expression.Expression;
import Model.ProgramState;
import Model.Utils.IDictionary;
import Model.Utils.MyDictionary;
import java.util.List;

public class CallFn implements IStatement {

    private String fname;
    private List<Expression> params;

    public CallFn(String fname, List<Expression> params) {
        this.fname = fname;
        this.params = params;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws Exception {
        if (!programState.getProcTable().containsKey(this.fname))
            throw new Exception("unknown procedure");

        List<String> listOfFormalParameters = programState.getProcTable().get(this.fname).getKey();
        IStatement function = programState.getProcTable().get(this.fname).getValue();
        IDictionary<String, Integer> newSymbolTable = new MyDictionary<>();

        for(int i = 0; i < listOfFormalParameters.size(); ++i)
            newSymbolTable.put(listOfFormalParameters.get(i), this.params.get(i).evaluate(programState.getSymbolTable(), programState.getHeap()));

        programState.getSymbolTableStack().push(newSymbolTable);
        programState.getExeStack().push(new Return());
        programState.getExeStack().push(function);

        return null;
    }

    @Override
    public String toString() {
        return String.format("call %s(%s)", this.fname, this.params.toString());
    }
}
