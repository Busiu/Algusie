// Flashcard
// 1. Solution
// 2. How to create Structs easy.
// 3. Default + combine make SegTrees implementation easier. AI -> add to SegTree Template
// 4. Build is not always necessary -> we can use set instead.... AI -> Change the SegTree Flashcard
// 5. When tl == tr in build or set -> remember about RETURN!!!


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Node {
    int plusMin = 0;
    int minusMin = 0;
};

struct SegmentTree {
private:
    int len;
    vector<Node> segTree;

    Node DEFAULT = {INT32_MAX, INT32_MAX};

    Node combine(const Node& a, const Node& b) {
        return {min(a.plusMin, b.plusMin), min(a.minusMin, b.minusMin)};
    }

    void build(vector<int>& arr, int at, int tl, int tr) {
        if (tl == tr) {
            segTree[at] = {arr[tl] + tl, arr[tl] - tl};
            return;
        }

        int tm = (tl + tr) / 2;
        build(arr, 2 * at, tl, tm);
        build(arr, 2 * at + 1, tm + 1, tr);

        segTree[at] = combine(segTree[2 * at], segTree[2 * at + 1]);
    }

    Node query(int l, int r, int at, int tl, int tr) {
        if (r < tl || tr < l) return DEFAULT;
        if (l <= tl && tr <= r) return segTree[at];

        int tm = (tl + tr) / 2;

        return combine(query(l, r, 2 * at, tl, tm), query(l, r, 2 * at + 1, tm + 1, tr));
    }

    void set(int idx, int val, int at, int tl, int tr) {
        if (tl == tr) {
            segTree[at] = {val + tl, val - tl};
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) set(idx, val, 2 * at, tl, tm);
        else set(idx, val, 2 * at + 1, tm + 1, tr);

        segTree[at] = combine(segTree[2 * at], segTree[2 * at + 1]);
    }

public: 
    SegmentTree(vector<int>& arr) {
        len = arr.size();
        segTree = vector<Node>(4 * len);
        build(arr, 1, 0, len - 1);
    }

    Node query(int l, int r) {
        return query(l, r, 1, 0, len - 1);
    }

    void set(int idx, int val) {
        set(idx, val, 1, 0, len - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    SegmentTree st(prices);

    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int k, x; cin >> k >> x; k--;
            st.set(k, x);
            prices[k] = x;
        } else {
            int k; cin >> k; k--;
            auto leftResult = st.query(0, k);
            auto rightResult = st.query(k, n - 1);
            cout << min(leftResult.minusMin + k, rightResult.plusMin - k) << endl;
        }
    }

    return 0;
}