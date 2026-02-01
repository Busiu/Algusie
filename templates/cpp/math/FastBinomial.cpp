#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 10;
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
    prep();

    cout << binomial(1000, 324) << endl;

    return 0;
}