// Link - https://cses.fi/problemset/task/1682
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

bool traverse(int n, vector<vector<int>>& g, bool isOut) {
    queue<int> q;
    q.push(0);
    vector<bool> v(n);
    int noVisited = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (v[cur]) continue;
        v[cur] = true;
        noVisited++;

        for (int nei : g[cur]) q.push(nei);
    }

    if (noVisited != n) {
        cout << "NO" << endl;
        int a = -1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                a = i;
                break;
            }
        }
        if (isOut) cout << "1 " << a + 1 << endl;
        else cout << a + 1 << " 1" << endl;
        return false;  
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> gOut(n);
    vector<vector<int>> gIn(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;    
        gOut[a].push_back(b);
        gIn[b].push_back(a);
    }

    bool res = traverse(n, gOut, true);
    if (!res) return 0;
    res = traverse(n, gIn, false);
    if (!res) return 0;

    cout << "YES" << endl;
    return 0;
}