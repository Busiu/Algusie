// Link - https://cses.fi/problemset/task/1713
// Source - https://usaco.guide/gold/divisibility
// Date - 2026-01-30

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        int ans = 1;
        for (int i = 2; i * i <= x; i++) {
            int noOcc = 0;
            while (x % i == 0) {
                noOcc++;
                x /= i;
            }
            ans *= (noOcc + 1);
        }
        if (x > 1) ans *= 2;
        cout << ans << endl;
    }
    return 0;
}