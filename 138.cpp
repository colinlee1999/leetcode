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
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode *, int> node_to_int;
		RandomListNode *p = head;
		int count = 0;
		while (p)
		{
			node_to_int[p] = count;
			count++;
			p = p->next;
		}
		vector<RandomListNode *> v;
		RandomListNode *r = new RandomListNode(0), *s;
		s = r;
		p = head;
		while (p)
		{
			RandomListNode *t = new RandomListNode(p->label);
			s->next = t;
			s = t;
			v.push_back(t);
			p = p->next;
		}
		p = head;
		s = r->next;
		while (p)
		{
			if (p->random)
				s->random = v[node_to_int[p->random]];
			s = s->next;
			p = p->next;
		}
		s = r->next;
		delete r;
		return s;
	}
};

int main()
{
    Solution s;
    cin.get();
}
