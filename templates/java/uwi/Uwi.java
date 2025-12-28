package java.uwi;

import java.util.Arrays;

public class Uwi {
    // Tree representation of graph - used in Weekly 426, 3373
    public static int[][] packU(int n, int[][] ft)
    {
        int[][] g = new int[n][];
        int[] p = new int[n];
        for(int[] u : ft){
            p[u[0]]++; p[u[1]]++;
        }
        for(int i = 0;i < n;i++)g[i] = new int[p[i]];
        for(int[] u : ft){
            g[u[0]][--p[u[0]]] = u[1];
            g[u[1]][--p[u[1]]] = u[0];
        }
        return g;
    }

    // Get parents, bfs traversed and depth of all nodes - used in Weekly 426, 3373
    public static int[][] parents(int[][] g, int root) {
        int n = g.length;
        int[] par = new int[n];
        Arrays.fill(par, -1);

        int[] depth = new int[n];
        depth[0] = 0;

        int[] q = new int[n];
        q[0] = root;
        for (int p = 0, r = 1; p < r; p++) {
            int cur = q[p];
            for (int nex : g[cur]) {
                if (par[cur] != nex) {
                    q[r++] = nex;
                    par[nex] = cur;
                    depth[nex] = depth[cur] + 1;
                }
            }
        }
        return new int[][]{par, q, depth};
    }

    // Get sorted count of unique elements
    public int[][] uniqcount(int[] a)
    {
        int n = a.length;
        int p = 0;
        int[][] b = new int[n][];
        for(int i = 0;i < n;i++){
            if(i == 0 || a[i] != a[i-1])b[p++] = new int[]{a[i], 0};
            b[p-1][1]++;
        }
        return Arrays.copyOf(b, p);
    }
}
