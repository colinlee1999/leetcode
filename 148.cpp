#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head) return head;
		int len = 0;
		ListNode * p = head;
		while (p)
		{
			len++;
			p = p->next;
		}
		ListNode * _head = head;
		merge_sort(_head, 0, len);
		return head;
	}

private:
	void merge_sort(ListNode * & head, int left, int right)
	{
		if (left + 1 == right)
		{
			head = head->next;
			return;
		}
		else
		{
			int mid = left + (right - left) / 2;
			ListNode * left_head = head;
			merge_sort(head, left, mid);
			ListNode * right_head = head;
			merge_sort(head, mid, right);
			merge(left_head, right_head, left, mid, right);
		}
	}

	void merge(ListNode * left_head, ListNode * right_head, int left, int mid, int right)
	{
		//cout << "==============================" << endl;
		//cout << "[" << left << "," << mid << "," << right << "]" << endl;
		ListNode * p, *q; // for left_head
		ListNode * r, * s; // for right_head
		int left_target = mid - left;
		int right_target = right - mid;
		
		//cout << "left:" << endl;
		p = left_head;
		int left_count = 1;
		while (left_count++ < left_target)
		{
			//cout << p->val << endl;
			p = p->next;
		}
		p->next = NULL;

		//cout << "right:" << endl;
		r = right_head;
		int right_count = 1;
		while (right_count++ < right_target)
		{
			//cout << r->val << endl;
			r = r->next;
		}
		//cout << endl;
		ListNode * right_tail = r->next;
		r->next = NULL;
		
		if (right_head->val < left_head->val)
		{
			swap(right_head->val, left_head->val);
			ListNode * node = right_head;
			right_head = right_head->next;
			node->next = NULL;
			
			p = left_head;
			q = p->next;
			while (q)
			{
				if (q->val >= node->val)
					break;
				p = q;
				q = q->next;
			}
			node->next = p->next;
			p->next = node;
		}
		p = left_head;
		q = p->next;
		r = right_head;
		while(r)
		{
			while (q)
			{
				if (q->val >= r->val)
					break;
				p = q;
				q = q->next;
			}
			if (!q) break;
			ListNode * node = r;
			r = r->next;
			node->next = q;
			p->next = node;
			p = node;
		}
		if (!q) p->next = r;
		while (p->next) p = p->next;
		p->next = right_tail;
	}
};

int main()
{
	Solution s;
    cin.get();
}
