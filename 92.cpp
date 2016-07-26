#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode * r = new ListNode(0);
		r->next = head;
		ListNode *p, *q, *s, *t;
		int left = 1, right;
		p = r;
		q = head;
		while (left < m)
		{
			p = q;
			q = q->next;
			left++;
		}
		s = p;
		t = q;
		right = left;
		while (right < n)
		{
			s = t;
			t = t->next;
			right++;
		}
		s->next = NULL;
		p->next = reverseList(q);
		q->next = t;
		head = r->next;
		delete r;
		return head;
	}

private:
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
