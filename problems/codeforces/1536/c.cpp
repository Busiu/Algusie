// Link - https://codeforces.com/problemset/problem/1536/C
// Source - https://usaco.guide/gold/divisibility
// Date - 2026-01-30

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int noK = 0, noD = 0;
        map<pair<int, int>, int> mp; 
        for (int i = 0; i < n; i++) {
            char ch; cin >> ch;
            if (ch == 'D') noD++;
            else noK++;
            int g = gcd(noK, noD);
            cout << ++mp[{noK / g, noD / g}] << " ";
        }
        cout << endl;
    }

    return 0;
}