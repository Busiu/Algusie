#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(int maxNum) {
    vector<bool> isPrime(maxNum + 1, true);
    for (int i = 2; i < isPrime.size(); i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < isPrime.size(); j += i) {
            isPrime[j] = false;
        }
    }
    vector<int> ans;
    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) ans.push_back(i);
    }
    return ans;
}

int main() {
    int maxNum = 100;
    auto primes = sieve(maxNum);
    for (int p : primes) {
        cout << p << " ";
    }
}