package graph;

import java.util.ArrayList;
import java.util.List;

public class Preprocessing {

    // Create list of connections from the given list of edges
    static List<List<int[]>> createGraph(int[][] edges) {
        var cons = new ArrayList<List<int[]>>();
        var n = edges.length + 1;
        for (int i = 0; i < n; i++) {
            cons.add(new ArrayList<>());
        }
        for (var edge : edges) {
            cons.get(edge[0]).add(new int[]{edge[1], edge[2]});
            cons.get(edge[1]).add(new int[]{edge[0], edge[2]});
        }
        return cons;
    }
}
