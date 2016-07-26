#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
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
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		return dfs(root, INT_MIN, INT_MAX);
	}

private:
	bool dfs(TreeNode * root, long long left, long long right)
	{
		if (root->val < left) return false;
		if (root->val > right) return false;
		bool dfs_left = true, dfs_right = true;
		if (root->left)  dfs_left = dfs(root->left, left, (long long)root->val - 1);
		if (root->right) dfs_right = dfs(root->right, (long long)root->val + 1, right);
		return dfs_left && dfs_right;
	}
};

int main()
{
	Solution s;
    cin.get();
}
