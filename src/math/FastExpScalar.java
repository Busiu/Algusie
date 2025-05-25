package algos.math;

public class FastExpScalar {
    static final int MOD = 1_000_000_007;

    static long fastExp(int base, int power) {
        var result = 1L;
        long tmp = base;
        while (power > 0) {
            if (power % 2 == 1) {
                result *= tmp;
                result %= MOD;
            }
            tmp *= tmp;
            tmp %= MOD;
            power /= 2;
        }

        return result;
    }
}
