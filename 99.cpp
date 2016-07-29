#include "iostream"
#include "vector"
#include "set"
#include <sstream>
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
	void recoverTree(TreeNode* root) {
		if (!root) return;
		TreeNode * prev = NULL;
		TreeNode * first = NULL, *second = NULL;
		inorder(root, prev, first, second);
		int temp = first->val;
		first->val = second->val;
		second->val = temp;
	}

private:
	void inorder(TreeNode * root, TreeNode * & prev, TreeNode * & first, TreeNode * & second)
	{
		if (root->left)
			inorder(root->left, prev, first, second);
		if (prev && prev->val > root->val)
		{
			if (!first) first = prev;
			second = root;
		}
		prev = root;
		if (root->right)
			inorder(root->right, prev, first, second);
	}
};

int main()
{
	Solution s;
    cin.get();
}
