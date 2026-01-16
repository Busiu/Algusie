#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    int prev = 0;
    ll ans = 0;
    while (N--) {
        int cur;
        cin >> cur;

        if (prev > 0) ans += max(0, prev - cur);
        prev = max(prev, cur);
    }

    cout << ans;
    return 0;
}