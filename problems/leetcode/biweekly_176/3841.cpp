// Source - https://leetcode.com/contest/biweekly-contest-176/
// Date - 2026-04-29

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
    struct FenwickTree {
        vector<vector<int>> tree;

        FenwickTree() {}

        FenwickTree(int size) {
            tree.assign(size + 1, vector<int>(26, 0));
        }

        void add(int idx, int ch, int val) {
            idx++;
            while (idx < tree.size()) {
                tree[idx][ch] += val;
                idx += (idx & -idx);
            }
        }

        vector<int> sum(int idx) {
            idx++;
            vector<int> ans(26);
            while (idx > 0) {
                for (int i = 0; i < 26; i++) {
                    ans[i] += tree[idx][i];
                }
                idx -= (idx & -idx);
            }
            return ans;
        }
    };

private:
    vector<int> timeIn;
    vector<int> timeOut;
    FenwickTree euler;
    vector<vector<int>> g;
    vector<vector<int>> up;
    int timer = 1;

    void createTour(string& s, int cur, int prev) {
        timeIn[cur] = timer;
        euler.add(timer++, s[cur] - 'a', 1);

        up[cur][0] = prev;
        for (int i = 1; i < up[cur].size(); i++) {
            up[cur][i] = up[up[cur][i - 1]][i - 1];
        }

        for (int nei : g[cur]) {
            if (nei == prev) continue;
            createTour(s, nei, cur);
        }

        timeOut[cur] = timer;
        euler.add(timer++, s[cur] - 'a', -1);
    }

    bool isAncestor(int u, int v) {
        return timeIn[u] <= timeIn[v] && timeOut[u] >= timeOut[v];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int i = up[u].size() - 1; i >= 0; i--) {
            if (!isAncestor(up[u][i], v)) {
                u = up[u][i];
            }
        }

        return up[u][0];
    }

    vector<int> mapQuery(string& s) {
        stringstream ss(s);
        string part1, part2, part3;
        ss >> part1 >> part2 >> part3;

        vector<int> ans(3);
        if (part1 == "update") {
            ans[0] = 1;
            ans[1] = stoi(part2);
            ans[2] = part3[0] - 'a';
        } else {
            ans[0] = 2;
            ans[1] = stoi(part2);
            ans[2] = stoi(part3);
        }
        return ans;
    }

    bool isPalindromic(vector<int>& a) {
        bool foundOdd = false;
        for (int num : a) {
            if (num % 2 == 1) {
                if (foundOdd) return false;
                foundOdd = true;
            }
        }
        return true;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        g.assign(n, vector<int>());
        for (auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        } 

        int log = 1;
        while ((1 << log) <= n) log++;
        up.assign(n, vector<int>(log, -1));

        timeIn.assign(n, 0);
        timeOut.assign(n, 0);
        euler = FenwickTree(2 * n + 1);

        createTour(s, 0, 0);

        vector<bool> ans;
        for (auto& q : queries) {
            auto beb = mapQuery(q);
            if (beb[0] == 1) {
                int u = beb[1];
                int nextAscii = beb[2];
                int curAscii = s[u] - 'a';

                euler.add(timeIn[u], curAscii, -1);
                euler.add(timeOut[u], curAscii, 1);

                euler.add(timeIn[u], nextAscii, 1);
                euler.add(timeOut[u], nextAscii, -1);

                s[u] = char (nextAscii + 'a');
            } else {
                int u = beb[1], v = beb[2];
                int parent = lca(u, v);

                if (parent != u && parent != v) {
                    vector<int> a = euler.sum(timeIn[u]);
                    vector<int> b = euler.sum(timeIn[v]);
                    vector<int> c = euler.sum(timeIn[parent]);
                    vector<int> d = euler.sum(timeIn[parent] - 1);

                    vector<int> result(26);
                    for (int i = 0; i < 26; i++) {
                        result[i] = a[i] + b[i] - c[i] - d[i];
                    }
                    ans.push_back(isPalindromic(result));
                } else {
                    if (parent == v) {
                        swap(u, v);
                    }
                    vector<int> a = euler.sum(timeIn[v]);
                    vector<int> b = euler.sum(timeIn[parent] - 1);
                    
                    vector<int> result(26);
                    for (int i = 0; i < 26; i++) {
                        result[i] = a[i] - b[i];
                    }
                    ans.push_back(isPalindromic(result));
                }
            }
        }

        return ans;
    }
};