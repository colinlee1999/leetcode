#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		int max_depth = -1;
		dfs(root, -1, max_depth, result);
		for (int i = 1; i < result.size(); i += 2)
			reverse(result[i].begin(), result[i].end());
		return result;
	}

	void dfs(TreeNode * root, int depth, int & max_depth, vector<vector<int> > & result)
	{
		if (root)
		{
			depth++;
			if (depth > max_depth)
			{
				max_depth = depth;
				result.push_back(vector<int>());
			}
			result[depth].push_back(root->val);
			dfs(root->left, depth, max_depth, result);
			dfs(root->right, depth, max_depth, result);
		}
	}
};

int main()
{
    cin.get();
}
