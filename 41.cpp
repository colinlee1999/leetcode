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
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) return 1;
		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] != i + 1)
			{
				if (nums[i]<1 || nums[i]>nums.size() || nums[nums[i] - 1] == nums[i])
					break;
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != i + 1) return i + 1;
		return nums.back() + 1;
	}
};

int main()
{
	Solution s;
    cin.get();
}
