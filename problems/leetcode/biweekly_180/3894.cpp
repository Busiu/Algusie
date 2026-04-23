// Source - https://leetcode.com/contest/biweekly-contest-180/
// Date - 2026-04-23

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0) return "Green";
        if (timer == 30) return "Orange";
        if (30 < timer && timer <= 90) return "Red";
        return "Invalid"; 
    }
};