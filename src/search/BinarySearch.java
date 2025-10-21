package search;

import java.util.ArrayList;

public class BinarySearch {

    // Return first element that is bigger or equal than val (Sorted ASC)
    int lowerBound(ArrayList<Integer> arr, int val) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr.get(mid) >= val) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    // Return first element that is lesser or equal than val (Sorted ASC)
    int upperBound(ArrayList<Integer> arr, int val) {
        int left = -1, right = arr.size() - 1;
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (arr.get(mid) <= val) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
