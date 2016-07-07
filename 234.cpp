#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head) return true;
		if (!(head->next)) return true;
		ListNode * slow, *fast, * half_list;
		slow = head;
		fast = head->next;
		while (fast)
		{
			if (fast->next && fast->next->next)
			{
				fast = fast->next->next;
				slow = slow->next;
			}
			else
			{
				break;
			}
		}
		if (!(fast->next))
		{
			half_list = reverseList(slow->next);
		}
		else
		{
			half_list = reverseList(slow->next->next);
		}
		slow->next = NULL;
		slow = head;
		fast = half_list;
		while (slow)
		{
			if (slow->val != fast->val) return false;
			slow = slow->next;
			fast = fast->next;
		}
		return true;
	}

	ListNode* reverseList(ListNode* head) {
        ListNode *p,*q;
		ListNode *r;
        if (!head) return head;
		p = head;
		if (!head->next) return head;
		q = head->next;
		head->next = NULL;
		while (q)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		return p;
    }
};

int main()
{
	Solution s;
	cin.get();
}
