package model.utils;

import java.util.Collection;

public interface IDictionary<K, V> {
    V put(K key, V value);
    V remove(K key);
    boolean contains(K key);
    V get(K key);
    Collection<V> values();
    Collection<K> keys();
    String toString();
}
