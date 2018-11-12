package model;

public class Vehicle {

    private int cost;
    String LicensePlate;

    Vehicle(int cost, String licensePlate) {
        this.cost = cost;
        this.LicensePlate = licensePlate;
    }

    public int getCost() {
        return this.cost;
    }

    public String getLicensePlate() {
        return this.LicensePlate;
    }


}
