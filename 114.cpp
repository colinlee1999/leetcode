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
	void flatten(TreeNode* root) {
		TreeNode * last_visited = NULL;
		_flatten(root, last_visited);
	}

private:
	TreeNode * _flatten(TreeNode * root, TreeNode * & last_visited)
	{
		if (!root) return NULL;
		last_visited = root;
		if (!root->right)
		{
			root->right = _flatten(root->left, last_visited);
			root->left = NULL;
			_flatten(root->right, last_visited);
		}
		else if (!root->left)
			_flatten(root->right, last_visited);
		else
		{
			TreeNode * right_tree = root->right;
			TreeNode * left_tree = root->left;
			TreeNode * left_tree_right_most = NULL;
			root->right = _flatten(left_tree, left_tree_right_most);
			root->left = NULL;
			left_tree_right_most->right = right_tree;
			_flatten(right_tree, last_visited);
		}
		return root;
	}
};

int main()
{
    cin.get();
}
