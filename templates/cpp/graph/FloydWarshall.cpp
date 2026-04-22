#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<vector<int>> floydWarshall(vector<vector<int>> g) {
    int noNodes = g.size();
    auto dist = g;

    for (int k = 0; k < noNodes; k++) {
        for (int i = 0; i < noNodes; i++) {
            for (int j = 0; j < noNodes; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                } 
            }
        }
    }

    return dist;
}