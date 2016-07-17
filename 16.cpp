#include "iostream"
#include "vector"
#include "set"
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int left, right, temp, result = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < (int)nums.size() - 2;i++)
		{
			left = i + 1;
			right = (int)nums.size() - 1;
			while (left < right)
			{
				temp = nums[i] + nums[left] + nums[right];
				if (abs(temp - target) < abs(result - target)) result = temp;
				if (temp == target) return target;
				else if (temp < target) left++;
				else right--;
			}
		}
		return result;
    }
};

int main()
{
	Solution s;
    cin.get();
}
