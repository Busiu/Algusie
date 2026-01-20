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

        lookup.assign(k, vector<int>(0, n));
        copy(arr.begin(), arr.end(), lookup[0]);

        for (int i = 1; i < k; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                lookup[i][j] = min(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);
            } 
        }
    }

    int query(int l, int r) {
        int inv = log[r - l + 1];
        return min(lookup[inv][l], lookup[inv][r - (1 << inv) + 1]); 
    }
};