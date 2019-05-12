package Model.Utils;

import javafx.util.Pair;

import java.util.*;

public class MySemaphore implements IDictionary<Integer, Pair<Integer, List<Integer>>> {

    private HashMap<Integer, Pair<Integer, List<Integer>>> dictionary;

    public MySemaphore(){
        dictionary = new HashMap<>();
    }

    @Override
    public Pair<Integer, List<Integer>> put(Integer key, Pair<Integer, List<Integer>> value) {
        return dictionary.put(key, value);
    }

    @Override
    public void replace(Integer key, Pair<Integer, List<Integer>> value){
        this.dictionary.replace(key, value);
    }

    @Override
    public Pair<Integer, List<Integer>> get(Integer key){
        return dictionary.get(key);
    }

    @Override
    public Integer getKey(Pair<Integer, List<Integer>> value){
        for(Integer key: dictionary.keySet()) {
            if (dictionary.get(key).equals(value))
                return key;
        }
        return null;
    }

    @Override
    public boolean containsKey(Integer key){
        return dictionary.containsKey(key);
    }

    @Override
    public boolean containsValue(Pair<Integer, List<Integer>> value){
        return dictionary.containsValue(value);
    }

    @Override
    public int size(){
        return dictionary.size();
    }

    @Override
    public Pair<Integer, List<Integer>> remove(int id){
        return dictionary.remove(id);
    }

    @Override
    public Collection<Pair<Integer, List<Integer>>> values(){
        return dictionary.values();
    }

    @Override
    public Set<Integer> keys(){
        return dictionary.keySet();
    }

    @Override
    public IDictionary<Integer, Pair<Integer, List<Integer>>> cloneDictionary(){
        IDictionary<Integer, Pair<Integer, List<Integer>>> newDictionary = new MyBarrier();
        for(Integer key: dictionary.keySet())
            newDictionary.put(key, dictionary.get(key));
        return newDictionary;
    }

    @Override
    public Iterable<Map.Entry<Integer, Pair<Integer, List<Integer>>>> getAll(){
        return dictionary.entrySet();
    }

    @Override
    public String toString(){
        StringBuilder str = new StringBuilder();
        for(Integer key: this.keys())
            str.append("\n").append(key.toString()).append("->").append(this.get(key).toString());
        return str.toString();
    }
}
