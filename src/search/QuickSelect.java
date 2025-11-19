package search;

import java.util.ArrayList;

public class QuickSelect {

    // INT[]
    void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    int kthSmallestDistinct(int[] arr, int l, int r, int k) {
        int idx = partitionDistinct(arr, l, r);
        if (idx == k) return arr[k];
        if (idx < k) return kthSmallestDistinct(arr, idx + 1, r, k);
        return kthSmallestDistinct(arr, l, idx - 1, k);
    }

    int partitionDistinct(int[] arr, int l, int r) {
        int pivot = arr[r];
        int wallIdx = l;
        for (int i = l; i < r; i++) {
            if (arr[i] <= pivot) {
                swap(arr, i, wallIdx);
                wallIdx++;
            }
        }
        swap(arr, r, wallIdx);

        return wallIdx;
    }



    // ARRAY LIST
    void swap(ArrayList<Integer> arr, int i, int j) {
        int tmp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, tmp);
    }

    int kthSmallestDistinct(ArrayList<Integer> arr, int l, int r, int k) {
        int idx = partitionDistinct(arr, l, r);
        if (idx == k) return arr.get(k);
        if (idx < k) return kthSmallestDistinct(arr, idx + 1, r, k);
        return kthSmallestDistinct(arr, l, idx - 1, k);
    }

    int partitionDistinct(ArrayList<Integer> arr, int l, int r) {
        int pivot = arr.get(r);
        int wallIdx = l;
        for (int i = l; i < r; i++) {
            if (arr.get(i) <= pivot) {
                swap(arr, i, wallIdx);
                wallIdx++;
            }
        }
        swap(arr, r, wallIdx);

        return wallIdx;
    }



    // Example of QuickSelect, where the same elements array would not make it O(n^2)
    int kthSmallest(ArrayList<Integer> arr, int l, int r, int k) {
        int[] idxes = partition(arr, l, r);
        int leftIdx = idxes[0], rightIdx = idxes[1];
        if (leftIdx <= k && k <= rightIdx) return arr.get(k);
        if (rightIdx < k) return kthSmallest(arr, rightIdx + 1, r, k);
        return kthSmallest(arr, l, leftIdx - 1, k);
    }

    int[] partition(ArrayList<Integer> arr, int l, int r) {
        int pivot = arr.get(r);
        int leftWallIdx = l, rightWallIdx = l;
        for (int i = l; i < r; i++) {
            if (arr.get(i) < pivot) {
                if (leftWallIdx == rightWallIdx) {
                    swap(arr, i, leftWallIdx);
                } else {
                    swap(arr, i, leftWallIdx);
                    swap(arr, i, rightWallIdx);
                }
                leftWallIdx++;
                rightWallIdx++;
            } else if (arr.get(i) == pivot) {
                swap(arr, i, rightWallIdx);
                rightWallIdx++;
            }
        }
        swap(arr, r, rightWallIdx);

        return new int[]{leftWallIdx, rightWallIdx};
    }
}
