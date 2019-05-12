package Exception;

public class InvalidExpressionError extends RuntimeException {

    public InvalidExpressionError(String msg){
        super(msg);
    }
}
