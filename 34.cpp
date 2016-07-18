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
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		result.push_back(bi_search(nums,
			0,
			nums.size(),
			target,
			true));
		result.push_back(bi_search(nums,
			0,
			nums.size(),
			target,
			false));
		return result;
	}

private:
	int bi_search(vector<int> & nums, int left, int right, int target, bool priority)
	{
		if (right - left <= 1)
		{
			if (right >= left + 1 && nums[left] == target) return left;
			return -1;
		}
		else
		{
			int mid = left + (right - left) / 2;
			if (priority)
			{
				if (nums[mid - 1] >= target) return bi_search(nums, left, mid, target, priority);
				return bi_search(nums, mid, right, target, priority);
			}
			else
			{
				if (nums[mid] <= target) return bi_search(nums, mid, right, target, priority);
				return bi_search(nums, left, mid, target, priority);
			}
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
