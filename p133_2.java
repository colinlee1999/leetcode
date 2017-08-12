import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class p133_2 {
    public class Solution {
        class UndirectedGraphNode {
            int label;
            List<UndirectedGraphNode> neighbors;
            UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
        };

        HashMap<Integer, UndirectedGraphNode> map = new HashMap<>();
        public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
            return clone(node);
        }

        private UndirectedGraphNode clone(UndirectedGraphNode node) {
            if(node == null) return null;
            if(map.containsKey(node.label)) return map.get(node.label);

            UndirectedGraphNode newNode = new UndirectedGraphNode(node.label);
            List<UndirectedGraphNode> list = node.neighbors;
            List<UndirectedGraphNode> newList = newNode.neighbors;
            map.put(node.label, newNode);
            for(UndirectedGraphNode nei: list) {
                newList.add(clone(nei));
            }

            return newNode;
        }
    }
}
