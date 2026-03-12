#include <bits/stdc++.h>

using namespace std;

int upper_bound(vector<int> arr, int val) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] > val) right = mid;
        else left = mid + 1;
    }
    return left;
}

int lower_bound(vector<int> arr, int val) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= val) right = mid;
        else left = mid + 1;
    }
    return left;
}
