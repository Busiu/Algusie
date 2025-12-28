package java.graph;

import java.util.ArrayList;

public class DirectedGraph {

    record DG(ArrayList<ArrayList<Integer>> ins, ArrayList<ArrayList<Integer>> outs) {}

    static DG createGraph(int[][] edges, int size) {
        var ins = new ArrayList<ArrayList<Integer>>();
        var outs = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < size; i++) {
            ins.add(new ArrayList<>());
            outs.add(new ArrayList<>());
        }
        for (var edge : edges) {
            outs.get(edge[0]).add(edge[1]);
            ins.get(edge[1]).add(edge[0]);
        }
        return new DG(ins, outs);
    }
}
