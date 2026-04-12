// Link - https://leetcode.com/problems/partition-array-into-k-distinct-groups/description/
// Source - https://leetcode.com/contest/weekly-contest-464/
// Date - 2026-04-05

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        int noGroups = nums.size() / k;
        
        unordered_map<int, int> numToOcc;
        int maxOcc = 0;
        for (int num : nums) {
            maxOcc = max(maxOcc, ++numToOcc[num]);
        }

        return maxOcc <= noGroups;
    }
};