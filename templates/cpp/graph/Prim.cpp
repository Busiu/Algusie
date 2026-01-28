#include <bits/stdc++.h>

using namespace std;

// Returns a length of longest edge from MST 
// Not tested :D 
int prim(int n, vector<vector<pair<int, int>>> g) {
    priority_queue<pair<int, int>> pq; // (-dist, idx)
    vector<bool> v(n);
    int ans = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top(); pq.pop();

        if (v[curNode]) continue;
        v[curNode] = true;
        ans = max(ans, -curDist);

        for (auto [nei, neiDist] : g[curNode]) {
            if (nei == curNode) continue;
            if (v[nei]) continue;
            pq.push({-neiDist, nei});
        }
    }
    return ans;
}