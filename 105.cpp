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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		if (inorder.size() != preorder.size()) return NULL;
		return build(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)preorder.size());
	}

private:
	TreeNode * build(vector<int> & preorder,
		int pre_left,
		int pre_right,
		vector<int> & inorder,
		int in_left,
		int in_right)
	{
		if (in_left > in_right) return NULL;
		if (pre_right < pre_left) return NULL;
		TreeNode * cur_node;
		for (int i = in_left; i <= in_right; i++)
			if (inorder[i] == preorder[pre_left])
			{
				TreeNode * left_tree = build(preorder, pre_left + 1, pre_left + i - in_left, inorder, in_left, i - 1);
				TreeNode * right_tree = build(preorder, pre_left + i - in_left + 1, pre_right, inorder, i + 1, in_right);
				cur_node = new TreeNode(0);
				cur_node->val = inorder[i];
				cur_node->left = left_tree;
				cur_node->right = right_tree;
				break;
			}
		return cur_node;
	}
};

int main()
{
    cin.get();
}
