// Link - https://usaco.org/index.php?page=viewproblem2&cpid=663
// Source - https://usaco.guide/bronze/rect-geo
// Date - 2026-02-02

#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct Rect {
    int x1, y1, x2, y2;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    int minX = min(a.x1, b.x1);
    int minY = min(a.y1, b.y1);
    int maxX = max(a.x2, b.x2);
    int maxY = max(a.y2, b.y2);
    int len = max(maxX - minX, maxY - minY);
    
    cout << len * len << endl;

    return 0;
}