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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
		ListNode *p, *q;
		p = head;
		q = head;
		while (q)
		{
			p = p->next;
			q = q->next;
			if (!q) break;
			q = q->next;
			if (p == q) return true;
		}
		return false;
    }
};

int main()
{
    Solution s;
    cin.get();
}
