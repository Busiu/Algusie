package undefined;

public class TravellingSalesmanProblem {
    int n;
    Integer[][] memo;       // (idx, mask)

    int dp(int curNodeIdx, int mask, int[][] costs) {
        if (mask == (1 << costs.length) - 1) {
            return costs[curNodeIdx][0];
        }

        if (memo[curNodeIdx][mask] != null) return memo[curNodeIdx][mask];

        int ans = Integer.MAX_VALUE;
        for (int nextNodeIdx = 0; nextNodeIdx < n; nextNodeIdx++) {
            if ((mask & (1 << nextNodeIdx)) > 0) continue;
            ans = Math.min(ans, costs[curNodeIdx][nextNodeIdx] + dp(nextNodeIdx, mask | (1 << nextNodeIdx), costs));
        }

        return memo[curNodeIdx][mask] = ans;
    }

    // costs[x][y] - cost of reaching node y FROM node x
    int tsp(int[][] costs) {
        return dp(0, 1, costs);
    }
}
