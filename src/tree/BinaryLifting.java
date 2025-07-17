package tree;

import java.util.ArrayList;

class BinaryLifting {
    int maxPower;
    int[] depth;
    long[] dist;
    int[][] up;
    ArrayList<ArrayList<int[]>> cons;

    BinaryLifting(int n, ArrayList<ArrayList<int[]>> cons) {
        this.maxPower = 0;
        while (1 << maxPower <= n) this.maxPower++;

        this.depth = new int[n];
        this.dist = new long[n];
        this.up = new int[n][maxPower];
        this.cons = cons;

        depth[0] = 0;
        dist[0] = 0;
        for (int i = 0; i < maxPower; i++) {
            up[0][i] = 0;
        }

        for (int[] child : cons.get(0)) {
            dfs(child[0], 0, child[1]);
        }
    }

    void dfs(int cur, int prev, int edgeLen) {
        depth[cur] = depth[prev] + 1;
        dist[cur] = dist[prev] + (long) edgeLen;
        up[cur][0] = prev;
        for (int i = 1; i < maxPower; i++) {
            up[cur][i] = up[up[cur][i - 1]][i - 1];
        }

        for (int[] child : cons.get(cur)) {
            if (child[0] == prev) continue;
            dfs(child[0], cur, child[1]);
        }
    }

    int lca(int node1, int node2) {
        if (depth[node1] < depth[node2]) {
            int tmp = node1;
            node1 = node2;
            node2 = tmp;
        }
        int diff = depth[node1] - depth[node2];
        for (int i = 0; i < maxPower; i++) {
            if ((diff & (1 << i)) > 0) {
                node1 = up[node1][i];
            }
        }

        if (node1 == node2) return node1;

        for (int i = maxPower - 1; i >= 0; i--) {
            if (up[node1][i] != up[node2][i]) {
                node1 = up[node1][i];
                node2 = up[node2][i];
            }
        }

        return up[node1][0];
    }
}