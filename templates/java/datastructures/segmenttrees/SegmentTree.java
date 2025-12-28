package java.datastructures.segmenttrees;

class SegmentTree {
    long[] tree;
    int n;

    SegmentTree(int[] arr) {
        this.n = arr.length;
        this.tree = new long[4 * n];
        build(arr, 1, 0, n - 1);
    }

    long combine(long a, long b) {
        return a + b;
    }

    long neutralElement() {
        return 0;
    }

    private void build(int[] arr, int v, int tl, int tr) {
        if (tl == tr) tree[v] = arr[tl];
        else {
            int tm = tl + (tr - tl) / 2;
            build(arr, 2 * v, tl, tm);
            build(arr, 2 * v + 1, tm + 1, tr);
            tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
        }
    }

    private long query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return neutralElement();
        if (l <= tl && r >= tr) return tree[v];
        int tm = tl + (tr - tl) / 2;
        return combine(
                query(2 * v, tl, tm, l, r),
                query(2 * v + 1, tm + 1, tr, l, r)
        );
    }

    private void update(int v, int tl, int tr, int idx, int val) {
        if (tl == tr) tree[v] = val;
        else {
            int tm = tl + (tr - tl) / 2;
            if (idx <= tm) update(2 * v, tl, tm, idx, val);
            else update(2 * v + 1, tm + 1, tr, idx, val);
            tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
        }
    }

    long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    void print(int v, int tl, int tr) {
        System.out.printf("[%s - %s]: %s%n", tl, tr, tree[v]);
        if (tl != tr) {
            int tm = tl + (tr - tl) / 2;
            print(2 * v, tl, tm);
            print(2 * v + 1, tm + 1, tr);
        }
    }
}
