package model.utils;

import java.util.Stack;

public class MyStack<T> implements IStack<T> {

    private Stack<T> stack;

    public MyStack() {
        this.stack = new Stack<>();
    }

    @Override
    public void push(T elem) {
        this.stack.push(elem);
    }

    @Override
    public T pop() {
        return this.stack.pop();
    }

    @Override
    public boolean isEmpty() {
        return this.stack.isEmpty();
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        result.append("\nSTACK:\n");
        for(T elem: this.stack)
            result.append(elem.toString()).append(" | ");
        return result.toString();
    }
}

