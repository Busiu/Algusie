// Source - https://leetcode.com/contest/biweekly-contest-177/
// Date - 2026-04-28

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    string mergeCharacters(string s, int k) {
        vector<int> lastOcc(26, -1);
        string ans = "";
        vector<int> removedIdxs;

        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            if (lastOcc[ch] != -1) {
                int l = lower_bound(removedIdxs.begin(), removedIdxs.end(), lastOcc[ch]) - removedIdxs.begin();
                int noRemoved = removedIdxs.size() - l;
                if (i - lastOcc[ch] - noRemoved <= k) {
                    removedIdxs.push_back(i);
                    continue;
                }
            }
            ans += s[i];
            lastOcc[ch] = i;
        }
        
        return ans;
    }
};