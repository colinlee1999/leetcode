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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
		ListNode *head, *p, *q, *r, *s;
		if (l1->val <= l2->val)
		{
			p = l1;
			q = l2;
		}
		else
		{
			p = l2;
			q = l1;
		}
		head = p;
		while (q)
		{
			s = q;
			q = q->next;
			r = p->next;
			while (r && r->val <= s->val)
			{
				p = r;
				r = r->next;
			}
			if (!r)
			{
				p->next = s;
				return head;
			}
			else
			{
				p->next = s;
				s->next = r;
				p = p->next;
			}			
		}
		return head;
    }
};

int main()
{
    Solution s;
    cin.get();
}
