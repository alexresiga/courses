package controller;
import model.*;
import repository.*;
import exceptions.DuplicateException;

import java.util.ArrayList;

public class Controller {

    private Repository repo;

    public Controller(Repository repo) {
        this.repo = repo;
    }

    public Repository getRepo() {
        return this.repo;
    }

    public void addVehicle(String type, int cost, String licensePlate) throws DuplicateException {
        switch (type) {
            case "car":
                Car car = new Car(cost, licensePlate);
                this.repo.add(car);
                break;
            case "truck":
                Truck truck = new Truck(cost, licensePlate);
                this.repo.add(truck);
                break;
            case "motor":
                Motorcycle motorcycle = new Motorcycle(cost, licensePlate);
                this.repo.add(motorcycle);
                break;
        }
    }

    public ArrayList<Vehicle> filterRepo() {
        ArrayList<Vehicle> result = new ArrayList<>();
        for(Vehicle vehicle: this.getRepo().getElems()) {
            if (vehicle.getCost() > 1000) {
                result.add(vehicle);
            }
        }
        return result;
    }

    public void removeVehicle(String licensePlate2) {
        ArrayList<Vehicle> toRemove = new ArrayList<>();
        for(Vehicle vehicle: this.getRepo().getElems()) {
            if (vehicle.getLicensePlate().equals(licensePlate2)) {
               toRemove.add(vehicle);
            }
        }

        this.repo.getElems().removeAll(toRemove);
    }
}
