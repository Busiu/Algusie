// Source - https://leetcode.com/contest/biweekly-contest-176/
// Date - 2026-04-29

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string word : words) {
            if (word.size() < k) continue;
            m[word.substr(0, k)]++;
        }
        int ans = 0;
        for (auto [key, val] : m) {
            if (val > 1) ans++;
        }
        return ans;
    }
};