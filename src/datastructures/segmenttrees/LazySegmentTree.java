package datastructures.segmenttrees;

class LazySegmentTree {
    long[] tree;
    long[] lazy;
    int n;

    LazySegmentTree(int[] arr) {
        this.n = arr.length;
        this.tree = new long[4 * n];
        this.lazy = new long[4 * n];
        build(arr, 1, 0, n - 1);
    }

    long combine(long a, long b) {
        return Math.max(a, b);
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

    private void push(int v, int tl, int tr) {
        if (lazy[v] != 0) {
            tree[v] += lazy[v]; // Depends on what exactly we want to achieve. (Move to separate method? Think about different Segment Trees? Different Types?)
            if (tl != tr) {
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    private long queryRange(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return neutralElement();
        push(v, tl, tr);
        if (l <= tl && r >= tr) return tree[v];
        int tm = tl + (tr - tl) / 2;
        return combine(
                queryRange(2 * v, tl, tm, l, r),
                queryRange(2 * v + 1, tm + 1, tr, l, r)
        );
    }

    private void updateRange(int v, int tl, int tr, int l, int r, int val) {
        push(v, tl, tr);
        if (tl > r || tr < l) return;
        if (l <= tl && r >= tr) {
            lazy[v] += val;
            push(v, tl, tr);
        } else {
            int tm = tl + (tr - tl) / 2;
            updateRange(2 * v, tl, tm, l, r, val);
            updateRange(2 * v + 1, tm + 1, tr, l, r, val);
            tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
        }
    }

    long queryRange(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }

    void updateRange(int l, int r, int val) {
        updateRange(1, 0, n - 1, l, r, val);
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
