#include <bits/stdc++.h>

using namespace std;

class PersistentSegmentTree {
private:
    struct Node {
        int sum;
        int left, right;
        Node() : sum(0), left(-1), right(-1) {}
    };

    vector<Node> segTree;
    vector<int> roots;
    int L, R;

    int copyNode(int node) {
        segTree.push_back(node == -1 ? Node() : segTree[node]);
        return segTree.size() - 1;
    }

    int update(int idx, int val, int prevNode, int tl, int tr) {
        int newNode = copyNode(prevNode);
        if (tl == tr) {
            segTree[newNode].sum = val;
            return newNode;
        }
    
        int tm = (tl + tr) / 2;
        if (idx <= tm) segTree[newNode].left = update(idx, val, segTree[newNode].left, tl, tm);
        else segTree[newNode].right = update(idx, val, segTree[newNode].right, tm + 1, tr);
        
        int leftResult = segTree[newNode].left != -1 ? segTree[segTree[newNode].left].sum : 0;
        int rightResult = segTree[newNode].right != -1 ? segTree[segTree[newNode].right].sum : 0;
        segTree[newNode].sum = leftResult + rightResult;

        return newNode;
    }

    int query(int l, int r, int node, int tl, int tr) {
        if (node == -1 || tr < l || tl > r) return 0;
        if (l <= tl && tr <= r) return segTree[node].sum;

        int tm = (tl + tr) / 2;
        return query(l, r, segTree[node].left, tl, tm) + query(l, r, segTree[node].right, tm + 1, tr);
    }

public:
    PersistentSegmentTree(int L, int R) : L(L), R(R) {
        roots.push_back(-1);
    }

    void update(int idx, int val) {
        roots.push_back(update(idx, val, roots.back(), L, R));
    }

    int query(int version, int l, int r) {
        if (version >= roots.size()) return 0;
        return query(l, r, roots[version], L, R);
    }
};