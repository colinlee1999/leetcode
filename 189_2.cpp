#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int nlen = nums.size();
		k %= nlen;
		reverse(nums, 0, nlen - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nlen - 1);
	}

private:
	void reverse(vector<int>& nums, int start_pos, int end_pos)
	{
		int left = start_pos;
		int right = end_pos;
		int temp;
		while (left < right)
		{
			temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
			left++;
			right--;
		}
	}
};

int main()
{
    Solution s;
	cout << s.convertToTitle(288) << endl;
    cin.get();
}
