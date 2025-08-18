package undefined;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.TreeSet;

// Implementation for 3636 - https://leetcode.com/problems/threshold-majority-queries/
public class Mo {

    record Query(int l, int r, int threshold, int idx) {}

    HashMap<Integer, Integer> numToFreq;
    ArrayList<TreeSet<Integer>> freqToElems;
    int maxFreq;
    int[] nums;

    void add(int idx) {
        int num = nums[idx];
        int curFreq = numToFreq.getOrDefault(num, 0);
        freqToElems.get(curFreq).remove(num);
        curFreq++;
        freqToElems.get(curFreq).add(num);
        numToFreq.put(num, curFreq);
        maxFreq = Math.max(maxFreq, curFreq);
    }

    void remove(int idx) {
        int num = nums[idx];
        int curFreq = numToFreq.getOrDefault(num, 0);
        freqToElems.get(curFreq).remove(num);
        curFreq--;
        if (curFreq > 0) freqToElems.get(curFreq).add(num);
        numToFreq.put(num, curFreq);
        if (freqToElems.get(maxFreq).isEmpty() && maxFreq > 0) maxFreq--;
    }

    int getAnswer(int threshold) {
        if (maxFreq < threshold) return -1;
        return freqToElems.get(maxFreq).getFirst();
    }

    public int[] subarrayMajority(int[] numsCopy, int[][] queries) {
        nums = numsCopy;
        int[] ans = new int[queries.length];

        // Create custom Queries
        var moQueries = new Query[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            moQueries[i] = new Query(query[0], query[1], query[2], i);
        }
        int blockSize = (int) Math.sqrt(nums.length);

        Arrays.sort(moQueries, (q1, q2) -> {
            if (q1.l / blockSize > q2.l / blockSize) return 1;
            else if (q1.l / blockSize < q2.l / blockSize) return -1;
            if (q1.r > q2.r) return 1;
            else if (q1.r < q2.r) return -1;
            return 0;
        });

        // Create Data Structures for answers
        numToFreq = new HashMap<>();                                                // --> MultiSet
        freqToElems = new ArrayList<>();
        maxFreq = 0;
        for (int i = 0; i <= nums.length; i++) freqToElems.add(new TreeSet<>());

        // Create pointers for queries
        int curLeft = 0, curRight = -1;

        // Start answer
        for (var query : moQueries) {
            while (curRight < query.r) add(++curRight);
            while (curRight > query.r) remove(curRight--);
            while (curLeft > query.l) add(--curLeft);
            while (curLeft < query.l) remove(curLeft++);
            ans[query.idx] = getAnswer(query.threshold);
        }

        return ans;
    }
}
