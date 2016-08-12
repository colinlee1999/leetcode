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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		int max_depth = -1;
		dfs(root, -1, max_depth, result);
		return result;
	}

	void dfs(TreeNode * root, int depth, int & max_depth, vector<int> & result)
	{
		if (root)
		{
			depth++;
			if (depth > max_depth)
			{
				max_depth = depth;
				result.push_back(0);
			}
			result[depth] = root->val;
			dfs(root->left, depth, max_depth, result);
			dfs(root->right, depth, max_depth, result);
		}
	}
};

int main()
{
    cin.get();
}
