package datastructures;

public class DSU {
    int[] parents;

    DSU (int size) {
        this.parents = new int[size];
        for (int i = 0; i < size; i++) parents[i] = i;
    }

    int find(int x) {
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }

    boolean union(int x, int y) {
        var xParent = find(x);
        var yParent = find(y);

        if (xParent == yParent) return false;
        else if (xParent > yParent) parents[xParent] = yParent;
        else parents[yParent] = xParent;

        return true;
    }
}
