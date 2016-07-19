#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> jump_num(nums.size(), 0);
		int right_most = 0;
		jump_num[0] = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = right_most + 1; j <= i + nums[i]; j++)
			{
				if (j >= nums.size()) break;
				jump_num[j] = jump_num[i] + 1;
			}
			right_most = max(right_most, i + nums[i]);
			if (right_most >= nums.size() - 1) break;
		}
		return jump_num.back();
	}
};

int main()
{
	Solution s;
    cin.get();
}
