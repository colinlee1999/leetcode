#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <algorithm>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		TreeLinkNode * prev;
		TreeLinkNode * row_start;
		TreeLinkNode * cur_node = root;
		int status = 0;
		while (true)
		{
			while (cur_node && !cur_node->left && !cur_node->right) cur_node = cur_node->next;
			if (!cur_node) break;
			if (cur_node->left)
			{
				row_start = cur_node->left;
				prev = cur_node;
				status = 1;
			}
			else
			{
				row_start = cur_node->right;
				prev = cur_node->next;
				status = 0;
			}
			cur_node = row_start;
			while (prev)
			{
				switch (status)
				{
				case 0:
					if (prev->left)
					{
						cur_node->next = prev->left;
						cur_node = cur_node->next;
					}
					status = 1;
					break;
				case 1:
					if (prev->right)
					{
						cur_node->next = prev->right;
						cur_node = cur_node->next;
					}
					prev = prev->next;
					status = 0;
					break;
				default:
					break;
				}
			}
			cur_node = row_start;
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
