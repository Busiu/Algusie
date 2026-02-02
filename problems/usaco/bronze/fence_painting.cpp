// Link - https://usaco.org/index.php?page=viewproblem2&cpid=567
// Source - https://usaco.guide/bronze/rect-geo
// Date - 2026-02-01

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a,b,c,d; cin >>a>>b>>c>>d;
    //if (a > c) swap(a,c); swap(b,d);                // NIE ROBIC TAKICH IFOW! KONCZY SIE TO PO PIERWSZY SREDNIKU!!!
    if (a > c) {
        swap(a, c);
        swap(b, d);
    }
    cout << (b - a) + max(0, d - max(b, c)) << endl;

    return 0;
}