package model.utils;

import java.util.Collection;
import java.util.HashMap;

public class MyDictionary<K, V> implements IDictionary<K, V> {

    private HashMap<K, V> dictionary;

    public MyDictionary() {
        this.dictionary = new HashMap<>();
    }

    @Override
    public V put(K key, V value) {
        return this.dictionary.put(key, value);
    }

    @Override
    public V remove(K key) {
        return this.dictionary.remove(key);
    }

    @Override
    public boolean contains(K key) {
        return this.dictionary.containsKey(key);
    }

    @Override
    public V get(K key) {
        return this.dictionary.get(key);
    }

    @Override
    public Collection<V> values() {
        return this.dictionary.values();
    }

    @Override
    public Collection<K> keys() {
        return this.dictionary.keySet();
    }

    @Override
    public String toString() {

        StringBuilder result = new StringBuilder();
        for (K key: this.dictionary.keySet())
            result.append(key.toString()).append("->").append(this.dictionary.get(key).toString()).append("\n");

        return result.toString();
    }
}
