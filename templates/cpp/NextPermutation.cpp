#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0) {
        if (nums[i + 1] <= nums[i]) i--;
        else break;
    }

    if (i == -1) {
        reverse(nums.begin(), nums.end());
        return;  
    }

    int j = i + 1;
    while (j < nums.size() - 1 && nums[j + 1] > nums[i]) j++;

    swap(nums[i], nums[j]);
    reverse(nums.begin() + i + 1, nums.end());
}