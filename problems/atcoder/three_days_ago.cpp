// Link - https://atcoder.jp/contests/abc295/tasks/abc295_d
// Source - https://usaco.guide/silver/intro-bitwise
// Date - 2026-02-09

#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    vector<int> occ(1 << 10); occ[0]++;
    ll ans = 0;
    int acc = 0;
    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';
        acc ^= (1 << d);
        ans += occ[acc]++;
    }

    cout << ans << endl;

    return 0;
}