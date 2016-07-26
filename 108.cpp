#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return build(nums, 0, nums.size());
	}

private:
	TreeNode * build(vector<int> & nums, int left, int right)
	{
		if (left >= right) return NULL;
		int mid = left + (right - left) / 2;
		TreeNode * cur_node = new TreeNode(nums[mid]);
		TreeNode * left_tree = build(nums, left, mid);
		TreeNode * right_tree = build(nums, mid + 1, right);
		cur_node->left = left_tree;
		cur_node->right = right_tree;
		return cur_node;
	}
};

int main()
{
    cin.get();
}
