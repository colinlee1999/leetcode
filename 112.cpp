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
    bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if ((!root->left) && (!root->right)) return root->val == sum;
		bool found = false;
		if (root->left) found = dfs(root->left, root->val, sum);
		if (found) return true;
		if (root->right) found = dfs(root->right, root->val, sum);
		return found;
    }

	bool dfs(TreeNode * root, int now, int sum)
	{
		now += root->val;
		if ((!root->left) && (!root->right))
		{
			if (now == sum) return true;
			else return false;
		}
		else 
		{
			bool found = false;
			if (root->left) found = dfs(root->left, now, sum);
			if (found) return true;
			if (root->right) found = dfs(root->right, now, sum);
			return found;
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
