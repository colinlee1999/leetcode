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
	void reorderList(ListNode* head) {
		int len = 0;
		ListNode *p = head, *q;
		while (p)
		{
			len++;
			p = p->next;
		}
		if (len == 0) return;
		p = head;
		int count = 1;
		int target = (len + 1) / 2;
		while (count++ < target)
			p = p->next;
		q = p->next;
		p->next = NULL;
		q = reverseList(q);
		p = head;
		while (q)
		{
			ListNode *r, *s;
			r = p;
			p = p->next;
			s = q;
			q = q->next;
			r->next = s;
			s->next = p;
		}
	}

private:
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
