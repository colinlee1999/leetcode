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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if (n == 0)
			return NULL;
		if (n == 1)
			return lists[0];
		if (n == 2)
			return mergeTwoLists(lists[0], lists[1]);
		vector<ListNode*> v1(lists.begin(), lists.begin() + n / 2);
		vector<ListNode*> v2(lists.begin() + n / 2, lists.end());
		return mergeTwoLists(
			mergeKLists(v1),
			mergeKLists(v2));
	}

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
		ListNode *head, *p, *q, *r, *s;
		head = new ListNode(0);
		r = head;
		p = l1;
		q = l2;
		while (p && q)
		{
			if (p->val < q->val)
			{
				r->next = p;
				p = p->next;
			}
			else
			{
				r->next = q;
				q = q->next;
			}
			r = r->next;
		}
		if (p) r->next = p;
		if (q) r->next = q;
		r = head;
		head = head->next;
		delete r;
		return head;
    }
};

int main()
{
    Solution s;
    cin.get();
}
