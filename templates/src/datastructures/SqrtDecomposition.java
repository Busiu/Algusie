package datastructures;

class SqrtDecomposition {
    int[] a;
    int[] b;
    int n;
    int blockSize;
    int noBlocks;

    SqrtDecomposition(int[] arr) {
        this.n = arr.length;
        this.blockSize = (int) Math.sqrt(n) + 1;
        this.noBlocks = blockSize;

        this.a = new int[n];
        this.b = new int[noBlocks];

        for (int i = 0; i < n; i++) {
            a[i] += arr[i];
            b[i / blockSize] += arr[i];
        }
    }

    int sumRange(int l, int r) {
        int ans = 0;

        for (int i = l; i <= r; ) {
            if (i % blockSize == 0 && i + blockSize - 1 <= r) {
                ans += b[i / blockSize];
                i += blockSize;
            } else {
                ans += a[i++];
            }
        }

        return ans;
    }

    void update(int idx, int val) {
        int blockIdx = idx / blockSize;
        b[blockIdx] += val - a[idx];
        a[idx] = val;
    }
}
