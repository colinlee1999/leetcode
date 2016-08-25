#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		bool found_p, found_q;
		found_p = found_q = false;
		TreeNode * lowest = root;
		int lowest_depth = 0;
		if (dfs(root, p, q, found_p, found_q, lowest, 0, lowest_depth)) return lowest;
		else return NULL;
	}

private:
	bool dfs(TreeNode * root, const TreeNode * p, const TreeNode * q,
		bool & found_p, bool & found_q, TreeNode * & lowest,
		int depth, int & lowest_depth)
	{
		if (!root)
			return false;
		if (found_p || found_q)
		{
			if (found_p && root == q)
				return true;
			if (found_q && root == p)
				return true;
		}
		else
		{
			if (root == p)
				found_p = true;
			if (root == q)
				found_q = true;
			if (found_p || found_q)
			{
				lowest_depth = depth;
				lowest = root;
			}
			if (found_p && found_q) return true;
		}
		if (dfs(root->left, p, q, found_p, found_q, lowest, depth + 1, lowest_depth)) return true;
		if (depth < lowest_depth)
		{
			lowest_depth = depth;
			lowest = root;
		}
		if (dfs(root->right, p, q, found_p, found_q, lowest, depth + 1, lowest_depth)) return true;
		return false;
	}
};

int main()
{
    Solution s;
    cin.get();
}
