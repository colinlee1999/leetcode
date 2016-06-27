#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m == 0)
		{
			nums1 = nums2;
			return;
		}
		if (n == 0)
			return;
		nums1.resize(m+n);
		int p1, p2;
		p1 = 0;
		p2 = 0;
		while (p1 < m + p2 && p2 < n)
		{
			if (nums1[p1] < nums2[p2]) p1++;
			else
			{
				for (int i = m + p2; i > p1; i--)
					nums1[i] = nums1[i - 1];
				nums1[p1] = nums2[p2];
				p2++;
			}
		}
		if (p1 == m + p2)
		{
			while (p2 < n)
			{
				nums1[p1] = nums2[p2];
				p1++;
				p2++;
			}
		}
    }
};

int main()
{
	Solution s;
	int my1[] = { 1,2,3,4 };
	int my2[] = { 2,2,3,5 };
	int m = 4;
	int n = 4;
	vector<int> v1(my1, my1 + (sizeof(my1) ) / sizeof(int));
	vector<int> v2(my2, my2 + (sizeof(my2)) / sizeof(int));
	s.merge(v1, m, v2, n);
	for (int i = 0;i < m + n;i++)
	{
		cout << v1[i] << ' ';
	}
	cout << endl;
    cin.get();
}
