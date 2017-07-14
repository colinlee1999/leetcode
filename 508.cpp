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

typedef unordered_map<int, int> UMAP_I_I;
typedef vector<int> VI;

class Solution {
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		UMAP_I_I umap;
		dfs(umap, root);
		int max_count = 0;
		for (auto it : umap) {
			if (it.second > max_count)
				max_count = it.second;
		}
		VI result;
		for (auto it : umap) {
			if (it.second == max_count) {
				result.push_back(it.first);
			}
		}
		return result;
	}

private:
	int dfs(UMAP_I_I& umap, TreeNode* cur) {
		if (!cur) return 0;
		int left = dfs(umap, cur->left);
		int right = dfs(umap, cur->right);
		int total = left + right + cur->val;
		if (umap.find(total) == umap.end()) {
			umap[total] = 1;
		}
		else {
			++umap[total];
		}
		return total;
	}
};

int main()
{
	Solution s;
	cin.get();
}
