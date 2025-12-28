package java.tree;

import java.util.ArrayList;

// 1. Find log
// 2. Calculate up, tin, tout using DFS. Start with dfs(root, root)
// 3. U is ancestor of V <==> tin[u] <= tin[v] && tout[u] >= tout[v]
// 4. Implement LCA
// a. Consider cases where u can be the ancestor of v and vice versa
// b. Otherwise - Calculate LCA using quasi Binary Search

public class BinaryLifting {
    int log;
    int n;
    int timer;
    ArrayList<ArrayList<Integer>> cons;
    int[] tin;
    int[] tout;
    int[][] up;

    BinaryLifting(int n, ArrayList<ArrayList<Integer>> cons) {
        this.n = n;
        this.cons = cons;

        log = 1;
        while ((1 << log) <= n) log++;

        timer = 0;
        tin = new int[n];
        tout = new int[n];

        up = new int[n][log];
        dfs(0, 0);
    }

    void dfs(int cur, int prev) {
        tin[cur] = ++timer;

        up[cur][0] = prev;
        for (int i = 1; i < log; i++) {
            up[cur][i] = up[up[cur][i - 1]][i - 1];
        }

        for (int nei : cons.get(cur)) {
            if (nei == prev) continue;
            dfs(nei, cur);
        }

        tout[cur] = ++timer;
    }

    boolean isAncestor(int u, int v) {
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
}
