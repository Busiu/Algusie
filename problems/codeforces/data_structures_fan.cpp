// Link - https://codeforces.com/contest/1872/problem/E
// Source - https://usaco.guide/silver/intro-bitwise
// Date - 2026-02-08

#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        string s; cin >> s;

        vector<int> xorPrefix(n);
        vector<int> xors(2);

        int acc = 0;
        for (int i = 0; i < n; i++) {
            acc ^= a[i];
            xorPrefix[i] = acc;
            xors[s[i] - '0'] ^= a[i];
        }

        int q; cin >> q;
        for (int i = 0; i < q; i++) {
            int type; cin >> type;
            if (type == 1) {
                int l, r; cin >> l >> r; l--; r--;
                int xorRange = xorPrefix[r] ^ (l > 0 ? xorPrefix[l - 1] : 0);
                xors[0] ^= xorRange; xors[1] ^= xorRange;
            } else {
                int g; cin >> g;
                cout << xors[g] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}