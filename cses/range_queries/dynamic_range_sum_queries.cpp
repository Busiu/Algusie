#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct SegmentTree {
private:
    int len;
    vector<ll> segTree;

    void build(vector<int>& arr, int at, int tl, int tr) {
        if (tl == tr) {
            segTree[at] = arr[tl];
            return; 
        }

        int tm = (tl + tr) / 2;
        build(arr, 2 * at, tl, tm);
        build(arr, 2 * at + 1, tm + 1, tr);
        segTree[at] = segTree[2 * at] + segTree[2 * at + 1];
    }

    void set(int idx, int val, int at, int tl, int tr) {
        if (tl == tr) {
            segTree[at] = val;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) set(idx, val, 2 * at, tl, tm);
        else set(idx, val, 2 * at + 1, tm + 1, tr);
        segTree[at] = segTree[2 * at] + segTree[2 * at + 1];
    }

    ll query(int l, int r, int at, int tl, int tr) {
        if (tr < l || r < tl) return 0;
        if (l <= tl && tr <= r) return segTree[at];

        int tm = (tl + tr) / 2;
        return query(l, r, 2 * at, tl, tm) + query(l, r, 2 * at + 1, tm + 1, tr);
    }

public:
    SegmentTree(vector<int>& arr) : len(arr.size()) {
        segTree = vector<ll> (4 * len, 0);
        build(arr, 1, 0, len - 1);
    }

    void set(int idx, int val) {
        set(idx, val, 1, 0, len - 1);
    }

    ll query(int l, int r) {
        return query(l, r, 1, 0, len - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    SegmentTree st(arr);

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u; k--;
            st.set(k, u);
        } else {
            int a, b;
            cin >> a >> b; a--; b--;
            cout << st.query(a, b) << endl;
        }
    }

    return 0;
}