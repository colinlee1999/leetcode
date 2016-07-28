#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		RandomListNode newHead(0), *p = head, *t = NULL;
		while (p)
		{
			RandomListNode *cloned = new RandomListNode(p->label);
			cloned->next = p->next;
			p->next = cloned;
			p = cloned->next;
		}

		p = head;
		while (p && p->next)
		{
			if (p->random) p->next->random = p->random->next;
			p = p->next->next;
		}

		p = head;
		t = &newHead;
		while (p && p->next)
		{
			t->next = p->next;
			p->next = p->next->next;
			t = t->next;
			p = p->next;
		}
		t->next = NULL;
		return newHead.next;
	}
};

int main()
{
    Solution s;
    cin.get();
}
