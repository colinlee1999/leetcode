public class p221_2 {
    class Solution {
        public int maximalSquare(char[][] matrix) {
            if (matrix.length == 0 || matrix[0].length == 0) return 0;
            int m = matrix.length;
            int n = matrix[0].length;
            int[][] f = new int[m + 1][n + 1];
            int[][] hor = new int[m + 1][n + 1];
            int[][] ver = new int[m + 1][n + 1];
            int result = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == '1') {
                        hor[i + 1][j + 1] = 1 + hor[i + 1][j];
                        ver[i + 1][j + 1] = 1 + ver[i][j + 1];
                        f[i + 1][j + 1] = Integer.min(hor[i + 1][j + 1], ver[i + 1][j + 1]);
                        f[i + 1][j + 1] = Integer.min(f[i + 1][j + 1], 1 + f[i][j]);
                        result = Integer.max(result, f[i + 1][j + 1]);
                    } else {
                        hor[i + 1][j + 1] = 0;
                        ver[i + 1][j + 1] = 0;
                        f[i + 1][j + 1] = 0;
                    }
                }
            }
            return result * result;
        }
    }
}
