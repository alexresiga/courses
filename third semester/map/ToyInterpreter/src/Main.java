import controller.Controller;
import model.Expression.ConstExp;
import model.Expression.VarExp;
import model.Expression.ArithExp;
import model.ProgramState;
import model.Statement.AssignmentStatement;
import model.Statement.CompoundStatement;
import model.Statement.IStatement;
import model.Statement.PrintStatement;
import model.utils.MyDictionary;
import model.utils.MyList;
import model.utils.MyStack;
import model.utils.MyTuple;
import repository.Repository;
import view.*;

import java.io.BufferedReader;


public class Main {

    public static void main(String[] args){
        MyStack<IStatement> ExeStack1 = new MyStack<>();
        MyDictionary<String, Integer> SymTable1 = new MyDictionary<>();
        MyList<Integer> Output1 = new MyList<>();
        MyDictionary<Integer, MyTuple<String, BufferedReader>> fileTable1 = new MyDictionary<>();
        IStatement ex1 = new CompoundStatement(new AssignmentStatement("v", new ConstExp(2)),
                new PrintStatement(new VarExp("v")));
        ProgramState prg1 = new ProgramState(ExeStack1, Output1, SymTable1, fileTable1,ex1);
        Repository repo1 = new Repository("log1.txt");
        Controller ctrl1 = new Controller(repo1);
        ctrl1.addState(prg1);

        MyStack<IStatement> ExeStack2 = new MyStack<>();
        MyDictionary<String, Integer> SymTable2 = new MyDictionary<>();
        MyList<Integer> Output2 = new MyList<>();
        MyDictionary<Integer, MyTuple<String, BufferedReader>> fileTable2 = new MyDictionary<>();
        IStatement ex2 = new CompoundStatement(new AssignmentStatement("a", new ArithExp('+',
                new ConstExp(2),new ArithExp('*',new ConstExp(3), new ConstExp(5)))),
                new CompoundStatement(new AssignmentStatement("b",new ArithExp('+',
                        new VarExp("a"), new ConstExp(1))), new PrintStatement(new VarExp("b"))));
        ProgramState prg2 = new ProgramState(ExeStack2, Output2, SymTable2, fileTable2, ex2);
        Repository repo2 = new Repository("log2.txt");
        Controller ctrl2 = new Controller(repo2);
        ctrl2.addState(prg2);
        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunCommand("1", ex1.toString(), ctrl1));
        menu.addCommand(new RunCommand("2", ex2.toString(), ctrl2));
        menu.show();

    }
}
