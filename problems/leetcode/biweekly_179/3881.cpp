// Source - https://leetcode.com/contest/biweekly-contest-179/
// Date - 2026-04-24

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;

    ll fastPow(ll a, ll n) {
        if (n == 0) return 1;
        ll ans = fastPow((a * a) % MOD, n / 2);
        if (n % 2 == 0) return ans;
        return (ans * a) % MOD;
    }


public:
    int countVisiblePeople(int n, int pos, int k) {
        vector<ll> fact(n);

        fact[0] = 1;
        for (int i = 1; i < n; i++) fact[i] = (fact[i - 1] * i) % MOD;

        ll ans = ((fact[n - 1] * fastPow(fact[k], MOD - 2)) % MOD * fastPow(fact[n - 1 - k], MOD - 2)) % MOD;
        ans <<= 1;
        ans %= MOD;

        return ans;
    }
};