package Exception;

public class StatementExecError extends RuntimeException {
    public StatementExecError(String msg){
        super(msg);
    }
}
