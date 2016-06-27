#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA) return NULL;
		if (!headB) return NULL;
		int l1 = 0;
		int l2 = 0;
		ListNode *p, *q, *r, *s;
		p = headA;
		while (p)
		{
			l1++;
			q = p;
			p = p->next;
		}
		r = headB;
		while (r)
		{
			l2++;
			s = r;
			r = r->next;
		}
		if (q != s) return NULL;
		p = headA;
		r = headB;
		while (l1 > l2)
		{
			l1--;
			p = p->next;
		}
		while (l1 < l2)
		{
			l2--;
			r = r->next;
		}
		while (p)
		{
			if (p == r) return p;
			else
			{
				p = p->next;
				r = r->next;
			}
		}
		return NULL;
    }
};

int main()
{
    cin.get();
}
