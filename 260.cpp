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
    vector<int> singleNumber(vector<int>& nums) {
		int xor_result = 0;
		for (auto it : nums)
			xor_result ^= it;
		int last_digit = 1;
		while ((xor_result & last_digit) == 0)
			last_digit <<= 1;
		int xor_result_group_1, xor_result_group_2;
		xor_result_group_1 = 0;
		xor_result_group_2 = 0;
		for (auto it : nums)
		{
			if ((last_digit & it) == 0)
				xor_result_group_1 ^= it;
			else
				xor_result_group_2 ^= it;
		}
		vector<int> result;
		result.push_back(xor_result_group_1);
		result.push_back(xor_result_group_2);
		return result;
    }
};

int main()
{
	Solution s;
	cin.get();
}
