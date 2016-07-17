#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		set<vector<int>> mid_result;
		int left, right, temp;
		for (int i = 0; i < (int)nums.size() - 3; i++)
		{
			for (int j = i + 1; j < (int)nums.size() - 2; j++)
			{
				left = j + 1;
				right = (int)nums.size() - 1;
				while (left < right)
				{
					temp = nums[i] + nums[j] + nums[left] + nums[right];
					if (temp == target)
					{
						vector<int> tv;
						tv.push_back(nums[i]);
						tv.push_back(nums[j]);
						tv.push_back(nums[left]);
						tv.push_back(nums[right]);
						mid_result.insert(tv);
						left++;
						right--;
					}
					else if (temp < target) left++;
					else right--;
				}
			}
		}
		for (auto it : mid_result)
			result.push_back(it);
		return result;
    }
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(-1);
	v.push_back(0);
	v.push_back(-2);
	v.push_back(2);
	s.fourSum(v,0);
    cin.get();
}
