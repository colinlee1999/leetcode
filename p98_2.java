import java.util.Objects;

public class p98_2 {
    public class TreeNode {
         int val;
         TreeNode left;
         TreeNode right;
         TreeNode(int x) { val = x; }
     }

    class Status {
        boolean isValid;
        long min;
        long max;
        public Status(boolean isValid, long min, long max) {
            this.isValid = isValid;
            this.min = min;
            this.max = max;
        }
    }

    public class Solution {
        public boolean isValidBST(TreeNode root) {
            return isValidBstDfs(root).isValid;
        }

        private Status isValidBstDfs(TreeNode cur) {
            if (Objects.isNull(cur)) {
                return new Status(true, Long.MAX_VALUE, Long.MIN_VALUE);
            } else {
                Status left = isValidBstDfs(cur.left);
                Status right = isValidBstDfs(cur.right);
                if (!(left.isValid && right.isValid)) return new Status(false, 0,0);
                if (left.max >= cur.val || right.min <= cur.val) return new Status(false, 0,0);
                return new Status(true, Long.min(cur.val, left.min), Long.max(cur.val, right.max));
            }
        }
    }
}
