#include "iostream"
#include "vector"
#include "set"
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int left, right, temp;
		for (int i = 0; i < (int)nums.size() - 2;i++)
		{
			left = i + 1;
			right = (int)nums.size() - 1;
			while (left < right)
			{
				temp = nums[i] + nums[left] + nums[right];
				if (temp == 0)
				{
					if (!result.empty() && result.back()[0] == nums[i] && result.back()[1] == nums[left])
					{
						left++;
						right--;
					}
					else
					{
						vector<int> tv;
						tv.push_back(nums[i]);
						tv.push_back(nums[left]);
						tv.push_back(nums[right]);
						result.push_back(tv);
					}
				}
				else if (temp < 0) left++;
				else right--;
			}
			while (i < (int)nums.size() - 1 && nums[i] == nums[i + 1])
				i++;
		}
		return result;
    }
};

int main()
{
	Solution s;
	vector<int> v;
	s.threeSum(v);
    cin.get();
}
