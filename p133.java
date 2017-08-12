import java.util.*;

public class p133 {
     class UndirectedGraphNode {
         int label;
         List<UndirectedGraphNode> neighbors;
         UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
     };

    public class Solution {
        HashMap<UndirectedGraphNode, Integer> hmNodes;
        int count;

        public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
            if (Objects.isNull(node)) return null;
            hmNodes = new HashMap<>();
            count = 0;
            getAllNodes(node);
            List<UndirectedGraphNode> listNodes = new ArrayList<>();
            for (int i = 0; i < count; ++i) listNodes.add(new UndirectedGraphNode(0));
            for (UndirectedGraphNode curNode :
                    hmNodes.keySet()) {
                UndirectedGraphNode newNode =listNodes.get(hmNodes.get(curNode));
                newNode.label = curNode.label;
                newNode.neighbors = new ArrayList<>();
                for (UndirectedGraphNode neiborNode:
                     curNode.neighbors) {
                    newNode.neighbors.add(listNodes.get(hmNodes.get(neiborNode)));
                }
            }
            return listNodes.get(0);
        }

        private void getAllNodes(UndirectedGraphNode curNode) {
            if (!hmNodes.containsKey(curNode)) {
                hmNodes.put(curNode, count);
                ++count;
                for (UndirectedGraphNode nextNode :
                        curNode.neighbors) {
                    getAllNodes(nextNode);
                }
            }
        }
    }
}
