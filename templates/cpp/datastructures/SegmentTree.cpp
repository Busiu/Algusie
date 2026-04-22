// Implementation of Point Update Range Sum Min Segment Tree
// Validation: https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
private:
    int len;
    vector<int> segTree;

    int DEFAULT = 0;
    int combine(const int& a, const int& b) {
        return a + b;
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

int main() {
    // --- Test Case 1: Basic Range Sum & Build ---
    vector<int> arr1 = {1, 3, 5, 7, 9, 11};
    SegmentTree st1(arr1);

    assert(st1.query(0, 2) == 9);   // 1 + 3 + 5
    assert(st1.query(1, 4) == 24);  // 3 + 5 + 7 + 9
    assert(st1.query(0, 5) == 36);  // Full range sum
    cout << "Test Case 1 Passed: Initial build and range queries correct." << endl;

    // --- Test Case 2: Point Updates (set) ---
    st1.set(2, 10);
    
    assert(st1.query(0, 2) == 14);  // 1 + 3 + 10
    assert(st1.query(2, 2) == 10);  // Single element query
    assert(st1.query(2, 5) == 37);  // 10 + 7 + 9 + 11
    cout << "Test Case 2 Passed: Point updates correctly reflected in queries." << endl;

    // --- Test Case 3: Small Array & Edge Cases ---
    vector<int> arr2 = {10, -5};
    SegmentTree st2(arr2);

    assert(st2.query(0, 0) == 10);
    assert(st2.query(1, 1) == -5);
    assert(st2.query(0, 1) == 5);
    
    st2.set(0, 0);
    assert(st2.query(0, 1) == -5);
    cout << "Test Case 3 Passed: Small array and negative values handled." << endl;

    cout << "All Segment Tree tests passed successfully!" << endl;

    return 0;
}