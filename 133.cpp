#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return NULL;
		unordered_map<UndirectedGraphNode *, int> node_to_int;
		vector<UndirectedGraphNode *> all_nodes;
		int count = 0;
		build_node_to_int(node_to_int, node, count, all_nodes);
		vector<UndirectedGraphNode *> v;
		for (int i = 0; i < count; i++)
			v.push_back(new UndirectedGraphNode(0));
		for (auto cur_node : all_nodes)
		{
			UndirectedGraphNode * cur_cloned_node = v[node_to_int[cur_node]];
			cur_cloned_node->label = cur_node->label;
			for (auto cur_neighbor : cur_node->neighbors)
				cur_cloned_node->neighbors.push_back(v[node_to_int[cur_neighbor]]);
		}
		return v[0];
	}

private:
	void build_node_to_int(unordered_map<UndirectedGraphNode *, int> & node_to_int,
		UndirectedGraphNode * node,
		int & count,
		vector<UndirectedGraphNode *> & all_nodes)
	{
		node_to_int[node] = count;
		count++;
		all_nodes.push_back(node);
		for (auto it : node->neighbors)
			if (!node_to_int.count(it))
				build_node_to_int(node_to_int, it, count, all_nodes);
	}
};

int main()
{
    Solution s;
    cin.get();
}
