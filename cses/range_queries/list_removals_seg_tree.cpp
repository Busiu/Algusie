#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct SegmentTree {
private:
    int len;
    vector<int> segTree;

    void build(int at, int tl, int tr) {
        if (tl == tr) {
            segTree[at] = 1;
            return; 
        }

        int tm = (tl + tr) / 2;
        build(2 * at, tl, tm);
        build(2 * at + 1, tm + 1, tr);
        segTree[at] = segTree[2 * at] + segTree[2 * at + 1];
    }

    void set_to_zero(int idx, int at, int tl, int tr) {
        if (tl == tr) {
            segTree[at] = 0;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) set_to_zero(idx, 2 * at, tl, tm);
        else set_to_zero(idx, 2 * at + 1, tm + 1, tr);
        segTree[at] = segTree[2 * at] + segTree[2 * at + 1];
    }

    int find_kth(int k, int at, int tl, int tr) {
        if (tl == tr) {
            return tl;
        }

        int tm = (tl + tr) / 2;
        if (k < segTree[2 * at]) return find_kth(k, 2 * at, tl, tm);
        else return find_kth(k - segTree[2 * at], 2 * at + 1, tm + 1, tr);
    }

public:
    SegmentTree(int len) : len(len) {
        segTree = vector<int> (4 * len, 0);
        build(1, 0, len - 1);
    }

    void set_to_zero(int idx) {
        set_to_zero(idx, 1, 0, len - 1);
    }

    ll find_kth(int k) {
        return find_kth(k, 1, 0, len - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    
    SegmentTree st(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        int idx = st.find_kth(a);
        cout << v[idx] << " ";
        st.set_to_zero(idx);
    }

    return 0;
}