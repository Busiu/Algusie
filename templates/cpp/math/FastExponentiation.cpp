#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MOD = 1e9 + 7;

ll fastPowRecursive(ll a, ll b) {
    if (b == 0) return 1;
    ll p = fastPowRecursive(a, b / 2);
    p = p * p % MOD;
    if (b % 2 == 1) p = p * a % MOD;
    return p;
}

ll fastPowIterative(ll a, ll b) {
    a %= MOD;
    ll ans = 1;
    ll f = a;
    while (b > 0) {
        if (b & 1) ans = ans * f % MOD;
        f = f * f % MOD;
        b >>= 1; 
    }
    return ans;
}