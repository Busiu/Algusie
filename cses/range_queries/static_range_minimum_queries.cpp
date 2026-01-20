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

struct SparseTable {
    vector<vector<int>> lookup;
    vector<int> log;

    SparseTable(vector<int>& arr) {
        int n = arr.size();
        log.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) log[i] = log[i / 2] + 1;
        int k = log[n] + 1;

        lookup.assign(k, vector<int>(n, 0));
        lookup[0].assign(arr.begin(), arr.end());

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SparseTable st(a);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--; b--; 
        cout << st.query(a, b) << endl;
    }

    return 0;
}