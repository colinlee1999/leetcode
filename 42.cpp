#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> prev_height;
		stack<int> prev_pos;
		vector<int> height_sum(height.size() + 1, 0);
		vector<int> total_water(height.size(), 0);
		int max_water = 0;
		for (int i = 0; i < height.size(); i++)
		{
			height_sum[i + 1] = height_sum[i] + height[i];
			if (prev_height.empty())
			{
				prev_height.push(height[i]);
				prev_pos.push(i);
			}
			else
			{
				int last_height = 0;
				int last_pos = 0;
				while (!prev_height.empty() && height[i] >= prev_height.top())
				{
					last_height = prev_height.top();
					last_pos = prev_pos.top();
					prev_height.pop();
					prev_pos.pop();
				}
				if (prev_height.empty())
				{
					total_water[i] = (i - last_pos - 1) * last_height - height_sum[i] + height_sum[last_pos + 1] + total_water[last_pos];
					prev_height.push(height[i]);
					prev_pos.push(i);
				}
				else
				{
					total_water[i] = (i - prev_pos.top() - 1) * height[i] - height_sum[i] + height_sum[prev_pos.top() + 1] + total_water[prev_pos.top()];
					prev_height.push(height[i]);
					prev_pos.push(i);
				}
				max_water = max(max_water, total_water[i]);
			}
		}
		return max_water;
	}
};

int main()
{
	Solution s;
    cin.get();
}
