// Source - https://leetcode.com/contest/biweekly-contest-179/
// Date - 2026-04-24

#include <bits/stdc++.h>

#define ll long long
using namespace std;

// state - (idx, curNum) -> 1000 * 5000
// (idx, curNum) = (idx + 1, curNum) + (idx + 1, curNum + 1) + (idx + 1, curNum + 2) + ... + (idx + 1, 5000), so:
// (idx, curNum) = (idx, curNum + 1) + (idx + 1, curNum)

// type 0 -> we consider curNum DigitSum
// type 1 -> otherwise

class Solution {
private:
    static const int MOD = 1e9 + 7;
    static const int MAX = 5000;

    bool initialized = false;
    vector<int> numToDigSum;
    vector<vector<ll>> memo;

    ll dp(vector<int>& digitSum, int i, int curNum) {
        if (i == digitSum.size()) return 1;
        if (curNum > MAX) return 0;

        if (memo[i][curNum] != -1) return memo[i][curNum];

        ll ans = 0;
        if (numToDigSum[curNum] == digitSum[i]) ans += dp(digitSum, i + 1, curNum);
        ans += dp(digitSum, i, curNum + 1);
        ans %= MOD;

        return memo[i][curNum]= ans;
    }

public:
    int countArrays(vector<int>& digitSum) {
        if (!initialized) {
            initialized = true;
            numToDigSum.assign(MAX + 1, -1);
            for (int i = 0; i <= MAX; i++) {
                int sum = 0, num = i;
                while (num > 0) {
                    sum += num % 10;
                    num /= 10;
                }
                numToDigSum[i] = sum;
            }
        }

        memo.assign(digitSum.size(), vector<ll>(MAX + 1, -1));
        return (int) (dp(digitSum, 0, 0) % MOD);
    }
};