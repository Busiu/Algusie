#include <bits/stdc++.h>

#define ll long long

using namespace std;

int knapsack01(int capacity, vector<int>& values, vector<int>& weights) {
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < values.size(); i++) {
        for (int j = capacity; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[capacity];
}

int knapsackComplete(int capacity, vector<int>& values, vector<int>& weights) {
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < values.size(); i++) {
        for (int j = weights[i]; j <= capacity; j++) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[capacity];
}
