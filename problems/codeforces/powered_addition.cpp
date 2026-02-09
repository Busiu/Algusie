// Link - https://codeforces.com/contest/1338/problem/A
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

        int maxDiff = 0;
        int curMax = a[0];
        for (int val : a) {
            maxDiff = max(maxDiff, curMax - val);
            curMax = max(curMax, val);
        }

        int ans = 0;
        while (maxDiff > 0) {
            ans++;
            maxDiff >>= 1;
        }

        cout << ans << endl;
    }

    return 0;
}