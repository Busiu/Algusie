package java.graph;

import java.util.Arrays;

public class Kruskal {
    class DSU {
        int[] parents;
        int[] size;

        DSU (int n) {
            this.parents = new int[n];
            this.size = new int[n];
            for (int i = 0; i < n; i++) {
                parents[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            if (parents[x] != x) parents[x] = find(parents[x]);
            return parents[x];
        }

        boolean union(int x, int y) {
            var xParent = find(x);
            var yParent = find(y);

            if (xParent == yParent) return false;

            if (size[xParent] > size[yParent]) {
                parents[yParent] = xParent;
                size[xParent] += size[yParent];
            } else {
                parents[xParent] = yParent;
                size[yParent] += size[xParent];
            }

            return true;
        }
    }

    // Return Minimum Spanning Tree
    int[][] kruskal(int[][] edges, int n) {
        int[][] mst = new int[n - 1][3];
        int mstIdx = 0;

        var dsu = new DSU(n);
        Arrays.sort(edges, (e1, e2) -> {
            if (e1[2] > e2[2]) return 1;
            else if (e1[2] == e2[2]) return 0;
            return -1;
        });

        for (int[] edge : edges) {
            if (dsu.union(edge[0], edge[1])) {
                mst[mstIdx++] = edge;
                if (mstIdx == n - 1) break;
            }
        }

        return mst;
    }
}
