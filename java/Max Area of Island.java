class Solution {
    public boolean[][] vis;
    public int[][] g;
    public int ans = 0, curr = 0;

    public boolean safe(int i, int j) {
        return (i >= 0 && j >= 0 && i < g.length && j < g[0].length && vis[i][j] == false && g[i][j] == 1);
    }

    public void dfs(int r, int c) {
        vis[r][c] = true;
        int[] R = { -1, 0, 0, 1 };
        int[] C = { 0, -1, 1, 0 };
        for (int i = 0; i < 4; i++) {
            if (safe(r + R[i], c + C[i])) {
                curr++;
                dfs(r + R[i], c + C[i]);
            }
        }
    }

    public int maxAreaOfIsland(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        vis = new boolean[r][c];
        g = grid;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (vis[i][j] == false && grid[i][j] == 1) {
                    curr = 1;
                    dfs(i, j);
                    ans = Math.max(ans, curr);
                }
            }
        }
        return ans;
    }
}