// Link - https://leetcode.com/problems/minimum-cost-path-with-teleportations/description/
// Source - https://leetcode.com/contest/biweekly-contest-163/
// Date - 2026-01-27

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define INF 2147483647
#define LL_INF 9223372036854775807

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int MOD = 1e9 + 7;

class Solution {
public:
    // dp[y][x][noTpsLeft] = min(grid[y + 1][x] + dp[y + 1][x][noTpsLeft], grid[y][x + 1] + dp[y][x + 1][noTpsLeft], WSZYSTKIE TEPEKI DOSTEPNE?)
    // tp mozliwe wszedzie, gdzie koszt jest mniejszy badz rowny

    // dp -> minCost to reach the target.
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1)));

        vector<pair<int, int>> points;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                points.push_back({y, x});
            }
        }

        sort(points.begin(), points.end(), [&](auto& a, auto& b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        });

        for (int t = 0; t <= k; t++) {
            vector<vector<int>> tp(m, vector<int>(n, INF / 4));
            
            // Precalculating TPs min values
            if (t > 0) {
                int curMinTp = INF / 2;
                for (int i = 0; i < points.size();) {                
                    int j = i;
                    while (j < points.size() && grid[points[i].first][points[i].second] == grid[points[j].first][points[j].second]) {
                        curMinTp = min(curMinTp, dp[points[j].first][points[j].second][t - 1]);
                        j++;
                    }
                    while (i < j) {
                        tp[points[i].first][points[i].second] = curMinTp;
                        i++;
                    }
                }
            }

            for (int y = m - 2; y >= 0; y--) {
                dp[y][n - 1][t] = min(dp[y + 1][n - 1][t] + grid[y + 1][n - 1], tp[y][n - 1]); 
            }
            for (int x = n - 2; x >= 0; x--) {
                dp[m - 1][x][t] = min(dp[m - 1][x + 1][t] + grid[m - 1][x + 1], tp[m - 1][x]); 
            }
            for (int y = m - 2; y >= 0; y--) {
                for (int x = n - 2; x >= 0; x--) {
                    dp[y][x][t] = min(min(dp[y + 1][x][t] + grid[y + 1][x], dp[y][x + 1][t] + grid[y][x + 1]), tp[y][x]);
                }
            }
        }

        return dp[0][0][k];
    }
};