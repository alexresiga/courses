package Model.Utils;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MyLock implements IDictionary<Integer, Integer> {

    private HashMap<Integer, Integer> dictionary;

    public MyLock(){
        dictionary = new HashMap<>();
    }

    @Override
    public Integer put(Integer key, Integer value) {
        return dictionary.put(key, value);
    }

    @Override
    public void replace(Integer key, Integer value){
        this.dictionary.replace(key, value);
    }

    @Override
    public Integer get(Integer key){
        return dictionary.get(key);
    }

    @Override
    public Integer getKey(Integer value){
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
    public boolean containsValue(Integer value){
        return dictionary.containsValue(value);
    }

    @Override
    public int size(){
        return dictionary.size();
    }

    @Override
    public Integer remove(int id){
        return dictionary.remove(id);
    }

    @Override
    public Collection<Integer> values(){
        return dictionary.values();
    }

    @Override
    public Set<Integer> keys(){
        return dictionary.keySet();
    }

    @Override
    public IDictionary<Integer, Integer> cloneDictionary(){
        IDictionary<Integer, Integer> newDictionary = new MyLatch();
        for(Integer key: dictionary.keySet())
            newDictionary.put(key, dictionary.get(key));
        return newDictionary;
    }

    @Override
    public Iterable<Map.Entry<Integer, Integer>> getAll(){
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


