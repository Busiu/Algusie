// Link - https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/
// Source - https://leetcode.com/contest/weekly-contest-464/
// Date - 2026-04-05

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for (int i = 1; i <= n; i++) {
            odd += 2 * i - 1;
            even += 2 * i;
        }
        return gcd(odd, even);
    }
};