package undefined;


// Idea: https://www.geeksforgeeks.org/dsa/find-maximum-subset-xor-given-set/
// Proof idea: xoring one row with another one does not change max xor of the system. Such transitions are equivalent.
public class MaxXorSubsequence {
    int maxXorSubsequence(int[] nums) {
        int gaussEndIdx = 0;
        for (int i = (1 << 30); i > 0; i >>= 1) {
            boolean found = false;
            for (int j = gaussEndIdx; j < nums.length; j++) {
                if ((nums[j] & i) > 0) {
                    int tmp = nums[gaussEndIdx];
                    nums[gaussEndIdx] = nums[j];
                    nums[j] = tmp;
                    gaussEndIdx++;
                    found = true;
                    break;
                }
            }
            if (!found) continue;

            for (int j = 0; j < nums.length; j++) {
                if (j == gaussEndIdx - 1) continue;
                if ((nums[j] & i) > 0) nums[j] ^= nums[gaussEndIdx - 1];
            }
        }

        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
}
