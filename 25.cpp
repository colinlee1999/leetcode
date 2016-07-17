#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1) return head;
		ListNode * r = new ListNode(0), *s, *p, *q;
		int count;
		r->next = head;
		head = r;
		p = head;
		q = head->next;
		while (q)
		{
			count = 0;
			r = q;
			s = q;
			while (count < k && q)
			{
				count++;
				s = q;
				q = q->next;
			}
			if (count == k)
			{
				s->next = NULL;
				p->next = reverseList(r);
				r->next = q;
				p = r;
			}
		}
		r = head;
		head = head->next;
		delete r;
		return head;
    }

	ListNode* reverseList(ListNode* head) {
		ListNode *p, *q;
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
