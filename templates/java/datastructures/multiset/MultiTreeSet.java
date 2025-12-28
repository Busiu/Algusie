package java.datastructures.multiset;

import java.util.Collection;
import java.util.TreeMap;

public class MultiTreeSet<E extends Comparable<E>> {
    TreeMap<E, Integer> freqMap = new TreeMap<>();
    int size;

    public MultiTreeSet() {}

    public MultiTreeSet(Collection<? extends E> c) {
        for(E element : c) add(element);
    }

    public int add(E element) {
        freqMap.merge(element, 1, Integer::sum);
        size++;
        return get(element);
    }

    public int remove(E element) {
        Integer curFreq = freqMap.get(element);
        if (curFreq == null) return 0;

        if (curFreq == 1) freqMap.remove(element);
        else freqMap.put(element, curFreq - 1);
        size--;
        return get(element);
    }

    public int get(E element) {
        Integer freq = freqMap.get(element);
        return freq == null ? 0 : freq;
    }

    public int getNoKeys() {
        return freqMap.size();
    }

    public int getNoAllElements() {
        return size;
    }

    public boolean contains(E element) {
        return get(element) > 0;
    }

    public boolean isEmpty() {
        return freqMap.isEmpty();
    }

    public E first() {
        return freqMap.firstKey();
    }

    public E last() {
        return freqMap.lastKey();
    }

    public E ceiling(E element) {
        return freqMap.ceilingKey(element);
    }

    public E floor(E element) {
        return freqMap.floorKey(element);
    }

    public E higher(E element) {
        return freqMap.higherKey(element);
    }

    public E lower(E element) {
        return freqMap.lowerKey(element);
    }
}
