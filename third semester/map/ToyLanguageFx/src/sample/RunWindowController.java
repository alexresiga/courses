package sample;

import Controller.Controller;

import Model.ProgramState;
import Model.Statement.IStatement;
import Model.Utils.*;

import javafx.beans.property.SimpleIntegerProperty;
//import javafx.beans.property.SimpleObjectProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.*;
//import javafx.util.Pair;

import java.io.BufferedReader;

import java.util.*;
import java.util.stream.Collectors;

public class RunWindowController {
    public Button oneStepButton;
    private Controller controller;

    @FXML
    private TableView<Map.Entry<String, Integer>> symbolTableView;

    @FXML
    private TableColumn<Map.Entry<String, Integer>, String> symbolTableVariableCol;

    @FXML
    private TableColumn<Map.Entry<String, Integer>, Integer> symbolTableValueCol;

    @FXML
    private TableView<Map.Entry<Integer, Integer>> heapTableView;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, Integer> heapAddressCol;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, Integer> heapValueCol;

    @FXML
    private TableView<Map.Entry<Integer, String>> fileTableView;

    @FXML
    private TableColumn<Map.Entry<Integer, String>, Integer> fileTableIdentifierCol;

    @FXML
    private TableColumn<Map.Entry<Integer, String>, String> fileTableNameCol;

    @FXML
    private ListView<Integer> programStateIdentifiersView;

    @FXML
    private ListView<String> exeStackView;

    @FXML
    private ListView<Integer> outputView;

    @FXML
    private TextField noOfProgramStatesView;

//    @FXML
//    private TableView<Map.Entry<Integer, Pair<Integer, List<Integer>>>> barrierTableView;
//
//    @FXML
//    private TableColumn<Map.Entry<Integer, Pair<Integer, List<Integer>>>, Integer> barrierTableIndexCol;
//
//    @FXML
//    private TableColumn<Map.Entry<Integer, Pair<Integer, List<Integer>>>, Integer> barrierTableValueCol;
//
//    @FXML
//    private TableColumn<Map.Entry<Integer, Pair<Integer, List<Integer>>>, List<Integer>> barrierTableListCol;

    @FXML
    private TableView<Map.Entry<Integer, Integer>> latchTableView;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, Integer> latchTableLocationCol;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, Integer> latchTableValueCol;

//    @FXML
//    private TableView<Map.Entry<Integer, Pair<Integer, List<Integer>>>> semaphoreTableView;
//
//    @FXML
//    private TableColumn<Map.Entry<Integer, Pair<Integer, List<Integer>>>, Integer> semaphoreTableIndexCol;
//
//    @FXML
//    private TableColumn<Map.Entry<Integer, Pair<Integer, List<Integer>>>, Integer> semaphoreTableValueCol;
//
//    @FXML
//    private TableColumn<Map.Entry<Integer, Pair<Integer, List<Integer>>>, List<Integer>> semaphoreTableListCol;

    @FXML
    private TableView<Map.Entry<Integer, Integer>> lockTableView;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, Integer> lockTableLocationCol;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, Integer> lockTableValueCol;



    @FXML
    public void initialize(){

        heapAddressCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        heapValueCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue()).asObject());

        fileTableIdentifierCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        fileTableNameCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getValue() + ""));

        symbolTableVariableCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getKey() + ""));
        symbolTableValueCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue()).asObject());

        programStateIdentifiersView.setOnMouseClicked(mouseEvent -> changeProgramState(getCurrentProgramState()));


//        barrierTableIndexCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
//        barrierTableValueCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue().getKey()).asObject());
//        barrierTableListCol.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getValue().getValue()));

        latchTableLocationCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        latchTableValueCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue()).asObject());


