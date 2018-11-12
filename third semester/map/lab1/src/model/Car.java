package model;

public class Car extends Vehicle {

    public Car(int cost, String licensePlate) {
        super(cost, licensePlate);
    }

    @Override
    public String toString() {
        return String.format("Vehicle type: car\n\tlicense plate: %s\n\treparation cost: %s\n", this.LicensePlate, Integer.toString(this.getCost()));
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Car)) {
            return false;
        }
        Car car = (Car) obj;
        return this.LicensePlate.equals(car.LicensePlate);
    }

}
