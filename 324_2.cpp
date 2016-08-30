#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <algorithm>
#include <ctime>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();

		// Find a median.
		auto midptr = nums.begin() + n / 2;
		nth_element(nums.begin(), midptr, nums.end());
		int mid = *midptr;

		// Index-rewiring.
		#define A(i) nums[(1+2*(i)) % (n|1)]

		// 3-way-partition-to-wiggly in O(n) time with O(1) space.
		int i = 0, j = 0, k = n - 1;
		while (j <= k) {
			if (A(j) > mid)
				swap(A(i++), A(j++));
			else if (A(j) < mid)
				swap(A(j), A(k--));
			else
				j++;
		}
	}
};

int main()
{
	Solution s;
	// int myInt[] = { 1,5,1,1,6,4 };
	int myInt[] = { 2,3,3,2,2,2,1,1 };
	// int myInt[] = { 1 };
	vector<int> v(myInt, myInt + sizeof(myInt) / sizeof(int));
	s.wiggleSort(v);
	for (auto it : v)
		cout << it << ' ';
	cout << endl;
    cin.get();
}
