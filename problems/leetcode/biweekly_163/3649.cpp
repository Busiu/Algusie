// Link - https://leetcode.com/problems/number-of-perfect-pairs/description/
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
    ll perfectPairs(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        ll ans = 0;
        int start = 0;
        for (int end = 0; end < nums.size(); end++) {
            while (2 * nums[start] < nums[end]) start++;
            ans += end - start;
        }
        
        return ans;
    }
};