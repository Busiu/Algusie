#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Rect {
	int x1, y1, x2, y2;
	void read() { cin >> x1 >> y1 >> x2 >> y2; }
    int width() { return x2 - x1; }
	int height() { return y2 - y1; }
	int area() { return  width() * height(); }
	bool isPointInside(int x, int y) { return x1 <= x && x <= x2 && y1 <= y && y <= y2; }
};

int interArea(Rect& r1, Rect& r2) {
    int cW = max(0, min(r1.x2, r2.x2) - max(r1.x1, r2.x1));
    int cH = max(0, min(r1.y2, r2.y2) - max(r1.y1, r2.y1));
    return cW * cH;
}

Rect interRect(Rect& r1, Rect& r2) {
    Rect rect{0,0,0,0};
    int x1 = max(r1.x1, r2.x1), x2 = min(r1.x2, r2.x2);
    int y1 = max(r1.y1, r2.y1), y2 = min(r1.y2, r2.y2);

    if (x1 < x2 && y1 < y2) rect = Rect{x1,y1,x2,y2};
	
    return rect;
}
