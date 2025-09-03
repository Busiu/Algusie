package datastructures.segmenttrees;

class FenwickTree {
    int n;
    int[] fenTree;

    FenwickTree(int[] arr) {
        this.n = arr.length + 1;
        this.fenTree = new int[n];
        for (int i = 0; i < n - 1; i++) {
            add(i, arr[i]);
        }
    }

    void add(int i, int val) {
        i++;
        while (i < n) {
            fenTree[i] += val;
            i += (i & -i);
        }
    }

    int sum(int i) {
        i++;
        var sum = 0;
        while (i > 0) {
            sum += fenTree[i];
            i -= (i & -i);
        }
        return sum;
    }
}