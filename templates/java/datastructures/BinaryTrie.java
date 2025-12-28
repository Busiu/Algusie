package java.datastructures;

import java.util.HashSet;

public class BinaryTrie {
    class Node {
        Node[] children;
        int[] subTrieSizes;
        Node() {
            this.children = new Node[2];
            this.subTrieSizes = new int[2];
        }
    }

    Node root;
    int elemSize;
    HashSet<Integer> inserted;

    BinaryTrie(int elemSize) {
        this.root = new Node();
        this.elemSize = elemSize;
        this.inserted = new HashSet<>();
    }

    void insert(int val) {
        if (inserted.contains(val)) return;
        inserted.add(val);

        Node helper = root;
        for (int i = (1 << (elemSize - 1)); i > 0; i >>= 1) {
            int childIdx = (val & i) > 0 ? 1 : 0;
            if (helper.children[childIdx] == null) helper.children[childIdx] = new Node();
            helper.subTrieSizes[childIdx]++;
            helper = helper.children[childIdx];
        }
    }

    int findKthSmallest(int k) {
        if (k > inserted.size()) return -1;

        Node helper = root;
        int val = 0;
        for (int i = (1 << (elemSize - 1)); i > 0; i >>= 1) {
            if (helper.subTrieSizes[0] < k) {
                k -= helper.subTrieSizes[0];
                helper = helper.children[1];
                val += i;
            } else {
                helper = helper.children[0];
            }
        }

        return val;
    }
}
