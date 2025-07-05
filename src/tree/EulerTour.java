package tree;

import java.util.ArrayList;

public class EulerTour {
    ArrayList<ArrayList<int[]>> cons;
    int n;

    int timer;
    int[] eTour;
    int[] tin;
    int[] tout;
    int[] par;

    EulerTour(ArrayList<ArrayList<int[]>> cons) {
        this.cons = cons;
        this.n = cons.size();

        this.timer = 0;
        this.eTour = new int[2 * n + 1]; // Consider using 2 * n - 1
        this.tin = new int[n];
        this.tout = new int[n];
        this.par = new int[n];

        ett(0, -1, 0);
    }

    void ett(int cur, int prev, int edgeVal) {
        par[cur] = prev;
        tin[cur] = timer;
        eTour[timer++] = edgeVal;

        for (int[] nei : cons.get(cur)) {
            if (nei[0] == prev) continue;
            ett(nei[0], cur, nei[1]);
        }

        tout[cur] = timer;
        eTour[timer++] = -edgeVal;
    }
}