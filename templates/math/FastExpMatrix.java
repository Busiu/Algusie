package math;

public class FastExpMatrix {
    static final int MOD = 1_000_000_007;

    static long[][] mul(long[][] mat1, long[][] mat2) {
        var m = mat1.length;
        var n = mat1[0].length;
        var p = mat2[0].length;

        var result = new long[m][p];

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < p; x++) {
                var sum = 0L;
                for (int t = 0; t < n; t++) {
                    sum += mat1[y][t] * mat2[t][x];
                    sum %= MOD;
                }
                result[y][x] = sum;
            }
        }

        return result;
    }

    static long[][] fastExp(long[][] mat, int pow) {
        if (pow == 1) {
            return mat;
        }

        if (pow % 2 == 1) {
            return mul(mat, fastExp(mul(mat, mat), pow / 2));
        }
        return fastExp(mul(mat, mat), pow / 2);
    }
}
