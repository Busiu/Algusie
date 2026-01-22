#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    ll totalSum = (ll) n * (n + 1) / 2;
    ll curSum = 0;
    for (int i = 0; i < n - 1; i++) {
        int a; cin >> a;
        curSum += a;
    }

    cout << totalSum - curSum;

    return 0;
}