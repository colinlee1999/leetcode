#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <hash_map>
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int nlen = nums.size();
		int left = 0;
		int right = nlen;
		int mid;
		bool left_ok, right_ok;
		while (left + 1 < right)
		{
			mid = left + (right - left) / 2;
			left_ok = true;
			right_ok = true;
			if (mid - 1 >= 0 && nums[mid - 1] >= nums[mid]) left_ok = false;
			if (mid + 1 < nlen && nums[mid + 1] >= nums[mid]) right_ok = false;
			if (left_ok && right_ok)
			{
				left = mid;
				break;
			}
			if (left_ok) left = mid;
			else right = mid;
		}
		return left;
	}
};

int main()
{
	Solution s;
    cin.get();
}
