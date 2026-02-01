// Link - https://cses.fi/problemset/task/1095
// Source - https://usaco.guide/gold/modular
// Date - example: 2026-01-31

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

const int MOD = 1e9 + 7;

ll fastPowIterative(ll a, ll b, ll mod) {
    ll ans = 1;
    a %= mod;
    ll f = a;
    while (b > 0) {
        if (b & 1) ans = ans * f % mod;
        f = f * f % mod;
        b >>= 1; 
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    while (n--) {
        ll a, b, c; cin >> a >> b >> c;
        ll pow = fastPowIterative(b, c, MOD - 1);
        cout << fastPowIterative(a, pow, MOD) << endl;
    }

    return 0;
}