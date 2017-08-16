import java.util.Objects;

public class p98 {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public class Solution {
        public boolean isValidBST(TreeNode root) {
            return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
        }

        private boolean isValidBST(TreeNode root, long minVal, long maxVal) {
            if (Objects.isNull(root)) return true;
            if (root.val >= maxVal || root.val <= minVal) return false;
            return isValidBST(root.left, minVal, root.val) && isValidBST(root.right, root.val, maxVal);
        }
    }
}
