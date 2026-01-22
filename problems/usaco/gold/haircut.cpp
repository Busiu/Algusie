#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define INF 2147483647
#define LL_INF 9223372036854775807

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int MOD = 1e9 + 7;

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
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> queue(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        if (val == n) continue;
        queue[val].push_back(i);
    }

    FenwickTree ft(n);
    for (int i = 0; i < n; i++) ft.add(i, 1);

    ll acc = 0;
    for (int i = 0; i < n; i++) {
        cout << acc << endl;
        for (int idx : queue[i]) {
            ft.add(idx, -1);
            acc += ft.sum(idx);
        }
    }

    return 0;
}