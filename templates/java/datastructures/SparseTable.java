package java.datastructures;

// This is the implementation of MIN Sparse Tree
// Try to use it in: 3599, 3605

// 1. Calculate log[i], where i: [1, n (arr.length)]
// a. log[1] = 0, log[i] = log[i / 2] + 1
// 2. Create Lookup Table [n][log[n] + 1]
// a. First row is equal to arr
// b. lookup[i][j] = f(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]), where f is any idempotent function
// 3. Query
// a. Calculate intervalLen r - l + 1 and its log
// b. return f(lookup[l][j], lookup[r - (1 << j) + 1][j])

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

        this.lookup = new int[n][log[n] + 1];
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
