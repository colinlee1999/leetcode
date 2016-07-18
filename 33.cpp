#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <hash_map>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		return bi_search(nums, 0, nums.size(), target);
    }

private:
	int bi_search(vector<int> & nums,
		int left,
		int right,
		int target)
	{
		if (right - left <4)
		{
			if (right >= left + 1 && nums[left] == target) return left;
			if (right >= left + 2 && nums[left+1] == target) return left+1;
			if (right >= left + 3 && nums[left+2] == target) return left+2;
			return -1;
		}
		else
		{
			int mid = (left + right) / 2;
			bool left_is_ordered = false;
			if (nums[left] < nums[mid - 1]) left_is_ordered = true;
			if (left_is_ordered && (nums[left] <= target && nums[mid - 1] >= target))
				return bi_search(nums, left, mid, target);
			if (!left_is_ordered && (nums[left] <= target || nums[mid - 1] >= target))
				return bi_search(nums, left, mid, target);
			return bi_search(nums, mid, right, target);
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
