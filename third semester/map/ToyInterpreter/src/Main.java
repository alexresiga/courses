import controller.Controller;
import model.Expression.ConstExp;
import model.Expression.ReadHeap;
import model.Expression.VarExp;
import model.Expression.ArithExp;
import model.ProgramState;
import model.Statement.*;
import model.utils.*;
import repository.Repository;
import view.*;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.util.HashMap;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        MyStack<IStatement> ExeStack1 = new MyStack<>();
        MyDictionary<String, Integer> SymTable1 = new MyDictionary<>();
        MyList<Integer> Output1 = new MyList<>();
        MyDictionary<Integer, ITuple<String, BufferedReader>> fileTable1 = new MyDictionary<>();
        IHeap<Integer> heap1 = new MyHeap<>(new HashMap<>());
        IStatement ex1 = new CompoundStatement(new AssignmentStatement("v", new ConstExp(2)),
                new NewStatement("v", new ConstExp(20)));
        ExeStack1.push(ex1);
        ProgramState prg1 = new ProgramState(ExeStack1, Output1, SymTable1, fileTable1, heap1, ex1);
        Repository repo1 = new Repository("log1.txt");
        Controller ctrl1 = new Controller(repo1);
        ctrl1.addState(prg1);

        MyStack<IStatement> ExeStack2 = new MyStack<>();
        MyDictionary<String, Integer> SymTable2 = new MyDictionary<>();
        MyList<Integer> Output2 = new MyList<>();
        MyDictionary<Integer, ITuple<String, BufferedReader>> fileTable2 = new MyDictionary<>();
        IHeap<Integer> heap2 = new MyHeap<>(new HashMap<>());
        IStatement ex2 = new CompoundStatement(new AssignmentStatement("a", new ArithExp('+',
                new ConstExp(2),new ArithExp('*',new ConstExp(3), new ConstExp(5)))),
                new CompoundStatement(new AssignmentStatement("b",new ArithExp('+',
                        new VarExp("a"), new ConstExp(1))), new PrintStatement(new VarExp("b"))));
        ProgramState prg2 = new ProgramState(ExeStack2, Output2, SymTable2, fileTable2, heap2, ex2);
        Repository repo2 = new Repository("log2.txt");
        Controller ctrl2 = new Controller(repo2);
        ctrl2.addState(prg2);


        MyStack<IStatement> ExeStack3 = new MyStack<>();
        MyDictionary<String, Integer> SymTable3 = new MyDictionary<>();
        MyList<Integer> Output3 = new MyList<>();
        MyDictionary<Integer, ITuple<String, BufferedReader>> fileTable3 = new MyDictionary<>();
        IHeap<Integer> heap3 = new MyHeap<>(new HashMap<>());
        IStatement open = new CompoundStatement(new OpenRFile("var_f", "test.in"),new CompoundStatement(new ReadFile(new VarExp("var_f"),"var_c"),new CompoundStatement(new PrintStatement(new VarExp("var_c")), new OpenRFile("var_g", "log4.txt"))));
        ExeStack3.push(open);
        ProgramState prg3 = new ProgramState(ExeStack3,Output3, SymTable3, fileTable3, heap3, open);
        Repository repo3 = new Repository("log3.txt");
        Controller ctrl3 = new Controller(repo3);
        ctrl3.addState(prg3);

        MyStack<IStatement> ExeStack4 = new MyStack<>();
        MyDictionary<String, Integer> SymTable4 = new MyDictionary<>();
        MyList<Integer> Output4 = new MyList<>();
        MyDictionary<Integer, ITuple<String, BufferedReader>> fileTable4 = new MyDictionary<>();
        IHeap<Integer> heap4 = new MyHeap<>(new HashMap<>());
        IStatement lab4 = new CompoundStatement(new AssignmentStatement("v", new ConstExp(10)),
                            new CompoundStatement(new NewStatement("v", new ConstExp(20)),
                            new CompoundStatement(new NewStatement("a", new ConstExp(22)),
                            new CompoundStatement(new HeapWrite("a", new ConstExp(30)),
                            new CompoundStatement(new PrintStatement(new VarExp("a")),
                            new CompoundStatement(new PrintStatement(new ReadHeap("a")),new AssignmentStatement("a", new ConstExp(0))))))));
        ExeStack4.push(lab4);
        ProgramState programState4 = new ProgramState(ExeStack4, Output4, SymTable4, fileTable4, heap4, lab4);
        Repository repo4 = new Repository("log4.txt");
        Controller ctrl4 = new Controller(repo4);
        ctrl4.addState(programState4);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunCommand("1", ex1.toString(), ctrl1));
        menu.addCommand(new RunCommand("2", ex2.toString(), ctrl2));
        menu.addCommand(new RunCommand("3", open.toString(), ctrl3));
        menu.addCommand(new RunCommand("4", lab4.toString(), ctrl4));
        menu.show();

    }
}
