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
    TreeNode* invertTree(TreeNode* root) {
        if (root)
        {
            TreeNode * temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

int main()
{
    Solution s;
    TreeNode * r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    cout<<s.invertTree(r)<<endl;
    cin.get();
}
