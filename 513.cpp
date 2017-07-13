#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_m	ap>
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
	int findBottomLeftValue(TreeNode* root) {
		int result;
		last_depth = -1;
		dfs(0, result, root);
		return result;
	}

private:
	void dfs(int depth, int& result, TreeNode* cur) {
		if (!cur) return;
		if (depth > last_depth) {
			last_depth = depth;
			result = cur->val;
		}
		dfs(depth + 1, result, cur->left);
		dfs(depth + 1, result, cur->right);
	}

	int last_depth;
};

int main()
{
	Solution s;
	cin.get();
}
