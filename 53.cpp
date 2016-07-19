#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> s(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++)
			s[i + 1] = s[i] + nums[i];
		int result = INT_MIN;
		int minimum = 0;
		for (int i = 1; i < s.size(); i++)
		{
			result = max(result, s[i] - minimum);
			minimum = min(minimum, s[i]);
		}
		return result;
    }
};

int main()
{
    Solution s;
	vector<vector<int>> v(1,vector<int>());
	v[0].push_back(2);
	v[0].push_back(3);
	s.spiralOrder(v);
    cin.get();
}
