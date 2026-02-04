// Link - https://codeforces.com/contest/1216/problem/C
// Source - https://usaco.guide/bronze/rect-geo
// Date - 2026-02-03

#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct Rect {
	ll x1, y1, x2, y2;
	void read() { cin >> x1 >> y1 >> x2 >> y2; }
    ll width() { return x2 - x1; }
	ll height() { return y2 - y1; }
	ll area() { return  width() * height(); }
};

ll interArea(const Rect& r1, const Rect& r2) {
    ll cW = max(0LL, min(r1.x2, r2.x2) - max(r1.x1, r2.x1));
    ll cH = max(0LL, min(r1.y2, r2.y2) - max(r1.y1, r2.y1));
    return cW * cH;
}

Rect interRect(Rect& r1, Rect& r2) {
    Rect rect{0,0,0,0};
    ll x1 = max(r1.x1, r2.x1), x2 = min(r1.x2, r2.x2);
    ll y1 = max(r1.y1, r2.y1), y2 = min(r1.y2, r2.y2);

    if (x1 < x2 && y1 < y2) rect = Rect{x1,y1,x2,y2};

    return rect;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Rect w, b1, b2;
    w.read();
    b1.read();
    b2.read();

    b1 = interRect(b1, w);
    b2 = interRect(b2, w);

    if (interArea(w, b1) + interArea(w, b2) - interArea(b1, b2) == w.area()) cout << "NO" << endl;
    else cout << "YES" << endl; 

    return 0;
}