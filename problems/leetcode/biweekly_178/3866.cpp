// Source - https://leetcode.com/contest/biweekly-contest-178/
// Date - 2026-04-28

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        for (int num : nums) {
            if (num % 2 == 0 && freq[num] == 1) return num;
        }

        return -1;
    }
};