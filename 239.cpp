#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<pair<int, int>> q;
		vector<int> result;
		if (k == 0) return result;
		for (int i = 0; i < k; i++)
		{
			while (!q.empty() && q.back().first <= nums[i]) q.pop_back();
			q.push_back(pair<int, int>(nums[i], i));
		}
		result.push_back(q.front().first);
		for (int i = k; i < nums.size(); i++)
		{
			if (q.front().second <= i - k) q.pop_front();
			while (!q.empty() && q.back().first <= nums[i]) q.pop_back();
			q.push_back(pair<int, int>(nums[i], i));
			result.push_back(q.front().first);
		}
		return result;
	}
};

int main()
{
    Solution s;
    cin.get();
}
