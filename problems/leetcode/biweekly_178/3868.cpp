// Source - https://leetcode.com/contest/biweekly-contest-178/
// Date - 2026-04-28

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1;
        unordered_map<int, int> freqAll;

        for (int num : nums1) {
            freq1[num]++;
            freqAll[num]++;
        }
        for (int num : nums2) {
            freqAll[num]++;
        }

        int cost = 0;
        for (auto& [val, occ] : freqAll) {
            if (occ % 2 == 1) return -1;
            cost += abs(occ / 2 - freq1[val]);
        }

        return cost >> 1;
    }
};