// Validation: https://leetcode.com/problems/separate-squares-ii

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    struct Node {
        int len, sum, occ;
        Node(int _len) {
            len = _len;
            sum = 0;
            occ = 0;
        };
    };
    vector<Node> arr;
    
    SegmentTree(int size, vector<int>& dists) {
        arr.assign(4 * size, Node(0));
        build(dists, 1, 0, size - 1);
    }

    void build(vector<int>& dists, int idx, int tl, int tr) {
        if (tl == tr) {
            arr[idx].len = dists[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(dists, 2 * idx, tl, tm);
        build(dists, 2 * idx + 1, tm + 1, tr);
        arr[idx].len = arr[2 * idx].len + arr[2 * idx + 1].len;
    }

    int sum(int idx, int tl, int tr, int l, int r) {
        if (tr < l || tl > r) return 0;
        if (l <= tl && r >= tr) return arr[idx].sum;
        
        int tm = (tl + tr) / 2;
        int res = sum(2 * idx, tl, tm, l, r);
        res += sum(2 * idx + 1, tm + 1, tr, l, r);
        return res;
    }

    void update(int idx, int tl, int tr, int l, int r, int change) {
        if (tr < l || tl > r) return;
        if (l <= tl && r >= tr) {
            arr[idx].occ += change;
        } else {
            int tm = (tl + tr) / 2;
            update(2 * idx, tl, tm, l, r, change);
            update(2 * idx + 1, tm + 1, tr, l, r, change);
        }
        pull(idx, tl, tr);
    }

    void pull(int idx, int tl, int tr) {
        if (arr[idx].occ > 0) arr[idx].sum = arr[idx].len;
        else {
            if (tl == tr) arr[idx].sum = 0;
            else arr[idx].sum = arr[2 * idx].sum + arr[2 * idx + 1].sum;
        }
    }

    void debug(int idx, int tl, int tr) {
        cout << "(" << tl << "," << tr << ") " << idx << ": Len " << arr[idx].len << ", Occ " << arr[idx].occ << ", Sum " << arr[idx].sum << endl;
        if (tl == tr) return;
        int tm = (tl + tr) / 2;
        debug(2 * idx, tl, tm);
        debug(2 * idx + 1, tm + 1, tr);
    }
};