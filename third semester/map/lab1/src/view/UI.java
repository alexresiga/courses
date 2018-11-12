package view;

import controller.Controller;
import model.Vehicle;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;
import exceptions.*;

class UI {

    private Controller ctrl;
    private static Scanner reader = new Scanner(System.in);


    UI(Controller controller) {
        this.ctrl = controller;
    }

    private static String printMenu() {
        return "1. Add vehicle\n2. Remove vehicle\n3. Filter vehicles\n4. Show All\n5. Exit\n";
    }

    private int readInteger(String msg) {
        int result = -1;

        System.out.println(msg);
        try {
            result = reader.nextInt();


        } catch (InputMismatchException exception) {
            System.out.println("Invalid integer value");
        }
        reader.nextLine();

        return result;
    }
    private String readString(String msg) {
        String result = "";
        System.out.println(msg);
        try {
            result = reader.nextLine();
        } catch(InputMismatchException exception) {
            System.out.println("Invalid string");
        }

        return result;
    }
    void show() {
            while (true) {
                try {
                    System.out.println(printMenu());
                    int command = this.readInteger("Enter command: ");
                    switch (command) {
                        case 1:
                            String type = this.readString("Enter vehicle type: ");
                            String licensePlate = this.readString("Enter license plate: ");
                            int cost = this.readInteger("Enter cost: ");

                            this.ctrl.addVehicle(type, cost, licensePlate);
                            break;
                        case 2:
                            String licensePlate2 = this.readString("Enter license plate: ");
                            this.ctrl.removeVehicle(licensePlate2);
                        case 3:
                            ArrayList<Vehicle> filtered = this.ctrl.filterRepo();
                            for (Vehicle vehicle : filtered) {
                                System.out.println(vehicle.toString());
                            }
                            break;
                        case 4:
                            ArrayList<Vehicle> result = this.ctrl.getRepo().getElems();
                            for (Vehicle v : result) {
                                System.out.println(v.toString());
                            }
                            break;
                        default:
                            break;

                    }
                }catch(DuplicateException exception) {
                    System.out.println(exception.getMessage());
                }
            }
        }
    }

