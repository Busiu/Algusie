#include <bits/stdc++.h>

using namespace std;

double shoelace(vector<vector<int>>& points) {
    double area = 0;
    for (int i = 0; i < points.size(); i++) {
        int next = i == points.size() - 1 ? 0 : i + 1;
        area += (points[i][0] * points[next][1] - points[i][1] * points[next][0]);
    }
    return abs(area) / 2;
}