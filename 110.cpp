#include "iostream"
#include "vector"
#include "set"
#include "map"
#include "cmath"
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
		bool is_balanced = true;
		get_height(root, is_balanced);
		return is_balanced;
    }

	int get_height(TreeNode * root, bool & is_balanced)
	{
		if (!root) return 0;
		int left, right;
		if (is_balanced) left = get_height(root->left, is_balanced);
		if (is_balanced) right = get_height(root->right, is_balanced);
		if (abs(left - right) > 1)
		{
			is_balanced = false;
			return 0;
		}
		else
		{
			return max(left, right) + 1;
		}
	}
};

int main()
{
    Solution s;
    cin.get();
}
