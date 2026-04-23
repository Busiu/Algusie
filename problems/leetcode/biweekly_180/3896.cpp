// Source - https://leetcode.com/contest/biweekly-contest-180/
// Date - 2026-04-23

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
private:
    bool isPrime(int n) {
        if (n == 1) return false;

        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }

public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            int num = nums[i];
            while (!isPrime(num)) {
                num++;
                ans++;
            }
        }
        for (int i = 1; i < nums.size(); i += 2) {
            int num = nums[i];
            while (isPrime(num)) {
                num++;
                ans++;
            }
        }
        return ans;
    }
};