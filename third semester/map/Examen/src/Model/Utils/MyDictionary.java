package Model.Utils;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MyDictionary<K, V> implements IDictionary<K, V> {

    private HashMap<K, V> dictionary;

    public MyDictionary(){
        dictionary = new HashMap<>();
    }

    @Override
    public V put(K key, V value) {
        return dictionary.put(key, value);
    }

    @Override
    public void replace(K key, V value){
        this.dictionary.replace(key, value);
    }

    @Override
    public V get(K key){
        return dictionary.get(key);
    }

    @Override
    public K getKey(V value){
        for(K key: dictionary.keySet()) {
            if (dictionary.get(key).equals(value))
                return key;
        }
        return null;
    }

    @Override
    public boolean containsKey(K key){
        return dictionary.containsKey(key);
    }

    @Override
    public boolean containsValue(V value){
        return dictionary.containsValue(value);
    }

    @Override
    public int size(){
        return dictionary.size();
    }

    @Override
    public V remove(int id){
        return dictionary.remove(id);
    }

    @Override
    public Collection<V> values(){
        return dictionary.values();
    }

    @Override
    public Set<K> keys(){
        return dictionary.keySet();
    }

    @Override
    public IDictionary<K, V> cloneDictionary(){
        IDictionary<K, V> newDictionary = new MyDictionary<>();
        for(K key: dictionary.keySet())
            newDictionary.put(key, dictionary.get(key));
        return newDictionary;
    }

    @Override
    public Iterable<Map.Entry<K, V>> getAll(){
        return dictionary.entrySet();
    }

    @Override
    public String toString(){
        StringBuilder str = new StringBuilder();
        for(K key: this.keys())
            str.append("\n").append(key.toString()).append("->").append(this.get(key).toString());
        return str.toString();
    }


}
