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
        ll y, x; cin >> y >> x; y--; x--;
        ll block = max(y, x);
        if (block % 2 == 0) {
            if (y == block) cout << y * y + x + 1 << endl;
            else cout << (x + 1) * (x + 1) - y << endl;
        } else {
            if (x == block) cout << x * x + y + 1 << endl;
            else cout << (y + 1) * (y + 1) - x << endl;
        }
    }

    return 0;
}