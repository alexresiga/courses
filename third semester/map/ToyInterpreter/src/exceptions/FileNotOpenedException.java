package exceptions;

public class FileNotOpenedException extends RuntimeException {

    public FileNotOpenedException(String message) {
        super(message);
    }
}
