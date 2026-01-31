// Link - https://atcoder.jp/contests/abc169/tasks/abc169_d
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

    ll n; cin >> n;
    int ans = 0;

    for (ll i = 2; i * i <= n; i++) {
        int noOcc = 0;
        int curThr = 1;
        while (n % i == 0) {
            noOcc++;
            n /= i;
            if (noOcc == curThr) {
                ans++;
                curThr++;
                noOcc = 0;
            }
        }
    }
    if (n > 1) ans++;
    cout << ans << endl;

    return 0;
}