#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parents;
    vector<int> size;

    DSU(int size) {
        parents.assign(size);
        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }
        size.assign(size, 1);
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    boolean union(int x, int y) {
        int xParent = find(x), yParent = find(y);
        if (xParent == yParent) return false;

        if (size[xParent] > size[yParent]) {
            parents[yParents] = xParent;
            size[xParent] += size[yParent];
        } else {
            parents[xParents] = yParent;
            size[yParent] += size[zParent];
        }
        return true;
    }

    boolean areConnected(int x, int y) {
        return find(x) == find(y);
    }
}