#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int p1, c1, p2, c2;
		c1 = c2 = 0;
		for (auto it : nums)
		{
			if (p1 == it)
				c1++;
			else if (p2 == it)
				c2++;
			else if (c1 == 0)
			{
				p1 = it;
				c1 = 1;
			}
			else if (c2 == 0)
			{
				p2 = it;
				c2 = 1;
			}
			else
			{
				c1--;
				c2--;
			}
		}
		c1 = 0;
		c2 = 0;
		for (auto it : nums)
		{
			if (p1 == it) c1++;
			else if (p2 == it) c2++;
		}
		vector<int> result;
		if (c1 > (int)nums.size() / 3) result.push_back(p1);
		if (c2 > (int)nums.size() / 3) result.push_back(p2);
		return result;
	}
};

int main()
{
    Solution s;
    cin.get();
}
