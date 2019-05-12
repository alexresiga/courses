package Model.Utils;

import java.util.Map;

public interface IHeap {
    void add(Integer value);
    void remove(Integer value);
    Integer get(Integer addr);
    Integer getAddress(Integer value);
    boolean exists(Integer addr);
    void replace(Integer address, Integer newValue);
    String toString();
    void setContent(Map<Integer, Integer> newContent);
    Map<Integer, Integer> getContent();
    Iterable<Integer> keys();
    Iterable<Map.Entry<Integer, Integer>> getAll();


}
