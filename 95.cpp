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
	vector<TreeNode*> generateTrees(int n) {
		return generate(1, n);
	}

	vector<TreeNode *> generate(int left, int right)
	{
		if (left <= right)
		{
			vector<TreeNode *> result;
			for (int root = left; root <= right; root++)
			{
				vector<TreeNode *> left_tree, right_tree;
				left_tree = generate(left, root - 1);
				right_tree = generate(root + 1, right);
				if (left_tree.size() == 0) left_tree.push_back(NULL);
				if (right_tree.size() == 0) right_tree.push_back(NULL);
				for (int i = 0; i < left_tree.size(); i++)
					for (int j = 0; j < right_tree.size(); j++)
					{
						TreeNode * t = new TreeNode(root);
						t->left = left_tree[i];
						t->right = right_tree[j];
						result.push_back(t);
					}						
			}
			return result;
		}
		else
			return vector<TreeNode *>();
	}
};

int main()
{
	Solution s;
    cin.get();
}
