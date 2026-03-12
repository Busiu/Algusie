#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parents;
    vector<int> rank;

    DSU(int size) {
        parents.assign(size, 0);
        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }
        rank.assign(size, 1);
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    bool unite(int x, int y) {
        int xParent = find(x), yParent = find(y);
        if (xParent == yParent) return false;

        if (rank[xParent] > rank[yParent]) {
            parents[yParent] = xParent;
            rank[xParent] += rank[yParent];
        } else {
            parents[xParent] = yParent;
            rank[yParent] += rank[xParent];
        }
        return true;
    }

    bool areConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    // --- Test Case 1: Linear Chain (Basic Connectivity) ---
    DSU dsu(5);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);

    assert(dsu.areConnected(0, 2)); // 0 and 2 should be connected
    assert(!dsu.areConnected(0, 3)); // 0 and 3 should NOT be connected
    cout << "Test Case 1 Passed: Basic connectivity confirmed." << endl;
    return 0;
}