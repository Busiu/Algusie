// Link - https://codeforces.com/contest/1225/problem/D
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

    int n, k; cin >> n >> k;
    
    unordered_map<string, int> needToOcc;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        string need = "";
        string it = "";
        for (int j = 2; j * j <= a; j++) {
            int noOcc = 0;
            while (a % j == 0) {
                noOcc++;
                a /= j;
            }
            if (noOcc % k != 0) {
                need += to_string(j) + "-" + to_string(k - (noOcc % k)) + ".";
                it += to_string(j) + "-" + to_string(noOcc % k) + ".";
            }
        }
        if (a > 1) {
            need += to_string(a) + "-" + to_string(k - 1) + ".";
            it += to_string(a) + "-" + to_string(1) + ".";
        }
        if (needToOcc.count(need) > 0) {
            ans += needToOcc[need];
        }
        needToOcc[it]++;
    }

    cout << ans << endl;

    return 0;
}