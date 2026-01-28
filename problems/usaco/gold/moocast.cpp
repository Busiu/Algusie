// Link - https://usaco.org/index.php?page=viewproblem2&cpid=669
// Source - https://usaco.guide/silver/graph-traversal
// Date - 2026-01-28

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

    vector<int> cowsX(n);
    vector<int> cowsY(n);

    for (int i = 0; i < n; i++) {
        cin >> cowsX[i] >> cowsY[i];
    } 

    priority_queue<pair<int, int>> pq; // (-dist, idx)
    vector<bool> v(n);
    int ans = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top(); pq.pop();

        if (v[curNode]) continue;
        v[curNode] = true;
        ans = max(ans, -curDist);

        for (int nei = 0; nei < n; nei++) {
            if (nei == curNode) continue;
            if (v[nei]) continue;
            int xDiff = cowsX[curNode] - cowsX[nei];
            int yDiff = cowsY[curNode] - cowsY[nei];
            int neiDist = xDiff * xDiff + yDiff * yDiff;
            pq.push({-neiDist, nei});
        }
    }

    cout << ans << endl;

    return 0;
}