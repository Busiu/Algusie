#include <bits/stdc++.h>

using namespace std;

int INF = 100;
vector<vector<int>> memo;
vector<vector<int>> dist;
int n;

int tsp(int curNode, int bitmask) {
    if (bitmask + 1 == 1 << n) return 0;

    if (memo[curNode][bitmask] != -1) return memo[curNode][bitmask];

    int ans = INF;
    for (int nei = 0; nei < n; nei++) {
        if ((1 << nei & bitmask) != 0) continue;
        ans = min(ans, tsp(nei, bitmask | 1 << nei) + dist[curNode][nei]);
    }

    return memo[curNode][bitmask] = ans;
}