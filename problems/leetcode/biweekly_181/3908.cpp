// Source - https://leetcode.com/contest/biweekly-contest-181/
// Date - 2026-04-27

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {

        int curDigit = -1;
        bool contains = false;
        while (n > 0) {
            curDigit = n % 10;
            if (curDigit == x) contains = true;
            n /= 10;
        }
        
        return contains && curDigit != x;
    }
};