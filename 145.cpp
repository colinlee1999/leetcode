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
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode *> s;
		stack<int> instruction;
		vector<int> result;
		if (!root) return result;
		s.push(root);
		instruction.push(0);
		while (!s.empty())
		{
			TreeNode * cur_node = s.top();
			int cur_instruction = instruction.top();
			switch (cur_instruction)
			{
			case 0:
				instruction.top() = 1;
				if (cur_node->left)
				{
					s.push(cur_node->left);
					instruction.push(0);
				}
				break;
			case 1:
				instruction.top() = 2;
				if (cur_node->right)
				{
					s.push(cur_node->right);
					instruction.push(0);
				}
				break;
			case 2:
				instruction.top() = 3;
				result.push_back(cur_node->val);
				break;
			case 3:
				s.pop();
				instruction.pop();
				break;
			default:
				break;
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
