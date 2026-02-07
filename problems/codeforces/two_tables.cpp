// Link - https://codeforces.com/contest/1555/problem/B
// Source - https://usaco.guide/bronze/rect-geo
// Date - 2026-02-03

#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct Rect {
	int x1, y1, x2, y2;
	void read() { cin >> x1 >> y1 >> x2 >> y2; }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int W, H; cin >> W >> H;
        Rect r; r.read();
        int w, h; cin >> w >> h;

        // Not moving first table at all
        if (r.y2 + h <= H || h <= r.y1 || r.x2 + w <= W || w <= r.x1) {
            cout << 0 << endl;
            continue;
        }

        // Moving first table in each direction
        int dist = INT_MAX;

        int toUp = max(h - r.y1, 0);
        if (r.y2 + toUp <= H) dist = min(dist, toUp);

        int toBottom = max(r.y2 - (H - h), 0);
        if (r.y1 - toBottom >= 0) dist = min(dist, toBottom);

        int toRight = max(w - r.x1, 0);
        if (r.x2 + toRight <= W) dist = min(dist, toRight);

        int toLeft = max(r.x2 - (W - w), 0);
        if (r.x1 - toLeft >= 0) dist = min(dist, toLeft);

        if (dist == INT_MAX) cout << -1 << endl;
        else cout << dist << endl;
    }

    return 0;
}