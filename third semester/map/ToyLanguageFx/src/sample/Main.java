package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        FXMLLoader mainLoader = new FXMLLoader();
        mainLoader.setLocation(getClass().getResource("RunWindow.fxml"));
        Parent mainWindow = mainLoader.load();

        RunWindowController mainController = mainLoader.getController();

        primaryStage.setTitle("Main Window");
        primaryStage.setScene(new Scene (mainWindow,1041, 600));
        primaryStage.show();

        FXMLLoader secondLoader = new FXMLLoader();
        secondLoader.setLocation(getClass().getResource("SelectWindow.fxml"));
        Parent secondWindow = secondLoader.load();

        SelectWindowController secondController = secondLoader.getController();
        secondController.setMainController(mainController);

        Stage secondStage = new Stage();
        secondStage.setTitle("Select Window");
        secondStage.setScene(new Scene (secondWindow, 500, 300));
        secondStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
