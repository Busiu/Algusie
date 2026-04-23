// Source - https://leetcode.com/contest/biweekly-contest-180/
// Date - 2026-04-23

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for (int num : nums) {
            while (num > 0) {
                int curDigit = num % 10;
                if (curDigit == digit) ans++;
                num /= 10;
            }
        }
        return ans;
    }
};