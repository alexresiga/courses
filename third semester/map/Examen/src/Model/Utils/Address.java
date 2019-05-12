package Model.Utils;

public class Address {
    private int address = 1;
    private static IStack<Integer> freeAddress = new MyStack<>();

    public Integer getFreeAddress() {
        if (freeAddress.isEmpty())
            return this.address++;
        else
            return freeAddress.pop();
    }
}
