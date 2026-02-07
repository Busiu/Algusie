// Link - https://codeforces.com/contest/1556/problem/D
// Source - https://usaco.guide/silver/intro-bitwise
// Date - 2026-02-07

#include <bits/stdc++.h>

#define ll long long
using namespace std;

int getSum(int i, int j) {
    i++; j++;
    cout << "and " << i << " " << j << endl;
    int a; cin >> a;
    cout << "or " << i << " " << j << endl;
    int o; cin >> o;
    int x = ~a & o;
    return x + (a << 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> nums(n);

    int aPb = getSum(0, 1);
    int aPc = getSum(0, 2);
    int bPc = getSum(1, 2);
    nums[0] = (aPb + aPc - bPc) / 2;
    nums[1] = (aPb + bPc - aPc) / 2;
    nums[2] = (bPc + aPc - aPb) / 2;

    for (int i = 3; i < n; i++) {
        int sum = getSum(0, i);
        nums[i] = sum - nums[0];
    }

    sort(nums.begin(), nums.end());
    cout << "finish " << nums[k - 1] << endl;

    return 0;
}