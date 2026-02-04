// Link - https://usaco.org/index.php?page=viewproblem2&cpid=783
// Source - https://usaco.guide/bronze/rect-geo
// Date - 2026-02-03

#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct Rect {
	int x1, y1, x2, y2;
	void read() { cin >> x1 >> y1 >> x2 >> y2; }
    int width() { return x2 - x1; }
	int height() { return y2 - y1; }
	int area() { return  width() * height(); }
};

pair<int,int> interXY(Rect& r1, Rect& r2) {
    int cW = max(min(r1.x2, r2.x2) - max(r1.x1, r2.x1), 0);
    int cH = max(min(r1.y2, r2.y2) - max(r1.y1, r2.y1), 0); 
    return {cW, cH};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Rect a, b;
    a.read();
    b.read();

    auto c = interXY(a, b);
    if (c.first < a.width() && c.second < a.height()) cout << a.area() << endl;
    else if (c.first == a.width() && a.y1 < b.y1 && b.y2 < a.y2) cout << a.area() << endl;
    else if (c.second == a.height() && a.x1 < b.x1 && b.x2 < a.x2) cout << a.area() << endl;
    else cout << a.area() - c.first * c.second << endl;

    return 0;
}