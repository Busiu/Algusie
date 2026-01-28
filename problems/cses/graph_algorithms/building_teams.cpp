// Link - https://cses.fi/problemset/task/1668
// Date - 2026-01-23

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

    vector<int> state(n, 0);

    for (int i = 0; i < n; i++) {
        if (state[i] > 0) continue;

        queue<pair<int, int>> q;
        q.push({i, 0});

        while (!q.empty()) {
            auto [cur, dist] = q.front();
            q.pop();

            if (state[cur] > 0) {
                if (state[cur] != (dist % 2) + 1) {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
                else continue;
            }
            state[cur] = dist % 2 + 1;

            for (int nei : g[cur]) {
                q.push({nei, dist + 1});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << state[i] << " ";
    }
    cout << endl;

    return 0;
}