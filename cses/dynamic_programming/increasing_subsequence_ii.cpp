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

struct FenwickTree {
    int len;
    vector<ll> fenTree;

    FenwickTree(int len) : len(len + 1) {
        fenTree = vector<ll>(len + 1);
    }

    void add(int idx, int val) {
        idx++;
        while(idx < len) {
            fenTree[idx] += val;
            fenTree[idx] %= MOD;
            idx += (idx & -idx);
        }
    }

    ll query(int idx) {
        idx++;
        ll sum = 0;
        while (idx > 0) {
            sum += fenTree[idx];
            idx -= (idx & -idx);
        }
        return sum % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> uniq = arr;
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

    for (int i = 0; i < n; i++) arr[i] = lower_bound(uniq.begin(), uniq.end(), arr[i]) - uniq.begin();

    FenwickTree ft(uniq.size());

    ll sum = 0;

    for (int a : arr) {
        ll cur = 1;
        cur += ft.query(a - 1);
        ft.add(a, cur);
        sum += cur;
    }

    cout << sum % MOD << endl;

    return 0;
}