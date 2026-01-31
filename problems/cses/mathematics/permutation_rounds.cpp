// Link - https://cses.fi/problemset/task/3398
// Source - https://usaco.guide/gold/divisibility
// Date - 2026-01-31

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
    vector<int> p(n);
    vector<bool> v(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;

    vector<int> sizesOfCycles;
    for (int i = 0; i < n; i++) {
        if (v[i]) continue;
        int curIdx = i, curSize = 0;
        while (!v[curIdx]) {
            v[curIdx] = true;
            curSize++;
            curIdx = p[curIdx];
        }
        sizesOfCycles.push_back(curSize);
    }

    map<int, int> mp;
    for (int num : sizesOfCycles) {
        for (int i = 2; i * i <= num; i++) {
            if (num % i != 0) continue;
            int noOcc = 0;
            while (num % i == 0) {
                noOcc++;
                num /= i;
            }
            if (mp.count(i) == 0) mp[i] = noOcc;
            else mp[i] = max(mp[i], noOcc);
        }
        if (num > 1) {
            if (mp.count(num) == 0) mp[num] = 1;
        }
    }

    ll ans = 1;
    for (auto [key, val] : mp) {
        for (int i = 0; i < val; i++) {
            ans *= key;
            ans %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}