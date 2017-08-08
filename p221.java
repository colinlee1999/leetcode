import java.util.Arrays;
import java.util.List;

public class p221 {
    public class Solution {
        public int maximalSquare(char[][] matrix) {
            if (matrix.length == 0 || matrix[0].length == 0) {
                return 0;
            }
            int maximum = 0;
            int m = matrix.length;
            int n = matrix[0].length;
            int[][] sum = new int[m + 1][n + 1];
            for (int[] row :
                    sum) {
                Arrays.fill(row, 0);
            }
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    sum[i + 1][j + 1] = matrix[i][j] - '0' + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
                }
            }
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int l = 1; l <= Integer.min(i, j) + 1; ++l) {
                        if (sum[i + 1][j + 1] + sum[i + 1 - l][j + 1 - l] - sum[i + 1 - l][j + 1] - sum[i + 1][j + 1 - l] == l * l) {
                            maximum = Integer.max(maximum, l);
                        } else {
                            break;
                        }
                    }
                }
            }
            return maximum * maximum;
        }
    }
}
