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

        IStatement ex1 = new CompoundStatement(
                new AssignStatement("v", new ConstExp(2)),
                new PrintStatement(new VarExp("v")));

        IStatement ex2 = new CompoundStatement(
                new AssignStatement("a", new ArithExp('+', new ConstExp(2),
                        new ArithExp('*', new ConstExp(3), new ConstExp(5)))),
                new CompoundStatement(
                        new AssignStatement("b", new ArithExp('+', new VarExp("a"), new ConstExp(1))),
                        new PrintStatement(new VarExp("b"))));

        IStatement ex3 = new CompoundStatement(
                new AssignStatement("v", new ConstExp(2)),
                new PrintStatement(new VarExp("v")));

        IStatement ex4 = new CompoundStatement(
                new AssignStatement("v", new ConstExp(10)),
                new CompoundStatement(
                        new NewHeap("v", new ConstExp(20)),
                        new CompoundStatement(
                                new NewHeap("a", new ConstExp(22)),
                                new PrintStatement(new VarExp("v"))
                        )
                )
        );
        IStatement ex5 = new CompoundStatement(
                new AssignStatement("v", new ConstExp(10)),
                new CompoundStatement(
                        new NewHeap("v", new ConstExp(20)),
                        new CompoundStatement(
                                new NewHeap("a", new ConstExp(22)),
                                new CompoundStatement(
                                        new PrintStatement(
                                                new ArithExp('+', new ConstExp(100), new ReadHeap("v"))),
                                        new PrintStatement(
                                                new ArithExp('+', new ConstExp(100), new ReadHeap("a"))
                                        )
                                )
                        )
                )
        );
        IStatement ex6 = new CompoundStatement(
                new AssignStatement("v", new ConstExp(10)),
                new CompoundStatement(
                        new NewHeap("v", new ConstExp(20)),
                        new CompoundStatement(
                                new NewHeap("a", new ConstExp(22)),
                                new CompoundStatement(
                                        new WriteHeap("a", new ConstExp(30)),
                                        new CompoundStatement(
                                                new PrintStatement(new VarExp("a")),
                                                new PrintStatement(new ReadHeap("a")))
                                )
                        )
                )
        );
        IStatement ex7 = new CompoundStatement(
                new AssignStatement("v", new ConstExp(10)),
                new CompoundStatement(
                        new NewHeap("v", new ConstExp(20)),
                        new CompoundStatement(
                                new NewHeap("a", new ConstExp(22)),
                                new CompoundStatement(
                                        new WriteHeap("a", new ConstExp(30)),
                                        new CompoundStatement(
                                                new PrintStatement(new VarExp("a")),
                                                new CompoundStatement(
                                                        new PrintStatement(new ReadHeap("a")),
                                                        new AssignStatement("a",
                                                                new ConstExp(0))
                                                )
                                        )
                                )
                        )
                )
        );
        IStatement ex8 = new PrintStatement(
                new ArithExp(
                        '+',
                        new ConstExp(10),
                        new BooleanExp(
                                "<",
                                new ConstExp(2),
                                new ConstExp(6)
                        )
                )
        );
        IStatement ex9 = new PrintStatement(
                new BooleanExp(
                        "<",
                        new ArithExp(
                                '+',
                                new ConstExp(10),
                                new ConstExp(2)
                        ),
                        new ConstExp(6)
                )
        );
        IStatement ex10 = new CompoundStatement(
                new AssignStatement("v", new ConstExp(6)),
                new CompoundStatement(
                        new WhileStatement(
                                new ArithExp(
                                        '-',
                                        new VarExp("v"),
                                        new ConstExp(4)
                                ),
                                new CompoundStatement(
                                        new PrintStatement(new VarExp("v")),
                                        new AssignStatement(
                                                "v",
                                                new ArithExp(
                                                        '-',
                                                        new VarExp("v"),
                                                        new ConstExp(1)
                                                )
                                        )
                                )
                        ),
                        new PrintStatement(new VarExp("v"))
                )
        );
        IStatement ex11 = new CompoundStatement(
                new OpenRFile("var_f", "test.in"),
                new CompoundStatement(
                        new ReadFile(new VarExp("var_f"), "var_c"),
                        new CompoundStatement(
                                new PrintStatement(new VarExp("var_c")),
                                new OpenRFile("var_g", "test2.in"))));

        IStatement ex15 = new CompoundStatement(
                new NewHeap("v1", new ConstExp(2)), new CompoundStatement(
                new NewHeap("v2", new ConstExp(3)), new CompoundStatement(
                new NewHeap("v3", new ConstExp(4)), new CompoundStatement(
                new NewBarrier("cnt", new ReadHeap("v2")), new CompoundStatement(
                new ForkStatement(
                        new CompoundStatement(
                                new Await("cnt"), new CompoundStatement(
                                new WriteHeap("v1", new ArithExp('*', new ReadHeap("v1"), new ConstExp(10))), new PrintStatement(new ReadHeap("v1")))
                        )
                ), new CompoundStatement(
                new ForkStatement(
                        new CompoundStatement(
                                new Await("cnt"), new CompoundStatement(
                                new WriteHeap("v2", new ArithExp('*', new ReadHeap("v2"), new ConstExp(10))), new CompoundStatement(
                                new WriteHeap("v2", new ArithExp('*', new ReadHeap("v2"), new ConstExp(10))), new PrintStatement(new ReadHeap("v2"))
                        )
                        )
                        )
                ), new CompoundStatement(
                new Await("cnt"), new PrintStatement(new ReadHeap("v3"))
        )
        )
        )
        )
        )
        )
        );

        IStatement ex20 = new CompoundStatement(new NewHeap("v1", new ConstExp(2)),
                new CompoundStatement(new NewHeap("v2", new ConstExp(3)),
                        new CompoundStatement(new NewHeap("v3", new ConstExp(4)),
                                new CompoundStatement(new NewLatch("cnt", new ReadHeap("v2")),
                                        new CompoundStatement(new ForkStatement(new CompoundStatement(new WriteHeap("v1", new ArithExp('*', new ReadHeap("v1"), new ConstExp(10))), new PrintStatement(new ReadHeap("v1")))),
                                                new CompoundStatement(new CountDown("cnt"),
                                                        new CompoundStatement(new ForkStatement(new CompoundStatement(new WriteHeap("v2", new ArithExp('*', new ReadHeap("v2"), new ConstExp(10))), new PrintStatement(new ReadHeap("v2")))),
                                                                new CompoundStatement(new CountDown("cnt"),
                                                                        new CompoundStatement(new ForkStatement(new CompoundStatement(new WriteHeap("v3", new ArithExp('*', new ReadHeap("v3"), new ConstExp(10))), new PrintStatement(new ReadHeap("v3")))),
                                                                                new CompoundStatement(new CountDown("cnt"),
                                                                                        new CompoundStatement(new LatchAwait("cnt"),
                                                                                                new CompoundStatement(new PrintStatement(new ConstExp(100)),
                                                                                                        new CompoundStatement(new LatchAwait("cnt"), new PrintStatement(new ConstExp(100)))))))))))))));

        IStatement ex14 = new CompoundStatement(new NewSemaphore("v", new ConstExp(2)),
                new CompoundStatement(
                        new ForkStatement(
                                new CompoundStatement(
                                        new Acquire("v"), new CompoundStatement(
                                        new PrintStatement(new ConstExp(1)), new Release("v")
                                )
                                )
                        ), new CompoundStatement(
                        new ForkStatement(
                                new CompoundStatement(
                                        new Acquire("v"), new CompoundStatement(
                                        new PrintStatement(new ConstExp(2)), new Release("v")
                                )
                                )
                        ),
                        new ForkStatement(
                                new CompoundStatement(
                                        new Acquire("v"), new CompoundStatement(
                                        new PrintStatement(new ConstExp(3)), new Release("v")
                                )
                                )
                        )
                )
                ));

        IStatement ex13 = new CompoundStatement(new NewHeap("v1", new ConstExp(20)),
                new CompoundStatement(new NewHeap("v2", new ConstExp(30)),
                        new CompoundStatement(new NewLock("x"), new CompoundStatement(
                                new ForkStatement( new CompoundStatement(new ForkStatement(new CompoundStatement(new LockStatement("x"),
                                        new CompoundStatement(new WriteHeap("v1", new ArithExp('-', new ReadHeap("v1"), new ConstExp(1))),
                                                new UnlockStatement("x")))),
                                        new CompoundStatement(new LockStatement("x"),
                                                new CompoundStatement(new WriteHeap("v1", new ArithExp('+', new ReadHeap("v1"), new ConstExp(1))),
                                                        new UnlockStatement("x"))))),
                                new CompoundStatement(new NewLock("q"),
                                        new CompoundStatement(new ForkStatement(
                                                new CompoundStatement(new ForkStatement(new CompoundStatement(new LockStatement("q"),
                                                        new CompoundStatement(new WriteHeap("v2", new ArithExp('+', new ReadHeap("v2"), new ConstExp(5))), new UnlockStatement("q")))),
                                                        new CompoundStatement(new AssignStatement("m", new ConstExp(100)),
                                                                new CompoundStatement(new LockStatement("q"),new CompoundStatement(new WriteHeap("v2", new ArithExp('+', new ReadHeap("v2"), new ConstExp(1))),new UnlockStatement("q")))))),
                                                new CompoundStatement(new AssignStatement("z", new ConstExp(200)),
                                                        new CompoundStatement(new AssignStatement("z", new ConstExp(300)),
                                                                new CompoundStatement(new AssignStatement("z", new ConstExp(400)),
                                                                        new CompoundStatement(new LockStatement("x"),
                                                                                new CompoundStatement(new PrintStatement(new ReadHeap("v1")),
                                                                                        new CompoundStatement(new UnlockStatement("x"),
                                                                                                new CompoundStatement(new LockStatement("q"),
                                                                                                        new CompoundStatement(new PrintStatement(new ReadHeap("v2")),
                                                                                                                new UnlockStatement("q")))))))))))))));

        IStatement ex12 = new CompoundStatement(
                new AssignStatement("v", new ConstExp(20)),
                new CompoundStatement(
                        new ForStatement("v",
                                new ConstExp(0),
                                new ConstExp(3),
                                new ArithExp('+', new VarExp("v"), new ConstExp(1)),
                                new ForkStatement(new CompoundStatement(
                                        new PrintStatement(new VarExp("v")),
                                        new AssignStatement("v", new ArithExp('+', new VarExp("v"), new ConstExp(1)))
                                )
                                )
                        ),
                        new PrintStatement(new ArithExp('*', new VarExp("v"), new ConstExp(10) )
                        )));

        IStatement ex17 = new CompoundStatement(new AssignStatement("v", new ConstExp(10)),
                new CompoundStatement(new ForkStatement(new CompoundStatement(new AssignStatement("v", new ArithExp('-',new VarExp("v"), new ConstExp(1))),
                        new CompoundStatement(new AssignStatement("v", new ArithExp('-', new VarExp("v"), new ConstExp(1))),
                                new PrintStatement(new VarExp("v"))))),
                        new CompoundStatement(new SleepStatement(10), new PrintStatement(new ArithExp('*',new VarExp("v"), new ConstExp(10))))));

        IStatement ex16 = new CompoundStatement(new AssignStatement("v", new ConstExp(0)),
                new CompoundStatement(new RepeatStatement(new CompoundStatement(new ForkStatement(new CompoundStatement(new PrintStatement(new VarExp("v")), new AssignStatement("v", new ArithExp('-', new VarExp("v"), new ConstExp(1))))), new AssignStatement("v", new ArithExp('+', new VarExp("v"), new ConstExp(1)))), new BooleanExp("==", new VarExp("v"), new ConstExp(3))),
                        new CompoundStatement(new AssignStatement("x", new ConstExp(1)),
                                new CompoundStatement(new AssignStatement("y", new ConstExp(2)),
                                        new CompoundStatement(new AssignStatement("z", new ConstExp(3)),
                                                new CompoundStatement(new AssignStatement("w", new ConstExp(4)),
                                                        new PrintStatement(new ArithExp('*', new VarExp("v"), new ConstExp(10)))))))));


        programStatements = new ArrayList<>(Arrays.asList(ex1, ex2, ex3, ex4, ex5, ex6, ex7, ex8, ex9, ex10, ex11, ex12, ex15, ex20, ex14, ex13, ex16, ex17));
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
