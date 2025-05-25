package math;

import java.util.ArrayList;
import java.util.List;

public class SieveOfEratosthenes {
    List<Integer> sieve(int n) {
        var notPrime = new boolean[n];
        for (int i = 2; i < n; i++) {
            if (notPrime[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                notPrime[j] = true;
            }
        }
        var result = new ArrayList<Integer>();
        for (int i = 2; i < n; i++) {
            if (!notPrime[i]) {
                result.add(i);
            }
        }
        return result;
    }
}
