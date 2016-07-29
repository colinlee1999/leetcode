#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode* & head, int start, int end) {
		if (start > end) return NULL;
		int mid = start + (end - start) / 2;
		TreeNode* left = sortedListToBST(head, start, mid - 1);
		TreeNode* parent = new TreeNode(head->val);
		parent->left = left;
		head = head->next;
		TreeNode* right = sortedListToBST(head, mid + 1, end);
		parent->right = right;
		return parent;
	}

	TreeNode *sortedListToBST(ListNode *head) {
		int length = 0;
		ListNode* node = head;
		while (node != NULL) {
			length++;
			node = node->next;
		}
		return sortedListToBST(head, 0, length - 1);
	}
};

int main()
{
	Solution s;
    cin.get();
}
