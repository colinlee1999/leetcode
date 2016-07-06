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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode * fake_head;
		fake_head->next = head;
		ListNode * p, *q;
		p = fake_head;
		q = fake_head->next;
		while (q)
		{
			if (q->val == val)
			{
				p->next = q->next;
				delete q;
				q = p->next;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}
		return fake_head->next;
	}
};

int main()
{
	Solution s;
	cin.get();
}
