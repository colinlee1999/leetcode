#include "iostream"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
      int max_depth = 0;
      if (root)
      	dfs(root, 0, max_depth);
      return max_depth;
    }

    void dfs(TreeNode* tree, int cur_depth, int & max_depth)
    {
    	cur_depth++;
		if (cur_depth>max_depth) max_depth = cur_depth;
		if (tree->left)
            dfs(tree->left, cur_depth, max_depth);
        if (tree->right)
            dfs(tree->right, cur_depth, max_depth);
    }
};

int main()
{
    Solution s;
    TreeNode * r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    cout<<s.maxDepth(r)<<endl;
    cin.get();
}
