package sample;

import Controller.Controller;
import Model.Expression.*;
import Model.ProgramState;
import Model.Statement.*;
import Repository.IRepository;
import Repository.Repository;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.ListView;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class SelectWindowController {
    public Button selectButton;
    @FXML
    private ListView<String> listView;
    private List<IStatement> programStatements;
    private RunWindowController mainController;

    void setMainController(RunWindowController mainWindowController) {
        this.mainController = mainWindowController;
    }

    private void populateSelectWindow() {

        IStatement sleep = new CompoundStatement(new AssignStatement("v", new ConstExp(10)),
                new CompoundStatement(new ForkStatement(new CompoundStatement(new AssignStatement("v", new ArithExp('-', new VarExp("v"), new ConstExp(1))),
                        new CompoundStatement(new AssignStatement("v", new ArithExp('-', new VarExp("v"), new ConstExp(1))),
                                new PrintStatement(new VarExp("v"))))),
                        new CompoundStatement(new SleepStatement(10), new PrintStatement(new ArithExp('*', new VarExp("v"), new ConstExp(10))))));


        IStatement procedures = new CompoundStatement(new AssignStatement("v", new ConstExp(2)),
                new CompoundStatement(new AssignStatement("w", new ConstExp(5)),
                        new CompoundStatement(new CallFn("sum", new ArrayList<>(Arrays.asList(new ArithExp('*', new VarExp("v"), new ConstExp(10)), new VarExp("w")))),
                                new CompoundStatement(new PrintStatement(new VarExp("v")), new ForkStatement(new CompoundStatement(new CallFn("product", new ArrayList<>(Arrays.asList(new VarExp("v"), new VarExp("w")))), new ForkStatement(new CallFn("sum", new ArrayList<>(Arrays.asList(new VarExp("v"), new VarExp("w")))))))))));

        programStatements = new ArrayList<>(Arrays.asList(sleep, procedures));
    }


    @FXML
    public void initialize() {
        populateSelectWindow();
        listView.setItems(FXCollections.observableList(
                programStatements.stream().map(IStatement::toString).collect(Collectors.toList())
        ));

    }

    @FXML
    public void executeSelect() {
        int index = listView.getSelectionModel().getSelectedIndex();

        if (index < 0) {
            Alert alert = new Alert(Alert.AlertType.ERROR, "The program was not selected", ButtonType.OK);
            alert.showAndWait();
            return;
        }

        ProgramState initialProgramState = new ProgramState(programStatements.get(index));
        IRepository repository = new Repository("log" + index + ".txt");
        repository.add(initialProgramState);
        Controller ctrl = new Controller(repository);

        mainController.setController(ctrl);


    }
}
