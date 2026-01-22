#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    int ans = 0, acc = 0, n = s.length();
    char prev = 'Q';

    for (int i = 0; i < n; i++) {
        if (prev != s[i]) {
            acc = 1;
            prev = s[i];
        } else acc++;
        ans = max(ans, acc);
    }

    cout << ans << endl;
    return 0;
}