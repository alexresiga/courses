package model;

public class Truck extends Vehicle {

    public Truck(int cost, String licensePlate) {
        super(cost, licensePlate);
    }

    @Override
    public String toString() {
        return String.format("Vehicle type: truck\n\tlicense plate: %s\n\treparation cost: %s\n", this.LicensePlate, Integer.toString(this.getCost()));
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Truck)) {
            return false;
        }
        Truck truck = (Truck) obj;
        return this.LicensePlate.equals(truck.LicensePlate);
    }
}
