#include "iostream"
#include "vector"
#include "set"
#include "sstream"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (!root) return result;
		ostringstream s;
		s << root->val;
		dfs(root, s.str(), result);
		return result;
    }

	void dfs(TreeNode * root, string path, vector<string> & result)
	{
		if (!root->left && !root->right)
		{
			result.push_back(path);
			return;
		}
		else
		{
			path += "->";
			if (root->left)
			{
				ostringstream s;
				s << root->left->val;
				dfs(root->left, path + s.str(), result);
			}
			if (root->right)
			{
				ostringstream s;
				s << root->right->val;
				dfs(root->right, path + s.str(), result);
			}
		}
	}
};

int main()
{
    Solution s;
    cin.get();
}
