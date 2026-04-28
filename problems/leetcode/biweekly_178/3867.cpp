// Source - https://leetcode.com/contest/biweekly-contest-178/
// Date - 2026-04-28

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    ll gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int curMax = -1;
        for (int i = 0; i < n; i++) {
            curMax = max(curMax, nums[i]);
            prefixGcd[i] = gcd(nums[i], curMax);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        ll ans = 0;
        for (int i = 0; i < n / 2; i++) ans += gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        return ans;
    }
};