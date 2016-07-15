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
        int xor_result = 0;
		for (auto it : nums)
			xor_result ^= it;
		return xor_result;
    }
};

int main()
{
	Solution s;
	cin.get();
}
