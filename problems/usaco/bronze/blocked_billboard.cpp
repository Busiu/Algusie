// Link - https://usaco.org/index.php?page=viewproblem2&cpid=759
// Source - https://usaco.guide/bronze/rect-geo
// Date - 2026-02-02

#include <bits/stdc++.h>

#define ll long long
using namespace std;


struct Rect {
    int x1, y1, x2, y2;
};

int intersectionArea(Rect& r1, Rect& r2) {
    int cW = max(min(r1.x2, r2.x2) - max(r1.x1, r2.x1), 0);
    int cH = max(min(r1.y2, r2.y2) - max(r1.y1, r2.y1), 0);
    return cW * cH;
}

int area(Rect& r) {
    int w = r.x2 - r.x1;
    int h = r.y2 - r.y1;
    return w * h;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Rect b1, b2, t;

    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    cout << area(b1) + area(b2) - intersectionArea(b1, t) - intersectionArea(b2, t) << endl;

    return 0;
}