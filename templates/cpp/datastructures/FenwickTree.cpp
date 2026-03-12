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

int main() {
    // --- Test Case 1: Point Updates ---
    FenwickTree ft(5);
    ft.add(1, 5);
    ft.add(3, 10);
    ft.add(1, 2);

    assert(ft.sum(1) == 7);
    assert(ft.sum(2) == 7);
    assert(ft.sum(3) == 17);
    cout << "Test Case 1 Passed: Point updates and prefix sums." << endl;
    cout << "\nAll Fenwick Tree tests passed!" << endl;
    return 0;
}