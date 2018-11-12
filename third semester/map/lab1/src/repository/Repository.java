package repository;

import exceptions.DuplicateException;
import model.*;
import java.util.ArrayList;

public class Repository implements RepositoryInterface {

    private ArrayList<Vehicle> elems;

    public Repository() {
        this.elems = new ArrayList<>();

    }

    @Override
    public void add(Vehicle vehicle) throws DuplicateException {
        if (this.elems.contains(vehicle)) {
            throw new DuplicateException("existing element");
        }
        this.elems.add(vehicle);

    }

    @Override
    public void delete(Vehicle vehicle) {
        this.elems.remove(vehicle);

    }

    @Override
    public ArrayList<Vehicle> getElems() {
        return this.elems;
    }


}
