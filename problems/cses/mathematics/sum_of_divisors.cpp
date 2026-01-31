// Link - https://cses.fi/problemset/task/1082
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

ll arithmeticSum(ll a, ll b) {
    ll B = (b * (b + 1) / 2) % MOD;
    ll A = (a * (a + 1) / 2) % MOD;
    return (B - A + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;

    ll ans = 0;
    ll upperLimit = n;
    for (ll i = 1; i * i < n; i++) {
        ll lowerLimit = n / (i + 1);
        ans += arithmeticSum(lowerLimit % MOD, upperLimit % MOD) * i;
        ans %= MOD;
        upperLimit = lowerLimit;
    }
    for (ll i = 1; i <= upperLimit; i++) {
        ans += i * (n / i);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}