#include "iostream"
#include "vector"
#include "set"
#include "map"
#include "cmath"
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		bool is_symmetric = true;
		dfs(root->left, root->right, is_symmetric);
		return is_symmetric;
    }

	void dfs(TreeNode * left, TreeNode * right, bool & is_symmetric)
	{
		if (!left)
		{
			if (right) is_symmetric = false;
			return;
		}
		else
		{
			if (!right)
			{	
				is_symmetric = false;
				return;
			}
			if (left->val != right->val)
				is_symmetric = false;
			if (is_symmetric) dfs(left->left, right->right, is_symmetric);
			if (is_symmetric) dfs(left->right, right->left, is_symmetric);
		}
	}
};

int main()
{
    Solution s;
    cin.get();
}
