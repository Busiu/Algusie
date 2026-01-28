// Link - https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/
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
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], 2 * e[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<bool> visited(n);

        while (!pq.empty()) {
            auto [curDist, curNode] = pq.top(); pq.pop();

            if (visited[curNode]) continue;
            visited[curNode] = true;

            if (curNode == n - 1) return curDist;

            for (auto& [nei, dist] : g[curNode]) {
                pq.push({curDist + dist, nei});

            }
        }

        return -1;
    }
};