package Model.Utils;

import java.util.Collection;
import java.util.Map;
import java.util.Set;

public interface IDictionary<K, V> {
    V put(K key, V value);
    void replace(K key, V value);
    V get(K key);
    K getKey(V value);
    boolean containsKey(K key);
    boolean containsValue(V value);
    int size();
    V remove(int id);
    Collection<V> values();
    Set<K> keys();
    String toString();
    IDictionary<K, V>  cloneDictionary();
    Iterable<Map.Entry<K, V>> getAll();
}
