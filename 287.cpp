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
		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] != i + 1)
			{
				if (nums[nums[i] - 1] == nums[i])
					return nums[i];
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}
		return 1;
    }
};

int main()
{
	Solution s;
    cin.get();
}
