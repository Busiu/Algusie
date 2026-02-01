// Link - https://cses.fi/problemset/task/1079
// Source - https://usaco.guide/gold/combo
// Date - 2026-02-01

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
const int MAX = 1e6 + 10;
ll fact[MAX];
ll inv[MAX]; 

ll fastPow(ll a, ll b) {
    a %= MOD;
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1; 
    }
    return ans;
}

void prep() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) fact[i] = fact[i - 1] * i % MOD;

    inv[MAX - 1] = fastPow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

ll binomial(ll n, ll k) {
    return fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    prep();

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cout << binomial(a, b) << endl;
    }

    return 0;
}