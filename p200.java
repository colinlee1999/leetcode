import java.util.Arrays;

public class p200 {
    public class Solution {
        private int[] dx = {0, 0, 1, -1};
        private int[] dy = {1, -1, 0, 0};
        private int m, n;

        public int numIslands(char[][] grid) {
            if (grid.length == 0 || grid[0].length == 0)
                return 0;
            int result = 0;
            m = grid.length;
            n = grid[0].length;
            boolean[][] visited = new boolean[m][n];
            for (boolean[] row :
                    visited) {
                Arrays.fill(row, false);
            }
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == '1' && !visited[i][j]) {
                        ++result;
                        dfs(grid, visited, i, j);
                    }
                }
            }

            return result;
        }

        private void dfs(char[][] grid, boolean[][] visited, int si, int sj) {
            visited[si][sj] = true;
            for (int k = 0; k < 4; ++k) {
                int ni = si + dx[k];
                int nj = sj + dy[k];
                if (0 <= ni && ni < m && 0 <= nj && nj < n) {
                    if (grid[ni][nj] == '1' && !visited[ni][nj])
                        dfs(grid, visited, ni, nj);
                }
            }
        }
    }
}
