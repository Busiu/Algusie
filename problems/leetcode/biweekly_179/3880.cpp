// Source - https://leetcode.com/contest/biweekly-contest-179/
// Date - 2026-04-24

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = 500;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == 1 && nums[j] == 2) {
                    ans = min(ans, abs(i - j));
                }
            }
        } 
        return ans != 500 ? ans : -1;
    }
};