package view;
import model.*;
import repository.Repository;
import controller.Controller;
import exceptions.*;

public class Main {



    public static void main(String[] args) {
        Vehicle car1 = new Car(1230, "W12");
        Truck truck1 = new Truck(2330, "A34");
        Motorcycle motor1 = new Motorcycle(230, "R4S");
        Vehicle car2 = new Car(130, "AR2");
        Truck truck2 = new Truck(5000, "AUI4");
        Motorcycle motor2 = new Motorcycle(30, "ABC");
        Repository repo = new Repository();
        try {
            repo.add(car1);
            repo.add(truck1);
            repo.add(motor1);
            repo.add(car2);
            repo.add(truck2);
            repo.add(motor2);
        }catch (DuplicateException exc) {
            System.out.println(exc.getMessage());
        }
        Controller ctrl = new Controller(repo);
        UI ui = new UI(ctrl);
        ui.show();

    }
}
