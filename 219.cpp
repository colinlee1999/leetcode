#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (k==0) return false;
		set<int> s;
		int i;
		for (i = 0; i < min(k,(int)nums.size()); i++)
		{
			if (s.find(nums[i]) != s.end()) return true;
			s.insert(nums[i]);
		}
		for (;i < nums.size(); i++)
		{
			if (s.find(nums[i]) != s.end()) return true;
			s.erase(nums[i - k]);
			s.insert(nums[i]);
		}
		return false;
	}
};

int main()
{
	Solution s;
	cin.get();
}
