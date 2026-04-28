// Source - https://leetcode.com/contest/biweekly-contest-181/
// Date - 2026-04-27

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int allMask = (1 << n) - 1;
        int ans = 0;
        vector<vector<int>> g;
        vector<bool> v;

        for (int bMask = 1; bMask < (1 << n); bMask++) {
            g.assign(n, vector<int>());
            for (auto& e : edges) {
                if ((((1 << e[0]) & bMask) > 0) && (((1 << e[1]) & bMask) > 0)) {
                    g[e[0]].push_back(e[1]);
                    g[e[1]].push_back(e[0]);
                }
            }

            int curSum = 0;
            int noParts = 0;
            v.assign(n, false);

            for (int i = 0; i < n; i++) {
                if (v[i] || (((1 << i) & bMask) == 0)) continue;

                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int curNode = q.front(); q.pop();
                    
                    if (v[curNode]) continue;
                    v[curNode] = true;

                    curSum += nums[curNode];

                    for (int nei : g[curNode]) {
                        q.push(nei);
                    }
                }

                noParts++;
            }

            if (noParts == 1 && curSum % 2 == 0) ans++;
        }

        return ans;
    }
};