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
	int searchInsert(vector<int>& nums, int target) {
		return bi_search(nums, 0, nums.size(), target);
	}

private:
	int bi_search(vector<int> & nums, int left, int right, int target)
	{
		if (right - left <= 1)
		{
			if (right - left == 1 && nums[left] >= target)  return left;
			return right;
		}
		else
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] > target) return bi_search(nums, left, mid, target);
			else return bi_search(nums, mid, right, target);
		}
	}
};

int main()
{
	Solution s;
    cin.get();
}
