// Source - https://leetcode.com/contest/biweekly-contest-176/
// Date - 2026-04-29

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    ll rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<ll> dp(n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            if (i - 1 >= 0 && colors[i] != colors[i - 1]) dp[i] = max(dp[i], dp[i - 1] + nums[i]);
            if (i - 2 >= 0) dp[i] = max(dp[i], dp[i - 2] + nums[i]);
            if (i - 3 >= 0) dp[i] = max(dp[i], dp[i - 3] + nums[i]);
            
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};