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
	int findDuplicate(vector<int>& nums) {
		if (nums.size() > 1)
		{
			int slow = nums[0];
			int fast = nums[nums[0]];
			while (slow != fast)
			{
				slow = nums[slow];
				fast = nums[nums[fast]];
			}
			fast = 0;
			while (slow != fast)
			{
				slow = nums[slow];
				fast = nums[fast];
			}
			return slow;
		}
		return -1;
    }
};

int main()
{
	Solution s;
    cin.get();
}
