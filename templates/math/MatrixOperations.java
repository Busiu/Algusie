package math;

public class MatrixOperations {
    int[][] rotate90(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] rotatedGrid = new int[n][m];
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                rotatedGrid[x][m - 1 - y] = grid[y][x];
            }
        }
        return rotatedGrid;
    }
}
