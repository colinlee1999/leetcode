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
#include <list>
#include <utility>

#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		sum = 0;
		last_used = false;
		dfs(root);
		return root;
	}

private:
	int sum;
	int last_sum;
	int last_num;
	bool last_used;

	void dfs(TreeNode* cur) {
		if (!cur) return;
		if (cur->right) {
			dfs(cur->right);
		}
		int c_val = cur->val;
		if (last_used) {
			if (c_val == last_num) {
				last_sum += c_val;
				cur->val += sum;
			}
			else {
				sum += last_sum;
				cur->val += sum;
				last_sum = c_val;
			}
		}
		else {
			last_used = true;
			last_num = c_val;
			last_sum = c_val;
		}
		if (cur->left) {
			dfs(cur->left);
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
