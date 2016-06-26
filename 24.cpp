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
    ListNode* swapPairs(ListNode* head) {
		ListNode * temp_head;
		temp_head->next = head;
		ListNode *p, *q, *r;
		p = temp_head;
		q = p->next;
		while (q)
		{
			r = q->next;
			if (!r) return temp_head->next;
			p->next = r;
			q->next = r->next;
			r->next = q;
			p = q;
			q = p->next;
		}
		return temp_head->next;
    }
};

int main()
{
    Solution s;
    cin.get();
}
