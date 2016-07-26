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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() == 0) return NULL;
		if (inorder.size() != postorder.size()) return NULL;
		return build(postorder, 0, (int)postorder.size() - 1, inorder, 0, (int)postorder.size() - 1);
	}

private:
	TreeNode * build(vector<int> & postorder,
		int post_left,
		int post_right,
		vector<int> & inorder,
		int in_left,
		int in_right)
	{
		if (in_left > in_right) return NULL;
		if (post_right < post_left) return NULL;
		TreeNode * cur_node;
		for (int i = in_right; i >= in_left; i--)
			if (inorder[i] == postorder[post_right])
			{
				TreeNode * left_tree = build(postorder, post_left, post_right + i - in_right - 1, inorder, in_left, i - 1);
				TreeNode * right_tree = build(postorder, post_right - in_right + i, post_right - 1, inorder, i + 1, in_right);
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
