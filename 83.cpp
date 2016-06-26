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
		ListNode * p, *q;
		p = head;
		q = head->next;
		while (q)
		{
			if (q->val == p->val)
			{
				q = q->next;
				p->next = q;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}
		return head;
    }
};

int main()
{
    Solution s;
    cin.get();
}
