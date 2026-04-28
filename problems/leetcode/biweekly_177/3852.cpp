// Source - https://leetcode.com/contest/biweekly-contest-177/
// Date - 2026-04-28

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<int> ans = {1000, 1000};
        for (auto& [x, xOcc] : freq) {
            for (auto& [y, yOcc] : freq) {
                if (y <= x || xOcc == yOcc) continue;
                if (x < ans[0] || (x == ans[0] && y < ans[1])) {
                    ans = {x, y};
                }
            }
        }

        if (ans[0] == 1000) return {-1, -1};
        return ans;
    }
};