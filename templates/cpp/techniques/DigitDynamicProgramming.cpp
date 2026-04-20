// Based on https://leetcode.com/problems/count-of-integers/description/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;

    ll dp[23][2][300];
    int minSum;
    int maxSum;

    ll ddp(string& num, int idx, bool tight, int curSum) {
        if (idx == num.size()) {
            return minSum <= curSum && curSum <= maxSum;
        }

        if (dp[idx][tight][curSum] != -1) return dp[idx][tight][curSum];

        ll ans = 0;
        int limit = tight ? num[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);
            ans += ddp(num, idx + 1, newTight, curSum + d);
        }
        ans %= MOD;
        
        return dp[idx][tight][curSum] = ans;
    }

    int digitCount(string& s) {
        int ans = 0;
        for (char ch : s) ans += ch - '0';
        return ans;
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        minSum = min_sum;
        maxSum = max_sum;

        memset(dp, -1, sizeof(dp));
        ll a = ddp(num1, 0, true, 0);

        memset(dp, -1, sizeof(dp));
        ll b = ddp(num2, 0, true, 0);

        ll ans = 0;
        int dc = digitCount(num1);
        if (minSum <= dc && dc <= maxSum) {
            ans = (b - a + 2 * MOD + 1) % MOD;
        } else {
            ans = (b - a + 2 * MOD) % MOD;
        }

        return (int) ans;
    }
};