#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <ctime>
#include <random>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		this->head = head;
		ListNode * p = head;
		len = 0;
		while (p)
		{
			len++;
			p = p->next;
		}
		srand(time(0));
	}

	/** Returns a random node's value. */
	int getRandom() {
		int next = (double)rand() / RAND_MAX * len;
		if (next == len) next--;
		ListNode * p = head;
		while (next > 0)
		{
			p = p->next;
			next--;
		}
		return p->val;
	}

private:
	int len;
	ListNode * head;
};

int main()
{
    cin.get();
}
