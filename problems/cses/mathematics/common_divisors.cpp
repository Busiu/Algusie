// Link - https://cses.fi/problemset/task/1081
// Source - https://usaco.guide/gold/divisibility
// Date - 2026-01-31

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

int MAX = 1e6 + 10;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    bool arr[MAX];
    memset(arr, false, sizeof(arr));
    
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 1; j * j <= x; j++) {
            if (x % j != 0) continue;

            if (arr[j]) ans = max(ans, j);
            arr[j] = true;
            if (j * j != x) {
                if (arr[x / j]) ans = max(ans, x / j);
                arr[x / j] = true;
            }
        }
    }
    cout << ans << endl;

    return 0;
}