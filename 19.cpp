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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p, *q, *r;
		p = head;
		q = head;
		while (n-- > 0) q = q->next;
		while (q)
		{ 
			r = p;
			p = p->next;
			q = q->next;
		}
		if (p == head)
		{
			return head->next;
		}
		else
		{
			r->next = p->next;
			return head;
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
