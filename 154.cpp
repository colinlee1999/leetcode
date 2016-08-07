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
    int findMin(vector<int>& nums) {
		return bi_search(nums, 0, nums.size());
    }

private:
	int bi_search(vector<int> & nums,
		int left,
		int right)
	{
		if (right - left <4)
		{
			int result = INT_MAX;
			for (int i = left; i < right; i++)
				result = min(result, nums[i]);
			return result;
		}
		else
		{
			int mid = left + (right - left) / 2;
			bool left_is_ordered = false;
			if (nums[left] < nums[mid - 1]) left_is_ordered = true;
			if (nums[left] == nums[mid - 1])
			{
				left_is_ordered = true;
				for (int i = left + 1; i < mid - 1; i++)
					if (nums[i] != nums[left])
					{
						left_is_ordered = false;
						break;
					}
			}
			if (left_is_ordered) return min(nums[left], bi_search(nums, mid, right));
			else return bi_search(nums, left, mid);
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
