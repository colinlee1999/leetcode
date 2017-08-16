import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class p117 {
     public class TreeLinkNode {
         int val;
         TreeLinkNode left, right, next;
         TreeLinkNode(int x) { val = x; }
     }

    public class Solution {
        public void connect(TreeLinkNode root) {
            if (Objects.isNull(root)) return;
            List<TreeLinkNode> cur = new ArrayList<>();
            root.next = null;
            cur.add(root);
            while (!cur.isEmpty()) {
                List<TreeLinkNode> next = new ArrayList<>();
                for (TreeLinkNode curNode :
                        cur) {
                    if (!Objects.isNull(curNode.left))
                        next.add(curNode.left);
                    if (!Objects.isNull(curNode.right))
                        next.add(curNode.right);
                }
                if (!next.isEmpty()) next.get(next.size()-1).next = null;
                for (int i = 0; i < next.size() - 1; ++i) {
                    next.get(i).next = next.get(i+1);
                }
                cur = next;
            }
            return;
        }
    }
}
