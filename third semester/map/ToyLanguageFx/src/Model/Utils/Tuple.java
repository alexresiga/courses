package Model.Utils;

public class Tuple<T1, T2> implements ITuple<T1, T2> {
    private T1 first;
    private T2 second;

    public Tuple(T1 first, T2 second){
        this.first = first;
        this.second = second;
    }
    @Override
    public String toString(){
        return this.first.toString();
    }

    @Override
    public T1 getFirst(){
        return first;
    }

    @Override
    public T2 getSecond() {
        return second;
    }
}
