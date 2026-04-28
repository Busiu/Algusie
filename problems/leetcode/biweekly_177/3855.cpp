// Source - https://leetcode.com/contest/biweekly-contest-177/
// Date - 2026-04-28

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
private: 
    int MOD = 1e9 + 7;

    ll fastPow(ll a, ll n) {
        if (n == 0) return 1;
        ll ans = fastPow((a * a) % MOD, n / 2);
        if (n % 2 == 0) return ans % MOD;
        return (a * ans) % MOD;
    }

public:
    int sumOfNumbers(int l, int r, int k) {
        ll sum = 0;
        for (int i = l; i <= r; i++) sum += i;
        
        sum = (sum * fastPow(r - l + 1, k - 1)) % MOD;
        ll pow = (fastPow(10, k) - 1 + MOD) % MOD;
        sum = (sum * pow) % MOD;
        sum = (sum * fastPow(9, MOD - 2)) % MOD;

        return (int) sum;
    }
};