package view;

/*
import model.ProgramState;
import model.Statement.*;
import model.utils.*;
import controller.Controller;
import model.Expression.*;

import java.io.BufferedReader;
import java.util.Scanner;

public class UI {

    private Controller ctrl;

    public UI(Controller controller) {
        this.ctrl = controller;
    }

    private static void printMenu() {
        System.out.println("\n\n1. v=2;Print(v)");
        System.out.println("2. a=2+3*5;b=a+1;Print(b)");
        System.out.println("3. a=2-2;(If a Then v=2 Else v=3);Print(v)");
        System.out.println("0. Exit");
        System.out.println("Input command: ");
    }

    public void show() {
        boolean done = false;
        while (!done) {
            MyStack<IStatement> ExeStack = new MyStack<>();
            MyDictionary<String, Integer> SymTable = new MyDictionary<>();
            MyList<Integer> Output = new MyList<>();
            MyDictionary<Integer, MyTuple<String, BufferedReader>> fileTable = new MyDictionary<>();
            printMenu();
            Scanner input = new Scanner(System.in);
            int cmd;

            if (input.hasNextInt())
                cmd = input.nextInt();
            else {
                System.out.println("Wrong input");
                continue;
            }
            switch (cmd) {
                case 0:
                    done = true;
                    break;
                case 1:
                    try {
                        IStatement ex1 = new CompoundStatement(new AssignmentStatement("v", new ConstExp(2)),
                                new PrintStatement(new VarExp("v")));
                        ExeStack.push(ex1);
                        ProgramState curr = new ProgramState(ExeStack, Output, SymTable, fileTable, ex1);
                        this.ctrl.addState(curr);
                        ctrl.allSteps();

                    } catch (Exception exc) {
                        System.out.println(exc.getMessage());
                    }
                    break;
                case 2:
                    try {
                        IStatement ex2 = new CompoundStatement(new AssignmentStatement("a", new ArithExp('+',
                                new ConstExp(2), new ArithExp('*', new ConstExp(3), new ConstExp(5)))),
                                new CompoundStatement(new AssignmentStatement("b", new ArithExp('+',
                                        new VarExp("a"), new ConstExp(1))), new PrintStatement(new VarExp("b"))));

                        ExeStack.push(ex2);
                        ProgramState curr = new ProgramState(ExeStack, Output, SymTable, fileTable, ex2);
                        ctrl.addState(curr);
                        ctrl.allSteps();

                    } catch (Exception exc) {
                        System.out.println(exc.getMessage());
                    }
                    break;
                case 3:
                    try {
                        IStatement ex3 = new CompoundStatement(new AssignmentStatement("a",
                                new ArithExp('-', new ConstExp(2), new ConstExp(2))),
                                new CompoundStatement(new IfStatement(new VarExp("a"),
                                        new AssignmentStatement("v", new ConstExp(2)), new
                                        AssignmentStatement("v", new ConstExp(3))),
                                        new PrintStatement(new VarExp("v"))));

                        ExeStack.push(ex3);
                        ProgramState curr = new ProgramState(ExeStack, Output, SymTable, fileTable, ex3);
                        ctrl.addState(curr);
                        ctrl.allSteps();

                    } catch (Exception exc) {
                        System.out.println(exc.getMessage());
                    }
                    break;
                case 4:
                    try {
                        IStatement open = new CompoundStatement(new OpenRFile("var_f", "test.in"),new CompoundStatement(new ReadFile(new VarExp("var_f"),"var_c"), new CompoundStatement(new PrintStatement(new VarExp("var_c")), new CloseRFile(new VarExp("var_f")))));
                        ExeStack.push(open);
                        ProgramState curr = new ProgramState(ExeStack, Output, SymTable, fileTable, open);
                        ctrl.addState(curr);
                        ctrl.allSteps();
                    } catch (Exception exc) {
                        System.out.println(exc.getMessage());
                    }
                    break;
            }
        }
    }
}

SEMINAR3- EXEMPLU1
var_f - descriptor fisier
var_c - citeste din fisier
var_f+2 - descriptor din var_f+2 care nu merge si ii pus la teka BAGAMAMIASPULA
 */
//IStatement s = new CompoundStatement(new OpenRFile(var_f, "test.in"), new CompStatement(new ReadFile(new VarExp("var_f"), "var_c"), new CompStatement(new PrintStatement(new VarExp("var_c"))
