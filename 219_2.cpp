#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (k==0) return false;
		
		unordered_map<int, int> m;
		unordered_map<int, int>::iterator iter;
		for (int i = 0; i < nums.size(); i++)
		{
			if ((iter = m.find(nums[i])) != m.end())
			{
				if (i - iter->second <= k)
					return true;
				else
					iter->second = i;
			}
			else
			{
				m.insert(pair<int, int>(nums[i], i));
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	cin.get();
}
