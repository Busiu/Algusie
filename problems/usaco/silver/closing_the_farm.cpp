// Link - https://usaco.org/index.php?page=viewproblem2&cpid=644
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

    int n, m; cin >> n >> m;

    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> closed(n, false);
    for (int i = 0; i < n; i++) {
        int ctr = 0;
        for (int j = 0; j < n; j++) {
            if (closed[j]) continue;

            vector<bool> visited(n, false);
            queue<int> q;
            q.push(j);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                
                if (visited[cur]) continue;
                visited[cur] = true;
                ctr++;

                for (int nei : g[cur]) {
                    if (closed[nei]) continue;
                    q.push(nei);
                } 
            }
            break;
        }
        if (ctr == n - i) cout << "YES" << endl;
        else cout << "NO" << endl;

        int a; cin >> a; a--;
        closed[a] = true;
    }

    return 0;
}