// Link - https://codeforces.com/problemset/problem/1514/C
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

    int n; cin >> n;

    ll product = 1;
    vector<int> ans;
    for (int i = 1; i < n; i++) {
        if (gcd(n, i) == 1) {
            product *= i;
            product %= n;
            ans.push_back(i);
        }
    }
    
    if (product == 1) {
        cout << ans.size() << endl;
        for (int val : ans) cout << val << " ";
    } else {
        cout << ans.size() - 1 << endl;
        for (int val : ans) if (val != product) cout << val << " ";
    }
    cout << endl;

    return 0;
}