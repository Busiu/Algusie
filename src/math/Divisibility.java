package math;

public class Divisibility {
    long gcd(long a, long b) {
        if (a < b) {
            var tmp = a;
            a = b;
            b = tmp;
        }
        while (b > 0) {
            a -= (a / b) * b;
            var tmp = a;
            a = b;
            b = tmp;
        }

        return a;
    }

    long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }
}
