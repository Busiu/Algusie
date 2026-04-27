// Source - https://leetcode.com/contest/biweekly-contest-179/
// Date - 2026-04-24

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> paths(m, vector<vector<int>>(n));
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1024)));
        paths[0][0].push_back(grid[0][0]);
        visited[0][0][grid[0][0]] = true;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (col > 0) {
                    for (int val : paths[row][col - 1]) {
                        int newVal = grid[row][col] ^ val;
                        if (visited[row][col][newVal]) continue;
                        visited[row][col][newVal] = true;
                        paths[row][col].push_back(newVal);
                    }
                }
                if (row > 0) {
                    for (int val : paths[row - 1][col]) {
                        int newVal = grid[row][col] ^ val;
                        if (visited[row][col][newVal]) continue;
                        visited[row][col][newVal] = true;
                        paths[row][col].push_back(newVal);
                    }
                }
            }
        }
        
        int ans = 2000;
        for (int val : paths[m - 1][n - 1]) ans = min(ans, val);
        return ans;
    }
};