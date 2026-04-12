// Link - https://leetcode.com/problems/maximum-walls-destroyed-by-robots/description/
// Source - https://leetcode.com/contest/weekly-contest-464/
// Date - 2026-04-05

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
private: 
    int MIN_INF = -2e9;
    int MAX_INF = 2e9;

    int noElementsSmaller(vector<int>& arr, int val) {
        return upper_bound(arr.begin(), arr.end(), val - 1) - arr.begin();
    }

    int noElementsSmallerOrEqual(vector<int>& arr, int val) {
        return upper_bound(arr.begin(), arr.end(), val) - arr.begin();
    }

    int wallsOnTheLeft(vector<pair<int, int>>& robots, vector<int>& walls, int idx) {
        int range = max(robots[idx - 1].first + 1, robots[idx].first - robots[idx].second);
        int end = noElementsSmallerOrEqual(walls, robots[idx].first);
        int start = noElementsSmaller(walls, range);
        return end - start;
    }

    int wallsOnTheRight(vector<pair<int, int>>& robots, vector<int>& walls, int idx) {
        int range = min(robots[idx].first + robots[idx].second, robots[idx + 1].first - 1);
        int end = noElementsSmallerOrEqual(walls, range);
        int start = noElementsSmaller(walls, robots[idx].first);
        return end - start;
    }

    int wallsCommon(vector<pair<int, int>>& robots, vector<int>& walls, int idx) {
        int allWalls = noElementsSmallerOrEqual(walls, robots[idx].first) - noElementsSmaller(walls, robots[idx - 1].first);
        int prevWalls = wallsOnTheRight(robots, walls, idx - 1);
        int curWalls = wallsOnTheLeft(robots, walls, idx);
        return min(allWalls - prevWalls, curWalls);
    }

public:
    int maxWalls(vector<int>& rob, vector<int>& dis, vector<int>& walls) {
        int n = rob.size();
        vector<pair<int, int>> robots(n + 2);       // pos, dist
        for (int i = 1; i <= n; i++) {
            robots[i] = {rob[i - 1], dis[i - 1]};
        }
        robots[0] = {MIN_INF, 0};
        robots[n + 1] = {MAX_INF, 0};
        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());

        vector<int> l(n + 2);
        vector<int> r(n + 2);

        l[1] = wallsOnTheLeft(robots, walls, 1);
        r[1] = wallsOnTheRight(robots, walls, 1);
        
        for (int i = 2; i <= n; i++) {
            l[i] = max(l[i - 1] + wallsOnTheLeft(robots, walls, i), r[i - 1] + wallsCommon(robots, walls, i));
            r[i] = max(r[i - 1], l[i - 1]) + wallsOnTheRight(robots, walls, i);
        }

        return max(l[n], r[n]);
    }
};