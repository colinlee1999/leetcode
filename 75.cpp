#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < nums.size() && nums[left] == 0) left++;
		while (right >= 0 && nums[right] == 2) right--;
		for (int pos = left; pos <= right; pos = max(left, pos))
		{
			switch (nums[pos])
			{
			case 0:
				swap(nums[pos], nums[left]);
				left++;
				while (left < nums.size() && nums[left] == 0) left++;
				break;
			case 1:
				pos++;
				break;
			case 2:
				swap(nums[pos], nums[right]);
				right--;
				while (right >= 0 && nums[right] == 2) right--;
				break;
			default:
				break;
			}
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
