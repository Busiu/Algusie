// Link - https://usaco.org/index.php?page=viewproblem2&cpid=992
// Source - https://usaco.guide/silver/graph-traversal
// Date - 2026-01-28
// TODO: Analyze other solutions. Create a flashcard.

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

// iter through cows. For each misplaces cow -> try to move it to correct place.
// How to find the path using the smallest possible wormholes? BS + BFS/DFS sounds good. Overall complexity -> O(N^2 * LOG(10^9))
// We can make it better. Let's use DSU. 

struct DSU {
    vector<int> parents;
    vector<int> rank;

    DSU(int size) {
        parents.assign(size, 0);
        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }
        rank.assign(size, 1);
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    bool union_sets(int x, int y) {
        int xParent = find(x), yParent = find(y);
        if (xParent == yParent) return false;

        if (rank[xParent] > rank[yParent]) {
            parents[yParent] = xParent;
            rank[xParent] += rank[yParent];
        } else {
            parents[xParent] = yParent;
            rank[yParent] += rank[xParent];
        }
        return true;
    }

    bool areConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        int c; cin >> c; c--;
        cows[i] = c;
    }

    vector<tuple<int, int, int>> wormholes(m);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w; a--; b--;
        wormholes[i] = {a, b, w};
    }

    sort(wormholes.begin(), wormholes.end(), [](auto& a, auto& b) {
        return get<2>(a) < get<2>(b);
    });

    DSU dsu(n);
    int ans = -1;
    int wIdx = m - 1;
    for (int i = 0; i < n; i++) {
        if (cows[i] == i) continue;
        while (!dsu.areConnected(cows[i], i)) {
            int a = get<0>(wormholes[wIdx]); int b = get<1>(wormholes[wIdx]);
            ans = get<2>(wormholes[wIdx]);
            wIdx--;
            dsu.union_sets(a, b);
        }
    }

    cout << ans << endl;

    return 0;
}