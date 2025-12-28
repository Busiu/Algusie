package java.graph;

import java.util.ArrayList;

public class DFSTree {

    // Template for Tree DFS with preprocessed connections
    static int dfs(ArrayList<ArrayList<Integer>> cons, int dist, int cur, int prev) {
        var result = 1;
        for (var nei : cons.get(cur)) {
            if (nei == prev) continue;
            result += dfs(cons, dist + 1, nei, cur);
        }
        return result;
    }
}
