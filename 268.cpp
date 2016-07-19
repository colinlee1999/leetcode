#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <unordered_set>
#include <unordered_map>
#define	INT_MIN	1<<31
#define	INT_MAX	~(INT_MIN)
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int nlen = nums.size();
		int sum = 0;
		for (auto it : nums)
			sum += it;
		return (nlen + 1)*nlen / 2 - sum;
	}
};

int main()
{
	Solution s;
    cin.get();
}
