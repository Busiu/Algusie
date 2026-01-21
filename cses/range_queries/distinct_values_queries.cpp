// Flashcards
// Analyze CSES Editorial

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

struct FenwickTree {
    vector<int> tree;
    
    FenwickTree(int size) {
        tree.assign(size + 1, 0);
    }

    void add(int idx, int val) {
        idx++;
        while (idx < tree.size()) {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }

    int sum(int idx) {
        idx++;
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= (idx & -idx);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<tuple<int, int, int>> qs(q);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        qs[i] = {b, a, i};
    }

    sort(qs.begin(), qs.end());

    vector<int> ans(q);
    map<int, int> numToIdx;
    FenwickTree ft(n);
    int curPtr = -1;
    for (auto [r, l, idx] : qs) {
        while (curPtr < r) {
            curPtr++;
            if (numToIdx.count(a[curPtr]) > 0) {
                int prevPtr = numToIdx[a[curPtr]];
                ft.add(prevPtr, -1);
            }
            ft.add(curPtr, 1);
            numToIdx[a[curPtr]] = curPtr;
        }

        ans[idx] = ft.sum(r) - ft.sum(l - 1);
    }

    for (int a : ans) cout << a << endl;

    return 0;
}