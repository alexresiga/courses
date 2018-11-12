package exceptions;

public class FileAlreadyOpenedException extends RuntimeException {

    public FileAlreadyOpenedException(String message) {
        super(message);
    }
}
