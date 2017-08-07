import java.util.ArrayList;
import java.util.List;

public class p257 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public class Solution {
        public List<String> binaryTreePaths(TreeNode root) {
            List<String> ls = new ArrayList<String>();
            if (root != null) {
                dfs(ls, "", root);
            }
            return ls;
        }

        private void dfs(List<String> ls, String curString, TreeNode curNode) {
            boolean hasChild = false;
            curString += curNode.val;
            if (curNode.left != null) {
                hasChild = true;
                dfs(ls, curString + "->", curNode.left);
            }
            if (curNode.right != null) {
                hasChild = true;
                dfs(ls, curString + "->", curNode.right);
            }
            if (!hasChild) {
                ls.add(curString);
            }
        }
    }
}
