// Link - https://leetcode.com/problems/minimum-sensors-to-cover-grid/description/
// Source - https://leetcode.com/contest/biweekly-contest-163/
// Date - 2026-01-27

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define INF 2147483647
#define LL_INF 9223372036854775807

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int MOD = 1e9 + 7;

class Solution {
public:
    int minSensors(int n, int m, int k) {
        int a = (n + 2 * k) / (2 * k + 1);
        int b = (m + 2 * k) / (2 * k + 1);
        return a * b;
    }
};