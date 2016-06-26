#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode* root) {
		int max_depth = -1;
		vector<vector<int> > temp_result, result;
		if (root) dfs(root, 0, max_depth, temp_result);
		for (vector<vector<int> >::reverse_iterator it = temp_result.rbegin(); it != temp_result.rend(); ++it)
		{
			result.push_back(*it);
		}
		return result;
	}

	void dfs(TreeNode * root, int depth, int & max_depth, vector<vector<int> > & temp_result)
	{
		if (depth > max_depth)
		{
			max_depth = depth;
			temp_result.push_back(vector<int>());
		}
		temp_result[depth].push_back(root->val);
		if (root->left)
			dfs(root->left, depth + 1, max_depth, temp_result);
		if (root->right)
			dfs(root->right, depth + 1, max_depth, temp_result);
	}
};

int main()
{
    Solution s;
    cin.get();
}
