#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;
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
			reverse(nums.begin(), nums.end());
			return;
		}
		for (int i = nums.size() - 1; i > pos; i--)
		{
			if (nums[i] > nums[pos])
			{
				int temp = nums[i];
				nums[i] = nums[pos];
				nums[pos] = temp;
				reverse(nums.begin() + pos + 1, nums.end());
				return;
			}
		}
		return;
	}
};

int main()
{
	Solution s;
    cin.get();
}
