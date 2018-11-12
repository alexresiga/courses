package model;

public class Motorcycle extends Vehicle {

    public Motorcycle(int cost, String licensePlate) {
        super(cost, licensePlate);
    }

    @Override
    public String toString() {
        return String.format("Vehicle type: motorcycle\n\tlicense plate: %s\n\treparation cost: %s\n",this.LicensePlate,Integer.toString(this.getCost()));
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Motorcycle)) {
            return false;
        }
        Motorcycle mtr = (Motorcycle) obj;
        return this.LicensePlate.equals(mtr.LicensePlate);
    }
}
