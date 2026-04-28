// Source - https://leetcode.com/contest/biweekly-contest-177/
// Date - 2026-04-28

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
private: 
    vector<int> oddStart(vector<int>& nums) {
        vector<int> toChange;
        vector<int> notToChange;
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) % 2 == i % 2) {
                toChange.push_back(nums[i]);
            } else {
                notToChange.push_back(nums[i]);
            }
        }
        sort(toChange.begin(), toChange.end());
        sort(notToChange.begin(), notToChange.end());

        int maxToChange = -2e9;
        int minToChange = 2e9;
        int maxNotToChange = -2e9;
        int minNotToChange = 2e9;

        if (!toChange.empty()) {
            maxToChange = toChange[toChange.size() - 1] - 1;
            minToChange = toChange[0] + 1;
        }
        if (!notToChange.empty()) {
            maxNotToChange = notToChange[notToChange.size() - 1];
            minNotToChange = notToChange[0];
        }

        int minDiff = max(max(maxToChange, maxNotToChange) - min(minToChange, minNotToChange), 1);
        
        return {(int)toChange.size(), minDiff};
    }

    vector<int> evenStart(vector<int>& nums) {
        vector<int> toChange;
        vector<int> notToChange;
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) % 2 != i % 2) {
                toChange.push_back(nums[i]);
            } else {
                notToChange.push_back(nums[i]);
            }
        }
        sort(toChange.begin(), toChange.end());
        sort(notToChange.begin(), notToChange.end());

        int maxToChange = -2e9;
        int minToChange = 2e9;
        int maxNotToChange = -2e9;
        int minNotToChange = 2e9;

        if (!toChange.empty()) {
            maxToChange = toChange[toChange.size() - 1] - 1;
            minToChange = toChange[0] + 1;
        }
        if (!notToChange.empty()) {
            maxNotToChange = notToChange[notToChange.size() - 1];
            minNotToChange = notToChange[0];
        }

        int minDiff = max(max(maxToChange, maxNotToChange) - min(minToChange, minNotToChange), 1);
        
        return {(int)toChange.size(), minDiff};
    }

public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        if (nums.size() == 1) return {0, 0};

        vector<int> oddRes = oddStart(nums);
        vector<int> evenRes = evenStart(nums);
        
        if (oddRes[0] < evenRes[0]) return oddRes;
        else if (oddRes[0] > evenRes[0]) return evenRes;
        return {oddRes[0], min(oddRes[1], evenRes[1])};
    }
};