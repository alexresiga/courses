package Model.Utils;

import Exception.HeapException;

import java.net.InterfaceAddress;
import java.util.HashMap;
import java.util.Map;

public class MyHeap implements IHeap {
    private HashMap<Integer, Integer> heap;
    private Integer nextFree = 1;

    public MyHeap() {
        this.heap = new HashMap<>();
    }

    @Override
    public void add(Integer value){
        if(!this.heap.containsValue(value)) {
            this.heap.put(this.nextFree, value);
            this.nextFree++;
        }

        else
            throw new HeapException("Value is already stored in the heap");
    }

    @Override
    public void remove(Integer value){
        if(this.heap.containsValue(value))
            this.heap.values().remove(value);
        else
            throw new HeapException("Value does not exist in the heap");
    }

    @Override
    public Integer get(Integer addr){
        return this.heap.get(addr);
    }

    @Override
    public Integer getAddress(Integer value){
        for(Integer key: this.heap.keySet()){
            if(this.heap.get(key) == value)
                return key;
        }
        throw new HeapException("No key associated to this value");
    }

    @Override
    public boolean exists(Integer addr){
        return this.heap.containsKey(addr);
    }

    @Override
    public void replace(Integer addr, Integer newValue){
        if(this.exists(addr))
            this.heap.replace(addr, newValue);
        else
            throw new HeapException("Invalid heap address");
    }

    @Override
    public void setContent(Map<Integer, Integer> newContent){
        this.heap = (HashMap<Integer, Integer>)newContent;
    }

    @Override
    public Map<Integer, Integer> getContent() { return this.heap; }


    @Override
    public Iterable<Integer> keys() {return heap.keySet();}

    @Override
    public Iterable<Map.Entry<Integer, Integer>> getAll(){
        return heap.entrySet();
    }

    @Override
    public String toString(){
        StringBuilder str = new StringBuilder();
        str.append("\nHEAP: ");
        if (this.heap.isEmpty()) str.append("\n");
        for(Integer key: this.heap.keySet())
            str.append("\n").append(key.toString()).append("->").append(this.get(key).toString());
        return str.toString();
    }
}
