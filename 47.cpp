#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		result.push_back(nums);
		while (nextPermutation(nums))
			result.push_back(nums);
		return result;
	}
	
    bool nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return false;
		int pos = nums.size();
		for (int i = nums.size() - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1])
			{
				pos = i - 1;
				break;
			}
		}
		if (pos == nums.size())
		{
			return false;
		}
		for (int i = nums.size() - 1; i > pos; i--)
		{
			if (nums[i] > nums[pos])
			{
				int temp = nums[i];
				nums[i] = nums[pos];
				nums[pos] = temp;
				reverse(nums.begin() + pos + 1, nums.end());
				return true;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
    cin.get();
}
