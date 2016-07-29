#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode *r = new ListNode(0), *p, *q, *s;
		while (head)
		{
			p = r;
			q = r->next;
			while (q)
			{
				if (q->val >= head->val) break;
				p = q;
				q = q->next;
			}
			s = head;
			head = head->next;
			p->next = s;
			s->next = q;
		}
		s = r->next;
		delete r;
		return s;
	}
};

int main()
{
	Solution s;
    cin.get();
}
