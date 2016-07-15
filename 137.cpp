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
    int singleNumber(vector<int>& nums) {
		int one, two, three;
		one = two = three = 0;
		for (auto it : nums)
		{
			two ^= it & one;
			one ^= it;
			three = one & two;
			one &= ~three;
			two &= ~three;
		}
		return one;
    }
};

int main()
{
	Solution s;
	cin.get();
}
