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
    ListNode* reverseList(ListNode* head) {
        ListNode *p,*q;
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
