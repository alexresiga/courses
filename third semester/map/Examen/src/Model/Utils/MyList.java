package Model.Utils;

import java.util.ArrayList;
import java.util.List;

public class MyList<T> implements IList<T> {
    private ArrayList<T> list;

    public MyList(){

        list = new ArrayList<>();
    }

    @Override
    public boolean add(T elem)
    {
        return list.add(elem);
    }

    @Override
    public void clear(){
        list.clear();
    }

    @Override
    public int size(){

        return list.size();
    }

    @Override
    public boolean isEmpty(){
        return list.isEmpty();
    }

    @Override
    public T get(int id){
        return list.get(id);
    }

    @Override
    public List<T> getAll() {
        return list;
    }

    @Override
    public String toString(){

        StringBuilder str = new StringBuilder();
        str.append("\nOUTPUT: ");
        if (this.list.isEmpty()) str.append("\n");
        for(T elem: this.list)
            str.append("\n").append(elem.toString());
        return str.toString();
    }
}
