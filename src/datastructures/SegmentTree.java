package datastructures;

class SegmentTree {
    long[] t;
    int n;

    SegmentTree(int[] arr) {
        this.n = arr.length;
        this.t = new long[4 * n];
    }

    long combine(long a, long b) {
        return a + b;
    }

    long neutralElement() {
        return 0;
    }

    void build(long[] arr, int v, int tl, int tr) {
        if (tl == tr) t[v] = arr[tl];
        else {
            int tm = tl + (tr - tl) / 2;
            build(arr, 2 * v, tl, tm);
            build(arr, 2 * v + 1, tm + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    long query(int v, int tl, int tr, int l, int r) {
        if (l > r) return neutralElement();
        if (l == tl && r == tr) return t[v];
        int tm = tl + (tr - tl) / 2;
        return combine(
                query(2 * v, tl, tm, l, Math.min(r, tm)),
                query(2 * v + 1, tm + 1, tr, Math.max(tm + 1, l), r)
        );
    }

    void update(int v, int tl, int tr, int idx, int val) {
        if (tl == tr) t[v] = val;
        else {
            int tm = tl + (tr - tl) / 2;
            if (idx <= tm) update(2 * v, tl, tm, idx, val);
            else update(2 * v + 1, tm + 1, tr, idx, val);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }
}
