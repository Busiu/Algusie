// Source - https://leetcode.com/contest/biweekly-contest-181/
// Date - 2026-04-27

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int maxIdx = 0;
        for (int i = 1; i < nums.size(); i++) if (nums[i] > nums[maxIdx]) maxIdx = i;

        ll left = 0;
        ll right = 0;
        for (int i = 0; i <= maxIdx; i++) left += nums[i];
        for (int i = maxIdx; i < nums.size(); i++) right += nums[i];

        if (left > right) return 0;
        if (left < right) return 1;
        return -1;
    }
};