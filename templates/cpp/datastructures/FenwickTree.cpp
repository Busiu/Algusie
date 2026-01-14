#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    vector<int> tree;
    
    FenwickTree(int size) {
        tree.assign(size + 1, 0);
    }

    void add(int idx, int val) {
        idx++;
        while (idx < tree.size()) {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }

    int sum(int idx) {
        idx++;
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= (idx & -idx);
        }
        return ans;
    }
};