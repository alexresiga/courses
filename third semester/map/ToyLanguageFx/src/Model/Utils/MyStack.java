package Model.Utils;

import java.util.Stack;
import java.util.List;

public class MyStack<T> implements IStack<T> {
    private Stack<T> stack;

    public MyStack(){

        stack = new Stack<>();
    }

    @Override
    public void push(T elem){
        stack.push(elem);
    }

    @Override
    public T pop() {
        return stack.pop();
    }

    @Override
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();

        Stack<T> tmp = (Stack<T>) this.stack.clone();
        Stack<T> reversedStack = new Stack<>();
        while (!tmp.empty()) {
            reversedStack.push(tmp.pop());
        }
        str.append("\nSTACK: ");
        for (T elem : reversedStack)
            str.append("\n").append(elem.toString());
        return str.toString();
    }

    @Override
    public List<T> getAll(){
        return stack;
    }
}