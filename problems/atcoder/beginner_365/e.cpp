// Link - https://atcoder.jp/contests/abc365/tasks/abc365_e
// Source - https://usaco.guide/silver/intro-bitwise
// Date - 2026-02-07

#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < 30; i++) {
        ll noOnes = 0, noZeros = 0;

        if ((a[n - 1] >> i) & 1) noOnes++;
        else noZeros++;

        for (int j = n - 2; j >= 0; j--) {
            int curBit = (a[j] >> i) & 1;
            if (curBit) {
                ans += noZeros * (1 << i);
                swap(noOnes, noZeros);
            } else {
                ans += noOnes * (1 << i);
            }

            if ((a[j] >> i) & 1) noOnes++;
            else noZeros++;
        } 
    }

    cout << ans << endl;

    return 0;
}