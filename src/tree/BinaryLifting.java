package tree;

public class BinaryLifting {
    int log;
    int[][] up;

    // Assuming parents[0] = -1;
    // Otherwise -> add sentinel node : parents[root] = n + 1. If any query returns n + 1 -> we have exceeded the top.
    BinaryLifting(int n, int[] parents) {
        log = 0;
        while (1 << log <= n) log++;

        this.up = new int[n][log];
        for (int i = 0; i < n; i++) {
            up[i][0] = parents[i];
        }
        for (int lvl = 1; lvl < log; lvl++) {
            for (int i = 0; i < n; i++) {
                int anc = up[i][lvl - 1];
                if (anc == -1) up[i][lvl] = -1;
                else up[i][lvl] = up[up[i][lvl - 1]][lvl - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int anc = node;
        for (int i = 0; i < log; i++) {
            if ((k & (1 << i)) > 0) {
                anc = up[anc][i];
            }
        }
        return anc;
    }
}
