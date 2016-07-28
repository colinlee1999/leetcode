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
	ListNode *detectCycle(ListNode *head) {
		int len = get_cycle_length(head);
		if (len == -1) return NULL;
		ListNode * p = head, *q = head;
		while (len-- > 0) q = q->next;
		while (p != q)
		{
			p = p->next;
			q = q->next;
		}
		return p;
	}

private:
	int get_cycle_length(ListNode *head) {
		if (!head) return -1;
		ListNode *p, *q;
		p = head;
		q = head;
		while (q)
		{
			p = p->next;
			q = q->next;
			if (!q) return -1;
			q = q->next;
			if (!q) return -1;
			if (p == q) break;
		}
		q = q->next;
		int count = 1;
		while (p != q)
		{
			q = q->next;
			count++;
		}
		return count;
    }
};

int main()
{
    Solution s;
	ListNode * p = new ListNode(1);
	ListNode * q = new ListNode(2);
	p->next = q;
	cout << s.detectCycle(p) << endl;
    cin.get();
}
