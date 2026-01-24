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

    vector<int> representatives;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        representatives.push_back(i);
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if (visited[cur]) continue;
            visited[cur] = true;

            for (int nei : g[cur]) {
                q.push(nei);
            }
        }
    }

    cout << representatives.size() - 1 << endl;
    for (int i = 1; i < representatives.size(); i++) {
        cout << representatives[0] + 1 << " " << representatives[i] + 1 << endl;
    }

    return 0;
}