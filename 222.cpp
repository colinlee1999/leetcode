#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		int depth1;
		int depth2;
		depth1 = depth2 = 0;
		TreeNode * p = root->left;
		while (p)
		{
			depth1++;
			p = p->left;
		}
		p = root->left;
		while (p)
		{
			depth2++;
			p = p->right;
		}
		cout << depth1 << "\t" << depth2 << endl;
		if (depth1 == depth2)
			return 1 + (~(-(1 << depth2))) + countNodes(root->right);
		else
			return 1 + (~(-(1 << depth2))) + countNodes(root->left);
	}
};

int main()
{
    Solution s;
    cin.get();
}
