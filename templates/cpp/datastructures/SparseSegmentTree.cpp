#include <bits/stdc++.h>

using namespace std;

class SparseSegmentTree {
private:
    struct Node {
        int sum;
        int left, right;
        Node() : sum(0), left(-1), right(-1) {}
    };

    vector<Node> segTree;
    int L, R;
    int root;

    int newNode() {
        segTree.emplace_back();
        return segTree.size() - 1;
    }

    void set(int idx, int val, int& node, int tl, int tr) {
        if (node == -1) node = newNode();
        if (tl == tr) {
            segTree[node].sum = val;
            return;
        } 

        int tm = (tl + tr) / 2;
        if (tm <= idx) set(idx, val, segTree[node].left, tl, tm);
        else set(idx, val, segTree[node].right, tm + 1, tr);

        int leftResult = segTree[node].left != -1 ? segTree[segTree[node].left].sum : 0;
        int rightResult = segTree[node].right != -1 ? segTree[segTree[node].right].sum : 0;
        segTree[node].sum = leftResult + rightResult;
    }

    int query(int l, int r, int node, int tl, int tr) {
        if (node == -1 || tr < l || tl > r) return 0;
        if (l <= tl && tr <= r) return segTree[node].sum;

        int tm = (tl + tr) / 2;
        return query(l, r, segTree[node].left, tl, tm) + query(l, r, segTree[node].right, tm + 1, tr);
    }

public:
    SparseSegmentTree(int L, int R) : L(L), R(R) {
        root = newNode();
    }

    void set(int idx, int val) {
        set(idx, val, root, L, R);
    }

    int query(int l, int r) {
        return query(l, r, root, L, R);
    }
};