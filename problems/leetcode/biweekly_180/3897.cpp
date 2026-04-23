// Source - https://leetcode.com/contest/biweekly-contest-180/
// Date - 2026-04-23

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;

public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int, int>> seg;
        int noOnes = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums0[i] == 0) noOnes += nums1[i];
            else seg.push_back({nums1[i], nums0[i]});
        }

        sort(seg.begin(), seg.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        string binS = string(noOnes, '1');
        for (auto s : seg) {
            binS += string(s.first, '1');
            binS += string(s.second, '0');
            cout << s.first << " " << s.second << endl;
        }

        ll ans = 0;
        ll acc = 1;
        for (int i = binS.size() - 1; i >= 0; i--) {
            cout << acc << endl;
            if (binS[i] == '1') {
                ans += acc;
                ans %= MOD;
            }
            acc <<= 1;
            acc %= MOD;
        }

        return (int) (ans % MOD);
    }
};