#include <bits/stdc++.h>

using namespace std;

vector<int> hierholzer(vector<vector<int>> cons) {
    stack<int> s;
    vector<int> path;

    s.push(0);
    while (!s.empty()) {
        int curNode = s.top();
        
        if (cons[curNode].empty()) {
            path.push_back(curNode);
            s.pop();
            continue;
        }

        int nextNode = *(cons[curNode].end() - 1);
        s.push(nextNode);
        cons[curNode].pop_back();
    }

    reverse(path.begin(), path.end());
    return path;
}