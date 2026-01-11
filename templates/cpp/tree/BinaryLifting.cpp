#include <bits/stdc++.h>

using namespace std;

class BinaryLifting {
public:
    vector<vector<int>> cons;
    vector<int> tin;
    vector<int> tout;
    vector<vector<int>> up;
    int n;
    int log;
    int timer;

    BinaryLifting(vector<vector<int>>& _cons, int _n) {
        n = _n;
        cons = _cons;

        timer = 0;
        log = 1;
        while ((1 << log) <= n) log++;

        tin.assign(n, 0);
        tout.assign(n, 0);
        up.assign(n, vector<int>(log, -1));

        dfs(0, -1);
    }

    void dfs(int cur, int prev) {
        tin[cur] = timer++;
    
        up[cur][0] = prev;
        for (int i = 1; i < log; i++) {
            up[cur][i] = up[up[cur][i - 1]][i - 1];
        }

        for (int nei : cons[cur]) {
            if (nei == prev) continue;
            dfs(nei, cur);
        }
    
        tout[cur] = timer++;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int i = log - 1; i >= 0; i--) {
            if (!isAncestor(up[u][i], v)) {
                u = up[u][i];
            }
        }

        return up[u][0];
    }
};