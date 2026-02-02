#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Rect {
	int x1, y1, x2, y2;
	void read() { cin >> x1 >> y1 >> x2 >> y2; }
	int area() { return (y2 - y1) * (x2 - x1); }
};