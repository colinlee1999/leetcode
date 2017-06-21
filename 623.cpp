#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode * new_root = new TreeNode(v);
			new_root->left = root;
			return new_root;
		}
		else {
			update(root, 1, v, d);
			return root;
		}
	}

private:
	void update(TreeNode* cur, int depth, int v, int d) {
		if (depth + 1 == d) {
			TreeNode* new_left = new TreeNode(v);
			TreeNode* new_right = new TreeNode(v);
			new_left->left = cur->left;
			new_right->right = cur->right;
			cur->left = new_left;
			cur->right = new_right;
			return;
		}
		else if (depth + 1 < d) {
			if (cur->left) {
				update(cur->left, depth + 1, v, d);
			}
			if (cur->right) {
				update(cur->right, depth + 1, v, d);
			}
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
