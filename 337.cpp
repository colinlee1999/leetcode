#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <ctime>
#include <random>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int rob(TreeNode* root) {
		if (!root) return 0;
		int contain_root, not_contain_root;
		return dfs(root, contain_root, not_contain_root);
	}

private:
	int dfs(const TreeNode * root, int & contain_root, int & not_contain_root)
	{
		if (!root->left && !root->right)
		{
			contain_root = root->val;
			not_contain_root = 0;
		}
		else
		{
			int left_contain_root, left_not_contain_root;
			int right_contain_root, right_not_contain_root;
			int left_best, right_best;
			left_contain_root = left_not_contain_root = 0;
			right_contain_root = right_not_contain_root = 0;
			left_best = right_best = 0;
			if (root->left) left_best = dfs(root->left, left_contain_root, left_not_contain_root);
			if (root->right) right_best = dfs(root->right, right_contain_root, right_not_contain_root);
			contain_root = root->val + left_not_contain_root + right_not_contain_root;
			not_contain_root = left_best + right_best;
		}
		return max(contain_root, not_contain_root);
	}
};

int main()
{
    cin.get();
}
