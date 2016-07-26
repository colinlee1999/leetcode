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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack< TreeNode *> node_stack;
		TreeNode * pNode = root;
		while (pNode || !node_stack.empty()) {
			if (pNode != NULL) {
				node_stack.push(pNode);
				pNode = pNode->left;
			}
			else {
				pNode = node_stack.top();
				node_stack.pop();
				result.push_back(pNode->val);
				pNode = pNode->right;
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
    cin.get();
}
