#include "iostream"
#include "vector"
#include <set>
#include "map"
#include <algorithm>
using namespace std;
 
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		multiset<int> s;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k)
				s.erase(nums[i - k - 1]);
			s.insert(nums[i]);
			auto it = s.find(nums[i]);
			if (it != s.begin() && labs(*(prev(it)) - nums[i]) <= t)
				return true;
			if (next(it) != s.end() && labs(*(next(it)) - nums[i]) <= t)
				return true;
		}
		return false;
	}
};

int main()
{
    Solution s;
    cin.get();
}
