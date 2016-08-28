#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <algorithm>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() < 3) return false;
		vector<int> l(2, 0);
		vector<bool> used(2, false);
		for (auto nit : nums)
		{
			if (used[1] && nit > l[1]) return true;
			else if (used[1])
			{
				if (nit <= l[0]) l[0] = nit;
				else l[1] = nit;
			}
			else if (used[0])
			{
				if (nit <= l[0]) l[0] = nit;
				else
				{
					used[1] = true;
					l[1] = nit;
				}
			}
			else
			{
				used[0] = true;
				l[0] = nit;
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
