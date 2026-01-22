// Implementation of Point Update Range Sum Min Segment Tree
// Validation: https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
private:
    int len;
    vector<int> segTree;

    int DEFAULT = INT32_MAX;
    int combine(const int& a, const int& b) {
        return min(a, b);
    }

    void build(vector<int>& arr, int at, int tl, int tr) {
        if (tl == tr) {
            segTree[at] = arr[tl];
            return; 
        }

        int tm = (tl + tr) / 2;
        build(arr, 2 * at, tl, tm);
        build(arr, 2 * at + 1, tm + 1, tr);

        segTree[at] = combine(segTree[2 * at], segTree[2 * at + 1]);    
    }

    void set(int idx, int val, int at, int tl, int tr) {
        if (tl == tr) {
            segTree[at] = val;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) set(idx, val, 2 * at, tl, tm);
        else set(idx, val, 2 * at + 1, tm + 1, tr);
        segTree[at] = combine(segTree[2 * at], segTree[2 * at + 1]);
    }

    int query(int l, int r, int at, int tl, int tr) {
        if (tr < l || tl > r) return DEFAULT;
        if (l <= tl && tr <= r) return segTree[at];

        int tm = (tl + tr) / 2;
        return combine(query(l, r, 2 * at, tl, tm), query(l, r, 2 * at + 1, tm + 1, tr));
    }

public:
    SegmentTree(vector<int>& arr) : len(arr.size()) {
        segTree = vector<int> (4 * len, 0);
        build(arr, 1, 0, len - 1);
    }

    void set(int idx, int val) {
        set(idx, val, 1, 0, len - 1);
    }

    int query(int l, int r) {
        return query(l, r, 1, 0, len - 1);
    }
};