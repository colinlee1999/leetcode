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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		if (!root) return result;
		vector<int> cur_seq;
		dfs(root, sum, cur_seq, result);
		return result;
	}

private:
	void dfs(TreeNode * root,
		int sum,
		vector<int> & cur_seq,
		vector<vector<int>> & result)
	{
		cur_seq.push_back(root->val);
		sum -= root->val;
		if (!root->left && !root->right)
		{
			if (sum == 0) result.push_back(cur_seq);
		}
		else
		{
			if (root->left) dfs(root->left, sum, cur_seq, result);
			if (root->right) dfs(root->right, sum, cur_seq, result);
		}
		cur_seq.pop_back();
	}
};

int main()
{
    cin.get();
}
