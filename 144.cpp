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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		stack<TreeNode *> s;
		TreeNode * cur = root;
		while (cur)
		{
			result.push_back(cur->val);
			if (cur->right) s.push(cur->right);
			if (cur->left) cur = cur->left;
			else if (!s.empty())
			{
				cur = s.top();
				s.pop();
			}
			else break;
		}
		return result;
	}
};

int main()
{
	Solution s;
    cin.get();
}
