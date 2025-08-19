package datastructures.multiset;

import java.util.Collection;
import java.util.HashMap;

public class MultiHashSet<E> {
    HashMap<E, Integer> freqMap = new HashMap<>();
    int size;

    public MultiHashSet() {}

    public MultiHashSet(Collection<? extends E> c) {
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
}
