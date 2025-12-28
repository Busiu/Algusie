package java.math;

public class Divisibility {
    long gcd(long a, long b) {
        if (a < b) {
            var tmp = a;
            a = b;
            b = tmp;
        }
        while (b > 0) {
            a %= b;
            var tmp = a;
            a = b;
            b = tmp;
        }

        return a;
    }

    long recursiveGcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }
}