//        semaphoreTableIndexCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
//        semaphoreTableValueCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue().getKey()).asObject());
//        semaphoreTableListCol.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getValue().getValue()));

        lockTableLocationCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        lockTableValueCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue()).asObject());


    }

    @FXML
    public void executeOneStep() {
        if(controller == null){
            Alert alert = new Alert(Alert.AlertType.ERROR, "The program was not selected", ButtonType.OK);
            alert.showAndWait();
            return;
        }

        boolean programStateLeft = getCurrentProgramState().getExeStack().isEmpty();
        if(programStateLeft){
            Alert alert = new Alert(Alert.AlertType.ERROR, "Nothing left to execute", ButtonType.OK);
            alert.showAndWait();
            return;
        }

        controller.oneStepGUI();

        changeProgramState(getCurrentProgramState());
        populateProgramStateIdentifiers();


    }

    void setController(Controller controller){
        this.controller = controller;
        populateProgramStateIdentifiers();
    }

    private void populateProgramStateIdentifiers(){
        List<ProgramState> programStateList = controller.getRepository().getProgramStateList();
        programStateIdentifiersView.setItems(FXCollections.observableList(getProgramStateIDs(programStateList)));
        noOfProgramStatesView.setText(""+ programStateList.size());
    }

    private List<Integer> getProgramStateIDs(List<ProgramState> programStateList){
        return programStateList.stream().map(ProgramState::getThreadId).collect(Collectors.toList());
    }

    private void populateSymbolTable(ProgramState currentProgramState) {
        IDictionary<String, Integer> symbolTable = currentProgramState.getSymbolTable();

        List<Map.Entry<String, Integer>> symbolTableList = new ArrayList<>();

        for(Map.Entry<String, Integer> entry : symbolTable.getAll())
            symbolTableList.add(entry);

        symbolTableView.setItems(FXCollections.observableList(symbolTableList));
        symbolTableView.refresh();
    }

    private void populateHeapTable(ProgramState currentProgramState) {
        IHeap heapTable = currentProgramState.getHeap();

        List<Map.Entry<Integer, Integer>> heapTableList = new ArrayList<>();

        for(Map.Entry<Integer, Integer> entry : heapTable.getAll())
            heapTableList.add(entry);

        heapTableView.setItems(FXCollections.observableList(heapTableList));
        heapTableView.refresh();
    }

    private void populateFileTable(ProgramState currentProgramState) {
        IDictionary<Integer, ITuple<String, BufferedReader>> fileTable = currentProgramState.getFileTable();

        Map<Integer, String> fileTableMap = new HashMap<>();

        for (Map.Entry<Integer, ITuple<String, BufferedReader>> entry : fileTable.getAll())
            fileTableMap.put(entry.getKey(), entry.getValue().getFirst());

        List<Map.Entry<Integer, String>> fileTableList = new ArrayList<>(fileTableMap.entrySet());
        fileTableView.setItems(FXCollections.observableList(fileTableList));
        fileTableView.refresh();
    }

    private void populateExecutionStack(ProgramState currentProgramState) {
        IStack<IStatement> executionStack = currentProgramState.getExeStack();

        List<String> executionStackList = new ArrayList<>();
        for(IStatement s : executionStack.getAll()){
            executionStackList.add(s.toString());
        }
        Collections.reverse(executionStackList);
        exeStackView.setItems(FXCollections.observableList(executionStackList));
        exeStackView.refresh();
    }

    private void populateOutput(ProgramState currentProgramState) {
        IList<Integer> output = currentProgramState.getOutputList();
        List<Integer> outputList = new ArrayList<>(output.getAll());
        outputView.setItems(FXCollections.observableList(outputList));
        outputView.refresh();
    }

//    private void populateBarrierTable(ProgramState currentProgramState) {
//        IDictionary<Integer, Pair<Integer, List<Integer>>> barrierTable = currentProgramState.getBarrierTable();
//
//        List<Map.Entry<Integer, Pair<Integer, List<Integer>>>> barrierTableList = new ArrayList<>();
//        for(Map.Entry<Integer, Pair<Integer, List<Integer>>> entry : barrierTable.getAll())
//            barrierTableList.add(entry);
//        barrierTableView.setItems(FXCollections.observableList(barrierTableList));
//        barrierTableView.refresh();
//    }

    private void populateLatchTable(ProgramState currentProgramState) {
        IDictionary<Integer, Integer> latchTable = currentProgramState.getLatchTable();

        List<Map.Entry<Integer, Integer>> latchTableList = new ArrayList<>();
        for(Map.Entry<Integer, Integer> entry : latchTable.getAll())
            latchTableList.add(entry);
        latchTableView.setItems(FXCollections.observableList(latchTableList));
        latchTableView.refresh();
    }

//    private void populateSemaphoreTable(ProgramState currentProgramState) {
//        IDictionary<Integer, Pair<Integer, List<Integer>>> semaphoreTable = currentProgramState.getSemaphoreTable();
//
//        List<Map.Entry<Integer, Pair<Integer, List<Integer>>>> semaphoreTableList = new ArrayList<>();
//        for(Map.Entry<Integer, Pair<Integer, List<Integer>>> entry : semaphoreTable.getAll())
//            semaphoreTableList.add(entry);
//        semaphoreTableView.setItems(FXCollections.observableList(semaphoreTableList));
//        semaphoreTableView.refresh();
//    }

    private void populateLockTable(ProgramState currentProgramState) {
        IDictionary<Integer, Integer> lockTable = currentProgramState.getLockTable();

        List<Map.Entry<Integer, Integer>> lockTableList = new ArrayList<>();
        for(Map.Entry<Integer, Integer> entry : lockTable.getAll())
            lockTableList.add(entry);
        lockTableView.setItems(FXCollections.observableList(lockTableList));
        lockTableView.refresh();
    }

    private ProgramState getCurrentProgramState(){
        int currentID;
        if(programStateIdentifiersView.getSelectionModel().getSelectedIndex() == -1)
            currentID = 1;
        else
            currentID = programStateIdentifiersView.getSelectionModel().getSelectedItem();
        return controller.getRepository().getProgramState(currentID);
    }

    private void changeProgramState(ProgramState currentProgramState) {
        if(currentProgramState == null)
            return;
        populateExecutionStack(currentProgramState);
        populateSymbolTable(currentProgramState);
        populateOutput(currentProgramState);
        populateFileTable(currentProgramState);
        populateHeapTable(currentProgramState);
        //populateBarrierTable(currentProgramState);
        populateLatchTable(currentProgramState);
        //populateSemaphoreTable(currentProgramState);
        populateLockTable(currentProgramState);
    }

}
