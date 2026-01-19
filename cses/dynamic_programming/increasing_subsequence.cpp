// Flashcard
// 1. Solution
// 2. Describe soulution with printing LIS elements. 
// 3. Edge Case:     cin >> inc[0];
// 4. SegTree RMQ solution.
// 5. Correct the definition of lower_bound and upper_bound in flashcards...

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> inc(1);
    cin >> inc[0];
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        int idx = lower_bound(inc.begin(), inc.end(), a) - inc.begin();
        if (idx >= inc.size()) inc.push_back(a);
        else inc[idx] = a;
    }
    cout << inc.size() << endl;

    return 0;
}