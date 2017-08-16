public class p79 {
    public class Solution {
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        int m, n;

        public boolean exist(char[][] board, String word) {
            if (word.isEmpty()) return true;
            if (board.length == 0) return false;
            if (board[0].length == 0) return false;
            m = board.length;
            n = board[0].length;
            boolean[][] visited = new boolean[m][n];
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (board[i][j] == word.charAt(0)) {
                        if (dfs(board, visited, word, i, j, 1))
                            return true;
                    }
            return false;
        }

        private boolean dfs(char[][] board, boolean[][] visited, String word, int x, int y, int pos) {
            if (pos == word.length()) {
                return true;
            } else {
                visited[x][y] = true;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && word.charAt(pos) == board[nx][ny]) {
                        if (dfs(board, visited, word, nx, ny, pos + 1))
                            return true;
                    }
                }
                visited[x][y] = false;
                return false;
            }
        }
    }
}
