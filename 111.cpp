#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		int min_depth = 1 << 30;
		dfs_min_depth(root, 1, min_depth);
		return min_depth;
	}

	void dfs_min_depth(TreeNode * root, int depth, int & min_depth)
	{
		if ((!root->left) && (!root->right))
		{
			if (depth < min_depth) min_depth = depth;
		}
		else
		{
			depth++;
			if (root->left) dfs_min_depth(root->left, depth, min_depth);
			if (root->right) dfs_min_depth(root->right, depth, min_depth);
		}		
	}
};

int main()
{
	Solution s;
    cin.get();
}
