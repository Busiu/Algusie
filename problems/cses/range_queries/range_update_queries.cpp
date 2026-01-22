#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct SegmentTree {
private:
    int len;
    vector<ll> segTree;

    void add(int idx, int val, int at, int tl, int tr) {
        if (tl == tr) {
            segTree[at] += val;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) add(idx, val, 2 * at, tl, tm);
        else add(idx, val, 2 * at + 1, tm + 1, tr);
        segTree[at] = segTree[2 * at] + segTree[2 * at + 1];
    }

    ll query(int l, int r, int at, int tl, int tr) {
        if (tr < l || r < tl) return 0;
        if (l <= tl && tr <= r) return segTree[at];

        int tm = (tl + tr) / 2;
        return query(l, r, 2 * at, tl, tm) + query(l, r, 2 * at + 1, tm + 1, tr);
    }

public:
    SegmentTree(int len) : len(len) {
        segTree = vector<ll> (4 * len, 0);
    }

    void add(int idx, int val) {
        add(idx, val, 1, 0, len - 1);
    }

    ll query(int l, int r) {
        return query(l, r, 1, 0, len - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    SegmentTree st(n + 1);

    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int a, b, u; cin >> a >> b >> u; a--; b--;
            st.add(a, u);
            st.add(b + 1, -u);
        } else {
            int k; cin >> k; k--;
            cout << arr[k] + st.query(0, k) << endl;
        }
    }

    return 0;
}