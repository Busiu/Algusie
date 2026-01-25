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
    
    vector<int> cowsX(n);
    vector<int> cowsY(n);

    for (int i = 0; i < n; i++) {
        cin >> cowsX[i] >> cowsY[i];
    }

    vector<vector<int>> g(n);
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> visited(n);
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int minX = INF, maxX = -1;
        int minY = INF, maxY = -1;

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (visited[cur]) continue;
            visited[cur] = true;

            minX = min(minX, cowsX[cur]);
            minY = min(minY, cowsY[cur]);
            maxX = max(maxX, cowsX[cur]);
            maxY = max(maxY, cowsY[cur]);

            for (int nei : g[cur]) {
                q.push(nei);
            }
        }

        ans = min(ans, 2 * (maxX - minX + maxY - minY));
    }

    cout << ans << endl;

    return 0;
}