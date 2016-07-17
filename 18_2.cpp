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
		vector<vector<int>> mid_result;
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
						mid_result.push_back(tv);
						left++;
						right--;
					}
					else if (temp < target) left++;
					else right--;
				}
			}
		}
		sort(mid_result.begin(), mid_result.end(), my_comp_func);
		for (auto it : mid_result)
		{
			if (!result.empty())
			{
				if (it[0] == result.back()[0] && it[1] == result.back()[1] && it[2] == result.back()[2] && it[3] == result.back()[3])
					continue;
				result.push_back(it);
			}
			else
			{
				result.push_back(it);
			}
		}
		return result;
	}

	struct
	{
		bool operator()(const vector<int> & a, const vector<int> & b)
		{
			for (int i = 0; i < 4; i++)
			{
				if (a[i] > b[i]) return false;
				else if (a[i] < b[i]) return true;
			}
			return false;
		}
	} my_comp_func;
};

int main()
{
	Solution s;
	int myint[] = { -4, -7, 3, -8, 6, 8, 5, 0, -8, -6, 6, 1, -1, 0, -10, 4, -1 };
	vector<int> v(myint, myint + sizeof(myint) / sizeof(int));
	for (auto it : s.fourSum(v,4))
	{
		for (auto it2 : it)
			cout<<it2<<' ';
		cout<<endl;
	}
    cin.get();
}
