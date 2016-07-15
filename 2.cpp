#include "iostream"
#include "vector"
#include "set"
#include <sstream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if ((!l1) && (!l2)) return NULL;
		ListNode * head = new ListNode(0);
		ListNode * p, *q, *r;
		p = l1;
		q = l2;
		r = head;
		int carry = 0;
		while (p && q)
		{
			ListNode *temp = new ListNode((carry + p->val + q->val) % 10);
			r->next = temp;
			r = temp;
			carry = (carry + p->val + q->val) / 10;
			p = p->next;
			q = q->next;
		}
		while (p)
		{
			ListNode *temp = new ListNode((carry + p->val) % 10);
			r->next = temp;
			r = temp;
			carry = (carry + p->val) / 10;
			p = p->next;
		}
		while (q)
		{
			ListNode *temp = new ListNode((carry + q->val) % 10);
			r->next = temp;
			r = temp;
			carry = (carry + q->val) / 10;
			q = q->next;
		}
		if (carry)
		{
			ListNode *temp = new ListNode(carry);
			r->next = temp;
		}
		r = head;
		head = head->next;
		delete r;
		return head;
    }
};

int main()
{
    Solution s;
    cin.get();
}
