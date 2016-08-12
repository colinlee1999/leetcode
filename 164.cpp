#include "iostream"
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int nums_len = nums.size();
		if (nums_len < 2) return 0;
		int largest = 0, smallest = INT_MAX;
		for (auto vit : nums)
		{
			largest = max(largest, vit);
			smallest = min(smallest, vit);
		}
		int interval_len = (largest - smallest) / (nums_len - 1);
		interval_len = interval_len == 0 ? 1 : interval_len;
		int num_intervals = (largest - smallest) / interval_len + 1;
		vector<pair<int, int>> v(num_intervals, pair<int, int>(-1, -1));
		for (auto vit : nums)
		{
			int interval_index = (vit - smallest) / interval_len;
			if (v[interval_index].first == -1)
			{
				v[interval_index].first = vit;
				v[interval_index].second = vit;
			}
			else
			{
				v[interval_index].first = min(v[interval_index].first, vit);
				v[interval_index].second = max(v[interval_index].second, vit);
			}
		}
		int last;
		int result = 0;
		int i = 0;
		for (; i < v.size(); i++)
			if (v[i].first != -1)
			{
				last = v[i].second;
				i++;
				break;
			}
		for (; i < v.size(); i++)
		{
			if (v[i].first != -1)
			{
				result = max(result, v[i].first - last);
				last = v[i].second;
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
