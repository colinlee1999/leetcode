#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int result = 0, num_nodes = -1;
		get_kth_smallest(root, k, result, num_nodes);
		return result;
	}

private:
	bool get_kth_smallest(TreeNode * root, const int k, int & result, int & num_nodes)
	{
		if (!root)
		{
			num_nodes = 0;
			return false;
		}
		int num_left_nodes = -1;
		if (get_kth_smallest(root->left, k, result, num_left_nodes))
			return true;
		if (num_left_nodes == k - 1)
		{
			result = root->val;
			return true;
		}
		int num_right_nodes = -1;
		if (get_kth_smallest(root->right, k - 1 - num_left_nodes, result, num_right_nodes))
			return true;
		num_nodes = 1 + num_left_nodes + num_right_nodes;
		return false;
	}
};

int main()
{
    Solution s;
    cin.get();
}
