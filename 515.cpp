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

typedef vector<int> VI;

class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		VI result;
		dfs(result, 0, root);
		return result;
	}
	
private:
	void dfs(VI& result, int depth, TreeNode* cur) {
		if (!cur) return;
		if (depth >= result.size()) {
			result.push_back(cur->val);
		}
		result[depth] = max(result[depth], cur->val);
		dfs(result, depth + 1, cur->left);
		dfs(result, depth + 1, cur->right);
	}

	int max(int a, int b) {
		if (a > b) return a;
		else return b;
	}
};

int main()
{
	Solution s;
	cin.get();
}
