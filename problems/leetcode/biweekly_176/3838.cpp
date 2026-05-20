// Source - https://leetcode.com/contest/biweekly-contest-176/
// Date - 2026-04-29

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (string& word : words) {
            int sum = 0;
            for (int ch : word) {
                sum += weights[ch - 'a'];
            }
            sum %= 26;
            ans += char (25 - sum + 'a');
        }
        return ans;
    }
};