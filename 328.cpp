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
	ListNode* oddEvenList(ListNode* head) {
		if (!head) return head;
		if (!head->next) return head;
		if (!head->next->next) return head;
		ListNode * odd, * even;
		ListNode * odd_tail, * even_tail;
		odd = head;
		even = head->next;
		odd_tail = odd;
		even_tail = even;
		ListNode * p = head->next->next;
		bool is_odd = true;
		while (p)
		{
			if (is_odd)
			{
				odd_tail->next = p;
				odd_tail = odd_tail->next;
			}
			else
			{
				even_tail->next = p;
				even_tail = even_tail->next;
			}
			is_odd = !is_odd;
			p = p->next;
		}
		odd_tail->next = even;
		even_tail->next = NULL;
		return odd;
	}
};

int main()
{
    cin.get();
}
