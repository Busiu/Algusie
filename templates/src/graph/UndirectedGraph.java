package graph;

import java.util.ArrayList;
import java.util.List;

public class UndirectedGraph {

    static List<List<int[]>> createGraph(int[][] edges, int size) {
        var cons = new ArrayList<List<int[]>>();
        for (int i = 0; i < size; i++) {
            cons.add(new ArrayList<>());
        }
        for (var edge : edges) {
            cons.get(edge[0]).add(new int[]{edge[1], edge[2]});
            cons.get(edge[1]).add(new int[]{edge[0], edge[2]});
        }
        return cons;
    }
}
