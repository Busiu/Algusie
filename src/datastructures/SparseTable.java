package datastructures;

// This is the implementation of MIN Sparse Tree
// Try to use it in: 3599, 3605
public class SparseTable {
    int n;
    int[] arr;
    int[] log;
    int[][] lookup;

    SparseTable(int[] arr) {
        this.n = arr.length;
        this.arr = arr;
        build();
    }

    void build() {
        this.log = new int[n + 1];
        log[1] = 0;
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }

        // Do I really need n + 1 here?
        this.lookup = new int[n + 1][log[n] + 1];
        for (int i = 0; i < n; i++) {
            lookup[i][0] = arr[i];
        }
        for (int j = 1; j <= log[n]; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                lookup[i][j] = Math.min(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int intervalLen = r - l + 1;
        int j = log[intervalLen];
        return Math.min(lookup[l][j], lookup[r - (1 << j) + 1][j]);
    }
}
