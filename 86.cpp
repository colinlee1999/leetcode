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
	ListNode* partition(ListNode* head, int x) {
		if (!head) return NULL;
		ListNode * r = new ListNode(0);
		ListNode *s = new ListNode(0);
		ListNode *p, *q, *t;
		p = r;
		q = s;
		t = head;
		while (t)
		{
			if (t->val < x)
			{
				p->next = t;
				p = p->next;
			}
			else
			{
				q->next = t;
				q = q->next;
			}
			t = t->next;
		}
		p->next = s->next;
		q->next = NULL;
		return r->next;
	}
};

int main()
{
    Solution s;
    cin.get();
}
