import java.util.Stack;

public class p85 {
    public class Solution {
        private class Pair {
            int val;
            int pos;

            public Pair(int val, int pos) {
                this.val = val;
                this.pos = pos;
            }
        }

        public int maximalRectangle(char[][] matrix) {
            if (matrix.length == 0 || matrix[0].length == 0) return 0;
            int result = 0;
            int m = matrix.length;
            int n = matrix[0].length;
            int[][] hor = new int[m + 1][n + 1];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == '1') {
                        hor[i + 1][j + 1] = hor[i + 1][j] + 1;
                    } else {
                        hor[i + 1][j + 1] = 0;
                    }
                }
            }
            Pair p = new Pair(0, 0);
            for (int j = 1; j <= n; ++j) {
                Stack<Pair> stack = new Stack<>();
                stack.push(new Pair(0, 0));
                for (int i = 1; i <= m; ++i) {
                    if (hor[i][j] > stack.peek().val) {
                        stack.push(new Pair(hor[i][j], i));
                    } else if (hor[i][j] < stack.peek().val) {
                        while (hor[i][j] < stack.peek().val) {
                            p = stack.pop();
                            result = Integer.max(result, (i - p.pos) * p.val);
                        }
                        stack.push(new Pair(hor[i][j], p.pos));
                    }
                }
                while (!stack.isEmpty()) {
                    p = stack.pop();
                    result = Integer.max(result, (m + 1 - p.pos) * p.val);
                }
            }
            return result;
        }
    }
}
