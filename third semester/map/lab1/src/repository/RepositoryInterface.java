package repository;

import model.*;
import java.util.ArrayList;
import exceptions.DuplicateException;

public interface RepositoryInterface {

    void add(Vehicle vehicle) throws DuplicateException;

    void delete(Vehicle vehicle);

    ArrayList<Vehicle> getElems();
}
