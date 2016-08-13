#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int nlen = nums.size();
		int left = 0, right = 0;
		int cur = 0;
		int result = INT_MAX;
		while (right < nlen)
		{
			while (right < nlen && cur < s)
			{
				cur += nums[right];
				right++;
			}
			while (left < right && cur - nums[left] >= s)
			{
				cur -= nums[left];
				left++;
			}
			if (cur >= s)
			{
				result = min(result, right - left);
				cur -= nums[left];
				left++;
			}			
		}
		return result == INT_MAX ? 0 : result;
	}
};

int main()
{
	Solution s;
    cin.get();
}
