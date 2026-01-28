// Link - https://usaco.org/index.php?page=viewproblem2&cpid=668
// Source - https://usaco.guide/silver/graph-traversal?lang=cpp
// Date - 2026-01-24

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

    vector<int> x(n);
    vector<int> y(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> p[i];

    vector<vector<int>> g(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int distSq = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            
            if (distSq <= p[i] * p[i]) g[i].push_back(j);
            if (distSq <= p[j] * p[j]) g[j].push_back(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(i);
        int noElems = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if (visited[cur]) continue;
            visited[cur] = true;
            noElems++;

            for (int nei : g[cur]) q.push(nei);
        }

        ans = max(ans, noElems);
    }

    cout << ans << endl;

    return 0;
}