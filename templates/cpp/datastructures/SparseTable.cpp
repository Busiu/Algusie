#include <bits/stdc++.h>

using namespace std;

struct SparseTable {
    vector<vector<int>> lookup;
    vector<int> log;

    SparseTable(vector<int>& arr) {
        int n = arr.size();
        log.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) log[i] = log[i / 2] + 1;
        int k = log[n - 1] + 1;

        lookup.assign(k, vector<int>(n, 0));
        copy(arr.begin(), arr.end(), lookup[0].begin());

        for (int i = 1; i < k; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                lookup[i][j] = min(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);
            } 
        }
    }

    int query(int l, int r) {
        int inv = log[r - l + 1];
        cout << inv << endl;
        return min(lookup[inv][l], lookup[inv][r - (1 << inv) + 1]); 
    }
};

int main() {
    // --- Test Case 1: Static RMQ ---
    vector<int> arr1 = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    SparseTable st1(arr1);

    assert(st1.query(0, 8) == 0);
    assert(st1.query(0, 2) == 2);
    assert(st1.query(4, 7) == 3);
    assert(st1.query(5, 5) == 10);
    cout << "Test Case 1 Passed: Static RMQ verified." << endl;

    // --- Test Case 2: Overlapping Ranges ---
    vector<int> arr2 = {10, 8, 6, 4, 2, 1, 3, 5, 7, 9};
    SparseTable st2(arr2);

    assert(st2.query(0, 3) == 4); // [10, 8, 6, 4]
    assert(st2.query(2, 4) == 2); // [6, 4, 2]
    assert(st2.query(0, 9) == 1); // Full array
    cout << "Test Case 2 Passed: Overlapping range logic verified." << endl;

    cout << "\nAll Sparse Table tests passed!" << endl;
    return 0;
}