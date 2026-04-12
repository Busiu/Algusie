// Link - https://leetcode.com/problems/jump-game-ix/description/
// Source - https://leetcode.com/contest/weekly-contest-464/
// Date - 2026-04-05

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nu) {
        int n = nu.size();
        vector<int> smallerFarestIdx(n);

        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = {nu[i], i};
        }
        sort(nums.begin(), nums.end());

        int farest = 0;
        for (auto [num, i] : nums) {
            farest = max(farest, i);
            smallerFarestIdx[i] = farest;
        }

        int prev = 0;
        int curMax = 0;
        int curFar = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            curMax = max(curMax, nu[i]);
            curFar = max(curFar, smallerFarestIdx[i]);
            if (curFar == i) {
                for (int j = prev; j <= i; j++) {
                    ans[j] = curMax;
                }
                prev = i + 1;
            }
        }
        
        return ans;
    }
};