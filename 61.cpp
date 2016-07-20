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
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return head;
		ListNode * p, *q, *s;
		int n = 0;
		p = head;
		while (p)
		{
			n++;
			s = p;
			p = p->next;
		}
		k %= n;
		if (k == 0) return head;
		p = head;
		for (int tk = n - k - 1; tk-- > 0;)
			p = p->next;
		q = p->next;
		s->next = head;
		p->next = NULL;
		return q;
	}
};

int main()
{
    Solution s;
    cin.get();
}
