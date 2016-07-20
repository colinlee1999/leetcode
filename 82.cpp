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
	ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
		ListNode * p, *q, *r, *s;
		r = new ListNode(0);
		r->next = head;
		s = r;
		p = head;
		q = head->next;
		while (q)
		{
			if (q->val == p->val)
			{
				while (q && q->val == p->val) q = q->next;
				s->next = q;
				if (!q) break;
				p = q;
				if (!q->next) break;
				q = q->next;
			}
			else
			{
				s = p;
				p = q;
				q = q->next;
			}
		}
		head = r->next;
		delete r;
		return head;
    }
};

int main()
{
    Solution s;
    cin.get();
}
