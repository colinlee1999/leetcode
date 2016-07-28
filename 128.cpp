#include "iostream"
#include "vector"
#include "set"
#include "map"
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s;
		unordered_map<int, bool> tried;
		for (auto it : nums)
		{
			s.insert(it);
			tried[it] = false;
		}
		int result = 1;
		for (auto sit : s)
		{
			if (!tried[sit])
			{
				int left = sit - 1;
				int right = sit + 1;
				int count = 1;
				while (tried.count(left) && !tried[left])
				{
					tried[left] = true;
					left--;
					count++;
				}
				while (tried.count(right) && !tried[right])
				{
					tried[right] = true;
					right++;
					count++;
				}
				result = max(result, count);
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
