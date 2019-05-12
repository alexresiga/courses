package sample;

import Controller.Controller;

import Model.ProgramState;
import Model.Statement.IStatement;
import Model.Utils.*;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.util.Pair;
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

    @FXML
    private TableView<Map.Entry<String, String>> procTableView;

    @FXML
    private TableColumn<Map.Entry<String, String>, String> procTableNameCol;

    @FXML
    private TableColumn<Map.Entry<String, String>,  String> procTableBodyCol;

    @FXML
    public void initialize(){

        procTableNameCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getKey() + ""));
        procTableBodyCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getValue() + ""));


        heapAddressCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        heapValueCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue()).asObject());

        fileTableIdentifierCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        fileTableNameCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getValue() + ""));

        symbolTableVariableCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getKey() + ""));
        symbolTableValueCol.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue()).asObject());

        programStateIdentifiersView.setOnMouseClicked(mouseEvent -> changeProgramState(getCurrentProgramState()));
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

    private void populateProcTable(ProgramState currentProgramState) {
        IDictionary<String, Pair<List<String>, IStatement>> procTable = currentProgramState.getProcTable();

        Map<String, String> procTableMap = new HashMap<>();

        for(Map.Entry<String, Pair<List<String>, IStatement>> entry : procTable.getAll()) {
            String signature = entry.getKey() + entry.getValue().getKey();
            procTableMap.put(signature, entry.getValue().getValue().toString());
        }

        List<Map.Entry<String, String>> procTableList = new ArrayList<>(procTableMap.entrySet());

        procTableView.setItems(FXCollections.observableList(procTableList));
        procTableView.refresh();

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
        populateProcTable(currentProgramState);
    }

}
