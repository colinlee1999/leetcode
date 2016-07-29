#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
#include <stack>
#include <map>
#define INT_MIN (1<<31)
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<pair<int, int>> intervals;
		int last_start_pos = 0;
		int result = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			result = max(result, nums[i]);
			if (nums[i] == 0)
			{
				intervals.push_back(pair<int, int>(last_start_pos, i));
				last_start_pos = i + 1;
			}
		}
		intervals.push_back(pair<int, int>(last_start_pos, nums.size()));
		for (auto it : intervals)
		{
			int left = it.first;
			int right = it.second;
			if (left + 1 < right)
			{
				int prod = 1, minus_count = 0;
				for (int i = left; i < right; i++)
				{
					prod *= nums[i];
					if (nums[i] < 0) minus_count++;
				}
				if (minus_count & 1)
				{
					int first_minus_prod, last_minus_prod;
					first_minus_prod = 1;
					for (int i = left; i < right; i++)
					{
						first_minus_prod *= nums[i];
						if (nums[i] < 0) break;
					}
					last_minus_prod = 1;
					for (int i = right - 1; i >= left; i--)
					{
						last_minus_prod *= nums[i];
						if (nums[i] < 0) break;
					}
					prod = max(prod / first_minus_prod, prod / last_minus_prod);
				}
				result = max(result, prod);
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
