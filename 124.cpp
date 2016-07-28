#include "iostream"
#include "vector"
#include "set"
#include "map"
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		if (!root) return 0;
		pair<long long, long long> result = dfs(root);
		return max(result.first, result.second);
	}

	pair<long long, long long> dfs(TreeNode * root) // first means starting from root, second means anyway
	{
		if (!root->left && !root->right)
			return pair<long long, long long>(root->val, root->val);
		pair<long long, long long> left_result(INT_MIN, INT_MIN), right_result(INT_MIN, INT_MIN);
		if (root->left) left_result = dfs(root->left);
		if (root->right) right_result = dfs(root->right);
		long long first = root->val;
		first = max(first, root->val + left_result.first);
		first = max(first, root->val + right_result.first);
		long long second = max(left_result.second, right_result.second);
		second = max(second, first);
		second = max(second, root->val + left_result.first + right_result.first);
		return pair<long long, long long>(first, second);
	}
};

int main()
{
    Solution s;
    cin.get();
}
