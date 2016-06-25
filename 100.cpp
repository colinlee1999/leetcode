#include "iostream"
#include "vector"
#include "set"
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p)
		{
			if (!q) return false;
			if (p->val != q->val) return false;
			if (!isSameTree(p->left, q->left)) return false;
			if (!isSameTree(p->right, q->right)) return false;
			return true;
		}
		else
		{
			if (q) return false;
			return true;
		}
    }
};

int main()
{
    Solution s;
    cin.get();
}
