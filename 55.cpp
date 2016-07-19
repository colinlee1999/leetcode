#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int right_most = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > right_most) return false;
			right_most = max(right_most, i + nums[i]);
			if (right_most >= nums.size() - 1) return true;
		}
		return true;
	}
};

int main()
{
	Solution s;
    cin.get();
}
