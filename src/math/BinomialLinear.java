package math;

public class BinomialLinear {
    int MOD = 1_000_000_007;
    int MAX = 100_010;

    static long[] fact;
    static long[] invFact;

    long fastPow(long n, long p) {
        if (p == 0) return 1;
        if (p == 1) return n;
        if (p % 2 == 1) return n * (fastPow(n * n % MOD, p / 2)) % MOD;
        return fastPow(n * n % MOD, p / 2) % MOD;
    }

    void prepare() {
        if (fact != null) return;

        fact = new long[MAX];
        invFact = new long[MAX];

        fact[0] = 1;
        for (int i = 1; i < MAX; i++) fact[i] = fact[i - 1] * i % MOD;
        invFact[MAX - 1] = fastPow(fact[MAX - 1], MOD - 2);
        for (int i = MAX - 2; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long mul(long a, long b) {
        return a * b % MOD;
    }

    long comb(int n, int k) {
        return mul(mul(fact[n], invFact[k]), invFact[n - k]);
    }

}
