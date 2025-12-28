package java.datastructures.segmenttrees;

class FenwickTree {
    int n;
    int[] fenTree;

    FenwickTree(int n) {
        this.n = n + 1;
        this.fenTree = new int[this.n];
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
        int sum = 0;
        while (i > 0) {
            sum += fenTree[i];
            i -= (i & -i);
        }
        return sum;
    }
}