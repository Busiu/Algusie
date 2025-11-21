package datastructures;

public class DSU {
    int[] parents;
    int[] size;

    DSU (int n) {
        this.parents = new int[n];
        this.size = new int[n];
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }

    boolean union(int x, int y) {
        var xParent = find(x);
        var yParent = find(y);

        if (xParent == yParent) return false;

        if (size[xParent] > size[yParent]) {
            parents[yParent] = xParent;
            size[xParent] += size[yParent];
        } else {
            parents[xParent] = yParent;
            size[yParent] += size[xParent];
        }

        return true;
    }
}
