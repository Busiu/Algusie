// Source - https://leetcode.com/contest/biweekly-contest-181/
// Date - 2026-04-27

#include <bits/stdc++.h>

#define ll long long
using namespace std;

// Removing odd nums -> good idea to save to Flashcards

class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> validNums;
        for (int num : nums) {
            if (num % 2 == 0) validNums.push_back(num);
        }

        for (int i = 0; i < queries.size(); i++) {
            auto& q = queries[i];            
            int l = lower_bound(validNums.begin(), validNums.end(), nums[q[0]]) - validNums.begin();
            int r = upper_bound(validNums.begin(), validNums.end(), nums[q[1]]) - validNums.begin() - 1;
            int k = q[2];

            if (l > r || 2 * k < validNums[l]) {
                ans.push_back(2 * k);
                continue;
            }


            int left = l, right = r;
            while (left < right) {
                int mid = right - (right - left) / 2;
                if (validNums[mid] / 2 - (mid - l + 1) < k) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }

            ans.push_back(validNums[left] + 2 * (k - (validNums[left] / 2 - (left - l + 1))));
        }

        return ans;
    }
};