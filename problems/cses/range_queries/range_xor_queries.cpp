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

    int n, q; cin >> n >> q;
    vector<int> p(n);
    int acc = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        acc ^= x;
        p[i] = acc;
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        ll res = p[b] ^ ((a > 0) ? p[a - 1] : 0);
        cout << res << endl;
    }

    return 0;
}