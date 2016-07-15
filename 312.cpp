#include "iostream"
#include "vector"
#include "set"
#include <sstream>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int nlen = nums.size();
		nums.push_back(1);
		nums.insert(nums.begin(), 1);
		int f[nlen+2][nlen+2];
		memset(f, 0, sizeof(f));
		for (int right = 0; right <= nlen + 1; right++)
			for (int left = right; left >= 0; left--)
			{
				for (int mid = left+1; mid < right; mid++)
				{
					f[left][right] = max(f[left][right], f[left][mid] + f[mid][right] + nums[left] * nums[mid] * nums[right]);
				}
			}
		return f[0][nlen + 1];
	}
};

int main()
{
    Solution s;
    cin.get();
}
