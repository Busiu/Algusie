// Link - https://kilonova.ro/problems/127
// Source - https://usaco.guide/gold/modular
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

ll fastPow(ll a, ll b, ll mod) {
    a %= mod;
    ll ans = 1;
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

    ifstream fin("sumdiv.in");
    ll A, B; fin >> A >> B;
    // ll A, B; cin >> A >> B;

    map<ll, int> f;
    for (ll i = 2; i * i <= A; i++) {
        if (A % i != 0) continue;
        int noOcc = 0;
        while (A % i == 0) {
            noOcc++;
            A /= i;
        }
        f[i] = noOcc;
    }
    if (A > 1) f[A] = 1;

    // for (auto[p, a] : f) {
    //     cout << p << ": " << a << endl;
    // }
    
    ll ans = 1;
    for (auto& [p, a] : f) {
        if ((p - 1) % MOD == 0) {
            // We cannot use modulo inverse, but this case is easy to calculate due to p === 1 mod 1e9 + 7
            ans = ans * (a * (B + 1) % MOD) % MOD;
        } else {
            ll pow = (a * (B % (MOD - 1)) + 1) % (MOD - 1);
            ll up = fastPow(p, pow, MOD);
            up = (up - 1 + MOD) % MOD;
            up = up * fastPow(p - 1, MOD - 2, MOD) % MOD;
            ans = ans * up % MOD;
        }
    }

	ofstream fout("sumdiv.out");
    fout << ans << endl;
    // cout << ans << endl;

    return 0;
}